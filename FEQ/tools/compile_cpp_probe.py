#!/usr/bin/env python3
"""Compile the complete translated research engine and record diagnostics."""
import argparse
from concurrent.futures import ThreadPoolExecutor
import hashlib
import json
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parents[1]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('directory', type=Path)
    parser.add_argument('--compiler', default='c++')
    parser.add_argument('--runtime', type=Path, default=ROOT/'build/f2c/lib32')
    parser.add_argument('--jobs', type=int, default=6)
    parser.add_argument('--sanitize', action='store_true')
    args = parser.parse_args()
    directory = args.directory.resolve()
    flags = [args.compiler, '-std=c++20', '-pedantic-errors', '-fstrict-aliasing',
             '-ffp-contract=off', '-fno-fast-math', '-O1', '-Wno-vexing-parse',
             '-Wno-shift-op-parentheses', '-I', str(ROOT/'include'),
             '-iquote', str(args.runtime.resolve()), '-iquote', str(directory)]
    if args.sanitize:
        flags.extend(['-fsanitize=address,undefined', '-fno-omit-frame-pointer', '-g'])
    def compile_one(path):
        command = flags+['-c', str(path), '-o', str(path.with_suffix('.o'))]
        process = subprocess.run(command, capture_output=True, text=True)
        path.with_suffix('.compile.log').write_text(process.stderr)
        return {'file':path.name, 'sha256':hashlib.sha256(path.read_bytes()).hexdigest(),
                'command':command, 'exit':process.returncode,
                'errors':[line for line in process.stderr.splitlines() if 'error:' in line]}
    with ThreadPoolExecutor(max_workers=args.jobs) as pool:
        records = list(pool.map(compile_one, sorted(directory.glob('*.cpp'))))
    (directory/'compile-manifest.json').write_text(json.dumps(records, indent=2)+'\n')
    for record in records:
        if record['exit']:
            print(record['file']+': '+str(len(record['errors']))+' errors; '+str(record['errors'][:2]))
    passed = sum(record['exit'] == 0 for record in records)
    print(f'{passed}/{len(records)} translation units compiled.')
    raise SystemExit(0 if passed == len(records) else 1)


if __name__ == '__main__':
    main()
