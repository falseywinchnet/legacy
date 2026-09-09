#!/usr/bin/env python3
"""Capture the unchanged FEQUTL 5.80 RTY7RF momentum balance and residual arithmetic.

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
    rng=random.Random(580106157);cases=[]
    for scale in (.0001,1.,10000.):
        for index in range(1024):
            q=real(rng.uniform(-1000,1000)*scale**2.5) if index%7 else 0.
            beta=real(rng.uniform(.5,3));area=real(rng.uniform(.01,100)*scale**2)
            road=real(rng.uniform(0,10000)*scale**3) if index%2 else 0.
            j=real(rng.uniform(.0001,1000)*scale**3);g=real((9.80665,32.174,32.2)[index%3])
            if index%2:
                beta44=real(rng.uniform(.5,3));q4=real(q*rng.uniform(.1,2))
                area44=real(area*rng.uniform(.1,2));j44=real(j*rng.uniform(.1,2))
            else:
                beta44=beta;q4=real(q*(1+rng.uniform(-1e-5,1e-5)));area44=area;j44=j
            momentum=((q*beta)*q)/area+road+j*g
            force=momentum*rng.uniform(0,1.1) if index%3==0 else 0.
            cases.append(dict(name=f'scale-{scale}-case-{index}',
                fields=[q,beta,area,road,j,g,beta44,q4,area44,j44],force=force))
    return cases


def image(original,pe,symbols,count):
    base=pe.OPTIONAL_HEADER.ImageBase;start=base+symbols['_MAIN__']['rva']
    scratch=base+symbols['_ftable_']['rva']+4096;record=scratch+128
    imports={item.name.decode():item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    code=Driver(start,imports);code.emit('fc');code.push(-11);code.api('GetStdHandle');code.emit('89c3')
    code.push(-10);code.api('GetStdHandle');code.emit('a3'+struct.pack('<I',scratch).hex())
    code.store(scratch+4,count);code.store(scratch+16,6)
    loop=start+len(code.code)
    code.push(0);code.push(scratch+8);code.push(48);code.push(record)
    code.emit('ff35'+struct.pack('<I',scratch).hex());code.api('ReadFile')
    code.emit('813d'+struct.pack('<II',scratch+8,48).hex());branch=len(code.code);code.emit('0f8400000000')
    code.push(2);code.api('ExitProcess');struct.pack_into('<i',code.code,branch+2,len(code.code)-(branch+6))
    destinations=(0xf2f3a4,0xf4bb54,0xf2f3bc,0xf4bb30,0xf2f4c0,0xf4bc30,
                  0xf2f52c,0xf2f564,0xf2f51c,0xf2f520)
    for index,destination in enumerate(destinations):
        code.emit('a1'+struct.pack('<I',record+index*4).hex()+'a3'+struct.pack('<I',destination).hex())
    code.code.extend(pe.get_data(0x1222b,0x32))
    # The original leaves M43 above cached A3 and Q3. Capture M43 wide
    # and remove those two cached values before the second arithmetic block.
    code.emit('dd1d'+struct.pack('<I',scratch+32).hex()+'ddd8ddd8')
    code.emit('55bd'+struct.pack('<I',scratch+768).hex())
    code.emit('dd05'+struct.pack('<I',scratch+32).hex()+'db7de4')
    code.emit('dd05'+struct.pack('<I',record+40).hex()+'db7df0')
    code.code.extend(pe.get_data(0x123ec,0x36))
    code.emit('dd1d'+struct.pack('<I',scratch+40).hex()+'5d')
    code.write(scratch+32,16,scratch+12)
    code.emit('ff0d'+struct.pack('<I',scratch+4).hex())
    code.emit('0f85'+struct.pack('<i',loop-(start+len(code.code)+6)).hex())
    driver=code.finish();later=sorted(item['rva'] for item in symbols.values() if item['type']==32 and item['section']==1 and item['rva']>symbols['_MAIN__']['rva'])
    if len(driver)>later[0]-symbols['_MAIN__']['rva']:raise ValueError('Tailwater momentum driver exceeds PROGRAM body.')
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
    inputs=b''.join(struct.pack('<10fd',*case['fields'],case['force']) for case in cases)
    (output/'inputs.bin').write_bytes(inputs);(output/'fixtures.json').write_text(json.dumps(cases,indent=2)+'\n')
    exe=output/'PROBE.EXE';exe.write_bytes(image(original,pe,symbols,len(cases)))
    env=os.environ.copy();env.update(WINEPREFIX=str(args.wine_prefix.resolve()),WINEDEBUG='-all',WINEDLLOVERRIDES='mscoree,mshtml=',MVK_CONFIG_LOG_LEVEL='0')
    command=[str(exe)] if os.name=='nt' else ['wine',str(exe)]
    with (output/'inputs.bin').open('rb') as stream:
        process=subprocess.run(command,cwd=output,env=env,stdin=stream,capture_output=True,timeout=60)
    if process.returncode or len(process.stdout)!=16*len(cases):
        (output/'error.log').write_bytes(process.stdout+process.stderr)
        raise RuntimeError(f'Original tailwater momentum driver failed: exit {process.returncode}, {len(process.stdout)} bytes.')
    expected=process.stdout;(output/'outputs.bin').write_bytes(expected)
    manifest=dict(original_sha256=ORIGINAL_SHA256,routines=['_rty7rf_'],cases=len(cases),
        original_rva=['0x1222b..0x1225d','0x123ec..0x12422'],
        instruction_sha256=[hashlib.sha256(pe.get_data(rva,length)).hexdigest() for rva,length in ((0x1222b,0x32),(0x123ec,0x36))],
        input_record_bytes=48,output_record_bytes=16,
        input_sha256=hashlib.sha256(inputs).hexdigest(),output_sha256=hashlib.sha256(expected).hexdigest(),
        probe_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        fixtures=[dict(name=case['name'],offset=index*16,bytes=16) for index,case in enumerate(cases)])
    if args.native:
        native=subprocess.run([str(args.native.resolve()),'--tailwater-momentum'],input=inputs,capture_output=True,timeout=30)
        (output/'native.bin').write_bytes(native.stdout);(output/'native.stderr.log').write_bytes(native.stderr)
        manifest.update(native_sha256=hashlib.sha256(args.native.read_bytes()).hexdigest(),native_returncode=native.returncode,
            exact_bytes=native.returncode==0 and expected==native.stdout)
    (output/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print(f'{len(cases)} original momentum balances and tailwater residuals captured.',flush=True)
    if args.native:raise SystemExit(0 if manifest['exact_bytes'] else 1)

if __name__=='__main__':main()
