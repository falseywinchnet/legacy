#!/usr/bin/env python3
"""Capture the original Lahey startup x87 control word and solver identity.

Only a disposable executable copy is patched. Its normal runtime startup runs
first; a tiny driver at PROGRAM entry writes eight bytes and exits via Win32.
The original file is verified against its recorded hash and never changed.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import struct
import subprocess
import tempfile

from inspect_binary import coff_symbols

ROOT = Path(__file__).resolve().parents[1]


def capture(program, wine_prefix):
    import pefile
    binary = ROOT / 'originals/feq1061/wrdapp/FEQ_10.61/BIN' / (program+'.exe')
    original = binary.read_bytes()
    digest = hashlib.sha256(original).hexdigest()
    analysis = json.loads((ROOT / 'recovery/source-analysis.json').read_text())
    expected = next(item['sha256'] for item in analysis['binaries'] if item['path'] == binary.relative_to(ROOT).as_posix())
    if digest != expected:
        raise ValueError('Original executable differs from the preserved recovery hash.')
    pe = pefile.PE(data=original)
    symbols = {item['name']: item for item in coff_symbols(original)}
    imports = {item.name.decode(): item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    base = pe.OPTIONAL_HEADER.ImageBase
    start = base+symbols['_MAIN__']['rva']
    code = bytearray()
    def push(value):
        code.extend(b'\x68'+struct.pack('<I', value & 0xffffffff))
    def api(name):
        code.extend(b'\xff\x15'+struct.pack('<I', imports[name]))
    # sub esp,32; mov esi,esp; xor eax,eax; clear the output record;
    # fnstcw [esi]; call WHAT_PRECISION; mov [esi+4],eax.
    code.extend(bytes.fromhex('83ec208bf431c08906894604d93e'))
    destination = base+symbols['_what_precision_']['rva']
    code.extend(b'\xe8'+struct.pack('<i', destination-(start+len(code)+5)))
    code.extend(bytes.fromhex('894604'))
    push(-11)
    api('GetStdHandle')
    code.extend(bytes.fromhex('8bd88d4e10'))  # EBX=stdout; ECX=&bytes_written.
    push(0)
    code.extend(b'\x51')
    push(8)
    code.extend(b'\x56\x53')
    api('WriteFile')
    push(0)
    api('ExitProcess')
    payload = bytearray(original)
    offset = pe.get_offset_from_rva(symbols['_MAIN__']['rva'])
    payload[offset:offset+len(code)] = code
    with tempfile.TemporaryDirectory(prefix='feq-startup-probe-') as directory:
        work = Path(directory)
        (work / 'PROBE.EXE').write_bytes(payload)
        env = os.environ.copy()
        env.update(WINEPREFIX=str(wine_prefix.resolve()), WINEDEBUG='-all',
                   WINEDLLOVERRIDES='mscoree,mshtml=', MVK_CONFIG_LOG_LEVEL='0')
        process = subprocess.run(['wine', 'PROBE.EXE'], cwd=work, env=env,
                                 capture_output=True, timeout=30, stdin=subprocess.DEVNULL)
    if process.returncode or len(process.stdout) != 8:
        raise RuntimeError(f'Unexpected probe result: exit={process.returncode}, bytes={process.stdout!r}, stderr={process.stderr[-2000:]!r}')
    control, reserved, precision = struct.unpack('<HHI', process.stdout)
    return {'program': program, 'binary_sha256': digest,
            'capture_point': 'PROGRAM entry after original runtime initialization',
            'x87_control_word_hex': hex(control),
            'precision_control_bits': (control >> 8) & 3,
            'rounding_control_bits': (control >> 10) & 3,
            'solver_precision_code': precision,
            'raw_record_hex': process.stdout.hex()}


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--wine-prefix', type=Path, default=ROOT / 'build/wineprefix')
    parser.add_argument('--output', type=Path, required=True)
    arguments = parser.parse_args()
    records = [capture(program, arguments.wine_prefix) for program in ('feq', 'fequtl')]
    arguments.output.parent.mkdir(parents=True, exist_ok=True)
    arguments.output.write_text(json.dumps(records, indent=2)+'\n')
    print(json.dumps(records, indent=2))
