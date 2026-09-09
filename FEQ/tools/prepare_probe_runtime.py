#!/usr/bin/env python3
"""Prepare an isolated, documented libf2c compatibility research build.

This is development infrastructure, not the native application's final runtime.
The input Netlib source and header are preserved. Every modification is hashed.
"""
import argparse
import hashlib
import json
from pathlib import Path
import shutil
import subprocess

ROOT = Path(__file__).resolve().parents[1]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--library-source',type=Path,default=ROOT/'build/f2c/lib')
    parser.add_argument('--header',type=Path,default=ROOT/'build/f2c/src/f2c.h')
    parser.add_argument('--output',type=Path,default=ROOT/'build/f2c/compat')
    args = parser.parse_args()
    output = args.output.resolve()
    if ROOT/'build' not in output.parents or output == args.library_source.resolve():
        parser.error('Use a separate FEQ/build/ directory.')
    output.mkdir(parents=True,exist_ok=True)
    records = []
    for path in sorted(args.library_source.iterdir()):
        if path.is_file() and path.suffix not in ('.o','.a','.xxx','.log') and path.name != 'a.out':
            shutil.copy2(path,output/path.name)
    def change(name, transform, reason):
        path = output/name
        before = path.read_bytes()
        after = transform(before.decode()).encode()
        path.write_bytes(after)
        records.append({'file':name,'reason':reason,
                        'before_sha256':hashlib.sha256(before).hexdigest(),
                        'after_sha256':hashlib.sha256(after).hexdigest()})
    def header(unused):
        result = args.header.read_text()
        result = result.replace('typedef long longint;','typedef long long longint;')
        result = result.replace('typedef unsigned long ulongint;','typedef unsigned long long ulongint;')
        return result
    change('f2c.h',header,'Use the translator integer32 ABI; integer64 remains explicitly long long on LLP64 and LP64 hosts.')
    change('fio.h',lambda text:text.replace('#define MXUNIT 100','#define MXUNIT 1025')+
           '\nint feq_compat_getc(FILE*);\n#define getc feq_compat_getc\n',
           'forunit.cmn permits logical unit 1024; formatted input must consume CRLF as one newline.')
    change('open.c',lambda text:text.replace('n = f__recpos + 1;','n = f__recpos + 2;')
           .replace("\tif (c)\n\t\t*se++ = c;", "#ifndef _WIN32\n\tif (c == '\\n')\n\t\t*se++ = '\\r';\n#endif\n\tif (c)\n\t\t*se++ = c;"),
           'Sequential formatted output uses the original CRLF bytes on every host.')
    # Decode path separators only where a Fortran filename becomes a host path.
    for name,statements in {
        'open.c':['g_char(a->ofnm,a->ofnmlen,buf);'],
        'inquire.c':['g_char(a->infile,a->infilen,buf);'],
    }.items():
        def paths(text):
            helper = '\nstatic void feq_path(char* path) {\n    while (*path) { if (*path == \'\\\\\') *path = \'/\'; ++path; }\n}\n'
            text = helper+text
            for statement in statements:
                text = text.replace(statement,statement+'\n\t\tfeq_path(buf);')
            return text
        change(name,paths,'Interpret the released Windows path separators through the native filesystem.')
    def decimal(text):
        declarations = ('int feq_decimal_fixed(char*, int, float, int, int);\n'
                        'int feq_decimal_exponential(char*, int, float, int);\n')
        anchor = '#endif\n\n int\n'
        if text.count(anchor) != 1:
            raise ValueError('Unexpected wref.c declarations.')
        text = text.replace(anchor,'#endif\n\n'+declarations+'\n int\n')
        original = '\tsprintf(buf,"%#.*E", d, dd);'
        replacement = ('\tif (len == sizeof(real)) {\n'
                       '\t\tif (feq_decimal_exponential(buf, sizeof(buf), p->pf, d) < 0) goto nogood;\n'
                       '\t} else\n'+original)
        if text.count(original) != 1:
            raise ValueError('Unexpected exponential conversion site.')
        text = text.replace(original,replacement)
        start = text.index('#ifdef USE_STRLEN')
        end = text.index('\n#ifndef WANT_LEAD_0',start)
        text = text[:start]+('\tif (len == sizeof(real)) {\n'
                            '\t\tn = feq_decimal_fixed(buf, sizeof(buf), p->pf, d, f__scale);\n'
                            '\t\tif (n < 0) { while (--w >= 0) PUT(\'*\'); return 0; }\n'
                            '\t\tb = buf; n += d1;\n'
                            '\t} else {\n'+text[start:end]+'\n\t}\n')+text[end:]
        return text
    change('wref.c',decimal,'Use original-verified REAL*4 decimal conversion; retain the existing field layout and REAL*8 path.')
    compatibility = r'''#include "f2c.h"
#include "fio.h"
#undef getc

int feq_compat_getc(FILE* stream) {
    int value = getc(stream);
    if (value == '\r' && f__curunit && f__curunit->ufmt) {
        int next = getc(stream);
        if (next == '\n') return '\n';
        if (next != EOF) ungetc(next, stream);
    }
    return value;
}
'''
    (output/'feq_compat.c').write_text(compatibility)
    change('makefile.u',lambda text:text.replace('MISC =\t','MISC =\tfeq_compat.o '),
           'Link the explicit CRLF reader into the isolated research runtime.')
    for path in output.glob('*.o'):
        path.unlink()
    (output/'libf2c.a').unlink(missing_ok=True)
    flags = '-O1 -fno-fast-math -ffp-contract=off -DWANT_LEAD_0 -DUIOLEN_int'
    command = ['make','-f','makefile.u','-j4','CFLAGS='+flags]
    with (output/'build.log').open('wb') as log:
        process = subprocess.run(command,cwd=output,stdout=log,stderr=subprocess.STDOUT)
    manifest = {'upstream':'https://www.netlib.org/f2c/libf2c.zip',
                'header_sha256':hashlib.sha256(args.header.read_bytes()).hexdigest(),
                'changes':records,'command':command,'returncode':process.returncode,
                'numeric_format_policy':'Leading zero enabled; REAL*4 uses independently verified original decimal conversion before field layout; REAL*8 retains Netlib conversion. No output rewriting.'}
    if process.returncode == 0:
        manifest['library_sha256'] = hashlib.sha256((output/'libf2c.a').read_bytes()).hexdigest()
    (output/'compatibility-manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print('Runtime build exit '+str(process.returncode)+'; '+str(len(records))+' recorded changes.')
    raise SystemExit(process.returncode)


if __name__ == '__main__':
    main()
