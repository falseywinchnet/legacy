#!/usr/bin/env python3
"""Capture original CHAMP geometry results using its preserved VB runtime.

Only temporary p-code copies receive replacement object-context pointers.
The original computation instructions and trailing procedure descriptors remain
unchanged. The separate C driver never calls the historical user interface.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import random
import shutil
import struct
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[1]
ROUTINES = {
    'interpolate': (0x479afc, 0x88, 0x34),
    'line': (0x478714, 0x68, 0x30),
    'intersection': (0x478254, 0x68, 0x30),
    'polygon': (0x47a72c, 0x98, 0x34),
}


def capture(output, prefix, count=1000):
    binary = ROOT / 'originals/champ2/champ.exe'
    data = binary.read_bytes()
    pe = struct.unpack_from('<I', data, 60)[0]
    first = pe + 24 + struct.unpack_from('<H', data, pe + 20)[0]
    def offset(va):
        for i in range(struct.unpack_from('<H', data, pe + 6)[0]):
            _, rva, size, raw = struct.unpack_from('<4I', data, first + i * 40 + 8)
            if rva <= va - 0x400000 < rva + size: return raw + va - 0x400000 - rva
        raise ValueError('unbacked procedure')
    runtime = prefix / 'drive_c/windows/syswow64/msvbvm60.dll'
    manifest = {'binary_sha256': hashlib.sha256(data).hexdigest(),
                'runtime_sha256': hashlib.sha256(runtime.read_bytes()).hexdigest(), 'routines': {}}
    output.mkdir(parents=True, exist_ok=True)
    rng = random.Random(20070914)
    with tempfile.TemporaryDirectory(prefix='champ-probe-') as directory:
        work = Path(directory)
        driver = work / 'PROBE.EXE'
        subprocess.run(['i686-w64-mingw32-gcc', '-O0', '-static', str(ROOT / 'tools/champ_probe_driver.c'), '-o', str(driver), '-loleaut32'], check=True)
        shutil.copyfile(runtime, work / 'msvbvm60.dll')
        for name, (va, code_size, descriptor_size) in ROUTINES.items():
            start = offset(va)
            (work / (name + '.bin')).write_bytes(data[start:start + code_size + descriptor_size])
            rows = []
            for i in range(count):
                if name == 'interpolate':
                    row = [rng.uniform(-100, 100), rng.uniform(-100, 100), rng.uniform(-1000, 1000), rng.uniform(-1000, 1000), rng.uniform(-1000, 1000)]
                    if i % 10 == 0: row[3] = row[2]
                    if i % 11 == 0: row[1] = row[0]
                elif name == 'line':
                    row = [rng.uniform(-10000, 10000), rng.uniform(-100, 100), rng.uniform(-10000, 10000), rng.uniform(-100, 100)]
                    if i % 10 == 0: row[2] = row[0]
                elif name == 'intersection':
                    row = [rng.uniform(-3, 3), -1, rng.uniform(-100, 100), rng.uniform(-3, 3), -1, rng.uniform(-100, 100)]
                    if i % 10 == 0: row[3] = row[0]
                else:
                    n = rng.randrange(3, 9)
                    row = [n] + [rng.uniform(-10000, 10000) for _ in range(8)] + [rng.uniform(-100, 100) for _ in range(8)]
                rows.append(struct.pack('<' + 'f' * len(row), *row))
            inputs = b''.join(rows)
            (work / 'CASES.BIN').write_bytes(inputs)
            env = os.environ.copy(); env['WINEPREFIX'] = str(prefix); env['WINEDEBUG'] = '-all'
            subprocess.run(['wine', str(driver), name, 'CASES.BIN', 'RESULTS.BIN'], cwd=work, env=env, check=True, timeout=30)
            expected = (work / 'RESULTS.BIN').read_bytes()
            (output / (name + '.input.bin')).write_bytes(inputs)
            (output / (name + '.expected.bin')).write_bytes(expected)
            manifest['routines'][name] = {'records': count, 'pcode_va': hex(va), 'pcode_bytes': code_size,
                'input_sha256': hashlib.sha256(inputs).hexdigest(), 'expected_sha256': hashlib.sha256(expected).hexdigest()}
            print(name, count, 'original records,', len(expected), 'result bytes')
    (output / 'manifest.json').write_text(json.dumps(manifest, indent=2) + '\n')


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--output', type=Path, default=ROOT / 'tests/reference/champ/routines')
    p.add_argument('--wine-prefix', type=Path, default=ROOT / 'build/oracle/wine')
    args = p.parse_args(); capture(args.output, args.wine_prefix.resolve())
