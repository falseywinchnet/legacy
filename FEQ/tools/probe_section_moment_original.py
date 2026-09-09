#!/usr/bin/env python3
"""Capture XLKT21 first moments and cross-check its base properties with XLKT20.

The unchanged original routines receive controlled type-21/31 table rows.
Every output word is retained; a floating-point tolerance is never applied.
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
from probe_profile_original import Driver, ORIGINAL_SHA256, ROOT, real
from probe_geometry_original import ORIGINAL_SHA256 as UTILITY_SHA256
from probe_section_original import fixtures, record


def image(original, pe, symbols, cases, program='feq'):
    base = pe.OPTIONAL_HEADER.ImageBase
    start = base+symbols['_MAIN__']['rva']
    imports = {item.name.decode():item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    code = Driver(start, imports)
    table = base+symbols['_ftable_']['rva']
    scratch = base+symbols['_matcom2_']['rva'] if program == 'feq' else table+4096
    offvec = base+symbols['_offcom_']['rva']
    code.emit('fc')
    code.push(-11)
    code.api('GetStdHandle')
    code.emit('89c3')
    code.store(offvec+20*4, 8)
    code.store(offvec+30*4, 8)
    for case in cases:
        payload = bytearray(49*4)
        for index, value in ((1,41), (3,31 if case['mode'] else 21), (4,33), (22,6 if case['mode'] else 0)):
            struct.pack_into('<i', payload, index*4, value)
        for name, offset in (('lower',33), ('upper',41)):
            row = case[name]
            struct.pack_into('<8f', payload, offset*4, *row[:5], case[name+'_moment'], *row[5:])
        code.copy(table, payload)
        code.copy(scratch, struct.pack('<If',1,case['depth']))
        # Scratch output order: A,T,DT,K,DK,B,DB,J. XLKT21's J argument
        # occurs between DT and K, so pass the corresponding explicit address.
        outputs = [scratch+8+i*4 for i in range(8)]
        for function in ('_xlkt20_', '_xlkt21_'):
            addresses = [scratch,scratch+4]+(outputs[:7] if function == '_xlkt20_' else
                                            outputs[:3]+[outputs[7]]+outputs[3:7])
            for address in reversed(addresses):
                code.push(address)
            code.call(base+symbols[function]['rva'])
            code.emit('83c4'+f'{len(addresses)*4:02x}')
            code.write(scratch+8,28 if function == '_xlkt20_' else 32,scratch+40)
    driver = code.finish()
    later = sorted(item['rva'] for item in symbols.values() if item['type']==32 and item['section']==1 and item['rva']>symbols['_MAIN__']['rva'])
    if len(driver) > later[0]-symbols['_MAIN__']['rva']:
        raise ValueError('First-moment batch exceeds the replaceable PROGRAM body.')
    result = bytearray(original)
    offset = pe.get_offset_from_rva(symbols['_MAIN__']['rva'])
    result[offset:offset+len(driver)] = driver
    return bytes(result)


def main():
    import pefile
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--native', type=Path, required=True)
    parser.add_argument('--program', choices=('feq','fequtl'), default='feq')
    parser.add_argument('--wine-prefix', type=Path, default=ROOT/'build/wineprefix')
    args = parser.parse_args()
    output = args.output.resolve()
    if output.exists() or ROOT/'build' not in output.parents:
        parser.error('Use a new FEQ/build/ directory.')
    output.mkdir(parents=True)
    original = (ROOT/'originals/feq1061/wrdapp/FEQ_10.61/BIN'/(args.program+'.exe')).read_bytes()
    original_sha256 = ORIGINAL_SHA256 if args.program == 'feq' else UTILITY_SHA256
    if hashlib.sha256(original).hexdigest() != original_sha256:
        raise ValueError('The recovered original executable hash changed.')
    pe = pefile.PE(data=original)
    symbols = {item['name']:item for item in coff_symbols(original)}
    cases = fixtures()
    rng = random.Random(106158021)
    for case in cases:
        case['lower_moment'] = real(rng.uniform(-100,10000))
        case['upper_moment'] = real(rng.uniform(-100,10000))
    inputs = b''.join(record(case)+struct.pack('<2f',case['lower_moment'],case['upper_moment']) for case in cases)
    (output/'inputs.bin').write_bytes(inputs)
    (output/'fixtures.json').write_text(json.dumps(cases,indent=2)+'\n')
    env = os.environ.copy()
    env.update(WINEPREFIX=str(args.wine_prefix.resolve()), WINEDEBUG='-all', WINEDLLOVERRIDES='mscoree,mshtml=', MVK_CONFIG_LOG_LEVEL='0')
    expected = bytearray()
    raw = bytearray()
    records = []
    for first in range(0,len(cases),16):
        batch = cases[first:first+16]
        executable = output/'PROBE.EXE'
        executable.write_bytes(image(original,pe,symbols,batch,args.program))
        command = [str(executable)] if os.name == 'nt' else ['wine',str(executable)]
        process = subprocess.run(command,cwd=output,env=env,capture_output=True,timeout=30,stdin=subprocess.DEVNULL)
        if process.returncode or len(process.stdout) != len(batch)*60:
            (output/'error.log').write_bytes(process.stdout+process.stderr)
            raise RuntimeError(f'Original first-moment driver failed: exit {process.returncode}, {len(process.stdout)} bytes.')
        raw.extend(process.stdout)
        for index,case in enumerate(batch):
            base_values = process.stdout[index*60:index*60+28]
            moment_values = process.stdout[index*60+28:index*60+60]
            if base_values != moment_values[:28]:
                raise ValueError('Original XLKT20 and XLKT21 disagree on a shared property: '+case['name'])
            records.append({'name':case['name'],'offset':len(expected),'bytes':32,
                            'original_shared_properties_agree':True,'sha256':hashlib.sha256(moment_values).hexdigest()})
            expected.extend(moment_values)
        print(f'{first+len(batch)}/{len(cases)} original first-moment intervals captured.',flush=True)
    (output/'original-both-routines.bin').write_bytes(raw)
    (output/'outputs.bin').write_bytes(expected)
    native = subprocess.run([str(args.native.resolve()),'--first-moment'],input=inputs,capture_output=True,timeout=30)
    (output/'native.bin').write_bytes(native.stdout)
    (output/'native.stderr.log').write_bytes(native.stderr)
    for item in records:
        start,end = item['offset'],item['offset']+32
        item['exact_bytes'] = native.stdout[start:end] == expected[start:end]
    comparison = {'original_sha256':original_sha256,'routines':['_xlkt20_','_xlkt21_'],
                  'native_sha256':hashlib.sha256(args.native.read_bytes()).hexdigest(),
                  'input_sha256':hashlib.sha256(inputs).hexdigest(),'output_sha256':hashlib.sha256(expected).hexdigest(),
                  'native_returncode':native.returncode,'fixtures':records,
                  'exact_bytes':native.returncode == 0 and bytes(expected) == native.stdout}
    (output/'comparison.json').write_text(json.dumps(comparison,indent=2)+'\n')
    print(f'{sum(item["exact_bytes"] for item in records)}/{len(cases)} match every output bit.')
    raise SystemExit(0 if comparison['exact_bytes'] else 1)


if __name__ == '__main__':
    main()
