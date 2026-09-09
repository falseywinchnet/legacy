#!/usr/bin/env python3
"""Verify three function-table interpolation methods against original LKTAB.

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


def fixtures():
    rng = random.Random(1061580234)
    cases = []
    for method in (2,3,4):
        for scale in (0.0001,1.0,100000000.0):
            for interval in range(8):
                x0 = real(rng.uniform(-100,100)*scale)
                x1 = real(x0+rng.uniform(0.1,20)*scale)
                lower = [x0,real(rng.uniform(-1000,1000000)*scale),real(rng.uniform(-10,1000)*scale)]
                upper = [x1,real(rng.uniform(-1000,1000000)*scale),real(rng.uniform(-10,1000)*scale)]
                for fraction in (0.0,0.2,0.51,0.87,1.0):
                    cases.append({'name':f'type-{method}-scale-{scale:g}-interval-{interval}-fraction-{fraction:g}',
                                  'method':method,'argument':real(x0+fraction*(x1-x0)),
                                  'lower':lower,'upper':upper})
    return cases


def image(original,pe,symbols,cases):
    base = pe.OPTIONAL_HEADER.ImageBase
    start = base+symbols['_MAIN__']['rva']
    imports = {item.name.decode():item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    code = Driver(start,imports)
    table = base+symbols['_ftable_']['rva']
    scratch = base+symbols['_matcom2_']['rva']
    code.emit('fc')
    code.push(-11)
    code.api('GetStdHandle')
    code.emit('89c3')
    for case in cases:
        stride = 2 if case['method'] == 2 else 3
        payload = bytearray((23+2*stride)*4)
        for index,value in ((1,23+stride),(2,1234),(3,case['method']),(4,23)):
            struct.pack_into('<i',payload,index*4,value)
        struct.pack_into('<'+str(stride)+'f',payload,23*4,*case['lower'][:stride])
        struct.pack_into('<'+str(stride)+'f',payload,(23+stride)*4,*case['upper'][:stride])
        code.copy(table,payload)
        code.copy(scratch,struct.pack('<IfI',1,case['argument'],0))
        for address in reversed([scratch,scratch+4,scratch+8,scratch+12,scratch+20,scratch+16]):
            code.push(address)
        code.call(base+symbols['_lktab_']['rva'])
        code.emit('83c418')
        code.write(scratch+12,8,scratch+24)
    driver = code.finish()
    later = sorted(item['rva'] for item in symbols.values() if item['type']==32 and item['section']==1 and item['rva']>symbols['_MAIN__']['rva'])
    if len(driver) > later[0]-symbols['_MAIN__']['rva']:
        raise ValueError('Function-table batch exceeds the replaceable PROGRAM body.')
    result = bytearray(original)
    offset = pe.get_offset_from_rva(symbols['_MAIN__']['rva'])
    result[offset:offset+len(driver)] = driver
    return bytes(result)


def main():
    import pefile
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output',type=Path,required=True)
    parser.add_argument('--native',type=Path,required=True)
    parser.add_argument('--wine-prefix',type=Path,default=ROOT/'build/wineprefix')
    args = parser.parse_args()
    output = args.output.resolve()
    if output.exists() or ROOT/'build' not in output.parents:
        parser.error('Use a new FEQ/build/ directory.')
    output.mkdir(parents=True)
    original = (ROOT/'originals/feq1061/wrdapp/FEQ_10.61/BIN/feq.exe').read_bytes()
    if hashlib.sha256(original).hexdigest() != ORIGINAL_SHA256:
        raise ValueError('The recovered original executable hash changed.')
    pe = pefile.PE(data=original)
    symbols = {item['name']:item for item in coff_symbols(original)}
    cases = fixtures()
    inputs = b''.join(struct.pack('<I7f',case['method'],case['argument'],*case['lower'],*case['upper']) for case in cases)
    (output/'inputs.bin').write_bytes(inputs)
    (output/'fixtures.json').write_text(json.dumps(cases,indent=2)+'\n')
    env = os.environ.copy()
    env.update(WINEPREFIX=str(args.wine_prefix.resolve()),WINEDEBUG='-all',WINEDLLOVERRIDES='mscoree,mshtml=',MVK_CONFIG_LOG_LEVEL='0')
    expected = bytearray()
    records = []
    for first in range(0,len(cases),32):
        batch = cases[first:first+32]
        executable = output/'PROBE.EXE'
        executable.write_bytes(image(original,pe,symbols,batch))
        command = [str(executable)] if os.name == 'nt' else ['wine',str(executable)]
        process = subprocess.run(command,cwd=output,env=env,capture_output=True,timeout=30,stdin=subprocess.DEVNULL)
        if process.returncode or len(process.stdout) != len(batch)*8:
            (output/'error.log').write_bytes(process.stdout+process.stderr)
            raise RuntimeError(f'Original LKTAB driver failed: exit {process.returncode}, {len(process.stdout)} bytes.')
        for index,case in enumerate(batch):
            value = process.stdout[index*8:index*8+8]
            records.append({'name':case['name'],'offset':len(expected),'bytes':8,'sha256':hashlib.sha256(value).hexdigest()})
            expected.extend(value)
        print(f'{first+len(batch)}/{len(cases)} original function-table intervals captured.',flush=True)
    (output/'outputs.bin').write_bytes(expected)
    native = subprocess.run([str(args.native.resolve())],input=inputs,capture_output=True,timeout=30)
    (output/'native.bin').write_bytes(native.stdout)
    (output/'native.stderr.log').write_bytes(native.stderr)
    for item in records:
        start,end = item['offset'],item['offset']+8
        item['exact_bytes'] = native.stdout[start:end] == expected[start:end]
    comparison = {'original_sha256':ORIGINAL_SHA256,'routine':'_lktab_',
                  'native_sha256':hashlib.sha256(args.native.read_bytes()).hexdigest(),
                  'input_sha256':hashlib.sha256(inputs).hexdigest(),'output_sha256':hashlib.sha256(expected).hexdigest(),
                  'native_returncode':native.returncode,'fixtures':records,
                  'exact_bytes':native.returncode == 0 and bytes(expected) == native.stdout}
    (output/'comparison.json').write_text(json.dumps(comparison,indent=2)+'\n')
    print(f'{sum(item["exact_bytes"] for item in records)}/{len(cases)} match every output bit.')
    raise SystemExit(0 if comparison['exact_bytes'] else 1)


if __name__ == '__main__':
    main()
