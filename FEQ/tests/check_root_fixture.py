#!/usr/bin/env python3
"""Require every bracket field and trial argument captured from the original."""
from pathlib import Path
import subprocess
import sys
import json

method = next((argument[2:] for argument in sys.argv[2:] if argument in ('--regflt','--rgf','--rgf5')), 'rgf3')
directory = 'root_solver' if method == 'rgf3' else 'root_solver_'+method
fixtures = Path(__file__).resolve().parent/'reference'/directory
inputs = (fixtures/'inputs.bin').read_bytes()
expected = (fixtures/'outputs.bin').read_bytes()
process = subprocess.run([sys.argv[1],*sys.argv[2:]],input=inputs,capture_output=True,timeout=30)
if process.returncode or process.stdout != expected:
    print(f'Root mismatch: exit {process.returncode}; expected {len(expected)} bytes, received {len(process.stdout)}.')
    if process.stderr:
        print(process.stderr.decode(errors='replace'))
    for index,(left,right) in enumerate(zip(expected,process.stdout)):
        if left != right:
            print(f'First different byte: {index}; original 0x{left:02x}, C++ 0x{right:02x}.')
            break
    raise SystemExit(1)
count = json.loads((fixtures/'manifest.json').read_text())['cases']
print(f'All {count} original root cases match every output bit and trial argument.')
