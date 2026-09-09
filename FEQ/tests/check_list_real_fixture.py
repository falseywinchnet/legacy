#!/usr/bin/env python3
"""Require complete original list-directed REAL*4 records, including whitespace."""
from pathlib import Path
import subprocess
import sys

fixtures = Path(__file__).resolve().parent/'reference/list_real'
inputs = (fixtures/'inputs.bin').read_bytes()
expected = (fixtures/'outputs.bin').read_bytes()
process = subprocess.run([sys.argv[1], '--list-real'], input=inputs, capture_output=True, timeout=30)
if process.returncode or process.stdout != expected:
    print(f'List REAL mismatch: exit {process.returncode}; expected {len(expected)} bytes, received {len(process.stdout)}.')
    if process.stderr:
        print(process.stderr.decode(errors='replace'))
    for index, (left, right) in enumerate(zip(expected, process.stdout)):
        if left != right:
            print(f'First different byte: {index}; original 0x{left:02x}, C++ 0x{right:02x}.')
            break
    raise SystemExit(1)
print(f'All {len(inputs)//8} original list-directed REAL*4 records match every byte.')
