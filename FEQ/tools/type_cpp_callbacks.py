#!/usr/bin/env python3
"""Give each historical callback its verified concrete C++ function type."""
import argparse
import hashlib
import json
from pathlib import Path
import re

from prepare_cpp_probe import PARSER, content, edit_text, functions, identifier, nodes


def parameter_type(parameter, data):
    kind = content(parameter.child_by_field_name('type'), data)
    declarator = parameter.child_by_field_name('declarator')
    while declarator is not None and declarator.type != 'identifier':
        if declarator.type == 'pointer_declarator':
            kind += '*'
        else:
            raise ValueError('Unreviewed parameter declarator: '+str(declarator))
        declarator = declarator.child_by_field_name('declarator')
    return kind


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('directory', type=Path)
    args = parser.parse_args()
    files, definitions, contexts = {}, {}, []
    for path in sorted(args.directory.glob('*.cpp')):
        data = path.read_bytes()
        files[path] = data
        for function in functions(data):
            declarator = function.child_by_field_name('declarator')
            name = content(identifier(declarator), data)
            params = declarator.child_by_field_name('parameters').named_children
            kinds = tuple(parameter_type(p, data) for p in params)
            names = tuple(content(identifier(p.child_by_field_name('declarator')), data) for p in params)
            definitions[name] = (content(function.child_by_field_name('type'), data), kinds, names)
            contexts.append((path, name, function, data))
    callbacks = {(name, i):set() for name, (_, kinds, _) in definitions.items()
                 for i,kind in enumerate(kinds) if kind.endswith('_fp')}
    links, evidence = [], []
    for path, name, function, data in contexts:
        local_callbacks = {definitions[name][2][i]:(name,i) for i in range(len(definitions[name][1])) if (name,i) in callbacks}
        for node in nodes(function.child_by_field_name('body')):
            if node.type != 'call_expression':
                continue
            callee = content(node.child_by_field_name('function'), data)
            arguments = node.child_by_field_name('arguments').named_children
            if callee not in definitions:
                continue
            for index, argument in enumerate(arguments):
                key = (callee,index)
                if key not in callbacks:
                    continue
                source = re.sub(r'^\s*\(\s*\w+_fp\s*\)\s*', '', content(argument, data)).strip()
                if source in local_callbacks:
                    links.append((key,local_callbacks[source]))
                elif source in definitions:
                    return_type, kinds, unused = definitions[source]
                    callbacks[key].add((return_type,kinds))
                    evidence.append({'caller':name,'callee':callee,'argument_index':index,
                                     'callback':source,'file':path.name,'line':node.start_point.row+1})
                else:
                    raise ValueError(f'Unknown callback argument {source} in {name} -> {callee}')
    changed = True
    while changed:
        changed = False
        for first,second in links:
            combined = callbacks[first] | callbacks[second]
            if callbacks[first] != combined or callbacks[second] != combined:
                callbacks[first] = combined.copy()
                callbacks[second] = combined.copy()
                changed = True
    # These general routines are present but are not called elsewhere in the
    # released sources. Their bodies call F with a single declared REAL*8.
    body_verified = {
        ('feq_gen_bisect_d_d_',3):('doublereal',('doublereal*',)),
        ('feq_gen_find_root_interval_d_',1):('doublereal',('doublereal*',)),
    }
    for key,signature in body_verified.items():
        if key in callbacks and not callbacks[key]:
            callbacks[key].add(signature)
            evidence.append({'callee':key[0],'argument_index':key[1],
                             'evidence':'Unused generic routine; callback invocation and local argument declaration inspected.'})
    invalid = {str(key):list(value) for key,value in callbacks.items() if len(value) != 1}
    if invalid:
        raise ValueError('Callback types must be unique and known: '+json.dumps(invalid))
    concrete = {key:next(iter(value)) for key,value in callbacks.items()}
    signatures = sorted(set(concrete.values()))
    aliases = {signature:'FeqCallback'+str(index+1) for index,signature in enumerate(signatures)}
    header = ['#ifndef FEQ_PROBE_CALLBACKS_HPP', '#define FEQ_PROBE_CALLBACKS_HPP', '#include "common.hpp"']
    for signature in signatures:
        return_type, kinds = signature
        header.append('typedef '+return_type+' (*'+aliases[signature]+')('+', '.join(kinds)+');')
    header.append('#endif')
    (args.directory/'callbacks.hpp').write_text('\n'.join(header)+'\n')
    records = []
    for path,data in files.items():
        edits = []
        for node in nodes(PARSER.parse(data).root_node):
            if node.type == 'function_declarator':
                try:
                    name = content(identifier(node),data)
                except ValueError:
                    continue
                if name not in definitions:
                    continue
                parameters = node.child_by_field_name('parameters')
                parameter_nodes = parameters.named_children
                return_type,kinds,names = definitions[name]
                if '...' in content(parameters,data):
                    replacements = [aliases[concrete[(name,i)]] if (name,i) in concrete else kind for i,kind in enumerate(kinds)]
                    edits.append((parameters.start_byte,parameters.end_byte,'('+', '.join(replacements)+')'))
                else:
                    for index,parameter in enumerate(parameter_nodes):
                        if (name,index) in concrete:
                            type_node = parameter.child_by_field_name('type')
                            edits.append((type_node.start_byte,type_node.end_byte,aliases[concrete[(name,index)]]))
            elif node.type == 'cast_expression':
                cast_type = node.child_by_field_name('type')
                value = node.child_by_field_name('value')
                if cast_type is not None and re.fullmatch(r'\w+_fp',content(cast_type,data)):
                    edits.append((node.start_byte,node.end_byte,content(value,data)))
        result = edit_text(data,edits)
        if edits:
            result = b'#include "callbacks.hpp"\n'+result
            path.write_bytes(result)
        records.append({'file':path.name,'edits':len(edits),'before_sha256':hashlib.sha256(data).hexdigest(),
                        'after_sha256':hashlib.sha256(result).hexdigest()})
    (args.directory/'callback-types.json').write_text(json.dumps({
        'types':{alias:{'return':signature[0],'arguments':signature[1]} for signature,alias in aliases.items()},
        'evidence':evidence,'files':records},indent=2)+'\n')
    print(f'{len(callbacks)} callback parameters; {len(signatures)} concrete signatures; {len(evidence)} recorded call constraints.')


if __name__ == '__main__':
    main()
