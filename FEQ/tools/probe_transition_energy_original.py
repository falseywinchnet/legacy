#!/usr/bin/env python3
"""Capture the unchanged FEQUTL 5.80 ECECHK and FHPL energy balances, head and Froude residuals.

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


def fixtures():
    rng=random.Random(5801061236);cases=[]
    for scale in (.0001,1.,10000.):
        for index in range(1024):
            htl=real(rng.uniform(.1,100)*scale);hpr=real(rng.uniform(.01,100)*scale)
            al=real(rng.uniform(.1,100)*scale**2);ar=real(rng.uniform(.1,100)*scale**2)
            alpha_l=real(rng.uniform(.5,3)) if index%8 else 0.
            alpha_r=real(rng.uniform(.5,3)) if index%9 else 0.
            kl=real(rng.uniform(.1,100)*scale**(8/3));kr=real(rng.uniform(.1,100)*scale**(8/3))
            dx=real(rng.uniform(0,100)*scale) if index%3 else 0.
            smoothing=real(rng.uniform(.001,1)*scale**.5) if index%6 else 0.
            ka=real(rng.uniform(0,1));kd=real(rng.uniform(0,1));g=real((19.6133,64.348,64.4)[index%3])
            q=real(rng.uniform(-100,100)*scale**2.5) if index%7 else 0.
            t=real(rng.choice((-2.,-.5,-.010000001,-.01,-.009999999,0.,.009999999,.01,.010000001,.5,1.,2.)))
            eps=real(rng.uniform(1e-5,.1)*scale);hpl=real(rng.uniform(.01,100)*scale)
            qc=real(rng.uniform(.1,100)*scale**2.5)
            cases.append(dict(name=f'scale-{scale}-case-{index}',
                fields=[htl,hpr,al,ar,alpha_l,alpha_r,kl,kr,dx,smoothing,ka,kd,g,q,t,eps,hpl,qc]))
    return cases


def image(original,pe,symbols,count):
    base=pe.OPTIONAL_HEADER.ImageBase;start=base+symbols['_MAIN__']['rva']
    scratch=base+symbols['_ftable_']['rva']+4096;record=scratch+128
    imports={item.name.decode():item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    code=Driver(start,imports);code.emit('fc');code.push(-11);code.api('GetStdHandle');code.emit('89c3')
    code.push(-10);code.api('GetStdHandle');code.emit('a3'+struct.pack('<I',scratch).hex())
    code.store(scratch+4,count);code.store(scratch+16,6)
    loop=start+len(code.code)
    code.push(0);code.push(scratch+8);code.push(72);code.push(record)
    code.emit('ff35'+struct.pack('<I',scratch).hex());code.api('ReadFile')
    code.emit('813d'+struct.pack('<II',scratch+8,72).hex());branch=len(code.code);code.emit('0f8400000000')
    code.push(2);code.api('ExitProcess');struct.pack_into('<i',code.code,branch+2,len(code.code)-(branch+6))
    destinations=(0xe9ae20,0xe9ae28,0xe9ae34,0xe9ae38,0xe9ae3c,0xe9ae40,
        0xe9ae44,0xe9ae48,0xe9ae64,0xe9ae68,0xe9ae5c,0xe9ae60,0xe9ae6c,
        0xe9ae74,0xe9ae84,0x40ef77c,0xe9ae24,0xe9ae78)
    for index,destination in enumerate(destinations):
        code.emit('a1'+struct.pack('<I',record+index*4).hex()+'a3'+struct.pack('<I',destination).hex())
    code.call(base+symbols['_ecechk_']['rva'])
    code.emit('dd1d'+struct.pack('<I',scratch+48).hex())
    # FHPL after section lookup and its left-total-head store. Preserve all
    # arithmetic and calls in place; RET replaces only the following epilogue.
    code.emit('5355bd'+struct.pack('<I',scratch+4096).hex())
    code.call(base+0x33fc1)
    code.emit('dd1d'+struct.pack('<I',scratch+56).hex()+'5d5b')
    code.code.extend(pe.get_data(0x33f62,0x26))
    code.emit('a1'+struct.pack('<I',0xe9ae20).hex()+'a3'+struct.pack('<I',scratch+64).hex())
    code.code.extend(pe.get_data(0x33c45,0x12))
    code.emit('dd1d'+struct.pack('<I',scratch+68).hex())
    code.write(scratch+48,28,scratch+12)
    code.emit('ff0d'+struct.pack('<I',scratch+4).hex())
    code.emit('0f85'+struct.pack('<i',loop-(start+len(code.code)+6)).hex())
    driver=code.finish();later=sorted(item['rva'] for item in symbols.values() if item['type']==32 and item['section']==1 and item['rva']>symbols['_MAIN__']['rva'])
    if len(driver)>later[0]-symbols['_MAIN__']['rva']:raise ValueError('Transition-energy driver exceeds PROGRAM body.')
    result=bytearray(original);offset=pe.get_offset_from_rva(symbols['_MAIN__']['rva']);result[offset:offset+len(driver)]=driver
    result[pe.get_offset_from_rva(0x34094)]=0xc3
    return bytes(result)


def main():
    import pefile
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--output',type=Path,required=True)
    parser.add_argument('--native',type=Path);parser.add_argument('--fixtures',type=Path)
    parser.add_argument('--wine-prefix',type=Path,default=ROOT/'build/wineprefix')
    args=parser.parse_args();output=args.output.resolve()
    if output.exists() or ROOT/'build' not in output.parents:parser.error('Use a new FEQ/build/ directory.')
    output.mkdir(parents=True)
    original=(ROOT/'originals/feq1061/wrdapp/FEQ_10.61/BIN/fequtl.exe').read_bytes()
    if hashlib.sha256(original).hexdigest()!=ORIGINAL_SHA256:raise ValueError('Recovered executable hash changed.')
    pe=pefile.PE(data=original);symbols={item['name']:item for item in coff_symbols(original)}
    cases=json.loads(args.fixtures.read_text()) if args.fixtures else fixtures()
    inputs=b''.join(struct.pack('<18f',*case['fields']) for case in cases)
    (output/'inputs.bin').write_bytes(inputs);(output/'fixtures.json').write_text(json.dumps(cases,indent=2)+'\n')
    exe=output/'PROBE.EXE';exe.write_bytes(image(original,pe,symbols,len(cases)))
    env=os.environ.copy();env.update(WINEPREFIX=str(args.wine_prefix.resolve()),WINEDEBUG='-all',WINEDLLOVERRIDES='mscoree,mshtml=',MVK_CONFIG_LOG_LEVEL='0')
    command=[str(exe)] if os.name=='nt' else ['wine',str(exe)]
    with (output/'inputs.bin').open('rb') as stream:
        process=subprocess.run(command,cwd=output,env=env,stdin=stream,capture_output=True,timeout=60)
    if process.returncode or len(process.stdout)!=28*len(cases):
        (output/'error.log').write_bytes(process.stdout+process.stderr)
        raise RuntimeError(f'Original transition-energy driver failed: exit {process.returncode}, {len(process.stdout)} bytes.')
    expected=process.stdout;(output/'outputs.bin').write_bytes(expected)
    manifest=dict(original_sha256=ORIGINAL_SHA256,routines=['_ecechk_','_fhpl_','_frlres_'],cases=len(cases),
        original_rva=['0x33c70..0x33d86','0x33fc1..0x34094','0x33f62..0x33f88','0x33c45..0x33c57'],
        instruction_sha256=[hashlib.sha256(pe.get_data(rva,length)).hexdigest() for rva,length in ((0x33c70,0x116),(0x33fc1,0xd3),(0x33f62,0x26),(0x33c45,0x12))],
        input_record_bytes=72,output_record_bytes=28,
        input_sha256=hashlib.sha256(inputs).hexdigest(),output_sha256=hashlib.sha256(expected).hexdigest(),
        probe_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        fixtures=[dict(name=case['name'],offset=index*28,bytes=28) for index,case in enumerate(cases)])
    if args.native:
        native=subprocess.run([str(args.native.resolve()),'--transition-energy'],input=inputs,capture_output=True,timeout=30)
        (output/'native.bin').write_bytes(native.stdout);(output/'native.stderr.log').write_bytes(native.stderr)
        manifest.update(native_sha256=hashlib.sha256(args.native.read_bytes()).hexdigest(),native_returncode=native.returncode,
            exact_bytes=native.returncode==0 and expected==native.stdout)
    (output/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print(f'{len(cases)} original energy checks, head residuals, total heads and Froude residuals captured.',flush=True)
    if args.native:raise SystemExit(0 if manifest['exact_bytes'] else 1)

if __name__=='__main__':main()
