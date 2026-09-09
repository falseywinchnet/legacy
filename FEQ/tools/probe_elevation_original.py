#!/usr/bin/env python3
"""Capture CHKARG spacing and duplicate removal from original FEQUTL instructions.

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
    cases=[];rng=random.Random(580942)
    def add(name,values,near,step,added=0,capacity=128):
        cases.append(dict(name=name,elevations=[real(v) for v in values],near_zero=real(near),maximum_step=real(step),added=added,capacity=capacity))
    add('model-rectangle-0-to-40',[0,40],.01,2.5)
    for scale in (.0001,1.,10000.):
        for trial in range(40):
            values=sorted(real(rng.uniform(-20,30)*scale) for index in range(2+trial%11))
            add(f'random-scale-{scale}-trial-{trial}',values,.01*scale,rng.uniform(.7,5)*scale,trial%2)
        for datum in (-100.,0.,100.):
            for second in (0.,.000625,.001,.01,.011,.02):
                add(f'near-zero-scale-{scale}-datum-{datum}-second-{second}',[(datum+x)*scale for x in (0.,second,1.,1.5)],.01*scale,.17*scale)
        for step in (.1,.2,1.,2.,2.000001,3.333333):
            add(f'spacing-scale-{scale}-step-{step}',[x*scale for x in (0.,1.,2.,10.)],.01*scale,step*scale)
    for datum in (-1.,0.,1.):
        add(f'equal-values-{datum}',[datum]*4,.01,.1,capacity=8)
    for capacity in (2,3,4,6,10):
        add(f'capacity-{capacity}',[0.,1.],.01,.1,capacity=capacity)
    return cases


def record(case):
    values=case['elevations'];capacity=case['capacity'];padded=values+[real(9000+i) for i in range(capacity-len(values))]
    return struct.pack('<IIffI',len(values),capacity,case['near_zero'],case['maximum_step'],case['added'])+struct.pack('<'+str(capacity)+'f',*padded)


def image(original,pe,symbols,cases):
    base=pe.OPTIONAL_HEADER.ImageBase;start=base+symbols['_MAIN__']['rva'];scratch=base+symbols['_ftable_']['rva']
    imports={item.name.decode():item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    code=Driver(start,imports);code.emit('fc');code.push(-11);code.api('GetStdHandle');code.emit('89c3')
    for case in cases:
        data=bytearray()
        def put(fmt,*values):
            data.extend(bytes((-len(data))%8));address=scratch+len(data);data.extend(struct.pack(fmt,*values));return address
        out=put('<i',99);maximum=put('<i',case['capacity']);near=put('<f',case['near_zero']);step=put('<f',case['maximum_step']);added=put('<i',case['added']);count=put('<i',len(case['elevations']))
        raw=record(case)[20:];z=put('<'+str(len(raw))+'s',raw);written=put('<i',0)
        code.copy(scratch,data)
        args=[out,maximum,near,step,added,count,z]
        for value in reversed(args):code.push(value)
        code.call(base+symbols['_chkarg_']['rva']);code.emit('83c41c')
        code.write(count,4,written);code.write(z,len(raw),written)
    driver=code.finish();later=sorted(item['rva'] for item in symbols.values() if item['type']==32 and item['section']==1 and item['rva']>symbols['_MAIN__']['rva'])
    if len(driver)>later[0]-symbols['_MAIN__']['rva']:raise ValueError('Elevation driver exceeds replaceable PROGRAM body.')
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
    for first in range(0,len(cases),4):
        batch=cases[first:first+4];exe=output/'PROBE.EXE';exe.write_bytes(image(original,pe,symbols,batch));command=[str(exe)] if os.name=='nt' else ['wine',str(exe)]
        process=subprocess.run(command,cwd=output,env=env,capture_output=True,timeout=30,stdin=subprocess.DEVNULL)
        if process.returncode or len(process.stdout)!=sum(4+4*case['capacity'] for case in batch):
            (output/'error.log').write_bytes(process.stdout+process.stderr)
            raise RuntimeError(f'Original elevation driver failed: exit {process.returncode}, {len(process.stdout)} bytes.')
        cursor=0
        for case in batch:
            size=4+4*case['capacity'];records.append({'name':case['name'],'offset':len(expected),'bytes':size});expected.extend(process.stdout[cursor:cursor+size]);cursor+=size
        print(f'{first+len(batch)}/{len(cases)} original elevation sequences captured.',flush=True)
    (output/'outputs.bin').write_bytes(expected);manifest={'original_sha256':ORIGINAL_SHA256,'routine':'_chkarg_','cases':len(cases),'input_sha256':hashlib.sha256(inputs).hexdigest(),'output_sha256':hashlib.sha256(expected).hexdigest(),'fixtures':records}
    if args.native:
        native=subprocess.run([str(args.native.resolve())],input=inputs,capture_output=True,timeout=30);(output/'native.bin').write_bytes(native.stdout);(output/'native.stderr.log').write_bytes(native.stderr)
        manifest.update(native_sha256=hashlib.sha256(args.native.read_bytes()).hexdigest(),native_returncode=native.returncode,exact_bytes=native.returncode==0 and bytes(expected)==native.stdout)
        for item in records:
            start,end=item['offset'],item['offset']+item['bytes']
            if bytes(expected[start:end])!=native.stdout[start:end]:print(item['name']+': DIFFERENT')
    (output/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    if args.native:raise SystemExit(0 if manifest['exact_bytes'] else 1)


if __name__=='__main__':main()
