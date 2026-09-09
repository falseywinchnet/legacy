#!/usr/bin/env python3
"""Make a disposable C++ candidate that records all four gate residual entries.

Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
"""
import argparse
import hashlib
import json
from pathlib import Path
import shutil
from prepare_cpp_probe import content,edit_text,functions,identifier

ROOT=Path(__file__).resolve().parents[1]
ROUTINES=('rsomy3_','rsomy4_','rswmy3_','rswmy4_')


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('source',type=Path);parser.add_argument('output',type=Path)
    parser.add_argument('--limit',type=int,default=100000)
    args=parser.parse_args();source=args.source.resolve();output=args.output.resolve()
    if output.exists() or ROOT/'build' not in output.parents:parser.error('Use a new FEQ/build/ directory.')
    if args.limit < 1 or args.limit > 1000000:parser.error('Use a trace limit from 1 through 1000000.')
    data=(source/'ufgate.cpp').read_bytes();edits=[];found=set()
    for function in functions(data):
        name=content(identifier(function.child_by_field_name('declarator')),data)
        if name not in ROUTINES:continue
        body=function.child_by_field_name('body');index=ROUTINES.index(name)
        argument='y3u' if name.endswith('3_') else 'y4u'
        insertion=f'\n    static FILE* trace = fopen("gate-{index:02d}.bin","wb");\n    static int trace_count = 0;\n    if (trace_count++ < {args.limit}) {{ fwrite(&ufcom_,1,168,trace); fwrite({argument},4,1,trace); }}\n'
        edits.append((body.start_byte+1,body.start_byte+1,insertion));found.add(name)
    if found != set(ROUTINES):raise ValueError('Expected all four original gate residual definitions.')
    instrumented=b'#include <cstdio>\n'+edit_text(data,edits)
    output.mkdir()
    for path in sorted(source.iterdir()):
        if path.is_file() and (path.suffix in ('.cpp','.h','.hpp') or path.name=='verified-components.json'):
            shutil.copyfile(path,output/path.name)
    (output/'ufgate.cpp').write_bytes(instrumented)
    manifest=dict(routines=ROUTINES,limit=args.limit,record_bytes=172,
        source=str(source/'ufgate.cpp'),source_sha256=hashlib.sha256(data).hexdigest(),
        instrumented_sha256=hashlib.sha256(instrumented).hexdigest(),
        tool_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest())
    (output/'gate-instrumentation.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print('Instrumented all four gate entries; compile and link this disposable candidate before running.')

if __name__=='__main__':main()
