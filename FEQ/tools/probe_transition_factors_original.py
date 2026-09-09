#!/usr/bin/env python3
"""Capture the unchanged FEQUTL 5.80 complete FACDC and GMEAN transition-factor routines.

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
    rng=random.Random(5801061136);cases=[]
    for scale in (.0001,1.,10000.):
        for index in range(1024):
            smoothing=real(rng.uniform(.001,10)*scale) if index%6 else 0.
            argument=real(rng.uniform(-2,2)*smoothing) if smoothing else real(rng.uniform(-10,10)*scale)
            if index%12==1:argument=-smoothing
            elif index%12==2:argument=smoothing
            elif index%12==3:argument=0.
            elif index%12==4:argument=-0.
            ka=real(rng.uniform(0,1));kd=real(rng.uniform(0,1))
            left=real(rng.uniform(.01,100)*scale);right=real(rng.uniform(.01,100)*scale)
            exponent=real(rng.choice((-4.,-2.,-1.,-.5,-.010000001,-.01,-.009999999,0.,.009999999,.01,.010000001,.5,1.,2.,4.)))
            cases.append(dict(name=f'scale-{scale}-case-{index}',
                fields=[argument,smoothing,ka,kd,left,right,exponent]))
    return cases


def image(original,pe,symbols,count):
    base=pe.OPTIONAL_HEADER.ImageBase;start=base+symbols['_MAIN__']['rva']
    scratch=base+symbols['_ftable_']['rva']+4096;record=scratch+128
    imports={item.name.decode():item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    code=Driver(start,imports);code.emit('fc');code.push(-11);code.api('GetStdHandle');code.emit('89c3')
    code.push(-10);code.api('GetStdHandle');code.emit('a3'+struct.pack('<I',scratch).hex())
    code.store(scratch+4,count);code.store(scratch+16,6)
    loop=start+len(code.code)
    code.push(0);code.push(scratch+8);code.push(28);code.push(record)
    code.emit('ff35'+struct.pack('<I',scratch).hex());code.api('ReadFile')
    code.emit('813d'+struct.pack('<II',scratch+8,28).hex());branch=len(code.code);code.emit('0f8400000000')
    code.push(2);code.api('ExitProcess');struct.pack_into('<i',code.code,branch+2,len(code.code)-(branch+6))
    for routine,indices,destination in (('_facdc_',range(3,-1,-1),scratch+32),('_gmean_',range(6,3,-1),scratch+40)):
        for index in indices:code.push(record+index*4)
        code.call(base+symbols[routine]['rva']);code.emit('83c4'+bytes((len(indices)*4,)).hex())
        code.emit('dd1d'+struct.pack('<I',destination).hex())
    code.write(scratch+32,16,scratch+12)
    code.emit('ff0d'+struct.pack('<I',scratch+4).hex())
    code.emit('0f85'+struct.pack('<i',loop-(start+len(code.code)+6)).hex())
    driver=code.finish();later=sorted(item['rva'] for item in symbols.values() if item['type']==32 and item['section']==1 and item['rva']>symbols['_MAIN__']['rva'])
    if len(driver)>later[0]-symbols['_MAIN__']['rva']:raise ValueError('Transition-factor driver exceeds PROGRAM body.')
    result=bytearray(original);offset=pe.get_offset_from_rva(symbols['_MAIN__']['rva']);result[offset:offset+len(driver)]=driver
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
    inputs=b''.join(struct.pack('<7f',*case['fields']) for case in cases)
    (output/'inputs.bin').write_bytes(inputs);(output/'fixtures.json').write_text(json.dumps(cases,indent=2)+'\n')
    exe=output/'PROBE.EXE';exe.write_bytes(image(original,pe,symbols,len(cases)))
    env=os.environ.copy();env.update(WINEPREFIX=str(args.wine_prefix.resolve()),WINEDEBUG='-all',WINEDLLOVERRIDES='mscoree,mshtml=',MVK_CONFIG_LOG_LEVEL='0')
    command=[str(exe)] if os.name=='nt' else ['wine',str(exe)]
    with (output/'inputs.bin').open('rb') as stream:
        process=subprocess.run(command,cwd=output,env=env,stdin=stream,capture_output=True,timeout=60)
    if process.returncode or len(process.stdout)!=16*len(cases):
        (output/'error.log').write_bytes(process.stdout+process.stderr)
        raise RuntimeError(f'Original transition-factor driver failed: exit {process.returncode}, {len(process.stdout)} bytes.')
    expected=process.stdout;(output/'outputs.bin').write_bytes(expected)
    manifest=dict(original_sha256=ORIGINAL_SHA256,routines=['_facdc_','_gmean_'],cases=len(cases),
        original_rva=['0x33d90..0x33e33','0x33e40..0x33ed2'],
        instruction_sha256=[hashlib.sha256(pe.get_data(rva,length)).hexdigest() for rva,length in ((0x33d90,0xa3),(0x33e40,0x92))],
        input_record_bytes=28,output_record_bytes=16,
        input_sha256=hashlib.sha256(inputs).hexdigest(),output_sha256=hashlib.sha256(expected).hexdigest(),
        probe_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        fixtures=[dict(name=case['name'],offset=index*16,bytes=16) for index,case in enumerate(cases)])
    if args.native:
        native=subprocess.run([str(args.native.resolve()),'--transition-factors'],input=inputs,capture_output=True,timeout=30)
        (output/'native.bin').write_bytes(native.stdout);(output/'native.stderr.log').write_bytes(native.stderr)
        manifest.update(native_sha256=hashlib.sha256(args.native.read_bytes()).hexdigest(),native_returncode=native.returncode,
            exact_bytes=native.returncode==0 and expected==native.stdout)
    (output/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print(f'{len(cases)} original loss factors and generalized conveyance means captured.',flush=True)
    if args.native:raise SystemExit(0 if manifest['exact_bytes'] else 1)

if __name__=='__main__':main()
