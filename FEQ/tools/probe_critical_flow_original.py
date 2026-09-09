#!/usr/bin/env python3
"""Capture standalone LKTQC, including zero-depth and following-interval rules.

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
from probe_energy_section_original import fixtures as energy_fixtures, record
from probe_profile_original import Driver, ROOT, ORIGINAL_SHA256 as FEQ_SHA256
from probe_geometry_original import ORIGINAL_SHA256 as UTILITY_SHA256


def image(original,pe,symbols,cases):
    base=pe.OPTIONAL_HEADER.ImageBase;start=base+symbols['_MAIN__']['rva'];table=base+symbols['_ftable_']['rva'];scratch=table+4096
    imports={item.name.decode():item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    code=Driver(start,imports);code.emit('fc');code.push(-11);code.api('GetStdHandle');code.emit('89c3')
    offsets=base+symbols['_offcom_']['rva']
    for table_type in (12,22,25,32,35):code.store(offsets+(table_type-1)*4,13)
    for case in cases:
        payload=bytearray(72*4)
        for index,value in ((1,59),(3,case['table_type']),(4,33),(22,8 if case['table_type'] in (32,35) else 0)):
            struct.pack_into('<i',payload,index*4,value)
        for row_index,row in enumerate(case['rows']):struct.pack_into('<11f',payload,(33+13*row_index)*4,*row)
        code.copy(table,payload);code.copy(scratch,struct.pack('<If',1,case['depth']))
        for address in (scratch+8,scratch+4,scratch):code.push(address)
        code.call(base+symbols['_lktqc_']['rva']);code.emit('83c40c')
        code.write(scratch+8,4,scratch+64)
    driver=code.finish();later=sorted(item['rva'] for item in symbols.values() if item['type']==32 and item['section']==1 and item['rva']>symbols['_MAIN__']['rva'])
    if len(driver)>later[0]-symbols['_MAIN__']['rva']:raise ValueError('Critical-flow driver exceeds replaceable PROGRAM body.')
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
    pe=pefile.PE(data=original);symbols={item['name']:item for item in coff_symbols(original)};cases=json.loads(args.fixtures.read_text()) if args.fixtures else energy_fixtures()
    inputs=b''.join(record(case) for case in cases);(output/'inputs.bin').write_bytes(inputs);(output/'fixtures.json').write_text(json.dumps(cases,indent=2)+'\n')
    env=os.environ.copy();env.update(WINEPREFIX=str(args.wine_prefix.resolve()),WINEDEBUG='-all',WINEDLLOVERRIDES='mscoree,mshtml=',MVK_CONFIG_LOG_LEVEL='0')
    expected=bytearray();records=[];first=0
    while first<len(cases):
        batch=cases[first:first+20]
        while True:
            try:
                payload=image(original,pe,symbols,batch)
                break
            except ValueError as error:
                if str(error)!='Critical-flow driver exceeds replaceable PROGRAM body.' or len(batch)==1:raise
                batch=batch[:len(batch)//2]
        exe=output/'PROBE.EXE';exe.write_bytes(payload);command=[str(exe)] if os.name=='nt' else ['wine',str(exe)]
        process=subprocess.run(command,cwd=output,env=env,capture_output=True,timeout=30,stdin=subprocess.DEVNULL)
        if process.returncode or len(process.stdout)!=4*len(batch):
            (output/'error.log').write_bytes(process.stdout+process.stderr)
            raise RuntimeError(f'Original critical-flow driver failed: exit {process.returncode}, {len(process.stdout)} bytes.')
        for index,case in enumerate(batch):
            records.append(dict(name=case['name'],offset=len(expected),bytes=4));expected.extend(process.stdout[index*4:(index+1)*4])
        first+=len(batch);(output/'outputs.partial.bin').write_bytes(expected)
        print(f'{first}/{len(cases)} original critical-flow cases captured.',flush=True)
    (output/'outputs.bin').write_bytes(expected)
    manifest=dict(original_sha256=original_hash,routines=['_lktqc_'],cases=len(cases),
        input_sha256=hashlib.sha256(inputs).hexdigest(),output_sha256=hashlib.sha256(expected).hexdigest(),
        probe_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),fixtures=records)
    if args.native:
        native=subprocess.run([str(args.native.resolve()),'--critical-flow'],input=inputs,capture_output=True,timeout=30);(output/'native.bin').write_bytes(native.stdout);(output/'native.stderr.log').write_bytes(native.stderr)
        manifest.update(native_sha256=hashlib.sha256(args.native.read_bytes()).hexdigest(),native_returncode=native.returncode,exact_bytes=native.returncode==0 and bytes(expected)==native.stdout)
    (output/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    if args.native:raise SystemExit(0 if manifest['exact_bytes'] else 1)

if __name__=='__main__':main()
