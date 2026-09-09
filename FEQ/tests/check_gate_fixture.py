#!/usr/bin/env python3
"""Require every gate or inverse-energy output bit from the original."""
from pathlib import Path
import hashlib
import json
import subprocess
import sys

kind=sys.argv[2]
mode={'gate_residual':'--gate','gate_levels':'--gate-levels','gate_free':'--gate-free',
      'gate_orifice':'--gate-orifice','specific_energy':'--specific-energy'}[kind]
fixtures=Path(__file__).resolve().parent/'reference'/kind
inputs=(fixtures/'inputs.bin').read_bytes();expected=(fixtures/'outputs.bin').read_bytes()
manifest=json.loads((fixtures/'manifest.json').read_text())
assert hashlib.sha256(inputs).hexdigest()==manifest['input_sha256']
assert hashlib.sha256(expected).hexdigest()==manifest['output_sha256']
process=subprocess.run([sys.argv[1],mode],input=inputs,capture_output=True,timeout=30)
if process.returncode or process.stdout != expected:
    print(f'{kind} mismatch: exit {process.returncode}; expected {len(expected)} bytes, received {len(process.stdout)}.')
    if process.stderr:print(process.stderr.decode(errors='replace'))
    for index,(left,right) in enumerate(zip(expected,process.stdout)):
        if left != right:
            print(f'First different byte: {index}; original 0x{left:02x}, C++ 0x{right:02x}.')
            break
    raise SystemExit(1)
count=manifest['cases']
print(f'All {count} original-executable {kind} cases match every output bit.')
