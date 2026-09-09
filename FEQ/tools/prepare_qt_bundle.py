#!/usr/bin/env python3
"""Prepare pinned Qt source archives and third-party notices for redistribution.

This is a maintainer packaging step, not a user or engine build dependency.
Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
"""
import argparse
import hashlib
import json
from pathlib import Path, PurePosixPath
import shutil
import tarfile
import urllib.request
VERSION = '6.11.2'
ARCHIVES = {
    'qtbase': '5b2e00eccaf5a4d8c14134ffa0ea8dfd0a35ae1ffc7f8d87fa4305a1ed23cf22',
    'qtsvg': 'd594337feca84c26fb67fe87b85e6a5c12fda404b611d905f9d138210c311876',
    'qtwayland': '8eb7615e39332a10f506e8dd70f02d5954bb5949ff54f6dcbf8bd6168222f9df',
}

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output', required=True, type=Path)
    parser.add_argument('--cache', required=True, type=Path)
    args = parser.parse_args()
    args.cache.mkdir(parents=True, exist_ok=True)
    (args.output/'sources').mkdir(parents=True, exist_ok=True)
    records = []
    for module, expected in ARCHIVES.items():
        name = module+'-everywhere-src-'+VERSION+'.tar.xz'
        url = 'https://download.qt.io/archive/qt/6.11/'+VERSION+'/submodules/'+name
        archive = args.cache/name
        if not archive.exists():
            temporary = archive.with_suffix('.download')
            with urllib.request.urlopen(url, timeout=120) as response, temporary.open('wb') as output:
                shutil.copyfileobj(response, output)
            temporary.replace(archive)
        actual = hashlib.sha256(archive.read_bytes()).hexdigest()
        if actual != expected:
            raise ValueError('Qt source checksum mismatch: '+str(archive))
        shutil.copy2(archive, args.output/'sources'/name)
        # Copy notices as readable files as well as retaining their complete
        # context in the unchanged source archives. Never extract archive paths.
        with tarfile.open(archive) as package:
            for member in package:
                path = PurePosixPath(member.name)
                base = path.name.lower()
                notice = '/LICENSES/' in member.name or base.startswith(('license', 'copying', 'copyright')) or base == 'qt_attribution.json'
                if not member.isfile() or not notice:
                    continue
                if path.is_absolute() or '..' in path.parts:
                    raise ValueError('Unsafe path in Qt source archive')
                destination = args.output/'notices'/Path(*path.parts)
                destination.parent.mkdir(parents=True, exist_ok=True)
                with package.extractfile(member) as source, destination.open('wb') as output:
                    shutil.copyfileobj(source, output)
        records.append(dict(module=module, version=VERSION, url=url, sha256=actual, bytes=archive.stat().st_size))
        print(name+': verified source and notices')
    (args.output/'sources.json').write_text(json.dumps(records,indent=2)+'\n')
    root = Path(__file__).resolve().parents[1]
    shutil.copy2(root/'app/licenses/Qt-NOTICE.md', args.output/'Qt-NOTICE.md')
if __name__ == '__main__':
    main()
