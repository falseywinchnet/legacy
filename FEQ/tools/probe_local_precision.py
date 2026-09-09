#!/usr/bin/env python3
"""Generate a research candidate with non-addressed REAL locals held as double.

This is a hypothesis generator, not a correctness rule. Original Lahey code
often holds source REAL locals in x87 registers or 80-bit spills, but actual
stores and expression reuse must still be verified against machine code.
New work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
"""
import argparse
import hashlib
import json
from pathlib import Path
import shutil

from prepare_cpp_probe import content, edit_text, functions, identifier, nodes

ROOT = Path(__file__).resolve().parents[1]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('source', type=Path)
    parser.add_argument('output', type=Path)
    parser.add_argument('--function', action='append', default=[])
    args = parser.parse_args()
    source, output = args.source.resolve(), args.output.resolve()
    if output.exists() or ROOT/'build' not in output.parents:
        parser.error('Use a new FEQ/build/ directory.')
    output.mkdir(parents=True)
    for path in source.glob('*.hpp'):
        shutil.copy2(path, output/path.name)
    records = []
    for path in sorted(source.glob('*.cpp')):
        original = path.read_bytes()
        edits = []
        for function in functions(original):
            name = content(identifier(function.child_by_field_name('declarator')), original)
            if args.function and name not in args.function:
                continue
            body = function.child_by_field_name('body')
            addressed = set()
            for node in nodes(body):
                if node.type == 'pointer_expression' and content(node, original).lstrip().startswith('&'):
                    argument = node.child_by_field_name('argument')
                    if argument.type == 'identifier':
                        addressed.add(content(argument, original))
            for node in nodes(body):
                if node.type != 'declaration' or content(node.child_by_field_name('type'), original) != 'real':
                    continue
                declarators = node.children_by_field_name('declarator')
                if not declarators or any(item.type != 'identifier' for item in declarators):
                    continue
                names = [content(item, original) for item in declarators]
                wide = [item for item in names if item not in addressed]
                narrow = [item for item in names if item in addressed]
                if not wide:
                    continue
                replacement = ('real '+', '.join(narrow)+';\n    ' if narrow else '')+'doublereal '+', '.join(wide)+';'
                edits.append((node.start_byte, node.end_byte, replacement))
                records.append({'file': path.name, 'function': name, 'line': node.start_point.row+1,
                                'wide_candidates': wide, 'addressed_locals_retained': narrow})
        changed = edit_text(original, edits)
        (output/path.name).write_bytes(changed)
    manifest = {'status': 'Unverified precision experiment; never infer acceptance from promotion alone.',
                'source_files': [{'name': path.name, 'sha256': hashlib.sha256(path.read_bytes()).hexdigest()}
                                 for path in sorted(source.glob('*.cpp'))], 'changes': records}
    (output/'local-precision.json').write_text(json.dumps(manifest, indent=2)+'\n')
    print(f'{sum(len(record["wide_candidates"]) for record in records)} local precision candidates in {len(set(record["function"] for record in records))} functions.')


if __name__ == '__main__':
    main()
