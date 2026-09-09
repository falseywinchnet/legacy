#!/usr/bin/env python3
"""Check the complete CHAMP project workflow against original engine runs."""
import json
from pathlib import Path
import subprocess
import sys
import tempfile

binary, root = Path(sys.argv[1]), Path(sys.argv[2])
reference = root / 'tests/reference/champ/workflow'
manifest = json.loads((reference / 'manifest.json').read_text())
volatile = (b' Executed on: ', b' Input file:  ', b' Output file: ')
with tempfile.TemporaryDirectory(prefix='champ-project-') as work:
    subprocess.run([binary, root, work], check=True)
    compared = 0
    for case in manifest['cases']:
        expected_input = (reference / case['input']).read_bytes()
        actual_input = (Path(work) / case['input']).read_bytes()
        if actual_input != expected_input:
            raise SystemExit(f"{case['name']}: project input generation changed")
        expected = (reference / case['output']).read_bytes()
        actual = (Path(work) / case['output']).read_bytes()
        if case['program'] == 'whafis4':
            expected = b''.join(line for line in expected.splitlines(keepends=True) if not line.startswith(volatile))
            actual = b''.join(line for line in actual.splitlines(keepends=True) if not line.startswith(volatile))
        if actual != expected:
            offset = next((i for i, (a, b) in enumerate(zip(actual, expected)) if a != b), min(len(actual), len(expected)))
            raise SystemExit(f"{case['name']}: project report differs from original at byte {offset}")
        compared += len(expected)
    print(f'{len(manifest["cases"])} complete project-generated reports match {compared:,} original bytes (WHAFIS execution metadata excluded).')
