#!/usr/bin/env python3
"""Capture unchanged root routines with wide residuals and polynomial callbacks.

Only a temporary PROGRAM driver and its callback are installed. Each original
trial argument, mutable bracket field, status, and callback count is captured.
Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
"""
import argparse
import hashlib
import json
import math
import os
import random
import struct
import subprocess
from pathlib import Path
from inspect_binary import coff_symbols
from probe_profile_original import Driver, ROOT, real
from probe_geometry_original import ORIGINAL_SHA256


def fixtures():
    cases=[];rng=random.Random(58010613)
    def add(name,a=1.,b=9.,fl=-2.,fr=4.,epsx=0.,epsf=0.,sequence=None,coefficients=None,mutations=None):
        cases.append(dict(name=name,kind=int(coefficients is not None),mutate=int(mutations is not None),
            values=list(map(real,(epsx,epsf,a,b,fl,fr,73.25))),
            coefficients=coefficients or [0.,0.,0.],sequence=sequence or [0.],mutations=mutations or [0.]))
    add('left-endpoint-including-tolerance',fl=-.5,epsf=.5)
    add('right-endpoint-including-tolerance',fr=.5,epsf=.5)
    add('left-priority-both-endpoints',fl=-.5,fr=.25,epsf=.5)
    add('same-sign-positive',fl=2.,fr=3.)
    add('same-sign-negative',fl=-2.,fr=-3.)
    add('zero-residual')
    add('negative-zero-residual',sequence=[-0.])
    add('failure-sentinel',sequence=[-1.e30])
    add('sentinel-equality-then-zero',sequence=[real(-.99e30),0.])
    add('below-sentinel-before-float-store',sequence=[math.nextafter(float(real(-.99e30)),-math.inf)])
    add('residual-just-below-tolerance',epsf=.125,sequence=[math.nextafter(.125,0.),0.])
    add('residual-equal-tolerance',epsf=.125,sequence=[.125,0.])
    add('residual-negative-just-below-tolerance',epsf=.125,sequence=[-math.nextafter(.125,0.),0.])
    add('collapse-before-residual-left',fl=-1.,fr=4.,epsx=1.,epsf=.125,sequence=[.0625])
    add('collapse-before-residual-right',fl=-4.,fr=1.,epsx=1.,epsf=.125,sequence=[.0625])
    add('collapse-tie-takes-right',fl=-2.,fr=2.,epsx=1.,sequence=[1.])
    add('failure-before-collapse',epsx=1.,sequence=[-1.e30])
    add('zero-before-collapse',epsx=1.)
    add('iteration-limit-101-calls',sequence=[1.]*101)
    add('negative-iteration-limit',sequence=[-1.]*101)
    add('alternating-iteration-limit',sequence=[(-1.)**i for i in range(101)])
    add('mutated-trial-success',mutations=[3.125])
    add('mutated-trials-in-bracket',sequence=[1.,-1.,.75,0.],mutations=[6.125,2.75,4.5,3.9])
    for epsx in (.5,math.nextafter(.5,0.),.49999997,.50000006):
        add(f'collapse-tolerance-{epsx}',a=1.,b=3.,epsx=epsx,sequence=[1.,0.])
    for epsx in (-1.,0.,.0000005,.000001,.000002):
        add(f'collapse-floor-{epsx}',a=1.,b=1.0000019,epsx=epsx,sequence=[1.,0.])
    add('negative-residual-tolerance',epsf=-1.,sequence=[.01,0.])
    add('zero-width-zero-center',a=0.,b=0.,sequence=[1.,0.])
    for scale in (.00001,1.,10000.):
        for trial in range(60):
            a=real(rng.uniform(-20.,0.)*scale);b=real(rng.uniform(.1,30.)*scale)
            fl=real(-rng.uniform(.01,100.));fr=real(rng.uniform(.01,100.))
            sequence=[rng.uniform(-30,30) for i in range(rng.randrange(1,22))]+[0.]
            add(f'script-scale-{scale}-trial-{trial}',a,b,fl,fr,sequence=sequence)
        for trial in range(60):
            a=real(rng.uniform(.01,1.)*scale);b=real(rng.uniform(2.,20.)*scale)
            root=rng.uniform(a,b);coefficients=[-root*root,0.,1.]
            fl=real(a*a-root*root);fr=real(b*b-root*root)
            add(f'quadratic-scale-{scale}-trial-{trial}',a,b,fl,fr,epsx=real(1.e-7 if trial%3 else 0.),
                epsf=real(scale*scale*1.e-7),coefficients=coefficients)
    for trial in range(40):
        sequence=[rng.uniform(-10.,10.) for i in range(12)]+[0.]
        mutations=list(map(real,(rng.uniform(1.,9.) for i in range(13))))
        add(f'mutable-script-{trial}',sequence=sequence,mutations=mutations)
    return cases


def padded(values):
    return (values+[values[-1]]*101)[:101]


def record(case):
    return struct.pack('<II7f3d101d101f',case['kind'],case['mutate'],*case['values'],
        *case['coefficients'],*padded(case['sequence']),*padded(case['mutations']))


