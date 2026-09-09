#!/usr/bin/env python3
"""Call the shipped PROFAC/PROSLV with controlled, bit-exact matrix fixtures.

Only a temporary PROGRAM-entry driver is replaced. The released matrix routines
and Lahey runtime startup execute their original machine instructions. The
preserved executable is hash-checked and never modified.
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

ROOT = Path(__file__).resolve().parents[1]
ORIGINAL_SHA256 = '16e46628e3d55f654e5b39ceecc621bcfcec86a0b881197a6e5f5fd17ec42399'


def real(value):
    return struct.unpack('<f',struct.pack('<f',value))[0]


def fixtures():
    rng = random.Random(1061580)
    result = []
    for scale in (0.0001,1.0,10000.0):
        for count in (1,2,3,5,8,12,20,24):
            matrix = [[real(rng.uniform(-1,1)*scale) for column in range(count)] for row in range(count)]
            for row in range(count):
                matrix[row][row] = real(sum(abs(value) for value in matrix[row])+scale)
            packed = []
            for row in range(count):
                packed.extend(matrix[row][:row])
                packed.extend(matrix[column][row] for column in range(row+1))
            result.append({'name':f'dense-{count}-scale-{scale:g}','n':count,
                'begin':[1],'end':[count],'kind':[1],
                'diagonal':[i*i for i in range(count+1)],
                'lower':[(i+1)*(i+1)-(i+1) for i in range(count)],
                'coefficients':packed,'rhs':[real(rng.uniform(-10,10)*scale) for i in range(count)],'solve':True})
    for count in (1,2,3,7):
        for trial in range(6):
            size = 3+8*count
            result.append({'name':f'branch-blocks-{count}-trial-{trial}','n':1,
                'begin':[1],'end':[4+8*(count-1)],'kind':[2],
                'diagonal':[0,1],'lower':[4],
                'coefficients':[real(rng.uniform(0.125,20.0)) for i in range(size)],
                'rhs':[0.0],'solve':False})
    return result


def record(case):
    blocks = len(case['begin'])
    header = struct.pack('<4I',case['n'],len(case['coefficients']),blocks,int(case['solve']))
    integers = case['begin']+case['end']+case['kind']+case['diagonal']+case['lower']
    numbers = case['coefficients']+case['rhs']
    return header+struct.pack('<'+str(len(integers))+'i',*integers)+struct.pack('<'+str(len(numbers))+'f',*numbers)


class Driver:
    def __init__(self,start,imports):
        self.start,self.imports = start,imports
        self.code = bytearray()
        self.data = bytearray()
        self.references = []

    def emit(self,hexadecimal):
        self.code.extend(bytes.fromhex(hexadecimal))

    def push(self,value):
        self.code.extend(b'\x68'+struct.pack('<I',value & 0xffffffff))

    def api(self,name):
        self.code.extend(b'\xff\x15'+struct.pack('<I',self.imports[name]))

    def call(self,address):
        self.code.extend(b'\xe8'+struct.pack('<i',address-(self.start+len(self.code)+5)))

    def store(self,address,value):
        self.code.extend(b'\xc7\x05'+struct.pack('<II',address,value & 0xffffffff))

    def copy(self,destination,payload):
        offset = len(self.data)
        self.data.extend(payload)
        self.code.extend(b'\xbe') # mov esi, embedded data address
        self.references.append((len(self.code),offset))
        self.code.extend(b'\0'*4)
        self.code.extend(b'\xbf'+struct.pack('<I',destination))
        self.code.extend(b'\xb9'+struct.pack('<I',len(payload)))
        self.emit('f3a4') # rep movsb

    def write(self,address,size,written):
        self.push(0)
        self.push(written)
        self.push(size)
        self.push(address)
        self.emit('53') # saved stdout HANDLE in EBX
        self.api('WriteFile')

    def finish(self):
        self.push(0)
        self.api('ExitProcess')
        for offset,target in self.references:
            struct.pack_into('<I',self.code,offset,self.start+len(self.code)+target)
        return self.code+self.data


def image(original,pe,symbols,case):
    base = pe.OPTIONAL_HEADER.ImageBase
    start = base+symbols['_MAIN__']['rva']
    imports = {item.name.decode():item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    code = Driver(start,imports)
    common = base+symbols['_matcom_']['rva']
    scratch = base+symbols['_matcom2_']['rva']
    # matcom.cmn is INTEGER*4/REAL*4 throughout. These offsets are also
    # independently visible in the original PROFAC absolute operands.
    offsets = {'r':12,'c':12+24800*4,'begin':12+(4*24800+1)*4}
    offsets['end'] = offsets['begin']+4401*4
    offsets['kind'] = offsets['end']+4401*4
    offsets['coefficients'] = offsets['kind']+(4401+16800)*4
    offsets['rhs'] = offsets['coefficients']+744000*4
    code.store(common,len(case['begin']))
    code.store(common+4,case['n'])
    code.store(common+8,len(case['coefficients']))
    code.store(scratch+4,6) # stdout unit used only by an unexpected diagnostic
    for key,source in [('begin','begin'),('end','end'),('kind','kind'),('c','diagonal'),('r','lower'),('coefficients','coefficients'),('rhs','rhs')]:
        values = case[source]
        kind = 'f' if source in ('coefficients','rhs') else 'i'
        code.copy(common+offsets[key],struct.pack('<'+str(len(values))+kind,*values))
    code.push(-11)
    code.api('GetStdHandle')
    code.emit('89c3') # mov ebx,eax
    code.push(scratch+4)
    code.call(base+symbols['_profac_']['rva'])
    code.emit('83c404')
    if case['solve']:
        for address in (common+offsets['rhs'],common+offsets['r'],common+offsets['c'],common+offsets['coefficients'],common+4):
            code.push(address)
        code.call(base+symbols['_proslv_']['rva'])
        code.emit('83c414')
    code.write(common+offsets['coefficients'],len(case['coefficients'])*4,scratch)
    code.write(common+offsets['rhs'],case['n']*4,scratch)
    driver = code.finish()
    routines = sorted(item['rva'] for item in symbols.values() if item['type']==32 and item['section']==1 and item['rva']>symbols['_MAIN__']['rva'])
    capacity = routines[0]-symbols['_MAIN__']['rva']
    if len(driver)>capacity:
        raise ValueError(f'Driver exceeds PROGRAM body: {len(driver)} > {capacity}')
    result = bytearray(original)
    offset = pe.get_offset_from_rva(symbols['_MAIN__']['rva'])
    result[offset:offset+len(driver)] = driver
    return result


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
        raise ValueError('Recovered FEQ executable hash changed.')
    pe = pefile.PE(data=original)
    symbols = {item['name']:item for item in coff_symbols(original)}
    cases = fixtures()
    inputs = b''.join(record(case) for case in cases)
    (output/'inputs.bin').write_bytes(inputs)
    env = os.environ.copy()
    env.update(WINEPREFIX=str(args.wine_prefix.resolve()),WINEDEBUG='-all',WINEDLLOVERRIDES='mscoree,mshtml=',MVK_CONFIG_LOG_LEVEL='0')
    expected = bytearray()
    records = []
    for case in cases:
        (output/'PROBE.EXE').write_bytes(image(original,pe,symbols,case))
        process = subprocess.run(['wine','PROBE.EXE'],cwd=output,env=env,capture_output=True,timeout=30,stdin=subprocess.DEVNULL)
        count = 4*(len(case['coefficients'])+case['n'])
        if process.returncode or len(process.stdout)!=count:
            (output/(case['name']+'.error.log')).write_bytes(process.stdout+process.stderr)
            raise RuntimeError(f'{case["name"]}: unexpected original driver result, exit={process.returncode}, bytes={len(process.stdout)}, expected={count}')
        records.append({'name':case['name'],'offset':len(expected),'bytes':count,'sha256':hashlib.sha256(process.stdout).hexdigest()})
        expected.extend(process.stdout)
    (output/'original.bin').write_bytes(expected)
    native = subprocess.run([str(args.native.resolve())],input=inputs,capture_output=True,timeout=30)
    (output/'native.bin').write_bytes(native.stdout)
    (output/'native.stderr.log').write_bytes(native.stderr)
    for item in records:
        start,end = item['offset'],item['offset']+item['bytes']
        item['exact_bytes'] = expected[start:end] == native.stdout[start:end]
        if not item['exact_bytes']:
            print(item['name']+': DIFFERENT',flush=True)
    result = {'original_sha256':ORIGINAL_SHA256,'native_sha256':hashlib.sha256(args.native.read_bytes()).hexdigest(),
        'wine_version':subprocess.check_output(['wine','--version'],text=True).strip(),
        'native_returncode':native.returncode,'fixtures':records,
        'exact_bytes':native.returncode==0 and bytes(expected)==native.stdout,
        'input_sha256':hashlib.sha256(inputs).hexdigest(),'output_sha256':hashlib.sha256(expected).hexdigest()}
    (output/'comparison.json').write_text(json.dumps(result,indent=2)+'\n')
    (output/'fixtures.json').write_text(json.dumps(cases,indent=2)+'\n')
    print(str(sum(r['exact_bytes'] for r in records))+'/'+str(len(records))+' cases match every output bit.')
    raise SystemExit(0 if result['exact_bytes'] else 1)


if __name__ == '__main__':
    main()
