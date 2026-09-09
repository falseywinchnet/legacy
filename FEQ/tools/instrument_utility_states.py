#!/usr/bin/env python3
"""Record transition states and the first 5,000 table words in a disposable candidate.

Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
"""
import argparse
import hashlib
import json
from pathlib import Path
import shutil
from prepare_cpp_probe import content,edit_text,functions,identifier,nodes

ROOT=Path(__file__).resolve().parents[1]
PREFIX='''#include <cstdint>
#include <cstring>
#include <fstream>
#include <stdexcept>
namespace {
void feq_write_utility_state(std::ofstream& output, const void* source, std::size_t size) {
    if (size % 4 != 0) { throw std::runtime_error("Invalid utility trace extent."); }
    const unsigned char* data = static_cast<const unsigned char*>(source);
    for (std::size_t offset = 0; offset < size; offset += 4) {
        std::uint32_t word = 0;
        std::memcpy(&word,data+offset,4);
        const unsigned char bytes[4] = {static_cast<unsigned char>(word),static_cast<unsigned char>(word >> 8),
            static_cast<unsigned char>(word >> 16),static_cast<unsigned char>(word >> 24)};
        output.write(reinterpret_cast<const char*>(bytes),4);
    }
    if (!output) { throw std::runtime_error("Utility state trace could not be written."); }
}
}
'''


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('source',type=Path);parser.add_argument('output',type=Path)
    parser.add_argument('--limit',type=int,default=100000)
    args=parser.parse_args();source=args.source.resolve();output=args.output.resolve()
    if output.exists() or ROOT/'build' not in output.parents:parser.error('Use a new FEQ/build/ directory.')
    if args.limit<1 or args.limit>1000000:parser.error('Trace limit must be between one and one million.')
    data=(source/'expcon.cpp').read_bytes();edits=[];captures=[]
    for function in functions(data):
        name=content(identifier(function.child_by_field_name('declarator')),data)
        body=function.child_by_field_name('body')
        if name=='fndhpl_':kind='head';position=body.start_byte+1;size=104;extra=''
        elif name=='frftrn_':
            kind='tables';position=body.start_byte+1;size=20104
            extra='static_assert(sizeof(ftable_) >= 20000); feq_write_utility_state(feq_state_stream,&ftable_,20000);'
        elif name=='fndect_':
            candidates=[node for node in nodes(body) if node.type=='expression_statement' and
                content(node,data)=='feq_gen_var_decimal_d_(&feccom_1.q, cq, (ftnlen)8);']
            if len(candidates)!=1:raise ValueError('Expected the partial-flow report call in FNDECT.')
            kind='flow';position=candidates[0].start_byte;size=108
            extra='feq_write_utility_state(feq_state_stream,&qfree,4);'
        else:continue
        filename='transition-'+kind+'.bin'
        insertion=('\n    { static_assert(sizeof(feccom_) == 104);\n'
            f'      static std::ofstream feq_state_stream("{filename}",std::ios::binary);\n'
            '      static unsigned int feq_state_count = 0;\n'
            f'      if (feq_state_count++ >= {args.limit}U) {{ throw std::runtime_error("Utility trace limit exceeded."); }}\n'
            '      feq_write_utility_state(feq_state_stream,&feccom_,104);\n'
            '      '+extra+'\n    }\n')
        edits.append((position,position,insertion))
        captures.append(dict(routine=name,point='partial-flow report' if kind=='flow' else 'entry',file=filename,record_bytes=size))
    if {item['routine'] for item in captures}!={'fndhpl_','frftrn_','fndect_'}:raise ValueError('Missing utility trace sites.')
    instrumented=PREFIX.encode()+edit_text(data,edits);output.mkdir()
    for path in sorted(source.iterdir()):
        if path.is_file() and (path.suffix in ('.cpp','.h','.hpp') or path.name=='verified-components.json'):
            shutil.copyfile(path,output/path.name)
    (output/'expcon.cpp').write_bytes(instrumented)
    manifest=dict(captures=captures,limit=args.limit,source=str(source/'expcon.cpp'),
        source_sha256=hashlib.sha256(data).hexdigest(),instrumented_sha256=hashlib.sha256(instrumented).hexdigest(),
        tool_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest())
    (output/'utility-state-instrumentation.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print('Instrumented transition entries, partial-flow reports and 5,000-word table snapshots.')

if __name__=='__main__':main()
