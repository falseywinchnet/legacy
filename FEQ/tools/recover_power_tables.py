#!/usr/bin/env python3
"""Recover numerical approximation coefficients from the retained FEQUTL.

Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
These are numerical constants, not copied executable instructions. Hexadecimal
floating literals preserve their exact values across supported C++ compilers.
"""
import argparse
import hashlib
from pathlib import Path
import struct
from probe_geometry_original import ORIGINAL_SHA256
from probe_profile_original import ROOT


def main():
    import pefile
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args()
    original=(ROOT/'originals/feq1061/wrdapp/FEQ_10.61/BIN/fequtl.exe').read_bytes()
    if hashlib.sha256(original).hexdigest()!=ORIGINAL_SHA256:raise ValueError('Original FEQUTL hash changed.')
    pe=pefile.PE(data=original)
    text=['// Numerical coefficients recovered from FEQUTL 5.80; see tools/recover_power_tables.py.',
          '// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.',
          '// Original executable SHA-256: '+ORIGINAL_SHA256]
    for name,address,count in [('logarithm_table',0x54ddb0,1024),('exponential_table',0x54fe80,128),('real_exponential_table',0x54db90,16)]:
        data=pe.get_data(address-pe.OPTIONAL_HEADER.ImageBase,8*count)
        numbers=struct.unpack('<'+str(count)+'d',data)
        text.extend(['','// Original VA '+hex(address)+'; coefficient bytes SHA-256: '+hashlib.sha256(data).hexdigest(),
                     'constexpr double '+name+'['+str(count)+'] = {'])
        for first in range(0,count,4):text.append('    '+', '.join(value.hex() for value in numbers[first:first+4])+',')
        text.append('};')
    args.output.write_text('\n'.join(text)+'\n')


if __name__=='__main__':main()
