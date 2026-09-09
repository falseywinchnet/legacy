#!/usr/bin/env python3
"""Probe explicit 53-bit arithmetic between the original REAL*4 stores.

The original executable's x87 control word is recorded in startup-state.json.
This experiment asks Clang for semantic operand types, then inserts explicit
double casts. It changes neither declared storage nor explicit source casts.
The generated program still requires differential validation against the binary.
"""
import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import shutil
import subprocess

ROOT = Path(__file__).resolve().parents[1]


def descendants(root):
    pending = [root]
    while pending:
        node = pending.pop()
        yield node
        pending.extend(reversed(node.get('inner', [])))


def scalar_type(node):
    value = node.get('type', {})
    return value.get('desugaredQualType', value.get('qualType'))


def source_location(location):
    if location.get('expansionLoc', {}).get('isMacroArgExpansion'):
        return location['spellingLoc']
    return location.get('expansionLoc', location)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('source', type=Path)
    parser.add_argument('output', type=Path)
    parser.add_argument('--file', action='append', default=[])
    parser.add_argument('--compiler', default='c++')
    parser.add_argument('--runtime', type=Path, default=ROOT/'build/f2c/lib32')
    args = parser.parse_args()
    output = args.output.resolve()
    source = args.source.resolve()
    if ROOT/'build' not in output.parents or output == source:
        parser.error('Use a separate FEQ/build/ directory for the experiment.')
    output.mkdir(parents=True, exist_ok=True)
    for path in source.glob('*.hpp'):
        shutil.copy2(path, output/path.name)
    records = []
    for path in sorted(source.glob('*.cpp')):
        original = path.read_bytes()
        if path.stem in ('common','dynamic_storage') or (args.file and path.name not in args.file):
            (output/path.name).write_bytes(original)
            continue
        prefix = b'#include "common.hpp"\n'
        if (source/'callbacks.hpp').is_file():
            prefix += b'#include "callbacks.hpp"\n'
        prefix += b'namespace feq_arithmetic_probe {\n'
        temporary = output/'arithmetic-input.cpp.txt'
        temporary.write_bytes(prefix+original+b'\n}\n')
        ast_path = output/'arithmetic-ast.json'
        command = [args.compiler, '-x', 'c++', '-std=c++20', '-fstrict-aliasing', '-ffp-contract=off',
                   '-fno-fast-math', '-Wno-vexing-parse', '-Wno-shift-op-parentheses',
                   '-I', str(ROOT/'include'), '-iquote', str(args.runtime.resolve()),
                   '-iquote', str(source), '-Xclang', '-ast-dump=json', '-Xclang',
                   '-ast-dump-filter=feq_arithmetic_probe', '-fsyntax-only', str(temporary)]
        with ast_path.open('wb') as sink:
            process = subprocess.run(command, stdout=sink, stderr=subprocess.PIPE)
        (output/(path.stem+'.arithmetic.log')).write_bytes(process.stderr)
        if process.returncode:
            raise RuntimeError('Semantic analysis failed for '+path.name+'; inspect its arithmetic log.')
        ast = json.loads(ast_path.read_bytes())
        expressions = []
        boundaries = set()
        for node in descendants(ast):
            kind, operation = node.get('kind'), node.get('opcode')
            if scalar_type(node) != 'float':
                continue
            if kind == 'BinaryOperator' and operation in ('+', '-', '*', '/'):
                operand = node['inner'][0]
            elif kind == 'CompoundAssignOperator' and operation in ('+=', '-=', '*=', '/='):
                if node.get('computeResultType', {}).get('qualType') != 'float':
                    continue
                # Promotion of the RHS makes the compound computation double
                # precision and evaluates the destination exactly once.
                operand = node['inner'][1]
            else:
                continue
            begin = source_location(operand['range']['begin'])
            end = source_location(operand['range']['end'])
            start = begin['offset']-len(prefix)
            stop = end['offset']+end['tokLen']-len(prefix)
            if not (0 <= start < stop <= len(original)):
                raise ValueError('Arithmetic operand outside the source file: '+path.name)
            boundaries.add((start,stop))
            expressions.append({'operation':operation,'line':original[:start].count(b'\n')+1,
                                'operand':original[start:stop].decode(), 'start':start,'end':stop})
        opens, closes = Counter(), Counter()
        for start,stop in boundaries:
            opens[start] += 1
            closes[stop] += 1
        positions = sorted(set(opens) | set(closes))
        pieces, previous = [], 0
        for position in positions:
            pieces.append(original[previous:position])
            pieces.append(b')'*closes[position])
            pieces.append(b'static_cast<double>('*opens[position])
            previous = position
        pieces.append(original[previous:])
        result = b''.join(pieces)
        (output/path.name).write_bytes(result)
        records.append({'file':path.name,'input_sha256':hashlib.sha256(original).hexdigest(),
                        'output_sha256':hashlib.sha256(result).hexdigest(),
                        'expressions':expressions, 'cast_count':len(boundaries)})
        print(path.name+': '+str(len(boundaries))+' explicit intermediate promotions.', flush=True)
    (output/'real-intermediates.json').write_text(json.dumps(records,indent=2)+'\n')
    (output/'arithmetic-input.cpp.txt').unlink(missing_ok=True)
    (output/'arithmetic-ast.json').unlink(missing_ok=True)
    print(str(sum(r['cast_count'] for r in records))+' explicit casts in '+str(len(records))+' inspected files.')


if __name__ == '__main__':
    main()
