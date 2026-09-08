#!/usr/bin/env python3
import struct
from pathlib import Path
import subprocess
import sys
import tempfile

binary, routine, root = Path(sys.argv[1]), sys.argv[2], Path(sys.argv[3])
reference = root/'tests/reference/whafis4/routines'
with tempfile.TemporaryDirectory(prefix='whafis-routine-') as work:
    actual = Path(work)/'actual.bin'
    subprocess.run([binary, routine, reference/(routine+'.input.bin'), actual], check=True)
    expected, got = (reference/(routine+'.expected.bin')).read_bytes(), actual.read_bytes()
    if expected != got:
        bad = [i//4 for i in range(0, min(len(expected),len(got)),4) if expected[i:i+4] != got[i:i+4]]
        raise SystemExit(f'{routine}: {len(bad)} differing original result words; first cases {bad[:8]}')
    print(f'{routine}: {len(got)//4} original binary32 values match exactly')
