#!/usr/bin/env python3
"""Capture the unchanged FEQUTL 5.80 EXPCON power loop and EMBANK downstream-head arithmetic.

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
    rng=random.Random(5801061246);cases=[]
    for scale in (.0001,1.,10000.):
        for trial in range(1024):
            head=real(rng.uniform(.01,100)*scale);drop=real(head*rng.uniform(.001,1.))
            count=rng.choice((2,3,4,5,7,10,21,51,101,151,350))
            index=(1 if trial%5==0 else count if trial%5==1 else rng.randrange(1,count+1))
            power=real(rng.choice((.25,.5,1.,1.3333333,1.5,2.,2.5,3.,4.,7.,8.)))
            if trial%32==0:head=drop=real(.1*scale);power=2.;count=21;index=18
            elif trial%32==1:head=drop=real(.1*scale);power=2.;count=21;index=12
            cases.append(dict(name=f'scale-{scale}-case-{trial}',
                fields=[head,drop,power],count=count,index=index))
    return cases


def image(original,pe,symbols,count):
    base=pe.OPTIONAL_HEADER.ImageBase;start=base+symbols['_MAIN__']['rva']
    scratch=base+symbols['_ftable_']['rva']+4096;record=scratch+128
    imports={item.name.decode():item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    code=Driver(start,imports);code.emit('fc');code.push(-11);code.api('GetStdHandle');code.emit('89c3')
    code.push(-10);code.api('GetStdHandle');code.emit('a3'+struct.pack('<I',scratch).hex())
    code.store(scratch+4,count);code.store(scratch+16,6)
    loop=start+len(code.code)
    code.push(0);code.push(scratch+8);code.push(20);code.push(record)
    code.emit('ff35'+struct.pack('<I',scratch).hex());code.api('ReadFile')
    code.emit('813d'+struct.pack('<II',scratch+8,20).hex());branch=len(code.code);code.emit('0f8400000000')
    code.push(2);code.api('ExitProcess');struct.pack_into('<i',code.code,branch+2,len(code.code)-(branch+6))
    code.emit('5355bd'+struct.pack('<I',scratch+4096).hex())
    code.emit('a1'+struct.pack('<I',record+8).hex()+'a3'+struct.pack('<I',0x570eb0).hex())
    code.emit('8b1d'+struct.pack('<I',record+12).hex()+'891d'+struct.pack('<I',0x570e74).hex())
    code.call(base+0x368f9)
    code.emit('a1'+struct.pack('<I',record+16).hex())
    code.emit('8b048508f57400a3'+struct.pack('<I',scratch+32).hex())
    code.emit('a1'+struct.pack('<I',record).hex()+'a3'+struct.pack('<I',0x56e624).hex())
    code.emit('d905'+struct.pack('<I',record+4).hex()+'d905'+struct.pack('<I',scratch+32).hex())
    code.code.extend(pe.get_data(0x32734,8))
    code.code.extend(pe.get_data(0x32762,12))
    code.code.extend(pe.get_data(0x32786,9))
    code.code.extend(pe.get_data(0x32795,3))
    code.emit('8b45f0a3'+struct.pack('<I',scratch+36).hex())
    code.emit('8b45eca3'+struct.pack('<I',scratch+40).hex())
    code.emit('5d5b')
    code.write(scratch+32,12,scratch+12)
    code.emit('ff0d'+struct.pack('<I',scratch+4).hex())
    code.emit('0f85'+struct.pack('<i',loop-(start+len(code.code)+6)).hex())
    driver=code.finish();later=sorted(item['rva'] for item in symbols.values() if item['type']==32 and item['section']==1 and item['rva']>symbols['_MAIN__']['rva'])
    if len(driver)>later[0]-symbols['_MAIN__']['rva']:raise ValueError('Transition-spacing driver exceeds PROGRAM body.')
    result=bytearray(original);offset=pe.get_offset_from_rva(symbols['_MAIN__']['rva']);result[offset:offset+len(driver)]=driver
    result[pe.get_offset_from_rva(0x36a07)]=0xc3
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
    inputs=b''.join(struct.pack('<3f2i',*case['fields'],case['count'],case['index']) for case in cases)
    (output/'inputs.bin').write_bytes(inputs);(output/'fixtures.json').write_text(json.dumps(cases,indent=2)+'\n')
    exe=output/'PROBE.EXE';exe.write_bytes(image(original,pe,symbols,len(cases)))
    env=os.environ.copy();env.update(WINEPREFIX=str(args.wine_prefix.resolve()),WINEDEBUG='-all',WINEDLLOVERRIDES='mscoree,mshtml=',MVK_CONFIG_LOG_LEVEL='0')
    command=[str(exe)] if os.name=='nt' else ['wine',str(exe)]
    with (output/'inputs.bin').open('rb') as stream:
        process=subprocess.run(command,cwd=output,env=env,stdin=stream,capture_output=True,timeout=60)
    if process.returncode or len(process.stdout)!=12*len(cases):
        (output/'error.log').write_bytes(process.stdout+process.stderr)
        raise RuntimeError(f'Original transition-spacing driver failed: exit {process.returncode}, {len(process.stdout)} bytes.')
    expected=process.stdout;(output/'outputs.bin').write_bytes(expected)
    manifest=dict(original_sha256=ORIGINAL_SHA256,routines=['_expcon_','_embank_','_g_arxr'],cases=len(cases),
        original_rva=['0x368f9..0x36a07','0x32734..0x3273c','0x32762..0x3276e','0x32786..0x3278f','0x32795..0x32798'],
        instruction_sha256=[hashlib.sha256(pe.get_data(rva,length)).hexdigest() for rva,length in ((0x368f9,0x10e),(0x32734,8),(0x32762,12),(0x32786,9),(0x32795,3))],
        input_record_bytes=20,output_record_bytes=12,
        input_sha256=hashlib.sha256(inputs).hexdigest(),output_sha256=hashlib.sha256(expected).hexdigest(),
        probe_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        fixtures=[dict(name=case['name'],offset=index*12,bytes=12) for index,case in enumerate(cases)])
    if args.native:
        native=subprocess.run([str(args.native.resolve()),'--transition-spacing'],input=inputs,capture_output=True,timeout=30)
        (output/'native.bin').write_bytes(native.stdout);(output/'native.stderr.log').write_bytes(native.stderr)
        manifest.update(native_sha256=hashlib.sha256(args.native.read_bytes()).hexdigest(),native_returncode=native.returncode,
            exact_bytes=native.returncode==0 and expected==native.stdout)
    (output/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print(f'{len(cases)} original partial flows and weir report heads captured.',flush=True)
    if args.native:raise SystemExit(0 if manifest['exact_bytes'] else 1)

if __name__=='__main__':main()
