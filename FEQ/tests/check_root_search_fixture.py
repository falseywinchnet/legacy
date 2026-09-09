#!/usr/bin/env python3
"""Require exact REGFAL/FDROOT outputs and callback state/address relationships."""
import hashlib
import json
from pathlib import Path
import subprocess
import sys

method=next((option[2:] for option in sys.argv[2:] if option in ('--fdroot','--regfal')),'regfal')
directory=Path(__file__).resolve().parent/'reference'/('root_search_'+method)
manifest=json.loads((directory/'manifest.json').read_text())
inputs=(directory/'inputs.bin').read_bytes();expected=(directory/'outputs.bin').read_bytes()
if hashlib.sha256(inputs).hexdigest()!=manifest['input_sha256'] or hashlib.sha256(expected).hexdigest()!=manifest['output_sha256']:
    raise SystemExit('The recorded original root search fixture hash changed.')
process=subprocess.run([sys.argv[1],*sys.argv[2:]],input=inputs,capture_output=True,timeout=30)
if process.returncode or process.stdout!=expected:
    print(f'Root search mismatch: exit {process.returncode}; expected {len(expected)} bytes, received {len(process.stdout)}.')
    if process.stderr:print(process.stderr.decode(errors='replace'))
    for index,(original,native) in enumerate(zip(expected,process.stdout)):
        if original!=native:
            case=index//manifest['output_record_bytes']
            print(f'First different byte {index}, fixture {case}: {manifest["fixtures"][case]["name"]}.')
            break
    raise SystemExit(1)
print(f'All {manifest["cases"]} {method.upper()} cases match every output and callback-visible state/address bit.')
