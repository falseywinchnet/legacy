#!/usr/bin/env python3
"""Research aid: translate the preserved WHAFIS 4G calculation statements.

This is deliberately specific to the supplied source, not a general Fortran
compiler. The resulting C++ has no dependency on this script or on Fortran.
Source labels and line numbers remain available for executable comparisons.
"""
from pathlib import Path
import json
import re
import shutil
import subprocess

ROOT = Path(__file__).resolve().parents[1]


def split(s):
    result, begin, depth, quote = [], 0, 0, False
    for i, c in enumerate(s):
        if c == "'": quote = not quote
        if quote: continue
        if c == '(': depth += 1
        if c == ')': depth -= 1
        if c == ',' and depth == 0:
            result.append(s[begin:i].strip()); begin = i + 1
    result.append(s[begin:].strip())
    return result


def statements():
    out = []
    for n, line in enumerate((ROOT/'originals/whafis4/WHAFIS4G.FOR').read_text().splitlines()[:4515], 1):
        if not line.strip() or line[0] in 'Cc*!': continue
        s = line[6:72].ljust(66)
        # Inline comments, outside strings.
        quote = False
        for i, c in enumerate(s):
            if c == "'": quote = not quote
            if c == '!' and not quote: s = s[:i]; break
        if line[5:6] not in (' ', '0', ''): out[-1][2] += s
        else: out.append([n, line[:5].strip(), s])
    return [(n, label, s.strip()) for n, label, s in out]


class Symbol:
    def __init__(self, name):
        self.name = name
        self.kind = 'int' if name[0] in 'IJKLMN' else 'float'
        self.shape = []
        self.length = 0
        self.init = None

    def declaration(self):
        t = f'Text<{self.length}>' if self.kind == 'text' else self.kind
        if self.shape: t = f'Array<{t}, {", ".join(self.shape)}>'
        return t


class Procedure:
    def __init__(self, name, kind, args):
        self.name, self.kind, self.args = name, kind, args
        self.symbols, self.shared, self.lines, self.formats = {}, set(), [], {}
        self.used, self.bounds = set(), []

    def symbol(self, name):
        if name not in self.symbols: self.symbols[name] = Symbol(name)
        return self.symbols[name]

    def variable(self, name):
        self.used.add(name)
        sym = self.symbol(name)
        if name == self.name and self.kind == 'FUNCTION': return 'result', sym.kind
        return name.lower() + ('_' if name.lower() in ('new', 'delete', 'default', 'do', 'if', 'else', 'for', 'while', 'switch', 'case', 'return', 'class', 'template') else ''), sym.kind


procedures = {}
module = Procedure('FIVEHUNDRED', 'MODULE', [])
current = None
for n, label, s in statements():
    m = re.match(r'(MODULE|PROGRAM|SUBROUTINE|FUNCTION)\s+(\w+)(?:\((.*)\))?$', s)
    if m:
        kind, name, args = m.groups()
        current = module if kind == 'MODULE' else Procedure(name, kind, split(args) if args else [])
        if kind != 'MODULE': procedures[name] = current
        continue
    if not current: continue
    if re.match(r'END (MODULE|PROGRAM|SUBROUTINE|FUNCTION)', s): current = None; continue
    if s.startswith('USE '):
        if s == 'USE FIVEHUNDRED':
            current.symbols.update(module.symbols); current.shared.update(module.symbols)
        continue
    if s.startswith('IMPLICIT ') or s == 'SAVE': continue
    m = re.match(r'(DIMENSION|REAL|LOGICAL|INTEGER(?:\*\d+)?|CHARACTER(?:\*\d+|\(LEN=\d+\))?)\s*(?:::)?\s+(.+)', s)
    if m:
        decl, names = m.groups()
        for name in split(names):
            v = re.fullmatch(r'(\w+)(?:\((.*)\))?', name)
            if not v: raise ValueError((n, s, name))
            name, shape = v.groups(); sym = current.symbol(name)
            if shape: sym.shape = split(shape)
            if decl.startswith('REAL'): sym.kind = 'float'
            if decl.startswith('INTEGER'): sym.kind = 'int'
            if decl.startswith('LOGICAL'): sym.kind = 'bool'
            if decl.startswith('CHARACTER'):
                sym.kind = 'text'; sizes = re.findall(r'\d+', decl); sym.length = int(sizes[0]) if sizes else 1
        continue
    if s.startswith('COMMON'):
        names = s.split('/')[2].strip()
        for name in split(names): current.shared.add(name); current.symbol(name)
        continue
    if s.startswith('DATA '):
        _, names, values, _ = re.split(r'DATA\s+|/', s, maxsplit=3)
        vals = split(values)
        for name, value in zip(split(names), vals):
            m = re.fullmatch(r'(\d+)H(.*)', value)
            if m: value = "'" + m[2][:int(m[1])] + "'"
            current.symbol(name).init = value
        continue
    if s.startswith('FORMAT('):
        # This quoted string spans a physical line in the supplied listing.
        # The executable contains one intervening space, without source padding.
        if current.name == 'WHAFIS4' and label == '828':
            s = re.sub(r'ARE\s+BEING', 'ARE BEING', s)
        current.formats[label] = s[6:]; continue
    # Native C++ owns filenames, streams, argument validation, and date metadata.
    if current.name == 'WHAFIS4' and (105 <= n < 140 or 141 <= n <= 144): continue
    if s.startswith('CLOSE('):
        if label: current.lines.append((n,label,'CONTINUE'))
        continue
    current.lines.append((n, label, s))

