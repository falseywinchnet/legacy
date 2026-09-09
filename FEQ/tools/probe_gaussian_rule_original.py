#!/usr/bin/env python3
"""Capture original GRULE/IMTQL2 nodes and weights for every supported order.

The preserved executable is hash-checked. Only a temporary PROGRAM driver is
replaced; original runtime startup and both numerical routines execute normally.
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
from probe_profile_original import Driver, ROOT
from probe_geometry_original import ORIGINAL_SHA256


def image(original,pe,symbols,maximum):
    base=pe.OPTIONAL_HEADER.ImageBase;start=base+symbols['_MAIN__']['rva']
    scratch=base+symbols['_ftable_']['rva']+4096
    nodes=scratch+4096;weights=scratch+8192
    imports={item.name.decode():item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    code=Driver(start,imports);code.emit('fc');code.push(-11);code.api('GetStdHandle');code.emit('89c3')
    code.store(scratch,1);loop=start+len(code.code)
    code.push(weights);code.push(nodes);code.push(scratch);code.call(base+symbols['_grule_']['rva']);code.emit('83c40c')
    for address in (nodes,weights):
        code.push(0);code.push(scratch+4)
        code.emit('a1'+struct.pack('<I',scratch).hex()+'c1e00350')
        code.push(address);code.emit('53');code.api('WriteFile')
    code.emit('ff05'+struct.pack('<I',scratch).hex())
    code.emit('813d'+struct.pack('<II',scratch,maximum+1).hex())
    code.emit('0f8c'+struct.pack('<i',loop-(start+len(code.code)+6)).hex())
    driver=code.finish();later=sorted(item['rva'] for item in symbols.values() if item['type']==32 and item['section']==1 and item['rva']>symbols['_MAIN__']['rva'])
    if len(driver)>later[0]-symbols['_MAIN__']['rva']:raise ValueError('Gaussian driver exceeds replaceable PROGRAM body.')
    result=bytearray(original);offset=pe.get_offset_from_rva(symbols['_MAIN__']['rva']);result[offset:offset+len(driver)]=driver
    return bytes(result)


def main():
    import pefile
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--output',type=Path,required=True)
    parser.add_argument('--native',type=Path);parser.add_argument('--maximum',type=int,default=256)
    parser.add_argument('--wine-prefix',type=Path,default=ROOT/'build/wineprefix')
    args=parser.parse_args();output=args.output.resolve()
    if output.exists() or ROOT/'build' not in output.parents:parser.error('Use a new FEQ/build/ directory.')
    if not 1<=args.maximum<=256:parser.error('The original GRULE scratch array supports orders 1 through 256.')
    output.mkdir(parents=True);original=(ROOT/'originals/feq1061/wrdapp/FEQ_10.61/BIN/fequtl.exe').read_bytes()
    if hashlib.sha256(original).hexdigest()!=ORIGINAL_SHA256:raise ValueError('Recovered executable hash changed.')
    pe=pefile.PE(data=original);symbols={item['name']:item for item in coff_symbols(original)}
    inputs=struct.pack('<'+str(args.maximum)+'I',*range(1,args.maximum+1));(output/'inputs.bin').write_bytes(inputs)
    exe=output/'PROBE.EXE';exe.write_bytes(image(original,pe,symbols,args.maximum))
    env=os.environ.copy();env.update(WINEPREFIX=str(args.wine_prefix.resolve()),WINEDEBUG='-all',WINEDLLOVERRIDES='mscoree,mshtml=',MVK_CONFIG_LOG_LEVEL='0')
    command=[str(exe)] if os.name=='nt' else ['wine',str(exe)]
    process=subprocess.run(command,cwd=output,env=env,capture_output=True,timeout=45,stdin=subprocess.DEVNULL)
    (output/'stderr.log').write_bytes(process.stderr)
    if process.returncode or len(process.stdout)!=8*args.maximum*(args.maximum+1):
        (output/'error.log').write_bytes(process.stdout+process.stderr)
        raise RuntimeError(f'Original Gaussian driver failed: exit {process.returncode}, {len(process.stdout)} bytes.')
    expected=process.stdout;(output/'outputs.bin').write_bytes(expected)
    manifest=dict(original_sha256=ORIGINAL_SHA256,routines=['_grule_','_imtql2_'],cases=args.maximum,
        input_sha256=hashlib.sha256(inputs).hexdigest(),output_sha256=hashlib.sha256(expected).hexdigest(),
        probe_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        fixtures=[dict(order=n,offset=8*(n-1)*n,bytes=16*n) for n in range(1,args.maximum+1)])
    if args.native:
        native=subprocess.run([str(args.native.resolve())],input=inputs,capture_output=True,timeout=30)
        (output/'native.bin').write_bytes(native.stdout);(output/'native.stderr.log').write_bytes(native.stderr)
        manifest.update(native_sha256=hashlib.sha256(args.native.read_bytes()).hexdigest(),native_returncode=native.returncode,
                        exact_bytes=native.returncode==0 and expected==native.stdout)
    (output/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print(f'{args.maximum} original Gaussian rules captured; exact: {manifest.get("exact_bytes","not compared")}.')
    if args.native:raise SystemExit(0 if manifest['exact_bytes'] else 1)

if __name__=='__main__':main()
