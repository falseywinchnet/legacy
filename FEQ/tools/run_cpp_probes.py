#!/usr/bin/env python3
"""Run all supplied examples with explicitly selected C++ research binaries."""
import argparse
import datetime
import json
from pathlib import Path
import platform
import shutil
import subprocess
import time

from run_originals import CASES, RELEASES, ROOT, file_record


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--feq', type=Path, required=True)
    parser.add_argument('--fequtl', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--case', action='append', choices=[case[0] for case in CASES])
    parser.add_argument('--legacy-path-links', action='store_true',
                        help='Create literal backslash aliases for the unadapted research I/O runtime.')
    parser.add_argument('--timeout', type=float, default=120)
    args = parser.parse_args()
    output = args.output.resolve()
    if output.exists() or ROOT/'build' not in output.parents:
        parser.error('Use a new directory under FEQ/build/.')
    output.mkdir(parents=True)
    shutil.copytree(RELEASES['1061']/'DATA',output/'data')
    working = output/'test'
    working.mkdir()
    (output/'bin').mkdir()
    for program in ('feq','fequtl'):
        shutil.copy2(getattr(args,program).resolve(),output/'bin'/program)
    if args.legacy_path_links:
        for path in (output/'data').iterdir():
            if path.is_file():
                for name in sorted({path.name,path.name.lower(),path.name.upper()}):
                    alias = working/('..\\data\\'+name)
                    if not alias.exists():
                        alias.symlink_to(Path('../data')/path.name)
    manifest = {
        'purpose':'C++ research execution; equivalence requires a separate comparison.',
        'created_utc':datetime.datetime.now(datetime.timezone.utc).isoformat(),
        'host':platform.platform(),'legacy_path_links':args.legacy_path_links,
        'inputs':[file_record(path,output) for path in sorted((output/'data').rglob('*')) if path.is_file()],
        'binaries':[file_record(output/'bin'/program,output) for program in ('feq','fequtl')],
        'cases':[],
    }
    failed = False
    for case,program,arguments in CASES:
        if args.case and case not in args.case:
            continue
        before = {path.name:file_record(path,working) for path in working.iterdir() if path.is_file() and not path.is_symlink()}
        command = [str(output/'bin'/program)]+arguments
        start = time.monotonic()
        try:
            process = subprocess.run(command,cwd=working,capture_output=True,stdin=subprocess.DEVNULL,timeout=args.timeout)
            console, returncode = process.stdout+process.stderr, process.returncode
        except subprocess.TimeoutExpired as error:
            console, returncode = (error.stdout or b'')+(error.stderr or b''), 'timeout'
        (output/(case+'.console.log')).write_bytes(console)
        changed = []
        for path in sorted(working.iterdir()):
            if path.is_file() and not path.is_symlink():
                record = file_record(path,working)
                if before.get(path.name) != record:
                    changed.append(record)
        completed = returncode == 0 and (working/(case+'.out')).is_file()
        manifest['cases'].append({'case':case,'program':program,'arguments':arguments,
            'returncode':returncode,'elapsed_seconds':time.monotonic()-start,
            'process_completed':completed,'outputs':changed})
        failed = failed or not completed
        (output/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
        print(f'{case}: exit {returncode}, {len(changed)} output files.',flush=True)
    raise SystemExit(1 if failed else 0)


if __name__ == '__main__':
    main()
