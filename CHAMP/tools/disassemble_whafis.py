#!/usr/bin/env python3
"""Disassemble named WHAFIS 4G procedures using its retained traceback table."""
import json
from pathlib import Path
import re
import struct
import capstone
import pefile

ROOT = Path(__file__).resolve().parents[1]
pe = pefile.PE(ROOT/'originals/whafis4/WHAFIS4.exe')
base = pe.OPTIONAL_HEADER.ImageBase
trace = next(s for s in pe.sections if s.Name.startswith(b'.trace')).get_data()
entries = []
for i in range(len(trace)-12):
    if trace[i:i+2] != b'\x02\x00': continue
    length, address = struct.unpack_from('<HI', trace, i+2)
    name = trace[i+8:i+8+length]
    if 1 <= length <= 30 and 0x401000 <= address < 0x440000 and re.fullmatch(rb'[A-Z][A-Z0-9_]*', name):
        entries.append({'name':name.decode(),'address':address,'trace_offset':i})
entries.sort(key=lambda e:e['address'])
out = ROOT/'build/whafis-disassembly'; out.mkdir(parents=True,exist_ok=True)
(out/'procedures.json').write_text(json.dumps(entries,indent=2)+'\n')
md = capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
md.detail=True
for index,entry in enumerate(entries):
    address=entry['address']; end=entries[index+1]['address'] if index+1<len(entries) else 0x40d000
    lines=[]
    for insn in md.disasm(pe.get_data(address-base,end-address),address):
        comments=[]
        for op in insn.operands:
            if op.type==capstone.x86.X86_OP_MEM and not op.mem.base and not op.mem.index:
                va=op.mem.disp
                if 0x44a100 <= va < 0x44acc0 and op.size==4:
                    data=pe.get_data(va-base,4)
                    if len(data)==4:comments.append(f'f32={struct.unpack("<f",data)[0]:.12g}')
        line=f'{insn.address:08x}  {insn.bytes.hex():22} {insn.mnemonic:8} {insn.op_str}'
        if comments:line+=' ; '+', '.join(comments)
        lines.append(line)
    (out/(entry['name']+'.asm')).write_text('\n'.join(lines)+'\n')
print('Disassembled',len(entries),'original procedures to',out)
