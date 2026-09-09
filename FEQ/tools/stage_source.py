#!/usr/bin/env python3
"""Reproduce the official compilation file selection in a disposable directory.

Staged source remains historical reference material with its original notices.
The source bytes are copied, not edited. This provides a reproducible input to
compiler probes and translation analysis; it does not build a product.
"""
import argparse
import hashlib
import json
from pathlib import Path
import shutil

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / 'originals/feq1061/wrdapp/FEQ_10.61/SRC'


def stage(program, destination, precision='single'):
    destination = destination.resolve()
    if destination.exists():
        raise ValueError('Destination must be new.')
    if ROOT / 'build' not in destination.parents:
        raise ValueError('Staging must remain in FEQ/build/.')
    destination.mkdir(parents=True)
    selected = {}
    def select(source, target=None):
        selected[target or source.name.lower()] = source
    for directory in (SOURCE / program.upper(), SOURCE / 'SHARE'):
        for path in sorted(directory.iterdir()):
            if path.suffix.lower() in ('.for', '.cmn', '.prm') or (program == 'fequtl' and path.suffix.lower() == '.f90'):
                select(path)
    # SHARE parameter files are copied by name in the vendor scripts.
    for name in list(selected):
        if selected[name].parent.name == 'SHARE' and name.endswith('.prm') and name != 'arsize.prm':
            del selected[name]
    select(SOURCE / 'SHARE' / ('morglh.prm' if program == 'feq' else 'morgux.prm'), 'morg.prm')
    who = 'lf95_ms_d_npf' if program == 'feq' and precision == 'double' else 'lf95_ms_s_npf'
    select(SOURCE / 'SHARE' / (who+'.who'), who+'.for')
    select(SOURCE / 'SVN_REPORT/svn_reportdmy.for', 'svn_report.for')
    excluded = ['locsubux.for', 'timer90.for', 'getsvn_lx_g95.for', 'getsvn_lx_lf95.for', 'getsvn_msw_g95.for', 'pwd_lx_g95.for', 'pwd_lx_lf95.for', 'pwd_msw_g95.for']
    if program == 'feq':
        select(SOURCE / 'FEQ' / precision / 'linsys.for')
        select(SOURCE / 'FEQ' / precision / 'matcom.cmn')
        select(SOURCE / 'FEQ/mkdir_fun_msw_lf95.for', 'mkdir_fun.for')
        excluded += ['hecdss.for', 'mkdir_fun_msw_lf95.for', 'mkdir_fun_msw_g95.for', 'mkdir_fun_lx_lf95.for', 'mkdir_fun_lx_g95.for']
    else:
        select(SOURCE / 'SHARE/pwd_msw_lf95.for', 'pwd.for')
        excluded += ['fqshrarg.for', 'locsubs.for', 'pwd_msw_lf95.for']
    for name in excluded:
        selected.pop(name, None)
    manifest = []
    for name, path in sorted(selected.items()):
        shutil.copyfile(path, destination / name)
        manifest.append({'staged': name, 'source': path.relative_to(ROOT).as_posix(),
                         'sha256': hashlib.sha256(path.read_bytes()).hexdigest()})
    (destination / 'source-manifest.json').write_text(json.dumps(manifest, indent=2)+'\n')
    print(f'{program}: {len(selected)} staged files; {precision} solver; HEC-DSS stubs')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('program', choices=['feq', 'fequtl'])
    parser.add_argument('destination', type=Path)
    parser.add_argument('--precision', choices=['single', 'double'], default='single')
    arguments = parser.parse_args()
    stage(arguments.program, arguments.destination, arguments.precision)
