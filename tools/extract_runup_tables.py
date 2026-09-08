#!/usr/bin/env python3
"""Extract original initialized RUNUP tables using its embedded debug symbols.

Requires output from extract_runup_debug.py. Tables retain their stored INTEGER*4
values and order; no OCR, interpolation, unit conversion, or inferred dimensions.
C6 array layout reference: microsoft/microsoft-pdb, cvdump/type6.cpp OLF_ARRAY.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct


def extract(exe_path, debug_dir, output):
    exe=exe_path.read_bytes();metadata=json.loads((debug_dir/'build-metadata.json').read_text())
    if hashlib.sha256(exe).hexdigest()!=metadata['sha256']:raise ValueError('Wrong input executable')
    section=next(s for s in metadata['modules']['4']['subsections'] if s['kind']=='0x103')
    start=section['file_offset'];blob=exe[start:start+section['bytes']];types={};p=0;index=0x200
    while p<len(blob):
        length=struct.unpack_from('<H',blob,p+1)[0];record=blob[p+3:p+3+length]
        if len(record)!=length:raise ValueError('Truncated type record')
        types[index]=record;p+=3+length;index+=1
    def array_info(index):
        record=types[index]
        if record[0]!=0x78:raise ValueError('Expected C6 array type')
        marker=record[1]
        if marker==0x85:bits=struct.unpack_from('<H',record,2)[0];p=4
        elif marker==0x86:bits=struct.unpack_from('<I',record,2)[0];p=6
        elif marker<0x80:bits=marker;p=2
        else:raise ValueError('Unsupported size encoding')
        if record[p]!=0x83:raise ValueError('Expected element type index')
        element=struct.unpack_from('<H',record,p+1)[0]
        primitive=array_info(element)[1] if element>=0x200 else element
        return bits,primitive
    header_bytes=struct.unpack_from('<H',exe,8)[0]*16
    targets=['DB','PDB','PDB1','PCH','DL1','DL2','DL3','DL4'];symbols={}
    for r in metadata['modules']['4']['symbol_records']:
        if r['kind']=='0x5' and r.get('name') in targets:symbols.setdefault(r['name'],r)
    result={'input':str(exe_path),'input_sha256':metadata['sha256'],
            'interpretation':'Original initialized signed 32-bit integers, flat Fortran storage order; scaling unchanged',
            'arrays':[]}
    for name in targets:
        symbol=symbols[name];bits,primitive=array_info(int(symbol['type_index'],16))
        if primitive!=0x82 or bits%32:raise ValueError('Expected INTEGER*4 array')
        address=header_bytes+symbol['segment']*16+symbol['data_offset'];size=bits//8
        if address+size>metadata['debug_offset']:raise ValueError('Array outside executable load image')
        data=exe[address:address+size];values=list(struct.unpack('<'+'i'*(bits//32),data))
        result['arrays'].append({'name':name,'type_index':symbol['type_index'],
            'segment':symbol['segment'],'segment_offset':symbol['data_offset'],
            'file_offset':address,'bytes':size,'sha256':hashlib.sha256(data).hexdigest(),
            'count':len(values),'values':values})
        print(name,len(values),'integers at file offset',hex(address))
    output.parent.mkdir(parents=True,exist_ok=True);output.write_text(json.dumps(result,indent=2)+'\n')


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('exe',type=Path);parser.add_argument('debug_dir',type=Path);parser.add_argument('output',type=Path)
    args=parser.parse_args();extract(args.exe,args.debug_dir,args.output)
