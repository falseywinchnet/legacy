#!/usr/bin/env python3
"""Reproducible synthetic RUNUP profiles and full original/native comparisons.

Run from the repository root after building build/native/runup. Requires DOSBox-X.
Outputs stay in build/runup-branches; approved fixtures are preserved separately.
"""
import sys, itertools, subprocess, json, difflib
from pathlib import Path
sys.path.insert(0, 'tools')
from run_original import run_original
out=Path('build/runup-branches');out.mkdir(exist_ok=True)
profiles={}
for slope in [1,2,4,8,15,30,50,100]:
 profiles['uniform-'+str(slope)]=([(z,z*slope) for z in [-20,-10,0,10,20]],slope)
for approach in [5,10,20,50]:
 for structure in [2,6]:
  profiles[f'approach-{approach}-structure-{structure}']=([(-30,-30*approach),(-15,-15*approach),(-3,-3*structure),(0,0),(5,5*structure),(20,20*structure)],structure)
profiles['segmented'] = ([(-20,-1000),(-4,-100),(-2,-40),(0,0),(4,8),(8,24),(20,60)],5)
profiles['berm'] = ([(-20,-1000),(-5,-100),(0,0),(4,20),(4,50),(10,75),(20,150)],7)
rows=[]
for name,(points,lastslope) in profiles.items():
 for rough in ([1.0,.7] if name in ('segmented','berm','uniform-8') else [1.0]):
  title=name+('-rough' if rough!=1 else '')
  lines=['  Binary comparison'.ljust(80),'  '+title,'%.1f'%lastslope]
  for n,(z,x) in enumerate(points):lines.append(f'{int(n+1==len(points)):1} {z:5.1f} {x:6.1f} {rough:5.3f}')
  for water,height,period in itertools.product([0,1,5],[2,5,8],[4,6,8]):
   if .002<height/(5.12*period**2)<.07:lines.append(f'0{water:5.2f} {height:5.2f} {period:5.2f}')
  inp=out/(title+'.dat');orig=out/(title+'.original.out');native=out/(title+'.native.out')
  inp.write_text('\n'.join(lines)+'\n')
  if not orig.exists():run_original('runup',inp,orig)
  p=subprocess.run(['build/native/runup',inp,native],capture_output=True)
  a=orig.read_bytes();b=native.read_bytes()
  delta=list(difflib.unified_diff(a.decode('latin1').splitlines(),b.decode('latin1').splitlines()))
  (out/(title+'.diff')).write_text('\n'.join(delta))
  print(title,'waves',len(lines)-3-len(points),'exit',p.returncode,'match',a==b,'orig',len(a),'native',len(b),flush=True)
  rows.append({'name':title,'exact':a==b,'native_exit':p.returncode,'input':str(inp),'original':str(orig),'native':str(native)})
(out/'results.json').write_text(json.dumps(rows,indent=2))
