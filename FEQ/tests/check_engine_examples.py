#!/usr/bin/env python3
"""Run both complete C++ programs and compare all 17 original reports.

Each invocation gets a fresh workspace. Report comparison masks only clocks.
Console output is checked for sanitizer diagnostics, including recoverable UB.
Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
"""
import argparse
import json
from pathlib import Path
import shutil
import subprocess
import sys
import tempfile

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT/'tools'))
from compare_reports import compare
from run_originals import CASES, RELEASES


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--feq', required=True, type=Path)
    parser.add_argument('--fequtl', required=True, type=Path)
    parser.add_argument('--output', required=True, type=Path)
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    output = Path(tempfile.mkdtemp(prefix='run-', dir=args.output.resolve()))
    source = RELEASES['1061']/'DATA'
    shutil.copytree(source, output/'data')
    working = output/'test'
    working.mkdir()
    records = []
    for case, program, arguments in CASES:
        binary = getattr(args, program).resolve()
        result = subprocess.run([str(binary), *arguments], cwd=working,
                                capture_output=True, stdin=subprocess.DEVNULL, timeout=120)
        console = result.stdout+result.stderr
        (output/(case+'.console.log')).write_bytes(console)
        if result.returncode or b'runtime error:' in console or b'ERROR: AddressSanitizer' in console:
            raise AssertionError(case+' failed (exit '+str(result.returncode)+'); see '+str(output/(case+'.console.log'))+'\n'+console.decode(errors='replace'))
        names = [case+'.out', case+'.out.spi', case+'.out.wsq'] if program == 'feq' else [case+'.out', case+'.tab']
        if case == 'utlexm':
            names.append('utlexm.chx')
        for name in names:
            report = dict(path=name, **compare((source/name).read_bytes(), (working/name).read_bytes()))
            records.append(report)
            print(name+': '+('exact bytes' if report['raw_equal'] else 'exact except clocks' if report['clock_masked_equal'] else 'DIFFERENT'))
    (output/'comparison.json').write_text(json.dumps(records,indent=2)+'\n')
    if len(records) != 17 or not all(item['clock_masked_equal'] for item in records):
        raise AssertionError('Complete engine output differs; see '+str(output/'comparison.json'))
    print('All 17 reports match. Evidence: '+str(output))


if __name__ == '__main__':
    main()
