#!/usr/bin/env python3
"""Capture FBASEL analytical flow integrals from the original FEQUTL.

Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
The original startup and FBASEL instructions are unchanged. The temporary
PROGRAM body supplies controlled positive-roughness boundary segments.
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
from probe_geometry_original import image, ORIGINAL_SHA256
from probe_profile_original import ROOT, real


def fixtures():
    cases = []
    rng = random.Random(58010612933)
    for scale in (0.001,1.0,1000.0):
        for trial in range(12):
            x = real(rng.uniform(-100,100)*scale)
            z = real(rng.uniform(-200,200)*scale)
            dx = real(rng.uniform(1,30)*scale)
            dz = real(rng.uniform(0.1,15)*scale)
            if trial%4 == 0:dz = 0.0
            if trial%4 == 1:dz = -dz
            if trial%4 == 2:dx = -dx
            rough = real(rng.uniform(0.01,0.09))
            points = [[x,z,rough,0],[real(x+dx),real(z+dz),rough,0]]
            low,high = min(p[1] for p in points),max(p[1] for p in points)
            for fraction in (0.0,0.31,1.1):
                water = real(low+fraction*max(high-low,scale))
                for mode in (0,2):
                    cases.append({'name':f'scale-{scale:g}-trial-{trial}-fraction-{fraction:g}-mode-{mode}',
                        'water_surface':water,'points':points,'roughness_modes':[0],
                        'sinuosity_mode':mode,'sinuosity':[real(rng.uniform(0.8,3.0)),1.0],
                        'manning_factor':real(1.49),'beta_option':'NEWBETA '})
    return cases


def record(case):
    points,modes = case['points'],case['roughness_modes']
    return (struct.pack('<fIIIf',case['water_surface'],len(points),len(modes),case['sinuosity_mode'],case['manning_factor'])+
            struct.pack('<'+str(len(modes))+'i',*modes)+
            b''.join(struct.pack('<fffIf',*point,sinuosity) for point,sinuosity in zip(points,case['sinuosity'])))


def main():
    import pefile
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output',type=Path,required=True)
    parser.add_argument('--native',type=Path)
    parser.add_argument('--fixtures',type=Path)
    parser.add_argument('--wine-prefix',type=Path,default=ROOT/'build/wineprefix')
    args = parser.parse_args();output = args.output.resolve()
    if output.exists() or ROOT/'build' not in output.parents:parser.error('Use a new FEQ/build/ directory.')
    output.mkdir(parents=True)
    original = (ROOT/'originals/feq1061/wrdapp/FEQ_10.61/BIN/fequtl.exe').read_bytes()
    if hashlib.sha256(original).hexdigest() != ORIGINAL_SHA256:raise ValueError('Recovered executable hash changed.')
    pe = pefile.PE(data=original);symbols = {item['name']:item for item in coff_symbols(original)}
    cases = json.loads(args.fixtures.read_text()) if args.fixtures else fixtures()
    inputs = b''.join(record(case) for case in cases)
    (output/'inputs.bin').write_bytes(inputs);(output/'fixtures.json').write_text(json.dumps(cases,indent=2)+'\n')
    env = os.environ.copy();env.update(WINEPREFIX=str(args.wine_prefix.resolve()),WINEDEBUG='-all',WINEDLLOVERRIDES='mscoree,mshtml=',MVK_CONFIG_LOG_LEVEL='0')
    expected = bytearray();records = []
    for first in range(0,len(cases),6):
        batch = cases[first:first+6];exe = output/'PROBE.EXE';exe.write_bytes(image(original,pe,symbols,batch,flux=True))
        command = [str(exe)] if os.name == 'nt' else ['wine',str(exe)]
        process = subprocess.run(command,cwd=output,env=env,capture_output=True,timeout=30,stdin=subprocess.DEVNULL)
        if process.returncode or len(process.stdout) != sum(64+12*len(case['roughness_modes']) for case in batch):
            (output/'error.log').write_bytes(process.stdout+process.stderr)
            raise RuntimeError(f'Original flux driver failed: exit {process.returncode}, {len(process.stdout)} bytes.')
        cursor = 0
        for case in batch:
            size = 64+12*len(case['roughness_modes']);records.append({'name':case['name'],'offset':len(expected),'bytes':size})
            expected.extend(process.stdout[cursor:cursor+size]);cursor += size
        print(f'{first+len(batch)}/{len(cases)} original section fluxes captured.',flush=True)
    (output/'outputs.bin').write_bytes(expected)
    manifest = {'original_sha256':ORIGINAL_SHA256,'routine':'_fbasel_ (analytical flow integrals)',
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
