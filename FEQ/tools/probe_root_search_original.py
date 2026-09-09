#!/usr/bin/env python3
"""Capture unchanged REGFAL/FDROOT arithmetic and callback-visible state.

Only PROGRAM and a controlled callback are replaced in a temporary executable.
The original root routines and runtime startup execute unchanged under Wine.
Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
"""
import argparse
import hashlib
import json
import math
import os
from pathlib import Path
import random
import struct
import subprocess
from inspect_binary import coff_symbols
from probe_profile_original import Driver, ROOT, real
from probe_geometry_original import ORIGINAL_SHA256
from probe_root_original import fixtures as root_fixtures

INPUT_BYTES=1592
OUTPUT_BYTES=3092


def fixtures():
    cases=[];rng=random.Random(580106149)
    def add(name,a=1.,b=9.,fl=-2.,fr=4.,epsx=0.,epsf=0.,sequence=None,
            coefficients=None,mutations=None,mutate=None,flag=73):
        cases.append(dict(name=name,kind=int(coefficients is not None),
            mutate=int(mutations is not None) if mutate is None else mutate,
            values=list(map(real,(epsx,epsf,a,b,73.25))),flag=flag,
            coefficients=coefficients or [0.,0.,0.],
            sequence=[fl,fr]+(sequence if sequence is not None else [0.]),
            mutations=mutations or [0.]))
    for case in root_fixtures():
        epsx,epsf,a,b,fl,fr,xm=case['values']
        add('adapted-'+case['name'],a,b,fl,fr,epsx,epsf,case['sequence'],
            case['coefficients'] if case['kind'] else None,
            [a,b]+case['mutations'] if case['mutate'] else None)
    for value in (.125,math.nextafter(.125,0.),math.nextafter(.125,1.)):
        add(f'wide-left-endpoint-{value!r}',fl=-value,epsf=.125)
        add(f'wide-right-endpoint-{value!r}',fr=value,epsf=.125)
    for flag in (-32768,-1,0,1,32767):
        add(f'preserve-initial-status-{flag}',flag=flag)
        add(f'preserve-small-left-status-{flag}',fl=.0625,fr=2.,epsf=.125,flag=flag)
        add(f'preserve-small-right-status-{flag}',fl=2.,fr=.0625,epsf=.125,flag=flag)
    for a,b in ((1.,2.),(1.,9.),(-1.,9.),(-9.,-1.),(-1.,1.),(0.,0.),(9.,1.)):
        add(f'fdroot-search-failure-{a}-{b}',a,b,fl=1.,fr=2.,sequence=[1.]*24)
        for trial in range(24):
            add(f'fdroot-change-at-callback-{trial}-{a}-{b}',a,b,fl=1.,fr=2.,
                sequence=[1.]*trial+[-1.])
    for mutate in (1,2,3):
        for index in range(24):
            changes=[real(rng.uniform(.25,20.)) for i in range(128)]
            sequence=[rng.uniform(-10.,10.) for i in range(index)]+[0.]
            add(f'callback-state-regfal-mode-{mutate}-{index}',mutations=changes,
                mutate=mutate,sequence=sequence)
            add(f'callback-state-fdroot-mode-{mutate}-{index}',fl=1.,fr=2.,mutations=changes,
                mutate=mutate,sequence=[1.]*index+[-1.])
    for scale in (.00001,1.,10000.):
        for index in range(40):
            a=real(rng.uniform(.01,10.)*scale);b=real(rng.uniform(11.,20.)*scale)
            fl=rng.uniform(-100.,-1.);fr=rng.uniform(1.,100.)
            sequence=[rng.uniform(-100.,100.) for i in range(12)]+[0.]
            add(f'wide-endpoints-scale-{scale}-{index}',a,b,fl,fr,sequence=sequence)
    return cases


def padded(values):
    return (values+[values[-1]]*128)[:128]


def record(case):
    return struct.pack('<II5fi3d128d128f',case['kind'],case['mutate'],*case['values'],
        case['flag'],*case['coefficients'],*padded(case['sequence']),*padded(case['mutations']))


