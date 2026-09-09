#!/usr/bin/env python3
"""Connect independently tested components to the FEQUTL research translation.

New work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
"""
import argparse
import hashlib
import json
from pathlib import Path
import shutil
from prepare_cpp_probe import content, edit_text, functions, identifier, nodes

ROOT = Path(__file__).resolve().parents[1]
DECLARATION = ('extern "C" void feq_section_geometry(float,int,int,const float*,const float*,'
               'const int*,const float*,const int*,float*,float*,double*,double*,float*,float*,'
               'float*,int*,int*);\n'
               'extern "C" void feq_section_flux(float,int,int,const float*,const float*,'
               'const int*,const float*,const int*,const float*,const float*,int,float,'
               'double*,double*,double*,double*,double*,double*,float*);\n')


def integrate_geometry(data):
    targets = [function for function in functions(data)
               if content(identifier(function.child_by_field_name('declarator')),data) == 'fbasel_']
    if len(targets) != 1:
        raise ValueError('Expected one FBASEL function definition.')
    function = targets[0]
    body = function.child_by_field_name('body')
    statements = [node for node in body.named_children if node.type != 'comment']
    start = [node for node in statements if node.type == 'expression_statement' and content(node,data) == 'jmin = 0;']
    stop = [node for node in statements if node.type == 'for_statement' and
            content(node.child_by_field_name('initializer'),data) == 'is = 1']
    if len(start) != 1 or len(stop) != 1:
        raise ValueError('Expected the original geometry and roughness loops.')
    # The control value immediately preceding the roughness loop sets its upper
    # bound. Keep it: the independent geometry call replaces only the first pass.
    previous = statements[statements.index(stop[0])-1]
    if content(previous,data) != 'feq_gen_i_d_1 = *nsub;':
        raise ValueError('Unexpected roughness-loop bound.')
    removed = data[start[0].start_byte:previous.start_byte].decode()
    if 'L500:' not in removed or 'for (j = 2;' not in removed:
        raise ValueError('Expected the complete original first geometry pass.')
    replacement = ('// FBASEL geometry: original-verified mixed binary32/binary64 accumulations.\n'
                   '    feq_section_geometry(*zi,*npnt,*nsub,&x[1],&feq_gen_z_d_[1],&sb[1],&lsn[1],\n'
                   '        &nvar[1],&ts[1],&ps[1],&as[1],&ybs[1],&ns[1],&ysmx[1],pvec,&jmin,&jmax);\n    ')
    flux = ('\n    // Independently verified analytical NEWBETA pass (sinuosity modes 0/2).\n'
            '    if (nbflag == 1 && *snflg != 1) {\n'
            '        feq_section_flux(*zi,*npnt,*nsub,&x[1],&feq_gen_z_d_[1],&sb[1],&lsn[1],\n'
            '            &nvar[1],&n[1],&sn[1],*snflg,*nfac,sumq,sumfm,sumfe,sumdq,sumdfm,sumdfe,&sbsn[1]);\n'
            '        return 0;\n'
            '    }\n')
    return DECLARATION.encode()+edit_text(data,[(start[0].start_byte,previous.start_byte,replacement),
        (stop[0].end_byte,stop[0].end_byte,flux)])


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('source',type=Path);parser.add_argument('output',type=Path)
    args = parser.parse_args();source = args.source.resolve();output = args.output.resolve()
    if output.exists() or ROOT/'build' not in output.parents:parser.error('Use a new FEQ/build/ directory.')
    output.mkdir(parents=True)
    for path in source.glob('*.hpp'):shutil.copy2(path,output/path.name)
    sources = []
    for path in sorted(source.glob('*.cpp')):
        data = path.read_bytes();sources.append({'name':path.name,'sha256':hashlib.sha256(data).hexdigest()})
        (output/path.name).write_bytes(integrate_geometry(data) if path.name == 'xsection.cpp' else data)
    manifest = {'status':'Research integration; full-model verification remains separate.',
                'source_files':sources,'changes':[{'file':'xsection.cpp','function':'fbasel_',
                'component':'src/section_geometry.cpp','scope':'First pass: geometric accumulation and line roughness weights.'},
                {'file':'xsection.cpp','function':'fbasel_','component':'src/section_flux.cpp',
                 'scope':'Analytical NEWBETA second pass; preserve the separate piecewise linear Gaussian path.'}]}
    (output/'verified-components.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print('Integrated independent section geometry and analytical flux into FEQUTL FBASEL.')


if __name__ == '__main__':main()
