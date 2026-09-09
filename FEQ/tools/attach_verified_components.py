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
import re
import shutil

from prepare_cpp_probe import content, edit_text, functions, identifier, nodes

ROOT = Path(__file__).resolve().parents[1]
DECLARATION = ('extern "C" void feq_interpolate_section_interval(int,int,int,float,'
               'float*,float*,float*,float*,float*,float*,float*);\n'
               'extern "C" void feq_interpolate_section_interval_moment(int,int,int,float,'
               'float*,float*,float*,float*,float*,float*,float*,float*);\n'
               'extern "C" void feq_interpolate_function_interval(int,int,int,float,float*,float*);\n')


def restore_traced_precision(body, name):
    """Apply only observed register/store differences, preserving source comments."""
    data = body.encode()
    function = functions(data)[0]
    edits = []
    if name == 'setinx_':
        declarations = [node for node in nodes(function) if node.type == 'declaration'
                        and content(node, data) == 'real newsum, oldsum;']
        if len(declarations) != 1:
            raise ValueError('The expected SETINX impulse-sum declaration changed.')
        node = declarations[0]
        edits.append((node.start_byte, node.end_byte,
                      '// Original SETINX keeps these sums in 53-bit registers across inline SIGN.\n'
                      '    doublereal newsum, oldsum;'))
        calls = [node for node in nodes(function) if node.type == 'call_expression'
                 and content(node.child_by_field_name('function'), data) == 'r_sign']
        if len(calls) != 4:
            raise ValueError('The expected four SETINX SIGN expressions changed.')
        for call in calls:
            arguments = call.child_by_field_name('arguments').named_children
            values = []
            for argument in arguments:
                text = content(argument, data)
                if argument.type != 'pointer_expression' or not text.startswith('&'):
                    raise ValueError('Expected a scalar address in SETINX SIGN.')
                values.append(text[1:])
            if len(values) != 2:
                raise ValueError('Expected two SIGN operands.')
            magnitude, sign = values
            # Lahey compares against zero: a negative-zero sign operand selects
            # positive magnitude. copysign would have different behavior.
            replacement = (f'({sign} >= 0.0 ? std::fabs(static_cast<double>({magnitude}))'
                           f' : -std::fabs(static_cast<double>({magnitude})))')
            edits.append((call.start_byte, call.end_byte, replacement))
    elif name == 'contrl_':
        calls = [node for node in nodes(function) if node.type == 'call_expression'
                 and content(node, data) in ('sqrt(head)', 'sqrt(slope)')]
        if len(calls) != 5:
            raise ValueError('The expected five CONTRL REAL square-root uses changed.')
        for call in calls:
            edits.append((call.start_byte, call.end_byte,
                          'static_cast<float>('+content(call, data)+')'))
        edits.append((function.child_by_field_name('body').start_byte+1,
                      function.child_by_field_name('body').start_byte+1,
                      '\n    // Original 0x422d03 and 0x422eb9 store REAL SQRT results as binary32.\n'))
    elif name == 'bdyflw_':
        declarations = [node for node in nodes(function) if node.type == 'declaration'
                        and content(node, data) == 'real temp;']
        if len(declarations) != 1:
            raise ValueError('The expected BDYFLW temporary declaration changed.')
        node = declarations[0]
        edits.append((node.start_byte, node.end_byte,
                      '// TEMP = -node_sign * (old_flow + weight * (new_flow - old_flow)).\n'
                      '    // Original 0x474eab-0x474ee8 accumulates without a binary32 TEMP store.\n'
                      '    doublereal temp;'))
    elif name == 'interp_':
        selected = {'feq_gen_h_d_', 'dx', 'fac'}
        found = set()
        for node in nodes(function):
            if node.type != 'declaration' or content(node.child_by_field_name('type'),data) != 'real':
                continue
            declarators = node.children_by_field_name('declarator')
            if not declarators or any(item.type != 'identifier' for item in declarators):
                continue
            names = [content(item,data) for item in declarators]
            wide = [item for item in names if item in selected]
            if not wide:
                continue
            narrow = [item for item in names if item not in selected]
            replacement = ('real '+', '.join(narrow)+';\n    ' if narrow else '')+'doublereal '+', '.join(wide)+';'
            edits.append((node.start_byte,node.end_byte,replacement))
            found.update(wide)
        if found != selected:
            raise ValueError('The expected INTERP distance and fraction declarations changed.')
        expressions = [node for node in nodes(function) if node.type == 'assignment_expression'
                       and content(node,data) == 'fac = static_cast<double>(feq_gen_h_d_) / dx']
        if len(expressions) != 2:
            raise ValueError('The expected two INTERP fractions changed.')
        for node in expressions:
            edits.append((node.start_byte,node.end_byte,'fac = feq_gen_h_d_ * (1.0 / dx)'))
        edits.append((function.child_by_field_name('body').start_byte+1,
                      function.child_by_field_name('body').start_byte+1,
                      '\n    // Original 0x434aed and 0x435403 use a retained reciprocal for each station fraction.\n'))
    else:
        raise ValueError('Unrecognized traced routine: '+name)
    return edit_text(data, edits).decode()


