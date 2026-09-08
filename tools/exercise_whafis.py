#!/usr/bin/env python3
"""Exercise the original WHAFIS executable across every principal card family."""
import argparse
from pathlib import Path
import subprocess
from run_original import run_original

ROOT=Path(__file__).resolve().parents[1]


def card(kind, *values):
    fields=list(values)+[0]*(10-len(values))
    def number(value, width):
        text=f'{value:g}'
        if len(text)>width:raise ValueError((value,width))
        return text.rjust(width)
    return kind+number(fields[0],6)+''.join(number(v,8) for v in fields[1:])


def marsh(plant='SPAT', *values):
    fields=list(values)+[0]*(9-len(values))
    return 'MG  '+plant+''.join(f'{v:8g}' for v in fields)


def cases():
    initial=card('IE',0,-5,10,6,12,8,7)
    yield 'inland', [initial,card('IF',100,0),card('IF',500,3),card('IF',1500,7)]
    yield 'overwater', [card('IE',0,-5,1,4,8),card('OF',500,-5),card('OF',3000,-2),card('OF',6000,2)]
    yield 'dunes-and-buildings', [initial,card('DU',100,1),card('DU',200,6,1),card('BU',400,5,.7,4),card('IF',800,8)]
    yield 'trees', [initial,card('VE',100,0,.2,10,3,1),card('VE',500,3,.3,12,5,.8),card('IF',900,5)]
    yield 'marsh-custom', [initial,card('VH',200,1,2,1,0,1),marsh('SPAT',.1,1,.85,327,.024,.012,.012,1.38),card('IF',800,4)]
    yield 'marsh-regions', [initial,card('VH',200,1,2,.4,3,2),marsh('SPAT',.1,.6,.85,327),marsh('DIST',.1,.4,1,100),card('VH',800,4,3,1,0,1),marsh('SPAT',.1,1,.85,327)]
    yield 'above-surge', [initial,card('IF',200,10),card('AS',400,14,6,12),card('AS',600,12,6,12),card('IF',1200,8)]
    yield 'surge-changes', [initial,card('IF',200,1,6,12),card('IF',500,3,5,10),card('IF',900,5),card('IF',1400,8,4,9)]
    for n in range(1,5):
        lines=(ROOT/f'originals/champ2/w{n}.dat').read_text().splitlines()
        yield f'champ-w{n}-500', [':500:'+lines[0].strip()]+[l for l in lines[1:] if l.strip()]
    yield 'comments-and-wind', [':500:Comments and nondefault wind',card('IE',0,-5,10,6,12,8,7,65,95,70),
                               'CMObserved comment before the first fetch',card('IF',200,1),'PSPostscript retained in the final section',
                               card('OF',500,3),'CMSecond comment',card('IF',1000,6)]


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--output',type=Path,default=ROOT/'build/whafis-branches')
    p.add_argument('--native',type=Path,default=ROOT/'build/native/whafis');p.add_argument('--original',action='store_true')
    a=p.parse_args();a.output.mkdir(parents=True,exist_ok=True)
    for name,lines in cases():
        if not lines[0].startswith(':500:'):lines.insert(0,'WHAFIS compatibility case: '+name)
        if lines[-1]!='ET':lines.append('ET')
        path=a.output/(name+'.dat');path.write_bytes(('\r\n'.join(lines)+'\r\n\r\n').encode())
        if a.original:run_original('whafis4',path,a.output/(name+'.original.out'),wine_prefix=ROOT/'build/oracle/wine')
        result=subprocess.run([a.native,path,a.output/(name+'.native.out')],capture_output=True,timeout=30)
        print(name,result.returncode,result.stderr.decode().strip(),flush=True)


if __name__=='__main__':main()
