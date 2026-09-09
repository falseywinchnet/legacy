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


def integrate_critical_speed_store(data):
    targets = [function for function in functions(data)
               if content(identifier(function.child_by_field_name('declarator')),data) == 'critq_']
    if len(targets) != 1:
        raise ValueError('Expected one CRITQ function definition.')
    calls = [node for node in nodes(targets[0]) if node.type == 'call_expression' and
             content(node.child_by_field_name('function'),data) == 'sqrt']
    if len(calls) != 1:
        raise ValueError('Expected one critical-speed square root.')
    call = calls[0]
    return edit_text(data,[(call.start_byte,call.end_byte,
        'static_cast<float>(/* Original 0x411964 stores sqrt(g*A/T) as REAL before Q=A*speed. */ '+content(call,data)+')')])


def integrate_arch(data):
    targets = [function for function in functions(data)
               if content(identifier(function.child_by_field_name('declarator')),data) == 'rharch_']
    if len(targets) != 1:
        raise ValueError('Expected one RHARCH definition.')
    statements = [node for node in targets[0].child_by_field_name('body').named_children if node.type != 'comment']
    starts = [node for node in statements if node.type == 'expression_statement' and
              content(node,data) == '*rise = static_cast<double>(*cfac) * *rise;']
    if len(starts) != 1 or statements[-1].type != 'return_statement':
        raise ValueError('Expected RHARCH executable boundaries.')
    replacement = r"""
    // Original-verified standard interpolation, legacy ASIN, and arch geometry.
    if (*rise <= 0.0F && *span <= 0.0F) {
        feq_gen_io_d__309.ciunit = *stdout;
        s_wsfe(&feq_gen_io_d__309);
        e_wsfe();
        s_stop(const_cast<char*>("Abnormal stop. Errors found."),static_cast<ftnlen>(28));
        return 0;
    }
    int feq_span_warning = 0;
    float feq_warning_values[2] = {};
    const int feq_arch_error = feq_arch_perimeter(*np,&rsvec[1],&spvec[1],&r1vec[1],&r3vec[1],
        *cfac,rise,span,nrh,&rhx[1],&rhy[1],a,&feq_span_warning,feq_warning_values);
    if (feq_arch_error != 0) {
        cilist* feq_error_format = feq_arch_error == 571 ? &feq_gen_io_d__300 : &feq_gen_io_d__307;
        feq_error_format->ciunit = *stdout;
        feq_gen_r_d_1 = static_cast<double>(feq_arch_error == 571 ? *rise : *span)/ *cfac;
        feq_gen_r_d_2 = static_cast<double>(feq_arch_error == 571 ? rsvec[1] : spvec[1])/ *cfac;
        feq_gen_r_d_3 = static_cast<double>(feq_arch_error == 571 ? rsvec[*np] : spvec[*np])/ *cfac;
        s_wsfe(feq_error_format);
        do_fio(&feq_gen_c_d_1,reinterpret_cast<char*>(&feq_gen_r_d_1),static_cast<ftnlen>(sizeof(real)));
        do_fio(&feq_gen_c_d_1,reinterpret_cast<char*>(&feq_gen_r_d_2),static_cast<ftnlen>(sizeof(real)));
        do_fio(&feq_gen_c_d_1,reinterpret_cast<char*>(&feq_gen_r_d_3),static_cast<ftnlen>(sizeof(real)));
        e_wsfe();
        *eflag = 1;
        return 0;
    }
    if (feq_span_warning != 0) {
        feq_gen_io_d__304.ciunit = *stdout;
        s_wsfe(&feq_gen_io_d__304);
        do_fio(&feq_gen_c_d_1,reinterpret_cast<char*>(&feq_warning_values[0]),static_cast<ftnlen>(sizeof(real)));
        do_fio(&feq_gen_c_d_1,reinterpret_cast<char*>(&feq_warning_values[1]),static_cast<ftnlen>(sizeof(real)));
        e_wsfe();
    }
    """
    declaration = ('extern "C" int feq_arch_perimeter(int,const float*,const float*,const float*,const float*,'
                   'float,float*,float*,int*,float*,float*,float*,int*,float*);\n')
    return declaration.encode()+edit_text(data,[(starts[0].start_byte,statements[-1].start_byte,replacement)])


