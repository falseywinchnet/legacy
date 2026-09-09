#!/usr/bin/env python3
"""Capture unchanged FEQUTL boundary constructors with an isolated PROGRAM driver.

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
from probe_geometry_original import ORIGINAL_SHA256
from probe_profile_original import Driver, ROOT, real

ROUTINES = ('_urqte_', '_mkpipe_', '_mkbox_', '_rhmak_', '_urqmak_')

def fixtures():
    cases=[]
    def add(kind,name,rise=1.,span=1.,slot=.01,height=30.,xoff=0.,yoff=0.,sides=0,x=(),y=()):
        cases.append(dict(kind=kind,name=name,sides=sides,values=list(map(real,(rise,span,slot,height,xoff,yoff))),x=list(map(real,x)),y=list(map(real,y))))
    for rise in (.001,.1,1.,3.15,12.,18.9,100.,10000.):
        for span in (.001,.2,1.,3.15,12.,18.9,150.,20000.):add(0,f'ellipse-{rise}-{span}',rise,span)
    rng=random.Random(5801061)
    for index in range(128):add(0,f'ellipse-varied-{index}',10**rng.uniform(-3,4),10**rng.uniform(-3,4))
    for diameter in (.001,.17,1.,3.58,12.,105.,10000.):
        for sides in (3,4,5,12,35,36,40,72,360):
            for xoff,yoff in ((0.,0.),(100.03,.4),(-1.001,-20.1)):
                add(1,f'circle-{diameter}-{sides}-{xoff}-{yoff}',diameter,sides=sides,xoff=xoff,yoff=yoff)
    for sides in (*range(3,129),129,255,256,360,720,1000,1001,4096,10000):
        for scale in (.017,1003.7):
            add(1,f'circle-dense-count-{sides}-{scale}',scale,sides=sides,
                slot=scale*.0007,height=scale*1.8)
    for rise in (.001,.17,1.,3.58,12.,105.,10000.):
        for span in (.001,3.15,12.,108.):
            for xoff,yoff in ((0.,0.),(100.03,.4),(-1.001,-20.1)):
                add(2,f'box-{rise}-{span}-{xoff}-{yoff}',rise,span,xoff=xoff,yoff=yoff)
    for count in (2,3,4,7,11,23,32):
        for kind in (3,4):
            for scale in (.001,1.,120.,10000.):
                theta=math.pi if kind==3 else math.pi/2
                x=[scale*math.sin(theta*i/(count-1)) for i in range(count)]
                # A two-point half shape needs a nonzero chord at the slot.
                if count==2:x[1]=scale
                y=[scale*math.cos(theta*i/(count-1)) for i in range(count)]
                for xoff,yoff in ((0.,0.),(100.03,.4),(-1.001,-20.1)):
                    add(kind,f'mirror-{kind}-{count}-{scale}-{xoff}-{yoff}',xoff=xoff,yoff=yoff,x=x,y=y)
    # Real original RHARCH outputs exercise the exact slot intersections used
    # by standard pipe arches, independently of this new implementation.
    directory=ROOT/'tests/reference/arch_perimeter'
    manifest=json.loads((directory/'manifest.json').read_text());data=(directory/'outputs.bin').read_bytes()
    for index,entry in enumerate(manifest['fixtures']):
        if index%12:continue
        offset=entry['offset'];error,count=struct.unpack_from('<ii',data,offset+8)
        if error:continue
        x=struct.unpack_from('<23f',data,offset+20);y=struct.unpack_from('<23f',data,offset+112)
        for xoff,yoff in ((0.,0.),(39.001,.8)):
            add(3,f'arch-source-{index}-{xoff}-{yoff}',xoff=xoff,yoff=yoff,x=x,y=y)
    return cases

def record(case):
    return struct.pack('<II6fI',case['kind'],case['sides'],*case['values'],len(case['x']))+b''.join(struct.pack('<f',value) for value in case['x']+case['y'])

def points(case):
    return (11,case['sides']+4,41,2*len(case['x'])+2,4*len(case['x']))[case['kind']]

def image(original,pe,symbols,cases):
    base=pe.OPTIONAL_HEADER.ImageBase;start=base+symbols['_MAIN__']['rva'];scratch=base+symbols['_ftable_']['rva']
    imports={item.name.decode():item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    code=Driver(start,imports);code.emit('fc');code.push(-11);code.api('GetStdHandle');code.emit('89c3')
    for case in cases:
        data=bytearray()
        def put(fmt,*values):
            data.extend(bytes((-len(data))%8));address=scratch+len(data);data.extend(struct.pack(fmt,*values));return address
        rise,span,slot,height,xoff,yoff=[put('<f',v) for v in case['values']]
        sides=put('<i',case['sides']);count=put('<i',len(case['x']));xin=put('<'+str(len(case['x']))+'f',*case['x']);yin=put('<'+str(len(case['y']))+'f',*case['y'])
        size=points(case);n=put('<i',0);written=put('<i',0)
        # Outputs are fully overwritten by the unchanged routine; reserve
        # scratch space without embedding large zero arrays into PROGRAM.
        x=scratch+len(data)+16;y=x+size*4
        code.copy(scratch,data)
        kind=case['kind']
        if kind==0:args=[rise,span,n,x,y]
        elif kind==1:args=[xoff,yoff,sides,rise,slot,height,n,x,y]
        elif kind==2:args=[xoff,yoff,span,rise,slot,height,n,x,y]
        else:args=[slot,height,yoff,xoff,count,xin,yin,x,y,n]
        for value in reversed(args):code.push(value)
        code.call(base+symbols[ROUTINES[kind]]['rva']);code.emit('83c4'+bytes([len(args)*4]).hex())
        code.write(n,4,written);code.write(x,4*size,written);code.write(y,4*size,written)
    driver=code.finish();later=sorted(item['rva'] for item in symbols.values() if item['type']==32 and item['section']==1 and item['rva']>symbols['_MAIN__']['rva'])
    if len(driver)>later[0]-symbols['_MAIN__']['rva']:raise ValueError('Conduit driver exceeds replaceable PROGRAM body.')
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
    first=0
    while first<len(cases):
        batch=cases[first:first+24]
        while True:
            try:
                payload=image(original,pe,symbols,batch)
                break
            except ValueError as error:
                if str(error)!='Conduit driver exceeds replaceable PROGRAM body.' or len(batch)==1:raise
                batch=batch[:len(batch)//2]
        exe=output/'PROBE.EXE';exe.write_bytes(payload);command=[str(exe)] if os.name=='nt' else ['wine',str(exe)]
        process=subprocess.run(command,cwd=output,env=env,capture_output=True,timeout=30,stdin=subprocess.DEVNULL)
        if process.returncode or len(process.stdout)!=sum(4+8*points(case) for case in batch):
            (output/'error.log').write_bytes(process.stdout+process.stderr)
            raise RuntimeError(f'Original conduit driver failed: exit {process.returncode}, {len(process.stdout)} bytes.')
        cursor=0
        for case in batch:
            size=4+8*points(case)
            if struct.unpack_from('<I',process.stdout,cursor)[0]!=points(case):raise ValueError('Unexpected original boundary point count.')
            records.append({'name':case['name'],'routine':ROUTINES[case['kind']],'offset':len(expected),'bytes':size});expected.extend(process.stdout[cursor:cursor+size]);cursor+=size
        first+=len(batch)
        (output/'outputs.partial.bin').write_bytes(expected)
        print(f'{first}/{len(cases)} original conduit boundaries captured.',flush=True)
    (output/'outputs.bin').write_bytes(expected);manifest={'original_sha256':ORIGINAL_SHA256,'routines':list(ROUTINES),'cases':len(cases),'input_sha256':hashlib.sha256(inputs).hexdigest(),'output_sha256':hashlib.sha256(expected).hexdigest(),'probe_sha256':hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),'fixtures':records}
    if args.native:
        native=subprocess.run([str(args.native.resolve())],input=inputs,capture_output=True,timeout=30);(output/'native.bin').write_bytes(native.stdout);(output/'native.stderr.log').write_bytes(native.stderr)
        manifest.update(native_sha256=hashlib.sha256(args.native.read_bytes()).hexdigest(),native_returncode=native.returncode,exact_bytes=native.returncode==0 and bytes(expected)==native.stdout)
    (output/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    if args.native:raise SystemExit(0 if manifest['exact_bytes'] else 1)

if __name__=='__main__':main()
