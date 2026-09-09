#!/usr/bin/env python3
"""Compare complete matrix COMMON records and optionally extract direct tests.

No words are masked or compared with a tolerance. Unused COMMON storage remains
part of the comparison. Named field counts make the first divergence reviewable.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct

SIZE = 3790428
# FEQ 10.61 matcom.cmn, using the released ARSIZE.PRM dimensions.
FIELDS = [('header',0,3,'i'),('lower',12,24800,'i'),('diagonal',99212,24801,'i'),
          ('equation_end',198416,24800,'i'),('variable_id',297616,24800,'i'),
          ('block_start',396816,4401,'i'),('block_end',414420,4401,'i'),
          ('block_kind',432024,4401,'i'),('address',449628,16800,'i'),
          ('coefficients',516828,744000,'f'),('rhs',3492828,24800,'f'),
          ('high_flow_factor',3592028,24800,'f'),('high_flow_state',3691228,24800,'i')]


def records(path):
    data = path.read_bytes()
    if not data or len(data)%SIZE:
        raise ValueError('Missing or partial matrix COMMON trace.')
    return data,[data[first:first+SIZE] for first in range(0,len(data),SIZE)]


def fixture(data,name):
    blocks,count,unused = struct.unpack_from('<3i',data)
    if not 0 < blocks <= 4401 or not 0 < count <= 24800:
        raise ValueError('Invalid captured matrix dimensions.')
    def words(offset,size,kind='i'):
        return list(struct.unpack_from('<'+str(size)+kind,data,offset))
    diagonal = words(99212,count+1)
    if not 0 < diagonal[-1] <= 744000:
        raise ValueError('Invalid captured matrix coefficient count.')
    return {'name':name,'n':count,'begin':words(396816,blocks),'end':words(414420,blocks),
            'kind':words(432024,blocks),'diagonal':diagonal,'lower':words(12,count),
            'coefficients':words(516828,diagonal[-1],'f'),'rhs':words(3492828,count,'f'),'solve':True}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('original',type=Path)
    parser.add_argument('native',type=Path,nargs='?')
    parser.add_argument('--output',type=Path)
    parser.add_argument('--extract-fixtures',type=Path)
    args = parser.parse_args()
    if args.native and not args.output:
        parser.error('A comparison requires --output.')
    if not args.native and not args.extract_fixtures:
        parser.error('Supply a native trace to compare or --extract-fixtures to extract original matrices.')
    left, originals = records(args.original)
    if args.extract_fixtures:
        args.extract_fixtures.write_text(json.dumps([fixture(data,f'model-matrix-{index+1}')
                                                   for index,data in enumerate(originals)],indent=2)+'\n')
    if not args.native:
        print(f'{len(originals)} original matrices extracted.')
        return
    right, natives = records(args.native)
    results = []
    for record_index,(original,native) in enumerate(zip(originals,natives)):
        fields = []
        for name,offset,count,kind in FIELDS:
            differences = [index for index in range(count)
                           if original[offset+4*index:offset+4*index+4] != native[offset+4*index:offset+4*index+4]]
            if not differences:
                continue
            examples = []
            for index in differences[:8]:
                position = offset+index*4
                examples.append({'zero_based_index':index,'original_bits':original[position:position+4].hex(),
                                 'native_bits':native[position:position+4].hex(),
                                 'original':struct.unpack_from('<'+kind,original,position)[0],
                                 'native':struct.unpack_from('<'+kind,native,position)[0]})
            fields.append({'field':name,'changed_words':len(differences),'first_differences':examples})
        results.append({'record':record_index+1,'exact_bytes':original==native,'fields':fields,
                        'original_dimensions':struct.unpack_from('<3i',original),
                        'native_dimensions':struct.unpack_from('<3i',native)})
    result = {'original_sha256':hashlib.sha256(left).hexdigest(),'native_sha256':hashlib.sha256(right).hexdigest(),
              'record_bytes':SIZE,'original_records':len(originals),'native_records':len(natives),
              'exact_bytes':left==right,'records':results}
    args.output.write_text(json.dumps(result,indent=2)+'\n')
    for result in results:
        print(f'Matrix {result["record"]}: '+('EXACT BYTES' if result['exact_bytes'] else
              str(sum(field['changed_words'] for field in result['fields']))+' differing words.'))
    raise SystemExit(0 if left==right else 1)


if __name__ == '__main__':
    main()
