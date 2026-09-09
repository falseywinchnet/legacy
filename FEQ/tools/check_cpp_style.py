#!/usr/bin/env python3
"""Enforce the requested explicit types and indexed loops in authored C++."""
from pathlib import Path
import re

root = Path(__file__).resolve().parents[1]
ignore = re.compile(r'/\*.*?\*/|//[^\n]*|"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'',re.S)
errors = []
for directory in ('src','include','tests','tools','engines'):
    for path in (root/directory).rglob('*'):
        if path.suffix not in ('.cpp','.hpp'):
            continue
        source = ignore.sub(lambda match:'\n'*match[0].count('\n'),path.read_text())
        for expression,label in [(r'\bauto\b','auto type deduction'),(r'\bstd\s*::\s*ranges\b','ranges'),
                                 (r'\bfor\s*\([^;{}]*(?<!:):(?!:)','range-based loop')]:
            for match in re.finditer(expression,source):
                errors.append(f'{path.relative_to(root)}:{source[:match.start()].count(chr(10))+1}: {label}')
if errors:
    print('\n'.join(errors))
    raise SystemExit(1)
print('C++ uses explicit types and indexed loops.')