intrinsics = {'AMAX1':'maximum','AMIN1':'minimum','ABS':'std::abs','SQRT':'std::sqrt',
              'TANH':'std::tanh','SINH':'std::sinh','COSH':'std::cosh','EXP':'std::exp',
              'LOG':'std::log','ALOG':'std::log','ALOG10':'std::log10','INT':'integer',
              'FLOAT':'real','IFIX':'integer','MAX0':'maximum','MIN0':'minimum','LEN_TRIM':'trimmed_length',
              'TRIM':'trim','ADJUSTL':'adjust_left','SIGN':'sign'}
token_pattern = re.compile(r"\s*(\d+\.\d*(?:[EeDd][+-]?\d+)?|\.\d+(?:[EeDd][+-]?\d+)?|\d+[EeDd][+-]?\d+|\d+|\.[A-Za-z]+\.|[A-Za-z][A-Za-z0-9_]*|'(?:[^']|'')*'|\*\*|//|==|/=|<=|>=|[()+*/,:<>=-])")
precedence = {'.OR.':1,'.AND.':2,'.EQ.':3,'.NE.':3,'.LT.':3,'.GT.':3,'.LE.':3,'.GE.':3,'==':3,'/=':3,'<':3,'>':3,'<=':3,'>=':3,'//':4,'+':5,'-':5,'*':6,'/':6,'**':8}
ops = {'.OR.':'||','.AND.':'&&','.EQ.':'==','.NE.':'!=','.LT.':'<','.GT.':'>','.LE.':'<=','.GE.':'>=','/=':'!='}


class Expression:
    def __init__(self, p, source):
        source = re.sub(r"\.\s*(EQ|NE|LT|GT|LE|GE|AND|OR|NOT|TRUE|FALSE)\s*\.", lambda m: " ."+m[1]+". ", source)
        if m := re.fullmatch(r"\s*(\d+)H(.*)\s*", source):
            source = "'" + m[2][:int(m[1])] + "'"
        self.p, self.source, self.i = p, source, 0
        self.tokens = []
        pos = 0
        while pos < len(source.rstrip()):
            m = token_pattern.match(source, pos)
            if not m: raise ValueError(('token',p.name,source[pos:],source))
            self.tokens.append(m[1]); pos = m.end()

    def take(self): t = self.tokens[self.i]; self.i += 1; return t
    def peek(self): return self.tokens[self.i] if self.i < len(self.tokens) else ''

    def parse(self, level=0):
        t = self.take(); upper = t.upper()
        if upper in ('-', '+', '.NOT.'):
            v, kind = self.parse(7 if upper != '.NOT.' else 3)
            left = (f'({"!" if upper == ".NOT." else t}{v})', 'bool' if upper == '.NOT.' else kind)
        elif t == '(':
            left = self.parse(); assert self.take() == ')'
        elif t.startswith("'"):
            left = (json.dumps(t[1:-1].replace("''", "'")), 'text')
        elif upper in ('.TRUE.', '.FALSE.'): left = ('true' if upper == '.TRUE.' else 'false', 'bool')
        elif t[0].isdigit() or t[0] == '.':
            kind = 'float' if any(c in t.upper() for c in '.ED') else 'int'
            t = t.lower().replace('d','e')
            left = (t + ('f' if kind == 'float' else ''), kind)
        else:
            if self.peek() == '(':
                self.take(); args = []; sliced = False
                while self.peek() != ')':
                    args.append(self.parse())
                    if self.peek() == ':': sliced = True; self.take(); continue
                    if self.peek() == ',': self.take(); continue
                    break
                assert self.take() == ')', (self.source,self.tokens[self.i:])
                if upper in intrinsics:
                    name = intrinsics[upper]
                    if upper in ('AMAX1','AMIN1','MAX0','MIN0'):
                        left = (f'{name}({", ".join(a[0] for a in args)})', 'int' if upper.endswith('0') else 'float')
                    else: left = (f'{name}({", ".join(a[0] for a in args)})', 'int' if upper in ('INT','LEN_TRIM') else 'text' if upper in ('TRIM','ADJUSTL') else 'float')
                elif upper in procedures:
                    left = (f'{upper.lower()}({", ".join(a[0] for a in args)})', 'float')
                else:
                    name, kind = self.p.variable(upper)
                    left = (f'{name}.slice({", ".join(a[0] for a in args)})' if sliced else f'{name}({", ".join(a[0] for a in args)})', kind)
            else: left = self.p.variable(upper)
        while self.peek().upper() in precedence and precedence[self.peek().upper()] >= level:
            op = self.take().upper(); rank = precedence[op]
            right = self.parse(rank if op == '**' else rank + 1)
            a, ak = left; b, bk = right
            if rank == 3:
                if ak == 'text' and bk != 'text': b = f'word_text({b})'
                if bk == 'text' and ak != 'text': a = f'word_text({a})'
                if ak == 'text' or bk == 'text': a, b = f'trim({a})', f'trim({b})'
                left = (f'({a} {ops.get(op,op)} {b})','bool')
            elif op == '//': left = (f'concatenate({a}, {b})','text')
            elif op == '**': left = (f'power({a}, {b})','int' if ak == bk == 'int' else 'float')
            else:
                kind = 'bool' if rank <= 2 else 'int' if ak == bk == 'int' else 'float'
                if kind == 'float': a, b = f'wide({a})', f'wide({b})'
                left = (f'({a} {ops.get(op,op)} {b})', kind)
        return left


