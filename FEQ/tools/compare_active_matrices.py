#!/usr/bin/env python3
"""Compare every active matrix word across complete model traces, without tolerance.

The compact record contains header, lower profile, diagonal offsets, block
starts/ends/kinds, coefficients, and right-hand side. Its dimensions are read
from each record, so a changed matrix size cannot silently shift the comparison.
Unused COMMON capacity and solver-unrelated banks are deliberately not captured.
Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct


def dimensions(blocks, rows, entries=None):
    if not 0 < blocks <= 4401 or not 0 < rows <= 24800:
        raise ValueError('Invalid captured matrix dimensions.')
    if entries is not None and not 0 < entries <= 744000:
        raise ValueError('Invalid captured coefficient count.')


def records(data):
    result = []
    position = 0
    while position < len(data):
        first = position
        fields = []

        def take(name, count, kind='i'):
            nonlocal position
            end = position+4*count
            if end > len(data):
                raise ValueError('Partial compact matrix record.')
            value = data[position:end]
            fields.append((name, kind, value))
            position = end
            return struct.unpack('<'+str(count)+kind, value)

        blocks, rows, unused = take('header', 3)
        dimensions(blocks, rows)
        take('lower', rows)
        diagonal = take('diagonal', rows+1)
        entries = diagonal[-1]
        dimensions(blocks, rows, entries)
        for name in ('block_start', 'block_end', 'block_kind'):
            take(name, blocks)
        take('coefficients', entries, 'f')
        take('rhs', rows, 'f')
        result.append({'bytes':data[first:position], 'fields':fields,
                       'dimensions':{'blocks':blocks, 'rows':rows, 'entries':entries}})
    if not result:
        raise ValueError('An empty trace cannot establish matrix equivalence.')
    return result


def compare(left, right):
    originals, natives = records(left), records(right)
    changes = []
    exact_records = 0
    for index, (original, native) in enumerate(zip(originals, natives)):
        if original['bytes'] == native['bytes']:
            exact_records += 1
            continue
        fields = []
        for (name, kind, a), (_, _, b) in zip(original['fields'], native['fields']):
            if a == b:
                continue
            differences = [i for i in range(min(len(a), len(b))//4)
                           if a[i*4:i*4+4] != b[i*4:i*4+4]]
            examples = []
            for word in differences[:8]:
                offset = word*4
                examples.append({'zero_based_index':word,
                                 'original_bits':a[offset:offset+4].hex(),
                                 'native_bits':b[offset:offset+4].hex(),
                                 'original':struct.unpack_from('<'+kind, a, offset)[0],
                                 'native':struct.unpack_from('<'+kind, b, offset)[0]})
            fields.append({'field':name, 'original_words':len(a)//4, 'native_words':len(b)//4,
                           'changed_words':len(differences)+abs(len(a)-len(b))//4,
                           'first_differences':examples})
        changes.append({'record':index+1, 'original_dimensions':original['dimensions'],
                        'native_dimensions':native['dimensions'], 'fields':fields})
    return {'scope':'All active solver inputs; no tolerance or masked words.',
            'original_sha256':hashlib.sha256(left).hexdigest(),
            'native_sha256':hashlib.sha256(right).hexdigest(),
            'original_bytes':len(left), 'native_bytes':len(right),
            'original_records':len(originals), 'native_records':len(natives),
            'exact_records':exact_records, 'exact_bytes':left==right, 'differences':changes}


def configuration(full, limit):
    if len(full) != 3790428:
        raise ValueError('Supply exactly one full COMMON record to determine dimensions.')
    blocks, rows, unused = struct.unpack_from('<3i', full)
    dimensions(blocks, rows)
    entries = struct.unpack_from('<i', full, 99212+rows*4)[0]
    dimensions(blocks, rows, entries)
    fields = [(0, 12), (12, rows*4), (99212, (rows+1)*4),
              (396816, blocks*4), (414420, blocks*4), (432024, blocks*4),
              (516828, entries*4), (3492828, rows*4)]
    return {'original_dimensions':{'blocks':blocks, 'rows':rows, 'entries':entries},
            'hooks':[{'routine':'_profac_', 'limit':limit,
                      'captures':[{'symbol':'_matcom_', 'offset':offset, 'bytes':size}
                                  for offset, size in fields]}]}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest='command', required=True)
    config = commands.add_parser('configure', help='Derive a compact trace from one original full matrix.')
    config.add_argument('full_matrix', type=Path)
    config.add_argument('--limit', type=int, default=1024)
    config.add_argument('--output', type=Path, required=True)
    comparison = commands.add_parser('compare', help='Compare two complete compact matrix traces.')
    comparison.add_argument('original', type=Path)
    comparison.add_argument('native', type=Path)
    comparison.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    if args.command == 'configure':
        if not 0 < args.limit <= 1024:
            parser.error('Trace limit must be from 1 through 1024.')
        result = configuration(args.full_matrix.read_bytes(), args.limit)
        print(json.dumps(result['original_dimensions']))
    else:
        result = compare(args.original.read_bytes(), args.native.read_bytes())
        print(f'{result["exact_records"]} of {result["original_records"]} original matrices match exactly; '
              f'{result["native_records"]} native matrices.')
        if result['differences']:
            first = result['differences'][0]
            print(f'First difference: matrix {first["record"]}, '+
                  ', '.join(item['field'] for item in first['fields'])+'.')
    args.output.write_text(json.dumps(result, indent=2)+'\n')
    if args.command == 'compare' and not result['exact_bytes']:
        raise SystemExit(1)


if __name__ == '__main__':
    main()
