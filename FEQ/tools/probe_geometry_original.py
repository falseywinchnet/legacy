#!/usr/bin/env python3
"""Verify section geometry against unchanged FEQUTL FBASEL machine code.

New work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
The controlled calls use OLDBETA and no sinuosity; fixed and depth-dependent
roughness modes are included.
The output record includes all mixed-precision geometric accumulation words.
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

ORIGINAL_SHA256 = '031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2'


def fixtures():
    rng = random.Random(58010612500)
    cases = []
    for scale in (0.001,1.0,1000.0):
        for trial in range(16):
            count = rng.randrange(3,12)
            subsections = rng.randrange(1,5)
            offset = real(rng.uniform(-1000,1000)*scale)
            datum = real(rng.uniform(-200,200)*scale)
            points = []
            for index in range(count):
                offset = real(offset+rng.uniform(0.1,30)*scale)
                elevation = real(datum+rng.uniform(0,15)*scale)
                roughness = real(rng.choice((0.0,-1.0,0.015,0.03,0.08)))
                points.append([offset,elevation,roughness,index%subsections])
            if trial%4 == 0:
                points[1][0] = points[0][0] # Vertical segment.
            if trial%4 == 1:
                points[1][1] = points[0][1] # Horizontal segment.
            if trial%4 == 2:
                points[1][0] = real(points[0][0]-3*scale) # Overhanging boundary.
            low,high = min(p[1] for p in points),max(p[1] for p in points)
            for fraction in (-0.1,0.0,0.07,0.31,0.8,1.0,1.1):
                water = real(low+fraction*(high-low))
                cases.append({'name':f'scale-{scale:g}-trial-{trial}-fraction-{fraction:g}',
                              'water_surface':water,'roughness_modes':[0]*subsections,'points':points})
    # Exercise the skipped line-weight accumulation for depth-dependent n.
    # Use monotone offsets; the original hydraulic-depth roughness lookup rejects
    # an overhang-only subsection with nonpositive width and positive area.
    extra = []
    for case in cases:
        if '-trial-3-' in case['name'] and any(case['name'].endswith('-fraction-'+f) for f in ('0.31','0.8','1.1')):
            for mode in (1,2,3):
                item = dict(case)
                item['name'] += '-roughness-'+str(mode)
                item['roughness_modes'] = [mode if mode != 3 else index%3 for index in range(len(case['roughness_modes']))]
                extra.append(item)
    return cases+extra


def record(case):
    modes,points = case['roughness_modes'],case['points']
    return (struct.pack('<fII',case['water_surface'],len(points),len(modes))+
            struct.pack('<'+str(len(modes))+'i',*modes)+
            b''.join(struct.pack('<fffI',*point) for point in points))


def image(original,pe,symbols,cases,flux=False):
    base = pe.OPTIONAL_HEADER.ImageBase
    start = base+symbols['_MAIN__']['rva']
    scratch = base+symbols['_ftable_']['rva']
    imports = {item.name.decode():item.address for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports if item.name}
    code = Driver(start,imports)
    code.emit('fc');code.push(-11);code.api('GetStdHandle');code.emit('89c3')
    for case in cases:
        points = case['points'];count = len(points);subs = len(case['roughness_modes'])
        data = bytearray()
        def put(fmt,*values):
            data.extend(bytes((-len(data))%8))
            address = scratch+len(data)
            data.extend(struct.pack(fmt,*values))
            return address
        snflg = put('<i',case.get('sinuosity_mode',0));zi = put('<f',case['water_surface']);npnt = put('<i',count);nsub = put('<i',subs)
        x = put('<'+str(count)+'f',*[p[0] for p in points]);z = put('<'+str(count)+'f',*[p[1] for p in points])
        sb = put('<'+str(count)+'i',*[p[3]+1 for p in points]);lsn = put('<'+str(count)+'f',*[p[2] for p in points])
        nvar = put('<'+str(subs)+'i',*case['roughness_modes']);sn = put('<'+str(count)+'f',*case.get('sinuosity',[1.0]*count))
        naty = put('<'+str(9*subs)+'f',*([0.03]*(9*subs)));yatn = put('<'+str(9*subs)+'f',*(list(range(9))*subs))
        nny = put('<'+str(subs)+'i',*([9]*subs));nfac = put('<f',case.get('manning_factor',1.49));betopt = put('<8s',case.get('beta_option','OLDBETA ').encode())
        n = put('<'+str(subs)+'f',*([0.03]*subs))
        ts = put('<'+str(subs)+'f',*([0]*subs));ps = put('<'+str(subs)+'f',*([0]*subs))
        area = put('<'+str(subs)+'d',*([0]*subs));moment = put('<'+str(subs)+'d',*([0]*subs));ns = put('<'+str(subs)+'f',*([0]*subs))
        sums = [put('<d',0) for unused in range(8)]
        ymax = put('<'+str(subs)+'f',*([0]*subs));sbsn = put('<'+str(subs)+'f',*([0]*subs))
        qs = put('<'+str(subs)+'f',*([0]*subs));ks = put('<'+str(subs)+'f',*([0]*subs))
        written = put('<i',0)
        code.copy(scratch,data)
        args = [snflg,zi,npnt,nsub,x,z,sb,lsn,nvar,sn,naty,yatn,nny,nfac,betopt,n,ts,ps,area,moment,ns,*sums,ymax,sbsn,qs,ks,8]
        for value in reversed(args):code.push(value)
        code.call(base+symbols['_fbasel_']['rva']);code.emit('81c4'+struct.pack('<I',len(args)*4).hex())
        if flux:
            for address in sums:code.write(address,8,written)
            for address in (sbsn,qs,ks):code.write(address,4*subs,written)
        else:
            for address,size in ((ts,4),(ps,4),(area,8),(moment,8),(ns,4),(ymax,4)):
                code.write(address,size*subs,written)
    driver = code.finish()
    later = sorted(item['rva'] for item in symbols.values() if item['type']==32 and item['section']==1 and item['rva']>symbols['_MAIN__']['rva'])
    if len(driver) > later[0]-symbols['_MAIN__']['rva']:
        raise ValueError('Geometry batch exceeds the replaceable PROGRAM body.')
    result = bytearray(original);offset = pe.get_offset_from_rva(symbols['_MAIN__']['rva'])
    result[offset:offset+len(driver)] = driver
    return bytes(result)


def main():
    import pefile
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output',type=Path,required=True)
    parser.add_argument('--native',type=Path)
    parser.add_argument('--fixtures',type=Path,help='Read explicit geometry cases instead of the deterministic suite.')
    parser.add_argument('--wine-prefix',type=Path,default=ROOT/'build/wineprefix')
    args = parser.parse_args();output = args.output.resolve()
    if output.exists() or ROOT/'build' not in output.parents:parser.error('Use a new FEQ/build/ directory.')
    output.mkdir(parents=True)
    original = (ROOT/'originals/feq1061/wrdapp/FEQ_10.61/BIN/fequtl.exe').read_bytes()
    if hashlib.sha256(original).hexdigest() != ORIGINAL_SHA256:raise ValueError('The recovered executable hash changed.')
    pe = pefile.PE(data=original);symbols = {item['name']:item for item in coff_symbols(original)}
    cases = json.loads(args.fixtures.read_text()) if args.fixtures else fixtures()
    inputs = b''.join(record(case) for case in cases)
    (output/'inputs.bin').write_bytes(inputs);(output/'fixtures.json').write_text(json.dumps(cases,indent=2)+'\n')
    env = os.environ.copy();env.update(WINEPREFIX=str(args.wine_prefix.resolve()),WINEDEBUG='-all',WINEDLLOVERRIDES='mscoree,mshtml=',MVK_CONFIG_LOG_LEVEL='0')
    expected = bytearray();records = []
    for first in range(0,len(cases),6):
        batch = cases[first:first+6];exe = output/'PROBE.EXE';exe.write_bytes(image(original,pe,symbols,batch))
        command = [str(exe)] if os.name == 'nt' else ['wine',str(exe)]
        process = subprocess.run(command,cwd=output,env=env,capture_output=True,timeout=30,stdin=subprocess.DEVNULL)
        if process.returncode or len(process.stdout) != sum(32*len(case['roughness_modes']) for case in batch):
            (output/'error.log').write_bytes(process.stdout+process.stderr)
            raise RuntimeError(f'Original geometry driver failed: exit {process.returncode}, {len(process.stdout)} bytes.')
        cursor = 0
        for case in batch:
            size = 32*len(case['roughness_modes']);records.append({'name':case['name'],'offset':len(expected),'bytes':size})
            expected.extend(process.stdout[cursor:cursor+size]);cursor += size
        print(f'{first+len(batch)}/{len(cases)} original section geometries captured.',flush=True)
    (output/'outputs.bin').write_bytes(expected)
    manifest = {'original_sha256':ORIGINAL_SHA256,'routine':'_fbasel_ (geometric outputs)',
                'cases':len(cases),'input_sha256':hashlib.sha256(inputs).hexdigest(),
                'output_sha256':hashlib.sha256(expected).hexdigest(),'fixtures':records}
    if args.native:
        native = subprocess.run([str(args.native.resolve())],input=inputs,capture_output=True,timeout=30)
        (output/'native.bin').write_bytes(native.stdout);(output/'native.stderr.log').write_bytes(native.stderr)
        manifest.update(native_sha256=hashlib.sha256(args.native.read_bytes()).hexdigest(),native_returncode=native.returncode,
                        exact_bytes=native.returncode == 0 and bytes(expected) == native.stdout)
    (output/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    if args.native:raise SystemExit(0 if manifest['exact_bytes'] else 1)


if __name__ == '__main__':main()
