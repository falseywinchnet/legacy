#!/usr/bin/env python3
"""Verify every original CHAMP table cell, including exact numbers and nulls."""
from collections import Counter
import json
from pathlib import Path
import subprocess
import sys
import tempfile

binary, root = Path(sys.argv[1]), Path(sys.argv[2])
expected = json.loads((root / 'recovery/champ-sample/tables.json').read_text())
with tempfile.TemporaryDirectory(prefix='access-check-') as work:
    output = Path(work) / 'tables.json'
    subprocess.run([binary, root / 'originals/champ2/sample.mdb', output], check=True, timeout=20)
    actual = json.loads(output.read_text())
    if actual.keys() != expected.keys(): raise SystemExit('The imported table inventory differs.')
    for table, rows in expected.items():
        def fingerprint(row):
            # JSON distinguishes 1 from 1.0 textually; database numeric values do
            # not. float.hex retains the exact original float/double value.
            return tuple(sorted((k, v.hex() if isinstance(v, float) else float(v).hex() if isinstance(v, int) else v) for k, v in row.items()))
        if Counter(fingerprint(r) for r in rows) != Counter(fingerprint(r) for r in actual[table]):
            raise SystemExit(f'{table}: imported row values differ from the independent MDB Tools reader')
    print(f'{len(expected)} tables; {sum(len(r) for r in expected.values())} rows; every cell matches')