def image(original,pe,symbols,cases,method='rgf3'):
    base=pe.OPTIONAL_HEADER.ImageBase;start=base+symbols['_MAIN__']['rva'];scratch=base+symbols['_ftable_']['rva']+4096
    state=scratch+2048;counter=state+4;trace=state+8
    imports={item.name.decode():item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    code=Driver(start,imports)
    code.emit('e900000000');callback=start+len(code.code)
    # EAX: mutable argument address. ECX: zero-based call index. EDX: bits.
    code.emit('8b4424048b0d'+struct.pack('<I',counter).hex()+'8b1089148d'+struct.pack('<I',trace).hex())
    code.emit('833d'+struct.pack('<I',scratch+4).hex()+'007409')
    code.emit('8b148d'+struct.pack('<I',scratch+868).hex()+'8910')
    code.emit('ff05'+struct.pack('<I',counter).hex())
    code.emit('833d'+struct.pack('<I',scratch).hex()+'007508')
    code.emit('dd04cd'+struct.pack('<I',scratch+60).hex()+'c3')
    # Horner polynomial F(X) = (c2*X+c1)*X+c0, without a REAL store.
    code.emit('d900dc0d'+struct.pack('<I',scratch+52).hex()+'dc05'+struct.pack('<I',scratch+44).hex()+
        'd808dc05'+struct.pack('<I',scratch+36).hex()+'c3')
    struct.pack_into('<i',code.code,1,len(code.code)-5)
    code.emit('fc');code.push(-11);code.api('GetStdHandle');code.emit('89c3')
    for case in cases:
        payload=record(case);code.copy(scratch,payload[:60])
        if not case['kind']:code.copy(scratch+60,struct.pack('<'+str(len(case['sequence']))+'d',*case['sequence']))
        if case['mutate']:code.copy(scratch+868,struct.pack('<'+str(len(case['mutations']))+'f',*case['mutations']))
        code.emit('31c0bf'+struct.pack('<I',state).hex()+'b967000000f3ab')
        args=[scratch+8,scratch+12,callback,scratch+16,scratch+20,scratch+24,scratch+28,scratch+32,state]
        for value in reversed(args):code.push(value)
        code.call(base+symbols['_'+method+'_']['rva']);code.emit('83c424')
        code.write(scratch+16,20,state+512);code.write(state,412,state+512)
    driver=code.finish();later=sorted(item['rva'] for item in symbols.values() if item['type']==32 and item['section']==1 and item['rva']>symbols['_MAIN__']['rva'])
    if len(driver)>later[0]-symbols['_MAIN__']['rva']:raise ValueError('Root driver exceeds replaceable PROGRAM body.')
    result=bytearray(original);offset=pe.get_offset_from_rva(symbols['_MAIN__']['rva']);result[offset:offset+len(driver)]=driver
    return bytes(result)


def main():
    import pefile
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--output',type=Path,required=True);parser.add_argument('--native',type=Path)
    parser.add_argument('--method',choices=['regflt','rgf','rgf3','rgf5'],default='rgf3')
    parser.add_argument('--fixtures',type=Path);parser.add_argument('--wine-prefix',type=Path,default=ROOT/'build/wineprefix')
    args=parser.parse_args();output=args.output.resolve()
    if output.exists() or ROOT/'build' not in output.parents:parser.error('Use a new FEQ/build/ directory.')
    output.mkdir(parents=True);original=(ROOT/'originals/feq1061/wrdapp/FEQ_10.61/BIN/fequtl.exe').read_bytes()
    if hashlib.sha256(original).hexdigest()!=ORIGINAL_SHA256:raise ValueError('Recovered executable hash changed.')
    pe=pefile.PE(data=original);symbols={item['name']:item for item in coff_symbols(original)};cases=json.loads(args.fixtures.read_text()) if args.fixtures else fixtures()
    inputs=b''.join(record(case) for case in cases);(output/'inputs.bin').write_bytes(inputs);(output/'fixtures.json').write_text(json.dumps(cases,indent=2)+'\n')
    env=os.environ.copy();env.update(WINEPREFIX=str(args.wine_prefix.resolve()),WINEDEBUG='-all',WINEDLLOVERRIDES='mscoree,mshtml=',MVK_CONFIG_LOG_LEVEL='0')
    expected=bytearray();records=[];first=0
    while first<len(cases):
        batch=cases[first:first+20]
        while True:
            try:
                payload=image(original,pe,symbols,batch,args.method)
                break
            except ValueError as error:
                if str(error)!='Root driver exceeds replaceable PROGRAM body.' or len(batch)==1:raise
                batch=batch[:len(batch)//2]
        exe=output/'PROBE.EXE';exe.write_bytes(payload);command=[str(exe)] if os.name=='nt' else ['wine',str(exe)]
        process=subprocess.run(command,cwd=output,env=env,capture_output=True,timeout=30,stdin=subprocess.DEVNULL)
        if process.returncode or len(process.stdout)!=432*len(batch):
            (output/'error.log').write_bytes(process.stdout+process.stderr)
            raise RuntimeError(f'Original root driver failed: exit {process.returncode}, {len(process.stdout)} bytes.')
        for index,case in enumerate(batch):
            records.append(dict(name=case['name'],offset=len(expected),bytes=432));expected.extend(process.stdout[index*432:(index+1)*432])
        first+=len(batch);(output/'outputs.partial.bin').write_bytes(expected)
        print(f'{first}/{len(cases)} original root cases captured.',flush=True)
    (output/'outputs.bin').write_bytes(expected)
    manifest=dict(original_sha256=ORIGINAL_SHA256,routines=['_'+args.method+'_'],cases=len(cases),
        input_sha256=hashlib.sha256(inputs).hexdigest(),output_sha256=hashlib.sha256(expected).hexdigest(),
        probe_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),fixtures=records)
    if args.native:
        native=subprocess.run([str(args.native.resolve()),'--'+args.method],input=inputs,capture_output=True,timeout=30);(output/'native.bin').write_bytes(native.stdout);(output/'native.stderr.log').write_bytes(native.stderr)
        manifest.update(native_sha256=hashlib.sha256(args.native.read_bytes()).hexdigest(),native_returncode=native.returncode,exact_bytes=native.returncode==0 and bytes(expected)==native.stdout)
    (output/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    if args.native:raise SystemExit(0 if manifest['exact_bytes'] else 1)

if __name__=='__main__':main()
