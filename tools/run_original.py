#!/usr/bin/env python3
"""Run an original FEMA engine in an isolated working directory.

RUNUP / WHAFIS 3 use DOSBox-X. WHAFIS 4 uses Windows directly or Wine.
The emulator is a development reference only, not the C++ product runtime.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[1]
PROGRAMS = {
    'runup': ('originals/runup2/RUNUP2.EXE', 'dos'),
    'whafis3': ('originals/whafis3/WHAFIS3.EXE', 'dos'),
    'whafis4': ('originals/whafis4/WHAFIS4.exe', 'windows'),
}


def run_original(program, input_path, output_path, *, timeout=30, coprocessor=False,
                 dosbox='dosbox-x', wine='wine', wine_prefix=None, log_path=None):
    relative, platform = PROGRAMS[program]
    binary = ROOT / relative
    original_hash = hashlib.sha256(binary.read_bytes()).hexdigest()
    with tempfile.TemporaryDirectory(prefix='legacy-reference-') as scratch:
        work = Path(scratch)
        shutil.copyfile(binary, work / 'MODEL.EXE')
        shutil.copyfile(input_path, work / 'INPUT.DAT')
        if program.startswith('whafis'):
            marsh = ROOT / ('originals/whafis4/MG.DAT' if program == 'whafis4' else 'originals/whafis3/MG.DAT')
            shutil.copyfile(marsh, work / 'MG.DAT')
        env = os.environ.copy()
        if platform == 'dos':
            command = [dosbox, '-silent', '-fastlaunch', '-defaultconf',
                       '-defaultdir', str(work), '-set', 'cpu core=normal',
                       '-set', 'cpu cycles=fixed 20000',
                       '-set', 'cpu fpu=' + ('true' if coprocessor else 'false'),
                       '-set', 'sdl output=surface',
                       '-c', 'mount c .', '-c', 'c:',
                       '-c', 'MODEL.EXE INPUT.DAT OUTPUT.OUT', '-c', 'exit',
                       '-time-limit', str(timeout)]
        else:
            command = [str(work / 'MODEL.EXE'), 'INPUT.DAT', 'OUTPUT.OUT']
            if os.name != 'nt':
                command.insert(0, wine)
                env['WINEDEBUG'] = '-all'
                if wine_prefix:
                    env['WINEPREFIX'] = str(Path(wine_prefix).resolve())
        process = subprocess.run(command, cwd=work, env=env, capture_output=True,
                                 timeout=timeout + 10)
        if log_path:
            Path(log_path).parent.mkdir(parents=True, exist_ok=True)
            Path(log_path).write_bytes(process.stdout + process.stderr)
        candidates = [work / 'OUTPUT.OUT', work / 'output.out']
        result = next((p for p in candidates if p.is_file()), None)
        if process.returncode or result is None:
            raise RuntimeError(f'{program} did not produce a reference output (exit {process.returncode}).\n'
                               + (process.stdout + process.stderr).decode(errors='replace')[-4000:])
        content = result.read_bytes()
        output_path = Path(output_path)
        output_path.parent.mkdir(parents=True, exist_ok=True)
        output_path.write_bytes(content)
        return {'program': program, 'binary_sha256': original_hash,
                'input_sha256': hashlib.sha256(Path(input_path).read_bytes()).hexdigest(),
                'output_sha256': hashlib.sha256(content).hexdigest(),
                'output_bytes': len(content),
                'floating_point': ('coprocessor' if coprocessor else 'original software emulator') if platform == 'dos' else 'original Windows runtime'}


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('program', choices=PROGRAMS)
    parser.add_argument('input', type=Path)
    parser.add_argument('output', type=Path)
    parser.add_argument('--coprocessor', action='store_true')
    parser.add_argument('--timeout', type=int, default=30)
    parser.add_argument('--dosbox', default='dosbox-x')
    parser.add_argument('--wine', default='wine')
    parser.add_argument('--wine-prefix')
    parser.add_argument('--log', type=Path)
    args = parser.parse_args()
    print(json.dumps(run_original(args.program, args.input, args.output,
                                 timeout=args.timeout, coprocessor=args.coprocessor,
                                 dosbox=args.dosbox, wine=args.wine,
                                 wine_prefix=args.wine_prefix, log_path=args.log), indent=2))