def integrate_conduit_boundaries(data):
    replacements = {
        'urqte_': 'feq_conduit_boundary(0,0,*rise,*span,0.0F,0.0F,0.0F,0.0F,nullptr,nullptr,nurq,&urqx[1],&urqy[1]);',
        'mkpipe_': 'feq_conduit_boundary(1,*nsides,*feq_gen_d_d_,*feq_gen_d_d_,*wslot,*hslot,*xoff,*zoff,nullptr,nullptr,npnts,&x[1],&feq_gen_z_d_[1]);',
        'mkbox_': 'feq_conduit_boundary(2,0,*rise,*span,*wslot,*hslot,*xoff,*zoff,nullptr,nullptr,npnts,&x[1],&feq_gen_z_d_[1]);',
        'rhmak_': 'feq_conduit_boundary(3,*nrh,0.0F,0.0F,*wslot,*hslot,*xoff,*yoff,&rhx[1],&rhy[1],npnts,&x[1],&y[1]);',
        'urqmak_': 'feq_conduit_boundary(4,*nurq,0.0F,0.0F,*wslot,*hslot,*xoff,*yoff,&urqx[1],&urqy[1],npnts,&x[1],&y[1]);',
    }
    edits = []; found = set()
    for function in functions(data):
        name = content(identifier(function.child_by_field_name('declarator')),data)
        if name not in replacements:continue
        statements = [node for node in function.child_by_field_name('body').named_children
                      if node.type not in ('comment','declaration')]
        start = 1 if name == 'rhmak_' else 0
        if statements[-1].type != 'return_statement' or statements[start].type != 'expression_statement':
            raise ValueError('Unexpected conduit constructor boundaries: '+name)
        if name == 'rhmak_' and (statements[0].type != 'if_statement' or
            content(statements[0].child_by_field_name('condition'),data) != '(rhx[2] == (float)0.)'):
            raise ValueError('Expected RHMAK zero-divide diagnostic guard.')
        replacement = '// Independently verified original conduit coordinates and REAL stores.\n    '+replacements[name]+'\n    '
        edits.append((statements[start].start_byte,statements[-1].start_byte,replacement));found.add(name)
    if found != set(replacements):raise ValueError('Missing a conduit boundary constructor.')
    declaration = ('extern "C" void feq_conduit_boundary(int,int,float,float,float,float,float,float,'
                   'const float*,const float*,int*,float*,float*);\n')
    return declaration.encode()+edit_text(data,edits)


def integrate_section_lookup(data):
    edits = []
    found = set()
    for function in functions(data):
        name = content(identifier(function.child_by_field_name('declarator')),data)
        if name not in ('xlkt20_','xlkt21_','xlkt22_','lktqc_'):
            continue
        body = content(function,data)
        begin = body.index('/*     FETCH VALUES FROM FTAB */')
        end = body.rindex('    return 0;')
        call = ('feq_interpolate_section_interval_moment(l,l+xoff,doff,*ya,a,t,dt,j,k,dk,b,db);'
                if name == 'xlkt21_' else 'feq_interpolate_section_interval(l,l+xoff,doff,*ya,a,t,dt,k,dk,b,db);')
        if name == 'xlkt22_':
            call = 'feq_interpolate_energy_section_interval(l,l+xoff,doff,feq_gen_type_d_,*ya,a,t,dt,j,k,dk,b,db,alp,dalp,qc);'
        elif name == 'lktqc_':
            call = 'feq_interpolate_critical_flow_interval(l,l+xoff,*ya,qc);'
        body = body[:begin]+'    // Directly verified against both FEQ and FEQUTL releases.\n    '+call+'\n'+body[end:]
        edits.append((function.start_byte,function.end_byte,body))
        found.add(name)
    if found != {'xlkt20_','xlkt21_','xlkt22_','lktqc_'}:
        raise ValueError('Expected all four section lookup routines.')
    declaration = ('extern "C" void feq_interpolate_critical_flow_interval(int,int,float,float*);\n'
                   'extern "C" void feq_interpolate_energy_section_interval(int,int,int,int,float,float*,float*,float*,float*,float*,float*,float*,float*,float*,float*,float*);\n'
                   'extern "C" void feq_interpolate_section_interval(int,int,int,float,float*,float*,float*,float*,float*,float*,float*);\n'
                   'extern "C" void feq_interpolate_section_interval_moment(int,int,int,float,float*,float*,float*,float*,float*,float*,float*,float*);\n')
    return declaration.encode()+edit_text(data,edits)