def expr(p, s):
    e = Expression(p,s); result=e.parse()
    assert e.i == len(e.tokens), (p.name,s,e.tokens[e.i:])
    return result


def parens(s):
    start=s.index('('); depth=0; quote=False
    for i in range(start,len(s)):
        c=s[i]
        if c=="'": quote=not quote
        if quote: continue
        if c=='(': depth+=1
        if c==')':
            depth-=1
            if depth==0: return s[start+1:i],s[i+1:].strip()
    raise ValueError(s)


def io_items(p, items, read):
    output=[]
    for item in split(items) if items else []:
        if item.startswith('('):
            inner, tail=parens(item); pieces=split(inner)
            loop_index=next((i for i,x in enumerate(pieces) if re.match(r'\w+\s*=',x)),None)
            if loop_index is not None:
                var, start=pieces[loop_index].split('=',1); name,_=p.variable(var.strip())
                end=expr(p,pieces[loop_index+1])[0]; start=expr(p,start)[0]
                output.append(f'for ({name} = {start}; {name} <= {end}; ++{name}) {{')
                output += io_items(p,','.join(pieces[:loop_index]),read); output.append('}')
                continue
        value,_=expr(p,item)
        output.append(f'record.{"read" if read else "write"}({value});')
    return output


def translate(p, s, n):
    if s == 'CONTINUE': return [';']
    if s in ('ENDIF','END IF'): return ['}']
    if s == 'ELSE': return ['} else {']
    if s.startswith(('ELSE IF','ELSEIF')):
        cond, tail=parens(s); return [f'}} else if ({expr(p,cond)[0]}) {{']
    if re.match(r'IF\s*\(',s):
        cond, tail=parens(s); c=expr(p,cond)[0]
        if tail=='THEN': return [f'if ({c}) {{']
        if re.fullmatch(r'\d+\s*,\s*\d+\s*,\s*\d+',tail):
            a,b,d=split(tail); return [f'if ({c} < 0) goto L{a};',f'if ({c} == 0) goto L{b};',f'goto L{d};']
        return [f'if ({c}) {{']+translate(p,tail,n)+['}']
    m=re.match(r'GO\s*TO\s+(\d+)$',s)
    if m: return ['goto L'+m[1]+';']
    if s == 'RETURN': return ['return result;' if p.kind=='FUNCTION' else 'return;']
    if s == 'STOP': return ['throw CalculationStopped{};']
    if s.startswith(('REWIND','BACKSPACE')):
        action,unit=re.match(r'(REWIND|BACKSPACE)\s*\(?\s*(\d+)\s*\)?',s).groups()
        return [f'io.{action.lower()}({unit});']
    if s.startswith(('READ(','READ (','WRITE(','WRITE (')):
        fields,items=parens(s); unit,fmt=split(fields); read=s.startswith('READ')
        format_string=fmt[1:-1] if fmt.startswith("'") else p.formats[fmt]
        u=expr(p,unit)[0]
        out=['{',f'auto record = io.{"reader" if read else "writer"}({u}, {json.dumps(format_string)});']
        out+=io_items(p,items,read);out+=['record.finish();','}'];return out
    if s.startswith('CALL '):
        call=s[5:].strip()
        if '(' not in call: return [call.lower()+'();']
        name=call[:call.index('(')].strip(); args,_=parens(call)
        return [name.lower()+'('+', '.join(expr(p,arg)[0] for arg in split(args))+');']
    if '=' in s:
        lhs,rhs=s.split('=',1); a,ak=expr(p,lhs); b,bk=expr(p,rhs)
        if ak != 'text' and bk=='text': b=f'word({b})'
        return [f'{a} = {b};']
    raise ValueError(('statement',p.name,n,s))


