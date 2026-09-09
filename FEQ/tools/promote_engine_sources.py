#!/usr/bin/env python3
"""Preserve a verified research candidate as buildable application source.

This is a maintainer operation, never a build prerequisite. Original source
notices remain attached to the historical implementation. New contributions:
Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
import shutil

ROOT = Path(__file__).resolve().parents[1]
RUNTIME_MEMBERS = '''backspac close ctype d_lg10 d_mod d_sign dolio due endfile
err exit_ f77_aloc feq_compat fmt fmtlib getarg_ i_dnnt i_indx i_len i_nint
i_sign iargc_ iio ilnw inquire lread lwrite open pow_dd r_lg10 r_sign rdfmt rewind
rsfe rsli rsne s_cat s_cmp s_copy s_stop sfe sig_die sue typesize uio util wref
wrtfmt wsfe wsle wsne xwsne'''.split()
RUNTIME_HEADERS = '''f2c.h fio.h fmt.h lio.h fp.h rawio.h sysdep1.h ctype.h'''.split()


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def checked_link(path):
    record = json.loads(path.read_text())
    for item in record['inputs']:
        source = Path(item['source'])
        if not source.is_absolute():
            source = ROOT/source
        if digest(source) != item['source_sha256'] or digest(Path(item['object'])) != item['object_sha256']:
            raise ValueError('Source or object differs from accepted link: '+str(source))
    for item in record['headers']:
        if digest(Path(item['path'])) != item['sha256']:
            raise ValueError('Header differs from accepted link: '+item['path'])
    if digest(Path(record['runtime'])) != record['runtime_sha256']:
        raise ValueError('Runtime differs from accepted link.')
    if digest(Path(record['executable'])) != record['executable_sha256']:
        raise ValueError('Executable differs from accepted link.')
    return record


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--feq-link', required=True, type=Path)
    parser.add_argument('--fequtl-link', required=True, type=Path)
    parser.add_argument('--runtime', required=True, type=Path)
    parser.add_argument('--output', required=True, type=Path)
    args = parser.parse_args()
    output = args.output.resolve()
    if output.exists():
        parser.error('Use a new source directory; existing application code is never overwritten.')
    links = [checked_link(args.feq_link), checked_link(args.fequtl_link)]
    output.mkdir(parents=True)
    files = []

    def save(source, relative, payload=None, changes=None):
        destination = output/relative
        destination.parent.mkdir(parents=True, exist_ok=True)
        destination.write_bytes(source.read_bytes() if payload is None else payload.encode())
        files.append({'path':relative, 'sha256':digest(destination),
                      'source':str(source.resolve().relative_to(ROOT)),
                      'source_sha256':digest(source), 'changes':changes or []})

    for record in links:
        program = record['program']
        directories = set()
        for item in record['inputs']:
            source = Path(item['source'])
            if source.is_absolute() and source.suffix == '.cpp':
                directories.add(source.parent)
                save(source, program+'/'+source.name)
        if len(directories) != 1:
            raise ValueError('Expected exactly one generated source directory for '+program)
        directory = next(iter(directories))
        for source in sorted(directory.glob('*.hpp')):
            save(source, program+'/'+source.name)
        for name in ('verified-components.json', 'utility-components.json'):
            if (directory/name).is_file():
                save(directory/name, 'provenance/'+program+'-'+name)

    for name in RUNTIME_MEMBERS:
        source = args.runtime/(name+'.c')
        text = re.sub(r'\bregister\s+', '', source.read_text())
        changes = ['Remove the obsolete register storage-class specifier.']
        if name == 'rsne':
            text = text.replace('extern int t_getc(Void);', 'extern "C" int t_getc(Void);')
            changes.append('Match t_getc definition C language linkage.')
        save(source, 'runtime/'+name+'.cpp', text, changes)
    for name in RUNTIME_HEADERS:
        source = args.runtime/name
        text = source.read_text()
        changes = []
        if name == 'f2c.h':
            declarations = (args.runtime/'f2ch.add').read_text()
            declarations = declarations.replace('extern void sig_die(char *, int);',
                                                'extern void sig_die(const char *, int);')
            text += '\n#ifdef FEQ_RUNTIME_BUILD\n'+declarations+'\n#endif\n'
            changes.append('Append Netlib C++ runtime declarations, using the const-correct sig_die signature.')
        save(source, 'runtime/'+name, text, changes)
    save(args.runtime/'Notice', 'runtime/NOTICE.txt')
    save(args.runtime/'compatibility-manifest.json', 'provenance/runtime-compatibility.json')
    manifest = {'purpose':'Initial application source promotion; future changes are tracked by Git.',
                'historical_license':'Preserved source notices; see FEQ/NOTICE.md. Translation does not relicense historical code.',
                'verified_links':[{'program':item['program'], 'executable_sha256':item['executable_sha256']}
                                  for item in links],
                'runtime_selection':'Union of archive members linked into both complete engines, including dependencies.',
                'runtime_cpp_prototypes':{'source':'f2ch.add','sha256':digest(args.runtime/'f2ch.add')},
                'files':files}
    (output/'provenance/initial-source-manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print(str(len(files))+' application source files preserved, with input/output hashes.')


if __name__ == '__main__':
    main()