def image(original,pe,symbols,count,method):
    base=pe.OPTIONAL_HEADER.ImageBase;start=base+symbols['_MAIN__']['rva']
    scratch=base+symbols['_ftable_']['rva']+4096
    state=scratch+2048;trace=state+8;control=scratch+6144
    imports={item.name.decode():item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    code=Driver(start,imports);labels={};branches=[]
    def address(value):return struct.pack('<I',value).hex()
    def label(name):labels[name]=len(code.code)
    def jump(opcode,name):
        code.emit(opcode);branches.append((len(code.code),name));code.emit('00000000')
    jump('e9','main');callback=start+len(code.code)
    # EAX is the argument pointer, ECX the evaluation index, EDX the trace.
    code.emit('8b4424048b0d'+address(state)+'81f980000000')
    jump('0f82','capacity-ok');code.push(3);code.api('ExitProcess');label('capacity-ok')
    code.emit('8d14498d14d5'+address(trace)+'508b008902')
    for index in range(4):
        code.emit('a1'+address(scratch+16+index*4)+'8942'+bytes([4+index*4]).hex())
    code.emit('58')
    for argument_class in (1,2,3):
        code.emit('3d'+address(scratch+12+argument_class*4))
        jump('0f84',f'class-{argument_class}')
    code.emit('833d'+address(state+4)+'00');jump('0f85','local-known')
    code.emit('a3'+address(state+4));label('local-known')
    code.emit('3b05'+address(state+4));jump('0f84','class-4');jump('e9','class-5')
    for argument_class in range(1,6):
        label(f'class-{argument_class}');code.emit('c74214'+address(argument_class));jump('e9','classified')
    label('classified')
    code.emit('f705'+address(scratch+4)+'01000000');jump('0f84','argument-unchanged')
    code.emit('8b148d'+address(scratch+1080)+'8910');label('argument-unchanged')
    code.emit('f705'+address(scratch+4)+'02000000');jump('0f84','globals-unchanged')
    code.emit('8b148d'+address(scratch+1080)+'8915'+address(scratch+16)+'8915'+address(scratch+24))
    code.emit('81f2000000808915'+address(scratch+20)+'8d51118915'+address(scratch+28))
    label('globals-unchanged');code.emit('ff05'+address(state))
    code.emit('833d'+address(scratch)+'00');jump('0f85','polynomial')
    code.emit('dd04cd'+address(scratch+56)+'c3')
    label('polynomial')
    # F(X)=(c2*X+c1)*X+c0, with no REAL residual store.
    code.emit('d900dc0d'+address(scratch+48)+'dc05'+address(scratch+40)+
        'd808dc05'+address(scratch+32)+'c3')
    label('main');code.emit('fc');code.push(-11);code.api('GetStdHandle');code.emit('89c3')
    code.push(-10);code.api('GetStdHandle');code.emit('a3'+address(control));code.store(control+4,count)
    label('loop')
    code.push(0);code.push(control+8);code.push(INPUT_BYTES);code.push(scratch)
    code.emit('ff35'+address(control));code.api('ReadFile')
    code.emit('813d'+address(control+8)+address(INPUT_BYTES));jump('0f84','input-complete')
    code.push(2);code.api('ExitProcess');label('input-complete')
    code.emit('31c0bf'+address(state)+'b9'+address(770)+'f3ab')
    args=([scratch+8,scratch+12,callback,scratch+16,scratch+20,scratch+24,scratch+28]
        if method=='regfal' else [scratch+20,callback,scratch+12,scratch+16,scratch+28])
    for value in reversed(args):code.push(value)
    code.call(base+symbols['_'+method+'_']['rva']);code.emit('83c4'+bytes([len(args)*4]).hex())
    code.write(scratch+16,16,control+12);code.write(state,4,control+12);code.write(trace,3072,control+12)
    code.emit('ff0d'+address(control+4));jump('0f85','loop')
    for offset,name in branches:struct.pack_into('<i',code.code,offset,labels[name]-(offset+4))
    driver=code.finish()
    later=sorted(item['rva'] for item in symbols.values() if item['type']==32 and item['section']==1 and item['rva']>symbols['_MAIN__']['rva'])
    if len(driver)>later[0]-symbols['_MAIN__']['rva']:raise ValueError('Root search driver exceeds PROGRAM body.')
    result=bytearray(original);offset=pe.get_offset_from_rva(symbols['_MAIN__']['rva'])
    result[offset:offset+len(driver)]=driver
    return bytes(result)


def main():
    import pefile
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--output',type=Path,required=True)
    parser.add_argument('--method',choices=['regfal','fdroot'],required=True)
    parser.add_argument('--native',type=Path);parser.add_argument('--fixtures',type=Path)
    parser.add_argument('--wine-prefix',type=Path,default=ROOT/'build/wineprefix')
    args=parser.parse_args();output=args.output.resolve()
    if output.exists() or ROOT/'build' not in output.parents:parser.error('Use a new FEQ/build/ directory.')
    output.mkdir(parents=True)
    original=(ROOT/'originals/feq1061/wrdapp/FEQ_10.61/BIN/fequtl.exe').read_bytes()
    if hashlib.sha256(original).hexdigest()!=ORIGINAL_SHA256:raise ValueError('Recovered executable hash changed.')
    pe=pefile.PE(data=original);symbols={item['name']:item for item in coff_symbols(original)}
    cases=json.loads(args.fixtures.read_text()) if args.fixtures else fixtures()
    inputs=b''.join(record(case) for case in cases)
    (output/'inputs.bin').write_bytes(inputs);(output/'fixtures.json').write_text(json.dumps(cases,indent=2)+'\n')
    exe=output/'PROBE.EXE';exe.write_bytes(image(original,pe,symbols,len(cases),args.method))
    env=os.environ.copy();env.update(WINEPREFIX=str(args.wine_prefix.resolve()),WINEDEBUG='-all',WINEDLLOVERRIDES='mscoree,mshtml=',MVK_CONFIG_LOG_LEVEL='0')
    command=[str(exe)] if os.name=='nt' else ['wine',str(exe)]
    # A regular input file avoids short reads from the host-to-Wine pipe.
    with (output/'inputs.bin').open('rb') as input_file:
        process=subprocess.run(command,cwd=output,env=env,stdin=input_file,capture_output=True,timeout=60)
    if process.returncode or len(process.stdout)!=OUTPUT_BYTES*len(cases):
        (output/'error.log').write_bytes(process.stdout+process.stderr)
        raise RuntimeError(f'Original root search driver failed: exit {process.returncode}, {len(process.stdout)} bytes.')
    expected=process.stdout;(output/'outputs.bin').write_bytes(expected)
    manifest=dict(original_sha256=ORIGINAL_SHA256,routines=['_'+args.method+'_'],cases=len(cases),
        input_record_bytes=INPUT_BYTES,output_record_bytes=OUTPUT_BYTES,
        input_sha256=hashlib.sha256(inputs).hexdigest(),output_sha256=hashlib.sha256(expected).hexdigest(),
        probe_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        fixtures=[dict(name=case['name'],offset=index*OUTPUT_BYTES,bytes=OUTPUT_BYTES) for index,case in enumerate(cases)])
    if args.native:
        native=subprocess.run([str(args.native.resolve()),'--'+args.method],input=inputs,capture_output=True,timeout=30)
        (output/'native.bin').write_bytes(native.stdout);(output/'native.stderr.log').write_bytes(native.stderr)
        manifest.update(native_sha256=hashlib.sha256(args.native.read_bytes()).hexdigest(),native_returncode=native.returncode,
            exact_bytes=native.returncode==0 and expected==native.stdout)
    (output/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print(f'{len(cases)} original {args.method.upper()} cases captured.',flush=True)
    if args.native:raise SystemExit(0 if manifest['exact_bytes'] else 1)

if __name__=='__main__':main()
