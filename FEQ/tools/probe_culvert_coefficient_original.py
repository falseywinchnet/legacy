#!/usr/bin/env python3
"""Capture unchanged FCD123 across all five culvert classes.

Box type-3 fixtures call original LKTQC with constant positive critical flow
in both rows, isolating the coefficient polynomial and its adjustments.
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

SHAPES=('PIPE','FLARED','BOX','MITER','RCPTG')


def fixtures():
    cases=[];rng=random.Random(1061580123)
    factors=((1.,1.,1.),(.87,1.03,.91),(1.12,1.17,1.1))
    for scale in (.0001,1.,10000.):
        for shape in (0,1,3):
            for ratio in (-.1,0.,.01,.39999997,.4,.40000003,1.,1.599,1.6,1.6000001,2.):
                for factor_index,factor in enumerate(factors):
                    height=real(2.25*scale);bed=real(.125*scale);level=real(bed+height*ratio)
                    cases.append(dict(name=f'{SHAPES[shape]}-scale-{scale}-ratio-{ratio}-factors-{factor_index}',shape=shape,
                        flow_type=1+factor_index,ratio_flag=(0,1,-2)[factor_index],values=list(map(real,(height,level,bed,1.,2.,*factor)))))
        for shape in (2,4):
            for flow_type in (1,2,3):
                for froude in (0.,.3,.7,1.,1.0999999,1.1,1.1000001,1.2):
                    for factor_index,factor in enumerate(factors):
                        qc=real(2.25*scale)
                        cases.append(dict(name=f'{SHAPES[shape]}-type-{flow_type}-scale-{scale}-froude-{froude}-factors-{factor_index}',shape=shape,
                            flow_type=flow_type,ratio_flag=0,values=list(map(real,(scale,scale,0.,froude*qc,qc,*factor)))))
    for trial in range(150):
        shape=trial%5;height=real(rng.uniform(.01,10.));bed=real(rng.uniform(-10.,10.));qc=real(rng.uniform(.01,100.))
        values=list(map(real,(height,bed+rng.uniform(-.2,2.)*height,bed,rng.uniform(0.,1.3)*qc,qc,
            rng.uniform(.5,1.2),rng.uniform(.5,1.2),rng.uniform(.5,1.2))))
        cases.append(dict(name=f'random-{trial}',shape=shape,flow_type=trial%3+1,ratio_flag=0,values=values))
    return cases


def record(case):return struct.pack('<IIi8f',case['shape'],case['flow_type'],case['ratio_flag'],*case['values'])


def image(original,pe,symbols,cases):
    base=pe.OPTIONAL_HEADER.ImageBase;start=base+symbols['_MAIN__']['rva'];table=base+symbols['_ftable_']['rva'];scratch=table+4096
    imports={item.name.decode():item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    code=Driver(start,imports);code.emit('fc');code.push(-11);code.api('GetStdHandle');code.emit('89c3')
    code.store(base+symbols['_offcom_']['rva']+11*4,13)
    cd=base+symbols['_cdcom_']['rva'];xs2=base+symbols['_xs2com_']['rva'];xs3=base+symbols['_xs3com_']['rva']
    for case in cases:
        values=case['values'];payload=bytearray(72*4)
        for index,value in ((1,59),(3,12),(4,33)):struct.pack_into('<i',payload,index*4,value)
        for row in range(3):
            struct.pack_into('<f',payload,(33+13*row)*4,float(row+1));struct.pack_into('<f',payload,(40+13*row)*4,values[4])
        code.copy(table,payload);code.copy(scratch,record(case));code.copy(scratch+128,SHAPES[case['shape']].ljust(8).encode())
        code.store(scratch+64,6)
        code.copy(cd+24,struct.pack('<3fi',*values[5:],case['ratio_flag']))
        code.store(xs2,1);code.store(xs3,1)
        code.copy(xs2+12,struct.pack('<2f',values[2],1.5));code.copy(xs2+28,struct.pack('<f',1.))
        code.copy(xs3+4,struct.pack('<f',values[3]));code.copy(xs3+16,struct.pack('<f',1.5));code.copy(xs3+28,struct.pack('<f',2.))
        for address in (8,scratch+16,scratch+12,scratch+128,scratch+4,scratch+64):code.push(address)
        code.call(base+symbols['_fcd123_']['rva']);code.emit('83c418dd1d'+struct.pack('<I',scratch+80).hex())
        code.write(scratch+80,8,scratch+256);code.write(cd+36,4,scratch+256)
    driver=code.finish();later=sorted(item['rva'] for item in symbols.values() if item['type']==32 and item['section']==1 and item['rva']>symbols['_MAIN__']['rva'])
    if len(driver)>later[0]-symbols['_MAIN__']['rva']:raise ValueError('Coefficient driver exceeds replaceable PROGRAM body.')
    result=bytearray(original);offset=pe.get_offset_from_rva(symbols['_MAIN__']['rva']);result[offset:offset+len(driver)]=driver
    return bytes(result)


def main():
    import pefile
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--output',type=Path,required=True);parser.add_argument('--native',type=Path)
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
        batch=cases[first:first+12]
        while True:
            try:
                payload=image(original,pe,symbols,batch)
                break
            except ValueError as error:
                if str(error)!='Coefficient driver exceeds replaceable PROGRAM body.' or len(batch)==1:raise
                batch=batch[:len(batch)//2]
        exe=output/'PROBE.EXE';exe.write_bytes(payload);command=[str(exe)] if os.name=='nt' else ['wine',str(exe)]
        process=subprocess.run(command,cwd=output,env=env,capture_output=True,timeout=30,stdin=subprocess.DEVNULL)
        if process.returncode or len(process.stdout)!=12*len(batch):
            (output/'error.log').write_bytes(process.stdout+process.stderr)
            raise RuntimeError(f'Original coefficient driver failed: exit {process.returncode}, {len(process.stdout)} bytes.')
        for index,case in enumerate(batch):
            records.append(dict(name=case['name'],offset=len(expected),bytes=12));expected.extend(process.stdout[index*12:(index+1)*12])
        first+=len(batch);(output/'outputs.partial.bin').write_bytes(expected)
        print(f'{first}/{len(cases)} original discharge coefficient cases captured.',flush=True)
    (output/'outputs.bin').write_bytes(expected)
    manifest=dict(original_sha256=ORIGINAL_SHA256,routines=['_fcd123_'],cases=len(cases),
        input_sha256=hashlib.sha256(inputs).hexdigest(),output_sha256=hashlib.sha256(expected).hexdigest(),
        probe_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),fixtures=records)
    if args.native:
        native=subprocess.run([str(args.native.resolve()),'--coefficient'],input=inputs,capture_output=True,timeout=30);(output/'native.bin').write_bytes(native.stdout);(output/'native.stderr.log').write_bytes(native.stderr)
        manifest.update(native_sha256=hashlib.sha256(args.native.read_bytes()).hexdigest(),native_returncode=native.returncode,exact_bytes=native.returncode==0 and bytes(expected)==native.stdout)
    (output/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    if args.native:raise SystemExit(0 if manifest['exact_bytes'] else 1)

if __name__=='__main__':main()
