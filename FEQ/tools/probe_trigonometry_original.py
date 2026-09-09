#!/usr/bin/env python3
"""Capture original FEQUTL REAL inverse-trigonometric register results.

Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
Only a temporary PROGRAM body is replaced; startup and inverse-trigonometric instructions
remain unchanged. Every output is the raw binary64 register result.
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
from probe_geometry_original import ORIGINAL_SHA256
from probe_profile_original import Driver, ROOT, real


def fixtures():
    rng=random.Random(580101960);result=[]
    words=[0,0x80000000,1,0x80000001,0x007fffff,0x807fffff,0x00800000,0x80800000]
    for value in (0.5,real(0.7071067690849304),1.):
        word=struct.unpack('<I',struct.pack('<f',value))[0]
        for offset in (-2,-1,0,1,2):
            if word+offset<=0x3f800000:words.extend([word+offset,0x80000000|(word+offset)])
    for field in range(1,127):
        for mantissa in (0,0x555555,0x7fffff):words.extend([(field<<23)|mantissa,0x80000000|(field<<23)|mantissa])
    for trial in range(600):words.append(struct.unpack('<I',struct.pack('<f',rng.uniform(-1,1)))[0])
    for kind in (0,1):
        for index,word in enumerate(words):
            result.append(dict(name=f'kind-{kind}-word-{word:08x}-{index}',kind=kind,argument=struct.unpack('<f',struct.pack('<I',word))[0]))
    return result


def record(case):return struct.pack('<If',case['kind'],case['argument'])


def image(original,pe,symbols,cases):
    base=pe.OPTIONAL_HEADER.ImageBase;start=base+symbols['_MAIN__']['rva'];scratch=base+symbols['_ftable_']['rva']
    imports={item.name.decode():item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    code=Driver(start,imports);code.emit('fc');code.push(-11);code.api('GetStdHandle');code.emit('89c3')
    data=bytearray()
    for case in cases:
        data.extend(struct.pack('<f12x',case['argument']))
    data.extend(bytes(8*len(cases)+4));code.copy(scratch,data)
    results=scratch+16*len(cases);written=results+8*len(cases)
    for index,case in enumerate(cases):
        x=scratch+index*16;code.push(x)
        code.call(base+symbols['_g_acos' if case['kind'] else '_g_asin']['rva']);code.emit('83c404')
        code.emit('dd1d'+struct.pack('<I',results+8*index).hex())
    code.write(results,len(cases)*8,written);driver=code.finish()
    later=sorted(item['rva'] for item in symbols.values() if item['type']==32 and item['section']==1 and item['rva']>symbols['_MAIN__']['rva'])
    if len(driver)>later[0]-symbols['_MAIN__']['rva']:raise ValueError('Trigonometry driver exceeds replaceable PROGRAM body.')
    result=bytearray(original);offset=pe.get_offset_from_rva(symbols['_MAIN__']['rva']);result[offset:offset+len(driver)]=driver
    return bytes(result)


def main():
    import pefile
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output',type=Path,required=True);parser.add_argument('--native',type=Path);parser.add_argument('--fixtures',type=Path)
    parser.add_argument('--wine-prefix',type=Path,default=ROOT/'build/wineprefix')
    args=parser.parse_args();output=args.output.resolve()
    if output.exists() or ROOT/'build' not in output.parents:parser.error('Use a new FEQ/build/ directory.')
    output.mkdir(parents=True)
    original=(ROOT/'originals/feq1061/wrdapp/FEQ_10.61/BIN/fequtl.exe').read_bytes()
    if hashlib.sha256(original).hexdigest()!=ORIGINAL_SHA256:raise ValueError('Recovered executable hash changed.')
    pe=pefile.PE(data=original);symbols={item['name']:item for item in coff_symbols(original)}
    cases=json.loads(args.fixtures.read_text()) if args.fixtures else fixtures();inputs=b''.join(record(case) for case in cases)
    (output/'inputs.bin').write_bytes(inputs);(output/'fixtures.json').write_text(json.dumps(cases,indent=2)+'\n')
    env=os.environ.copy();env.update(WINEPREFIX=str(args.wine_prefix.resolve()),WINEDEBUG='-all',WINEDLLOVERRIDES='mscoree,mshtml=',MVK_CONFIG_LOG_LEVEL='0')
    expected=bytearray()
    for first in range(0,len(cases),96):
        batch=cases[first:first+96];exe=output/'PROBE.EXE';exe.write_bytes(image(original,pe,symbols,batch))
        command=[str(exe)] if os.name=='nt' else ['wine',str(exe)]
        process=subprocess.run(command,cwd=output,env=env,capture_output=True,timeout=30,stdin=subprocess.DEVNULL)
        if process.returncode or len(process.stdout)!=8*len(batch):
            (output/'error.log').write_bytes(process.stdout+process.stderr)
            raise RuntimeError(f'Original trigonometry driver failed: exit {process.returncode}, {len(process.stdout)} bytes.')
        expected.extend(process.stdout);print(f'{first+len(batch)}/{len(cases)} original inverse-trigonometric values captured.',flush=True)
    (output/'outputs.bin').write_bytes(expected)
    manifest={'original_sha256':ORIGINAL_SHA256,'routines':['_g_asin','_g_acos'],'cases':len(cases),
        'input_sha256':hashlib.sha256(inputs).hexdigest(),'output_sha256':hashlib.sha256(expected).hexdigest()}
    if args.native:
        native=subprocess.run([str(args.native.resolve())],input=inputs,capture_output=True,timeout=30)
        (output/'native.bin').write_bytes(native.stdout);(output/'native.stderr.log').write_bytes(native.stderr)
        manifest.update(native_sha256=hashlib.sha256(args.native.read_bytes()).hexdigest(),native_returncode=native.returncode,
            exact_bytes=native.returncode==0 and bytes(expected)==native.stdout)
    (output/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    if args.native:raise SystemExit(0 if manifest['exact_bytes'] else 1)


if __name__=='__main__':main()
