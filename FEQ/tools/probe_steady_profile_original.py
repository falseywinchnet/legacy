#!/usr/bin/env python3
"""Capture original SFPSBE energy and normal-flow instruction sequences.

Relocated blocks retain every original instruction byte and internal branch.
Only a temporary PROGRAM driver is replaced in a build-directory copy.
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

ENERGY_START=0x26d83
ENERGY_END=0x26daa
NORMAL_START=0x26c5d
NORMAL_END=0x26cb2


def fixtures():
    rng=random.Random(1061580426);cases=[]
    for scale in (.0001,1.,10000.):
        for datum in (0.,1234.5*scale,-987.65*scale):
            for slope in (-1.,-0.,0.,1.e-8,.00013,.05,1.,17.):
                bed=real(datum);level=real(bed+.712345*scale)
                cases.append(dict(name=f'scale-{scale}-datum-{datum}-slope-{slope}',
                    values=list(map(real,(level,bed,3.172*scale,.173*scale,1.237,64.4,slope,137.17*scale)))))
        for trial in range(120):
            bed=real(rng.uniform(-1000,1000)*scale);level=real(bed+rng.uniform(.0001,100)*scale)
            cases.append(dict(name=f'random-scale-{scale}-trial-{trial}',values=list(map(real,
                (level,bed,rng.uniform(-100,100)*scale,rng.uniform(.0001,100)*scale,
                 rng.uniform(.5,3),19.62 if trial%2 else 64.4,rng.uniform(-.001,.1),rng.uniform(.01,1000)*scale)))))
    return cases


def record(case):return struct.pack('<8f',*case['values'])


def image(original,pe,symbols,cases):
    base=pe.OPTIONAL_HEADER.ImageBase;start=base+symbols['_MAIN__']['rva'];scratch=base+symbols['_ftable_']['rva']+4096
    frame=scratch+2048
    imports={item.name.decode():item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    code=Driver(start,imports);code.emit('e900000000');energy_entry=start+len(code.code)
    code.emit('55bd'+struct.pack('<I',frame).hex())
    code.code.extend(pe.get_data(ENERGY_START,ENERGY_END-ENERGY_START))
    code.emit('dbad44ffffff5dc3')
    normal_entry=start+len(code.code);code.emit('55bd'+struct.pack('<I',frame).hex())
    code.code.extend(pe.get_data(NORMAL_START,NORMAL_END-NORMAL_START))
    code.emit('5dc3');struct.pack_into('<i',code.code,1,len(code.code)-5)
    code.emit('fc');code.push(-11);code.api('GetStdHandle');code.emit('89c3')
    for case in cases:
        code.copy(scratch,record(case));code.store(frame-0x174,scratch+8)
        # Initial YR is the wide difference ZDN-ZBR, retained after FST REAL.
        code.emit('d905'+struct.pack('<I',scratch).hex()+'d825'+struct.pack('<I',scratch+4).hex()+
            'db3d'+struct.pack('<I',frame-0x5c).hex())
        for address,index in ((0xe9b2a0,3),(0xe9b2a4,4),(0xf4bc34,5),(0x568888,6),(0xe9b28c,7)):
            code.copy(address,struct.pack('<f',case['values'][index]))
        for entry,index in ((energy_entry,0),(normal_entry,1)):
            code.call(entry);code.emit('dd1d'+struct.pack('<I',scratch+256+8*index).hex())
        code.write(scratch+256,16,scratch+512)
    driver=code.finish();later=sorted(item['rva'] for item in symbols.values() if item['type']==32 and item['section']==1 and item['rva']>symbols['_MAIN__']['rva'])
    if len(driver)>later[0]-symbols['_MAIN__']['rva']:raise ValueError('Steady-profile driver exceeds replaceable PROGRAM body.')
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
        batch=cases[first:first+24]
        while True:
            try:
                payload=image(original,pe,symbols,batch)
                break
            except ValueError as error:
                if str(error)!='Steady-profile driver exceeds replaceable PROGRAM body.' or len(batch)==1:raise
                batch=batch[:len(batch)//2]
        exe=output/'PROBE.EXE';exe.write_bytes(payload);command=[str(exe)] if os.name=='nt' else ['wine',str(exe)]
        process=subprocess.run(command,cwd=output,env=env,capture_output=True,timeout=30,stdin=subprocess.DEVNULL)
        if process.returncode or len(process.stdout)!=16*len(batch):
            (output/'error.log').write_bytes(process.stdout+process.stderr)
            raise RuntimeError(f'Original steady-profile driver failed: exit {process.returncode}, {len(process.stdout)} bytes.')
        for index,case in enumerate(batch):
            records.append(dict(name=case['name'],offset=len(expected),bytes=16));expected.extend(process.stdout[index*16:(index+1)*16])
        first+=len(batch);(output/'outputs.partial.bin').write_bytes(expected)
        print(f'{first}/{len(cases)} original steady-profile cases captured.',flush=True)
    (output/'outputs.bin').write_bytes(expected)
    sequences=[dict(name=name,start_rva=hex(first),end_rva=hex(last),
        sha256=hashlib.sha256(pe.get_data(first,last-first)).hexdigest())
        for name,first,last in (('specific_energy',ENERGY_START,ENERGY_END),('normal_flow',NORMAL_START,NORMAL_END))]
    manifest=dict(original_sha256=ORIGINAL_SHA256,routines=['_sfpsbe_'],instruction_sequences=sequences,cases=len(cases),
        input_sha256=hashlib.sha256(inputs).hexdigest(),output_sha256=hashlib.sha256(expected).hexdigest(),
        probe_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),fixtures=records)
    if args.native:
        native=subprocess.run([str(args.native.resolve()),'--profile'],input=inputs,capture_output=True,timeout=30);(output/'native.bin').write_bytes(native.stdout);(output/'native.stderr.log').write_bytes(native.stderr)
        manifest.update(native_sha256=hashlib.sha256(args.native.read_bytes()).hexdigest(),native_returncode=native.returncode,exact_bytes=native.returncode==0 and bytes(expected)==native.stdout)
    (output/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    if args.native:raise SystemExit(0 if manifest['exact_bytes'] else 1)

if __name__=='__main__':main()
