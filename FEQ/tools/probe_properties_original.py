#!/usr/bin/env python3
"""Capture COMPEL section properties from unchanged original FEQUTL code.

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
from probe_geometry_original import ORIGINAL_SHA256
from probe_profile_original import Driver, ROOT, real


def fixtures():
    rng=random.Random(5801061979);cases=[]
    for scale in (.001,1.,1000.):
        for trial in range(4):
            ns=1+trial%3;count=5+trial
            x=real(rng.uniform(-100,100)*scale);datum=real(rng.uniform(-200,200)*scale)
            points=[];sinuosity=[]
            for index in range(count):
                x=real(x+rng.uniform(.1,15)*scale)
                points.append([x,real(datum+rng.uniform(0,10)*scale),real(rng.uniform(.01,.08)),index%ns])
                sinuosity.append(real(rng.uniform(.8,3.)))
            if trial==0:points[1][0]=points[0][0]
            if trial==1:points[2][1]=points[1][1]
            low,high=min(p[1] for p in points),max(p[1] for p in points)
            for fraction in (0.,.37,1.1):
                for average in (0,1):
                    for mode in (0,2):
                        for beta in ('OLDBETA ','NEWBETA '):
                            cases.append(dict(name=f'scale-{scale}-trial-{trial}-fraction-{fraction}-average-{average}-mode-{mode}-beta-{beta.strip()}',
                                water_surface=real(low+fraction*(high-low)),points=points,roughness_modes=[(trial+i)%3 for i in range(ns)],
                                sinuosity_mode=mode,sinuosity=sinuosity,manning_factor=real(1.49 if trial%2 else 1.),beta_option=beta,
                                gravity=real(32.2 if trial%2 else 9.81),average_roughness=average,usgs_coefficients=trial%2,
                                slot=0.,previous_conveyance=[0.]*ns,previous_width=[0.]*ns))
    return cases


def record(case):
    points,modes=case['points'],case['roughness_modes'];beta=['OLDBETA ','NEWBETA ','NEWBETAM','NEWBETAE','NEWBETAX'].index(case['beta_option'])
    return (struct.pack('<f6I3f',case['water_surface'],len(points),len(modes),case['average_roughness'],case['sinuosity_mode'],beta,case['usgs_coefficients'],case['manning_factor'],case['gravity'],case['slot'])+
            b''.join(struct.pack('<iff',mode,k,t) for mode,k,t in zip(modes,case['previous_conveyance'],case['previous_width']))+
            b''.join(struct.pack('<fffIf',*point,sn) for point,sn in zip(points,case['sinuosity'])))


def image(original,pe,symbols,cases):
    base=pe.OPTIONAL_HEADER.ImageBase;start=base+symbols['_MAIN__']['rva'];scratch=base+symbols['_ftable_']['rva']
    imports={item.name.decode():item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    code=Driver(start,imports);code.emit('fc');code.push(-11);code.api('GetStdHandle');code.emit('89c3')
    for case in cases:
        points=case['points'];count=len(points);subs=len(case['roughness_modes']);data=bytearray()
        def put(fmt,*values):
            data.extend(bytes((-len(data))%8));address=scratch+len(data);data.extend(struct.pack(fmt,*values));return address
        zi=put('<f',case['water_surface']);npnt=put('<i',count);nsub=put('<i',subs);navm=put('<i',case['average_roughness'])
        x=put('<'+str(count)+'f',*[p[0] for p in points]);z=put('<'+str(count)+'f',*[p[1] for p in points]);sb=put('<'+str(count)+'i',*[p[3]+1 for p in points])
        nfac=put('<f',case['manning_factor']);betopt=put('<8s',case['beta_option'].encode());snflg=put('<i',case['sinuosity_mode'])
        lsn=put('<'+str(count)+'f',*[p[2] for p in points]);nvar=put('<'+str(subs)+'i',*case['roughness_modes'])
        naty=put('<'+str(9*subs)+'f',*([real(.03)]*(9*subs)));yatn=put('<'+str(9*subs)+'f',*(list(range(9))*subs));nny=put('<'+str(subs)+'i',*([9]*subs))
        sn=put('<'+str(count)+'f',*case['sinuosity']);wrn=put('<i',0)
        kold=put('<'+str(subs)+'f',*case['previous_conveyance']);told=put('<'+str(subs)+'f',*case['previous_width']);n=put('<'+str(subs)+'f',*([real(.03)]*subs))
        xsv=put('<22f',*list(range(9000,9022)));written=put('<i',0)
        code.copy(scratch,data)
        code.copy(base+symbols['_grvcom_']['rva'],struct.pack('<f',case['gravity']))
        code.copy(base+symbols['_nrdzcm_']['rva'],struct.pack('<ffifiii',0.,0.,1,case['slot'],case['usgs_coefficients'],0,0))
        args=[zi,npnt,nsub,navm,x,z,sb,nfac,betopt,snflg,lsn,nvar,naty,yatn,nny,sn,wrn,kold,told,n,xsv,8]
        for value in reversed(args):code.push(value)
        code.call(base+symbols['_compel_']['rva']);code.emit('81c4'+struct.pack('<I',len(args)*4).hex())
        code.write(xsv,22*4,written)
        for address in (n,kold,told):code.write(address,subs*4,written)
    driver=code.finish();later=sorted(item['rva'] for item in symbols.values() if item['type']==32 and item['section']==1 and item['rva']>symbols['_MAIN__']['rva'])
    if len(driver)>later[0]-symbols['_MAIN__']['rva']:raise ValueError('Properties driver exceeds replaceable PROGRAM body.')
    result=bytearray(original);offset=pe.get_offset_from_rva(symbols['_MAIN__']['rva']);result[offset:offset+len(driver)]=driver
    return bytes(result)


def main():
    import pefile
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--output',type=Path,required=True);parser.add_argument('--native',type=Path);parser.add_argument('--fixtures',type=Path)
    parser.add_argument('--wine-prefix',type=Path,default=ROOT/'build/wineprefix');args=parser.parse_args();output=args.output.resolve()
    if output.exists() or ROOT/'build' not in output.parents:parser.error('Use a new FEQ/build/ directory.')
    output.mkdir(parents=True);original=(ROOT/'originals/feq1061/wrdapp/FEQ_10.61/BIN/fequtl.exe').read_bytes()
    if hashlib.sha256(original).hexdigest()!=ORIGINAL_SHA256:raise ValueError('Recovered executable hash changed.')
    pe=pefile.PE(data=original);symbols={item['name']:item for item in coff_symbols(original)};cases=json.loads(args.fixtures.read_text()) if args.fixtures else fixtures();inputs=b''.join(record(case) for case in cases)
    (output/'inputs.bin').write_bytes(inputs);(output/'fixtures.json').write_text(json.dumps(cases,indent=2)+'\n')
    env=os.environ.copy();env.update(WINEPREFIX=str(args.wine_prefix.resolve()),WINEDEBUG='-all',WINEDLLOVERRIDES='mscoree,mshtml=',MVK_CONFIG_LOG_LEVEL='0');expected=bytearray();records=[]
    for first in range(0,len(cases),6):
        batch=cases[first:first+6];exe=output/'PROBE.EXE';exe.write_bytes(image(original,pe,symbols,batch));command=[str(exe)] if os.name=='nt' else ['wine',str(exe)]
        process=subprocess.run(command,cwd=output,env=env,capture_output=True,timeout=30,stdin=subprocess.DEVNULL)
        if process.returncode or len(process.stdout)!=sum(88+12*len(case['roughness_modes']) for case in batch):
            (output/'error.log').write_bytes(process.stdout+process.stderr)
            raise RuntimeError(f'Original properties driver failed: exit {process.returncode}, {len(process.stdout)} bytes.')
        cursor=0
        for case in batch:
            size=88+12*len(case['roughness_modes']);records.append({'name':case['name'],'offset':len(expected),'bytes':size});expected.extend(process.stdout[cursor:cursor+size]);cursor+=size
        print(f'{first+len(batch)}/{len(cases)} original section properties captured.',flush=True)
    (output/'outputs.bin').write_bytes(expected);manifest={'original_sha256':ORIGINAL_SHA256,'routine':'_compel_','cases':len(cases),'input_sha256':hashlib.sha256(inputs).hexdigest(),'output_sha256':hashlib.sha256(expected).hexdigest(),'fixtures':records}
    if args.native:
        native=subprocess.run([str(args.native.resolve())],input=inputs,capture_output=True,timeout=30);(output/'native.bin').write_bytes(native.stdout);(output/'native.stderr.log').write_bytes(native.stderr)
        manifest.update(native_sha256=hashlib.sha256(args.native.read_bytes()).hexdigest(),native_returncode=native.returncode,exact_bytes=native.returncode==0 and bytes(expected)==native.stdout)
    (output/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    if args.native:raise SystemExit(0 if manifest['exact_bytes'] else 1)


if __name__=='__main__':main()
