#!/usr/bin/env python3
"""Run the six unmodified USGS distribution examples with their original binaries.

Windows runs the PE32 executables directly. Other hosts require Wine. Inputs,
executables, raw outputs, console logs, command lines, and hashes are retained in
an isolated run directory. The preserved distribution is never a working folder.
This is a development reference runner, not the native C++ application.
"""
import argparse
import datetime
import hashlib
import json
import os
from pathlib import Path
import platform
import shutil
import subprocess
import time

ROOT = Path(__file__).resolve().parents[1]
RELEASES = {
    '1061': ROOT / 'originals/feq1061/wrdapp/FEQ_10.61',
    '998': ROOT / 'originals/feq998/wrdapp/FEQ_9.98',
}
CASES = [
    ('feqex1', 'feq', ['..\\data\\feqex1', 'feqex1.out']),
    ('feqex2', 'feq', ['..\\data\\feqex2', 'feqex2.out']),
    ('feqex3', 'feq', ['..\\data\\feqex3', 'feqex3.out']),
    ('feqex4', 'feq', ['..\\data\\feqex4', 'feqex4.out']),
    ('utlexm', 'fequtl', ['..\\data\\utlexm.in', 'utlexm.out', 'utlexm.tab']),
    ('culvert', 'fequtl', ['..\\data\\culvert.in', 'culvert.out', 'culvert.tab']),
]


def file_record(path, root):
    payload = path.read_bytes()
    return {'path': path.relative_to(root).as_posix(), 'bytes': len(payload),
            'sha256': hashlib.sha256(payload).hexdigest()}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--release', choices=RELEASES, default='1061')
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--wine', default='wine')
    parser.add_argument('--wine-prefix', type=Path, default=ROOT / 'build/wineprefix')
    parser.add_argument('--timeout', type=float, default=120)
    args = parser.parse_args()
    source = RELEASES[args.release]
    output = args.output.resolve()
    if output.exists():
        parser.error('Output must be a new directory; prior reference runs are preserved.')
    if ROOT / 'originals' == output or ROOT / 'originals' in output.parents:
        parser.error('A reference run cannot write into originals/.')
    output.mkdir(parents=True)
    for directory in ('BIN', 'DATA'):
        shutil.copytree(source / directory, output / directory.lower())
    working = output / 'test'
    working.mkdir()
    env = os.environ.copy()
    env.update(WINEDEBUG='-all', WINEPREFIX=str(args.wine_prefix.resolve()),
               WINEDLLOVERRIDES='mscoree,mshtml=', MVK_CONFIG_LOG_LEVEL='0')
    wine_version = None
    if os.name != 'nt':
        wine_version = subprocess.check_output([args.wine, '--version'], text=True).strip()
    manifest = {
        'release': args.release,
        'created_utc': datetime.datetime.now(datetime.timezone.utc).isoformat(),
        'host': platform.platform(), 'wine': wine_version,
        'inputs': [file_record(p, output) for p in sorted((output / 'data').rglob('*')) if p.is_file()],
        'binaries': [file_record(output / 'bin' / (name + '.exe'), output) for name in ('feq', 'fequtl')],
        'cases': [],
    }
    failed = False
    for case, program, arguments in CASES:
        executable = output / 'bin' / (program + '.exe')
        command = [str(executable)] + arguments
        if os.name != 'nt':
            command.insert(0, args.wine)
        before = {p.name: file_record(p, working) for p in working.iterdir() if p.is_file()}
        started = time.monotonic()
        try:
            process = subprocess.run(command, cwd=working, env=env, capture_output=True,
                                     timeout=args.timeout, stdin=subprocess.DEVNULL)
            console = process.stdout + process.stderr
            returncode = process.returncode
        except subprocess.TimeoutExpired as error:
            console = (error.stdout or b'') + (error.stderr or b'')
            returncode = 'timeout'
        (output / (case + '.console.log')).write_bytes(console)
        changed = []
        for path in sorted(working.iterdir()):
            if path.is_file():
                record = file_record(path, working)
                if before.get(path.name) != record:
                    changed.append(record)
        success = returncode == 0 and (working / (case + '.out')).is_file()
        manifest['cases'].append({
            'case': case, 'program': program, 'arguments': arguments,
            'working_directory': 'test', 'returncode': returncode,
            'elapsed_seconds': time.monotonic() - started,
            'outputs': changed, 'process_completed': success,
        })
        # Exit zero alone is not a scientific validation: output comparison is separate.
        failed = failed or not success
        (output / 'manifest.json').write_text(json.dumps(manifest, indent=2) + '\n')
        print(f'{case}: exit {returncode}, {len(changed)} output files', flush=True)
    raise SystemExit(1 if failed else 0)


if __name__ == '__main__':
    main()
