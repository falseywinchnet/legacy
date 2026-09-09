#!/usr/bin/env python3
"""Capture original FEQUTL real and double power results for controlled inputs.

Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
Only a temporary PROGRAM body is replaced; startup and power instructions
remain unchanged. Every output is a raw binary32 or binary64 result.
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
    rng = random.Random(58010611660)
    result=[]
    exponents=[-3.0,-1.0,-0.5,0.0,0.083333333333333,0.3333333,0.6666667,1.0,1.333333,1.5,1.666667,2.0,2.333333,2.666667,3.0,3.333333,4.0,5.0,6.0,7.0,8.0]
    for kind in (0,1):
        for trial in range(400):
            x=2.0**rng.uniform(-12,12)
            y=rng.choice(exponents)
            if kind==0:x,y=real(x),real(y)
            else:
                if trial%2==0:y=real(y)
            result.append({'name':f'{"real" if kind==0 else "double"}-trial-{trial}', 'kind':kind,'base':x,'exponent':y})
        for x in (0.0,1.0,0.5,2.0,0.99999,1.00001):
            for y in exponents:
                if x==0 and y<0:continue
                if kind==0:xx,yy=real(x),real(y)
                else:xx,yy=x,y
                result.append({'name':f'kind-{kind}-base-{x}-exponent-{y}', 'kind':kind,'base':xx,'exponent':yy})
    wide_rng = random.Random(5801660)
    for kind in (0,1):
        maximum,mantissa_bits = (255,23) if kind == 0 else (2047,52)
        integer_format,real_format = ('<I','<f') if kind == 0 else ('<Q','<d')
        for field in range(1,maximum):
            word = (field << mantissa_bits) | wide_rng.getrandbits(mantissa_bits)
            x = struct.unpack(real_format,struct.pack(integer_format,word))[0]
            y = wide_rng.choice([real(0.3333333),real(0.6666667),-real(0.3333333)])
            result.append({'name':f'kind-{kind}-binary-exponent-{field}','kind':kind,'base':x,'exponent':y})
        for word in (1,2,3,8,1023,(1 << mantissa_bits)-1):
            x = struct.unpack(real_format,struct.pack(integer_format,word))[0]
            for y in (real(0.3333333),real(0.6666667),-real(0.3333333)):
                result.append({'name':f'kind-{kind}-subnormal-{word}-y-{y}','kind':kind,'base':x,'exponent':y})
    return result


def record(case):return struct.pack('<IIdd',case['kind'],0,case['base'],case['exponent'])


def image(original,pe,symbols,cases):
    base=pe.OPTIONAL_HEADER.ImageBase;start=base+symbols['_MAIN__']['rva'];scratch=base+symbols['_ftable_']['rva']
    imports={item.name.decode():item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    code=Driver(start,imports);code.emit('fc');code.push(-11);code.api('GetStdHandle');code.emit('89c3')
    data=bytearray()
    for case in cases:
        data.extend(struct.pack('<dd',case['base'],case['exponent']) if case['kind'] else struct.pack('<ff8x',case['base'],case['exponent']))
    data.extend(bytes(8*len(cases)+4));code.copy(scratch,data)
    results=scratch+16*len(cases);written=results+8*len(cases)
    for index,case in enumerate(cases):
        x=scratch+index*16;code.push(x+(8 if case['kind'] else 4));code.push(x)
        code.call(base+symbols['_g_adxd' if case['kind'] else '_g_arxr']['rva']);code.emit('83c408')
        code.emit(('dd1d' if case['kind'] else 'd91d')+struct.pack('<I',results+8*index).hex())
    code.write(results,len(cases)*8,written);driver=code.finish()
    later=sorted(item['rva'] for item in symbols.values() if item['type']==32 and item['section']==1 and item['rva']>symbols['_MAIN__']['rva'])
    if len(driver)>later[0]-symbols['_MAIN__']['rva']:raise ValueError('Power driver exceeds replaceable PROGRAM body.')
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
            raise RuntimeError(f'Original power driver failed: exit {process.returncode}, {len(process.stdout)} bytes.')
        expected.extend(process.stdout);print(f'{first+len(batch)}/{len(cases)} original powers captured.',flush=True)
    (output/'outputs.bin').write_bytes(expected)
    manifest={'original_sha256':ORIGINAL_SHA256,'routines':['_g_arxr','_g_adxd'],'cases':len(cases),
        'input_sha256':hashlib.sha256(inputs).hexdigest(),'output_sha256':hashlib.sha256(expected).hexdigest()}
    if args.native:
        native=subprocess.run([str(args.native.resolve())],input=inputs,capture_output=True,timeout=30)
        (output/'native.bin').write_bytes(native.stdout);(output/'native.stderr.log').write_bytes(native.stderr)
        manifest.update(native_sha256=hashlib.sha256(args.native.read_bytes()).hexdigest(),native_returncode=native.returncode,
            exact_bytes=native.returncode==0 and bytes(expected)==native.stdout)
    (output/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    if args.native:raise SystemExit(0 if manifest['exact_bytes'] else 1)


if __name__=='__main__':main()
