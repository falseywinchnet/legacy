#!/usr/bin/env python3
"""Capture original RITTER wave steps, complete XLOOKW calls or FRIT residuals.

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

SIZES={'wave':(32,16),'section':(48,20),'residual':(20,12)}


def fixtures(mode):
    rng=random.Random(5801061238+list(SIZES).index(mode));cases=[]
    for scale in (.0001,1.,10000.):
        for index in range(1024):
            case=dict(name=f'{mode}-scale-{scale}-case-{index}')
            if mode=='wave':
                gravity=real((9.80665,32.174,32.2)[index%3])
                depth=real(rng.uniform(.01,100)*scale);previous=real(depth*rng.uniform(0,1))
                area=real(rng.uniform(.01,100)*scale**2);width=real(rng.uniform(.01,100)*scale)
                cold=real(rng.uniform(.01,100)*scale**.5) if index%9 else 0.
                case['fields']=[gravity,depth,previous,area,width,cold]
                case['previous_escoffier']=rng.uniform(0,1000)*scale**.5 if index%9 else 0.
            elif mode=='section':
                low=real(rng.uniform(.01,10)*scale) if index%4 else 0.
                high=real(low+rng.uniform(.01,10)*scale)
                fraction=(0.,.000001,.01,.25,.5,.9,.999999,1.)[index%8]
                depth=real(low+fraction*(high-low));gravity=real((9.80665,32.174,32.2)[index%3])
                width=real(rng.uniform(.01,100)*scale);area=real(rng.uniform(.01,100)*scale**2)
                cold=real(rng.uniform(.01,100)*scale**.5);wold=real(rng.uniform(0,1000)*scale**.5)
                if low==0.:area=0.;cold=0.;wold=0.
                width2=real(width*rng.uniform(.1,3))
                area2=real(area+.5*(high-low)*(width+width2))
                case['fields']=[depth,gravity,low,width,area,cold,wold,high,width2,area2,0.,0.]
            else:
                first=real(rng.uniform(.1,100)*scale**.5)
                velocity=real(rng.uniform(-.05,10)*scale**.5)
                current=real(rng.uniform(.01,100)*scale**.5)
                area=real(rng.uniform(.01,100)*scale**2)
                if index%8==0:area=0.
                elif index%8==1:area=-area
                flow=real(rng.uniform(-100,100)*scale**2.5)
                if index%3==0:flow=real(((first+velocity)-current)*(area if area>0 else 1.))
                case['fields']=[first,velocity,current,flow,area]
            cases.append(case)
    return cases


def image(original,pe,symbols,count,mode):
    base=pe.OPTIONAL_HEADER.ImageBase;start=base+symbols['_MAIN__']['rva']
    table=base+symbols['_ftable_']['rva'];scratch=table+4096;record=scratch+128
    imports={item.name.decode():item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    code=Driver(start,imports);code.emit('fc');code.push(-11);code.api('GetStdHandle');code.emit('89c3')
    code.push(-10);code.api('GetStdHandle');code.emit('a3'+struct.pack('<I',scratch).hex())
    code.store(scratch+4,count);code.store(scratch+16,1);code.store(scratch+20,5)
    input_size,output_size=SIZES[mode];blocks=[]
    loop=start+len(code.code)
    code.push(0);code.push(scratch+8);code.push(input_size);code.push(record)
    code.emit('ff35'+struct.pack('<I',scratch).hex());code.api('ReadFile')
    code.emit('813d'+struct.pack('<II',scratch+8,input_size).hex());branch=len(code.code);code.emit('0f8400000000')
    code.push(2);code.api('ExitProcess');struct.pack_into('<i',code.code,branch+2,len(code.code)-(branch+6))
    def copy_word(index,destination):
        code.emit('a1'+struct.pack('<I',record+index*4).hex()+'a3'+struct.pack('<I',destination).hex())
    if mode=='wave':
        for index,destination in ((1,table+32*4),(4,table+33*4),(3,table+34*4)):copy_word(index,destination)
        code.emit('5355bd'+struct.pack('<I',scratch+1024).hex()+'bb20000000')
        # Original loop-entry stack, top first: 2g, g, Yold, Wold, Cold.
        code.emit('d905'+struct.pack('<I',record+20).hex())
        code.emit('dd05'+struct.pack('<I',record+24).hex())
        for offset in (8,0,0):code.emit('d905'+struct.pack('<I',record+offset).hex())
        code.emit('d805'+struct.pack('<I',record).hex())
        blocks=[(0x71b7a,0x56)];code.code.extend(pe.get_data(*blocks[0]))
        code.emit('db6db4d91d'+struct.pack('<I',scratch+32).hex())
        code.emit('db6da8dd1d'+struct.pack('<I',scratch+36).hex())
        code.emit('db6da8d91d'+struct.pack('<I',scratch+44).hex())
        code.emit('ddd8ddd85d5b')
    elif mode=='section':
        code.store(table+4,38);code.store(table+16,33)
        for index in range(10):copy_word(index+2,table+(33+index)*4)
        copy_word(1,0xf4bc30)
        arguments=[scratch+16,scratch+20,record]+[scratch+32+index*4 for index in range(5)]
        for address in reversed(arguments):code.push(address)
        code.call(base+symbols['_xlookw_']['rva']);code.emit('83c420')
        blocks=[(symbols['_xlookw_']['rva'],0x2c9)]
    else:
        for index,destination in enumerate((0xb64d40,0xb64d44,0xb64d48,0xb64d50,0xb64d4c)):copy_word(index,destination)
        blocks=[(0x716ba,0x45)];code.code.extend(pe.get_data(*blocks[0]))
        code.emit('dd1d'+struct.pack('<I',scratch+32).hex())
        code.emit('a1'+struct.pack('<I',0xb64d4c).hex()+'a3'+struct.pack('<I',scratch+40).hex())
    code.write(scratch+32,output_size,scratch+12)
    code.emit('ff0d'+struct.pack('<I',scratch+4).hex())
    code.emit('0f85'+struct.pack('<i',loop-(start+len(code.code)+6)).hex())
    driver=code.finish();later=sorted(item['rva'] for item in symbols.values() if item['type']==32 and item['section']==1 and item['rva']>symbols['_MAIN__']['rva'])
    if len(driver)>later[0]-symbols['_MAIN__']['rva']:raise ValueError('Ritter driver exceeds PROGRAM body.')
    result=bytearray(original);offset=pe.get_offset_from_rva(symbols['_MAIN__']['rva']);result[offset:offset+len(driver)]=driver
    return bytes(result),blocks


def main():
    import pefile
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--output',type=Path,required=True)
    parser.add_argument('--mode',choices=SIZES,required=True);parser.add_argument('--native',type=Path);parser.add_argument('--fixtures',type=Path)
    parser.add_argument('--wine-prefix',type=Path,default=ROOT/'build/wineprefix')
    args=parser.parse_args();output=args.output.resolve()
    if output.exists() or ROOT/'build' not in output.parents:parser.error('Use a new FEQ/build/ directory.')
    output.mkdir(parents=True)
    original=(ROOT/'originals/feq1061/wrdapp/FEQ_10.61/BIN/fequtl.exe').read_bytes()
    if hashlib.sha256(original).hexdigest()!=ORIGINAL_SHA256:raise ValueError('Recovered executable hash changed.')
    pe=pefile.PE(data=original);symbols={item['name']:item for item in coff_symbols(original)}
    cases=json.loads(args.fixtures.read_text()) if args.fixtures else fixtures(args.mode)
    inputs=b''.join(struct.pack('<6fd',*case['fields'],case['previous_escoffier']) if args.mode=='wave' else
        struct.pack('<'+str(len(case['fields']))+'f',*case['fields']) for case in cases)
    (output/'inputs.bin').write_bytes(inputs);(output/'fixtures.json').write_text(json.dumps(cases,indent=2)+'\n')
    exe=output/'PROBE.EXE';payload,blocks=image(original,pe,symbols,len(cases),args.mode);exe.write_bytes(payload)
    env=os.environ.copy();env.update(WINEPREFIX=str(args.wine_prefix.resolve()),WINEDEBUG='-all',WINEDLLOVERRIDES='mscoree,mshtml=',MVK_CONFIG_LOG_LEVEL='0')
    command=[str(exe)] if os.name=='nt' else ['wine',str(exe)]
    with (output/'inputs.bin').open('rb') as stream:
        process=subprocess.run(command,cwd=output,env=env,stdin=stream,capture_output=True,timeout=60)
    input_size,output_size=SIZES[args.mode]
    if process.returncode or len(process.stdout)!=output_size*len(cases):
        (output/'error.log').write_bytes(process.stdout+process.stderr)
        raise RuntimeError(f'Original Ritter driver failed: exit {process.returncode}, {len(process.stdout)} bytes.')
    expected=process.stdout;(output/'outputs.bin').write_bytes(expected)
    manifest=dict(original_sha256=ORIGINAL_SHA256,mode=args.mode,cases=len(cases),
        routines=[{'wave':'_ritter_','section':'_xlookw_','residual':'_frit_'}[args.mode]],
        original_rva=[f'0x{rva:x}..0x{rva+length:x}' for rva,length in blocks],
        instruction_sha256=[hashlib.sha256(pe.get_data(rva,length)).hexdigest() for rva,length in blocks],
        input_record_bytes=input_size,output_record_bytes=output_size,
        input_sha256=hashlib.sha256(inputs).hexdigest(),output_sha256=hashlib.sha256(expected).hexdigest(),
        probe_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        fixtures=[dict(name=case['name'],offset=index*output_size,bytes=output_size) for index,case in enumerate(cases)])
    if args.native:
        native=subprocess.run([str(args.native.resolve()),'--ritter-'+args.mode],input=inputs,capture_output=True,timeout=30)
        (output/'native.bin').write_bytes(native.stdout);(output/'native.stderr.log').write_bytes(native.stderr)
        manifest.update(native_sha256=hashlib.sha256(args.native.read_bytes()).hexdigest(),native_returncode=native.returncode,
            exact_bytes=native.returncode==0 and expected==native.stdout)
    (output/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print(f'{len(cases)} original Ritter {args.mode} cases captured.',flush=True)
    if args.native:raise SystemExit(0 if manifest['exact_bytes'] else 1)

if __name__=='__main__':main()
