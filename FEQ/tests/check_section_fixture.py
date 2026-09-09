#!/usr/bin/env python3
"""Require every section-interpolation output bit captured from the originals."""
from pathlib import Path
import subprocess
import sys

with_moment = len(sys.argv) > 2 and sys.argv[2] == '--first-moment'
fixtures = Path(__file__).resolve().parent/('reference/section_first_moment' if with_moment else 'reference/section_interpolation')
inputs = (fixtures/'inputs.bin').read_bytes()
expected = (fixtures/'outputs.bin').read_bytes()
process = subprocess.run([sys.argv[1]]+(['--first-moment'] if with_moment else []),input=inputs,capture_output=True,timeout=30)
if process.returncode or process.stdout != expected:
    print(f'Section fixture mismatch: exit {process.returncode}; expected {len(expected)} bytes, received {len(process.stdout)}.')
    if process.stderr:
        print(process.stderr.decode(errors='replace'))
    for index,(left,right) in enumerate(zip(expected,process.stdout)):
        if left != right:
            print(f'First different byte: {index}; original 0x{left:02x}, C++ 0x{right:02x}.')
            break
    raise SystemExit(1)
print(f'All {len(inputs)//(72 if with_moment else 64)} original-executable section fixtures match every output bit.')
