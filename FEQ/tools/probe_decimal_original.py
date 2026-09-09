#!/usr/bin/env python3
"""Capture the released runtime's REAL*4 decimal digits without report layout.

New work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
The original startup and _jwe_iroc instructions execute unchanged; only MAIN is
replaced with a bounded driver. Records preserve all float bits, including NaNs.
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
from probe_profile_original import Driver, ORIGINAL_SHA256, ROOT


def fixtures():
    cases = []
    def add(bits,kind,precision,scale):
        cases.append({'bits':bits,'kind':kind,'precision':precision,'scale':scale})
    # Both signs; zero, subnormals, normal boundaries and IEEE special values.
    boundaries = [0,1,0x3fffff,0x7fffff,0x800000,0x800001,0x7f7fffff,0x7f800000,0x7fc00000,0x7f800001]
    for bits in boundaries:
        for sign in (0,0x80000000):
            for kind in (0,4,8,12):
                for precision in (0,2,9,20):
                    add(bits|sign,kind,precision,0)
    # Decimal halfway cases and adjacent representable floats.
    for value in (0.005,0.05,0.125,0.375,0.625,0.875,1.125,1.25,9.25,9.75,9.95,98.25,97.25,88.25,445.0,78.5,99.95):
        bits = struct.unpack('<I',struct.pack('<f',value))[0]
        for neighbor in (-1,0,1):
            for kind in (0,4,8,12):
                for precision in (0,1,2,8,12):
                    add(bits+neighbor,kind,precision,0)
    # Every finite exponent field, seeded mantissas, all descriptor kinds and
    # positive/negative scale factors, including requests for no kept digits.
    rng = random.Random(1061580414)
    for exponent in range(255):
        for kind in (0,4,8,12):
            bits = (rng.randrange(2)<<31)|(exponent<<23)|rng.getrandbits(23)
            add(bits,kind,rng.choice((0,1,2,6,9,20)),rng.choice((-4,-1,0,1,3)))
    return cases


def image(original,pe,symbols,cases):
    base = pe.OPTIONAL_HEADER.ImageBase
    start = base+symbols['_MAIN__']['rva']
    scratch = base+symbols['_matcom2_']['rva']
    imports = {item.name.decode():item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    code = Driver(start,imports)
    code.emit('fc');code.push(-11);code.api('GetStdHandle');code.emit('89c3')
    for case in cases:
        # Descriptor: size, G-state, value*, digits*, count, exponent, kind,
        # decimal places, scale, engineering shift, padding. Buffer is 16 bytes.
        data = struct.pack('<HHIIiibBhhH',4,0,scratch+44,scratch+28,0,0,
                           case['kind'],case['precision'],case['scale'],0,0)
        code.copy(scratch,data+b' '*16+struct.pack('<I',case['bits']))
        code.push(scratch);code.call(base+symbols['_jwe_iroc']['rva']);code.emit('83c404')
        code.emit('a3'+struct.pack('<I',scratch+20).hex()) # status
        code.emit('0fb705'+struct.pack('<I',scratch+24).hex())
        code.emit('66a3'+struct.pack('<I',scratch+26).hex()) # engineering shift
        code.emit('0fb705'+struct.pack('<I',scratch+2).hex())
        code.emit('66a3'+struct.pack('<I',scratch+24).hex()) # G-state
        code.write(scratch+12,32,scratch+48)
    driver = code.finish()
    later = sorted(item['rva'] for item in symbols.values() if item['type']==32 and item['section']==1 and item['rva']>symbols['_MAIN__']['rva'])
    if len(driver) > later[0]-symbols['_MAIN__']['rva']:
        raise ValueError('Decimal batch exceeds the replaceable PROGRAM body.')
    result = bytearray(original)
    offset = pe.get_offset_from_rva(symbols['_MAIN__']['rva'])
    result[offset:offset+len(driver)] = driver
    return bytes(result)


def main():
    import pefile
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output',type=Path,required=True)
    parser.add_argument('--native',type=Path)
    parser.add_argument('--wine-prefix',type=Path,default=ROOT/'build/wineprefix')
    args = parser.parse_args()
    output = args.output.resolve()
    if output.exists() or ROOT/'build' not in output.parents:
        parser.error('Use a new FEQ/build/ directory.')
    output.mkdir(parents=True)
    original = (ROOT/'originals/feq1061/wrdapp/FEQ_10.61/BIN/feq.exe').read_bytes()
    if hashlib.sha256(original).hexdigest() != ORIGINAL_SHA256:
        raise ValueError('The recovered original executable hash changed.')
    pe = pefile.PE(data=original)
    symbols = {item['name']:item for item in coff_symbols(original)}
    cases = fixtures()
    inputs = b''.join(struct.pack('<IIii',case['bits'],case['kind'],case['precision'],case['scale']) for case in cases)
    (output/'inputs.bin').write_bytes(inputs)
    (output/'fixtures.json').write_text(json.dumps(cases,indent=2)+'\n')
    env = os.environ.copy()
    env.update(WINEPREFIX=str(args.wine_prefix.resolve()),WINEDEBUG='-all',WINEDLLOVERRIDES='mscoree,mshtml=',MVK_CONFIG_LOG_LEVEL='0')
    expected = bytearray()
    for first in range(0,len(cases),64):
        batch = cases[first:first+64]
        executable = output/'PROBE.EXE'
        executable.write_bytes(image(original,pe,symbols,batch))
        command = [str(executable)] if os.name == 'nt' else ['wine',str(executable)]
        process = subprocess.run(command,cwd=output,env=env,capture_output=True,timeout=30,stdin=subprocess.DEVNULL)
        if process.returncode or len(process.stdout) != len(batch)*32:
            (output/'error.log').write_bytes(process.stdout+process.stderr)
            raise RuntimeError(f'Original decimal driver failed: exit {process.returncode}, {len(process.stdout)} bytes.')
        expected.extend(process.stdout)
        print(f'{first+len(batch)}/{len(cases)} original decimal conversions captured.',flush=True)
    (output/'outputs.bin').write_bytes(expected)
    manifest = {'original_sha256':ORIGINAL_SHA256,'routine':'_jwe_iroc (REAL*4 branch), _jwe_igetfig',
                'cases':len(cases),'input_record_bytes':16,'output_record_bytes':32,
                'input_sha256':hashlib.sha256(inputs).hexdigest(),'output_sha256':hashlib.sha256(expected).hexdigest()}
    if args.native:
        native = subprocess.run([str(args.native.resolve())],input=inputs,capture_output=True,timeout=30)
        (output/'native.bin').write_bytes(native.stdout)
        (output/'native.stderr.log').write_bytes(native.stderr)
        manifest.update(native_sha256=hashlib.sha256(args.native.read_bytes()).hexdigest(),
                        native_returncode=native.returncode,exact_bytes=native.returncode == 0 and bytes(expected) == native.stdout)
    (output/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    if args.native:
        raise SystemExit(0 if manifest['exact_bytes'] else 1)


if __name__ == '__main__':
    main()
