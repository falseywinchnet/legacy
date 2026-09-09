#!/usr/bin/env python3
"""Capture unchanged FEQUTL INTERP station-fraction instruction sequences.

A temporary PROGRAM driver copies input records, loops over them and writes the
retained fraction as binary64. The released startup and precision setting run
normally; all three numerical instruction blocks retain their original bytes.
Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
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
from probe_profile_original import Driver, ROOT, real
from probe_geometry_original import ORIGINAL_SHA256

SEQUENCES = [('span',0x42e8d,0x42ea5),('reciprocal',0x43756,0x43773),
             ('fraction',0x438a5,0x438b7)]


def fixtures():
    rng = random.Random(1061580429)
    cases = []
    for scale in (1.e-10,.0001,1.,10000.,1.e10):
        for left,right in ((0.,17.3),(-123.7,59.1),(1001.125,1001.375),(-0.,1.),(-1000.,0.)):
            a,b = real(left*scale),real(right*scale)
            for fraction in (0.,1.e-7,.1234567,.5,.9999999,1.):
                cases.append(dict(name=f'scale-{scale}-bounds-{left}-{right}-fraction-{fraction}',
                                  values=[a,b,real(a+fraction*(b-a))]))
        for trial in range(72):
            a = real(rng.uniform(-1000,1000)*scale)
            b = real(a+rng.uniform(.1,1000)*scale)
            cases.append(dict(name=f'random-scale-{scale}-trial-{trial}',
                              values=[a,b,real(a+rng.random()*(b-a))]))
    for exponent in (-30,-1,0,7,30):
        a = real(2.**exponent)
        word = struct.unpack('<I',struct.pack('<f',a))[0]
        for distance in (1,2,3,7,17):
            b = struct.unpack('<f',struct.pack('<I',word+distance))[0]
            for station in (a,real((a+b)*.5),b):
                cases.append(dict(name=f'adjacent-exponent-{exponent}-steps-{distance}-station-{station}',values=[a,b,station]))
    return cases


def record(case):
    return struct.pack('<3f',*case['values'])


def image(original,pe,symbols,cases):
    base = pe.OPTIONAL_HEADER.ImageBase
    start = base+symbols['_MAIN__']['rva']
    scratch = base+symbols['_ftable_']['rva']+4096
    frame = scratch+2048
    input_address = scratch+4096
    imports = {item.name.decode():item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    code = Driver(start,imports)
    code.emit('e900000000')
    entry = start+len(code.code)
    code.emit('5556bd'+struct.pack('<I',frame).hex())
    code.emit('a1'+struct.pack('<I',scratch+36).hex())
    code.emit('a3'+struct.pack('<I',frame+0x14).hex()+'83c004')
    code.emit('a3'+struct.pack('<I',frame+0x18).hex())
    for name,first,last in SEQUENCES:
        if name == 'fraction':
            code.emit('a1'+struct.pack('<I',scratch+36).hex()+'83c008be01000000')
        code.code.extend(pe.get_data(first,last-first))
    code.emit('5e5dc3')
    struct.pack_into('<i',code.code,1,len(code.code)-5)
    code.emit('fc')
    code.copy(input_address,b''.join(record(case) for case in cases))
    code.store(scratch+32,len(cases));code.store(scratch+36,input_address)
    code.push(-11);code.api('GetStdHandle');code.emit('89c3')
    loop = start+len(code.code)
    code.call(entry)
    code.emit('dd1d'+struct.pack('<I',scratch+256).hex())
    code.write(scratch+256,8,scratch+512)
    code.emit('8305'+struct.pack('<I',scratch+36).hex()+'0c')
    code.emit('ff0d'+struct.pack('<I',scratch+32).hex())
    code.emit('0f85'+struct.pack('<i',loop-(start+len(code.code)+6)).hex())
    driver = code.finish()
    later = sorted(item['rva'] for item in symbols.values() if item['type']==32 and item['section']==1 and item['rva']>symbols['_MAIN__']['rva'])
    if len(driver)>later[0]-symbols['_MAIN__']['rva']:
        raise ValueError('Station-fraction driver exceeds replaceable PROGRAM body.')
    result = bytearray(original)
    offset = pe.get_offset_from_rva(symbols['_MAIN__']['rva'])
    result[offset:offset+len(driver)] = driver
    return bytes(result)


def main():
    import pefile
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output',type=Path,required=True);parser.add_argument('--native',type=Path)
    parser.add_argument('--fixtures',type=Path);parser.add_argument('--wine-prefix',type=Path,default=ROOT/'build/wineprefix')
    args = parser.parse_args();output = args.output.resolve()
    if output.exists() or ROOT/'build' not in output.parents:parser.error('Use a new FEQ/build/ directory.')
    output.mkdir(parents=True)
    original = (ROOT/'originals/feq1061/wrdapp/FEQ_10.61/BIN/fequtl.exe').read_bytes()
    if hashlib.sha256(original).hexdigest()!=ORIGINAL_SHA256:raise ValueError('Recovered executable hash changed.')
    pe = pefile.PE(data=original);symbols = {item['name']:item for item in coff_symbols(original)}
    cases = json.loads(args.fixtures.read_text()) if args.fixtures else fixtures()
    inputs = b''.join(record(case) for case in cases)
    (output/'inputs.bin').write_bytes(inputs);(output/'fixtures.json').write_text(json.dumps(cases,indent=2)+'\n')
    exe = output/'PROBE.EXE';exe.write_bytes(image(original,pe,symbols,cases))
    env = os.environ.copy();env.update(WINEPREFIX=str(args.wine_prefix.resolve()),WINEDEBUG='-all',WINEDLLOVERRIDES='mscoree,mshtml=',MVK_CONFIG_LOG_LEVEL='0')
    command = [str(exe)] if os.name=='nt' else ['wine',str(exe)]
    process = subprocess.run(command,cwd=output,env=env,capture_output=True,timeout=45,stdin=subprocess.DEVNULL)
    (output/'stderr.log').write_bytes(process.stderr)
    if process.returncode or len(process.stdout)!=8*len(cases):
        (output/'error.log').write_bytes(process.stdout+process.stderr)
        raise RuntimeError(f'Original station-fraction driver failed: exit {process.returncode}, {len(process.stdout)} bytes.')
    expected = process.stdout;(output/'outputs.bin').write_bytes(expected)
    manifest = dict(original_sha256=ORIGINAL_SHA256,routines=['_interp_'],
        instruction_sequences=[dict(name=name,start_rva=hex(first),end_rva=hex(last),sha256=hashlib.sha256(pe.get_data(first,last-first)).hexdigest()) for name,first,last in SEQUENCES],
        cases=len(cases),input_sha256=hashlib.sha256(inputs).hexdigest(),output_sha256=hashlib.sha256(expected).hexdigest(),
        probe_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        fixtures=[dict(name=case['name'],offset=index*8,bytes=8) for index,case in enumerate(cases)])
    if args.native:
        native = subprocess.run([str(args.native.resolve()),'--station'],input=inputs,capture_output=True,timeout=30)
        (output/'native.bin').write_bytes(native.stdout);(output/'native.stderr.log').write_bytes(native.stderr)
        manifest.update(native_sha256=hashlib.sha256(args.native.read_bytes()).hexdigest(),native_returncode=native.returncode,
                        exact_bytes=native.returncode==0 and expected==native.stdout)
    (output/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print(f'{len(cases)} original station fractions captured; exact: {manifest.get("exact_bytes","not compared")}.')
    if args.native:raise SystemExit(0 if manifest['exact_bytes'] else 1)

if __name__=='__main__':main()
