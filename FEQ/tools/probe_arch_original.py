#!/usr/bin/env python3
"""Capture RHARCH pipe-arch semi-perimeters from unchanged original FEQUTL code.

Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import struct
import subprocess
from inspect_binary import coff_symbols
from probe_geometry_original import ORIGINAL_SHA256
from probe_profile_original import Driver, ROOT, real


def fixtures():
    import re
    source=ROOT/'originals/feq1061/wrdapp/FEQ_10.61/SRC/FEQUTL/conduit.for'
    text=' '.join(line[6:72] for line in source.read_text().splitlines() if line and line[0] not in 'cC*!')
    cases=[]
    for suffix in ('RC','CM','CMB','CM1','CM1B','SP18','SP31'):
        arrays=[[real(float(v)) for v in re.search(r'\b'+name+r'\s*/([^/]+)/',text).group(1).split(',')] for name in ('RS'+suffix,'SP'+suffix,'R1'+suffix,'R3'+suffix)]
        for conversion in (1.,12.,real(39.37008)):
            for mode in ('rise','span'):
                for fraction in (.013,.37,.67,.99):
                    vector=arrays[0 if mode=='rise' else 1];value=real((vector[0]+fraction*(vector[-1]-vector[0]))/conversion)
                    cases.append(dict(name=f'{suffix}-conversion-{conversion}-{mode}-{fraction}',table=list(map(list,zip(*arrays))),conversion=conversion,
                        rise=value if mode=='rise' else 0.,span=value if mode=='span' else 0.))
                vector=arrays[0 if mode=='rise' else 1]
                for endpoint in (0,-1):
                    for offset in (-.2,-.099,-.001,0.,.001,.099,.2):
                        value=real((vector[endpoint]+offset)/conversion)
                        cases.append(dict(name=f'{suffix}-conversion-{conversion}-{mode}-endpoint-{endpoint}-offset-{offset}',
                            table=list(map(list,zip(*arrays))),conversion=conversion,
                            rise=value if mode=='rise' else 0.,span=value if mode=='span' else 0.))
        if suffix=='CM':
            cases.append(dict(name='culvert-CMPA-rise-3.58-span-5.33',table=list(map(list,zip(*arrays))),conversion=12.,rise=real(3.58),span=real(5.33)))
    return cases


def record(case):
    return struct.pack('<Ifff',len(case['table']),case['conversion'],case['rise'],case['span'])+b''.join(struct.pack('<4f',*row) for row in case['table'])


def image(original,pe,symbols,cases):
    base=pe.OPTIONAL_HEADER.ImageBase;start=base+symbols['_MAIN__']['rva'];scratch=base+symbols['_ftable_']['rva']
    imports={item.name.decode():item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    code=Driver(start,imports);code.emit('fc');code.push(-11);code.api('GetStdHandle');code.emit('89c3')
    for case in cases:
        rows=case['table'];count=len(rows);data=bytearray()
        def put(fmt,*values):
            data.extend(bytes((-len(data))%8));address=scratch+len(data);data.extend(struct.pack(fmt,*values));return address
        stdout=put('<i',99);np=put('<i',count);vectors=[]
        for column in range(4):vectors.append(put('<'+str(count)+'f',*[r[column] for r in rows]))
        conversion=put('<f',case['conversion']);rise=put('<f',case['rise']);span=put('<f',case['span']);error=put('<i',0);nrh=put('<i',0)
        x=put('<23f',*([9000.]*23));y=put('<23f',*([9001.]*23));a=put('<f',9002.);written=put('<i',0)
        code.copy(scratch,data)
        args=[stdout,np,*vectors,conversion,rise,span,error,nrh,x,y,a]
        for value in reversed(args):code.push(value)
        code.call(base+symbols['_rharch_']['rva']);code.emit('83c438')
        for address,size in ((rise,4),(span,4),(error,4),(nrh,4),(a,4),(x,92),(y,92)):code.write(address,size,written)
    driver=code.finish();later=sorted(item['rva'] for item in symbols.values() if item['type']==32 and item['section']==1 and item['rva']>symbols['_MAIN__']['rva'])
    if len(driver)>later[0]-symbols['_MAIN__']['rva']:raise ValueError('Pipe-arch driver exceeds replaceable PROGRAM body.')
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
        if process.returncode or len(process.stdout)!=204*len(batch):
            (output/'error.log').write_bytes(process.stdout+process.stderr)
            raise RuntimeError(f'Original pipe-arch driver failed: exit {process.returncode}, {len(process.stdout)} bytes.')
        cursor=0
        for case in batch:
            size=204;records.append({'name':case['name'],'offset':len(expected),'bytes':size});expected.extend(process.stdout[cursor:cursor+size]);cursor+=size
        print(f'{first+len(batch)}/{len(cases)} original section pipe-arch captured.',flush=True)
    (output/'outputs.bin').write_bytes(expected);manifest={'original_sha256':ORIGINAL_SHA256,'routine':'_rharch_','cases':len(cases),'input_sha256':hashlib.sha256(inputs).hexdigest(),'output_sha256':hashlib.sha256(expected).hexdigest(),'fixtures':records}
    if args.native:
        native=subprocess.run([str(args.native.resolve())],input=inputs,capture_output=True,timeout=30);(output/'native.bin').write_bytes(native.stdout);(output/'native.stderr.log').write_bytes(native.stderr)
        manifest.update(native_sha256=hashlib.sha256(args.native.read_bytes()).hexdigest(),native_returncode=native.returncode,exact_bytes=native.returncode==0 and bytes(expected)==native.stdout)
    (output/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    if args.native:raise SystemExit(0 if manifest['exact_bytes'] else 1)


if __name__=='__main__':main()