def integrate_scalar_lookup(data):
    targets = [function for function in functions(data)
               if content(identifier(function.child_by_field_name('declarator')),data) == 'lktab_']
    if len(targets) != 1:
        raise ValueError('Expected one scalar LKTAB definition.')
    function = targets[0]
    body = content(function,data)
    begin = body.index('L2:')
    end = body.index('L5:',begin)
    body = body[:begin]+('L2:\nL3:\nL4:\n'
        '    // Every output bit verified against both released programs.\n'
        '    feq_interpolate_function_interval(feq_gen_type_d_,lsta,inc,arg,func,pdv);\n'
        '    goto L1000;\n')+body[end:]
    declaration = 'extern "C" void feq_interpolate_function_interval(int,int,int,float,float*,float*);\n'
    return declaration.encode()+edit_text(data,[(function.start_byte,function.end_byte,body)])


def integrate_submerged_weir(data):
    targets = [function for function in functions(data)
               if content(identifier(function.child_by_field_name('declarator')),data) == 'stothq_']
    if len(targets) != 1:
        raise ValueError('Expected one STOTHQ definition.')
    function = targets[0]
    statements = [node for node in function.child_by_field_name('body').named_children if node.type != 'comment']
    starts = [node for node in statements if node.type == 'expression_statement' and content(node,data) == 'knt = 0;']
    returns = [node for node in statements if node.type == 'return_statement']
    conditions = {}
    for node in nodes(function):
        if node.type == 'if_statement':
            condition = content(node.child_by_field_name('condition'),data)
            if condition in ('(*l == (float)0.)','(knt > 100)'):
                conditions[condition] = content(node.child_by_field_name('consequence'),data)
    if len(starts) != 1 or len(returns) != 1 or len(conditions) != 2:
        raise ValueError('Expected STOTHQ arithmetic and diagnostic boundaries.')
    replacement = ('// Original-verified STOTHQ iteration; retain historical diagnostic output.\n'
        '    const int feq_weir_error = feq_submerged_weir(*hcwtab,*lcwtab,*subtab,*hlcrit,*l,*feq_gen_h_d_,\n'
        '        *htail,*depth,grvcom_1.grav,grvcom_1.grav2,htot,q,&head,&qw,&qwold,&cw,&frac);\n'
        '    if (feq_weir_error == 1) '+conditions['(*l == (float)0.)']+'\n'
        '    if (feq_weir_error == 2) '+conditions['(knt > 100)']+'\n    ')
    declaration = ('extern "C" int feq_submerged_weir(int,int,int,float,float,float,float,float,float,float,'
                   'float*,float*,float*,float*,float*,float*,float*);\n')
    return declaration.encode()+edit_text(data,[(starts[0].start_byte,returns[0].start_byte,replacement)])


