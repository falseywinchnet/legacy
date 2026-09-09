#!/usr/bin/env python3
"""Inspect the retained COFF symbols and disassemble named original routines.

Dependencies: pefile and capstone, in a development Python environment.
The PE executable's COFF values are image RVAs (verified against function bytes),
not object-file section offsets. Original files are opened read-only.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct

ROOT = Path(__file__).resolve().parents[1]


def coff_symbols(payload):
    pe = struct.unpack_from('<I', payload, 60)[0]
    position, count = struct.unpack_from('<II', payload, pe+12)
    strings = position+18*count
    records = []
    index = 0
    while index < count:
        offset = position+18*index
        name = payload[offset:offset+8]
        value, section, kind, storage, auxiliary = struct.unpack_from('<IhHBB', payload, offset+8)
        if name[:4] == bytes(4):
            start = strings+struct.unpack_from('<I', name, 4)[0]
            name = payload[start:payload.index(bytes(1), start)]
        else:
            name = name.rstrip(bytes(1))
        records.append({'name': name.decode('latin1'), 'rva': value, 'section': section,
                        'type': kind, 'storage': storage, 'auxiliary_records': auxiliary})
        index += 1+auxiliary
    return records


def main():
    import capstone
    import pefile
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('program', choices=['feq', 'fequtl'])
    parser.add_argument('--routine', action='append', default=[])
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    binary = ROOT / 'originals/feq1061/wrdapp/FEQ_10.61/BIN' / (args.program+'.exe')
    payload = binary.read_bytes()
    pe = pefile.PE(data=payload)
    base = pe.OPTIONAL_HEADER.ImageBase
    records = coff_symbols(payload)
    args.output.mkdir(parents=True, exist_ok=True)
    manifest = {'binary': binary.relative_to(ROOT).as_posix(),
                'binary_sha256': hashlib.sha256(payload).hexdigest(),
                'image_base': base, 'entry_rva': pe.OPTIONAL_HEADER.AddressOfEntryPoint,
                'symbols': records}
    (args.output / 'symbols.json').write_text(json.dumps(manifest, indent=2)+'\n')
    functions = sorted([record for record in records if record['type'] == 32 and record['section'] == 1], key=lambda item: item['rva'])
    names = {base+record['rva']: record['name'] for record in records if record['section'] > 0}
    disassembler = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    disassembler.detail = True
    written = []
    for index, function in enumerate(functions):
        if args.routine and function['name'] not in args.routine:
            continue
        start = function['rva']
        end = functions[index+1]['rva'] if index+1 < len(functions) else pe.sections[0].VirtualAddress+pe.sections[0].Misc_VirtualSize
        if end <= start:
            continue
        lines = [f'; {function["name"]}', f'; Original SHA-256: {manifest["binary_sha256"]}', f'; Image RVA: 0x{start:x}']
        for instruction in disassembler.disasm(pe.get_data(start, end-start), base+start):
            annotations = []
            for operand in instruction.operands:
                if operand.type == capstone.x86.X86_OP_IMM and operand.imm in names:
                    annotations.append(names[operand.imm])
                elif operand.type == capstone.x86.X86_OP_MEM and not operand.mem.base and not operand.mem.index:
                    address = operand.mem.disp
                    if address in names:
                        annotations.append(names[address])
                    if base <= address < base+pe.OPTIONAL_HEADER.SizeOfImage and operand.size in (2, 4, 8):
                        value = pe.get_data(address-base, operand.size)
                        if len(value) == operand.size:
                            annotations.append('bits='+value.hex())
                            if operand.size == 4:
                                annotations.append('f32='+repr(struct.unpack('<f', value)[0]))
                            elif operand.size == 8:
                                annotations.append('f64='+repr(struct.unpack('<d', value)[0]))
            text = f'{instruction.address:08x}  {instruction.bytes.hex():24} {instruction.mnemonic:9} {instruction.op_str}'
            if annotations:
                text += ' ; '+', '.join(annotations)
            lines.append(text.rstrip())
        filename = ''.join(char if char.isalnum() or char in '_-' else '_' for char in function['name'])+'.asm'
        (args.output / filename).write_text('\n'.join(lines)+'\n')
        written.append(function['name'])
    absent = sorted(set(args.routine)-set(written))
    if absent:
        raise ValueError('Requested function symbols not found: '+', '.join(absent))
    print(f'{args.program}: {len(records)} symbols; {len(written)} routines disassembled.')


if __name__ == '__main__':
    main()
