#!/usr/bin/env python3
"""Capture all four unchanged underflow-gate momentum residuals and COMMON stores.

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
from probe_energy_section_original import fixtures as energy_fixtures, record as energy_record

INPUT_BYTES=308
OUTPUT_BYTES=672
ROUTINES=('_rsomy3_','_rswmy3_','_rsomy4_','_rswmy4_')


def fixtures():
    rng=random.Random(580106147);cases=energy_fixtures()
    for index,case in enumerate(cases):
        values=[real(rng.uniform(.1,20)) for unused in range(40)]
        for position in (10,11,12,13):values[position]=real(rng.uniform(-1000,1000))
        values[0]=real(rng.uniform(.1,100))
        values[5]=real(rng.uniform(10,10000))
        values[6]=real(rng.uniform(10,10000))
        values[9]=real(rng.uniform(.01,10000))
        values[17]=real(values[5]*rng.uniform(.01,.3))
        values[25]=real(rng.uniform(.8,2.))
        values[26]=real(rng.uniform(.8,2.))
        values[28]=real(rng.uniform(.1,100))
        values[29]=real(rng.uniform(.1,100))
        values[30]=real(rng.uniform(.3,1.))
        values[31]=real(rng.uniform(.3,1.))
        values[32]=real(9.81 if index%2 else 32.2)
        values[33]=real(2.*values[32])
        values[36]=real(rng.uniform(.1,10000))
        case['common']=values
    return cases


def record(case):
    return energy_record(case)+struct.pack('<II40f',1,1,*case['common'])


def image(original,pe,symbols,count):
    base=pe.OPTIONAL_HEADER.ImageBase;start=base+symbols['_MAIN__']['rva']
    table=base+symbols['_ftable_']['rva'];scratch=table+4096;record_address=scratch+1024
    common=base+symbols['_ufcom_']['rva'];offsets=base+symbols['_offcom_']['rva']
    imports={item.name.decode():item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    code=Driver(start,imports);code.emit('fc');code.push(-11);code.api('GetStdHandle');code.emit('89c3')
    code.push(-10);code.api('GetStdHandle');code.emit('a3'+struct.pack('<I',scratch).hex());code.store(scratch+4,count)
    for table_type in (12,22,25,32,35):code.store(offsets+(table_type-1)*4,13)
    loop=start+len(code.code)
    code.push(0);code.push(scratch+8);code.push(INPUT_BYTES);code.push(record_address)
    code.emit('ff35'+struct.pack('<I',scratch).hex());code.api('ReadFile')
    code.emit('813d'+struct.pack('<II',scratch+8,INPUT_BYTES).hex());branch=len(code.code);code.emit('0f8400000000')
    code.push(2);code.api('ExitProcess');struct.pack_into('<i',code.code,branch+2,len(code.code)-(branch+6))
    payload=bytearray(72*4)
    for index,value in ((1,59),(4,33)):
        struct.pack_into('<i',payload,index*4,value)
    code.copy(table,payload)
    def copy_words(source,destination,count):
        code.emit('be'+struct.pack('<I',source).hex()+'bf'+struct.pack('<I',destination).hex()+
                  'b9'+struct.pack('<I',count).hex()+'f3a5')
    copy_words(record_address,table+12,1)
    code.emit('a1'+struct.pack('<I',record_address).hex()+'83f820')
    cubic_branch=len(code.code);code.emit('0f8400000000')
    code.emit('83f823');linear_branch=len(code.code);code.emit('0f8500000000')
    struct.pack_into('<i',code.code,cubic_branch+2,len(code.code)-(cubic_branch+6))
    code.store(table+22*4,8)
    struct.pack_into('<i',code.code,linear_branch+2,len(code.code)-(linear_branch+6))
    for row in range(3):
        copy_words(record_address+8+row*44,table+(33+row*13)*4,10)
        copy_words(record_address+8+row*44+40,table+(33+row*13+10)*4,1)
        # Type 35 stores ALPHA's derivative after its two sinuosity columns.
        copy_words(record_address+8+row*44+40,table+(33+row*13+12)*4,1)
    for name in ROUTINES:
        copy_words(record_address+140,common,42)
        code.push(record_address+4);code.call(base+symbols[name]['rva']);code.emit('83c404')
        code.emit('dd1d'+struct.pack('<I',scratch+16).hex())
        code.write(scratch+16,8,scratch+12);code.write(common+8,160,scratch+12)
    code.emit('ff0d'+struct.pack('<I',scratch+4).hex())
    code.emit('0f85'+struct.pack('<i',loop-(start+len(code.code)+6)).hex())
    driver=code.finish();later=sorted(item['rva'] for item in symbols.values() if item['type']==32 and item['section']==1 and item['rva']>symbols['_MAIN__']['rva'])
    if len(driver)>later[0]-symbols['_MAIN__']['rva']:raise ValueError('Gate residual driver exceeds PROGRAM body.')
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
    if hashlib.sha256(original).hexdigest()!=ORIGINAL_SHA256:raise ValueError('Recovered executable hash changed.')
    pe=pefile.PE(data=original);symbols={item['name']:item for item in coff_symbols(original)}
    cases=json.loads(args.fixtures.read_text()) if args.fixtures else fixtures();inputs=b''.join(record(case) for case in cases)
    (output/'inputs.bin').write_bytes(inputs);(output/'fixtures.json').write_text(json.dumps(cases,indent=2)+'\n')
    exe=output/'PROBE.EXE';exe.write_bytes(image(original,pe,symbols,len(cases)))
    env=os.environ.copy();env.update(WINEPREFIX=str(args.wine_prefix.resolve()),WINEDEBUG='-all',WINEDLLOVERRIDES='mscoree,mshtml=',MVK_CONFIG_LOG_LEVEL='0')
    command=[str(exe)] if os.name=='nt' else ['wine',str(exe)]
    process=subprocess.run(command,cwd=output,env=env,input=inputs,capture_output=True,timeout=60)
    if process.returncode or len(process.stdout)!=OUTPUT_BYTES*len(cases):
        (output/'error.log').write_bytes(process.stdout+process.stderr)
        raise RuntimeError(f'Original gate residual driver failed: exit {process.returncode}, {len(process.stdout)} bytes.')
    expected=process.stdout;(output/'outputs.bin').write_bytes(expected)
    manifest=dict(original_sha256=ORIGINAL_SHA256,routines=ROUTINES,cases=len(cases),calls=4*len(cases),
        input_record_bytes=INPUT_BYTES,output_record_bytes=OUTPUT_BYTES,
        input_sha256=hashlib.sha256(inputs).hexdigest(),output_sha256=hashlib.sha256(expected).hexdigest(),
        probe_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        fixtures=[dict(name=case['name'],offset=index*OUTPUT_BYTES,bytes=OUTPUT_BYTES) for index,case in enumerate(cases)])
    if args.native:
        native=subprocess.run([str(args.native.resolve()),'--gate'],input=inputs,capture_output=True,timeout=30)
        (output/'native.bin').write_bytes(native.stdout);(output/'native.stderr.log').write_bytes(native.stderr)
        manifest.update(native_sha256=hashlib.sha256(args.native.read_bytes()).hexdigest(),native_returncode=native.returncode,
            exact_bytes=native.returncode==0 and expected==native.stdout)
    (output/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print(f'{len(cases)} gate fixtures, {4*len(cases)} unchanged original residual calls captured.',flush=True)
    if args.native:raise SystemExit(0 if manifest['exact_bytes'] else 1)

if __name__=='__main__':main()