def restore_steady_initialization(body):
    """Preserve SFPSBM registers while making its output argument stores explicit."""
    data = body.encode()
    function = functions(data)[0]
    selected = set(('feq_gen_r_d_1 feq_gen_r_d_2 am ck km dy qm vl vr wx xl xr zl zr '
                    'fac dem sfm dvm elev sgndv res dg div yta').split())
    found = set()
    edits = []
    output_copies = set()
    for node in nodes(function):
        if node.type == 'declaration' and content(node.child_by_field_name('type'),data) == 'real':
            declarators = node.children_by_field_name('declarator')
            if declarators and all(item.type == 'identifier' for item in declarators):
                names = [content(item,data) for item in declarators]
                wide = [item for item in names if item in selected]
                narrow = [item for item in names if item not in selected]
                if wide:
                    replacement = ('real '+', '.join(narrow)+';\n    ' if narrow else '')+'doublereal '+', '.join(wide)+';'
                    edits.append((node.start_byte,node.end_byte,replacement))
                    found.update(wide)
        if node.type != 'call_expression':
            continue
        called = content(node.child_by_field_name('function'),data)
        text = content(node,data)
        match = re.search(r'\(char \*\)&(\w+),',text) if called == 'do_fio' else None
        if match and match[1] in selected:
            name = match[1]
            temporary = 'feq_output_'+name
            replacement = '('+temporary+' = static_cast<float>('+name+'), '+text.replace('&'+name+',','&'+temporary+',')+')'
            output_copies.add(temporary)
            edits.append((node.start_byte,node.end_byte,replacement))
        elif called == 'i_nint' and text == 'i_nint(&feq_gen_r_d_1)':
            output_copies.add('feq_output_feq_gen_r_d_1')
            edits.append((node.start_byte,node.end_byte,
                '(feq_output_feq_gen_r_d_1 = static_cast<float>(feq_gen_r_d_1), i_nint(&feq_output_feq_gen_r_d_1))'))
    if found != selected:
        raise ValueError('The expected SFPSBM scalar declarations changed: '+str(sorted(selected-found)))
    position = function.child_by_field_name('body').start_byte+1
    prefix = ('\n    // SFPSBM holds hydraulic temporaries in 53-bit registers.\n'
              '    // In particular KM squared must not pass through a binary32 translation temporary.\n'
              '    // Output statements store separate REAL argument copies, as in the original assembly.\n'
              '    real '+', '.join(sorted(output_copies))+';\n')
    edits.append((position,position,prefix))
    return edit_text(data,edits).decode()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('source',type=Path)
    parser.add_argument('output',type=Path)
    parser.add_argument('--setinx-distance-rounding',action='store_true',
                        help='Reproduce the independently traced reciprocal and binary32 DXDT store in SETINX.')
    parser.add_argument('--traced-register-stores',action='store_true',
                        help='Restore traced SETINX, CONTRL, BDYFLW, and INTERP register/store behavior.')
    parser.add_argument('--steady-initialization-registers',action='store_true',
                        help='Restore SFPSBM register temporaries with separate REAL output argument stores.')
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
            if name in ('xlkt20_','xxlkt20_','xlkt21_'):
                begin = body.index('/*     FETCH VALUES FROM FTAB */')
                end = body.rindex('    return 0;')
                call = ('feq_interpolate_section_interval_moment(l,l+xoff,doff,*ya,a,t,dt,j,k,dk,b,db);'
                        if name == 'xlkt21_' else 'feq_interpolate_section_interval(l,l+xoff,doff,*ya,a,t,dt,k,dk,b,db);')
                body = body[:begin]+'    '+call+'\n'+body[end:]
                needs_declaration = True
                changes.append({'file':path.name,'function':name,'component':'src/section_interpolation.cpp',
                                'verification':'Original-executable fixture replay; see tests/reference/section_interpolation and section_first_moment.'})
            elif name == 'lktab_':
                begin = body.index('L2:')
                end = body.index('L5:',begin)
                body = body[:begin]+('L2:\nL3:\nL4:\n'
                    '    feq_interpolate_function_interval(feq_gen_type_d_,lsta,inc,arg,func,pdv);\n'
                    '    goto L1000;\n')+body[end:]
                needs_declaration = True
                changes.append({'file':path.name,'function':name,'component':'src/table_interpolation.cpp',
                                'verification':'360 original-executable fixtures; all value and derivative bits exact.'})
            elif name == 'sfpsbm_' and args.steady_initialization_registers:
                body = restore_steady_initialization(body)
                changes.append({'file':path.name,'function':name,
                                'rounding':'Retained scalar and power temporaries; separate REAL stores for output arguments.',
                                'evidence':'recovery/assembly/feq/_sfpsbm_.asm'})
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
                if not args.traced_register_stores or name not in ('setinx_','contrl_','bdyflw_','interp_'):
                    continue
            if args.traced_register_stores and name in ('setinx_','contrl_','bdyflw_','interp_'):
                body = restore_traced_precision(body, name)
                changes.append({'file':path.name,'function':name,
                                'rounding':'Restore original register precision and explicit binary32 stores.',
                                'evidence':'recovery/NUMERICAL_PROBES.md'})
            edits.append((function.start_byte,function.end_byte,body))
        result = edit_text(data,edits)
        if needs_declaration:
            result = DECLARATION.encode()+result
        if args.traced_register_stores and path.name == 'brnmat.cpp':
            result = b'#include <cmath>\n'+result
        (output/path.name).write_bytes(result)
    manifest = {'status':'Research integration; passing component fixtures does not establish whole-engine acceptance.',
                'changes':changes,'source_files':[{'name':path.name,'sha256':hashlib.sha256(path.read_bytes()).hexdigest()}
                                                for path in sorted(source.glob('*.cpp'))]}
    (output/'verified-components.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print(f'{len(changes)} component or rounding integrations recorded.')


if __name__ == '__main__':
    main()
