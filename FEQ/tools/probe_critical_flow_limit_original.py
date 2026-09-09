#!/usr/bin/env python3
"""Capture unchanged QCLIM extrapolation, retained flow and reported slope.

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
    rng=random.Random(5801061237);cases=[]
    for scale in (.0001,1.,10000.):
        for index in range(1024):
            lower=real(rng.uniform(.1,100)*scale)
            upper=real(lower+rng.uniform(.1,10)*scale)
            depth=real(lower+rng.uniform(-.005,2)*(upper-lower))
            if index%11==0:depth=lower
            elif index%11==1:depth=upper
            low_flow=real(rng.uniform(.01,1000)*scale**2.5)
            high_flow=real(low_flow*rng.uniform(.5,2))
            factor=real(rng.uniform(.01,2)) if index%5 else 1.
            if index%17==0:factor=0.
            root=real(rng.uniform(.1,100)*scale**(4/3))
            cases.append(dict(name=f'scale-{scale}-case-{index}',
                fields=[depth,lower,upper,low_flow,high_flow,factor,root]))
    # Original UTLEXM sewer table 1057 at the first slot row, before QCLIMIT.
    cases[0]=dict(name='utlexm-sewer-1057-slot-limit',fields=[
        3.51231050491333,3.36098575592041,3.474454164505005,
        138.6665802001953,197.7191619873047,1.,23.36881446838379])
    return cases


def image(original,pe,symbols,count):
    base=pe.OPTIONAL_HEADER.ImageBase;start=base+symbols['_MAIN__']['rva']
    table=base+symbols['_ftable_']['rva'];scratch=table+4096;record=scratch+128
    imports={item.name.decode():item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    code=Driver(start,imports);code.emit('fc');code.push(-11);code.api('GetStdHandle');code.emit('89c3')
    code.push(-10);code.api('GetStdHandle');code.emit('a3'+struct.pack('<I',scratch).hex())
    code.store(scratch+4,count)
    loop=start+len(code.code)
    code.push(0);code.push(scratch+8);code.push(28);code.push(record)
    code.emit('ff35'+struct.pack('<I',scratch).hex());code.api('ReadFile')
    code.emit('813d'+struct.pack('<II',scratch+8,28).hex());branch=len(code.code);code.emit('0f8400000000')
    code.push(2);code.api('ExitProcess');struct.pack_into('<i',code.code,branch+2,len(code.code)-(branch+6))
    destinations=(table+40*4,table+24*4,table+32*4,table+31*4,table+39*4,0x55609c,table+43*4)
    for index,destination in enumerate(destinations):
        code.emit('a1'+struct.pack('<I',record+index*4).hex()+'a3'+struct.pack('<I',destination).hex())
    # EBX/ESI address the unchanged table reads; EBP supplies scratch locals.
    # Preserve the wide Qc in both the original x87 spill and binary64 capture.
    code.emit('535655bd'+struct.pack('<I',scratch+1024).hex()+'bb20000000be08000000')
    code.code.extend(pe.get_data(0x9ef1,0x98))
    code.emit('dd15'+struct.pack('<I',scratch+32).hex())
    code.code.extend(pe.get_data(0x9f8c,3))
    code.code.extend(pe.get_data(0x9fa3,6))
    code.emit('8b45f8a3'+struct.pack('<I',scratch+40).hex())
    code.code.extend(pe.get_data(0x9fb8,0x21))
    code.code.extend(pe.get_data(0x9feb,3))
    code.emit('8b45f8a3'+struct.pack('<I',scratch+44).hex()+'5d5e5b')
    code.write(scratch+32,16,scratch+12)
    code.emit('ff0d'+struct.pack('<I',scratch+4).hex())
    code.emit('0f85'+struct.pack('<i',loop-(start+len(code.code)+6)).hex())
    driver=code.finish();later=sorted(item['rva'] for item in symbols.values() if item['type']==32 and item['section']==1 and item['rva']>symbols['_MAIN__']['rva'])
    if len(driver)>later[0]-symbols['_MAIN__']['rva']:raise ValueError('Critical-limit driver exceeds PROGRAM body.')
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
        raise RuntimeError(f'Original critical-limit driver failed: exit {process.returncode}, {len(process.stdout)} bytes.')
    expected=process.stdout;(output/'outputs.bin').write_bytes(expected)
    blocks=((0x9ef1,0x98),(0x9f8c,3),(0x9fa3,6),(0x9fb8,0x21),(0x9feb,3))
    manifest=dict(original_sha256=ORIGINAL_SHA256,routines=['_qclim_'],cases=len(cases),
        original_rva=[f'0x{rva:x}..0x{rva+length:x}' for rva,length in blocks],
        instruction_sha256=[hashlib.sha256(pe.get_data(rva,length)).hexdigest() for rva,length in blocks],
        input_record_bytes=28,output_record_bytes=16,
        input_sha256=hashlib.sha256(inputs).hexdigest(),output_sha256=hashlib.sha256(expected).hexdigest(),
        probe_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        fixtures=[dict(name=case['name'],offset=index*16,bytes=16) for index,case in enumerate(cases)])
    if args.native:
        native=subprocess.run([str(args.native.resolve()),'--critical-limit'],input=inputs,capture_output=True,timeout=30)
        (output/'native.bin').write_bytes(native.stdout);(output/'native.stderr.log').write_bytes(native.stderr)
        manifest.update(native_sha256=hashlib.sha256(args.native.read_bytes()).hexdigest(),native_returncode=native.returncode,
            exact_bytes=native.returncode==0 and expected==native.stdout)
    (output/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print(f'{len(cases)} original retained critical-flow limits, REAL flows and reported slopes captured.',flush=True)
    if args.native:raise SystemExit(0 if manifest['exact_bytes'] else 1)

if __name__=='__main__':main()
