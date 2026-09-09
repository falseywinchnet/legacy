#!/usr/bin/env python3
"""Capture STOTHQ results with the unchanged original FEQUTL routine.

The driver replaces only a disposable PROGRAM body, preserving original runtime
startup. Each batch uses three linear coefficient tables and a bounded machine
code loop. The committed inputs include original-model calls and coefficient
boundary cases. No original numerical routine is patched.
Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
"""
import argparse
import hashlib
import json
import os
import struct
import subprocess
from pathlib import Path
from inspect_binary import coff_symbols
from probe_geometry_original import ORIGINAL_SHA256
from probe_profile_original import Driver,ROOT

def encode(fixtures):
    data=struct.pack('<2f',*fixtures['gravity'])
    for table in fixtures['tables']:
        data+=struct.pack('<I',len(table))+b''.join(struct.pack('<2f',*r) for r in table)
    return data+b''.join(struct.pack('<7f',*c['values']) for c in fixtures['cases'])

def image(original,pe,symbols,fixtures,cases):
    base=pe.OPTIONAL_HEADER.ImageBase;start=base+symbols['_MAIN__']['rva'];bank=base+symbols['_ftable_']['rva'];scratch=bank+20000
    imports={i.name.decode():i.address for d in pe.DIRECTORY_ENTRY_IMPORT for i in d.imports if i.name};code=Driver(start,imports)
    code.emit('fc');code.push(-11);code.api('GetStdHandle');code.emit('89c3')
    ids=[1,101,201]
    if len(fixtures['tables'])!=3 or any(not 2<=len(rows)<=39 for rows in fixtures['tables']):
        raise ValueError('Expected three bounded linear coefficient tables.')
    for ptr,rows in zip(ids,fixtures['tables']):
        size=22+2*len(rows);data=bytearray(size*4)
        struct.pack_into('<4i',data,0,ptr+size-2,ptr,2,ptr+22)
        for i,row in enumerate(rows):struct.pack_into('<2f',data,(22+2*i)*4,*row)
        code.copy(bank+ptr*4,data)
    code.copy(base+symbols['_grvcom_']['rva'],struct.pack('<2f',*fixtures['gravity']))
    values=scratch+128
    code.copy(scratch,struct.pack('<3iI',*ids,0))
    code.copy(values,b''.join(struct.pack('<7f',*c['values']) for c in cases))
    code.emit('be');code.code.extend(struct.pack('<I',values))
    code.emit('bf');code.code.extend(struct.pack('<I',len(cases)))
    loop=len(code.code)
    # ESI points to seven mutable REAL arguments; EDI counts records. The
    # original routine preserves both registers and the stdout handle in EBX.
    for i in reversed(range(7)):
        code.emit('8d46');code.code.append(i*4);code.emit('50')
    for i in reversed(range(3)):code.push(scratch+4*i)
    code.call(base+symbols['_stothq_']['rva']);code.emit('83c428')
    code.push(0);code.push(scratch+12);code.push(8);code.emit('8d46145053');code.api('WriteFile')
    code.emit('83c61c4f0f85');code.code.extend(struct.pack('<i',loop-(len(code.code)+4)))
    driver=code.finish();later=sorted(i['rva'] for i in symbols.values() if i['type']==32 and i['section']==1 and i['rva']>symbols['_MAIN__']['rva'])
    if len(driver)>later[0]-symbols['_MAIN__']['rva']:raise ValueError(f'Weir driver {len(driver)} exceeds PROGRAM {later[0]-symbols["_MAIN__"]["rva"]}.')
    result=bytearray(original);off=pe.get_offset_from_rva(symbols['_MAIN__']['rva']);result[off:off+len(driver)]=driver;return bytes(result)

def main():
    import pefile
    p=argparse.ArgumentParser();p.add_argument('--fixtures',type=Path,default=ROOT/'tests/reference/weir_flow/fixtures.json');p.add_argument('--output',type=Path,required=True);p.add_argument('--native',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
    if out.exists() or ROOT/'build' not in out.parents:p.error('Use a new FEQ/build directory.')
    out.mkdir(parents=True);orig=(ROOT/'originals/feq1061/wrdapp/FEQ_10.61/BIN/fequtl.exe').read_bytes()
    if hashlib.sha256(orig).hexdigest()!=ORIGINAL_SHA256:raise ValueError('Recovered original executable hash changed.')
    pe=pefile.PE(data=orig);symbols={i['name']:i for i in coff_symbols(orig)};f=json.loads(a.fixtures.read_text());data=encode(f);(out/'inputs.bin').write_bytes(data);(out/'fixtures.json').write_text(json.dumps(f,indent=2)+'\n');expected=bytearray();records=[]
    env=os.environ.copy();env.update(WINEPREFIX=str(ROOT/'build/wineprefix'),WINEDEBUG='-all',WINEDLLOVERRIDES='mscoree,mshtml=',MVK_CONFIG_LOG_LEVEL='0')
    for first in range(0,len(f['cases']),128):
        batch=f['cases'][first:first+128];exe=out/'PROBE.EXE';exe.write_bytes(image(orig,pe,symbols,f,batch));command=[str(exe)] if os.name=='nt' else ['wine',str(exe)];r=subprocess.run(command,cwd=out,env=env,capture_output=True,timeout=30,stdin=subprocess.DEVNULL)
        if r.returncode or len(r.stdout)!=8*len(batch):
            (out/'error.log').write_bytes(r.stdout+r.stderr);raise RuntimeError(f'Original weir call failed: {r.returncode}, {len(r.stdout)} bytes.')
        for i,c in enumerate(batch):records.append({'name':c['name'],'offset':len(expected)+8*i,'bytes':8})
        expected+=r.stdout;print(f'{first+len(batch)}/{len(f["cases"])} captured.',flush=True)
    (out/'outputs.bin').write_bytes(expected);native=subprocess.run([str(a.native.resolve())],input=data,capture_output=True);(out/'native.bin').write_bytes(native.stdout);(out/'native.stderr.log').write_bytes(native.stderr)
    manifest={'original_sha256':ORIGINAL_SHA256,'routine':'_stothq_','cases':len(records),'fixtures':records,'input_sha256':hashlib.sha256(data).hexdigest(),'output_sha256':hashlib.sha256(expected).hexdigest(),'native_sha256':hashlib.sha256(a.native.read_bytes()).hexdigest(),'native_returncode':native.returncode,'exact_bytes':native.returncode==0 and expected==native.stdout}
    (out/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n');raise SystemExit(0 if manifest['exact_bytes'] else 1)
if __name__=='__main__':main()
