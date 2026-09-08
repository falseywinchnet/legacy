#!/usr/bin/env python3
"""Call original WHAFIS numerical procedures from a temporary Windows driver."""
import argparse
import os
from pathlib import Path
import struct
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[1]
ROUTINES = {'SHBM':(0x407dd3,3),'HIN':(0x407e9b,5),'T':(0x409ac5,4),'HM0':(0x409ffe,3)}


def probe(routine, records, prefix):
    import pefile
    original=ROOT/'originals/whafis4/WHAFIS4.exe';pe=pefile.PE(original)
    imports={i.name.decode():i.address for d in pe.DIRECTORY_ENTRY_IMPORT for i in d.imports if i.name}
    base=0x401000;buf=0x485000;count=buf+32;filename=base+400
    code=bytearray();labels={};fixups=[]
    def push(v):code.extend(b'\x68'+struct.pack('<I',v&0xffffffff))
    def api(name):code.extend(b'\xff\x15'+struct.pack('<I',imports[name]))
    def jump(op,label):code.extend(op);fixups.append((len(code),label));code.extend(b'\x00'*4)
    # CreateFileA(CASES.BIN, GENERIC_READ, FILE_SHARE_READ, nullptr,
    #             OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr).
    for v in (0,0x80,3,0,1,0x80000000,filename):push(v)
    api('CreateFileA');code.extend(b'\x8b\xf0')
    push(-11);api('GetStdHandle');code.extend(b'\x8b\xd8')
    labels['loop']=len(code)
    push(0);push(count);push(20);push(buf);code.extend(b'\x56');api('ReadFile')
    code.extend(b'\x83\x3d'+struct.pack('<I',count)+b'\x14');jump(b'\x0f\x85','done')
    for i in range(8):code.extend(bytes((0xdd,0xc0+i))) # Clear unused x87 register tags.
    address,args=ROUTINES[routine]
    for i in reversed(range(args)):push(buf+4*i)
    code.extend(b'\xe8'+struct.pack('<i',address-(base+len(code)+5)))
    code.extend(b'\xd9\x1d'+struct.pack('<I',buf+20))
    push(0);push(count);push(4);push(buf+20);code.extend(b'\x53');api('WriteFile')
    jump(b'\xe9','loop');labels['done']=len(code)
    code.extend(b'\x56');api('CloseHandle');push(0);api('ExitProcess')
    for at,label in fixups:struct.pack_into('<i',code,at,labels[label]-(at+4))
    assert len(code)<400
    code.extend(b'\x90'*(400-len(code)));code.extend(b'CASES.BIN\0')
    data=bytearray(original.read_bytes());off=pe.get_offset_from_rva(base-pe.OPTIONAL_HEADER.ImageBase)
    data[off:off+len(code)]=code
    with tempfile.TemporaryDirectory(prefix='whafis-probe-') as temp:
        work=Path(temp);(work/'PROBE.EXE').write_bytes(data);(work/'CASES.BIN').write_bytes(records)
        env=os.environ.copy();env.update(WINEPREFIX=str(prefix.resolve()),WINEDEBUG='-all')
        run=subprocess.run(['wine','PROBE.EXE'],cwd=work,env=env,stdout=subprocess.PIPE,stderr=subprocess.PIPE,timeout=30)
        if run.returncode or len(run.stdout)!=len(records)//5:
            raise RuntimeError((run.returncode,len(run.stdout),run.stderr.decode(errors='replace')))
        return run.stdout


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('routine',choices=ROUTINES);p.add_argument('input',type=Path);p.add_argument('output',type=Path)
    p.add_argument('--wine-prefix',type=Path,default=ROOT/'build/oracle/wine')
    a=p.parse_args();a.output.write_bytes(probe(a.routine,a.input.read_bytes(),a.wine_prefix));print('Captured',a.output)
