#!/usr/bin/env python3
"""Prepare strictly typed C++ research engines from recorded f2c output.

Generated historical code retains its original notices. This tool does not
assert numerical equivalence or turn that code into an MIT-licensed work.
Every applied storage transformation is recorded beside the generated files.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re

import tree_sitter
import tree_sitter_cpp

ROOT = Path(__file__).resolve().parents[1]
PARSER = tree_sitter.Parser(tree_sitter.Language(tree_sitter_cpp.language()))


def nodes(root):
    stack = [root]
    while stack:
        node = stack.pop()
        yield node
        stack.extend(reversed(node.named_children))


def edit_text(data, edits):
    previous = len(data)+1
    for start, end, replacement in sorted(edits, reverse=True):
        if end > previous:
            raise ValueError(f'Overlapping source edits at {start}:{end}')
        data = data[:start]+replacement.encode()+data[end:]
        previous = start
    return data


def content(node, data):
    return data[node.start_byte:node.end_byte].decode()


def identifier(declarator):
    node = declarator
    while node is not None and node.type != 'identifier':
        node = node.child_by_field_name('declarator')
    if node is None:
        raise ValueError('Declarator without an identifier: '+str(declarator))
    return node


def functions(data):
    return [n for n in nodes(PARSER.parse(data).root_node) if n.type == 'function_definition']


COMMON = re.compile(r'^struct\s*\{(?P<body>.*?)\}\s*(?P<name>\w+)\s*;', re.M|re.S)
OVERLAY = re.compile(r'^#define\s+(\w+)\s+\(\((real|integer)\s*\*\)([^\n]+)\)$', re.M)


def prepare_file(data, common, initializers, events):
    text = data.decode()
    first = min(n.start_byte for n in functions(data))
    prologue = text[:first]
    edits = []
    for match in COMMON.finditer(prologue):
        name, body = match['name'], match['body']
        normalized = re.sub(r'/\*.*?\*/|\s+', '', body, flags=re.S)
        if name in common and common[name]['normalized'] != normalized:
            raise ValueError('Inconsistent COMMON layout: '+name)
        common[name] = {'body': body, 'normalized': normalized}
        edits.append((match.start(), match.end(), '/* COMMON '+name+' is declared in common.hpp. */'))
    # BLOCK DATA for OFFCOM is emitted with individual scalar members by f2c.
    # Preserve its 35 integer values in the canonical declared array instead.
    init = re.search(r'struct\s*\{\s*integer e_1\[35\];\s*\}\s*offcom_\s*=\s*\{(.*?)\};', prologue, re.S)
    if init:
        values = [value.strip() for value in init[1].split(',') if value.strip()]
        if len(values) != 35 or any(not re.fullmatch(r'-?\d+', v) for v in values):
            raise ValueError('Unexpected OFFCOM initialized representation: '+str(values))
        initializers['offcom_'] = '{ {'+', '.join(values)+'} }'
        common.setdefault('offcom_', {'body': '\n    integer offvec[35];\n', 'normalized': 'integeroffvec[35];'})
        edits.append((init.start(), init.end(), '/* OFFCOM BLOCK DATA is defined in common.cpp. */'))
    data = edit_text(data, edits)
    text = data.decode()
    text = re.sub(r'struct offcom_1_\s*\{.*?\};', '', text, flags=re.S)
    text = text.replace('#define offcom_1 (*(struct offcom_1_ *) &offcom_)', '#define offcom_1 offcom_')

    def overlay(match):
        name, kind, address = match.groups()
        address = address.strip()
        if address == '&ftablea_1 + 2':
            replacement = f'(feq::BitView<{kind}>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))'
        elif re.fullmatch(r'&\w+', address):
            replacement = f'(feq::BitView<{kind}>({address}, sizeof({address[1:]})))'
        elif re.fullmatch(r'equiv_\d+', address):
            replacement = f'(feq::BitView<{kind}>({address}, sizeof({address})))'
        else:
            raise ValueError('Unrecognized EQUIVALENCE overlay: '+match[0])
        events.append({'operation': 'bit-overlay', 'name': name, 'storage': address, 'type': kind})
        return '#define '+name+' '+replacement

    text = OVERLAY.sub(overlay, text)
    data = text.encode()
    edits = []
    for function in functions(data):
        body = function.child_by_field_name('body')
        declaration = function.child_by_field_name('declarator')
        function_name = content(identifier(declaration), data)
        body_text = content(body, data)
        adjustment = re.search(r'/\* Parameter adjustments \*/(.*?)/\* Function Body \*/', body_text, re.S)
        if adjustment:
            parameters = declaration.child_by_field_name('parameters')
            parameter_map = {}
            for parameter in parameters.named_children:
                ident = identifier(parameter.child_by_field_name('declarator'))
                parameter_map[content(ident, data)] = (parameter, ident)
            region_start = body.start_byte+adjustment.start(1)
            for match in re.finditer(r'(?m)^\s*(?:--(\w+)|(\w+)\s*-=\s*([^;]+));', adjustment[1]):
                name, bias = (match[1], '1') if match[1] else (match[2], match[3].strip())
                if name not in parameter_map:
                    raise ValueError(f'{function_name}: adjustment of a non-argument {name}')
                parameter, ident = parameter_map[name]
                kind = content(parameter.child_by_field_name('type'), data)
                edits.append((ident.start_byte, ident.end_byte, 'feq_storage_'+name))
                edits.append((region_start+match.start(), region_start+match.end(),
                              '\n    feq::IndexedPointer<'+kind+'> '+name+'(feq_storage_'+name+', '+bias+');'))
                events.append({'operation': 'indexed-argument', 'function': function_name, 'name': name, 'bias': bias, 'type': kind})
        view_names = set(re.findall(r'^#define (\w+) \(feq::BitView<', body_text, re.M))
        scalar_names = set(re.findall(r'^#define (\w+) \(feq::BitReference<', body_text, re.M))
        for node in nodes(body):
            if node.type != 'pointer_expression' or not content(node, data).lstrip().startswith('&'):
                continue
            argument = node.child_by_field_name('argument')
            if argument is None:
                continue
            if argument.type == 'subscript_expression':
                base = argument.child_by_field_name('argument')
                subscripts = argument.child_by_field_name('indices')
                name = content(base, data)
                if name in view_names:
                    index = content(subscripts, data)[1:-1]
                    edits.append((node.start_byte, node.end_byte, name+'.lease('+index+').data()'))
                    events.append({'operation': 'scalar-bit-argument', 'function': function_name, 'name': name})
            elif argument.type == 'identifier' and content(argument, data) in scalar_names:
                name = content(argument, data)
                edits.append((node.start_byte, node.end_byte, name+'.lease().data()'))
                events.append({'operation': 'scalar-bit-argument', 'function': function_name, 'name': name})
    data = edit_text(data, edits)
    # Literal Fortran arguments are immutable. f2c's old ABI lacks const on
    # read-only arguments. A cast is explicit and never used for an output.
    edits = []
    for node in nodes(PARSER.parse(data).root_node):
        if node.type not in ('string_literal', 'concatenated_string'):
            continue
        if node.parent.type in ('argument_list', 'assignment_expression'):
            edits.append((node.start_byte, node.end_byte, 'const_cast<char*>('+content(node, data)+')'))
        elif node.parent.type == 'init_declarator':
            declarator = node.parent.child_by_field_name('declarator')
            if declarator.type == 'pointer_declarator':
                edits.append((node.start_byte, node.end_byte, 'const_cast<char*>('+content(node, data)+')'))
    data = edit_text(data, edits)
    text = data.decode()
    text = text.replace('#ifdef __cplusplus\nextern "C" {', '#include "common.hpp"\n#ifdef __cplusplus\nextern "C" {', 1)
    return text


def renamed(text):
    token = re.compile(r'(/\*.*?\*/|//[^\n]*|"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\')|([A-Za-z_][A-Za-z_0-9]*)', re.S)
    def convert(match):
        word = match[2]
        if word in ('not', 'and', 'or', 'xor', 'compl', 'bitand', 'bitor', 'and_eq', 'or_eq', 'xor_eq', 'not_eq'):
            return 'feq_keyword_'+word
        if word and '__' in word and word != '__cplusplus':
            return 'feq_gen_'+word.replace('__', '_d_')
        return match[0]
    return token.sub(convert, text)


def debug_matrix_compatibility(text, events):
    """Preserve the shipped SAVEMAT 8-byte copy despite its 4-byte callers."""
    data = text.encode()
    matches = [f for f in functions(data) if content(identifier(f.child_by_field_name('declarator')), data) == 'savemat_']
    if not matches:
        return text
    function = matches[0]
    replacement = r'''int savemat_(integer *n, integer *m, real *pdavec, real *rhs,
             real *pdavec2, real *rhs2) {
    // Released ntmatrix.for:636-647 declares these REAL*8, although the
    // shipped solver's MATCOM and MATCOM2 arrays are REAL*4. Original binary
    // RVA 0x75c00 copies 8*N bytes of RHS, then 8*M bytes of PDAVEC.
    // Preserve that observed copy, using each complete COMMON object as the
    // byte-storage boundary. No typed double pointer aliases a float array.
    if (pdavec != matcom_1.pdavec || rhs != matcom_1.rhs ||
        pdavec2 != matcom2_1.pdavec2 || rhs2 != matcom2_1.rhs2) {
        throw std::invalid_argument("SAVEMAT expected the released COMMON arrays.");
    }
    const std::size_t rhs_bytes = feq::checked_extent(*n > 0 ? *n : 0, 8);
    const std::size_t matrix_bytes = feq::checked_extent(*m > 0 ? *m : 0, 8);
    feq::copy_object_bytes(&matcom2_, sizeof(matcom2_), offsetof(Common_matcom2_, rhs2),
                           &matcom_, sizeof(matcom_), offsetof(Common_matcom_, rhs), rhs_bytes);
    feq::copy_object_bytes(&matcom2_, sizeof(matcom2_), offsetof(Common_matcom2_, pdavec2),
                           &matcom_, sizeof(matcom_), offsetof(Common_matcom_, pdavec), matrix_bytes);
    return 0;
}'''
    events.append({'operation':'released-debug-copy', 'function':'savemat_',
                   'source':'ntmatrix.for:636-647', 'binary_rva':'0x75c00',
                   'copy_width':8, 'caller_storage_width':4})
    return edit_text(data, [(function.start_byte,function.end_byte,replacement)]).decode()


def symbol(name):
    return name+('__' if '_' in name else '_')


def wrappers(source, output, texts):
    result = ['#include "common.hpp"', 'extern "C" {']
    for record in json.loads((source/'lowering-manifest.json').read_text()):
        data = texts[Path(record['file']).stem].encode()
        for wrapper in record.get('dynamic_wrappers', []):
            name = symbol(wrapper['implementation'])
            function = next(f for f in functions(data) if content(identifier(f.child_by_field_name('declarator')), data) == name)
            declarator = function.child_by_field_name('declarator')
            parameters = declarator.child_by_field_name('parameters').named_children
            params = [(content(p, data), content(identifier(p.child_by_field_name('declarator')), data)) for p in parameters]
            argument_count = len(wrapper['arguments'])
            array_count = len(wrapper['arrays'])
            names = {a['name']:params[i][1] for i,a in enumerate(wrapper['arguments'])}
            original_length_count = sum(a['kind'].startswith('character') for a in wrapper['arguments'])
            public_params = params[:argument_count]+params[argument_count+array_count:argument_count+array_count+original_length_count]
            result.append('int '+name+'('+', '.join(p[0] for p in params)+');')
            result.append('// Dynamic local storage. Source: '+wrapper['origin'])
            result.append('int '+symbol(wrapper['name'])+'('+', '.join(p[0] for p in public_params)+') {')
            allocated = []
            extra_lengths = []
            for index,array in enumerate(wrapper['arrays']):
                kind = {'integer':'integer','real*8':'doublereal','real':'real','character*1':'char'}[array['kind']]
                cpp_name = params[argument_count+index][1]
                dimensions = ['static_cast<std::int64_t>(*'+names[d]+')' for d in array['dimensions']]
                result.append('    std::vector<'+kind+'> '+cpp_name+'(feq::checked_extent('+', '.join(dimensions)+'));')
                allocated.append(cpp_name+'.data()')
                if kind == 'char':
                    extra_lengths.append('1')
            arguments = [p[1] for p in params[:argument_count]]+allocated+[p[1] for p in public_params[argument_count:]]+extra_lengths
            result.append('    return '+name+'('+', '.join(arguments)+');')
            result.append('}')
    result.append('}')
    (output/'dynamic_storage.cpp').write_text(renamed('\n'.join(result)+'\n'))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('source', type=Path)
    parser.add_argument('output', type=Path)
    args = parser.parse_args()
    output = args.output.resolve()
    if ROOT/'build' not in output.parents:
        parser.error('Research source products must stay under FEQ/build/.')
    output.mkdir(parents=True, exist_ok=True)
    common, initializers, records, texts = {}, {}, [], {}
    for path in sorted(args.source.glob('*.c')):
        data = path.read_bytes()
        events = []
        converted = prepare_file(data, common, initializers, events)
        if path.stem == 'ntmatrix' and re.search(r'\breal\s+pdavec\[', common['matcom_']['body']):
            converted = debug_matrix_compatibility(converted, events)
        texts[path.stem] = converted
        (output/(path.stem+'.cpp')).write_text(renamed(converted))
        records.append({'file':path.name, 'input_sha256':hashlib.sha256(data).hexdigest(), 'transformations':events})
    header = ['#ifndef FEQ_PROBE_COMMON_HPP', '#define FEQ_PROBE_COMMON_HPP',
              '#include <feq/storage.hpp>', '#include <vector>', '#include <string>', '#include <cmath>',
              '#undef stdin', '#undef stdout', '#undef stderr', '#include "f2c.h"', 'extern "C" {']
    definitions = ['#include "common.hpp"', 'extern "C" {']
    for name in sorted(common):
        header.append('struct Common_'+name+' {'+common[name]['body']+'};')
        header.append('extern Common_'+name+' '+name+';')
        definitions.append('Common_'+name+' '+name+' = '+initializers.get(name, '{}')+';')
    header.extend(['}', '#endif'])
    definitions.append('}')
    (output/'common.hpp').write_text(renamed('\n'.join(header)+'\n'))
    (output/'common.cpp').write_text(renamed('\n'.join(definitions)+'\n'))
    wrappers(args.source, output, texts)
    (output/'cpp-preparation.json').write_text(json.dumps({'files':records, 'common_blocks':len(common)}, indent=2)+'\n')
    print(f'{len(records)} source files; {len(common)} unified COMMON blocks; '+str(sum(len(r['transformations']) for r in records))+' recorded transformations.')


if __name__ == '__main__':
    main()
