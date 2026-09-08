#!/usr/bin/env python3
"""Statically unpack the InstallShield payload of the recovered CHAMP installers.

Usage: python3 tools/extract_champ_installer.py setup.exe output-directory
Then: 7zz x CHAMP.msi, followed by 7zz x Data1.cab.
No Windows executable is run. This supports the observed ANSI InstallShield
format only. Format/decoding reference: https://github.com/lifenjoiner/ISx
(MIT; see tools/ISx-LICENSE.txt). Original implementation for this recovery.
"""
import argparse
from pathlib import Path
import struct


def extract(source, destination):
    data = source.read_bytes()
    def u16(offset):
        return struct.unpack_from('<H', data, offset)[0]
    def u32(offset):
        return struct.unpack_from('<I', data, offset)[0]
    if data[:2] != b'MZ':
        raise ValueError('Expected a PE executable')
    pe = u32(60)
    if data[pe:pe + 4] != b'PE\0\0':
        raise ValueError('Missing PE signature')
    sections = pe + 24 + u16(pe + 20)
    position = max(u32(sections + 40 * i + 20) +
                   u32(sections + 40 * i + 16) for i in range(u16(pe + 6)))
    if data[position:position + 14] != b'InstallShield\0':
        raise ValueError('Unsupported overlay format')
    count = u16(position + 14)
    position += 46
    destination.mkdir(parents=True, exist_ok=True)
    for _ in range(count):
        if position + 312 > len(data):
            raise ValueError('Truncated entry header')
        name_bytes = data[position:position + 260].split(b'\0', 1)[0]
        name = name_bytes.decode('ascii')
        if not name or name in ('.', '..') or '/' in name or '\\' in name:
            raise ValueError('Unsafe entry name')
        flags, length = u32(position + 260), u32(position + 268)
        if flags not in (0, 2, 6):
            raise ValueError(f'Unsupported encoding flags {flags}')
        position += 312
        if position + length > len(data):
            raise ValueError('Truncated entry body')
        payload = data[position:position + length]
        if flags & 2:
            magic = (0x13, 0x35, 0x86, 0x07)
            key = [value ^ magic[i % 4] for i, value in enumerate(name_bytes)]
            payload = bytes((~(((value << 4) | (value >> 4)) ^
                              key[(i % 1024 if flags & 4 else i) % len(key)])) & 255
                            for i, value in enumerate(payload))
        target = destination / name
        if target.exists():
            raise FileExistsError(target)
        target.write_bytes(payload)
        print(f'{name}: {length} bytes')
        position += length


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('source', type=Path)
    parser.add_argument('destination', type=Path)
    args = parser.parse_args()
    extract(args.source, args.destination)
