#!/usr/bin/env python3
"""Compare native C++ results to raw outputs from the original 1991 routines."""
from pathlib import Path
import subprocess
import sys
import tempfile

executable, routine, directory = sys.argv[1:]
root = Path(directory)
expected = (root / (routine + '.expected.bin')).read_bytes()
with tempfile.TemporaryDirectory() as tmp:
    output = Path(tmp) / 'actual.bin'
    subprocess.run([executable, routine, str(root / (routine + '.input.bin')), str(output)], check=True)
    actual = output.read_bytes()
    if actual != expected:
        failures = [i // 4 for i in range(0, min(len(actual), len(expected)), 4)
                    if actual[i:i + 4] != expected[i:i + 4]]
        raise SystemExit(f'{routine}: byte mismatch at records {failures[:20]}, lengths {len(actual)}/{len(expected)}')
print(f'{routine}: {len(expected) // 4} original routine results match bit for bit')
