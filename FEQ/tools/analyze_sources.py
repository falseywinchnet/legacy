#!/usr/bin/env python3
"""Inventory source procedures and compare preserved FEQ releases without edits."""
import collections
import difflib
import hashlib
import json
from pathlib import Path
import re
import struct

ROOT = Path(__file__).resolve().parents[1]
CURRENT = ROOT / 'originals/feq1061/wrdapp/FEQ_10.61'
EARLIER = ROOT / 'originals/feq998/wrdapp/FEQ_9.98'
SOURCE_EXTENSIONS = {'.for', '.f', '.f90', '.cmn', '.prm', '.who'}


def source_files(root):
    return {p.relative_to(root).as_posix().lower(): p for p in root.rglob('*')
            if p.is_file() and '.svn' not in p.parts and 'make' not in p.parts
            and p.suffix.lower() in SOURCE_EXTENSIONS}


def normalized(path):
    # Newlines alone are normalized. Case, comments, spacing, and numbers remain.
    return path.read_bytes().replace(b'\r\n', b'\n').replace(b'\r', b'\n')


def pe_info(path):
    payload = path.read_bytes()
    offset = struct.unpack_from('<I', payload, 60)[0]
    if payload[offset:offset+4] != b'PE\0\0':
        return {'path': path.relative_to(ROOT).as_posix(), 'format': 'not PE'}
    machine, count, timestamp, symoff, symbols, optsize, flags = struct.unpack_from('<HHIIIHH', payload, offset+4)
    opt = offset+24
    magic = struct.unpack_from('<H', payload, opt)[0]
    sections = []
    for index in range(count):
        start = opt+optsize+index*40
        name, vsize, rva, size, position = struct.unpack_from('<8sIIII', payload, start)
        sections.append({'name': name.rstrip(b'\0').decode('ascii'), 'rva': rva,
                         'virtual_size': vsize, 'file_offset': position, 'file_size': size})
    def rva_offset(rva):
        for section in sections:
            delta = rva-section['rva']
            if 0 <= delta < max(section['virtual_size'], section['file_size']):
                return section['file_offset']+delta
        raise ValueError(f'Unmapped PE RVA {rva:x}')
    def cstring(position):
        return payload[position:payload.index(b'\0', position)].decode('ascii')
    imports = []
    directory = opt+(96 if magic == 0x10b else 112)
    imp_rva, imp_size = struct.unpack_from('<II', payload, directory+8)
    if imp_rva:
        entry = rva_offset(imp_rva)
        while payload[entry:entry+20] != b'\0'*20:
            lookup, stamp, chain, name, address = struct.unpack_from('<IIIII', payload, entry)
            dll = cstring(rva_offset(name))
            imported_names = []
            thunk = rva_offset(lookup or address)
            width = 4 if magic == 0x10b else 8
            fmt = '<I' if width == 4 else '<Q'
            while True:
                value = struct.unpack_from(fmt, payload, thunk)[0]
                if not value:
                    break
                if value & (1 << (8*width-1)):
                    imported_names.append({'ordinal': value & 65535})
                else:
                    imported_names.append(cstring(rva_offset(value)+2))
                thunk += width
            imports.append({'dll': dll, 'symbols': imported_names})
            entry += 20
    return {'path': path.relative_to(ROOT).as_posix(), 'sha256': hashlib.sha256(payload).hexdigest(),
            'bytes': len(payload), 'machine': hex(machine), 'format': 'PE32' if magic == 0x10b else 'PE32+',
            'coff_timestamp': timestamp, 'coff_symbol_count': symbols,
            'entry_rva': struct.unpack_from('<I', payload, opt+16)[0],
            'subsystem': struct.unpack_from('<H', payload, opt+68)[0],
            'sections': sections, 'imports': imports}


def main():
    old, new = source_files(EARLIER / 'SRC'), source_files(CURRENT / 'SRC')
    changes, procedures, pristine_changes = [], [], []
    differences = ROOT / 'recovery/diffs'
    differences.mkdir(exist_ok=True)
    declaration = re.compile(r'^\s*(?:(?:DOUBLE\s+PRECISION|REAL(?:\*\d+)?|INTEGER(?:\*\d+)?|LOGICAL|CHARACTER(?:\*\d+)?)\s+)?(SUBROUTINE|FUNCTION|PROGRAM|BLOCK\s*DATA)\s*(\w+)?', re.I)
    for key in sorted(set(old) | set(new)):
        a, b = old.get(key), new.get(key)
        status = 'added' if a is None else 'removed' if b is None else 'identical' if a.read_bytes() == b.read_bytes() else 'newlines-only' if normalized(a) == normalized(b) else 'changed'
        item = {'path': key, 'status': status}
        for tag, path in [('old', a), ('new', b)]:
            if path:
                item[tag] = {'path': path.relative_to(ROOT).as_posix(), 'sha256': hashlib.sha256(path.read_bytes()).hexdigest(), 'lines': len(normalized(path).splitlines())}
        changes.append(item)
        if status == 'changed':
            diff = difflib.unified_diff(normalized(a).decode('latin1').splitlines(True), normalized(b).decode('latin1').splitlines(True), fromfile='9.98/'+key, tofile='10.61/'+key)
            target = differences / (key.replace('/', '__')+'.diff')
            target.write_text(''.join(diff))
        if b:
            for number, line in enumerate(normalized(b).decode('latin1').splitlines(), 1):
                if not line or line[0] in 'cC*!' or len(line) < 7 or line[5] not in ' 0':
                    continue
                match = declaration.match(line[6:72])
                if match:
                    procedures.append({'path': b.relative_to(ROOT).as_posix(), 'line': number,
                                       'kind': match[1].lower(), 'name': (match[2] or '').lower()})
            pristine = b.parent / '.svn/text-base' / (b.name+'.svn-base')
            if pristine.exists() and normalized(pristine) != normalized(b):
                pristine_changes.append({'path': b.relative_to(ROOT).as_posix(),
                                         'pristine': pristine.relative_to(ROOT).as_posix()})
                diff = difflib.unified_diff(normalized(pristine).decode('latin1').splitlines(True), normalized(b).decode('latin1').splitlines(True), fromfile='SVN/'+key, tofile='distributed/'+key)
                (differences / ('svn__'+key.replace('/', '__')+'.diff')).write_text(''.join(diff))
    result = {'normalization': 'CRLF and CR to LF only',
              'summary': dict(collections.Counter(item['status'] for item in changes)),
              'files': changes, 'procedures': procedures, 'svn_content_changes': pristine_changes,
              'binaries': [pe_info(p) for p in sorted((CURRENT / 'BIN').rglob('*.exe'))]}
    (ROOT / 'recovery/source-analysis.json').write_text(json.dumps(result, indent=2)+'\n')
    print(json.dumps({'source_comparison': result['summary'], 'procedure_entries': len(procedures),
                      'svn_content_changes': pristine_changes,
                      'binaries': [{'path': b['path'], 'format': b['format'], 'imports': [i['dll'] for i in b.get('imports', [])]} for b in result['binaries']]}, indent=2))


if __name__ == '__main__':
    main()
