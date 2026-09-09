#!/usr/bin/env python3
"""Capture the unchanged FEQUTL 5.80 FULBAR routine, including road flow.

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
    rng=random.Random(580106152);cases=[]
    for scale in (.001,1.,1000.):
        for index in range(1024):
            area=real(rng.uniform(.1,100)*scale**2)
            a1=real(area*rng.uniform(10,100));a2=real(area*rng.uniform(.5,2))
            a3=real(area*rng.uniform(.5,2));alpha=real(rng.uniform(1,3))
            k2=real(rng.uniform(20,100)*area*scale**(2/3));k1=real(k2*rng.uniform(3,30))
            z3=real(rng.uniform(-1000,1000)*scale)
            z1=real(z3+rng.uniform(.01,30)*scale)
            cd=real((.5,.6,.61,.8,.95,1.)[index%6]);length=real(rng.uniform(.1,100)*scale)
            loss=real(rng.uniform(0,1));g2=real((19.6133,64.348,64.4)[index%3])
            friction=0. if index%5==0 else rng.uniform(.1,100)*scale/(k2*k2)
            numerator=g2*(z1-z3)
            divisor=real(1+cd*cd*((area/a3)**2-1-(alpha-loss)*(area/a1)**2+
                g2*area*area*(length/(k1*k2)+friction)))
            initial=real(cd*area*real((numerator/divisor)**.5))
            road=real(initial*(0.,0.,.00001,.01,.1,.3,.5,1.)[index%8])
            tolerance=real((.000001,.00001,.0001,.001,.01,.1,1.)[(index//8)%7])
            fields=list(map(real,(a1,alpha,k1,z1,a2,k2,a3,cd,area,z3,length,loss,g2,road,tolerance)))
            cases.append(dict(name=f'scale-{scale}-case-{index}',fields=fields,friction=friction))
    return cases


def image(original,pe,symbols,count):
    base=pe.OPTIONAL_HEADER.ImageBase;start=base+symbols['_MAIN__']['rva']
    scratch=base+symbols['_ftable_']['rva']+4096;record=scratch+128
    imports={item.name.decode():item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    code=Driver(start,imports);code.emit('fc');code.push(-11);code.api('GetStdHandle');code.emit('89c3')
    code.push(-10);code.api('GetStdHandle');code.emit('a3'+struct.pack('<I',scratch).hex())
    code.store(scratch+4,count);code.store(scratch+16,6)
    loop=start+len(code.code)
    code.push(0);code.push(scratch+8);code.push(68);code.push(record)
    code.emit('ff35'+struct.pack('<I',scratch).hex());code.api('ReadFile')
    code.emit('813d'+struct.pack('<II',scratch+8,68).hex());branch=len(code.code);code.emit('0f8400000000')
    code.push(2);code.api('ExitProcess');struct.pack_into('<i',code.code,branch+2,len(code.code)-(branch+6))
    destinations=(base+symbols['_appcom_']['rva']+8,base+symbols['_appcom_']['rva']+12,
        base+symbols['_grvcom_']['rva']+4,0xf4bb2c,0x40ef768,
        base+symbols['_culcom_']['rva'],base+symbols['_culcom_']['rva']+4)
    for index,destination in enumerate(destinations):
        code.emit('a1'+struct.pack('<I',record+40+index*4).hex()+'a3'+struct.pack('<I',destination).hex())
    code.push(scratch+36);code.push(scratch+32)
    for index in range(9,-1,-1):code.push(record+4*index)
    code.push(scratch+16);code.call(base+symbols['_fulbar_']['rva']);code.emit('83c434')
    code.write(scratch+32,8,scratch+12)
    code.emit('ff0d'+struct.pack('<I',scratch+4).hex())
    code.emit('0f85'+struct.pack('<i',loop-(start+len(code.code)+6)).hex())
    driver=code.finish();later=sorted(item['rva'] for item in symbols.values() if item['type']==32 and item['section']==1 and item['rva']>symbols['_MAIN__']['rva'])
    if len(driver)>later[0]-symbols['_MAIN__']['rva']:raise ValueError('Full-barrel driver exceeds PROGRAM body.')
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
    cases=json.loads(args.fixtures.read_text()) if args.fixtures else fixtures()
    inputs=b''.join(struct.pack('<15fd',*case['fields'],case['friction']) for case in cases)
    (output/'inputs.bin').write_bytes(inputs);(output/'fixtures.json').write_text(json.dumps(cases,indent=2)+'\n')
    exe=output/'PROBE.EXE';exe.write_bytes(image(original,pe,symbols,len(cases)))
    env=os.environ.copy();env.update(WINEPREFIX=str(args.wine_prefix.resolve()),WINEDEBUG='-all',WINEDLLOVERRIDES='mscoree,mshtml=',MVK_CONFIG_LOG_LEVEL='0')
    command=[str(exe)] if os.name=='nt' else ['wine',str(exe)]
    with (output/'inputs.bin').open('rb') as stream:
        process=subprocess.run(command,cwd=output,env=env,stdin=stream,capture_output=True,timeout=60)
    if process.returncode or len(process.stdout)!=8*len(cases):
        (output/'error.log').write_bytes(process.stdout+process.stderr)
        raise RuntimeError(f'Original full-barrel driver failed: exit {process.returncode}, {len(process.stdout)} bytes.')
    expected=process.stdout;(output/'outputs.bin').write_bytes(expected)
    manifest=dict(original_sha256=ORIGINAL_SHA256,routines=['_fulbar_'],cases=len(cases),
        original_rva='0x25960..0x25b4f',routine_sha256=hashlib.sha256(pe.get_data(0x25960,0x1ef)).hexdigest(),
        input_record_bytes=68,output_record_bytes=8,
        input_sha256=hashlib.sha256(inputs).hexdigest(),output_sha256=hashlib.sha256(expected).hexdigest(),
        probe_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        fixtures=[dict(name=case['name'],offset=index*8,bytes=8) for index,case in enumerate(cases)])
    if args.native:
        native=subprocess.run([str(args.native.resolve()),'--full-barrel'],input=inputs,capture_output=True,timeout=30)
        (output/'native.bin').write_bytes(native.stdout);(output/'native.stderr.log').write_bytes(native.stderr)
        manifest.update(native_sha256=hashlib.sha256(args.native.read_bytes()).hexdigest(),native_returncode=native.returncode,
            exact_bytes=native.returncode==0 and expected==native.stdout)
    (output/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print(f'{len(cases)} original full-barrel calculations captured.',flush=True)
    if args.native:raise SystemExit(0 if manifest['exact_bytes'] else 1)

if __name__=='__main__':main()
