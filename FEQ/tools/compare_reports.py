#!/usr/bin/env python3
"""Compare entire outputs, masking only explicitly identified execution clocks.

No whitespace, sign, precision, diagnostic, version, or numerical tolerance is
discarded. A separate raw-byte result accompanies the clock-masked comparison.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re

ROOT = Path(__file__).resolve().parents[1]
CLOCKS = [
    ('run_timestamp', re.compile(rb'(?m)^([ ;*]*Version: +[0-9]+\.[0-9]+ Version date: [^\r\n]*?Date/time of run: )[0-9]{4}/[0-9]{2}/[0-9]{2}: [0-9]{2}\.[0-9]{2}\.[0-9]{2}\.[0-9]{3}(?= *\r?$)')),
    ('elapsed_time', re.compile(rb'(?m)^( (?:Initialization|Computation) time=) +[0-9]+\.[0-9]+ secs or +[0-9]+\.[0-9]+ mins(?=\r?$)')),
]


def mask_clocks(payload):
    counts = {}
    for name, expression in CLOCKS:
        payload, count = expression.subn(rb'\1<EXECUTION-CLOCK>', payload)
        counts[name] = count
    return payload, counts


def compare(expected, actual):
    left, left_counts = mask_clocks(expected)
    right, right_counts = mask_clocks(actual)
    equal = left == right and left_counts == right_counts
    result = {'raw_equal': expected == actual, 'clock_masked_equal': equal,
              'expected_sha256': hashlib.sha256(expected).hexdigest(),
              'actual_sha256': hashlib.sha256(actual).hexdigest(),
              'expected_clock_fields': left_counts, 'actual_clock_fields': right_counts,
              'expected_bytes': len(expected), 'actual_bytes': len(actual)}
    if not equal:
        position = next((i for i, pair in enumerate(zip(left, right)) if pair[0] != pair[1]), min(len(left), len(right)))
        result['first_masked_difference'] = {
            'byte_offset': position, 'line': left[:position].count(b'\n')+1,
            'expected_context': repr(left[max(0, position-60):position+120]),
            'actual_context': repr(right[max(0, position-60):position+120]),
        }
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('actual', type=Path)
    parser.add_argument('--expected', type=Path, default=ROOT / 'originals/feq1061/wrdapp/FEQ_10.61/DATA')
    parser.add_argument('--manifest', type=Path)
    args = parser.parse_args()
    files = [f'feqex{i}.out{suffix}' for i in range(1, 5) for suffix in ('', '.spi', '.wsq')]
    files += ['utlexm.out', 'utlexm.tab', 'utlexm.chx', 'culvert.out', 'culvert.tab']
    results = []
    for name in files:
        expected, actual = args.expected / name, args.actual / name
        if not expected.is_file() or not actual.is_file():
            result = {'path': name, 'clock_masked_equal': False, 'missing': 'expected' if not expected.is_file() else 'actual'}
        else:
            result = dict(path=name, **compare(expected.read_bytes(), actual.read_bytes()))
        results.append(result)
        print(f'{name}: ' + ('EXACT BYTES' if result.get('raw_equal') else 'EXACT EXCEPT CLOCKS' if result['clock_masked_equal'] else 'DIFFERENT'))
    if args.manifest:
        args.manifest.parent.mkdir(parents=True, exist_ok=True)
        args.manifest.write_text(json.dumps({'mask_policy': 'Run timestamps and initialization/computation elapsed clocks only; preserve all other bytes.', 'files': results}, indent=2)+'\n')
    raise SystemExit(0 if all(item['clock_masked_equal'] for item in results) else 1)


if __name__ == '__main__':
    main()