def integrate_weir_quadrature(data):
    targets = [function for function in functions(data)
               if content(identifier(function.child_by_field_name('declarator')),data) == 'sbfemb_']
    if len(targets) != 1:
        raise ValueError('Expected one SBFEMB definition.')
    statements = [node for node in nodes(targets[0]) if node.type == 'expression_statement']
    starts = [node for node in statements if content(node,data).startswith('dx = (feq_gen_r_d_1 =')]
    ends = [node for node in statements if content(node,data) == 'qsub += qseg;']
    if len(starts) != 1 or len(ends) != 1 or starts[0].parent != ends[0].parent:
        raise ValueError('Expected one complete SBFEMB Simpson accumulation.')
    replacement = ('// Qsegment = abs(XR-XL)*(Qleft+4*Qmid+Qright)/6.\n'
        '        // Original 0x42ff92..0x42ffb5 retains the width and segment flow wide,\n'
        '        // and multiplies by the REAL reciprocal at 0x56cf40 before adding QSUB.\n'
        '        const double feq_width = (std::abs)(static_cast<double>(xr[iseg])-xl[iseg]);\n'
        '        const double feq_flow = (static_cast<double>(qmid)*4.0+qleft)+qright;\n'
        '        qsub += (feq_width*feq_flow)*static_cast<double>(0.1666666716337204F);')
    return b'#include <cmath>\n'+edit_text(data,[(starts[0].start_byte,ends[0].end_byte,replacement)])


def integrate_weir_drop_fractions(data):
    targets = [function for function in functions(data)
               if content(identifier(function.child_by_field_name('declarator')),data) == 'embank_']
    if len(targets) != 1:
        raise ValueError('Expected one EMBANK definition.')
    statements = [node for node in nodes(targets[0]) if node.type == 'expression_statement']
    targets = [node for node in statements if content(node,data) ==
               'pfdvec[feq_gen_i_d_ - 1] = pow_dd(&feq_gen_d_d_1, &feq_gen_d_d_2);']
    if len(targets) != 1:
        raise ValueError('Expected the original EMBANK drop-fraction power.')
    statement = targets[0]
    replacement = ('// PFD = REAL((I-1)/(NFRAC-1)) ** REAL(POWER).\n'
        '        // Original 0x431d10..0x431d4a uses a retained reciprocal and a\n'
        '        // REAL argument store before the released REAL power kernel.\n'
        '        pfdvec[feq_gen_i_d_ - 1] = feq::legacy_power(\n'
        '            static_cast<float>(static_cast<double>(feq_gen_i_d_-1)*(1.0/static_cast<double>(nfrac-1))),power);')
    return b'#include <feq/power.hpp>\n'+edit_text(data,[(statement.start_byte,statement.end_byte,replacement)])


def integrate_roots(data):
    methods = {'regflt_':0,'rgf_':1,'rgf3_':2,'rgf5_':3}
    edits = []
    for function in functions(data):
        name = content(identifier(function.child_by_field_name('declarator')),data)
        if name not in methods:continue
        body = function.child_by_field_name('body')
        replacement = ('{\n    // Original-verified bracket updates, wide residuals and convergence ordering.\n'
            f'    feq_root_variant({methods[name]},*epsx,*epsf,f,a,b,fl,fr,xm,feq_gen_flag_d_);\n    return 0;\n}}')
        edits.append((body.start_byte,body.end_byte,replacement))
    if len(edits) != len(methods):raise ValueError('Expected all four verified root definitions.')
    declaration = 'extern "C" void feq_root_variant(int,float,float,double(*)(float*),float*,float*,float*,float*,float*,int*);\n'
    return declaration.encode()+edit_text(data,edits)


def integrate_steady_residuals(data):
    edits = []
    for function in functions(data):
        name = content(identifier(function.child_by_field_name('declarator')),data)
        if name not in ('sber_','sper_'):continue
        subcritical = name == 'sber_'
        common = 'sberc_1' if subcritical else 'sperc_1'
        adr,flow,neighbor_flow,conveyance,area = ('adrs','qt','qt','kr','ar') if subcritical else ('adr','qr','ql','kl','al')
        method = 'steady_subcritical_residual' if subcritical else 'steady_supercritical_residual'
        body = function.child_by_field_name('body')
        replacement = f"""{{
    float yt = *y < {common}.feq_gen_d_d_ ? *y : {common}.feq_gen_d_d_;
    float a,t,dt,j,k,dk,bet,dbet,alp,dalp;
    extern int xlktal_(int*,float*,float*,float*,float*,float*,float*,float*,float*,float*,float*,float*);
    xlktal_(&{common}.{adr},&yt,&a,&t,&dt,&j,&k,&dk,&bet,&dbet,&alp,&dalp);
    // Lookup clamps the section depth, while energy uses the original Y.
    const feq::SteadyResidualInput input{{*y,a,k,alp,{common}.{flow},{common}.{neighbor_flow},
        {common}.{conveyance},{common}.dx,{common}.se,{common}.rhs,{common}.kacc,{common}.kdec,
        {common}.{area},grvcom_1.grav2}};
    return feq::{method}(input);
}}"""
        edits.append((body.start_byte,body.end_byte,replacement))
    if len(edits) != 2:raise ValueError('Expected SBER and SPER definitions.')
    return b'#include <feq/steady_residual.hpp>\n'+edit_text(data,edits)


