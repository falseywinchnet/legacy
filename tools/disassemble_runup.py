#!/usr/bin/env python3
"""Disassemble recovered 16-bit RUNUP application code with its own C6 symbols.

Research dependency: capstone 5. The executable and existing extraction metadata
are read without modification. Segment values are DOS load-relative paragraphs.
"""
import argparse
from pathlib import Path
import json
import struct
from capstone import Cs, CS_ARCH_X86, CS_MODE_16


def instructions(engine, code, start):
    offset = 0
    while offset < len(code):
        raw = code[offset:]
        extra = 0
        floating = False
        if len(raw) >= 2 and raw[0] == 0xcd and 0x34 <= raw[1] <= 0x3b:
            raw = bytes([raw[1] + 0xa4]) + raw[2:]
            extra = 1
            floating = True
        elif raw[:2] == b'\xcd\x3d':
            raw = b'\x9b' + raw[2:]
            extra = 1
            floating = True
        ins = next(engine.disasm(raw, start + offset, count=1), None)
        if ins is None:
            raise ValueError(f'Undecodable instruction at {start + offset:04x}')
        size = ins.size + extra
        yield ins, code[offset:offset + size], floating
        offset += size


def disassemble(exe_path, metadata_path, output):
    exe = exe_path.read_bytes()
    meta = json.loads(metadata_path.read_text())
    header = struct.unpack_from('<H', exe, 8)[0] * 16
    symbols = {}
    data = {}
    for module in meta['modules'].values():
        for s in module.get('public_symbols', []):
            symbols[s['segment'] * 16 + s['offset']] = s['name']
        for s in module.get('symbol_records', []):
            if s.get('kind') == '0x5':
                data.setdefault(s['data_offset'], []).append(s['name'])
    engine = Cs(CS_ARCH_X86, CS_MODE_16)
    output.mkdir(parents=True, exist_ok=True)
    for module in list(meta['modules'].values())[:4]:
        mapping = {}
        for f in module.get('source_files', []):
            for line in f['line_mappings']:
                mapping.setdefault(line['code_offset'], []).append(f"{f['name']}:{line['line']}")
        records = module.get('symbol_records', [])
        for index, proc in enumerate(records):
            if proc.get('kind') != '0x1':
                continue
            local = []
            for s in records[index + 1:]:
                if s['kind'] == '0x1':
                    break
                if s.get('name'):
                    local.append(s)
            start = proc['code_offset']
            address = module['segment'] * 16 + start
            code = exe[header + address:header + address + proc['code_bytes']]
            lines = [f"; {proc['name']} original RUNUP2.EXE, relative {module['segment']:04x}:{start:04x}",
                     '; Source line numbers and symbols come from the original executable.']
            lines += ['; ' + json.dumps(s, sort_keys=True) for s in local]
            for ins, original_bytes, floating in instructions(engine, code, start):
                if ins.address in mapping:
                    lines.append('; ' + ', '.join(mapping[ins.address]))
                extra = 'Microsoft x87 trap' if floating else ''
                if ins.mnemonic == 'lcall':
                    seg, off = [int(v.strip(), 0) for v in ins.op_str.split(':')]
                    extra = symbols.get(seg * 16 + off, '')
                elif ins.mnemonic == 'call' and '[' not in ins.op_str:
                    try:
                        extra = symbols.get(module['segment'] * 16 + int(ins.op_str, 0), '')
                    except ValueError:
                        pass
                lines.append(f'{ins.address:04x}  {original_bytes.hex():24s} {ins.mnemonic:8s} {ins.op_str}' + (f' ; {extra}' if extra else ''))
            (output / (proc['name'] + '.asm')).write_text('\n'.join(lines) + '\n')
    return output


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--exe', type=Path, default=Path('originals/runup2/RUNUP2.EXE'))
    parser.add_argument('--metadata', type=Path, default=Path('recovery/runup-1991-debug/build-metadata.json'))
    parser.add_argument('--output', type=Path, default=Path('build/runup-disassembly'))
    args = parser.parse_args()
    print(disassemble(args.exe, args.metadata, args.output))
