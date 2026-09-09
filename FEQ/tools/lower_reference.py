#!/usr/bin/env python3
"""Lower the released Fortran extensions for inspectable translation probes.

This is research tooling. Generated sources retain the historical notices and
are not the new MIT implementation. Every transformation is recorded. Unsupported
constructs fail visibly; no hydraulic procedure is replaced by a stub.
"""
import argparse
from dataclasses import dataclass, replace
import json
from pathlib import Path
import re
import subprocess

ROOT = Path(__file__).resolve().parents[1]


@dataclass
class Statement:
    code: str
    label: str = ''
    origin: str = ''
    comment: bool = False


def compact(text):
    """Fortran ignores blanks outside quoted constants in fixed-form source."""
    result = []
    index = 0
    while index < len(text):
        char = text[index]
        if char in "'\"":
            quote = char
            result.append(char)
            index += 1
            while index < len(text):
                char = text[index]
                result.append(char)
                index += 1
                if char == quote:
                    if index < len(text) and text[index] == quote:
                        result.append(quote)
                        index += 1
                    else:
                        break
        elif char == '!':
            break
        elif not char.isspace() and char != '\x1a':
            result.append(char.lower())
            index += 1
        else:
            index += 1
    return ''.join(result)


def strip_inline_comment(text):
    index = 0
    quote = None
    while index < len(text):
        char = text[index]
        if quote:
            if char == quote:
                if index+1 < len(text) and text[index+1] == quote:
                    index += 1
                else:
                    quote = None
        elif char in "'\"":
            quote = char
        elif char == '!':
            return text[:index]
        index += 1
    return text


def read_fixed(path, stack=()):
    if path.name in stack:
        raise ValueError(f'Recursive INCLUDE: {path}')
    result = []
    pending = None
    comments = []

    def flush():
        nonlocal pending, comments
        if pending:
            statement = replace(pending, code=compact(pending.code))
            match = re.fullmatch(r"include['\"]([^'\"]+)['\"]", statement.code)
            if match:
                result.append(Statement('INCLUDE '+statement.origin, comment=True))
                result.extend(read_fixed(path.parent / match[1].lower(), stack+(path.name,)))
            elif statement.code:
                result.append(statement)
            pending = None
        result.extend(comments)
        comments = []

    for number, line in enumerate(path.read_bytes().decode('latin1').splitlines(), 1):
        if not line.strip(' \t\x1a'):
            continue
        if line[0] in 'cC*!':
            comments.append(Statement(line[1:], origin=f'{path.name}:{number}', comment=True))
            continue
        if line.startswith('\t'):
            if len(line) > 1 and line[1] in '123456789':
                line = '     '+line[1:]
            else:
                line = '      '+line[1:]
        if '\t' in line[:6]:
            raise ValueError(f'Mixed tab/label layout needs explicit handling: {path}:{number}')
        body = strip_inline_comment(line[6:72]).ljust(66)
        if len(line) > 5 and line[5] not in ' 0':
            if pending is None:
                raise ValueError(f'Orphan continuation: {path}:{number}')
            pending.code += body
        else:
            flush()
            pending = Statement(body, line[:5].strip(), f'{path.name}:{number}')
    flush()
    return result


def split_top(text, separator=','):
    result = []
    depth = 0
    start = 0
    quote = None
    index = 0
    while index < len(text):
        char = text[index]
        if quote:
            if char == quote:
                if index+1 < len(text) and text[index+1] == quote:
                    index += 1
                else:
                    quote = None
        elif char in "'\"":
            quote = char
        elif char == '(':
            depth += 1
        elif char == ')':
            depth -= 1
        elif char == separator and depth == 0:
            result.append(text[start:index])
            start = index+1
        index += 1
    result.append(text[start:])
    return result


def close_paren(text, start):
    depth = 0
    quote = None
    index = start
    while index < len(text):
        char = text[index]
        if quote:
            if char == quote:
                if index+1 < len(text) and text[index+1] == quote:
                    index += 1
                else:
                    quote = None
        elif char in "'\"":
            quote = char
        elif char == '(':
            depth += 1
        elif char == ')':
            depth -= 1
            if depth == 0:
                return index
        index += 1
    raise ValueError('Unbalanced parentheses: '+text)


