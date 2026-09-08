#!/usr/bin/env python3
"""Compare complete native reports with preserved original executable output."""
import json
from pathlib import Path
import subprocess
import sys
import tempfile

binary, root = Path(sys.argv[1]), Path(sys.argv[2])
manifest = json.loads((root / 'tests/reference/runup/manifest.json').read_text())
with tempfile.TemporaryDirectory(prefix='runup-check-') as work:
    for case in manifest['cases']:
        output = Path(work) / (case['name'] + '.out')
        completed = subprocess.run([binary, root / case['input'], output], capture_output=True)
        if completed.returncode != case.get('expected_exit', 0):
            raise SystemExit(f"{case['name']}: native run failed: {completed.stderr.decode(errors='replace')}")
        expected, actual = (root / case['output']).read_bytes(), output.read_bytes()
        if actual != expected:
            offset = next((i for i, (a, b) in enumerate(zip(actual, expected)) if a != b), min(len(actual), len(expected)))
            raise SystemExit(f"{case['name']}: report mismatch at byte {offset}; expected {len(expected)} bytes, got {len(actual)}")
        print(f"{case['name']}: {len(actual)} bytes match the original exactly")
