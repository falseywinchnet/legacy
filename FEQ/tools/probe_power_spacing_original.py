#!/usr/bin/env python3
"""Capture LSTOPF's unchanged arithmetic after its argument-ratio lookup.

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

BLOCK = (0x7f002,0x7f174)
INPUT_BYTES = 24
OUTPUT_BYTES = 2056


def fixtures():
    rng=random.Random(580106151);cases=[]
    for scale in (.0001,1.,10000.):
        for index in range(384):
            first=real(rng.uniform(.001,100)*scale)
            last=real(first*rng.uniform(1.001,1000))
            offset=real(first*rng.uniform(-.99,100))
            ratio=real(1+rng.uniform(.00001,2))
            capacity=(0,1,2,8,64,512)[index%6]
            flag=(-7,0,1,19)[index%4]
            cases.append(dict(name=f'random-scale-{scale}-{index}',fields=[first,last,offset,ratio],capacity=capacity,flag=flag))
    for intervals in (1,2,3,4,7,8,31,32,63,64,127,255,510):
        ratio=real(16.**(1./intervals));bits=struct.unpack('<I',struct.pack('<f',ratio))[0]
        for adjacent in (-1,0,1):
            ratio=struct.unpack('<f',struct.pack('<I',bits+adjacent))[0]
            for capacity in (0,1,2,7,64,512):
                cases.append(dict(name=f'interval-boundary-{intervals}-neighbor-{adjacent}-capacity-{capacity}',
                    fields=[1.,16.,0.,ratio],capacity=capacity,flag=19))
    for offset in (-450.,-1.,0.,1.,450.,1048576.):
        for span in (.00001,.1,1.,10.,1000.):
            for ratio in (1.0001,1.01,1.5,2.,100.):
                # Shift the domain while keeping both shifted bounds positive;
                # float point stores make subtracting the offset observable.
                first=real(max(1.,-offset+1.));last=real(first+span)
                if first==last:continue
                cases.append(dict(name=f'offset-{offset}-span-{span}-ratio-{ratio}',
                    fields=list(map(real,(first,last,offset,ratio))),capacity=512,flag=0))
    return cases


def image(original,pe,symbols,count):
    base=pe.OPTIONAL_HEADER.ImageBase;start=base+symbols['_MAIN__']['rva']
    scratch=base+symbols['_ftable_']['rva']+4096
    record=scratch+2304;frame=scratch+4096;points=scratch+40
    imports={item.name.decode():item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    code=Driver(start,imports);code.emit('fc');code.push(-11);code.api('GetStdHandle');code.emit('89c3')
    code.push(-10);code.api('GetStdHandle');code.emit('a3'+struct.pack('<I',scratch).hex());code.store(scratch+4,count)
    for offset,pointer in ((0x18,record+8),(0x28,record+16),(0x2c,scratch+32),(0x30,points),(0x34,scratch+36)):
        code.store(frame+offset,pointer)
    loop=start+len(code.code)
    code.push(0);code.push(scratch+8);code.push(INPUT_BYTES);code.push(record)
    code.emit('ff35'+struct.pack('<I',scratch).hex());code.api('ReadFile')
    code.emit('813d'+struct.pack('<II',scratch+8,INPUT_BYTES).hex());branch=len(code.code);code.emit('0f8400000000')
    code.push(2);code.api('ExitProcess');struct.pack_into('<i',code.code,branch+2,len(code.code)-(branch+6))
    code.emit('a1'+struct.pack('<I',record+12).hex()+'a3'+struct.pack('<I',0x5a8dbc).hex())
    code.emit('a1'+struct.pack('<I',record+20).hex()+'a3'+struct.pack('<I',scratch+36).hex())
    code.store(scratch+32,-777)
    code.emit('b8'+struct.pack('<f',-7.25).hex()+'bf'+struct.pack('<I',points).hex()+
              'b9'+struct.pack('<I',512).hex()+'f3ab')
    # LSTOPF retains A and B across the preceding table lookup. Its complete
    # arithmetic block expects B at ST(0), A at ST(1), and original stack slots.
    code.emit('5355bd'+struct.pack('<I',frame).hex())
    code.emit('d905'+struct.pack('<I',record).hex()+'d905'+struct.pack('<I',record+4).hex())
    code.code.extend(pe.get_data(BLOCK[0],BLOCK[1]-BLOCK[0]))
    code.emit('5d5b');code.write(scratch+32,OUTPUT_BYTES,scratch+12)
    code.emit('ff0d'+struct.pack('<I',scratch+4).hex())
    code.emit('0f85'+struct.pack('<i',loop-(start+len(code.code)+6)).hex())
    driver=code.finish();later=sorted(item['rva'] for item in symbols.values() if item['type']==32 and item['section']==1 and item['rva']>symbols['_MAIN__']['rva'])
    if len(driver)>later[0]-symbols['_MAIN__']['rva']:raise ValueError('Breakpoint driver exceeds PROGRAM body.')
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
    inputs=b''.join(struct.pack('<4f2i',*case['fields'],case['capacity'],case['flag']) for case in cases)
    (output/'inputs.bin').write_bytes(inputs);(output/'fixtures.json').write_text(json.dumps(cases,indent=2)+'\n')
    exe=output/'PROBE.EXE';exe.write_bytes(image(original,pe,symbols,len(cases)))
    env=os.environ.copy();env.update(WINEPREFIX=str(args.wine_prefix.resolve()),WINEDEBUG='-all',WINEDLLOVERRIDES='mscoree,mshtml=',MVK_CONFIG_LOG_LEVEL='0')
    command=[str(exe)] if os.name=='nt' else ['wine',str(exe)]
    with (output/'inputs.bin').open('rb') as stream:
        process=subprocess.run(command,cwd=output,env=env,stdin=stream,capture_output=True,timeout=60)
    if process.returncode or len(process.stdout)!=OUTPUT_BYTES*len(cases):
        (output/'error.log').write_bytes(process.stdout+process.stderr)
        raise RuntimeError(f'Original breakpoint driver failed: exit {process.returncode}, {len(process.stdout)} bytes.')
    expected=process.stdout;(output/'outputs.bin').write_bytes(expected)
    manifest=dict(original_sha256=ORIGINAL_SHA256,routine='_lstopf_',cases=len(cases),
        instruction_block=dict(rva=f'0x{BLOCK[0]:x}..0x{BLOCK[1]:x}',sha256=hashlib.sha256(pe.get_data(BLOCK[0],BLOCK[1]-BLOCK[0])).hexdigest()),
        input_record_bytes=INPUT_BYTES,output_record_bytes=OUTPUT_BYTES,
        input_sha256=hashlib.sha256(inputs).hexdigest(),output_sha256=hashlib.sha256(expected).hexdigest(),
        probe_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        fixtures=[dict(name=case['name'],offset=index*OUTPUT_BYTES,bytes=OUTPUT_BYTES) for index,case in enumerate(cases)])
    if args.native:
        native=subprocess.run([str(args.native.resolve()),'--power-spacing'],input=inputs,capture_output=True,timeout=30)
        (output/'native.bin').write_bytes(native.stdout);(output/'native.stderr.log').write_bytes(native.stderr)
        manifest.update(native_sha256=hashlib.sha256(args.native.read_bytes()).hexdigest(),native_returncode=native.returncode,
            exact_bytes=native.returncode==0 and expected==native.stdout)
    (output/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print(f'{len(cases)} original breakpoint sequences and capacity decisions captured.',flush=True)
    if args.native:raise SystemExit(0 if manifest['exact_bytes'] else 1)

if __name__=='__main__':main()
