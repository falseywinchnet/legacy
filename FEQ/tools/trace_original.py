#!/usr/bin/env python3
"""Capture COMMON memory at named routine entries in a disposable PE32 copy.

The hook preserves flags, general registers, the complete x87 environment and
register stack. It then executes whole displaced entry instructions and resumes
the unchanged routine. Captures are research data, never acceptance masks.
Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import struct
import subprocess

from inspect_binary import coff_symbols
from probe_profile_original import Driver, ORIGINAL_SHA256
from run_originals import ROOT, RELEASES, CASES, file_record
from compare_reports import compare


def align(value, alignment):
    return (value+alignment-1)//alignment*alignment


class TraceDriver(Driver):
    def __init__(self, start, imports):
        super().__init__(start, imports)
        self.labels = {}
        self.branches = []

    def label(self, name):
        self.labels[name] = len(self.code)

    def branch(self, opcode, name):
        self.emit(opcode)
        self.branches.append((len(self.code), name))
        self.code.extend(bytes(4))

    def complete(self):
        for position, name in self.branches:
            struct.pack_into('<i', self.code, position, self.labels[name]-position-4)
        return self.code


def patch(original, pe, symbols, hooks):
    import capstone
    base = pe.OPTIONAL_HEADER.ImageBase
    imports = {item.name.decode(): item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    rva = align(pe.OPTIONAL_HEADER.SizeOfImage, pe.OPTIONAL_HEADER.SectionAlignment)
    section = bytearray()
    result = bytearray(original)
    details = []
    disassembler = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    for index, hook in enumerate(hooks):
        name = hook['routine']
        routine_rva = symbols[name]['rva']
        inside_offset = hook.get('offset', 0)
        if inside_offset < 0 or inside_offset > 100000:
            raise ValueError('Invalid routine trace offset.')
        original_rva = routine_rva+inside_offset
        boundary = routine_rva
        for instruction in disassembler.disasm(pe.get_data(routine_rva, inside_offset), base+routine_rva):
            boundary += instruction.size
        if boundary != original_rva:
            raise ValueError('Trace offset is not an instruction boundary.')
        instructions = []
        length = 0
        for instruction in disassembler.disasm(pe.get_data(original_rva, 32), base+original_rva):
            # Relative control transfers need relocation. Only simple routine
            # prologues are accepted; never copy an unexamined branch or call.
            if instruction.mnemonic not in ('push', 'mov', 'sub', 'add', 'lea', 'nop', 'and',
                    'fld', 'fst', 'fstp', 'fadd', 'faddp', 'fsub', 'fsubp', 'fsubr', 'fsubrp',
                    'fmul', 'fmulp', 'fdiv', 'fdivp', 'fdivr', 'fdivrp', 'fxch'):
                raise ValueError(f'Unsupported entry instruction: {name}: {instruction.mnemonic} {instruction.op_str}')
            instructions.append(instruction.mnemonic+' '+instruction.op_str)
            length += instruction.size
            if length >= 5:
                break
        if length < 5:
            raise ValueError('Incomplete routine entry.')
        start_offset = align(len(section), 4096)
        section.extend(bytes(start_offset-len(section)))
        start = base+rva+start_offset
        # Each hook owns 4096 bytes; code occupies the first 3072, state and
        # filename the remainder. Mutable state exists only in the added section.
        state = start+3072
        written, count, handle, filename = state, state+4, state+8, state+16
        driver = TraceDriver(start, imports)
        driver.emit('9c60')                         # pushfd; pushad
        driver.emit('83ec6cdd3424fc')               # sub esp,108; fnsave [esp]; cld
        driver.emit('813d')
        driver.code.extend(struct.pack('<II', count, hook.get('limit', 8)))
        driver.branch('0f83', 'restore')           # jae
        driver.emit('833d')
        driver.code.extend(struct.pack('<I', count)+b'\x00')
        driver.branch('0f85', 'write')
        # CreateFileA(filename, GENERIC_WRITE, FILE_SHARE_READ, NULL,
        #             CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL).
        for value in (0, 0x80, 2, 0, 1, 0x40000000, filename):
            driver.push(value)
        driver.api('CreateFileA')
        driver.emit('a3')
        driver.code.extend(struct.pack('<I', handle))
        driver.emit('83f8ff')
        driver.branch('0f84', 'failure')
        driver.label('write')
        driver.emit('8b1d')
        driver.code.extend(struct.pack('<I', handle))
        record_size = 0
        for capture in hook['captures']:
            size = capture['bytes']
            if 'stack_offset' in capture or capture.get('fpu'):
                if capture.get('fpu'):
                    if size != 108:
                        raise ValueError('The full x87 save record is 108 bytes.')
                    driver.emit('89e6')             # mov esi,esp (saved x87 record)
                else:
                    if capture['stack_offset'] < 0 or size <= 0 or capture['stack_offset']+size > 100000:
                        raise ValueError('Invalid stack capture extent.')
                    driver.emit('8b742478')         # saved ESP from PUSHAD (before pushfd adjustment)
                    driver.emit('81c6')
                    driver.code.extend(struct.pack('<I',capture['stack_offset']+4))
                driver.push(0)
                driver.push(written)
                driver.push(size)
                driver.emit('5653')                # push esi; push ebx
                driver.api('WriteFile')
            else:
                address = base+(capture['rva'] if 'rva' in capture else symbols[capture['symbol']]['rva']+capture.get('offset', 0))
                if size <= 0 or address < base or address+size > base+pe.OPTIONAL_HEADER.SizeOfImage:
                    raise ValueError('Capture lies outside original image.')
                driver.write(address, size, written)
            driver.emit('85c0')
            driver.branch('0f84', 'failure')
            driver.emit('813d')
            driver.code.extend(struct.pack('<II', written, size))
            driver.branch('0f85', 'failure')
            record_size += size
        driver.emit('ff05')
        driver.code.extend(struct.pack('<I', count))
        driver.branch('e9', 'restore')
        driver.label('failure')
        driver.push(91)
        driver.api('ExitProcess')
        driver.label('restore')
        driver.emit('dd242483c46c619d')             # frstor; add esp,108; popad; popfd
        driver.code.extend(pe.get_data(original_rva, length))
        driver.emit('e9')
        driver.code.extend(struct.pack('<i', base+original_rva+length-(start+len(driver.code)+4)))
        code = driver.complete()
        if len(code) > 3072:
            raise ValueError('Trace hook exceeds its reserved code slot.')
        slot = bytearray(4096)
        slot[:len(code)] = code
        output_name = f'trace-{index:02d}.bin'
        encoded_name = output_name.encode('ascii')+b'\0'
        slot[3088:3088+len(encoded_name)] = encoded_name
        section.extend(slot)
        file_offset = pe.get_offset_from_rva(original_rva)
        displacement = start-(base+original_rva+5)
        result[file_offset:file_offset+length] = b'\xe9'+struct.pack('<i', displacement)+b'\x90'*(length-5)
        details.append({**hook, 'file': output_name, 'record_bytes': record_size,
                        'original_rva': original_rva, 'hook_rva': start-base,
                        'displaced_bytes': pe.get_data(original_rva, length).hex(),
                        'displaced_instructions': instructions})
    header_offset = pe.sections[-1].get_file_offset()+40
    header_bytes = bytes(result[header_offset:header_offset+40])
    # The hash-checked Lahey image fills unused header space with a linker
    # source-control string. These bytes are not a section or data directory.
    # Preserve the replaced text in the trace manifest and the original image.
    if header_offset+40 > pe.OPTIONAL_HEADER.SizeOfHeaders or (
            any(header_bytes) and not header_bytes.startswith(b'$Header: /prj/control/src/header/')):
        raise ValueError('No recognized unused PE section-header slot.')
    for directory in pe.OPTIONAL_HEADER.DATA_DIRECTORY:
        if directory.Size and directory.VirtualAddress < header_offset+40 and directory.VirtualAddress+directory.Size > header_offset:
            raise ValueError('A PE data directory overlaps the new section header.')
    for detail in details:
        detail['replaced_header_padding'] = header_bytes.hex()
    raw_offset = align(len(result), pe.OPTIONAL_HEADER.FileAlignment)
    raw_size = align(len(section), pe.OPTIONAL_HEADER.FileAlignment)
    # Retain the original COFF and debug overlay at its exact file offsets.
    result.extend(bytes(raw_offset-len(result)))
    result.extend(section)
    result.extend(bytes(raw_size-len(section)))
    struct.pack_into('<8sIIIIIIHHI', result, header_offset,
                     b'.feqtrc\0', len(section), rva, raw_size, raw_offset, 0, 0, 0, 0, 0xe0000060)
    struct.pack_into('<H', result, pe.FILE_HEADER.get_field_absolute_offset('NumberOfSections'), len(pe.sections)+1)
    struct.pack_into('<I', result, pe.OPTIONAL_HEADER.get_field_absolute_offset('SizeOfImage'),
                     align(rva+len(section), pe.OPTIONAL_HEADER.SectionAlignment))
    struct.pack_into('<I', result, pe.OPTIONAL_HEADER.get_field_absolute_offset('CheckSum'), 0)
    return bytes(result), details


def main():
    import pefile
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--config', type=Path, required=True)
    parser.add_argument('--case', choices=[case[0] for case in CASES], default='feqex1')
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--wine-prefix', type=Path, default=ROOT/'build/wineprefix')
    args = parser.parse_args()
    output = args.output.resolve()
    if output.exists() or ROOT/'build' not in output.parents:
        parser.error('Use a new FEQ/build/ directory.')
    case, program, arguments = next(case for case in CASES if case[0] == args.case)
    original_path = RELEASES['1061']/'BIN'/(program+'.exe')
    original = original_path.read_bytes()
    configuration = json.loads(args.config.read_text())
    expected_hash = configuration.get('original_sha256', ORIGINAL_SHA256 if program == 'feq' else None)
    original_hash = hashlib.sha256(original).hexdigest()
    if original_hash != expected_hash:
        raise ValueError('Original executable hash is absent or changed.')
    pe = pefile.PE(data=original)
    symbols = {item['name']: item for item in coff_symbols(original)}
    traced, hooks = patch(original, pe, symbols, configuration['hooks'])
    output.mkdir(parents=True)
    shutil.copytree(RELEASES['1061']/'DATA', output/'data')
    working = output/'test'
    working.mkdir()
    executable = output/'TRACE.EXE'
    executable.write_bytes(traced)
    env = os.environ.copy()
    env.update(WINEPREFIX=str(args.wine_prefix.resolve()), WINEDEBUG='-all',
               WINEDLLOVERRIDES='mscoree,mshtml=', MVK_CONFIG_LOG_LEVEL='0')
    command = ([str(executable)] if os.name == 'nt' else ['wine', str(executable)])+arguments
    process = subprocess.run(command, cwd=working, env=env, capture_output=True, timeout=120, stdin=subprocess.DEVNULL)
    (output/'console.log').write_bytes(process.stdout+process.stderr)
    for hook in hooks:
        capture = working/hook['file']
        if capture.exists() and capture.stat().st_size % hook['record_bytes']:
            raise RuntimeError('Partial trace: '+hook['file'])
        hook['records'] = capture.stat().st_size//hook['record_bytes'] if capture.exists() else 0
        hook['sha256'] = hashlib.sha256(capture.read_bytes()).hexdigest() if capture.exists() else None
    reports = [case+'.out'+suffix for suffix in ('', '.spi', '.wsq')] if program == 'feq' else [case+'.out', case+'.tab']
    verification = {name: compare((RELEASES['1061']/'DATA'/name).read_bytes(), (working/name).read_bytes())
                    for name in reports if (working/name).exists()}
    manifest = {'original': file_record(original_path, ROOT), 'traced_sha256': hashlib.sha256(traced).hexdigest(),
                'command': command, 'returncode': process.returncode, 'hooks': hooks, 'output_verification': verification,
                'outputs': [file_record(path, output) for path in sorted(working.iterdir()) if path.is_file()]}
    (output/'manifest.json').write_text(json.dumps(manifest, indent=2)+'\n')
    print(json.dumps({'returncode': process.returncode, 'hooks': hooks}, indent=2))
    raise SystemExit(process.returncode or (0 if len(verification) == len(reports) and
                     all(item['clock_masked_equal'] for item in verification.values()) else 1))


if __name__ == '__main__':
    main()
