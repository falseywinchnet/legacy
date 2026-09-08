#!/usr/bin/env python3
"""Compare native CHAMP geometry to unchanged original p-code results."""
import json
from pathlib import Path
import subprocess
import sys
import tempfile

binary, root = Path(sys.argv[1]), Path(sys.argv[2])
reference = root / 'tests/reference/champ/routines'
manifest = json.loads((reference / 'manifest.json').read_text())
with tempfile.TemporaryDirectory(prefix='champ-check-') as work:
    for routine, item in manifest['routines'].items():
        output = Path(work) / (routine + '.bin')
        subprocess.run([binary, routine, reference / (routine + '.input.bin'), output], check=True, timeout=20)
        expected = (reference / (routine + '.expected.bin')).read_bytes()
        actual = output.read_bytes()
        if actual != expected:
            stride = len(expected) // item['records']
            failures = [i // stride for i in range(0, len(expected), stride) if actual[i:i + stride] != expected[i:i + stride]]
            raise SystemExit(f'{routine}: {len(failures)} raw results differ; first records {failures[:8]}')
        print(f"{routine}: {item['records']} original results match bit for bit")
