#!/usr/bin/env python3
"""Call original CUTTAB on streamed table records; preserve all table columns.

Only the temporary PROGRAM driver is replaced. The released CUTTAB and startup
execute unchanged instructions. Fixtures are streamed through Win32 ReadFile
and WriteFile, so a single original process handles the complete matrix.
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

ROWS=8
COLUMNS=13
STRIDE=999
RECORD_BYTES=8+4*ROWS*COLUMNS


def adjacent(value,step):
    word=struct.unpack('<I',struct.pack('<f',value))[0]
    return struct.unpack('<f',struct.pack('<I',word+step))[0]


def fixtures():
    rng=random.Random(1061580935);cases=[]
    def add(name,gravity,widths,count=None):
        table=[]
        for column in range(COLUMNS):
            for row in range(ROWS):
                value=(row*.712345+.03123) if column==0 else rng.uniform(.1,1000)
                table.append(real(value))
        for row,value in enumerate(widths):table[ROWS+row]=real(value)
        cases.append(dict(name=name,gravity=real(gravity),count=len(widths) if count is None else count,table=table))
    for gravity in (9.81,adjacent(15.,-1),15.,adjacent(15.,1),32.2):
        limit=real(.07 if gravity>15. else .02134)
        for width in (real(limit*.25),adjacent(limit,-1),limit,adjacent(limit,1)):
            for relative in (0.,.0009999,.001,.0010001,.002):
                for row in (1,2,5,7):
                    widths=[real(10.+i) for i in range(row-1)]+[real(width*(1.+relative)),width]
                    widths += [real(1.+i) for i in range(ROWS-len(widths))]
                    add(f'gravity-{gravity}-width-{width}-delta-{relative}-row-{row}',gravity,widths)
        for widths in ([0.,0.,0.],[.01,0.,.01],[.01,-0.,.01],[.01,.0,.02,.020001],
                       [3.,2.,1.],[.01],[.01,.01],[.01,.01,.01],[0.,.01,.01]):
            add(f'gravity-{gravity}-skip-widths-{widths}',gravity,widths)
        for trial in range(36):
            width=real(rng.uniform(.0001,float(limit)))
            row=1+trial%7
            widths=[real(1.+i) for i in range(row-1)]+[width,real(width*(1.+rng.uniform(-.0009,.0009)))]
            widths += [real(2.+i) for i in range(ROWS-len(widths))]
            add(f'gravity-{gravity}-random-{trial}',gravity,widths)
    return cases


def record(case):
    return struct.pack('<If104f',case['count'],case['gravity'],*case['table'])


def image(original,pe,symbols,count):
    base=pe.OPTIONAL_HEADER.ImageBase;start=base+symbols['_MAIN__']['rva']
    scratch=base+symbols['_ftable_']['rva']+4096
    table=scratch+8192;record_address=scratch+1024
    imports={item.name.decode():item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    code=Driver(start,imports);code.emit('fc')
    code.push(-11);code.api('GetStdHandle');code.emit('89c3')
    code.push(-10);code.api('GetStdHandle');code.emit('a3'+struct.pack('<I',scratch).hex())
    code.store(scratch+4,count)
    loop=start+len(code.code)
    code.push(0);code.push(scratch+8);code.push(RECORD_BYTES);code.push(record_address)
    code.emit('ff35'+struct.pack('<I',scratch).hex());code.api('ReadFile')
    # A short read is a failed capture, never a partially initialized table.
    code.emit('813d'+struct.pack('<II',scratch+8,RECORD_BYTES).hex())
    success_branch=len(code.code);code.emit('0f8400000000')
    code.push(2);code.api('ExitProcess')
    struct.pack_into('<i',code.code,success_branch+2,len(code.code)-(success_branch+6))
    code.emit('a1'+struct.pack('<I',record_address+4).hex()+'a3'+struct.pack('<I',base+symbols['_grvcom_']['rva']).hex())
    def copy_words(source,destination,words):
        code.emit('be'+struct.pack('<I',source).hex()+'bf'+struct.pack('<I',destination).hex()+'b9'+struct.pack('<I',words).hex()+'f3a5')
    for column in range(COLUMNS):copy_words(record_address+8+column*ROWS*4,table+column*STRIDE*4,ROWS)
    code.push(table);code.push(record_address);code.call(base+symbols['_cuttab_']['rva']);code.emit('83c408')
    for column in range(COLUMNS):copy_words(table+column*STRIDE*4,record_address+8+column*ROWS*4,ROWS)
    code.write(record_address,RECORD_BYTES,scratch+12)
    code.emit('ff0d'+struct.pack('<I',scratch+4).hex())
    code.emit('0f85'+struct.pack('<i',loop-(start+len(code.code)+6)).hex())
    driver=code.finish();later=sorted(item['rva'] for item in symbols.values() if item['type']==32 and item['section']==1 and item['rva']>symbols['_MAIN__']['rva'])
    if len(driver)>later[0]-symbols['_MAIN__']['rva']:raise ValueError('Slot driver exceeds replaceable PROGRAM body.')
    result=bytearray(original);offset=pe.get_offset_from_rva(symbols['_MAIN__']['rva']);result[offset:offset+len(driver)]=driver
    return bytes(result)


def main():
    import pefile
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--output',type=Path,required=True)
    parser.add_argument('--native',type=Path);parser.add_argument('--fixtures',type=Path)
    parser.add_argument('--wine-prefix',type=Path,default=ROOT/'build/wineprefix')
    args=parser.parse_args();output=args.output.resolve()
    if output.exists() or ROOT/'build' not in output.parents:parser.error('Use a new FEQ/build/ directory.')
    output.mkdir(parents=True);original=(ROOT/'originals/feq1061/wrdapp/FEQ_10.61/BIN/fequtl.exe').read_bytes()
    if hashlib.sha256(original).hexdigest()!=ORIGINAL_SHA256:raise ValueError('Recovered executable hash changed.')
    pe=pefile.PE(data=original);symbols={item['name']:item for item in coff_symbols(original)}
    cases=json.loads(args.fixtures.read_text()) if args.fixtures else fixtures()
    if not cases or any(case['count']<0 or case['count']>ROWS or len(case['table'])!=ROWS*COLUMNS for case in cases):
        raise ValueError('Invalid slot fixture dimensions.')
    inputs=b''.join(record(case) for case in cases);(output/'inputs.bin').write_bytes(inputs)
    (output/'fixtures.json').write_text(json.dumps(cases,indent=2)+'\n')
    exe=output/'PROBE.EXE';exe.write_bytes(image(original,pe,symbols,len(cases)))
    env=os.environ.copy();env.update(WINEPREFIX=str(args.wine_prefix.resolve()),WINEDEBUG='-all',WINEDLLOVERRIDES='mscoree,mshtml=',MVK_CONFIG_LOG_LEVEL='0')
    command=[str(exe)] if os.name=='nt' else ['wine',str(exe)]
    process=subprocess.run(command,cwd=output,env=env,input=inputs,capture_output=True,timeout=45)
    (output/'stderr.log').write_bytes(process.stderr)
    if process.returncode or len(process.stdout)!=RECORD_BYTES*len(cases):
        (output/'error.log').write_bytes(process.stdout+process.stderr)
        raise RuntimeError(f'Original slot driver failed: exit {process.returncode}, {len(process.stdout)} bytes.')
    expected=process.stdout;(output/'outputs.bin').write_bytes(expected)
    manifest=dict(original_sha256=ORIGINAL_SHA256,routines=['_cuttab_'],cases=len(cases),
        input_record_bytes=RECORD_BYTES,output_record_bytes=RECORD_BYTES,input_sha256=hashlib.sha256(inputs).hexdigest(),
        output_sha256=hashlib.sha256(expected).hexdigest(),probe_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        fixtures=[dict(name=case['name'],offset=index*RECORD_BYTES,bytes=RECORD_BYTES) for index,case in enumerate(cases)])
    if args.native:
        native=subprocess.run([str(args.native.resolve())],input=inputs,capture_output=True,timeout=30)
        (output/'native.bin').write_bytes(native.stdout);(output/'native.stderr.log').write_bytes(native.stderr)
        manifest.update(native_sha256=hashlib.sha256(args.native.read_bytes()).hexdigest(),native_returncode=native.returncode,
                        exact_bytes=native.returncode==0 and expected==native.stdout)
    (output/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print(f'{len(cases)} original CUTTAB cases captured; exact: {manifest.get("exact_bytes","not compared")}.')
    if args.native:raise SystemExit(0 if manifest['exact_bytes'] else 1)

if __name__=='__main__':main()
