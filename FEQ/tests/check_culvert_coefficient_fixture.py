#!/usr/bin/env python3
"""Require original discharge coefficients and head-ratio flags."""
from pathlib import Path
import subprocess
import sys
import json

fixtures = Path(__file__).resolve().parent/'reference/culvert_coefficient'
inputs = (fixtures/'inputs.bin').read_bytes()
expected = (fixtures/'outputs.bin').read_bytes()
process = subprocess.run([sys.argv[1],'--coefficient'],input=inputs,capture_output=True,timeout=30)
if process.returncode or process.stdout != expected:
    print(f'Coefficient mismatch: exit {process.returncode}; expected {len(expected)} bytes, received {len(process.stdout)}.')
    if process.stderr:
        print(process.stderr.decode(errors='replace'))
    for index,(left,right) in enumerate(zip(expected,process.stdout)):
        if left != right:
            print(f'First different byte: {index}; original 0x{left:02x}, C++ 0x{right:02x}.')
            break
    raise SystemExit(1)
count = json.loads((fixtures/'manifest.json').read_text())['cases']
print(f'All {count} original discharge coefficient cases match every output bit.')
