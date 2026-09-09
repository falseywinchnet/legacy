#!/usr/bin/env python3
"""Byte comparison that excludes only WHAFIS's three execution-metadata lines."""
import difflib
import json
from pathlib import Path
import subprocess
import sys
import tempfile


def normalize(data):
    prefixes = (b' Executed on: ', b' Input file:  ', b' Output file: ')
    return b''.join(line for line in data.splitlines(keepends=True) if not line.startswith(prefixes))


if __name__ == '__main__':
    binary, root = Path(sys.argv[1]), Path(sys.argv[2])
    manifest = json.loads((root/'tests/reference/whafis4/manifest.json').read_text())
    total = 0
    with tempfile.TemporaryDirectory(prefix='whafis-check-') as work:
        for case in manifest['cases']:
            output = Path(work)/(case['name']+'.out')
            run = subprocess.run([binary, root/case['input'], output], capture_output=True, timeout=30)
            if run.returncode != case.get('expected_exit', 0):
                raise SystemExit(f"{case['name']}: {run.stderr.decode(errors='replace')}")
            expected = normalize((root/case['output']).read_bytes())
            actual = normalize(output.read_bytes())
            if actual != expected:
                difference = ''.join(difflib.unified_diff(expected.decode().splitlines(True), actual.decode().splitlines(True)))
                raise SystemExit(f"{case['name']}: report mismatch\n{difference[:6000]}")
            total += len(actual)
            print(f"{case['name']}: {len(actual)} non-metadata bytes match the original")
    print(f"{len(manifest['cases'])} complete reports, {total} compared bytes")
