#!/usr/bin/env python3
"""Recover embedded NB02 build metadata from the original RUNUP2.EXE.

Only the observed 16-bit NB02/C6 layout is supported. Source text is not
reconstructed. Raw subsection bytes accompany the decoded record fields.
Format reference: Microsoft's cvdump (ReadNB02, GetSSTMOD, DumpSrcLn,
DumpModSymC6, C6ProcSym), https://github.com/microsoft/microsoft-pdb/tree/master/cvdump
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct


def extract(path, output):
    exe = path.read_bytes()
    def u16(b, p):
        return struct.unpack_from('<H', b, p)[0]
    def u32(b, p):
        return struct.unpack_from('<I', b, p)[0]
    def name(b, p):
        length = b[p]
        if p + 1 + length > len(b):
            raise ValueError('Truncated name')
        return b[p + 1:p + 1 + length].decode('ascii'), p + 1 + length
    if exe[-8:-4] != b'NB02':
        raise ValueError('Missing NB02 trailer')
    base = len(exe) - u32(exe, len(exe) - 4)
    if exe[base:base + 4] != b'NB02':
        raise ValueError('Invalid debug base')
    directory = base + u32(exe, base + 4)
    count = u16(exe, directory)
    if directory + 2 + count * 10 != len(exe) - 8:
        raise ValueError('Unexpected directory extent')
    result = {'input':str(path), 'sha256':hashlib.sha256(exe).hexdigest(),
              'format':'CodeView NB02 / C6 / 16-bit', 'debug_offset':base,
              'debug_bytes_including_trailer':len(exe)-base,
              'directory_entries':count, 'modules':{}, 'libraries':[]}
    output.mkdir(parents=True, exist_ok=True)
    (output/'RUNUP2.NB02.bin').write_bytes(exe[base:])
    raw = output/'subsections'
    raw.mkdir(exist_ok=True)
    for i in range(count):
        kind, module, offset, length = struct.unpack_from('<HHIH', exe, directory+2+i*10)
        if offset + length > directory-base:
            raise ValueError('Subsection outside data region')
        b = exe[base+offset:base+offset+length]
        key=f'{module:03d}-{kind:04x}'
        (raw/(key+'.bin')).write_bytes(b)
        if kind == 0x106:
            p=0
            while p<len(b):
                value,p=name(b,p)
                if value:result['libraries'].append(value)
            continue
        m=result['modules'].setdefault(str(module),{'subsections':[]})
        m['subsections'].append({'kind':hex(kind),'file_offset':base+offset,
                                'bytes':length,'raw':'subsections/'+key+'.bin'})
        if kind==0x101:
            seg,off,size,overlay,lib,nseg=struct.unpack_from('<6H',b)
            value,end=name(b,12)
            if end > len(b):raise ValueError('Unsupported module layout')
            if end < len(b):m['additional_segment_bytes_hex']=b[end:].hex()
            m.update(name=value,segment=seg,code_offset=off,code_bytes=size,library_index=lib)
        elif kind==0x102:
            p=0; pubs=[]
            while p<len(b):
                off,seg,typ=struct.unpack_from('<3H',b,p);value,end=name(b,p+6)
                pubs.append({'name':value,'segment':seg,'offset':off,'type_index':hex(typ)})
                p=end
            m['public_symbols']=pubs
        elif kind==0x109:
            p=0;files=[]
            while p<len(b):
                value,p=name(b,p);seg,n=struct.unpack_from('<2H',b,p);p+=4
                entries=[]
                for _ in range(n):
                    line,off=struct.unpack_from('<2H',b,p);p+=4
                    entries.append({'line':line,'code_offset':off})
                files.append({'name':value,'segment':seg,'line_mappings':entries})
            if p!=len(b):raise ValueError('Invalid line table extent')
            m['source_files']=files
        elif kind==0x104:
            p=0;records=[]
            while p<len(b):
                size=b[p]+1;r=b[p:p+size]
                if len(r)!=size or size<2:raise ValueError('Invalid symbol size')
                k=r[1]
                if k&0x80:raise ValueError('Unexpected 32-bit symbol')
                rec={'kind':hex(k),'file_offset':base+offset+p,'raw_hex':r.hex()}
                if k==1:
                    off,typ,sizecode,start,end,res=struct.unpack_from('<6H',r,2)
                    value,_=name(r,15)
                    rec.update(name=value,code_offset=off,code_bytes=sizecode,
                               type_index=hex(typ),return_type=r[14])
                elif k==4:
                    off,typ=struct.unpack_from('<hH',r,2);value,_=name(r,6)
                    rec.update(name=value,bp_offset=off,type_index=hex(typ))
                elif k==5:
                    off,seg,typ=struct.unpack_from('<3H',r,2);value,_=name(r,8)
                    rec.update(name=value,segment=seg,data_offset=off,type_index=hex(typ))
                records.append(rec);p+=size
            m['symbol_records']=records
    (output/'build-metadata.json').write_text(json.dumps(result,indent=2)+'\n')
    for m in result['modules'].values():
        if 'source_files' in m:
            for f in m['source_files']:
                lines=f['line_mappings']
                print(f["name"],len(lines),'line mappings, maximum line',max(x['line'] for x in lines))
            print('Procedures:',', '.join(r['name'] for r in m.get('symbol_records',[]) if r['kind']=='0x1'))
    print('Modules:',len(result['modules']),'directory entries:',count,'debug bytes:',len(exe)-base)


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('exe',type=Path);parser.add_argument('output',type=Path)
    args=parser.parse_args();extract(args.exe,args.output)
