#!/usr/bin/env python3
"""Fetch explicitly listed historical files and record their original bytes."""
import argparse
import concurrent.futures
import datetime
import hashlib
import json
import pathlib
import urllib.request

ROOT = pathlib.Path(__file__).resolve().parents[1]
MANIFEST = ROOT / 'recovery/manifest.json'


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('sources', type=pathlib.Path)
    parser.add_argument('--refresh', action='store_true')
    args = parser.parse_args()
    sources = json.loads(args.sources.read_text())
    old = json.loads(MANIFEST.read_text()) if MANIFEST.exists() else []
    known = {item['path']: item for item in old}

    def fetch(source):
        relative = pathlib.PurePosixPath(source['path'])
        if relative.is_absolute() or '..' in relative.parts or relative.parts[0] != 'originals':
            raise ValueError('Recovery destinations must be inside originals/')
        target = ROOT / relative
        previous = known.get(str(relative))
        if target.exists() and previous and not args.refresh:
            digest = hashlib.sha256(target.read_bytes()).hexdigest()
            if digest != previous['sha256'] or previous['url'] != source['url']:
                raise ValueError(f'Existing recovery differs from its record: {relative}')
            return previous
        request = urllib.request.Request(source['url'], headers={'User-Agent': 'Legacy-FEQ-source-recovery/1.0'})
        with urllib.request.urlopen(request, timeout=90) as response:
            payload = response.read()
            entry = dict(source)
            entry.update(final_url=response.url, status=response.status,
                         content_type=response.headers.get('Content-Type'),
                         last_modified=response.headers.get('Last-Modified'),
                         size=len(payload), sha256=hashlib.sha256(payload).hexdigest(),
                         retrieved_at=datetime.datetime.now(datetime.timezone.utc).isoformat())
        if source.get('kind') == 'distribution' and not payload.startswith((b'PK', b'MZ', b'\x1f\x8b')):
            raise ValueError(f'Download is not an archive/executable: {source["url"]}')
        target.parent.mkdir(parents=True, exist_ok=True)
        temporary = target.with_name(target.name + '.download')
        temporary.write_bytes(payload)
        temporary.replace(target)
        return entry

    failures = []
    with concurrent.futures.ThreadPoolExecutor(max_workers=4) as pool:
        futures = {pool.submit(fetch, item): item for item in sources}
        for future in concurrent.futures.as_completed(futures):
            source = futures[future]
            try:
                entry = future.result()
                known[entry['path']] = entry
                print(f'{entry["path"]}: {entry["size"]} bytes {entry["sha256"]}', flush=True)
            except Exception as error:
                failure = dict(source, error=str(error))
                failures.append(failure)
                print(f'FAILED {source["url"]}: {error}', flush=True)
    MANIFEST.parent.mkdir(parents=True, exist_ok=True)
    MANIFEST.write_text(json.dumps(sorted(known.values(), key=lambda item: item['path']), indent=2) + '\n')
    (ROOT / 'recovery/fetch-failures.json').write_text(json.dumps(failures, indent=2) + '\n')
    if failures:
        raise SystemExit(1)


if __name__ == '__main__':
    main()
