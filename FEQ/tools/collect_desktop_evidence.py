#!/usr/bin/env python3
"""Collect verification records without following application-package symlinks.

Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT license.
"""
import argparse
import os
from pathlib import Path
import shutil


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--build', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    build = args.build.resolve()
    output = args.output.resolve()
    roots = ['desktop/Testing/Temporary', 'desktop/desktop-verification',
             'desktop/example-verification', 'installation-verification',
             'installer-verification']
    extensions = {'.json', '.log', '.png', '.out', '.tab', '.spi', '.wsq', '.chx'}
    count = 0
    for root in roots:
        for directory, folders, files in os.walk(build/root, followlinks=False):
            folders[:] = [name for name in folders
                          if not (Path(directory)/name).is_symlink()
                          and not name.startswith('relocated installation')
                          and name not in {'installed', 'mounted'}]
            for name in files:
                source = Path(directory)/name
                if source.is_symlink():
                    continue
                if source.suffix.lower() not in extensions and name != 'dependencies.txt':
                    continue
                destination = output/source.relative_to(build)
                destination.parent.mkdir(parents=True, exist_ok=True)
                shutil.copyfile(source, destination)
                count += 1
    if count == 0:
        raise RuntimeError('No verification evidence was produced.')
    print(f'Collected {count} verification files without package or external symlinks.')


if __name__ == '__main__':
    main()
