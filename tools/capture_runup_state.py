#!/usr/bin/env python3
"""Capture original RUNUP data memory at a known main-program boundary.

A temporary instruction patch writes data memory to redirected standard output
and exits. No preserved file is modified; the computation up to the selected
boundary remains the original program. Used to diagnose translation differences.
"""
import argparse
import json
from pathlib import Path
import shutil
import struct
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[1]
BOUNDARIES = {'input': 0x08de, 'first-wave': 0x0a95}


def capture(input_path, boundary='first-wave'):
    exe = bytearray((ROOT / 'originals/runup2/RUNUP2.EXE').read_bytes())
    header = struct.unpack_from('<H', exe, 8)[0] * 16
    patch = bytes.fromhex('bb0100 ba0000 b90063 b440 cd21 b8004c cd21')
    at = header + BOUNDARIES[boundary]
    exe[at:at + len(patch)] = patch
    with tempfile.TemporaryDirectory(prefix='runup-state-') as directory:
        work = Path(directory)
        (work / 'MODEL.EXE').write_bytes(exe)
        shutil.copyfile(input_path, work / 'INPUT.DAT')
        command = ['dosbox-x', '-silent', '-fastlaunch', '-defaultconf', '-defaultdir', directory,
                   '-set', 'cpu core=normal', '-set', 'cpu fpu=false', '-set', 'cpu cycles=fixed 20000',
                   '-set', 'sdl output=surface', '-c', 'mount c .', '-c', 'c:',
                   '-c', 'MODEL.EXE INPUT.DAT OUTPUT.OUT > STATE.BIN', '-c', 'exit', '-time-limit', '30']
        subprocess.run(command, capture_output=True, timeout=40, check=True)
        data = (work / 'STATE.BIN').read_bytes()
        if len(data) != 0x6300:
            raise ValueError(f'Unexpected snapshot size {len(data)}')
        return data


def named_values(data):
    meta = json.loads((ROOT / 'recovery/runup-1991-debug/build-metadata.json').read_text())
    result = {}
    for module in list(meta['modules'].values())[:4]:
        procedure = module['name']
        for s in module.get('symbol_records', []):
            if s['kind'] == '0x1': procedure = s['name']
            if s['kind'] != '0x5' or s['type_index'] not in ('0x82', '0x88'): continue
            offset = (s['segment'] - 0xdca) * 16 + s['data_offset']
            if offset < 0 or offset + 4 > len(data): continue
            fmt = '<i' if s['type_index'] == '0x82' else '<f'
            key = procedure + '.' + s['name']
            result[key] = {'ds_offset': hex(offset), 'value': struct.unpack_from(fmt, data, offset)[0],
                           'raw': data[offset:offset + 4].hex()}
    return result


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('input', type=Path)
    parser.add_argument('output', type=Path)
    parser.add_argument('--at', choices=BOUNDARIES, default='first-wave')
    args = parser.parse_args()
    data = capture(args.input, args.at)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_bytes(data)
    args.output.with_suffix('.json').write_text(json.dumps(named_values(data), indent=2) + '\n')
    print(f'Captured {len(data)} original data bytes after {args.at}')
