#!/usr/bin/env python3
"""Compare section interpolation with both original lookup implementations.

The hash-checked original runs its normal Lahey initialization, then a temporary
PROGRAM driver initializes controlled table intervals and calls XLKT20 and
XXLKT20. All seven binary32 output fields are retained, including signed zeros.
New work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
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
from probe_profile_original import Driver, ORIGINAL_SHA256, ROOT, real
from probe_geometry_original import ORIGINAL_SHA256 as UTILITY_SHA256


def fixtures():
    rng = random.Random(106158020)
    result = []
    for mode in (0,1):
        for scale in (0.0001,1.0,10000.0):
            for interval in range(8):
                y0 = real(rng.uniform(0,10)*scale)
                y1 = real(y0+rng.uniform(0.1,3)*scale)
                lower = [y0,real(rng.uniform(0.01,100)),real(rng.uniform(0.1,1000)),
                         real(rng.uniform(0.01,100)),real(rng.uniform(0.5,3)),
                         real(rng.uniform(-1,100)),real(rng.uniform(-1,1))]
                upper = [y1,real(rng.uniform(0.01,100)),real(rng.uniform(0.1,1000)),
                         real(rng.uniform(0.01,100)),real(rng.uniform(0.5,3)),
                         real(rng.uniform(-1,100)),real(rng.uniform(-1,1))]
                for fraction in (0.0,0.2,0.51,0.87,1.0):
                    result.append({'name':f'mode-{mode}-scale-{scale:g}-interval-{interval}-fraction-{fraction:g}',
                                   'mode':mode,'depth':real(y0+fraction*(y1-y0)),'lower':lower,'upper':upper})
    return result


def record(case):
    return struct.pack('<I15f',case['mode'],case['depth'],*case['lower'],*case['upper'])


def image(original,pe,symbols,cases,program='feq'):
    routines = ('_xlkt20_','_xxlkt20_') if program == 'feq' else ('_xlkt20_',)
    base = pe.OPTIONAL_HEADER.ImageBase
    start = base+symbols['_MAIN__']['rva']
    imports = {item.name.decode():item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    code = Driver(start,imports)
    table = base+symbols['_ftable_']['rva']
    scratch = base+symbols['_matcom2_']['rva'] if program == 'feq' else table+4096
    offvec = base+symbols['_offcom_']['rva']
    code.emit('fc')
    code.push(-11)
    code.api('GetStdHandle')
    code.emit('89c3')
    # A type-20 row uses the first five columns. Derivative mode adds two
    # columns. Both entry points read stride from OFFVEC and slope offset
    # from the table header, allowing the same controlled two-row fixture.
    code.store(offvec+19*4,7)
    for case in cases:
        payload = bytearray(47*4)
        for index,value in ((1,40),(3,20),(4,33),(22,5 if case['mode'] else 0)):
            struct.pack_into('<i',payload,index*4,value)
        struct.pack_into('<7f',payload,33*4,*case['lower'])
        struct.pack_into('<7f',payload,40*4,*case['upper'])
        code.copy(table,payload)
        code.copy(scratch,struct.pack('<If',1,case['depth']))
        for function in routines:
            for address in reversed([scratch,scratch+4]+[scratch+8+i*4 for i in range(7)]):
                code.push(address)
            code.call(base+symbols[function]['rva'])
            code.emit('83c424')
            code.write(scratch+8,28,scratch+36)
    driver = code.finish()
    later = sorted(item['rva'] for item in symbols.values() if item['type']==32 and item['section']==1 and item['rva']>symbols['_MAIN__']['rva'])
    capacity = later[0]-symbols['_MAIN__']['rva']
    if len(driver)>capacity:
        raise ValueError('Section fixture batch exceeds the replaceable PROGRAM body.')
    result = bytearray(original)
    offset = pe.get_offset_from_rva(symbols['_MAIN__']['rva'])
    result[offset:offset+len(driver)] = driver
    return bytes(result)


def main():
    import pefile
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output',type=Path,required=True)
    parser.add_argument('--native',type=Path,required=True)
    parser.add_argument('--program',choices=('feq','fequtl'),default='feq')
    parser.add_argument('--wine-prefix',type=Path,default=ROOT/'build/wineprefix')
    args = parser.parse_args()
    output = args.output.resolve()
    if output.exists() or ROOT/'build' not in output.parents:
        parser.error('Use a new FEQ/build/ directory.')
    output.mkdir(parents=True)
    original = (ROOT/'originals/feq1061/wrdapp/FEQ_10.61/BIN'/(args.program+'.exe')).read_bytes()
    original_sha256 = ORIGINAL_SHA256 if args.program == 'feq' else UTILITY_SHA256
    routines = ['_xlkt20_','_xxlkt20_'] if args.program == 'feq' else ['_xlkt20_']
    record_bytes = 28*len(routines)
    if hashlib.sha256(original).hexdigest()!=original_sha256:
        raise ValueError('The recovered original executable hash changed.')
    pe = pefile.PE(data=original)
    symbols = {item['name']:item for item in coff_symbols(original)}
    cases = fixtures()
    inputs = b''.join(record(case) for case in cases)
    (output/'inputs.bin').write_bytes(inputs)
    env = os.environ.copy()
    env.update(WINEPREFIX=str(args.wine_prefix.resolve()),WINEDEBUG='-all',WINEDLLOVERRIDES='mscoree,mshtml=',MVK_CONFIG_LOG_LEVEL='0')
    expected = bytearray()
    raw = bytearray()
    records = []
    for first in range(0,len(cases),16):
        batch = cases[first:first+16]
        executable = output/'PROBE.EXE'
        executable.write_bytes(image(original,pe,symbols,batch,args.program))
        command = [str(executable)] if os.name=='nt' else ['wine',str(executable)]
        process = subprocess.run(command,cwd=output,env=env,capture_output=True,timeout=30,stdin=subprocess.DEVNULL)
        if process.returncode or len(process.stdout)!=len(batch)*record_bytes:
            (output/'error.log').write_bytes(process.stdout+process.stderr)
            raise RuntimeError(f'Original section driver failed: exit {process.returncode}, {len(process.stdout)} bytes.')
        raw.extend(process.stdout)
        for index,case in enumerate(batch):
            normal = process.stdout[index*record_bytes:index*record_bytes+28]
            fast = process.stdout[index*record_bytes+28:index*record_bytes+56] if len(routines) == 2 else normal
            if normal!=fast:
                raise ValueError('The original lookup routines disagree: '+case['name'])
            records.append({'name':case['name'],'offset':len(expected),'bytes':28,
                            'original_calls_agree':True,'original_calls':len(routines),'sha256':hashlib.sha256(normal).hexdigest()})
            expected.extend(normal)
        print(f'{first+len(batch)}/{len(cases)} original intervals captured.',flush=True)
    (output/'original-both-routines.bin').write_bytes(raw)
    (output/'outputs.bin').write_bytes(expected)
    native = subprocess.run([str(args.native.resolve())],input=inputs,capture_output=True,timeout=30)
    (output/'native.bin').write_bytes(native.stdout)
    (output/'native.stderr.log').write_bytes(native.stderr)
    for item in records:
        start,end = item['offset'],item['offset']+28
        item['exact_bytes'] = native.stdout[start:end]==expected[start:end]
    comparison = {'original_sha256':original_sha256,'routines':routines,
                  'native_sha256':hashlib.sha256(args.native.read_bytes()).hexdigest(),
                  'input_sha256':hashlib.sha256(inputs).hexdigest(),'output_sha256':hashlib.sha256(expected).hexdigest(),
                  'native_returncode':native.returncode,'fixtures':records,
                  'exact_bytes':native.returncode==0 and bytes(expected)==native.stdout}
    (output/'comparison.json').write_text(json.dumps(comparison,indent=2)+'\n')
    (output/'fixtures.json').write_text(json.dumps(cases,indent=2)+'\n')
    print(f'{sum(item["exact_bytes"] for item in records)}/{len(cases)} match every output bit.')
    raise SystemExit(0 if comparison['exact_bytes'] else 1)


if __name__ == '__main__':
    main()
