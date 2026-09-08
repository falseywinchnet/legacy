#!/usr/bin/env python3
"""Read original VB project metadata without running CHAMP.

Format reference: https://github.com/williballenthin/python-vb
(ProjectData, ObjectTable, PublicObjectDescriptor). This is a small independent
reader of the observed layout; it does not reconstruct Visual Basic source.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
import struct


def extract(path):
    data=path.read_bytes()
    def u16(p):return struct.unpack_from('<H',data,p)[0]
    def u32(p):return struct.unpack_from('<I',data,p)[0]
    if data[:2]!=b'MZ':raise ValueError('Expected PE executable')
    pe=u32(60)
    if data[pe:pe+4]!=b'PE\0\0':raise ValueError('Expected PE signature')
    opt=pe+24
    if u16(opt)!=0x10b:raise ValueError('Expected PE32')
    base=u32(opt+28);table=opt+u16(pe+20);sections=[]
    for i in range(u16(pe+6)):
        p=table+i*40;virtual_size,rva,size,raw=struct.unpack_from('<4I',data,p+8)
        if raw:sections.append((rva,size,raw))
    def offset(va):
        rva=va-base
        for start,size,raw in sections:
            if start<=rva<start+size:return raw+rva-start
        raise ValueError(f'Pointer {va:x} outside file-backed sections')
    def cstring(va):
        p=offset(va);end=data.find(b'\0',p)
        if end<0:raise ValueError('Unterminated string')
        return data[p:end].decode('ascii')
    # Entry point: PUSH VB-header VA, followed by the runtime startup call.
    entry=offset(base+u32(opt+16))
    if data[entry]!=0x68:raise ValueError('Unsupported VB entrypoint')
    header=offset(u32(entry+1))
    if data[header:header+4]!=b'VB5!':raise ValueError('Missing VB header')
    project=offset(u32(header+0x30))
    table=offset(u32(project+4));count=u16(table+0x2a);objects=offset(u32(table+0x30))
    result={'input':str(path),'sha256':hashlib.sha256(data).hexdigest(),
            'vb_header_file_offset':header,'project_info_file_offset':project,
            'project_name':cstring(u32(table+0x40)),
            'compilation':'p-code' if u32(project+0x20)==0 else 'native',
            'embedded_project_path':data[project+0x24:project+0x234].decode('utf-16le').split('\0',1)[0],
            'objects':[],'embedded_developer_credits':[]}
    for i in range(count):
        p=objects+i*0x30;name=cstring(u32(p+0x18));methods=u32(p+0x1c);names=u32(p+0x20)
        item={'name':name,'descriptor_file_offset':p,'object_flags':hex(u32(p+0x28)),
              'declared_method_count':methods,'method_names':[]}
        if names:
            array=offset(names)
            for j in range(methods):
                address=u32(array+j*4)
                try:
                    item['method_names'].append(cstring(address) if address else None)
                except (ValueError, UnicodeDecodeError):
                    item['method_names'].append({'unparsed_value':hex(address)})
        result['objects'].append(item)
    for match in re.finditer(rb'(?:[\x20-\x7e]\x00){5,}',data):
        value=match.group().decode('utf-16le')
        if value.startswith('Developed by '):
            result['embedded_developer_credits'].append({'file_offset':match.start(),'text':value})
    return result


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('exe',type=Path);parser.add_argument('output',type=Path)
    args=parser.parse_args();result=extract(args.exe)
    args.output.parent.mkdir(parents=True,exist_ok=True)
    args.output.write_text(json.dumps(result,indent=2)+'\n')
    print(result['project_name'],result['compilation'],result['embedded_project_path'])
    print('Objects:',len(result['objects']))
    print(', '.join(o['name'] for o in result['objects']))
