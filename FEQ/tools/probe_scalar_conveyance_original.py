#!/usr/bin/env python3
"""Capture the unchanged FEQUTL 5.80 complete LKTK conveyance lookup.

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


def fixtures():
    rng=random.Random(580106155);cases=[]
    for kind in (1,12,20,21,22,23,24,25,30,31,32,33,34,35):
        for scale in (.0001,1.,10000.):
            for index in range(64):
                lower=real(rng.uniform(-100,100)*scale)
                upper=real(lower+rng.uniform(.001,10)*scale)
                fraction=(0.,1.,.00001,.99999,.1,.3,.5,.8)[index%8]
                depth=real(lower+(upper-lower)*fraction)
                root0=real(rng.uniform(0,10000)*scale) if index%7 else 0.
                root1=real(rng.uniform(0,10000)*scale) if index%11 else 0.
                cases.append(dict(name=f'type-{kind}-scale-{scale}-case-{index}',
                    table_type=kind,fields=[depth,lower,root0,upper,root1]))
    return cases


def image(original,pe,symbols,count):
    base=pe.OPTIONAL_HEADER.ImageBase;start=base+symbols['_MAIN__']['rva']
    scratch=base+symbols['_ftable_']['rva']+4096;record=scratch+128
    imports={item.name.decode():item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    code=Driver(start,imports);code.emit('fc');code.push(-11);code.api('GetStdHandle');code.emit('89c3')
    code.push(-10);code.api('GetStdHandle');code.emit('a3'+struct.pack('<I',scratch).hex())
    code.store(scratch+4,count);code.store(scratch+20,1)
    table=base+symbols['_ftable_']['rva'];offvec=base+symbols['_offcom_']['rva']
    code.store(table+8,1)
    loop=start+len(code.code)
    code.push(0);code.push(scratch+8);code.push(24);code.push(record)
    code.emit('ff35'+struct.pack('<I',scratch).hex());code.api('ReadFile')
    code.emit('813d'+struct.pack('<II',scratch+8,24).hex());branch=len(code.code);code.emit('0f8400000000')
    code.push(2);code.api('ExitProcess');struct.pack_into('<i',code.code,branch+2,len(code.code)-(branch+6))
    # Use the unchanged original OFFCOM stride for the selected table type.
    # Reset the cached interval to row 33, then populate depth and sqrt(K).
    code.store(table+16,33)
    destinations=(table+12,scratch+24,table+33*4,table+36*4)
    for index,destination in enumerate(destinations):
        code.emit('a1'+struct.pack('<I',record+index*4).hex()+'a3'+struct.pack('<I',destination).hex())
    code.emit('a1'+struct.pack('<I',record).hex())
    code.emit('8b0c85'+struct.pack('<I',offvec-4).hex()+'83c121')
    code.emit('890d'+struct.pack('<I',table+4).hex())
    for source,destination in ((record+16,table),(record+20,table+12)):
        code.emit('a1'+struct.pack('<I',source).hex()+'89048d'+struct.pack('<I',destination).hex())
    code.push(scratch+32);code.push(scratch+24);code.push(scratch+20)
    code.call(base+symbols['_lktk_']['rva']);code.emit('83c40c')
    code.write(scratch+32,4,scratch+12)
    code.emit('ff0d'+struct.pack('<I',scratch+4).hex())
    code.emit('0f85'+struct.pack('<i',loop-(start+len(code.code)+6)).hex())
    driver=code.finish();later=sorted(item['rva'] for item in symbols.values() if item['type']==32 and item['section']==1 and item['rva']>symbols['_MAIN__']['rva'])
    if len(driver)>later[0]-symbols['_MAIN__']['rva']:raise ValueError('Scalar conveyance driver exceeds PROGRAM body.')
    result=bytearray(original);offset=pe.get_offset_from_rva(symbols['_MAIN__']['rva']);result[offset:offset+len(driver)]=driver
    return bytes(result)


def main():
    import pefile
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--output',type=Path,required=True)
    parser.add_argument('--native',type=Path);parser.add_argument('--fixtures',type=Path)
    parser.add_argument('--wine-prefix',type=Path,default=ROOT/'build/wineprefix')
    args=parser.parse_args();output=args.output.resolve()
    if output.exists() or ROOT/'build' not in output.parents:parser.error('Use a new FEQ/build/ directory.')
    output.mkdir(parents=True)
    original=(ROOT/'originals/feq1061/wrdapp/FEQ_10.61/BIN/fequtl.exe').read_bytes()
    original_sha256=ORIGINAL_SHA256
    if hashlib.sha256(original).hexdigest()!=original_sha256:raise ValueError('Recovered executable hash changed.')
    pe=pefile.PE(data=original);symbols={item['name']:item for item in coff_symbols(original)}
    cases=json.loads(args.fixtures.read_text()) if args.fixtures else fixtures()
    inputs=b''.join(struct.pack('<I5f',case['table_type'],*case['fields']) for case in cases)
    (output/'inputs.bin').write_bytes(inputs);(output/'fixtures.json').write_text(json.dumps(cases,indent=2)+'\n')
    exe=output/'PROBE.EXE';exe.write_bytes(image(original,pe,symbols,len(cases)))
    env=os.environ.copy();env.update(WINEPREFIX=str(args.wine_prefix.resolve()),WINEDEBUG='-all',WINEDLLOVERRIDES='mscoree,mshtml=',MVK_CONFIG_LOG_LEVEL='0')
    command=[str(exe)] if os.name=='nt' else ['wine',str(exe)]
    with (output/'inputs.bin').open('rb') as stream:
        process=subprocess.run(command,cwd=output,env=env,stdin=stream,capture_output=True,timeout=60)
    if process.returncode or len(process.stdout)!=4*len(cases):
        (output/'error.log').write_bytes(process.stdout+process.stderr)
        raise RuntimeError(f'Original scalar conveyance driver failed: exit {process.returncode}, {len(process.stdout)} bytes.')
    expected=process.stdout;(output/'outputs.bin').write_bytes(expected)
    manifest=dict(original_sha256=original_sha256,program='fequtl',routines=['_lktk_'],cases=len(cases),
        original_rva=hex(symbols['_lktk_']['rva']),
        input_record_bytes=24,output_record_bytes=4,
        input_sha256=hashlib.sha256(inputs).hexdigest(),output_sha256=hashlib.sha256(expected).hexdigest(),
        probe_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        fixtures=[dict(name=case['name'],offset=index*4,bytes=4) for index,case in enumerate(cases)])
    if args.native:
        native=subprocess.run([str(args.native.resolve()),'--scalar-conveyance'],input=inputs,capture_output=True,timeout=30)
        (output/'native.bin').write_bytes(native.stdout);(output/'native.stderr.log').write_bytes(native.stderr)
        manifest.update(native_sha256=hashlib.sha256(args.native.read_bytes()).hexdigest(),native_returncode=native.returncode,
            exact_bytes=native.returncode==0 and expected==native.stdout)
    (output/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print(f'{len(cases)} original FEQUTL scalar conveyance calls captured.',flush=True)
    if args.native:raise SystemExit(0 if manifest['exact_bytes'] else 1)

if __name__=='__main__':main()
