#!/usr/bin/env python3
"""Capture the unchanged FEQUTL 5.80 FRFCHN elevation/flow arithmetic and CHNTAB power loop.

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
    rng=random.Random(5801061442);cases=[]
    for scale in (.0001,1.,10000.):
        for trial in range(1024):
            datum=real(rng.uniform(-1000,1000)*scale)
            head=real(rng.uniform(.0001,100)*scale)
            left=real(datum+rng.uniform(-.1,.1)*scale)
            right=real(datum+rng.uniform(-.1,.1)*scale)
            depth=real(head*rng.uniform(.001,.99))
            k=real(rng.uniform(.01,1000)*scale)
            slope=real(rng.uniform(1e-8,.1))
            count=rng.choice((2,3,4,5,7,10,21,51,101,151))
            index=(1 if trial%5==0 else count if trial%5==1 else rng.randrange(1,count+1))
            power=real(rng.choice((.25,.5,1.,1.3333333,1.5,2.,2.5,3.,4.,7.,8.)))
            cases.append(dict(name=f'scale-{scale}-case-{trial}',
                fields=[head,datum,left,right,depth,k,slope,power],count=count,index=index))
    return cases


def image(original,pe,symbols,count):
    base=pe.OPTIONAL_HEADER.ImageBase;start=base+symbols['_MAIN__']['rva']
    scratch=base+symbols['_ftable_']['rva']+4096;record=scratch+128
    imports={item.name.decode():item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    code=Driver(start,imports);code.emit('fc');code.push(-11);code.api('GetStdHandle');code.emit('89c3')
    code.push(-10);code.api('GetStdHandle');code.emit('a3'+struct.pack('<I',scratch).hex())
    code.store(scratch+4,count);code.store(scratch+16,6)
    loop=start+len(code.code)
    code.push(0);code.push(scratch+8);code.push(40);code.push(record)
    code.emit('ff35'+struct.pack('<I',scratch).hex());code.api('ReadFile')
    code.emit('813d'+struct.pack('<II',scratch+8,40).hex());branch=len(code.code);code.emit('0f8400000000')
    code.push(2);code.api('ExitProcess');struct.pack_into('<i',code.code,branch+2,len(code.code)-(branch+6))
    code.emit('5355bd'+struct.pack('<I',scratch+4096).hex())
    code.emit('bb'+struct.pack('<I',record+4).hex()+'b9'+struct.pack('<I',record).hex())
    code.emit('c74514'+struct.pack('<I',record+8).hex())
    code.code.extend(pe.get_data(0x6df8,0x11))
    code.emit('dd1d'+struct.pack('<I',scratch+48).hex())
    code.emit('a1'+struct.pack('<I',0x40ef794).hex()+'a3'+struct.pack('<I',scratch+56).hex())
    code.emit('a1'+struct.pack('<I',record+16).hex()+'a3'+struct.pack('<I',0x553cc8).hex()+'a3'+struct.pack('<I',0x40ef798).hex())
    code.emit('c74518'+struct.pack('<I',record+12).hex())
    for rva,destination in ((0x6f7b,scratch+60),(0x711b,scratch+64)):
        code.emit('c74528'+struct.pack('<I',destination).hex())
        code.emit('dd05'+struct.pack('<I',scratch+48).hex())
        code.code.extend(pe.get_data(rva,0x12))
    code.emit('a1'+struct.pack('<I',record+24).hex()+'a3'+struct.pack('<I',0x40ef790).hex())
    code.emit('bb'+struct.pack('<I',record+20-0x74).hex())
    code.code.extend(pe.get_data(0x6e67,0x17))
    code.emit('a1'+struct.pack('<I',0x40ef788).hex()+'a3'+struct.pack('<I',scratch+68).hex())
    code.emit('a1'+struct.pack('<I',record+32).hex()+'a3'+struct.pack('<I',0x554abc).hex())
    code.emit('a1'+struct.pack('<I',record+28).hex()+'a3'+struct.pack('<I',0x554b00).hex())
    # The complete CHNTAB power loop starts with the retained zero numerator.
    code.emit('d9ee');code.call(base+0x7f6c)
    code.emit('a1'+struct.pack('<I',record+36).hex())
    code.emit('8b048594236000a3'+struct.pack('<I',scratch+72).hex())
    code.emit('5d5b')
    code.write(scratch+48,28,scratch+12)
    code.emit('ff0d'+struct.pack('<I',scratch+4).hex())
    code.emit('0f85'+struct.pack('<i',loop-(start+len(code.code)+6)).hex())
    driver=code.finish();later=sorted(item['rva'] for item in symbols.values() if item['type']==32 and item['section']==1 and item['rva']>symbols['_MAIN__']['rva'])
    if len(driver)>later[0]-symbols['_MAIN__']['rva']:raise ValueError('Channel-rating driver exceeds PROGRAM body.')
    result=bytearray(original);offset=pe.get_offset_from_rva(symbols['_MAIN__']['rva']);result[offset:offset+len(driver)]=driver
    result[pe.get_offset_from_rva(0x8062)]=0xc3
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
    inputs=b''.join(struct.pack('<8f2i',*case['fields'],case['count'],case['index']) for case in cases)
    (output/'inputs.bin').write_bytes(inputs);(output/'fixtures.json').write_text(json.dumps(cases,indent=2)+'\n')
    exe=output/'PROBE.EXE';exe.write_bytes(image(original,pe,symbols,len(cases)))
    env=os.environ.copy();env.update(WINEPREFIX=str(args.wine_prefix.resolve()),WINEDEBUG='-all',WINEDLLOVERRIDES='mscoree,mshtml=',MVK_CONFIG_LOG_LEVEL='0')
    command=[str(exe)] if os.name=='nt' else ['wine',str(exe)]
    with (output/'inputs.bin').open('rb') as stream:
        process=subprocess.run(command,cwd=output,env=env,stdin=stream,capture_output=True,timeout=60)
    if process.returncode or len(process.stdout)!=28*len(cases):
        (output/'error.log').write_bytes(process.stdout+process.stderr)
        raise RuntimeError(f'Original channel-rating driver failed: exit {process.returncode}, {len(process.stdout)} bytes.')
    expected=process.stdout;(output/'outputs.bin').write_bytes(expected)
    manifest=dict(original_sha256=ORIGINAL_SHA256,routines=['_frfchn_','_chntab_','_g_arxr'],cases=len(cases),
        original_rva=['0x6df8..0x6e09','0x6f7b..0x6f8d','0x711b..0x712d','0x6e67..0x6e7e','0x7f6c..0x8062'],
        instruction_sha256=[hashlib.sha256(pe.get_data(rva,length)).hexdigest() for rva,length in ((0x6df8,0x11),(0x6f7b,0x12),(0x711b,0x12),(0x6e67,0x17),(0x7f6c,0xf6))],
        input_record_bytes=40,output_record_bytes=28,
        input_sha256=hashlib.sha256(inputs).hexdigest(),output_sha256=hashlib.sha256(expected).hexdigest(),
        probe_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        fixtures=[dict(name=case['name'],offset=index*28,bytes=28) for index,case in enumerate(cases)])
    if args.native:
        native=subprocess.run([str(args.native.resolve()),'--channel-rating'],input=inputs,capture_output=True,timeout=30)
        (output/'native.bin').write_bytes(native.stdout);(output/'native.stderr.log').write_bytes(native.stderr)
        manifest.update(native_sha256=hashlib.sha256(args.native.read_bytes()).hexdigest(),native_returncode=native.returncode,
            exact_bytes=native.returncode==0 and expected==native.stdout)
    (output/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print(f'{len(cases)} original channel-rating elevation, normal-flow and power cases captured.',flush=True)
    if args.native:raise SystemExit(0 if manifest['exact_bytes'] else 1)

if __name__=='__main__':main()