def words_outside_strings(text, callback):
    result = []
    index = 0
    while index < len(text):
        if text[index] in "'\"":
            quote, start = text[index], index
            index += 1
            while index < len(text):
                if text[index] == quote:
                    index += 1
                    if index < len(text) and text[index] == quote:
                        index += 1
                        continue
                    break
                index += 1
            result.append(text[start:index])
        elif text[index].isalpha() or text[index] == '_':
            start = index
            while index < len(text) and (text[index].isalnum() or text[index] == '_'):
                index += 1
            result.append(callback(text[start:index], text[index:]))
        else:
            result.append(text[index])
            index += 1
    return ''.join(result)


TYPE = re.compile(r'^(doubleprecision|real(?:\*\d+)?|integer(?:\*\d+)?|logical(?:\*\d+)?|character(?:\*(?:\([^)]*\)|\d+))?|complex(?:\*\d+)?)(.*)$')
HEADER = re.compile(r'^(?:(?:doubleprecision|real(?:\*\d+)?|integer(?:\*\d+)?|logical|character\*(?:\([^)]*\)|\d+))?function|subroutine|program|blockdata)')
SPEC = re.compile(r'^(?:implicit|doubleprecision|real|integer|logical|character|complex|dimension|common|equivalence|save|parameter|external|intrinsic|data|namelist)')


def is_specification(code):
    # REAL_RESPONSE(I)=... and DONE=... are ordinary assignments despite
    # beginning with letters that can also introduce specification statements.
    return bool(SPEC.match(code)) and len(split_top(code, '=')) == 1


def simplify_type(code):
    code = re.sub(r'^(integer|real|logical)\(kind=(\d+)\)::', r'\1*\2', code)
    code = re.sub(r'^(integer|real|logical|character|doubleprecision)::', r'\1', code)
    return code


def symbol_table(statements):
    symbols, parameters = {}, {}
    for statement in statements:
        if statement.comment:
            continue
        code = simplify_type(statement.code)
        match = TYPE.match(code)
        if match and not HEADER.match(code):
            kind, variables = match.groups()
            for declaration in split_top(variables):
                item = re.fullmatch(r'([a-z_]\w*)(\(.*\))?(\*(?:\([^)]*\)|\d+))?', declaration)
                if item:
                    name, dimensions, suffix = item.groups()
                    previous = symbols.get(name, {})
                    symbols[name] = dict(previous, kind=kind+(suffix or ''), dimensions=split_top(dimensions[1:-1]) if dimensions else previous.get('dimensions', []))
        if code.startswith('dimension'):
            for item in split_top(code[9:]):
                name, dimensions = item.split('(', 1)
                symbols.setdefault(name, {'kind': 'integer' if name[0] in 'ijklmn' else 'real'})['dimensions'] = split_top(dimensions[:-1])
        if code.startswith('parameter('):
            for item in split_top(code[10:-1]):
                name, value = item.split('=', 1)
                parameters[name] = value
    return symbols, parameters