def integrate_culvert_losses(data):
    definitions = {content(identifier(function.child_by_field_name('declarator')),data):function
                   for function in functions(data)}
    if not {'degcon_','rqvstw_','fcd123_'}.issubset(definitions):
        raise ValueError('Expected DEGCON, RQVSTW and FCD123 definitions.')
    body = definitions['degcon_'].child_by_field_name('body')
    edits = [(body.start_byte,body.end_byte,
        '{\n    return feq::culvert_contraction(*c123,*a1,*a);\n}')]
    statements = [node for node in nodes(definitions['rqvstw_']) if node.type == 'expression_statement']
    stores = [node for node in statements if content(node,data).startswith('dh =')]
    if len(stores) != 1:
        raise ValueError('Expected one RQVSTW head-loss store.')
    store = stores[0]
    prior = statements[statements.index(store)-2:statements.index(store)]
    if [content(node,data) for node in prior] != [
            'feq_gen_r_d_1 = cdcom_1.cd;',
            'feq_gen_r_d_2 = static_cast<double>(*q) / cdcom_1.avh;']:
        raise ValueError('Unexpected RQVSTW head-loss power temporaries.')
    edits.append((prior[0].start_byte,store.end_byte,
        '// Original Q/AVH stays wide through its square; DH is the only REAL store.\n'
        '    dh = feq::culvert_head_loss(cdcom_1.cd,*q,cdcom_1.avh,grvcom_1.grav2);'))
    function = definitions['fcd123_']
    statements = [node for node in function.child_by_field_name('body').named_children if node.type != 'comment']
    branches = [node for node in statements if node.type == 'if_statement']
    returns = [node for node in statements if node.type == 'return_statement']
    if len(branches) != 2 or len(returns) != 1 or 's_cmp(culcls' not in content(branches[0],data):
        raise ValueError('Expected the original FCD123 shape dispatch and return.')
    replacement = r"""
    feq::CulvertCoefficientInput feq_input{};
    if (s_cmp(culcls,const_cast<char*>("PIPE"),8,4) == 0) {
        feq_input.shape = feq::CulvertShape::pipe;
    } else if (s_cmp(culcls,const_cast<char*>("FLARED"),8,6) == 0) {
        feq_input.shape = feq::CulvertShape::flared;
    } else if (s_cmp(culcls,const_cast<char*>("BOX"),8,3) == 0) {
        feq_input.shape = feq::CulvertShape::box;
    } else if (s_cmp(culcls,const_cast<char*>("MITER"),8,5) == 0) {
        feq_input.shape = feq::CulvertShape::miter;
    } else if (s_cmp(culcls,const_cast<char*>("RCPTG"),8,5) == 0) {
        feq_input.shape = feq::CulvertShape::rcptg;
    } else {
        feq_gen_io_d__103.ciunit = *stdout;
        s_wsfe(&feq_gen_io_d__103);
        do_fio(&feq_gen_c_d_1,culcls,static_cast<ftnlen>(8));
        e_wsfe();
        s_stop(const_cast<char*>("Abnormal stop. Errors found."),static_cast<ftnlen>(28));
        return 0.0;
    }
    if (feq_input.shape == feq::CulvertShape::box && *feq_gen_type_d_ == 3) {
        if (xs2com_1.a2 < xs3com_1.a3) {
            adrtab = xs2com_1.adrxs2;
            y = xs2com_1.y2;
        } else {
            adrtab = xs3com_1.adrxs3;
            y = xs3com_1.y3;
        }
        lktqc_(&adrtab,&y,&qc);
        feq_input.critical_flow = qc;
    }
    feq_input.flow_type = *feq_gen_type_d_;
    feq_input.upstream_height = *dup;
    feq_input.upstream_level = *z1true;
    feq_input.entrance_bed = xs2com_1.zb2;
    feq_input.flow = xs3com_1.q3;
    feq_input.rounding_factor = cdcom_1.krb;
    feq_input.wing_factor = cdcom_1.kwing;
    feq_input.projection_factor = cdcom_1.kproj;
    return feq::culvert_discharge_coefficient(feq_input,cdcom_1.ratflg);
    """
    if 'feq_gen_io_d__103.ciunit = *stdout;' not in content(function,data):
        raise ValueError('FCD123 unsupported-class diagnostic changed.')
    edits.append((branches[0].start_byte,returns[0].end_byte,replacement))
    return b'#include <feq/culvert_loss.hpp>\n'+edit_text(data,edits)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('source',type=Path);parser.add_argument('output',type=Path)
    args = parser.parse_args();source = args.source.resolve();output = args.output.resolve()
    if output.exists() or ROOT/'build' not in output.parents:parser.error('Use a new FEQ/build/ directory.')
    output.mkdir(parents=True)
    for path in source.glob('*.hpp'):shutil.copy2(path,output/path.name)
    sources = []
    integrated_files = set()
    for path in sorted(source.glob('*.cpp')):
        data = path.read_bytes();sources.append({'name':path.name,'sha256':hashlib.sha256(data).hexdigest()})
        if path.name == 'xsection.cpp':data = integrate_elevations(integrate_properties(integrate_geometry(data)))
        elif path.name == 'critq.cpp':data = integrate_critical_speed_store(data)
        elif path.name == 'conduit.cpp':data = integrate_conduit_boundaries(integrate_arch(data))
        elif path.name == 'fqshrftb.cpp':data = integrate_scalar_lookup(integrate_section_lookup(data))
        elif path.name == 'embank.cpp':data = integrate_weir_drop_fractions(integrate_weir_quadrature(integrate_submerged_weir(data)))
        elif path.name == 'rootfind.cpp':data = integrate_roots(data)
        elif path.name == 'culvertc.cpp':data = integrate_steady_residuals(data)
        elif path.name == 'culvertd.cpp':data = integrate_culvert_losses(data)
        if path.name in ('xsection.cpp','critq.cpp','conduit.cpp','fqshrftb.cpp','embank.cpp','rootfind.cpp','culvertc.cpp','culvertd.cpp'):
            integrated_files.add(path.name)
        (output/path.name).write_bytes(data)
    if integrated_files != {'xsection.cpp','critq.cpp','conduit.cpp','fqshrftb.cpp','embank.cpp','rootfind.cpp','culvertc.cpp','culvertd.cpp'}:
        raise ValueError('Prepared utility sources are missing required integration files.')
    manifest = {'status':'Research integration; full-model verification remains separate.',
                'source_files':sources,'changes':[{'file':'xsection.cpp','function':'fbasel_',
                'component':'src/section_geometry.cpp','scope':'First pass: geometric accumulation and line roughness weights.'},
                {'file':'xsection.cpp','function':'fbasel_','component':'src/section_flux.cpp',
                 'scope':'Analytical NEWBETA second pass; preserve the separate piecewise linear Gaussian path.'},
                {'file':'xsection.cpp','function':'compel_','component':'src/section_properties.cpp',
                 'scope':'Section aggregation, conveyance, coefficients, critical flows and KOLD/TSOLD updates; retain original diagnostic formats.'},
                {'file':'xsection.cpp','function':'chkarg_','component':'src/elevation_arguments.cpp',
                 'scope':'Elevation spacing, near-zero insertion, stable sort and duplicate removal; retain ERR:525 formatting.'},
                {'file':'critq.cpp','function':'critq_','scope':'REAL critical-speed store before multiplication by area.',
                 'evidence':'recovery/assembly/fequtl/_critq_.asm, VA 0x411964.'},
                {'file':'conduit.cpp','function':'rharch_','component':'src/arch_perimeter.cpp',
                 'scope':'Standard interpolation and area-adjusted perimeter; retain original diagnostic formats.',
                 'verification':'tests/reference/arch_perimeter/manifest.json'},
                {'file':'conduit.cpp','functions':['urqte_','mkpipe_','mkbox_','rhmak_','urqmak_'],
                 'component':'src/conduit_boundary.cpp','scope':'Area corrections, boundary mirroring and slot intersections.',
                 'verification':'tests/reference/conduit_boundary/manifest.json'},
                {'file':'fqshrftb.cpp','functions':['xlkt20_','xlkt21_'],'component':'src/section_interpolation.cpp',
                 'verification':['tests/reference/section_interpolation/fequtl-manifest.json',
                                 'tests/reference/section_first_moment/fequtl-manifest.json']},
                {'file':'fqshrftb.cpp','function':'xlkt22_','component':'src/section_energy.cpp',
                 'scope':'All eleven properties including logarithmic critical flow; XLKTAL delegates to this routine.',
                 'verification':'tests/reference/section_energy/manifest.json'},
                {'file':'fqshrftb.cpp','function':'lktqc_','component':'src/section_energy.cpp',
                 'scope':'Standalone critical flow, including the original zero-depth NaN.',
                 'verification':'tests/reference/critical_flow/manifest.json'},
                {'file':'fqshrftb.cpp','function':'lktab_','component':'src/table_interpolation.cpp',
                 'scope':'Scalar table types 2, 3 and 4.',
                 'verification':'tests/reference/function_tables/fequtl-manifest.json'},
                {'file':'embank.cpp','function':'stothq_','component':'src/weir_flow.cpp',
                 'scope':'Submerged-flow iteration with original lookup and diagnostic behavior.',
                 'verification':'tests/reference/weir_flow/manifest.json'},
                {'file':'embank.cpp','function':'sbfemb_',
                 'scope':'Retained Simpson width/flow registers and original REAL reciprocal of six.',
                 'evidence':'recovery/assembly/fequtl/_sbfemb_.asm, VA 0x42ff92..0x42ffb5.'},
                {'file':'rootfind.cpp','functions':['regflt_','rgf_','rgf3_','rgf5_'],'component':'src/root_solver.cpp',
                 'scope':'Modified false position, wide callback results, mutable trial arguments and exact failure outputs.',
                 'verification':['tests/reference/root_solver/manifest.json','tests/reference/root_solver_regflt/manifest.json',
                     'tests/reference/root_solver_rgf/manifest.json','tests/reference/root_solver_rgf5/manifest.json']},
                {'file':'culvertc.cpp','functions':['sber_','sper_'],'component':'src/steady_residual.cpp',
                 'scope':'Wide velocity, energy, eddy loss and normalized residuals after original section lookup.',
                 'verification':'tests/reference/steady_residual/manifest.json'},
                {'file':'culvertd.cpp','functions':['degcon_','rqvstw_','fcd123_'],'component':'src/culvert_loss.cpp',
                 'scope':'Discharge curves, contraction adjustment and RQVSTW velocity head loss.',
                 'verification':['tests/reference/culvert_loss/manifest.json','tests/reference/culvert_coefficient/manifest.json']},
                {'file':'embank.cpp','function':'embank_','component':'src/power.cpp',
                 'scope':'Original reciprocal and REAL power argument/result for partial free-drop fractions.',
                 'evidence':'recovery/assembly/fequtl/_embank_.asm, VA 0x431d10..0x431d4a.'}]}
    (output/'verified-components.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print('Integrated independent section geometry/flux/properties, elevations, arch perimeter, section lookups and submerged-weir iteration.')


if __name__ == '__main__':main()
