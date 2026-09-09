#!/usr/bin/env python3
"""Link a compiled FEQ research candidate with the independently verified core.

All authored components are rebuilt for this link. Historical translation
objects must have a successful, current source-hash compilation receipt.
This tool produces a research executable, not an accepted end-user release.
Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
"""
import argparse
import hashlib
import json
from pathlib import Path
import subprocess
from compile_cpp_probe import header_inputs, header_digest

ROOT = Path(__file__).resolve().parents[1]


def sha256(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('directory', type=Path)
    parser.add_argument('--runtime', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--compiler', default='c++')
    parser.add_argument('--matrix-trace', action='store_true')
    args = parser.parse_args()
    directory, runtime, output = args.directory.resolve(), args.runtime.resolve(), args.output.resolve()
    object_directory = output.with_name(output.name+'.objects')
    if output.exists() or object_directory.exists() or ROOT/'build' not in output.parents:
        parser.error('Use a new executable path under FEQ/build/.')
    receipts = json.loads((directory/'compile-manifest.json').read_text())
    headers = header_inputs(directory, runtime)
    headers_sha256 = header_digest(headers)
    paths = sorted(directory.glob('*.cpp'))
    if {record['file'] for record in receipts} != {path.name for path in paths}:
        raise ValueError('Compilation receipt does not cover the exact translation file set.')
    by_name = {record['file']:record for record in receipts}
    objects = []
    inputs = []
    for path in paths:
        record = by_name[path.name]
        if record['exit'] != 0 or record['sha256'] != sha256(path):
            raise ValueError('Source changed or failed to compile: '+path.name)
        if record.get('headers_sha256') != headers_sha256:
            raise ValueError('Headers changed or compilation receipt predates header verification: '+path.name)
        if path.name == 'linsys.cpp':
            continue
        obj = path.with_suffix('.o')
        if not obj.is_file():
            raise ValueError('Compiled object is missing: '+obj.name)
        if record.get('object_sha256') != sha256(obj):
            raise ValueError('Object changed since compilation: '+obj.name)
        objects.append(obj)
        inputs.append({'source':str(path),'source_sha256':sha256(path),
                       'object':str(obj),'object_sha256':sha256(obj)})
    object_directory.mkdir(parents=True)
    flags = ['-std=c++20','-pedantic-errors','-fstrict-aliasing','-ffp-contract=off','-fno-fast-math','-O1',
             '-I',str(ROOT/'include'),'-iquote',str(directory),'-iquote',str(runtime)]
    if args.matrix_trace:
        flags.append('-DFEQ_RESEARCH_MATRIX_TRACE')
    sources = ['src/md5.cpp','src/profile_matrix.cpp','src/section_interpolation.cpp','src/table_interpolation.cpp',
               'tools/profile_compat.cpp','tools/section_compat.cpp','tools/table_compat.cpp','tools/probe_support.cpp']
    if args.matrix_trace:
        sources.append('tools/matrix_trace.cpp')
    commands = []
    for name in sources:
        source = ROOT/name
        obj = object_directory/(source.stem+'.o')
        command = [args.compiler,*flags,'-c',str(source),'-o',str(obj)]
        process = subprocess.run(command,capture_output=True)
        (object_directory/(source.stem+'.compile.log')).write_bytes(process.stdout+process.stderr)
        if process.returncode:
            raise RuntimeError('Component compilation failed; see '+str(object_directory/(source.stem+'.compile.log')))
        commands.append(command)
        objects.append(obj)
        inputs.append({'source':name,'source_sha256':sha256(source),
                       'object':str(obj),'object_sha256':sha256(obj)})
    library = runtime/'libf2c.a'
    command = [args.compiler,'-o',str(output),*[str(path) for path in objects],str(library)]
    subprocess.run(command,check=True)
    manifest = {'status':'Research candidate; whole-model acceptance requires independent comparison.',
                'matrix_trace':args.matrix_trace,'compiler':subprocess.check_output([args.compiler,'--version'],text=True),
                'compile_commands':commands,'link_command':command,'inputs':inputs,'headers':headers,
                'runtime':str(library),'runtime_sha256':sha256(library),
                'executable':str(output),'executable_sha256':sha256(output)}
    (object_directory/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print('Linked '+output.name+'; '+str(len(objects))+' object hashes recorded.')


if __name__ == '__main__':
    main()
