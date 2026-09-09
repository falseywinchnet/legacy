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


PROPERTY_DECLARATION = ('extern "C" int feq_section_properties(int,int,int,const char*,float,float,float,int,int,int*,'
    'const float*,const float*,const double*,const double*,const float*,const float*,const float*,const float*,'
    'double,double,double,double,double,double,double,double,float*,float*,float*,int*,int*,float*);\n')


def integrate_properties(data):
    targets = [function for function in functions(data)
               if content(identifier(function.child_by_field_name('declarator')),data) == 'compel_']
    if len(targets) != 1:
        raise ValueError('Expected one COMPEL function definition.')
    body = targets[0].child_by_field_name('body')
    statements = [node for node in body.named_children if node.type != 'comment']
    calls = [node for node in statements if node.type == 'expression_statement' and content(node,data).startswith('fbasel_(')]
    returns = [node for node in statements if node.type == 'return_statement']
    if len(calls) != 1 or len(returns) != 1 or content(returns[0],data) != 'return 0;':
        raise ValueError('Expected the original COMPEL call and return boundaries.')
    replacement = r"""
    // COMPEL totals: independently verified original arithmetic and state updates.
    int feq_diagnostic_kind[401];
    int feq_diagnostic_subsection[401];
    float feq_diagnostic_percentage[401];
    const int feq_diagnostic_count = feq_section_properties(*nsub,*navm,*snflg,betopt,*nfac,
        grvcom_1.grav,nrdzcm_1.slot,nrdzcm_1.iusgs,nrdzcm_1.nocm,wrn557,
        ts,ps,as,ybs,&n[1],sbsn,qs,ks,sumq,sumfm,sumfe,sumdq,sumdfm,sumdfe,summa,summq,
        &kold[1],&tsold[1],&xsv[1],feq_diagnostic_kind,feq_diagnostic_subsection,feq_diagnostic_percentage);
    for (int feq_event = 0; feq_event < feq_diagnostic_count; ++feq_event) {
        j = feq_diagnostic_subsection[feq_event];
        if (feq_diagnostic_kind[feq_event] == 1) {
            feq_gen_io_d__362.ciunit = xscom_1.lout;
            s_wsfe(&feq_gen_io_d__362);
            do_fio(&feq_gen_c_d_1, reinterpret_cast<char*>(zi), static_cast<ftnlen>(sizeof(real)));
            do_fio(&feq_gen_c_d_1, reinterpret_cast<char*>(&j), static_cast<ftnlen>(sizeof(integer)));
            e_wsfe();
            xscom_1.eflag = 1;
        } else if (feq_diagnostic_kind[feq_event] == 2) {
            feq_gen_io_d__363.ciunit = xscom_1.lout;
            s_wsfe(&feq_gen_io_d__363);
            do_fio(&feq_gen_c_d_1, reinterpret_cast<char*>(zi), static_cast<ftnlen>(sizeof(real)));
            do_fio(&feq_gen_c_d_1, reinterpret_cast<char*>(&j), static_cast<ftnlen>(sizeof(integer)));
            e_wsfe();
            feq_gen_io_d__364.ciunit = xscom_1.lout;
            s_wsfe(&feq_gen_io_d__364);
            e_wsfe();
        } else if (feq_diagnostic_kind[feq_event] == 3) {
            feq_gen_io_d__372.ciunit = feq_gen_stdun_com_d_1.std6;
            s_wsfe(&feq_gen_io_d__372);
            do_fio(&feq_gen_c_d_1, reinterpret_cast<char*>(&j), static_cast<ftnlen>(sizeof(integer)));
            do_fio(&feq_gen_c_d_1, reinterpret_cast<char*>(zi), static_cast<ftnlen>(sizeof(real)));
            do_fio(&feq_gen_c_d_1, reinterpret_cast<char*>(&feq_diagnostic_percentage[feq_event]), static_cast<ftnlen>(sizeof(real)));
            e_wsfe();
        } else if (feq_diagnostic_kind[feq_event] == 4) {
            feq_gen_io_d__374.ciunit = feq_gen_stdun_com_d_1.std6;
            s_wsle(&feq_gen_io_d__374);
            do_lio(&feq_gen_c_d_9,&feq_gen_c_d_1,const_cast<char*>(" *ERR:615* NEWBETA FAILURE. VALUE < 1"),static_cast<ftnlen>(37));
            e_wsle();
        }
    }
    """
    return PROPERTY_DECLARATION.encode()+edit_text(data,[(calls[0].end_byte,returns[0].start_byte,replacement)])


def integrate_elevations(data):
    targets = [function for function in functions(data)
               if content(identifier(function.child_by_field_name('declarator')),data) == 'chkarg_']
    if len(targets) != 1:
        raise ValueError('Expected one CHKARG function definition.')
    statements = [node for node in targets[0].child_by_field_name('body').named_children if node.type != 'comment']
    starts = [node for node in statements if node.type == 'expression_statement' and content(node,data) == 'n = *ndep;']
    returns = [node for node in statements if node.type == 'return_statement']
    if len(starts) != 1 or len(returns) != 1:
        raise ValueError('Expected CHKARG executable boundaries.')
    replacement = r"""
    // Original-verified CHKARG register precision, stable sort, and RDUP.
    const int feq_exhausted = feq_elevation_arguments(*mxndep,ndep,*nrzero,*dzlim,*added,&feq_gen_z_d_[1]);
    for (int feq_event = 0; feq_event < feq_exhausted; ++feq_event) {
        feq_gen_io_d__151.ciunit = *stdout;
        s_wsfe(&feq_gen_io_d__151);
        e_wsfe();
    }
    """
    return b'extern "C" int feq_elevation_arguments(int,int*,float,float,int,float*);\n'+edit_text(
        data,[(starts[0].start_byte,returns[0].start_byte,replacement)])


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
        (output/path.name).write_bytes(integrate_elevations(integrate_properties(integrate_geometry(data))) if path.name == 'xsection.cpp' else data)
    manifest = {'status':'Research integration; full-model verification remains separate.',
                'source_files':sources,'changes':[{'file':'xsection.cpp','function':'fbasel_',
                'component':'src/section_geometry.cpp','scope':'First pass: geometric accumulation and line roughness weights.'},
                {'file':'xsection.cpp','function':'fbasel_','component':'src/section_flux.cpp',
                 'scope':'Analytical NEWBETA second pass; preserve the separate piecewise linear Gaussian path.'},
                {'file':'xsection.cpp','function':'compel_','component':'src/section_properties.cpp',
                 'scope':'Section aggregation, conveyance, coefficients, critical flows and KOLD/TSOLD updates; retain original diagnostic formats.'},
                {'file':'xsection.cpp','function':'chkarg_','component':'src/elevation_arguments.cpp',
                 'scope':'Elevation spacing, near-zero insertion, stable sort and duplicate removal; retain ERR:525 formatting.'}]}
    (output/'verified-components.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print('Integrated independent FBASEL geometry/analytical flux, COMPEL properties and CHKARG spacing.')


if __name__ == '__main__':main()
