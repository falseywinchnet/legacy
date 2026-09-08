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
HOOK = 0x402e68


def capture(input_path, destination, wine_prefix):
    import pefile
    original = ROOT/'originals/whafis4/WHAFIS4.exe'
    pe = pefile.PE(original)
    imports = {i.name.decode():i.address for d in pe.DIRECTORY_ENTRY_IMPORT for i in d.imports if i.name}
    code=bytearray()
    def push(value): code.extend(b'\x68'+struct.pack('<I',value&0xffffffff))
    def call(name): code.extend(b'\xff\x15'+struct.pack('<I',imports[name]))
    code.extend(b'\xd9\x3d'+struct.pack('<I',DATA_END-4)) # Retain original x87 control word.
    push(-11); call('GetStdHandle')
    code.extend(b'\x83\xec\x04\x8b\xd4') # local bytes-written count
    push(0);code.extend(b'\x52');push(DATA_END-DATA_START);push(DATA_START);code.extend(b'\x50')
    call('WriteFile');push(0);call('ExitProcess')
    binary=bytearray(original.read_bytes());offset=pe.get_offset_from_rva(HOOK-pe.OPTIONAL_HEADER.ImageBase)
    binary[offset:offset+len(code)]=code
    with tempfile.TemporaryDirectory(prefix='whafis-capture-') as temp:
        work=Path(temp);(work/'MODEL.EXE').write_bytes(binary)
        shutil.copyfile(input_path,work/'INPUT.DAT');shutil.copyfile(ROOT/'originals/whafis4/MG.DAT',work/'MG.DAT')
        env=os.environ.copy();env.update(WINEPREFIX=str(wine_prefix.resolve()),WINEDEBUG='-all')
        run=subprocess.run(['wine','MODEL.EXE','INPUT.DAT','OUTPUT.OUT'],cwd=work,env=env,stdout=subprocess.PIPE,stderr=subprocess.PIPE,timeout=30)
        if len(run.stdout)!=DATA_END-DATA_START:raise RuntimeError((run.returncode,len(run.stdout),run.stderr.decode(errors='replace')))
        destination.parent.mkdir(parents=True,exist_ok=True);destination.write_bytes(run.stdout)
    fields={};offset=0x47a2a0
    for name,count,kind in [('tof',1,'f'),('param',10,'f'),('bsfo',1,'f'),('befo',1,'f'),('whi',1,'f'),('wht',1,'f'),('nfo',1,'i'),('hbw',1000,'f'),('ap',1000,'f'),('set',1,'f'),('se',1,'f'),('steg',1000,'f'),('elz',1000,'f'),('gs',1000,'f'),('ew',1000,'f'),('sa',5000,'f'),('m',1,'i'),('nap',1,'i')]:
        values=struct.unpack_from('<'+kind*count,run.stdout,offset-DATA_START)
        fields[name]={'address':hex(offset),'value':values[0] if count==1 else values}
        offset+=count*4
    destination.with_suffix('.json').write_text(json.dumps({'binary_sha256':hashlib.sha256(original.read_bytes()).hexdigest(),'hook':hex(HOOK),'fields':fields},indent=2)+'\n')
    print('Captured',len(run.stdout),'original bytes to',destination)


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('input',type=Path);parser.add_argument('output',type=Path)
    parser.add_argument('--wine-prefix',type=Path,default=ROOT/'build/oracle/wine')
    args=parser.parse_args();capture(args.input,args.output,args.wine_prefix)
