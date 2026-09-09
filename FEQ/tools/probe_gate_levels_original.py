#!/usr/bin/env python3
"""Capture UFGATE's unchanged tailwater elevation and head-drop instructions.

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

START_RVA=0x819a9
END_RVA=0x819d3
SUBMERGED_START_RVA=0x81b76
SUBMERGED_END_RVA=0x81bab


def fixtures():
    rng=random.Random(580106148);cases=[]
    for datum in (-1048576.,-1000.,0.,450.,1000.,1048576.):
        for depth in (.0001,.03125,.25,.5,1.,3.,100.):
            for fraction in (0.,.000001,.001,.03,.2,.9,1.):
                fields=list(map(real,(depth,datum,depth*(1.-fraction),datum,datum)))
                cases.append(dict(name=f'datum-{datum}-depth-{depth}-drop-fraction-{fraction}',fields=fields))
    for scale in (.0001,1.,10000.):
        for index in range(128):
            datum=real(rng.uniform(-1000,1000)*scale)
            fields=list(map(real,(rng.uniform(.001,100)*scale,datum,
                rng.uniform(.001,100)*scale,datum+rng.uniform(-1,1)*scale,datum+rng.uniform(-1,1)*scale)))
            cases.append(dict(name=f'random-scale-{scale}-{index}',fields=fields))
    for index,case in enumerate(cases):
        case['fields'].append(real((0.,.005,.010772,.023208,.05,.5,.99,1.)[index%8]))
    return cases


def image(original,pe,symbols,count):
    base=pe.OPTIONAL_HEADER.ImageBase;start=base+symbols['_MAIN__']['rva']
    scratch=base+symbols['_ftable_']['rva']+4096;record_address=scratch+128;frame=scratch+2048
    common=base+symbols['_ufcom_']['rva']
    imports={item.name.decode():item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    code=Driver(start,imports);code.emit('fc');code.push(-11);code.api('GetStdHandle');code.emit('89c3')
    code.push(-10);code.api('GetStdHandle');code.emit('a3'+struct.pack('<I',scratch).hex());code.store(scratch+4,count)
    loop=start+len(code.code)
    code.push(0);code.push(scratch+8);code.push(24);code.push(record_address)
    code.emit('ff35'+struct.pack('<I',scratch).hex());code.api('ReadFile')
    code.emit('813d'+struct.pack('<II',scratch+8,24).hex());branch=len(code.code);code.emit('0f8400000000')
    code.push(2);code.api('ExitProcess');struct.pack_into('<i',code.code,branch+2,len(code.code)-(branch+6))
    for index,destination in enumerate((common+8,common+48,0x5aa508,common+60,0x5aa4b0)):
        code.emit('a1'+struct.pack('<I',record_address+index*4).hex()+'a3'+struct.pack('<I',destination).hex())
    code.emit('55bd'+struct.pack('<I',frame).hex())
    code.code.extend(pe.get_data(START_RVA,END_RVA-START_RVA))
    code.emit('dd1d'+struct.pack('<I',scratch+32).hex())
    code.emit('dbade4feffffdd1d'+struct.pack('<I',scratch+40).hex())
    code.emit('a1'+struct.pack('<I',record_address+20).hex()+'a3'+struct.pack('<I',0x94f8e4).hex())
    code.emit('53bb01000000')
    code.code.extend(pe.get_data(SUBMERGED_START_RVA,SUBMERGED_END_RVA-SUBMERGED_START_RVA))
    code.emit('dd1d'+struct.pack('<I',scratch+52).hex())
    code.emit('db6dc8dd1d'+struct.pack('<I',scratch+60).hex())
    code.emit('a1'+struct.pack('<I',common+20).hex()+'a3'+struct.pack('<I',scratch+48).hex()+'5b5d')
    code.write(scratch+32,36,scratch+12)
    code.emit('ff0d'+struct.pack('<I',scratch+4).hex())
    code.emit('0f85'+struct.pack('<i',loop-(start+len(code.code)+6)).hex())
    driver=code.finish();later=sorted(item['rva'] for item in symbols.values() if item['type']==32 and item['section']==1 and item['rva']>symbols['_MAIN__']['rva'])
    if len(driver)>later[0]-symbols['_MAIN__']['rva']:raise ValueError('Gate levels driver exceeds PROGRAM body.')
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
    inputs=b''.join(struct.pack('<6f',*case['fields']) for case in cases)
    (output/'inputs.bin').write_bytes(inputs);(output/'fixtures.json').write_text(json.dumps(cases,indent=2)+'\n')
    exe=output/'PROBE.EXE';exe.write_bytes(image(original,pe,symbols,len(cases)))
    env=os.environ.copy();env.update(WINEPREFIX=str(args.wine_prefix.resolve()),WINEDEBUG='-all',WINEDLLOVERRIDES='mscoree,mshtml=',MVK_CONFIG_LOG_LEVEL='0')
    command=[str(exe)] if os.name=='nt' else ['wine',str(exe)]
    process=subprocess.run(command,cwd=output,env=env,input=inputs,capture_output=True,timeout=60)
    if process.returncode or len(process.stdout)!=36*len(cases):
        (output/'error.log').write_bytes(process.stdout+process.stderr)
        raise RuntimeError(f'Original gate levels driver failed: exit {process.returncode}, {len(process.stdout)} bytes.')
    expected=process.stdout;(output/'outputs.bin').write_bytes(expected)
    manifest=dict(original_sha256=ORIGINAL_SHA256,routine='_ufgate_',cases=len(cases),
        instruction_rva=f'0x{START_RVA:x}..0x{END_RVA:x}',
        instruction_sha256=hashlib.sha256(pe.get_data(START_RVA,END_RVA-START_RVA)).hexdigest(),
        submerged_instruction_rva=f'0x{SUBMERGED_START_RVA:x}..0x{SUBMERGED_END_RVA:x}',
        submerged_instruction_sha256=hashlib.sha256(pe.get_data(SUBMERGED_START_RVA,SUBMERGED_END_RVA-SUBMERGED_START_RVA)).hexdigest(),
        input_record_bytes=24,output_record_bytes=36,
        input_sha256=hashlib.sha256(inputs).hexdigest(),output_sha256=hashlib.sha256(expected).hexdigest(),
        probe_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        fixtures=[dict(name=case['name'],offset=index*36,bytes=36) for index,case in enumerate(cases)])
    if args.native:
        native=subprocess.run([str(args.native.resolve()),'--gate-levels'],input=inputs,capture_output=True,timeout=30)
        (output/'native.bin').write_bytes(native.stdout);(output/'native.stderr.log').write_bytes(native.stderr)
        manifest.update(native_sha256=hashlib.sha256(args.native.read_bytes()).hexdigest(),native_returncode=native.returncode,
            exact_bytes=native.returncode==0 and expected==native.stdout)
    (output/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print(f'{len(cases)} original gate head and drop calculations captured.',flush=True)
    if args.native:raise SystemExit(0 if manifest['exact_bytes'] else 1)

if __name__=='__main__':main()
