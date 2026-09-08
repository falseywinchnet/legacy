#!/usr/bin/env python3
"""Call original RUNUP numerical routines using a tiny DOS test driver.

Only a temporary copy of the main program is replaced. The target routines,
Microsoft runtime, MZ relocation table, and initialization path are unchanged.
Input/output records are binary so decimal formatting cannot hide differences.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[1]


def driver(target, record_bytes=24, argument_offsets=(0, 4, 8, 12, 16, 20), result_offset=20, result_bytes=4):
    origin = 0x8c4
    code = bytearray()
    labels = {}
    jumps = []
    def emit(s): code.extend(bytes.fromhex(s))
    def u16(v): code.extend(struct.pack('<H', v & 0xffff))
    def label(s): labels[s] = len(code)
    def jump(s):
        emit('e9'); jumps.append((len(code), s)); u16(0)
    # File name and record buffer occupy unused page-heading storage.
    emit('ba'); u16(0x19d4)
    emit('b8 00 3d cd 21 73 03')
    jump('error')
    emit('89 c6')  # si = input handle
    label('loop')
    emit('89 f3 ba'); u16(0x1a00)
    emit('b9'); u16(record_bytes)
    emit('b4 3f cd 21 73 03')
    jump('error')
    emit('83 f8 00 75 03')
    jump('done')
    emit('3d'); u16(record_bytes)
    emit('74 03'); jump('error')
    for offset in argument_offsets:
        emit('68'); u16(0x1a00 + offset)
    emit('0e e8')
    u16(target - (origin + len(code) + 2))
    emit('bb 01 00 ba'); u16(0x1a00 + result_offset)
    emit('b9'); u16(result_bytes)
    emit('b4 40 cd 21 73 03'); jump('error')
    jump('loop')
    label('done'); emit('b8 00 4c cd 21')
    label('error'); emit('b8 01 4c cd 21')
    for position, name in jumps:
        struct.pack_into('<h', code, position, labels[name] - position - 2)
    if len(code) > 960:
        raise ValueError('Driver exceeds replaced main procedure')
    return code


def probe(name, records, *, record_bytes=24, argument_offsets=(0, 4, 8, 12, 16, 20),
          result_offset=20, result_bytes=4, coprocessor=False):
    original = (ROOT / 'originals/runup2/RUNUP2.EXE').read_bytes()
    metadata = json.loads((ROOT / 'recovery/runup-1991-debug/build-metadata.json').read_text())
    if hashlib.sha256(original).hexdigest() != metadata['sha256']:
        raise ValueError('Unexpected executable')
    proc = next(r for r in metadata['modules']['4']['symbol_records']
                if r.get('kind') == '0x1' and r.get('name') == name)
    patch = driver(proc['code_offset'], record_bytes, argument_offsets, result_offset, result_bytes)
    exe = bytearray(original)
    header = struct.unpack_from('<H', exe, 8)[0] * 16
    exe[header + 0x8c4:header + 0x8c4 + len(patch)] = patch
    filename = header + 0xdca * 16 + 0x19d4
    exe[filename:filename + 10] = b'CASES.BIN\0'
    if any(len(record) != record_bytes for record in records):
        raise ValueError('Wrong record size')
    with tempfile.TemporaryDirectory(prefix='runup-probe-') as directory:
        work = Path(directory)
        (work / 'PROBE.EXE').write_bytes(exe)
        (work / 'CASES.BIN').write_bytes(b''.join(records))
        command = ['dosbox-x', '-silent', '-fastlaunch', '-defaultconf', '-defaultdir', directory,
                   '-set', 'cpu core=normal', '-set', 'cpu cycles=fixed 20000',
                   '-set', 'cpu fpu=' + ('true' if coprocessor else 'false'),
                   '-set', 'sdl output=surface', '-c', 'mount c .', '-c', 'c:',
                   '-c', 'PROBE.EXE CASES.BIN UNUSED.OUT > RESULT.BIN', '-c', 'exit', '-time-limit', '30']
        process = subprocess.run(command, capture_output=True, timeout=40)
        result = work / 'RESULT.BIN'
        if process.returncode or not result.exists():
            raise RuntimeError('Routine probe failed: ' + process.stderr.decode(errors='replace')[-1500:])
        content = result.read_bytes()
        if len(content) != len(records) * result_bytes:
            raise RuntimeError(f'Unexpected result length {len(content)}, expected {len(records) * result_bytes}: {content[:100]!r}')
        return [content[i:i + result_bytes] for i in range(0, len(content), result_bytes)]


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('routine', choices=['RINT', 'SWLINT', 'LOGLOG', 'LOGLIN'])
    parser.add_argument('values', nargs=5, type=float)
    args = parser.parse_args()
    fmt = '<6f' if args.routine == 'SWLINT' else '<6i'
    values = args.values if args.routine == 'SWLINT' else [int(x) for x in args.values]
    result = probe(args.routine, [struct.pack(fmt, *values, 0)])[0]
    print(struct.unpack('<f' if args.routine == 'SWLINT' else '<i', result)[0])
