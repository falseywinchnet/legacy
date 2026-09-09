#!/usr/bin/env python3
"""Compile the complete translated research engine and record diagnostics."""
import argparse
from concurrent.futures import ThreadPoolExecutor
import hashlib
import json
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parents[1]


def header_inputs(directory, runtime):
    """Record the complete project/runtime header set, including unused headers."""
    paths = set()
    for base in (ROOT/'include', directory, runtime):
        for suffix in ('*.h', '*.hpp'):
            paths.update(base.rglob(suffix))
    return [{'path':str(path.resolve()), 'sha256':hashlib.sha256(path.read_bytes()).hexdigest()}
            for path in sorted(paths)]


def header_digest(headers):
    return hashlib.sha256(json.dumps(headers, sort_keys=True).encode()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('directory', type=Path)
    parser.add_argument('--compiler', default='c++')
    parser.add_argument('--runtime', type=Path, default=ROOT/'build/f2c/lib32')
    parser.add_argument('--jobs', type=int, default=6)
    parser.add_argument('--sanitize', action='store_true')
    args = parser.parse_args()
    directory = args.directory.resolve()
    headers = header_inputs(directory, args.runtime.resolve())
    headers_sha256 = header_digest(headers)
    flags = [args.compiler, '-std=c++20', '-pedantic-errors', '-fstrict-aliasing',
             '-ffp-contract=off', '-fno-fast-math', '-O1', '-Wno-vexing-parse',
             '-Wno-shift-op-parentheses', '-I', str(ROOT/'include'),
             '-iquote', str(args.runtime.resolve()), '-iquote', str(directory)]
    if args.sanitize:
        flags.extend(['-fsanitize=address,undefined', '-fno-omit-frame-pointer', '-g'])
    def compile_one(path):
        source_sha256 = hashlib.sha256(path.read_bytes()).hexdigest()
        command = flags+['-c', str(path), '-o', str(path.with_suffix('.o'))]
        process = subprocess.run(command, capture_output=True, text=True)
        path.with_suffix('.compile.log').write_text(process.stderr)
        if source_sha256 != hashlib.sha256(path.read_bytes()).hexdigest():
            raise RuntimeError('Source changed during compilation: '+path.name)
        return {'file':path.name, 'sha256':source_sha256,
                'headers_sha256':headers_sha256,
                'object_sha256':hashlib.sha256(path.with_suffix('.o').read_bytes()).hexdigest() if process.returncode == 0 else None,
                'command':command, 'exit':process.returncode,
                'errors':[line for line in process.stderr.splitlines() if 'error:' in line]}
    with ThreadPoolExecutor(max_workers=args.jobs) as pool:
        records = list(pool.map(compile_one, sorted(directory.glob('*.cpp'))))
    if headers != header_inputs(directory, args.runtime.resolve()):
        raise RuntimeError('Headers changed during compilation.')
    (directory/'compile-inputs.json').write_text(json.dumps({
        'headers':headers, 'headers_sha256':headers_sha256,
        'compiler':subprocess.check_output([args.compiler, '--version'], text=True)}, indent=2)+'\n')
    (directory/'compile-manifest.json').write_text(json.dumps(records, indent=2)+'\n')
    for record in records:
        if record['exit']:
            print(record['file']+': '+str(len(record['errors']))+' errors; '+str(record['errors'][:2]))
    passed = sum(record['exit'] == 0 for record in records)
    print(f'{passed}/{len(records)} translation units compiled.')
    raise SystemExit(0 if passed == len(records) else 1)


if __name__ == '__main__':
    main()
