#!/usr/bin/env python3
"""Capture unchanged UFGATE lip-contact and free-orifice state blocks.

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

BLOCKS = ((0x817a9,0x817ed),(0x822f2,0x82382),(0x80e6c,0x80e9c),
          (0x80ee5,0x80f35),(0x80f76,0x80f88),(0x80ff4,0x8100c))


def fixtures():
    rng=random.Random(580106152);cases=[]
    for scale in (.0001,1.,10000.):
        for index in range(384):
            opening=real(rng.uniform(.001,10)*scale)
            area=real(rng.uniform(.001,100)*scale*scale)
            coefficient=real(rng.uniform(.4,1.2));contraction=real(rng.uniform(.3,1.))
            bottom=real(rng.uniform(-1000,1000)*scale)
            gate_bottom=real(bottom+rng.uniform(-1,1)*scale)
            depth=real(max(0.,gate_bottom-bottom)+opening+rng.uniform(.001,100)*scale)
            alpha=real(rng.uniform(.8,3.))
            ratio=(.000001,.01,.1,.4,.9,.999)[index%6]
            upstream_area=real((area*coefficient)*(alpha**.5)/ratio)
            gravity=real((9.80665,32.174,32.2)[index%3])
            fields=list(map(real,(opening,area,coefficient,contraction,depth,bottom,
                gate_bottom,upstream_area,alpha,2*gravity)))
            cases.append(dict(name=f'random-scale-{scale}-{index}',fields=fields))
    for datum in (-1048576.,-1000.,0.,450.,1000.,1048576.):
        for head in (0.,.00001,.1,.7544864416122437,1.,2.7975,46.58898162841797):
            for coefficient in (.5,.61,1.):
                opening=real(max(.00001,head)*.5)
                fields=list(map(real,(opening,2.7,coefficient,.5,head+opening,
                    datum,datum,27.,1.3,64.4)))
                cases.append(dict(name=f'datum-{datum}-head-{head}-cd-{coefficient}',fields=fields))
    # Inputs at the first differing setup states in the supplied original
    # UTLEXM traces (RSOMY3 record 492 and RSWMY4 record 0).
    for name,depth,area in (('example-orifice',2.531749725341797,3038.099609375),
                            ('example-contact',1.8544864654541016,1952.69189453125)):
        cases.append(dict(name=name,fields=[.5,321.,.9800000190734863,.7411199808120728,
            depth,449.,450.,area,1.,64.4000015258789]))
    for case in cases:
        fields=case['fields'];opening=fields[0];bottom=fields[5]
        fields.extend(map(real,(opening*1.5089728832244873,fields[6],bottom-.1*opening,opening*.93)))
    return cases


def image(original,pe,symbols,count):
    base=pe.OPTIONAL_HEADER.ImageBase;start=base+symbols['_MAIN__']['rva']
    scratch=base+symbols['_ftable_']['rva']+4096;record=scratch+128;frame=scratch+2048
    common=base+symbols['_ufcom_']['rva']
    imports={item.name.decode():item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    code=Driver(start,imports);code.emit('fc');code.push(-11);code.api('GetStdHandle');code.emit('89c3')
    code.push(-10);code.api('GetStdHandle');code.emit('a3'+struct.pack('<I',scratch).hex());code.store(scratch+4,count)
    loop=start+len(code.code)
    code.push(0);code.push(scratch+8);code.push(56);code.push(record)
    code.emit('ff35'+struct.pack('<I',scratch).hex());code.api('ReadFile')
    code.emit('813d'+struct.pack('<II',scratch+8,56).hex());branch=len(code.code);code.emit('0f8400000000')
    code.push(2);code.api('ExitProcess');struct.pack_into('<i',code.code,branch+2,len(code.code)-(branch+6))
    for index,destination in enumerate((common+116,common+120,common+128,common+132,
                                       common+8,common+48,common+52,common+28,common+108,common+140)):
        code.emit('a1'+struct.pack('<I',record+index*4).hex()+'a3'+struct.pack('<I',destination).hex())
    code.emit('55bd'+struct.pack('<I',frame).hex())
    # The contact block begins with the retained upstream surface and saved
    # opening/bottom operands from UFGATE's preceding comparison.
    code.emit('d905'+struct.pack('<I',common+116).hex()+'dbbdf0feffff')
    code.emit('d905'+struct.pack('<I',common+52).hex()+'dbbdfcfeffff')
    code.emit('d905'+struct.pack('<I',common+8).hex()+'d805'+struct.pack('<I',common+48).hex())
    code.code.extend(pe.get_data(BLOCKS[0][0],BLOCKS[0][1]-BLOCKS[0][0]))
    code.emit('a1'+struct.pack('<I',common+152).hex()+'a3'+struct.pack('<I',scratch+32).hex())
    code.code.extend(pe.get_data(BLOCKS[1][0],BLOCKS[1][1]-BLOCKS[1][0]))
    # UFGATE retains Z2B for the following jet-depth calculation; discard
    # that unused value after capturing the complete free-orifice block.
    code.emit('ddd8')
    for index,source in enumerate((common+76,common+12,0x5aa4ec)):
        code.emit('a1'+struct.pack('<I',source).hex()+'a3'+struct.pack('<I',scratch+36+index*4).hex())
    for index,destination in enumerate((0x5aa49c,0x5aa4b0,common+60,0x5aa510)):
        code.emit('a1'+struct.pack('<I',record+40+index*4).hex()+'a3'+struct.pack('<I',destination).hex())
    code.code.extend(pe.get_data(BLOCKS[2][0],BLOCKS[2][1]-BLOCKS[2][0]))
    code.emit('a1'+struct.pack('<I',0x5aa524).hex()+'a3'+struct.pack('<I',scratch+48).hex())
    code.code.extend(pe.get_data(BLOCKS[3][0],BLOCKS[3][1]-BLOCKS[3][0]));code.emit('ddd8')
    code.emit('a1'+struct.pack('<I',common+152).hex()+'a3'+struct.pack('<I',scratch+52).hex())
    code.code.extend(pe.get_data(BLOCKS[4][0],BLOCKS[4][1]-BLOCKS[4][0]))
    code.emit('a1'+struct.pack('<I',0x5aa518).hex()+'a3'+struct.pack('<I',scratch+56).hex())
    code.code.extend(pe.get_data(BLOCKS[5][0],BLOCKS[5][1]-BLOCKS[5][0]))
    code.emit('d91d'+struct.pack('<I',scratch+60).hex()+'5d')
    code.write(scratch+32,32,scratch+12)
    code.emit('ff0d'+struct.pack('<I',scratch+4).hex())
    code.emit('0f85'+struct.pack('<i',loop-(start+len(code.code)+6)).hex())
    driver=code.finish();later=sorted(item['rva'] for item in symbols.values() if item['type']==32 and item['section']==1 and item['rva']>symbols['_MAIN__']['rva'])
    if len(driver)>later[0]-symbols['_MAIN__']['rva']:raise ValueError('Gate state driver exceeds PROGRAM body.')
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
    inputs=b''.join(struct.pack('<14f',*case['fields']) for case in cases)
    (output/'inputs.bin').write_bytes(inputs);(output/'fixtures.json').write_text(json.dumps(cases,indent=2)+'\n')
    exe=output/'PROBE.EXE';exe.write_bytes(image(original,pe,symbols,len(cases)))
    env=os.environ.copy();env.update(WINEPREFIX=str(args.wine_prefix.resolve()),WINEDEBUG='-all',WINEDLLOVERRIDES='mscoree,mshtml=',MVK_CONFIG_LOG_LEVEL='0')
    command=[str(exe)] if os.name=='nt' else ['wine',str(exe)]
    with (output/'inputs.bin').open('rb') as stream:
        process=subprocess.run(command,cwd=output,env=env,stdin=stream,capture_output=True,timeout=60)
    if process.returncode or len(process.stdout)!=32*len(cases):
        (output/'error.log').write_bytes(process.stdout+process.stderr)
        raise RuntimeError(f'Original gate state driver failed: exit {process.returncode}, {len(process.stdout)} bytes.')
    expected=process.stdout;(output/'outputs.bin').write_bytes(expected)
    manifest=dict(original_sha256=ORIGINAL_SHA256,routine='_ufgate_',cases=len(cases),
        instruction_blocks=[dict(rva=f'0x{start:x}..0x{end:x}',sha256=hashlib.sha256(pe.get_data(start,end-start)).hexdigest()) for start,end in BLOCKS],
        input_record_bytes=56,output_record_bytes=32,
        input_sha256=hashlib.sha256(inputs).hexdigest(),output_sha256=hashlib.sha256(expected).hexdigest(),
        probe_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        fixtures=[dict(name=case['name'],offset=index*32,bytes=32) for index,case in enumerate(cases)])
    if args.native:
        native=subprocess.run([str(args.native.resolve()),'--gate-state'],input=inputs,capture_output=True,timeout=30)
        (output/'native.bin').write_bytes(native.stdout);(output/'native.stderr.log').write_bytes(native.stderr)
        manifest.update(native_sha256=hashlib.sha256(args.native.read_bytes()).hexdigest(),native_returncode=native.returncode,
            exact_bytes=native.returncode==0 and expected==native.stdout)
    (output/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print(f'{len(cases)} original gate-contact and free-orifice states captured.',flush=True)
    if args.native:raise SystemExit(0 if manifest['exact_bytes'] else 1)

if __name__=='__main__':main()
