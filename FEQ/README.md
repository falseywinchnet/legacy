# FEQ / FEQUTL

This project is bringing **USGS FEQ 10.61** and **FEQUTL 5.80** to modern,
portable C++. FEQ solves one-dimensional unsteady flow in channel networks and
control structures. FEQUTL produces the hydraulic function tables used by FEQ.

**Implementation in progress. A native C++ application is not released yet.**
The original releases, manuals, source comparison, executable regression
baseline, and first verified independent C++ numerical components are available
here. The completed coastal software is a separate
project in [`../CHAMP/`](../CHAMP/).

**Work: Astra · Sponsor: Rainstar · Foundation: Hashem.** New project work is
covered by the [MIT license](LICENSE), subject to the explicit scope and preserved
historical notices in [NOTICE.md](NOTICE.md).

## What has been verified

The official 2009 distribution contains FEQ 10.61 and FEQUTL 5.80 Windows
executables, their Fortran source, helper utilities, and six example runs.
All six run under Wine. The resulting 17 files match the distributed expected
outputs byte for byte after masking only run timestamps and elapsed execution
clocks. Five files match without any masking, including all four FEQ water-level
and discharge histories. No hydraulic values, diagnostics, spacing, version
fields, or convergence results are excluded from this comparison.

This establishes the original executable baseline. It does not yet establish
C++ equivalence. See [the recorded comparison](recovery/reference-1061-comparison.json)
and [recovery findings](recovery/FINDINGS.md).

The independent C++ profile-matrix factorization and solution routines now match
**every output bit in 48 direct tests of the original executable**. These include
dense matrices at three scales and the specialized branch blocks. The tests
preserve the original compiler's wider register intermediates and explicit
single-precision stores. Their captured inputs and outputs are committed in
[`tests/reference/profile_matrix/`](tests/reference/profile_matrix/).

Complete translated research engines also execute all six examples. Full-engine
equivalence remains in progress: the current strict comparison passes 5 of the
17 files, with numerical differences in the remaining reports and tables.
[`recovery/cpp-research-status.json`](recovery/cpp-research-status.json) records
the actual binaries, runtime changes, and all comparisons. These research
engines are not application releases.

## Build and check the independent C++ components

A C++20 compiler and CMake 3.20 or newer build the numerical library. Python 3
runs the fixture comparison during testing. From the collection root:

```sh
cmake -S FEQ -B FEQ/build/core -DCMAKE_BUILD_TYPE=Release
cmake --build FEQ/build/core --config Release
ctest --test-dir FEQ/build/core -C Release --output-on-failure
```

This checks the original-executable matrix fixtures, defined shared storage,
and the historical input fingerprint algorithm. It does not require Wine,
Fortran, or a source translator. The CI workflow runs these checks on Windows,
macOS, and Linux, with a separate sanitizer build.

## Reproduce the original baseline

On macOS or Linux, install Wine with support for 32-bit Windows programs. On
Windows the executables run directly. Python 3 is needed for these research tools.
From this directory:

```sh
python3 tools/run_originals.py --output build/reference-run
python3 tools/compare_reports.py build/reference-run/test
```

Choose a new output directory for each run. The runner preserves inputs, binary
hashes, commands, raw console logs, raw output files, and a run manifest. It copies
the distribution into the run directory and never runs inside `originals/`.

The original commands are `feq input-file report-file` and
`fequtl input-file report-file table-file`. The original filename and working
directory conventions still apply to these historical programs.

## Project contents

| Location | Contents |
| --- | --- |
| [`originals/archives/`](originals/archives/) | Exact downloaded distributions and companion installers. |
| [`originals/feq1061/`](originals/feq1061/) | Complete unpacked 10.61/5.80 archive, including source, binaries, examples, and embedded Subversion snapshots. |
| [`originals/feq998/`](originals/feq998/) | Earlier 9.98/5.46 distribution for comparison. |
| [`originals/manuals/`](originals/manuals/) | FEQ and FEQUTL manuals, alternate published formats, FEMA review guidance, and companion user guides. |
| [`recovery/`](recovery/) | Download hashes and provenance, archive-member hashes, source inventory, revision diffs, and reference results. |
| [`tools/`](tools/) | Reproducible recovery, source analysis, and original-executable comparison tools. |

## Numerical compatibility requirements

The implementation must retain the requested releases' input semantics, table
formats, numerical precision, operation ordering where it affects results,
convergence decisions, and diagnostics. Equations and their source locations
belong beside the implementing code. Version-specific defects must be identified
and tested; a correction must never silently masquerade as 10.61/5.80 behavior.

USGS documents a FEQ 10.61 side-weir time-factor defect and a warning about the
secondary convergence criterion. The distributed FEQUTL source also contains a
March 2009 roughness fix absent from its embedded pristine source snapshot.
[FINDINGS.md](recovery/FINDINGS.md) records these distinctions and their evidence.

New C++ uses explicit types, ordinary indexed loops, portable storage and I/O,
and checked boundaries. `auto`, range-based loops, ranges, and reliance on
undefined behavior are excluded from the authored implementation.
