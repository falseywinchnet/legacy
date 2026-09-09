#!/bin/sh
# Launch from the extracted portable folder, regardless of the current directory.
feq_app_dir=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
exec "$feq_app_dir/bin/feq-workbench" "$@"
