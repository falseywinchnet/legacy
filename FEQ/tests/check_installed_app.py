#!/usr/bin/env python3
"""Launch a relocated installed application with no Qt SDK on PATH.

Compare its actual outputs with all 17 released reports and verify each bundled
engine, manual, Qt source archive, and run ledger. No compiler or test binary is
involved in the launch. Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import platform
import shutil
import subprocess
import sys
import tempfile
ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'tools'))
from compare_reports import compare
from run_originals import CASES

def hashes(folder):
    return {p.relative_to(folder).as_posix(): hashlib.sha256(p.read_bytes()).hexdigest()
            for p in folder.rglob('*') if p.is_file()}

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--package', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    output = Path(tempfile.mkdtemp(prefix='installation-', dir=args.output.resolve()))
    package = output/'relocated installation with spaces café 河'
    shutil.copytree(args.package, package, symlinks=True)
    system = platform.system()
    if system == 'Darwin':
        bundle = package/'FEQ Workbench.app/Contents'
        binary = bundle/'MacOS/FEQ Workbench'
        engines = bundle/'MacOS'
        resources = bundle/'Resources'
    else:
        binary = package/'bin'/('feq-workbench.exe' if system == 'Windows' else 'feq-workbench')
        engines = package/'bin'
        resources = package/'share/feq'
    assert binary.is_file()
    for name in ('feq', 'fequtl'):
        assert (engines/(name+('.exe' if system == 'Windows' else ''))).is_file()
    for name in ('feq.pdf', 'fequtl.pdf'):
        assert (resources/'manuals'/name).stat().st_size > 10000
    assert (resources/'licenses/LICENSE').is_file()
    sources = json.loads((resources/'licenses/qt/sources.json').read_text(encoding='utf-8'))
    assert len(sources) == 3
    for source in sources:
        archive = resources/'licenses/qt/sources'/Path(source['url']).name
        assert hashlib.sha256(archive.read_bytes()).hexdigest() == source['sha256']
    before = hashes(resources/'examples')
    environment = dict(os.environ)
    for key in list(environment):
        if key.startswith(('QT_', 'QML_', 'DYLD_', 'LD_')) or key in ('FEQ_RUN_SOURCE_ROOT', 'FEQ_RUN_COPY_ROOT'):
            environment.pop(key)
    environment['PATH'] = os.path.join(environment.get('SystemRoot','C:\\Windows'), 'System32') if system == 'Windows' else '/usr/bin:/bin'
    verification = output/'acceptance'
    working = output/'unrelated working folder'
    working.mkdir()
    process = subprocess.run([str(binary), '--verify-installation', str(verification)], cwd=working,
                             env=environment, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, timeout=150)
    (output/'application.log').write_bytes(process.stdout)
    print(process.stdout.decode(errors='replace'))
    assert process.returncode == 0, 'Installed application failed; see '+str(output)
    receipt = json.loads((verification/'installation.json').read_text(encoding='utf-8'))
    assert Path(receipt['resources']).resolve() == resources.resolve(), 'Application used external development resources'
    assert before == hashes(resources/'examples'), 'Application modified installed examples'
    reports = []
    for run, (case, program, arguments) in zip(receipt['runs'], CASES, strict=True):
        ledger = json.loads((Path(run['folder'])/'run.json').read_text(encoding='utf-8'))
        assert ledger['status'] == 'completed' and ledger['arguments'] == arguments
        executable = engines/(program+('.exe' if system == 'Windows' else ''))
        assert ledger['engine_sha256'] == hashlib.sha256(executable.read_bytes()).hexdigest()
        for entry in ledger['outputs']:
            assert hashlib.sha256((Path(run['folder'])/entry['path']).read_bytes()).hexdigest() == entry['sha256']
        names = [case+'.out', case+'.out.spi', case+'.out.wsq'] if program == 'feq' else [case+'.out', case+'.tab']
        if case == 'utlexm':
            names.append('utlexm.chx')
        for name in names:
            item = dict(path=name, **compare((resources/'examples/data'/name).read_bytes(), (Path(run['working'])/name).read_bytes()))
            reports.append(item)
    assert len(reports) == 17 and all(item['clock_masked_equal'] for item in reports)
    (output/'comparison.json').write_text(json.dumps(reports,indent=2)+'\n')
    if system == 'Linux':
        dependencies = subprocess.check_output(['ldd', str(binary)], env=environment).decode()
        (output/'dependencies.txt').write_text(dependencies)
        assert 'not found' not in dependencies
        for line in dependencies.splitlines():
            if 'libQt6' in line:
                assert str(package) in line, 'Application loaded Qt outside the relocated package'
    print('Relocated installed application: all six models, 17 exact reports, bundled resources and source checksums passed.')
    print('Evidence: '+str(output))
if __name__ == '__main__':
    main()
