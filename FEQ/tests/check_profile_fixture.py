#!/usr/bin/env python3
"""Require every profile-solver output byte to match the original binary."""
from pathlib import Path
import json
import subprocess
import sys

fixtures = Path(sys.argv[2]) if len(sys.argv)>2 else Path(__file__).resolve().parent/'reference/profile_matrix'
expected = (fixtures/'outputs.bin').read_bytes()
process = subprocess.run([sys.argv[1]],input=(fixtures/'inputs.bin').read_bytes(),capture_output=True,timeout=30)
if process.returncode or process.stdout != expected:
    print(f'Profile fixture mismatch: exit {process.returncode}; expected {len(expected)} bytes, received {len(process.stdout)}.')
    if process.stderr:
        print(process.stderr.decode(errors='replace'))
    for index,(left,right) in enumerate(zip(expected,process.stdout)):
        if left != right:
            print(f'First different byte: {index}; original 0x{left:02x}, C++ 0x{right:02x}.')
            break
    raise SystemExit(1)
count = len(json.loads((fixtures/'manifest.json').read_text())['fixtures'])
print(f'All {count} original-executable matrix fixtures match every output bit.')
