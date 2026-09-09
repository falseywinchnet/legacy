#!/usr/bin/env python3
"""Capture UFGATE's unchanged critical setup and free-weir iteration blocks.

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

BLOCKS=((0x80b47,0x80bbd),(0x816af,0x81762))


def fixtures():
    rng=random.Random(580106149);cases=[]
    for scale in (.0001,1.,10000.):
        for index in range(256):
            opening=real(rng.uniform(.001,10)*scale)
            width=real(rng.uniform(.01,100)*scale)
            gravity=real((9.80665,32.174,32.2)[index%3]);twog=real(2*gravity)
            coefficient=real(rng.uniform(.4,1.2));datum=real(rng.uniform(-1000,1000)*scale)
            updatum=real(datum+rng.uniform(-.01,.01)*scale)
            head=rng.uniform(.001,20)*scale
            alpha=real(rng.uniform(1,3))
            area=real(head*width*rng.uniform(4,100))
            fields=list(map(real,(opening,width,gravity,twog,coefficient,datum,updatum,
                coefficient,alpha,width,area,gravity,(.00001,.000001,1e-9)[index%3])))
            cases.append(dict(name=f'random-scale-{scale}-{index}',head=head,fields=fields))
    for datum in (-1048576.,-1000.,0.,450.,1000.,1048576.):
        for head in (0.,.00001,.1,1.,2.7975,3.,10.):
            for coefficient in (.5,.61,1.):
                # These cases combine cancellation above a datum with tiny
                # differences between a retained head and its REAL value.
                retained=head+(head*2**-27)
                fields=list(map(real,(max(.00001,head),2.7,32.2,64.4,coefficient,datum,datum,
                    coefficient,1.3,2.7,max(1.,head)*27.,32.2,1e-7)))
                cases.append(dict(name=f'datum-{datum}-head-{head}-cd-{coefficient}',head=retained,fields=fields))
    return cases


def image(original,pe,symbols,count):
    base=pe.OPTIONAL_HEADER.ImageBase;start=base+symbols['_MAIN__']['rva']
    scratch=base+symbols['_ftable_']['rva']+4096;record=scratch+128;frame=scratch+2048
    common=base+symbols['_ufcom_']['rva']
    imports={item.name.decode():item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    code=Driver(start,imports);code.emit('fc');code.push(-11);code.api('GetStdHandle');code.emit('89c3')
    code.push(-10);code.api('GetStdHandle');code.emit('a3'+struct.pack('<I',scratch).hex());code.store(scratch+4,count)
    loop=start+len(code.code)
    code.push(0);code.push(scratch+8);code.push(60);code.push(record)
    code.emit('ff35'+struct.pack('<I',scratch).hex());code.api('ReadFile')
    code.emit('813d'+struct.pack('<II',scratch+8,60).hex());branch=len(code.code);code.emit('0f8400000000')
    code.push(2);code.api('ExitProcess');struct.pack_into('<i',code.code,branch+2,len(code.code)-(branch+6))
    for index,destination in enumerate((common+116,common+124,common+136,common+140,common+128,common+52,common+48)):
        code.emit('a1'+struct.pack('<I',record+8+index*4).hex()+'a3'+struct.pack('<I',destination).hex())
    code.emit('55bd'+struct.pack('<I',frame).hex())
    code.code.extend(pe.get_data(BLOCKS[0][0],BLOCKS[0][1]-BLOCKS[0][0]))
    for index,source in enumerate((common+120,common+12,0x5aa4e4,0x5aa4f8,0x5aa500)):
        code.emit('a1'+struct.pack('<I',source).hex()+'a3'+struct.pack('<I',scratch+32+index*4).hex())
    code.emit('dd05'+struct.pack('<I',record).hex()+'dbbd44ffffff')
    for index,destination in enumerate((common+128,common+108,common+124,common+28,common+136,0x40ef76c)):
        code.emit('a1'+struct.pack('<I',record+36+index*4).hex()+'a3'+struct.pack('<I',destination).hex())
    code.code.extend(pe.get_data(BLOCKS[1][0],BLOCKS[1][1]-BLOCKS[1][0]))
    for index,source in enumerate((common+12,0x5aa4ec)):
        code.emit('a1'+struct.pack('<I',source).hex()+'a3'+struct.pack('<I',scratch+52+index*4).hex())
    code.emit('5d');code.write(scratch+32,28,scratch+12)
    code.emit('ff0d'+struct.pack('<I',scratch+4).hex())
    code.emit('0f85'+struct.pack('<i',loop-(start+len(code.code)+6)).hex())
    driver=code.finish();later=sorted(item['rva'] for item in symbols.values() if item['type']==32 and item['section']==1 and item['rva']>symbols['_MAIN__']['rva'])
    if len(driver)>later[0]-symbols['_MAIN__']['rva']:raise ValueError('Gate free-flow driver exceeds PROGRAM body.')
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
    inputs=b''.join(struct.pack('<d13f',case['head'],*case['fields']) for case in cases)
    (output/'inputs.bin').write_bytes(inputs);(output/'fixtures.json').write_text(json.dumps(cases,indent=2)+'\n')
    exe=output/'PROBE.EXE';exe.write_bytes(image(original,pe,symbols,len(cases)))
    env=os.environ.copy();env.update(WINEPREFIX=str(args.wine_prefix.resolve()),WINEDEBUG='-all',WINEDLLOVERRIDES='mscoree,mshtml=',MVK_CONFIG_LOG_LEVEL='0')
    command=[str(exe)] if os.name=='nt' else ['wine',str(exe)]
    with (output/'inputs.bin').open('rb') as stream:
        process=subprocess.run(command,cwd=output,env=env,stdin=stream,capture_output=True,timeout=60)
    if process.returncode or len(process.stdout)!=28*len(cases):
        (output/'error.log').write_bytes(process.stdout+process.stderr)
        raise RuntimeError(f'Original gate free-flow driver failed: exit {process.returncode}, {len(process.stdout)} bytes.')
    expected=process.stdout;(output/'outputs.bin').write_bytes(expected)
    manifest=dict(original_sha256=ORIGINAL_SHA256,routine='_ufgate_',cases=len(cases),
        instruction_blocks=[dict(rva=f'0x{start:x}..0x{end:x}',sha256=hashlib.sha256(pe.get_data(start,end-start)).hexdigest()) for start,end in BLOCKS],
        input_record_bytes=60,output_record_bytes=28,
        input_sha256=hashlib.sha256(inputs).hexdigest(),output_sha256=hashlib.sha256(expected).hexdigest(),
        probe_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        fixtures=[dict(name=case['name'],offset=index*28,bytes=28) for index,case in enumerate(cases)])
    if args.native:
        native=subprocess.run([str(args.native.resolve()),'--gate-free'],input=inputs,capture_output=True,timeout=30)
        (output/'native.bin').write_bytes(native.stdout);(output/'native.stderr.log').write_bytes(native.stderr)
        manifest.update(native_sha256=hashlib.sha256(args.native.read_bytes()).hexdigest(),native_returncode=native.returncode,
            exact_bytes=native.returncode==0 and expected==native.stdout)
    (output/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print(f'{len(cases)} original gate critical and free-weir calculations captured.',flush=True)
    if args.native:raise SystemExit(0 if manifest['exact_bytes'] else 1)

if __name__=='__main__':main()
