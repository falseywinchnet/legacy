#!/usr/bin/env python3
"""Capture original WHAFIS COMMON storage after wave propagation.

Only a temporary executable copy is patched, immediately before its ECHO call.
All preceding input processing and wave calculations are the original program.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import struct
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[1]
DATA_START, DATA_END = 0x44f000, 0x488000
BOUNDARIES = {'wave': (0x402e68, 0), 'fetch-coefficients': (0x4050b6, 228),
              'fetch-done': (0x406242, 228)}


def capture(input_path, destination, wine_prefix, boundary='wave', visit=1):
    import capstone
    import pefile
    original = ROOT/'originals/whafis4/WHAFIS4.exe'
    pe = pefile.PE(original)
    imports = {i.name.decode():i.address for d in pe.DIRECTORY_ENTRY_IMPORT for i in d.imports if i.name}
    hook, frame_bytes = BOUNDARIES[boundary]
    if boundary == 'wave' and visit != 1: raise ValueError('Wave boundary supports the first transect only')
    stub, counter = 0x449200, DATA_END-16
    md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
    displaced=bytearray()
    for instruction in md.disasm(pe.get_data(hook-0x400000,20),hook):
        displaced.extend(instruction.bytes)
        if len(displaced)>=5:break
    code=bytearray(b'\x9c\x60') # Preserve caller registers and integer flags on skipped visits.
    code.extend(b'\xff\x05'+struct.pack('<I',counter))
    code.extend(b'\x81\x3d'+struct.pack('<II',counter,visit))
    code.extend(b'\x0f\x85');skip_fixup=len(code);code.extend(b'\x00'*4)
    def push(value): code.extend(b'\x68'+struct.pack('<I',value&0xffffffff))
    def call(name): code.extend(b'\xff\x15'+struct.pack('<I',imports[name]))
    code.extend(b'\xd9\x3d'+struct.pack('<I',DATA_END-4)) # Retain original x87 control word.
    push(-11); call('GetStdHandle')
    code.extend(b'\x8b\xd8')
    push(0);push(counter+8);push(DATA_END-DATA_START);push(DATA_START);code.extend(b'\x53')
    call('WriteFile')
    if frame_bytes:
        code.extend(b'\x8d\x85'+struct.pack('<i',-frame_bytes))
        push(0);push(counter+8);push(frame_bytes);code.extend(b'\x50\x53');call('WriteFile')
    push(0);call('ExitProcess')
    struct.pack_into('<i',code,skip_fixup,len(code)-(skip_fixup+4))
    code.extend(b'\x61\x9d');code.extend(displaced)
    code.extend(b'\xe9'+struct.pack('<i',hook+len(displaced)-(stub+len(code)+5)))
    binary=bytearray(original.read_bytes());offset=pe.get_offset_from_rva(hook-pe.OPTIONAL_HEADER.ImageBase)
    binary[offset:offset+len(displaced)]=b'\xe9'+struct.pack('<i',stub-(hook+5))+b'\x90'*(len(displaced)-5)
    stub_offset=pe.get_offset_from_rva(stub-pe.OPTIONAL_HEADER.ImageBase)
    assert not any(binary[stub_offset:stub_offset+len(code)]), 'Stub region must be unused padding'
    binary[stub_offset:stub_offset+len(code)]=code
    with tempfile.TemporaryDirectory(prefix='whafis-capture-') as temp:
        work=Path(temp);(work/'MODEL.EXE').write_bytes(binary)
        shutil.copyfile(input_path,work/'INPUT.DAT');shutil.copyfile(ROOT/'originals/whafis4/MG.DAT',work/'MG.DAT')
        env=os.environ.copy();env.update(WINEPREFIX=str(wine_prefix.resolve()),WINEDEBUG='-all')
        run=subprocess.run(['wine','MODEL.EXE','INPUT.DAT','OUTPUT.OUT'],cwd=work,env=env,stdout=subprocess.PIPE,stderr=subprocess.PIPE,timeout=30)
        if len(run.stdout)!=DATA_END-DATA_START+frame_bytes:raise RuntimeError((run.returncode,len(run.stdout),run.stderr.decode(errors='replace')))
        destination.parent.mkdir(parents=True,exist_ok=True);destination.write_bytes(run.stdout)
    fields={};offset=0x47a2a0
    for name,count,kind in [('tof',1,'f'),('param',10,'f'),('bsfo',1,'f'),('befo',1,'f'),('whi',1,'f'),('wht',1,'f'),('nfo',1,'i'),('hbw',1000,'f'),('ap',1000,'f'),('set',1,'f'),('se',1,'f'),('steg',1000,'f'),('elz',1000,'f'),('gs',1000,'f'),('ew',1000,'f'),('sa',5000,'f'),('m',1,'i'),('nap',1,'i')]:
        values=struct.unpack_from('<'+kind*count,run.stdout,offset-DATA_START)
        fields[name]={'address':hex(offset),'value':values[0] if count==1 else values}
        offset+=count*4
    frame = {str(offset):struct.unpack_from('<f',run.stdout,len(run.stdout)+offset)[0]
             for offset in range(-frame_bytes,0,4)}
    destination.with_suffix('.json').write_text(json.dumps({'binary_sha256':hashlib.sha256(original.read_bytes()).hexdigest(),'hook':hex(hook),'visit':visit,'fields':fields,'frame':frame},indent=2)+'\n')
    print('Captured',len(run.stdout),'original bytes to',destination)


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('input',type=Path);parser.add_argument('output',type=Path)
    parser.add_argument('--wine-prefix',type=Path,default=ROOT/'build/oracle/wine')
    parser.add_argument('--boundary',choices=BOUNDARIES,default='wave');parser.add_argument('--visit',type=int,default=1)
    args=parser.parse_args();capture(args.input,args.output,args.wine_prefix,args.boundary,args.visit)
