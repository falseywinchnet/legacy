#!/usr/bin/env python3
"""Capture all XLKT22 outputs and check XLKTAL's shared properties.

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
from probe_profile_original import Driver, ROOT, real, ORIGINAL_SHA256 as FEQ_SHA256
from probe_geometry_original import ORIGINAL_SHA256 as UTILITY_SHA256


def fixtures():
    rng=random.Random(106158022);cases=[]
    for table_type in (12,22,25,32,35):
        for scale in (.0001,1.,10000.):
            for zero_depth in (False,True):
                for interval in range(4):
                    y0=0. if zero_depth else real(rng.uniform(.01,10)*scale)
                    y1=real(y0+rng.uniform(.1,3)*scale);y2=real(y1+rng.uniform(.1,3)*scale)
                    rows=[]
                    for y in (y0,y1,y2):
                        rows.append(list(map(real,(y,rng.uniform(.01,100),rng.uniform(.1,1000),
                            rng.uniform(.01,100),rng.uniform(.5,3),rng.uniform(-100,10000),
                            rng.uniform(.5,5),rng.uniform(.001,100000),rng.uniform(-1,100),
                            rng.uniform(-1,1),rng.uniform(-2,2)))))
                    if zero_depth:rows[0][7]=0.
                    for fraction in (0.,.00001,.2,.51,.87,.999999,1.):
                        cases.append(dict(name=f'type-{table_type}-scale-{scale}-zero-{zero_depth}-interval-{interval}-fraction-{fraction}',
                            table_type=table_type,depth=real(y0+fraction*(y1-y0)),rows=rows))
    return cases


def record(case):
    return struct.pack('<If33f',case['table_type'],case['depth'],*[v for row in case['rows'] for v in row])


def image(original,pe,symbols,cases):
    base=pe.OPTIONAL_HEADER.ImageBase;start=base+symbols['_MAIN__']['rva'];table=base+symbols['_ftable_']['rva'];scratch=table+4096
    imports={item.name.decode():item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    code=Driver(start,imports);code.emit('fc');code.push(-11);code.api('GetStdHandle');code.emit('89c3')
    offsets=base+symbols['_offcom_']['rva']
    for table_type in (12,22,25,32,35):code.store(offsets+(table_type-1)*4,13)
    for case in cases:
        table_type=case['table_type'];payload=bytearray(72*4)
        for index,value in ((1,59),(3,table_type),(4,33),(22,8 if table_type in (32,35) else 0)):
            struct.pack_into('<i',payload,index*4,value)
        for row_index,row in enumerate(case['rows']):
            values=row[:8]+row[8:10]+([row[10],431.,.911] if table_type!=35 else [431.,.911,row[10]])
            struct.pack_into('<13f',payload,(33+13*row_index)*4,*values)
        code.copy(table,payload);code.copy(scratch,struct.pack('<If',1,case['depth']))
        for name,count in (('_xlkt22_',11),('_xlktal_',10)):
            args=[scratch,scratch+4]+[scratch+8+4*i for i in range(count)]
            for value in reversed(args):code.push(value)
            code.call(base+symbols[name]['rva']);code.emit('83c4'+bytes([len(args)*4]).hex())
            code.write(scratch+8,4*count,scratch+64)
    driver=code.finish();later=sorted(item['rva'] for item in symbols.values() if item['type']==32 and item['section']==1 and item['rva']>symbols['_MAIN__']['rva'])
    if len(driver)>later[0]-symbols['_MAIN__']['rva']:raise ValueError('Energy section driver exceeds replaceable PROGRAM body.')
    result=bytearray(original);offset=pe.get_offset_from_rva(symbols['_MAIN__']['rva']);result[offset:offset+len(driver)]=driver
    return bytes(result)


def main():
    import pefile
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--output',type=Path,required=True);parser.add_argument('--native',type=Path)
    parser.add_argument('--program',choices=('feq','fequtl'),default='fequtl');parser.add_argument('--fixtures',type=Path)
    parser.add_argument('--wine-prefix',type=Path,default=ROOT/'build/wineprefix');args=parser.parse_args();output=args.output.resolve()
    if output.exists() or ROOT/'build' not in output.parents:parser.error('Use a new FEQ/build/ directory.')
    output.mkdir(parents=True);original=(ROOT/'originals/feq1061/wrdapp/FEQ_10.61/BIN'/(args.program+'.exe')).read_bytes()
    original_hash=FEQ_SHA256 if args.program=='feq' else UTILITY_SHA256
    if hashlib.sha256(original).hexdigest()!=original_hash:raise ValueError('Recovered executable hash changed.')
    pe=pefile.PE(data=original);symbols={item['name']:item for item in coff_symbols(original)};cases=json.loads(args.fixtures.read_text()) if args.fixtures else fixtures();inputs=b''.join(record(case) for case in cases)
    (output/'inputs.bin').write_bytes(inputs);(output/'fixtures.json').write_text(json.dumps(cases,indent=2)+'\n')
    env=os.environ.copy();env.update(WINEPREFIX=str(args.wine_prefix.resolve()),WINEDEBUG='-all',WINEDLLOVERRIDES='mscoree,mshtml=',MVK_CONFIG_LOG_LEVEL='0');expected=bytearray();raw=bytearray();records=[]
    first=0
    while first<len(cases):
        batch=cases[first:first+16]
        while True:
            try:
                payload=image(original,pe,symbols,batch)
                break
            except ValueError as error:
                if str(error)!='Energy section driver exceeds replaceable PROGRAM body.' or len(batch)==1:raise
                batch=batch[:len(batch)//2]
        exe=output/'PROBE.EXE';exe.write_bytes(payload);command=[str(exe)] if os.name=='nt' else ['wine',str(exe)]
        process=subprocess.run(command,cwd=output,env=env,capture_output=True,timeout=30,stdin=subprocess.DEVNULL)
        if process.returncode or len(process.stdout)!=84*len(batch):
            (output/'error.log').write_bytes(process.stdout+process.stderr)
            raise RuntimeError(f'Original energy-section driver failed: exit {process.returncode}, {len(process.stdout)} bytes.')
        raw.extend(process.stdout)
        for index,case in enumerate(batch):
            values=process.stdout[index*84:index*84+44]
            if values[:40]!=process.stdout[index*84+44:index*84+84]:raise ValueError('XLKT22 and XLKTAL disagree on shared properties.')
            records.append({'name':case['name'],'offset':len(expected),'bytes':44});expected.extend(values)
        first+=len(batch);(output/'outputs.partial.bin').write_bytes(expected)
        print(f'{first}/{len(cases)} original energy-section intervals captured.',flush=True)
    (output/'outputs.bin').write_bytes(expected);(output/'original-both-routines.bin').write_bytes(raw)
    manifest={'original_sha256':original_hash,'routines':['_xlkt22_','_xlktal_'],'original_shared_properties_agree':True,'cases':len(cases),
        'input_sha256':hashlib.sha256(inputs).hexdigest(),'output_sha256':hashlib.sha256(expected).hexdigest(),'probe_sha256':hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),'fixtures':records}
    if args.native:
        native=subprocess.run([str(args.native.resolve())],input=inputs,capture_output=True,timeout=30);(output/'native.bin').write_bytes(native.stdout);(output/'native.stderr.log').write_bytes(native.stderr)
        manifest.update(native_sha256=hashlib.sha256(args.native.read_bytes()).hexdigest(),native_returncode=native.returncode,exact_bytes=native.returncode==0 and bytes(expected)==native.stdout)
    (output/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    if args.native:raise SystemExit(0 if manifest['exact_bytes'] else 1)

if __name__=='__main__':main()
