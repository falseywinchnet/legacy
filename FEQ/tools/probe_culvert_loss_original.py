#!/usr/bin/env python3
"""Capture DEGCON and the unmodified RQVSTW head-loss instruction sequence.

The head-loss sequence has absolute addresses, no branches or calls, and is
relocated intact into the temporary driver with callee-saved registers retained.
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

LOSS_START=0x2dbd1
LOSS_END=0x2dc04


def fixtures():
    rng=random.Random(580106124);cases=[]
    for scale in (.0001,1.,10000.):
        for ratio in (.000001,.05,.19999997,.2,.20000003,.7,1.,1.2):
            for coefficient in (.3,.5,.8,.98,1.,1.2):
                for sign in (-1.,1.):
                    a1=real(3.1*scale);area=real(a1*ratio)
                    cases.append(dict(name=f'scale-{scale}-ratio-{ratio}-coefficient-{coefficient}-sign-{sign}',
                        values=list(map(real,(coefficient,a1,area,sign*7.123*scale,64.4)))))
        for trial in range(80):
            a1=real(rng.uniform(.1,100.)*scale);area=real(a1*rng.uniform(.001,1.5))
            cases.append(dict(name=f'random-scale-{scale}-trial-{trial}',values=list(map(real,
                (rng.uniform(.1,1.3),a1,area,rng.uniform(-100,100)*scale,19.62 if trial%2 else 64.4)))))
    return cases


def record(case):return struct.pack('<5f',*case['values'])


def image(original,pe,symbols,cases):
    base=pe.OPTIONAL_HEADER.ImageBase;start=base+symbols['_MAIN__']['rva'];scratch=base+symbols['_ftable_']['rva']+4096
    imports={item.name.decode():item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    code=Driver(start,imports);code.emit('e900000000');loss_entry=start+len(code.code)
    code.emit('5356bb'+struct.pack('<I',scratch+12).hex())
    code.code.extend(pe.get_data(LOSS_START,LOSS_END-LOSS_START))
    code.emit('5e5bc3');struct.pack_into('<i',code.code,1,len(code.code)-5)
    code.emit('fc');code.push(-11);code.api('GetStdHandle');code.emit('89c3')
    for case in cases:
        code.copy(scratch,record(case))
        for address in (scratch+8,scratch+4,scratch):code.push(address)
        code.call(base+symbols['_degcon_']['rva']);code.emit('83c40c')
        code.emit('dd15'+struct.pack('<I',scratch+256).hex())
        code.emit('d91d'+struct.pack('<I',0xf2f2e0).hex())
        code.copy(0xf2f308,struct.pack('<f',case['values'][2]))
        code.copy(0xf4bc34,struct.pack('<f',case['values'][4]))
        code.call(loss_entry)
        code.write(scratch+256,8,scratch+512)
        code.write(0xf2f2e0,4,scratch+512)
        code.write(0x56bb10,4,scratch+512)
    driver=code.finish();later=sorted(item['rva'] for item in symbols.values() if item['type']==32 and item['section']==1 and item['rva']>symbols['_MAIN__']['rva'])
    if len(driver)>later[0]-symbols['_MAIN__']['rva']:raise ValueError('Culvert-loss driver exceeds replaceable PROGRAM body.')
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
                if str(error)!='Culvert-loss driver exceeds replaceable PROGRAM body.' or len(batch)==1:raise
                batch=batch[:len(batch)//2]
        exe=output/'PROBE.EXE';exe.write_bytes(payload);command=[str(exe)] if os.name=='nt' else ['wine',str(exe)]
        process=subprocess.run(command,cwd=output,env=env,capture_output=True,timeout=30,stdin=subprocess.DEVNULL)
        if process.returncode or len(process.stdout)!=16*len(batch):
            (output/'error.log').write_bytes(process.stdout+process.stderr)
            raise RuntimeError(f'Original culvert-loss driver failed: exit {process.returncode}, {len(process.stdout)} bytes.')
        for index,case in enumerate(batch):
            records.append(dict(name=case['name'],offset=len(expected),bytes=16));expected.extend(process.stdout[index*16:(index+1)*16])
        first+=len(batch);(output/'outputs.partial.bin').write_bytes(expected)
        print(f'{first}/{len(cases)} original culvert-loss cases captured.',flush=True)
    (output/'outputs.bin').write_bytes(expected)
    manifest=dict(original_sha256=ORIGINAL_SHA256,routines=['_degcon_'],head_loss_rva_start=hex(LOSS_START),head_loss_rva_end=hex(LOSS_END),
        head_loss_instruction_sha256=hashlib.sha256(pe.get_data(LOSS_START,LOSS_END-LOSS_START)).hexdigest(),cases=len(cases),
        input_sha256=hashlib.sha256(inputs).hexdigest(),output_sha256=hashlib.sha256(expected).hexdigest(),
        probe_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),fixtures=records)
    if args.native:
        native=subprocess.run([str(args.native.resolve())],input=inputs,capture_output=True,timeout=30);(output/'native.bin').write_bytes(native.stdout);(output/'native.stderr.log').write_bytes(native.stderr)
        manifest.update(native_sha256=hashlib.sha256(args.native.read_bytes()).hexdigest(),native_returncode=native.returncode,exact_bytes=native.returncode==0 and bytes(expected)==native.stdout)
    (output/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    if args.native:raise SystemExit(0 if manifest['exact_bytes'] else 1)

if __name__=='__main__':main()
