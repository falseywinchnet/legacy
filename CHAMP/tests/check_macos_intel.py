#!/usr/bin/env python3
"""Run the reference suite against the Intel slices of a universal Mac build."""
from pathlib import Path
import shlex
import subprocess
import sys
import tempfile
root = Path(__file__).resolve().parents[1]
build = Path(sys.argv[1]).resolve()
programs = ["runup", "whafis", "runup_math_probe", "whafis_math_probe",
            "champ_math_probe", "project_probe", "access_probe", "io_probe"]
tasks = [("check_project_reference.py", "project_probe", root),
         ("check_champ_reference.py", "champ_math_probe", root),
         ("check_access_reference.py", "access_probe", root),
         ("check_runup_reference.py", "runup", root),
         ("check_whafis_reference.py", "whafis", root)]
tasks += [("check_whafis_routine.py", "whafis_math_probe", r, root)
          for r in ("SHBM", "T", "HM0", "HIN")]
tasks += [("check_routine_reference.py", "runup_math_probe", r,
           root / "tests/reference/runup/routines")
          for r in ("LOOK", "RINT", "SWLINT", "LOGLIN", "LOGLOG", "DBPLOT")]
with tempfile.TemporaryDirectory(prefix="legacy-intel-") as directory:
    wrappers = Path(directory)
    for name in programs:
        wrapper = wrappers / name
        wrapper.write_text('#!/bin/sh\nexec /usr/bin/arch -x86_64 ' +
                           shlex.quote(str(build / name)) + ' "$@"\n')
        wrapper.chmod(0o755)
    subprocess.run([wrappers / "io_probe"], check=True, timeout=30)
    for script, program, *args in tasks:
        subprocess.run([sys.executable, root / "tests" / script,
                        wrappers / program, *map(str, args)], check=True, timeout=120)
print("All 16 checks passed using the Intel slices of the universal build.")