class Lowering:
    def __init__(self):
        self.events = []
        self.locals = {}
        self.external = {}
        self.serial = 0
        self.labels = set()
        self.next_label = 99000
        self.symbols = {}
        self.dynamic_wrappers = []

    def label(self):
        while str(self.next_label) in self.labels:
            self.next_label -= 1
        result = str(self.next_label)
        self.labels.add(result)
        self.next_label -= 1
        return result

    def local(self, kind, prefix):
        self.serial += 1
        name = f'feql_{prefix}{self.serial}'
        if name in self.symbols:
            raise ValueError('Generated local conflicts with historical source.')
        self.locals[name] = kind
        return name

    def event(self, statement, change):
        self.events.append({'origin': statement.origin, 'change': change, 'statement': statement.code})

    def selects(self, statements):
        output = []
        index = 0
        while index < len(statements):
            current = statements[index]
            if current.comment or not current.code.startswith('selectcase('):
                output.append(current)
                index += 1
                continue
            expression = current.code[11:-1]
            kind = self.symbols.get(expression, {}).get('kind', 'integer')
            if not kind.startswith(('integer', 'logical', 'character')):
                raise ValueError('Unsupported SELECT type: '+current.origin)
            variable = self.local(kind, 'select')
            output.append(replace(current, code=variable+'='+expression))
            branches = []
            nesting = 0
            end = index+1
            branch = None
            while end < len(statements):
                line = statements[end]
                if not line.comment and line.code.startswith('selectcase('):
                    nesting += 1
                elif not line.comment and line.code == 'endselect':
                    if nesting == 0:
                        break
                    nesting -= 1
                if not line.comment and line.code.startswith('case') and nesting == 0:
                    branch = [line.code[4:], []]
                    branches.append(branch)
                elif branch is not None:
                    branch[1].append(line)
                else:
                    if not line.comment:
                        raise ValueError('Unexpected code before CASE: '+line.origin)
                    output.append(line)
                end += 1
            if end == len(statements):
                raise ValueError('Unterminated SELECT CASE: '+current.origin)
            branches.sort(key=lambda item: item[0] == 'default')
            for number, (condition, body) in enumerate(branches):
                if condition == 'default':
                    code = 'else' if number else 'if(.true.)then'
                else:
                    terms = []
                    for value in split_top(condition[1:-1]):
                        limits = split_top(value, ':')
                        if len(limits) == 1:
                            operator = '.eqv.' if kind.startswith('logical') else '.eq.'
                            terms.append(variable+operator+value)
                        else:
                            checks = []
                            if limits[0]:
                                checks.append(variable+'.ge.'+limits[0])
                            if limits[1]:
                                checks.append(variable+'.le.'+limits[1])
                            terms.append('('+'.and.'.join(checks)+')')
                    code = ('if(' if number == 0 else 'elseif(')+'.or.'.join(terms)+')then'
                output.append(replace(current, code=code, label=''))
                output.extend(self.selects(body))
            output.append(replace(statements[end], code='endif'))
            self.event(current, 'SELECT evaluates its selector once; ordered IF/ELSE branches preserve every CASE, including an initially placed DEFAULT.')
            index = end+1
        return output

    def loops(self, statements):
        output, stack = [], []
        for statement in statements:
            if statement.comment:
                output.append(statement)
                continue
            code = statement.code
            start = re.fullmatch(r'do(?:(\d+))?([a-z_]\w*=.*|while\(.*\))?', code)
            if start and start[2] and not start[2].startswith('while('):
                if len(split_top(start[2].split('=', 1)[1])) < 2:
                    start = None  # e.g. DONE=0 is an assignment, not a DO.
            if start:
                terminal, control = start.groups()
                entry = {'terminal': terminal, 'exit': self.label(), 'cycle': self.label(), 'used_exit': False, 'used_cycle': False}
                stack.append(entry)
                if control is None:
                    code = 'dowhile(.true.)'
                    self.event(statement, 'Unbounded DO lowered to DO WHILE(.TRUE.).')
            elif re.search(r'(?:^|\))(exit|cycle)$', code):
                match = re.search(r'(exit|cycle)$', code)
                if not stack:
                    raise ValueError('EXIT/CYCLE without DO: '+statement.origin)
                action = match[1]
                stack[-1]['used_'+action] = True
                if action == 'cycle' and stack[-1]['terminal']:
                    raise ValueError('CYCLE in a labeled DO needs a separate terminal-statement review: '+statement.origin)
                code = code[:match.start()]+'goto'+stack[-1][action]
                self.event(statement, action.upper()+' lowered to a unique loop-boundary label.')
            terminal_entries = []
            if code == 'enddo':
                if not stack or stack[-1]['terminal']:
                    raise ValueError('Mismatched END DO: '+statement.origin)
                terminal_entries.append(stack.pop())
            elif statement.label:
                while stack and stack[-1]['terminal'] == statement.label:
                    terminal_entries.append(stack.pop())
            for entry in terminal_entries:
                if entry['used_cycle']:
                    output.append(replace(statement, code='continue', label=entry['cycle']))
            output.append(replace(statement, code=code))
            for entry in terminal_entries:
                if entry['used_exit']:
                    output.append(replace(statement, code='continue', label=entry['exit']))
        if stack:
            raise ValueError('Unterminated DO in routine.')
        return output

    def intrinsics(self, statement):
        code = statement.code
        before = []
        if code.startswith('callsystem(') and '//' in code:
            expression = code[11:-1]
            # These two historical commands have exactly three concatenands.
            # Separate arguments retain each string's exact runtime length.
            parts = re.split(r'//(?=(?:[^"]*"[^"]*")*[^"]*$)', expression)
            if len(parts) != 3:
                raise ValueError('System concatenation requires explicit review: '+statement.origin)
            self.event(statement, 'Three command-string parts passed separately to a length-aware platform adapter.')
            return [replace(statement, code='callfeq_system3('+','.join(parts)+')')]
        direct_adjust = re.fullmatch(r'([a-z_]\w*)=(adjustl|adjustr)\((.*)\)', code)
        if direct_adjust:
            target, operation, argument = direct_adjust.groups()
            if self.symbols.get(target, {}).get('kind', '').startswith('character'):
                self.event(statement, operation.upper()+' assigned through a character adapter that snapshots aliased input.')
                return [replace(statement, code=f'callfeq_{operation}({argument},{target})')]
        # The four typed adapters preserve object bits, not numerical conversion.
        if 'transfer(' in code:
            transfer = re.search(r'\btransfer\(', code)
            end = close_paren(code, transfer.end()-1)
            source, mold = split_top(code[transfer.end():end])
            source_kind = self.symbols.get(source.split('(')[0], {}).get('kind')
            mold_kind = self.symbols.get(mold.split('(')[0], {}).get('kind')
            if source_kind.startswith('character') and mold_kind in ('real*8', 'doubleprecision'):
                name, kind = 'feq_transfer_cd', 'real*8'
            elif source_kind in ('real*8', 'doubleprecision') and mold_kind.startswith('character'):
                name, kind = 'feq_transfer_dc', 'character*8'
            elif source_kind == 'real' and mold_kind == 'integer':
                name, kind = 'feq_transfer_ri', 'integer'
            else:
                raise ValueError(f'Unreviewed TRANSFER types {source_kind}/{mold_kind}: {statement.origin}')
            self.external[name] = kind
            code = code[:transfer.start()]+name+'('+source+')'+code[end+1:]
            self.event(statement, 'TRANSFER mapped to a typed bit-copy adapter.')
        for function in ('adjustl', 'adjustr'):
            while True:
                match = re.search(r'\b'+function+r'\(', code)
                if not match:
                    break
                end = close_paren(code, match.end()-1)
                argument = code[match.end():end]
                base = argument.split('(')[0]
                kind = self.symbols.get(base, {}).get('kind', '')
                if not kind.startswith('character'):
                    raise ValueError('Character adapter type unavailable: '+statement.origin)
                # Substrings only occur in left adjustment followed by assignment.
                # A longer fixed temporary supplies only additional trailing blanks.
                if '(*)' in kind:
                    raise ValueError('Assumed-length adjustment requires a dedicated adapter: '+statement.origin)
                temporary = self.local(kind, 'adjust')
                before.append(replace(statement, code=f'callfeq_{function}({argument},{temporary})', label=''))
                code = code[:match.start()]+temporary+code[end+1:]
                self.event(statement, function.upper()+' uses an explicit character result temporary.')
        while True:
            match = re.search(r'\btrim\(', code)
            if not match:
                break
            end = close_paren(code, match.end()-1)
            argument = code[match.end():end]
            if not re.fullmatch(r'\w+', argument):
                raise ValueError('TRIM of a non-variable requires review: '+statement.origin)
            code = code[:match.start()]+argument+'(1:feq_len_trim('+argument+'))'+code[end+1:]
            self.external['feq_len_trim'] = 'integer'
            self.event(statement, 'TRIM lowered to a substring with the exact last-nonblank length.')
        if 'len_trim' in code:
            code = words_outside_strings(code, lambda name, tail: 'feq_len_trim' if name == 'len_trim' else name)
            if 'feq_len_trim(' in code:
                self.external['feq_len_trim'] = 'integer'
        if 'epsilon(' in code:
            match = re.search(r'\bepsilon\((\w+)\)', code)
            kind = self.symbols[match[1]]['kind']
            if kind != 'real':
                raise ValueError('EPSILON type needs review: '+statement.origin)
            code = code[:match.start()]+'1.1920928955078125e-7'+code[match.end():]
            self.event(statement, 'EPSILON for REAL*4 replaced by its exact IEEE-754 value, 2**(-23).')
        if "advance='NO'" in code or "advance='no'" in code:
            if code.lower() != "write(*,'(a1)',advance='no')'.'":
                raise ValueError('Unreviewed nonadvancing I/O: '+statement.origin)
            code = "write(*,'(a1,$)')'.'"
            self.event(statement, 'Nonadvancing one-character console progress uses the equivalent dollar format edit.')
        if before and statement.label:
            before[0] = replace(before[0], label=statement.label)
            statement = replace(statement, label='')
        return before+[replace(statement, code=code)]

    def arrays(self, statement):
        code = statement.code
        match = re.fullmatch(r'([a-z_]\w*)=(?!=)(.*)', code)
        if not match or match[1] not in self.symbols or not self.symbols[match[1]]['dimensions']:
            return [statement]
        name, expression = match.groups()
        dimensions = self.symbols[name]['dimensions']
        indexes = [self.local('integer', 'index') for dimension in dimensions]
        result = []
        for index, dimension in reversed(list(zip(indexes, dimensions))):
            bounds = split_top(dimension, ':')
            if len(bounds) == 1:
                bounds.insert(0, '1')
            result.append(replace(statement, code=f'do{index}={bounds[0]},{bounds[1]}', label=''))
        def element(word, tail):
            symbol = self.symbols.get(word)
            if symbol and symbol['dimensions'] and not tail.startswith('('):
                if len(symbol['dimensions']) != len(indexes):
                    raise ValueError('Array-assignment rank mismatch: '+statement.origin)
                return word+'('+','.join(indexes)+')'
            return word
        expression = words_outside_strings(expression, element)
        result.append(replace(statement, code=name+'('+','.join(indexes)+')='+expression, label=''))
        result.extend(replace(statement, code='enddo', label='') for dimension in dimensions)
        result[0] = replace(result[0], label=statement.label)
        self.event(statement, 'Whole-array assignment lowered to column-major indexed loops, retaining scalar broadcasting.')
        return result

    def routine(self, statements):
        self.locals, self.external = {}, {}
        self.labels = {line.label for line in statements if line.label}
        self.next_label = 99000
        self.symbols, parameters = symbol_table(statements)
        first = next(index for index, line in enumerate(statements) if not line.comment)
        header = statements[first]
        if not HEADER.match(header.code):
            raise ValueError('Missing routine header: '+header.origin+' '+header.code)
        routine_match = re.fullmatch(r'subroutine(\w+)\((.*)\)', header.code)
        dynamic_names = {
            'get_item_limits': ['head_start', 'head_end'],
            'twodtabfit': ['pqppfd', 'pqphu', 'ppqppfdphu', 'ppqphuppfd',
                          'pfdropphu', 'pqppfdadj', 'pqphuadj'],
        }
        if routine_match and routine_match[1] in dynamic_names:
            name, arguments = routine_match.groups()
            arrays = dynamic_names[name]
            argument_names = split_top(arguments)
            wrapper = {'name': name, 'implementation': name+'_storage',
                       'arguments': [{'name': item, **self.symbols[item]} for item in argument_names],
                       'arrays': [{'name': item, **self.symbols[item]} for item in arrays],
                       'origin': header.origin}
            self.dynamic_wrappers.append(wrapper)
            new_header = f'subroutine{name}_storage('+','.join(argument_names+arrays)+')'
            statements = list(statements)
            statements[first] = replace(header, code=new_header)
            self.event(header, 'Automatic local arrays supplied by a checked native allocation wrapper; dimensions and indexing retained.')
        prepared = []
        for line in statements:
            if line.comment:
                prepared.append(line)
            else:
                code = simplify_type(line.code)
                if code != line.code:
                    self.event(line, 'Equivalent explicit-size Fortran 77 type declaration.')
                prepared.append(replace(line, code=code))
        prepared = self.selects(prepared)
        prepared = self.loops(prepared)
        output = []
        for line in prepared:
            if line.comment or HEADER.match(line.code):
                output.append(line)
            elif is_specification(line.code):
                # LEN_TRIM becomes a typed external adapter, not an unknown intrinsic.
                code = words_outside_strings(line.code, lambda name, tail: 'feq_len_trim' if name == 'len_trim' else name)
                if code.startswith('intrinsic'):
                    names = [name for name in split_top(code[9:]) if name not in ('len_trim', 'feq_len_trim')]
                    if not names:
                        continue
                    code = 'intrinsic'+','.join(names)
                # Remove the old scalar declaration; the typed adapter is inserted once.
                if re.fullmatch(r'integer(?:\*4)?feq_len_trim', code):
                    continue
                output.append(replace(line, code=code))
            else:
                for item in self.intrinsics(line):
                    output.extend(self.arrays(item))
        # DATA may precede later declarations in F95; f2c requires it last.
        data = [line for line in output if not line.comment and line.code.startswith('data') and is_specification(line.code)]
        output = [line for line in output if line not in data]
        insertion = None
        for index, line in enumerate(output):
            if line.comment or HEADER.match(line.code) or is_specification(line.code):
                continue
            insertion = index
            break
        if insertion is None:
            insertion = len(output)-1
        extra = []
        for name, kind in self.locals.items():
            extra.append(Statement(kind+' '+name, origin=header.origin))
        for name, kind in self.external.items():
            extra.append(Statement(kind+' '+name, origin=header.origin))
            extra.append(Statement('external '+name, origin=header.origin))
        output[insertion:insertion] = extra+data
        return output


