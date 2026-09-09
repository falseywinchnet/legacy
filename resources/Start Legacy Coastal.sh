#!/bin/sh
# Start the bundled desktop application from any working directory.
app_dir=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
exec "$app_dir/Legacy Coastal" "$@"
