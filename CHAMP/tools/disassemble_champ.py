#!/usr/bin/env python3
"""Annotate CHAMP's original VB6 p-code with its own strings and constants.

The input dump is produced by the Apache-2.0 visualbasic-rs `dump` example:
https://github.com/BinFlip/visualbasic-rs
This tool does not treat disassembler output as recovered original VB source.
"""
import argparse
import json
from pathlib import Path
import re
import struct


def annotate(binary, dump, output):
    data = binary.read_bytes()
    def u32(p): return struct.unpack_from('<I', data, p)[0]
    pe = u32(60)
    optional = pe + 24
    base = u32(optional + 28)
    sections = []
    first = optional + struct.unpack_from('<H', data, pe + 20)[0]
    for i in range(struct.unpack_from('<H', data, pe + 6)[0]):
        virtual_size, rva, size, raw = struct.unpack_from('<4I', data, first + i * 40 + 8)
        sections.append((rva, size, raw))
    def offset(va):
        for rva, size, raw in sections:
            if rva <= va - base < rva + size: return raw + va - base - rva
        raise ValueError('unbacked address')
    def string(va):
        try:
            p = offset(va)
            length = u32(p - 4)
            if length > 8192 or length % 2: return None
            text = data[p:p + length].decode('utf-16le')
            if '\0' in text or any(ord(c) < 32 and c not in '\r\n\t' for c in text): return None
            return text
        except (ValueError, UnicodeError, struct.error): return None
    output.mkdir(parents=True, exist_ok=True)
    objects = {}; name = None; pool = 0
    for line in dump.read_text().splitlines():
        match = re.match(r'\.object (\S+) :', line)
        if match: name = match[1]; objects[name] = []
        if name is None: continue
        if 'Constants VA:' in line: pool = int(line.split('0x')[1], 16)
        annotations = []
        for ref in re.finditer(r'\[pool\+([0-9A-F]+)\]', line):
            index = int(ref[1], 16); va = u32(offset(pool + index * 4))
            text = string(va)
            annotations.append(json.dumps(text, ensure_ascii=False) if text is not None else f'VA 0x{va:08X}')
        if re.search(r'Lit(Date|Cy|VarR8) ', line):
            numbers = re.findall(r'-?0x[0-9A-F]+', line.split('//')[0])
            if len(numbers) == 2:
                value = struct.unpack('<d', struct.pack('<II', *(int(v, 16) & 0xffffffff for v in numbers)))[0]
                annotations.append(f'binary64 {value!r}')
        if annotations: line = line.split(' // ')[0] + ' // ' + '; '.join(annotations)
        objects[name].append(line)
    for name, lines in objects.items(): (output / (name + '.pcode')).write_text('\n'.join(lines) + '\n')
    print(f'{len(objects)} original objects annotated in {output}')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('dump', type=Path)
    parser.add_argument('--binary', type=Path, default=Path('originals/champ2/champ.exe'))
    parser.add_argument('--output', type=Path, default=Path('build/champ-pcode'))
    args = parser.parse_args()
    annotate(args.binary, args.dump, args.output)
