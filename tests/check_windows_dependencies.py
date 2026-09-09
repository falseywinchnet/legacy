#!/usr/bin/env python3
"""Check PE import tables without needing a Windows SDK or third-party module."""

import struct
import sys
from pathlib import Path


def imported_dlls(path):
    data = Path(path).read_bytes()

    def unpack(fmt, offset):
        if offset < 0 or offset + struct.calcsize(fmt) > len(data):
            raise ValueError("truncated PE structure")
        return struct.unpack_from(fmt, data, offset)

    if data[:2] != b"MZ":
        raise ValueError("missing DOS header")
    pe, = unpack("<I", 0x3C)
    if data[pe:pe + 4] != b"PE\0\0":
        raise ValueError("missing PE signature")
    sections, = unpack("<H", pe + 6)
    optional_size, = unpack("<H", pe + 20)
    optional = pe + 24
    magic, = unpack("<H", optional)
    if magic == 0x20B:
        directory_offset = 112
        image_base, = unpack("<Q", optional + 24)
    elif magic == 0x10B:
        directory_offset = 96
        image_base, = unpack("<I", optional + 28)
    else:
        raise ValueError("unsupported PE optional header")
    directory_count, = unpack("<I", optional + directory_offset - 4)
    header_size, = unpack("<I", optional + 60)
    section_table = optional + optional_size

    def file_offset(rva):
        if 0 <= rva < header_size and rva < len(data):
            return rva
        for index in range(sections):
            size, address, raw_size, raw_offset = unpack(
                "<IIII", section_table + index * 40 + 8
            )
            if address <= rva < address + max(size, raw_size):
                delta = rva - address
                if delta >= raw_size or raw_offset + delta >= len(data):
                    raise ValueError("RVA has no file contents")
                return raw_offset + delta
        raise ValueError(f"unmapped RVA {rva:#x}")

    def dll_name(rva):
        offset = file_offset(rva)
        end = data.find(b"\0", offset, min(offset + 1024, len(data)))
        if end < 0:
            raise ValueError("unterminated imported DLL name")
        return data[offset:end].decode("ascii")

    names = set()
    # Normal and delay-load imports use different descriptor layouts.
    for directory, descriptor_size in ((1, 20), (13, 32)):
        if directory >= directory_count:
            continue
        entry = directory_offset + directory * 8
        if entry + 8 > optional_size:
            raise ValueError("truncated PE data directory")
        rva, size = unpack("<II", optional + entry)
        if rva == 0:
            continue
        for relative in range(0, size - descriptor_size + 1, descriptor_size):
            offset = file_offset(rva + relative)
            words = unpack("<" + "I" * (descriptor_size // 4), offset)
            if not any(words):
                break
            if directory == 1:
                name_rva = words[3]
            else:
                name_rva = words[1] if words[0] & 1 else words[1] - image_base
            names.add(dll_name(name_rva))
        else:
            raise ValueError("unterminated PE import directory")
    return sorted(names, key=str.lower)


def main():
    if len(sys.argv) < 2:
        raise SystemExit("usage: check_windows_dependencies.py PROGRAM.exe [...]")
    failed = False
    for name in sys.argv[1:]:
        try:
            imports = imported_dlls(name)
            runtime = [dll for dll in imports if dll.lower().startswith(
                ("vcruntime", "msvcp", "msvcr", "ucrtbase", "api-ms-win-crt-")
            )]
            print(f"{name}: {', '.join(imports)}")
            if runtime:
                print(f"ERROR: separately installed C/C++ runtime required: {runtime}")
                failed = True
        except (ValueError, OSError, struct.error) as error:
            print(f"ERROR: {name}: {error}")
            failed = True
    raise SystemExit(1 if failed else 0)


if __name__ == "__main__":
    main()
