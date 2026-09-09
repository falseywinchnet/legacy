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
**every output bit in 62 direct tests of the original executable**. These include
dense matrices at three scales, specialized branch blocks, and eight mixed-block
matrices captured during the original FEQEX1 model and six FEQEX4 matrices
spanning a control-flow transition. The tests
preserve the original compiler's wider register intermediates and explicit
single-precision stores. Their captured inputs and outputs are committed in
[`tests/reference/profile_matrix/`](tests/reference/profile_matrix/),
[`tests/reference/profile_models/`](tests/reference/profile_models/), and
[`tests/reference/profile_controls/`](tests/reference/profile_controls/).

The independent cross-section interval interpolation matches **all seven output
words in 240 cases against both original lookup routines**, for 480 original
calls. An additional 240 cases verify the section's first moment and all seven
shared properties against `XLKT21`. Scalar function-table interpolation matches
both output words in **360 original-executable cases**, covering table types 2,
3, and 4. These tests cover multiple scales and both interval endpoints.
Equations and the exact machine-code rounding
points accompany [`src/section_interpolation.cpp`](src/section_interpolation.cpp).
The captured fixtures are in
[`tests/reference/section_interpolation/`](tests/reference/section_interpolation/).

The independent section-boundary geometry also matches **every geometric output
bit in 363 direct FEQUTL tests**. These cover dry, partially submerged, and fully
submerged boundaries, multiple subsections, three scales, vertical/horizontal
segments, overhangs, and fixed or depth-dependent roughness modes. Area and first
moment retain their original double precision; width, wetted perimeter, weighted
roughness, and maximum depth retain their observed single precision stores.
The fixtures are in [`tests/reference/section_geometry/`](tests/reference/section_geometry/).

The analytical NEWBETA flow pass matches **every output bit in 458 direct
FEQUTL cases**, including the six flow/flux sums and their derivatives,
multiple subsections, depth-dependent roughness, piecewise constant sinuosity,
and slopes on both sides of the horizontal-segment threshold. The independent
real and double power implementation matches **3,382 original-executable cases**
covering every finite normal exponent field and representative subnormals.
It retains the released approximation tables, sequential small-integer powers,
and even the original double-power subnormal normalization behavior. These
components use explicit portable C++ arithmetic and do not call host `pow`.
Their fixtures are in [`tests/reference/section_flux/`](tests/reference/section_flux/)
and [`tests/reference/power/`](tests/reference/power/). Piecewise linear
sinuosity uses a separate Gaussian integration path that remains to be verified.

Section-property aggregation matches **415 direct original-executable cases**,
including old and new flux coefficients, critical-flow selection, averaged
roughness, USGS coefficients, and retained slot conveyance. The independent
elevation-argument generator matches **201 original-executable cases**, including
near-zero insertion, subdivision spacing, duplicate removal, and exhausted
capacity. Both preserve the original mixed precision and in-place updates.
Their fixtures are in [`tests/reference/section_properties/`](tests/reference/section_properties/)
and [`tests/reference/elevation_arguments/`](tests/reference/elevation_arguments/).

The pipe-arch perimeter matches **757 direct original-executable cases**,
covering all seven standard families, three unit conversions, rise and span
selection, endpoint tolerances, and out-of-table returns. Its inverse
trigonometry preserves the original approximation coefficients and matches
**2,780 binary64 return values**. The formula comments identify the released
constants and every observed single precision store. Section and scalar table
lookups have also been independently recaptured from FEQUTL, with all output
bits agreeing with the corresponding FEQ fixtures. The fixtures are in
[`tests/reference/arch_perimeter/`](tests/reference/arch_perimeter/) and
[`tests/reference/trigonometry/`](tests/reference/trigonometry/).

The submerged-weir iteration matches **2,901 direct FEQUTL calls**: 2,691
distinct calls captured from the supplied example and 210 added cases around
the low/high-head table boundary, free-flow bypass, and complete submergence.
Both the returned total head and discharge match every bit. The integration
also restores the original Simpson accumulation and REAL power call used to
construct drop fractions. The fixtures and their original trace provenance are
in [`tests/reference/weir_flow/`](tests/reference/weir_flow/).

The independent single precision decimal converter matches **all 2,360 direct
original-executable cases**, including every finite exponent field, subnormals,
signed zeros, halfway values and their adjacent floats, infinities, and NaNs.
It preserves the original nine digit ceiling and binary scaling steps. The
captured digit bytes, counts, exponents, and G/EN descriptor states are committed
under [`tests/reference/decimal_digits/`](tests/reference/decimal_digits/).

Complete translated research engines execute all six examples. **All twelve
FEQ report files now match**, masking only execution clocks; all four FEQ
water-level and discharge histories match raw bytes. Every numerical value,
diagnostic, convergence location, and other report byte is included. Across
both programs, the strict comparison passes 13 of 17 files. Four FEQUTL reports
and tables still have numerical differences.
[`recovery/cpp-research-status.json`](recovery/cpp-research-status.json) records
the actual binaries, runtime changes, and all comparisons. These research
engines are not application releases, and example coverage does not establish
complete input-space equivalence.

Tracing establishes exact active solver inputs at every matrix assembly in
FEQEX1 (621 matrices), FEQEX2 (325), FEQEX3 (578), and FEQEX4 (568). These comparisons
include every active coefficient, residual, and profile/block index, with no tolerance.
The recorded comparison and trace configurations are in
[`recovery/model-active-matrices.json`](recovery/model-active-matrices.json).

## Build and check the independent C++ components

A C++20 compiler and CMake 3.20 or newer build the numerical library. Python 3
runs the fixture comparison during testing. From the collection root:

```sh
cmake -S FEQ -B FEQ/build/core -DCMAKE_BUILD_TYPE=Release
cmake --build FEQ/build/core --config Release
ctest --test-dir FEQ/build/core -C Release --output-on-failure
```

This checks the original-executable matrix, interpolation, geometry, flux, power,
and decimal fixtures, defined
shared storage, and the historical input fingerprint algorithm. It does not require Wine,
Fortran, or a source translator. The CI workflow runs these checks on Windows,
macOS, and Linux, with a separate sanitizer build.

[`recovery/NUMERICAL_PROBES.md`](recovery/NUMERICAL_PROBES.md) explains how to
recapture the original-machine-code fixtures and trace a full model.

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
