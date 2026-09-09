#!/usr/bin/env python3
"""Install or mount the actual distributed installer, then run its application."""
import argparse
from pathlib import Path
import platform
import subprocess
import sys
import tempfile
ROOT = Path(__file__).resolve().parents[1]

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--installers', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    output = Path(tempfile.mkdtemp(prefix='installer-',dir=args.output.resolve()))
    system = platform.system()
    if system == 'Darwin':
        installers = list(args.installers.glob('*.dmg'))
        assert len(installers) == 1
        mount = output/'mounted'
        mount.mkdir()
        subprocess.run(['hdiutil','attach','-readonly','-nobrowse','-mountpoint',str(mount),str(installers[0].resolve())], check=True,timeout=90)
        try:
            subprocess.run([sys.executable,str(ROOT/'tests/check_installed_app.py'),'--package',str(mount),'--output',str(output/'verification')],check=True,timeout=180)
        finally:
            subprocess.run(['hdiutil','detach',str(mount)],check=True,timeout=45)
    elif system == 'Windows':
        installers = list(args.installers.glob('*.exe'))
        assert len(installers) == 1
        installed = output/'installed'
        # NSIS requires /D to be the final, unquoted argument. CreateProcess
        # receives this string directly; no command shell interprets it.
        command = '"'+str(installers[0].resolve())+'" /S /D='+str(installed)
        subprocess.run(command,check=True,timeout=120)
        try:
            subprocess.run([sys.executable,str(ROOT/'tests/check_installed_app.py'),'--package',str(installed),'--output',str(output/'verification')],check=True,timeout=180)
        finally:
            uninstaller = installed/'Uninstall.exe'
            assert uninstaller.is_file()
            subprocess.run([str(uninstaller),'/S'],check=True,timeout=90)
    else:
        raise ValueError('Linux package installation is tested in the clean Ubuntu container.')
    print('Actual installer acceptance passed. Evidence: '+str(output))
if __name__ == '__main__':
    main()
