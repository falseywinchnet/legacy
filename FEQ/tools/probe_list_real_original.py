#!/usr/bin/env python3
"""Capture complete list-directed REAL*4 records from the released runtime.

Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
The bounded replacement MAIN repeats the original compiler-options call before
calling the unchanged _jwe_ilst runtime with scalar and label/scalar descriptors.
The preserved executable is opened read-only and verified by SHA-256.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import random
import struct
import subprocess

from inspect_binary import coff_symbols
from probe_profile_original import Driver, ROOT

ORIGINAL_SHA256 = '031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2'


def fixtures():
    cases = []
    def add(bits, name):
        # Console label/scalar, console scalar, report label/scalar, report scalar.
        for style in (0, 1, 2, 3):
            cases.append({'bits':bits, 'style':style, 'name':name})
    for bits in (0, 1, 0x3fffff, 0x7fffff, 0x800000, 0x800001,
                 0x7f7fffff, 0x7f800000, 0x7fc00000, 0x7f800001):
        for sign in (0, 0x80000000):
            add(bits | sign, 'IEEE-boundary')
    # Every decimal decade in binary32, adjacent floats and both signs.
    for exponent in range(-44, 39):
        bits = struct.unpack('<I', struct.pack('<f', 10.0**exponent))[0]
        for neighbor in (-1, 0, 1):
            for sign in (0, 0x80000000):
                add((bits+neighbor) | sign, f'decade-{exponent}-neighbor-{neighbor}')
    for value in (0.125, 0.375, 0.625, 0.875, 1.125, 1.25, 9.25, 9.75,
                  82432.40625, 29144.25, 151438.0, 233153.75, 659459.25, 659458.0):
        bits = struct.unpack('<I', struct.pack('<f', value))[0]
        for neighbor in (-1, 0, 1):
            for sign in (0, 0x80000000):
                add((bits+neighbor) | sign, 'halfway-and-gate-report')
    rng = random.Random(1061580009)
    for exponent in range(255):
        for trial in range(4):
            bits = (rng.randrange(2) << 31) | (exponent << 23) | rng.getrandbits(23)
            add(bits, 'seeded-exponent-coverage')
    return cases


def image(original, pe, symbols, cases):
    base = pe.OPTIONAL_HEADER.ImageBase
    start = base+symbols['_MAIN__']['rva']
    scratch = base+symbols['_ftable_']['rva']+4096
    imports = {item.name.decode():item.address for dll in pe.DIRECTORY_ENTRY_IMPORT
               for item in dll.imports if item.name}
    code = Driver(start, imports)
    code.emit('fc')
    # MAIN RVA 0x386e0..0x386f6 installs the compiler's 0x707013 options.
    # Omitting this changes separators, exponent case and zero formatting.
    for value in (0, 0, 0, 0x707013):
        code.push(value)
    code.call(base+symbols['_jwe_xcop']['rva'])
    code.emit('83c410')
    labeled = bytearray(pe.get_data(0x1a9bd4, 56))
    if len(labeled) != 56 or struct.unpack_from('<I', labeled)[0] != 0x8209:
        raise ValueError('The original UFGATE list-output descriptor changed.')
    struct.pack_into('<I', labeled, 8, scratch+256)
    struct.pack_into('<I', labeled, 52, scratch+260)
    scalar = labeled[:32]+labeled[44:56]
    code.copy(scratch, labeled)
    code.copy(scratch+128, scalar)
    # Bounded loop over literal input records. ESI and EDI are preserved by
    # the original cdecl runtime; no value arithmetic occurs in this driver.
    code.copy(scratch+512, b''.join(struct.pack('<II', case['bits'], case['style']) for case in cases))
    code.emit('be'+struct.pack('<I',scratch+512).hex())  # ESI = input cursor
    code.emit('bf'+struct.pack('<I',len(cases)).hex())   # EDI = record count
    loop = len(code.code)
    code.emit('8b06a3'+struct.pack('<I',scratch+260).hex()) # value bits
    code.emit('8b460489c1d1e1') # EAX=style; ECX=style*2
    code.emit('83e1fc83c106890d'+struct.pack('<I',scratch+256).hex()) # unit=6 or 10
    code.emit('83e001c1e00705'+struct.pack('<I',scratch).hex()) # descriptor offset
    code.emit('50')
    code.call(base+symbols['_jwe_ilst']['rva'])
    code.emit('83c40483c6084f') # discard argument; next input; decrement count
    displacement = loop-(len(code.code)+2)
    if not -128 <= displacement < 0:
        raise ValueError('List driver loop no longer fits a short branch.')
    code.emit('75'+struct.pack('b',displacement).hex())
    code.call(base+symbols['_jwe_xend']['rva'])
    driver = code.finish()
    later = sorted(item['rva'] for item in symbols.values() if item['type'] == 32 and
                   item['section'] == 1 and item['rva'] > symbols['_MAIN__']['rva'])
    if len(driver) > later[0]-symbols['_MAIN__']['rva']:
        raise ValueError('List-output driver exceeds the replaceable PROGRAM body.')
    result = bytearray(original)
    offset = pe.get_offset_from_rva(symbols['_MAIN__']['rva'])
    result[offset:offset+len(driver)] = driver
    return bytes(result)


def main():
    import pefile
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--native', type=Path)
    parser.add_argument('--wine-prefix', type=Path, default=ROOT/'build/wineprefix')
    args = parser.parse_args()
    output = args.output.resolve()
    if output.exists() or ROOT/'build' not in output.parents:
        parser.error('Use a new FEQ/build/ directory.')
    output.mkdir(parents=True)
    original = (ROOT/'originals/feq1061/wrdapp/FEQ_10.61/BIN/fequtl.exe').read_bytes()
    if hashlib.sha256(original).hexdigest() != ORIGINAL_SHA256:
        raise ValueError('The original executable hash changed.')
    pe = pefile.PE(data=original)
    symbols = {item['name']:item for item in coff_symbols(original)}
    cases = fixtures()
    inputs = b''.join(struct.pack('<II', case['bits'], case['style']) for case in cases)
    (output/'inputs.bin').write_bytes(inputs)
    (output/'fixtures.json').write_text(json.dumps(cases, indent=2)+'\n')
    env = os.environ.copy()
    env.update(WINEPREFIX=str(args.wine_prefix.resolve()), WINEDEBUG='-all',
               WINEDLLOVERRIDES='mscoree,mshtml=', MVK_CONFIG_LOG_LEVEL='0')
    expected, console, report = bytearray(), bytearray(), bytearray()
    for first in range(0, len(cases), 768):
        batch = cases[first:first+768]
        executable = output/'PROBE.EXE'
        executable.write_bytes(image(original, pe, symbols, batch))
        report_file = output/'fort.10'
        report_file.unlink(missing_ok=True)
        command = [str(executable)] if os.name == 'nt' else ['wine', str(executable)]
        process = subprocess.run(command, cwd=output, env=env, capture_output=True,
                                 timeout=30, stdin=subprocess.DEVNULL)
        file_bytes = report_file.read_bytes() if report_file.exists() else b''
        console_count = sum(case['style'] < 2 for case in batch)
        if (process.returncode or process.stdout.count(b'\r\n') != console_count or
                file_bytes.count(b'\r\n') != len(batch)-console_count):
            (output/'error.log').write_bytes(process.stdout+process.stderr)
            raise RuntimeError(f'Original list driver failed: exit {process.returncode}, {len(process.stdout)} bytes.')
        console.extend(process.stdout)
        report.extend(file_bytes)
        console_records = iter(process.stdout.splitlines(keepends=True))
        report_records = iter(file_bytes.splitlines(keepends=True))
        # Merge the two untouched streams in input order; no output byte is
        # rewritten, padded, stripped or normalized.
        for case in batch:
            expected.extend(next(console_records if case['style'] < 2 else report_records))
        print(f'{first+len(batch)}/{len(cases)} original list records captured.', flush=True)
    (output/'outputs.bin').write_bytes(expected)
    (output/'console.bin').write_bytes(console)
    (output/'report.bin').write_bytes(report)
    manifest = {'original_sha256':ORIGINAL_SHA256, 'routine':'_jwe_ilst, _jwe_ilor, _jwe_iedo',
                'probe_sha256':hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
                'compiler_options':0x707013, 'cases':len(cases), 'input_record_bytes':8,
                'output_records':'One complete CRLF-terminated record per input, with scalar or label/scalar descriptors.',
                'input_sha256':hashlib.sha256(inputs).hexdigest(),
                'output_sha256':hashlib.sha256(expected).hexdigest(),
                'console_sha256':hashlib.sha256(console).hexdigest(),
                'report_sha256':hashlib.sha256(report).hexdigest()}
    if args.native:
        native = subprocess.run([str(args.native.resolve()), '--list-real'], input=inputs,
                                capture_output=True, timeout=30)
        (output/'native.bin').write_bytes(native.stdout)
        (output/'native.stderr.log').write_bytes(native.stderr)
        manifest.update(native_sha256=hashlib.sha256(args.native.read_bytes()).hexdigest(),
                        native_returncode=native.returncode,
                        exact_bytes=native.returncode == 0 and bytes(expected) == native.stdout)
    (output/'manifest.json').write_text(json.dumps(manifest, indent=2)+'\n')
    if args.native:
        raise SystemExit(0 if manifest['exact_bytes'] else 1)


if __name__ == '__main__':
    main()
