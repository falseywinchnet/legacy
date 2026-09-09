#!/usr/bin/env python3
"""Run the desktop workflow and independently compare its 17 original reports."""
import argparse
import hashlib
import json
from pathlib import Path
import subprocess
import sys
import tempfile
ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT/'tools'))
from compare_reports import compare
from run_originals import CASES

def hashes(folder):
    return {p.relative_to(folder).as_posix(): hashlib.sha256(p.read_bytes()).hexdigest()
            for p in folder.rglob('*') if p.is_file()}

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('runner', 'fake', 'resources', 'output'):
        parser.add_argument('--'+name, type=Path, required=True)
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    destination = Path(tempfile.mkdtemp(prefix='run-', dir=args.output.resolve()))
    before = hashes(args.resources)
    result = subprocess.run([str(args.runner.resolve()), str(destination), str(args.fake.resolve())],
                            capture_output=True, timeout=270)
    console = result.stdout+result.stderr
    (destination/'workflow.log').write_bytes(console)
    print(console.decode(errors='replace'))
    if result.returncode:
        raise AssertionError('Desktop workflow failed; see '+str(destination))
    if before != hashes(args.resources):
        raise AssertionError('Desktop changed an installed model or resource')
    runs = json.loads((destination/'desktop-runs.json').read_text())
    records = []
    for run, (case, program, arguments) in zip(runs, CASES, strict=True):
        names = [case+'.out', case+'.out.spi', case+'.out.wsq'] if program == 'feq' else [case+'.out', case+'.tab']
        if case == 'utlexm':
            names.append('utlexm.chx')
        ledger = json.loads((Path(run['folder'])/'run.json').read_text())
        assert ledger['status'] == 'completed'
        assert ledger['arguments'] == arguments
        for entry in ledger['outputs']:
            actual = Path(run['folder'])/entry['path']
            assert hashlib.sha256(actual.read_bytes()).hexdigest() == entry['sha256']
        for name in names:
            report = dict(path=name, **compare((args.resources/'examples/data'/name).read_bytes(), (Path(run['working'])/name).read_bytes()))
            records.append(report)
            print(name+': '+('exact bytes' if report['raw_equal'] else 'exact except clocks' if report['clock_masked_equal'] else 'DIFFERENT'))
    (destination/'comparison.json').write_text(json.dumps(records,indent=2)+'\n')
    assert len(records) == 17 and all(item['clock_masked_equal'] for item in records)
    print('All 17 desktop reports match; source resources unchanged. Evidence: '+str(destination))
if __name__ == '__main__':
    main()