def body(p):
    out=[]; loops=[]
    labels=set()
    for n,label,s in p.lines:
        labels.update(re.findall(r'GO\s*TO\s+(\d+)',s))
        if re.search(r'\)\s*\d+\s*,\s*\d+\s*,\s*\d+$',s): labels.update(re.findall(r'\d+',s[s.rindex(')')+1:]))
    for n,label,s in p.lines:
        if label in labels: out.append('L'+label+':')
        if p.name == 'WHAFIS4' and n == 620: out.append('record_transect(std::string_view(title2));')
        if (m:=re.match(r'DO\s+(\d+)\s+(\w+)\s*=\s*(.*)',s)):
            end,var,bounds=m.groups();bounds=split(bounds);name,_=p.variable(var)
            start,stop=expr(p,bounds[0])[0],expr(p,bounds[1])[0]
            step=expr(p,bounds[2])[0] if len(bounds)>2 else '1'
            bound=f'limit_{n}';p.bounds.append(bound)
            out.append(f'{bound} = {stop};')
            out.append(f'for ({name} = {start}; {name} {">=" if step.startswith("(-") or step.startswith("-") else "<="} {bound}; {name} += {step}) {{')
            loops.append(end)
        else: out += translate(p,s,n)
        while loops and label==loops[-1]: out.append('}');loops.pop()
    assert not loops, (p.name,loops)
    return out


bodies={p.name:body(p) for p in procedures.values()}
shared={**module.symbols}
for p in procedures.values():
    for name in p.shared:
        sym=p.symbols[name]
        if name in shared:
            assert shared[name].declaration()==sym.declaration(), (name,shared[name].declaration(),sym.declaration())
        shared[name]=sym


def signature(p):
    args=[]
    for name in p.args:
        sym=p.symbol(name); t=sym.declaration()
        if p.kind=='SUBROUTINE' or sym.shape: t+='&'
        args.append(t+' '+p.variable(name)[0])
    return ('float' if p.kind=='FUNCTION' else 'void')+' '+p.name.lower()+'('+', '.join(args)+')'


header=['#pragma once','#include "support.hpp"','#include "legacy/whafis.hpp"','namespace legacy::whafis::detail {','class Engine {','public:', 'RecordFiles io;', 'std::vector<TransectResult> transects;', 'void record_transect(std::string_view title);']
for name,sym in sorted(shared.items()): header.append(sym.declaration()+' '+name.lower()+'{};')
for p in procedures.values(): header.append(signature(p)+';')
header += ['};','}']
(ROOT/'src/whafis').mkdir(exist_ok=True)
(ROOT/'src/whafis/engine.hpp').write_text('\n'.join(header)+'\n')
for p in procedures.values():
    result=['// Port of WHAFIS4G.FOR: '+p.name+'. Source labels support differential review.', '#include "engine.hpp"','namespace legacy::whafis::detail {',signature(p).replace(' '+p.name.lower()+'(', ' Engine::'+p.name.lower()+'(')+' {']
    if p.name in ('SHBM', 'T'): continue # Maintained from original instruction/storage sequence.
    for name in sorted(p.used-set(p.args)-p.shared):
        sym=p.symbol(name)
        var=p.variable(name)[0]
        init='{}'
        if sym.init is not None:
            v,k=expr(p,sym.init)
            if k=='text' and sym.kind!='text':v=f'word({v})'
            init=' = '+v
        wide_locals = {'FETCH': {'TSAVG', 'SAVG', 'GAVG', 'DAVG', 'GSLAVG', 'STMP'},
                       'WHAFIS4': {'STMP'}}
        declared = 'double' if name in wide_locals.get(p.name, set()) else sym.declaration()
        result.append(declared+' '+var+init+';')
    for bound in p.bounds:result.append('int '+bound+'{};')
    result+=bodies[p.name]
    if p.kind=='FUNCTION':result.append('return result;')
    result+=['}','}']
    (ROOT/'src/whafis'/f'{p.name.lower()}.cpp').write_text('\n'.join(result)+'\n')
print('Wrote',len(procedures),'C++ procedures with',sum(len(v) for v in bodies.values()),'lines.')
if formatter := shutil.which('clang-format'):
    subprocess.run([formatter, '-i', '-style={BasedOnStyle: LLVM, IndentWidth: 4, ColumnLimit: 100}',
                    *map(str, (ROOT/'src/whafis').glob('*.cpp')), str(ROOT/'src/whafis/engine.hpp')], check=True)