def render(statements):
    output = []
    for statement in statements:
        if statement.comment:
            output.append('c'+statement.code)
            continue
        code = statement.code
        if statement.origin:
            output.append('c SOURCE '+statement.origin)
        # Split at the exact fixed-form boundary. Continued string literals retain
        # all characters because every intermediate record fills column 72.
        for start in range(0, len(code), 66):
            prefix = statement.label.rjust(5)+' ' if start == 0 else '     &'
            output.append(prefix+code[start:start+66])
    return '\n'.join(output)+'\n'


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('source', type=Path)
    parser.add_argument('output', type=Path)
    parser.add_argument('--f2c', type=Path)
    parser.add_argument('--real-mode', choices=['double-intermediates', 'single-intermediates'], default='double-intermediates')
    args = parser.parse_args()
    destination = args.output.resolve()
    if ROOT / 'build' not in destination.parents:
        parser.error('Probe products must stay in FEQ/build/.')
    destination.mkdir(parents=True, exist_ok=True)
    records = []
    failed = 0
    for path in sorted(args.source.glob('*.for')):
        conversion = Lowering()
        record = {'file': path.name}
        try:
            statements = read_fixed(path)
            result, routine = [], []
            for statement in statements:
                routine.append(statement)
                if not statement.comment and statement.code == 'end':
                    result.extend(conversion.routine(routine))
                    routine = []
            if any(not line.comment for line in routine):
                raise ValueError('Source has code after its last END: '+path.name)
            result.extend(routine)
            target = destination / (path.stem+'.f')
            target.write_text(render(result))
            record['transformations'] = conversion.events
            record['dynamic_wrappers'] = conversion.dynamic_wrappers
            if args.f2c:
                command = [str(args.f2c.resolve()), '-C++', '-a', '-c', '-!bs']
                if args.real_mode == 'single-intermediates':
                    command.append('-R')
                command.append(target.name)
                record['translator_arguments'] = command[1:]
                process = subprocess.run(command, cwd=destination, capture_output=True, text=True)
                (destination / (path.stem+'.log')).write_text(process.stderr)
                record['translator_returncode'] = process.returncode
                failed += process.returncode != 0
                print(f'{path.name}: {len(conversion.events)} transformations; f2c {process.returncode}', flush=True)
        except Exception as error:
            record['error'] = str(error)
            failed += 1
            print(f'{path.name}: FAILED: {error}', flush=True)
        records.append(record)
    (destination / 'lowering-manifest.json').write_text(json.dumps(records, indent=2)+'\n')
    print(f'{len(records)} files inspected; {failed} incomplete.', flush=True)
    raise SystemExit(1 if failed else 0)


if __name__ == '__main__':
    main()
