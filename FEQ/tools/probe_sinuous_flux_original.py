#!/usr/bin/env python3
"""Capture original FBASEL Gaussian sinuosity integrals with streamed fixtures.

The driver calls unchanged GRULE and FBASEL after released runtime startup.
Only a build-directory PROGRAM entry is replaced; originals are hash-checked.
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

POINTS=8
SUBSECTIONS=4
INPUT_BYTES=204
OUTPUT_BYTES=112


def fixtures():
    rng=random.Random(10615802775);cases=[]
    def add(name,water,points,modes,sinuosity,order,model,factor=1.49,gravity=32.2):
        cases.append(dict(name=name,water_surface=real(water),points=points,roughness_modes=modes,
            sinuosity=list(map(real,sinuosity)),order=order,model=model,manning_factor=real(factor),gravity=real(gravity)))
    for scale in (.001,1.,1000.):
        for shape in ('rising','falling','horizontal','vertical','overhang','valley'):
            for wet in (0.,.31,1.1):
                coordinates={'rising':[(0.,0.),(12.,6.)], 'falling':[(0.,6.),(12.,0.)],
                    'horizontal':[(0.,0.),(12.,0.)], 'vertical':[(0.,0.),(0.,6.)],
                    'overhang':[(12.,0.),(0.,6.)], 'valley':[(0.,6.),(6.,0.),(12.,6.)]}[shape]
                points=[[real((x+.3125)*scale),real((z-.173)*scale),real(.037),0] for x,z in coordinates]
                water=real((-.173+6.*wet)*scale)
                for order in (1,5,21):
                    for model in (0,1,2):
                        add(f'{shape}-scale-{scale}-wet-{wet}-order-{order}-model-{model}',water,points,[0],
                            [1.5-.75*i/(len(points)-1) for i in range(len(points))],order,model)
        for trial in range(48):
            count=2+trial%7;subs=1+trial%4
            offset=rng.uniform(-10,10)*scale;datum=rng.uniform(-2,2)*scale
            points=[]
            for index in range(count):
                offset=real(offset+rng.uniform(.3,10)*scale)
                points.append([offset,real(datum+rng.uniform(0,6)*scale),real(rng.uniform(.015,.08)),index%subs])
            water=real(datum+rng.uniform(.1,8)*scale)
            modes=[(trial+i)%3 for i in range(subs)]
            add(f'random-scale-{scale}-trial-{trial}',water,points,modes,
                [rng.uniform(.5,3.) for i in range(count)],(1,2,3,5,7,11,21)[trial%7],trial%3,
                1.0 if trial%2 else 1.49,9.81 if trial%2 else 32.2)
    # Supplied triangular-channel geometry, with the original linear point
    # sinuosity. Synthetic probes supply positive depth directly.
    for water in (.0001,.08,2.,4.,6.,8.,10.):
        for order in (5,7,21):
            add(f'triangular-channel-depth-{water}-order-{order}',water,
                [[0.,10.,real(.05),0],[10.,0.,real(.05),0],[20.,10.,real(.05),0]],
                [0],[1.5,1.,.5],order,1)
    return cases


def record(case):
    points=case['points'];subs=len(case['roughness_modes'])
    result=struct.pack('<fIIIIff',case['water_surface'],len(points),subs,case['order'],case['model'],case['manning_factor'],case['gravity'])
    result+=struct.pack('<4i',*(case['roughness_modes']+[0]*(SUBSECTIONS-subs)))
    for index in range(POINTS):
        point=points[index] if index<len(points) else [0.,0.,.03,0]
        sinuosity=case['sinuosity'][index] if index<len(points) else 1.
        result+=struct.pack('<fffIf',*point,sinuosity)
    return result


def image(original,pe,symbols,count):
    base=pe.OPTIONAL_HEADER.ImageBase;start=base+symbols['_MAIN__']['rva']
    scratch=base+symbols['_ftable_']['rva']+4096;record_address=scratch+1024;work=scratch+8192
    gnicom=base+symbols['_gnicom_']['rva'];gravity=base+symbols['_grvcom_']['rva']
    imports={item.name.decode():item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    data=bytearray()
    def put(fmt,*values):
        data.extend(bytes((-len(data))%8));address=work+len(data);data.extend(struct.pack(fmt,*values));return address
    snflag=put('<i',1)
    x=put('<8f',*([0.]*8));z=put('<8f',*([0.]*8));sb=put('<8i',*([1]*8));lsn=put('<8f',*([.03]*8));sn=put('<8f',*([1.]*8))
    naty=put('<36f',*([.03]*36));yatn=put('<36f',*(list(range(9))*4));nny=put('<4i',9,9,9,9)
    betopt=put('<8s',b'OLDBETA ');options=put('<24s',b'OLDBETA NEWBETA NEWBETAX')
    n=put('<4f',.03,.03,.03,.03);ts=put('<4f',0,0,0,0);ps=put('<4f',0,0,0,0)
    area=put('<4d',0,0,0,0);moment=put('<4d',0,0,0,0);ns=put('<4f',0,0,0,0)
    sums=[put('<d',0) for unused in range(8)]
    ymax=put('<4f',0,0,0,0);sbsn=put('<4f',0,0,0,0);qs=put('<4f',0,0,0,0);ks=put('<4f',0,0,0,0)
    code=Driver(start,imports);code.emit('fc');code.push(-11);code.api('GetStdHandle');code.emit('89c3')
    code.push(-10);code.api('GetStdHandle');code.emit('a3'+struct.pack('<I',scratch).hex());code.store(scratch+4,count)
    loop=start+len(code.code)
    code.push(0);code.push(scratch+8);code.push(INPUT_BYTES);code.push(record_address)
    code.emit('ff35'+struct.pack('<I',scratch).hex());code.api('ReadFile')
    code.emit('813d'+struct.pack('<II',scratch+8,INPUT_BYTES).hex());branch=len(code.code);code.emit('0f8400000000')
    code.push(2);code.api('ExitProcess');struct.pack_into('<i',code.code,branch+2,len(code.code)-(branch+6))
    code.copy(work,data)
    def move_word(source,destination,increment=False):
        code.emit('a1'+struct.pack('<I',source).hex())
        if increment:code.emit('40')
        code.emit('a3'+struct.pack('<I',destination).hex())
    move_word(record_address+24,gravity);move_word(record_address+12,gnicom+336)
    for index in range(POINTS):
        source=record_address+44+20*index
        for field,destination in ((0,x),(4,z),(8,lsn),(12,sb),(16,sn)):
            move_word(source+field,destination+index*4,field==12)
    code.emit('a1'+struct.pack('<I',record_address+16).hex()+'8d34c5'+struct.pack('<I',options).hex())
    code.emit('bf'+struct.pack('<I',betopt).hex()+'b902000000f3a5')
    code.push(gnicom);code.push(gnicom+168);code.push(gnicom+336);code.call(base+symbols['_grule_']['rva']);code.emit('83c40c')
    arguments=[snflag,record_address,record_address+4,record_address+8,x,z,sb,lsn,record_address+28,sn,naty,yatn,nny,record_address+20,
               betopt,n,ts,ps,area,moment,ns,*sums,ymax,sbsn,qs,ks,8]
    for value in reversed(arguments):code.push(value)
    code.call(base+symbols['_fbasel_']['rva']);code.emit('81c4'+struct.pack('<I',4*len(arguments)).hex())
    code.write(sums[0],64,scratch+12)
    for address in (sbsn,qs,ks):code.write(address,16,scratch+12)
    code.emit('ff0d'+struct.pack('<I',scratch+4).hex())
    code.emit('0f85'+struct.pack('<i',loop-(start+len(code.code)+6)).hex())
    driver=code.finish();later=sorted(item['rva'] for item in symbols.values() if item['type']==32 and item['section']==1 and item['rva']>symbols['_MAIN__']['rva'])
    if len(driver)>later[0]-symbols['_MAIN__']['rva']:raise ValueError('Sinuosity driver exceeds replaceable PROGRAM body.')
    result=bytearray(original);offset=pe.get_offset_from_rva(symbols['_MAIN__']['rva']);result[offset:offset+len(driver)]=driver
    return bytes(result)


def main():
    import pefile
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--output',type=Path,required=True)
    parser.add_argument('--native',type=Path);parser.add_argument('--fixtures',type=Path)
    parser.add_argument('--wine-prefix',type=Path,default=ROOT/'build/wineprefix')
    args=parser.parse_args();output=args.output.resolve()
    if output.exists() or ROOT/'build' not in output.parents:parser.error('Use a new FEQ/build/ directory.')
    output.mkdir(parents=True);original=(ROOT/'originals/feq1061/wrdapp/FEQ_10.61/BIN/fequtl.exe').read_bytes()
    if hashlib.sha256(original).hexdigest()!=ORIGINAL_SHA256:raise ValueError('Recovered executable hash changed.')
    pe=pefile.PE(data=original);symbols={item['name']:item for item in coff_symbols(original)}
    cases=json.loads(args.fixtures.read_text()) if args.fixtures else fixtures()
    if not cases or any(not 2<=len(case['points'])<=POINTS or not 1<=len(case['roughness_modes'])<=SUBSECTIONS or not 1<=case['order']<=21 or case['model'] not in (0,1,2) for case in cases):
        raise ValueError('Invalid sinuosity fixture dimensions or mode.')
    inputs=b''.join(record(case) for case in cases);(output/'inputs.bin').write_bytes(inputs)
    (output/'fixtures.json').write_text(json.dumps(cases,indent=2)+'\n')
    exe=output/'PROBE.EXE';exe.write_bytes(image(original,pe,symbols,len(cases)))
    env=os.environ.copy();env.update(WINEPREFIX=str(args.wine_prefix.resolve()),WINEDEBUG='-all',WINEDLLOVERRIDES='mscoree,mshtml=',MVK_CONFIG_LOG_LEVEL='0')
    command=[str(exe)] if os.name=='nt' else ['wine',str(exe)]
    process=subprocess.run(command,cwd=output,env=env,input=inputs,capture_output=True,timeout=45)
    (output/'stderr.log').write_bytes(process.stderr)
    if process.returncode or len(process.stdout)!=OUTPUT_BYTES*len(cases):
        (output/'error.log').write_bytes(process.stdout+process.stderr)
        raise RuntimeError(f'Original sinuosity driver failed: exit {process.returncode}, {len(process.stdout)} bytes.')
    expected=process.stdout;(output/'outputs.bin').write_bytes(expected)
    manifest=dict(original_sha256=ORIGINAL_SHA256,routines=['_grule_','_fbasel_ (Gaussian sinuosity integrals)'],cases=len(cases),
        input_record_bytes=INPUT_BYTES,output_record_bytes=OUTPUT_BYTES,input_sha256=hashlib.sha256(inputs).hexdigest(),
        output_sha256=hashlib.sha256(expected).hexdigest(),probe_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        fixtures=[dict(name=case['name'],offset=index*OUTPUT_BYTES,bytes=OUTPUT_BYTES) for index,case in enumerate(cases)])
    if args.native:
        native=subprocess.run([str(args.native.resolve())],input=inputs,capture_output=True,timeout=30)
        (output/'native.bin').write_bytes(native.stdout);(output/'native.stderr.log').write_bytes(native.stderr)
        manifest.update(native_sha256=hashlib.sha256(args.native.read_bytes()).hexdigest(),native_returncode=native.returncode,
                        exact_bytes=native.returncode==0 and expected==native.stdout)
    (output/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print(f'{len(cases)} original Gaussian sinuosity cases captured; exact: {manifest.get("exact_bytes","not compared")}.')
    if args.native:raise SystemExit(0 if manifest['exact_bytes'] else 1)

if __name__=='__main__':main()
