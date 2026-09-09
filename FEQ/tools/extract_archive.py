#!/usr/bin/env python3
"""Extract a preserved ZIP with member hashes and no path traversal."""
import argparse
import hashlib
import json
import pathlib
import zipfile

ROOT = pathlib.Path(__file__).resolve().parents[1]


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('archive', type=pathlib.Path)
    parser.add_argument('destination', type=pathlib.Path)
    args = parser.parse_args()
    archive = args.archive.resolve()
    destination = args.destination.resolve()
    destination.relative_to(ROOT / 'originals')
    members = []
    paths = set()
    with zipfile.ZipFile(archive) as source:
        for member in source.infolist():
            relative = pathlib.PurePosixPath(member.filename.replace('\\', '/'))
            if relative.is_absolute() or '..' in relative.parts or any(':' in p for p in relative.parts):
                raise ValueError(f'Unsafe archive path: {member.filename}')
            if member.is_dir():
                continue
            mode = (member.external_attr >> 16) & 0xFFFF
            if mode & 0o170000 == 0o120000:
                raise ValueError(f'Symlink in archive: {member.filename}')
            target = destination / relative
            if str(relative) in paths:
                raise ValueError(f'Duplicate member: {member.filename}')
            paths.add(str(relative))
            payload = source.read(member)
            if target.exists() and target.read_bytes() != payload:
                raise ValueError(f'Extraction would overwrite different bytes: {target}')
            target.parent.mkdir(parents=True, exist_ok=True)
            target.write_bytes(payload)
            members.append({'member':member.filename,'path':str(target.relative_to(ROOT)),
                            'size':len(payload),'sha256':hashlib.sha256(payload).hexdigest(),
                            'zip_crc32':f'{member.CRC:08x}','zip_date_time':member.date_time})
    record = {'archive':str(archive.relative_to(ROOT)),
              'sha256':hashlib.sha256(archive.read_bytes()).hexdigest(),'members':members}
    output = ROOT / 'recovery/archives' / (archive.stem + '.json')
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(record,indent=2)+'\n')
    print(f'{archive.name}: {len(members)} files, {sum(p["size"] for p in members)} bytes')


if __name__ == '__main__':
    main()
