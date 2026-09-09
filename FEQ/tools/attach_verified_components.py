#!/usr/bin/env python3
"""Connect verified numerical components to a translated research candidate.

Only actual function definitions are selected, using the C++ syntax tree.
The resulting whole engine remains subject to original-executable comparison.
New work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
"""
import argparse
import hashlib
import json
from pathlib import Path
import shutil

from prepare_cpp_probe import content, edit_text, functions, identifier

ROOT = Path(__file__).resolve().parents[1]
DECLARATION = ('extern "C" void feq_interpolate_section_interval(int,int,int,float,'
               'float*,float*,float*,float*,float*,float*,float*);\n')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('source',type=Path)
    parser.add_argument('output',type=Path)
    parser.add_argument('--setinx-distance-rounding',action='store_true',
                        help='Reproduce the independently traced reciprocal and binary32 DXDT store in SETINX.')
    args = parser.parse_args()
    source, output = args.source.resolve(),args.output.resolve()
    if output.exists() or ROOT/'build' not in output.parents:
        parser.error('Use a new FEQ/build/ directory.')
    output.mkdir(parents=True)
    for path in source.glob('*.hpp'):
        shutil.copy2(path,output/path.name)
    changes = []
    for path in sorted(source.glob('*.cpp')):
        data = path.read_bytes()
        edits = []
        needs_declaration = False
        for function in functions(data):
            name = content(identifier(function.child_by_field_name('declarator')),data)
            body = content(function,data)
            if name in ('xlkt20_','xxlkt20_'):
                begin = body.index('/*     FETCH VALUES FROM FTAB */')
                end = body.rindex('    return 0;')
                body = body[:begin]+'    feq_interpolate_section_interval(l,l+xoff,doff,*ya,a,t,dt,k,dk,b,db);\n'+body[end:]
                needs_declaration = True
                changes.append({'file':path.name,'function':name,'component':'src/section_interpolation.cpp',
                                'verification':'240 cases, 480 original calls, all seven output words exact'})
            elif name == 'setinx_' and args.setinx_distance_rounding:
                old = 'dxdt = dx / *dt;'
                if body.count(old)!=1:
                    raise ValueError('The expected SETINX distance/time expression changed.')
                body = body.replace(old,
                    '// Original 0x40c5fd forms a double reciprocal; 0x40c680 stores DXDT as binary32.\n'
                    '    dxdt = static_cast<float>(dx * (1.0 / *dt));')
                changes.append({'file':path.name,'function':name,'rounding':'double reciprocal followed by binary32 distance/time ratio',
                                'original_addresses':['0x40c5fd','0x40c680'],
                                'evidence':'recovery/probes/branch-distance-trace.json'})
            else:
                continue
            edits.append((function.start_byte,function.end_byte,body))
        result = edit_text(data,edits)
        if needs_declaration:
            result = DECLARATION.encode()+result
        (output/path.name).write_bytes(result)
    manifest = {'status':'Research integration; passing component fixtures does not establish whole-engine acceptance.',
                'changes':changes,'source_files':[{'name':path.name,'sha256':hashlib.sha256(path.read_bytes()).hexdigest()}
                                                for path in sorted(source.glob('*.cpp'))]}
    (output/'verified-components.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print(f'{len(changes)} component or rounding integrations recorded.')


if __name__ == '__main__':
    main()
