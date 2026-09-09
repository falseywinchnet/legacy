#!/usr/bin/env python3
"""Generate 80 deterministic varied profiles and compare the original RUNUP.

Run from the repository root after a native build. Requires DOSBox-X.
The fixed seed makes slope, roughness, and changing-water cases reproducible.
"""
import sys,random,subprocess,json,difflib
from pathlib import Path
sys.path.insert(0,'tools')
from run_original import run_original
rng=random.Random(19911106);base=Path('build/runup-random');base.mkdir(exist_ok=True)
def fixed(v,n,d=1):
 s=f'{v:.{d}f}'
 if len(s)>n:s=f'{v:.0f}.'
 return s.rjust(n)
rows=[]
for case in range(80):
 elev=[-30,-20,-10,-5,-2,0,2,5,8,12,20]
 if case%4==0:elev=[-20,-10,-5,-2,0,2,5,10,20]
 positions=[0]
 for a,b in zip(elev,elev[1:]):positions.append(positions[-1]+(b-a)*rng.choice([1,2,3,5,8,10,15,20,30,50,100]))
 origin=positions[elev.index(0)];positions=[x-origin for x in positions]
 roughs=[rng.choice([.3,.5,.7,1]) if case%3==0 else 1 for _ in elev]
 name=f'random-{case:03}'
 lines=['  Binary comparison'.ljust(80),'  '+name,'10.0']
 for n,(z,x,r) in enumerate(zip(elev,positions,roughs)):lines.append(f'{int(n==len(elev)-1)} '+fixed(z,5)+' '+fixed(x,6)+f' {r:5.3f}')
 for water,height,period in [(1.1,2,6),(5,5,6),(10.4,8,8),(0,5,4),(1.1,2,8),(0,2,6)]:lines.append(f'0{water:5.2f} {height:5.2f} {period:5.2f}')
 inp=base/(name+'.dat');old=base/(name+'.original.out');new=base/(name+'.native.out');inp.write_text('\n'.join(lines)+'\n')
 if not old.exists():run_original('runup',inp,old)
 p=subprocess.run(['build/native/runup',inp,new],capture_output=True)
 a=old.read_bytes();b=new.read_bytes();delta=list(difflib.unified_diff(a.decode('latin1').splitlines(),b.decode('latin1').splitlines()))
 (base/(name+'.diff')).write_text('\n'.join(delta))
 if delta:print(name,'exit',p.returncode,'old',len(a),'new',len(b),'diff',len(delta),flush=True)
 rows.append({'name':name,'exact':a==b,'native_exit':p.returncode,'original_bytes':len(a),'native_bytes':len(b)})
(base/'results.json').write_text(json.dumps(rows,indent=2));print('EXACT',sum(r['exact'] for r in rows),'of',len(rows),flush=True)
