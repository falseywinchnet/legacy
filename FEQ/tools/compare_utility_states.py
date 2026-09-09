#!/usr/bin/env python3
"""Verify original/native utility states, complete reports and build provenance.

Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
"""
import argparse
import datetime
import hashlib
import json
from pathlib import Path
from compare_reports import compare

ROOT=Path(__file__).resolve().parents[1]


def read(path):return json.loads(path.read_text())
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()


def validate_link(link):
    for item in link['inputs']:
        if sha(ROOT/item['source'])!=item['source_sha256'] or sha(ROOT/item['object'])!=item['object_sha256']:
            raise ValueError('Changed source or object: '+item['source'])
    for item in link['headers']:
        if sha(ROOT/item['path'])!=item['sha256']:raise ValueError('Changed header: '+item['path'])
    if sha(ROOT/link['runtime'])!=link['runtime_sha256']:raise ValueError('Changed runtime library.')
    if sha(ROOT/link['executable'])!=link['executable_sha256']:raise ValueError('Changed executable.')


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--original',type=Path,required=True);parser.add_argument('--native',type=Path,required=True)
    parser.add_argument('--instrumented',type=Path,required=True);parser.add_argument('--link',type=Path,required=True)
    parser.add_argument('--config',type=Path,default=ROOT/'recovery/probes/transition-state-utlexm.json')
    parser.add_argument('--output',type=Path,required=True);args=parser.parse_args()
    original=args.original.resolve();native=args.native.resolve();instrumented=args.instrumented.resolve()
    baseline=read(original/'manifest.json');run=read(native/'manifest.json')
    instrumentation=read(instrumented/'utility-state-instrumentation.json');link=read(args.link);config=read(args.config)
    validate_link(link)
    if baseline['returncode']!=0 or sha(original/'TRACE.EXE')!=baseline['traced_sha256']:
        raise ValueError('Original trace did not complete with its recorded executable.')
    if sha(ROOT/baseline['original']['path'])!=config['original_sha256'] or baseline['original']['sha256']!=config['original_sha256']:
        raise ValueError('Original executable identity changed.')
    if len(config['hooks'])!=len(baseline['hooks']):raise ValueError('Original hook set changed.')
    for planned,observed in zip(config['hooks'],baseline['hooks']):
        if any(observed.get(key)!=value for key,value in planned.items()):raise ValueError('Original hook configuration changed.')
    for item in run['inputs']+run['binaries']:
        if sha(native/item['path'])!=item['sha256']:raise ValueError('Native input or binary changed: '+item['path'])
    for item in run['inputs']:
        if sha(original/item['path'])!=item['sha256']:raise ValueError('Original and native model inputs differ.')
    for case in run['cases']:
        if case['returncode']!=0 or not case['process_completed']:raise ValueError('Native execution did not complete.')
        for item in case['outputs']:
            if sha(native/'test'/item['path'])!=item['sha256']:raise ValueError('Native output changed: '+item['path'])
    if not any(item['path']=='bin/fequtl' and item['sha256']==link['executable_sha256'] for item in run['binaries']):
        raise ValueError('Native run does not use the verified utility link.')
    if sha(ROOT/instrumentation['source'])!=instrumentation['source_sha256']:
        raise ValueError('Instrumentation source changed.')
    instrumented_source=instrumented/'expcon.cpp'
    if sha(instrumented_source)!=instrumentation['instrumented_sha256'] or sha(ROOT/'tools/instrument_utility_states.py')!=instrumentation['tool_sha256']:
        raise ValueError('Instrumentation output or tool changed.')
    if not any(Path(item['source'])==instrumented_source and item['source_sha256']==instrumentation['instrumented_sha256'] for item in link['inputs']):
        raise ValueError('Link does not include the instrumented source.')
    captures={item['routine']:item for item in instrumentation['captures']};comparisons=[]
    if set(captures)!={'fndhpl_','fndect_','frftrn_'} or {item['routine'][1:] for item in baseline['hooks']}!=set(captures):
        raise ValueError('Original and native trace sites differ.')
    for hook in baseline['hooks']:
        capture=captures[hook['routine'][1:]]
        a=original/'test'/hook['file'];b=native/'test'/capture['file']
        left=a.read_bytes();right=b.read_bytes();size=hook['record_bytes']
        if size!=capture['record_bytes'] or len(left)%size or left!=right:
            raise ValueError('Utility state mismatch: '+hook['routine'])
        count=len(left)//size
        if count!=hook['records'] or count<1 or count>=min(hook['limit'],instrumentation['limit']) or sha(a)!=hook['sha256']:
            raise ValueError('Trace count, limit or digest is inconsistent.')
        comparisons.append(dict(routine=hook['routine'],point=capture['point'],records=count,record_bytes=size,
            bytes=len(left),original_trace=str(a.relative_to(ROOT)),native_trace=str(b.relative_to(ROOT)),sha256=sha(a),exact_bytes=True))
    reports=[]
    for name in ('utlexm.out','utlexm.tab','utlexm.chx'):
        expected=(ROOT/'originals/feq1061/wrdapp/FEQ_10.61/DATA'/name).read_bytes()
        first=compare(expected,(original/'test'/name).read_bytes());second=compare(expected,(native/'test'/name).read_bytes())
        if not first['clock_masked_equal'] or not second['clock_masked_equal']:raise ValueError('Instrumented report differs: '+name)
        reports.append(dict(path=name,original=first,native=second))
    proof=dict(created_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),
        scope='All transition head-search entry and partial-flow report states plus snapshots of the first 5000 table words in supplied UTLEXM; no state masks.',
        exact_bytes=True,total_records=sum(item['records'] for item in comparisons),comparisons=comparisons,
        configuration=dict(path=str(args.config.resolve().relative_to(ROOT)),sha256=sha(args.config)),
        comparison_tool_sha256=sha(Path(__file__)),original_trace_manifest=baseline,
        native_run_manifest=run,native_instrumentation=instrumentation,native_link_manifest=link,reports=reports)
    args.output.parent.mkdir(parents=True,exist_ok=True);args.output.write_text(json.dumps(proof,indent=2)+'\n')
    for item in comparisons:print(f"{item['routine']}: all {item['records']} records match ({item['bytes']} bytes).")
    print('Reports, model inputs, trace extents and all build hashes verified.')

if __name__=='__main__':main()
