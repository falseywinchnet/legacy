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

The energy-section lookup matches **840 intervals against both `XLKT22` and
`XLKTAL` in both released programs**, for 3,360 original calls. All eleven
properties, including energy coefficients and logarithmically interpolated
critical flow, match every bit. The tests cover five table types, explicit
slopes, three scales, interval endpoints, and the special zero-depth rule.
The fixtures are in [`tests/reference/section_energy/`](tests/reference/section_energy/).

The `REGFLT`, `RGF`, `RGF3` and `RGF5` root solvers each match **434
original-executable cases**, including every bracket field, failure flag,
callback count, and trial argument. Each routine retains its own convergence
ordering, endpoint selection, damping, and failure outputs. The tests cover
threshold equality, the `RGF5` tolerance floor, wide residuals, all four return
flags, the 101-evaluation limit, three numerical scales, and callbacks that
adjust the trial argument. The same fixtures separately verify the adapter's
original argument addresses. See [`src/root_solver.cpp`](src/root_solver.cpp)
and [`tests/reference/root_solver/`](tests/reference/root_solver/).

`REGFAL` and `FDROOT` each match **894 original-executable cases**. These
add wide endpoint residuals, every search position, status preservation and
callbacks that change their argument or the external bracket and status.
Every callback's visible state and argument relationship matches, both through
the C++ API and the research adapter. REGFAL retains wide residuals throughout;
FDROOT preserves the incoming status on success and caches its search interval
after evaluating both endpoints. See
[`tests/reference/root_search_regfal/`](tests/reference/root_search_regfal/) and
[`tests/reference/root_search_fdroot/`](tests/reference/root_search_fdroot/).

The subcritical and supercritical energy residuals match **840 cases against
both original functions**, for 1,680 original calls. These include all five
section-table types and depths above the barrel-height lookup limit. Velocity,
energy, eddy losses and the returned residual retain the original wide
arithmetic. The energy term uses the requested depth even when the section
lookup uses a lower barrel height. See
[`src/steady_residual.cpp`](src/steady_residual.cpp) and
[`tests/reference/steady_residual/`](tests/reference/steady_residual/).

Specific energy and normal-flow calculations also match **432 original
instruction-sequence cases**. `SFPSBE` retains the initial depth difference,
velocity, energy and Froude ratio in wide registers, while its normal-flow
square roots store REAL before multiplication. The integration preserves
those distinctions and the separate REAL value used by the initial-depth
error message. See [`tests/reference/steady_profile/`](tests/reference/steady_profile/).

The standalone normal-flow residual matches **3,072 original instruction-sequence
cases**, including near-root cancellation, three scales, signed flow and zero
slope. NDRSD returns `(sqrt(S)*K-Q)/Q` without a REAL store; its lookup receives
a private copy of the trial depth. See
[`tests/reference/normal_flow_residual/`](tests/reference/normal_flow_residual/).

Both departure-reach energy residuals match **3,072 original instruction-sequence
cases each**. R4TO44 and R44TO4 preserve the private depth used by section
lookup and return their energy imbalance without rounding the velocity or
residual to REAL. See
[`tests/reference/departure_energy/`](tests/reference/departure_energy/).

The tailwater momentum balance and normalized residual match **3,072 original
instruction-sequence cases**, retaining both returned binary64 values. The
upstream balance stays wide across downstream calculations, and the final
residual stays wide through the root-solver return. Flap force is an input to
these fixtures. See [`src/tailwater_residual.cpp`](src/tailwater_residual.cpp) and
[`tests/reference/tailwater_momentum/`](tests/reference/tailwater_momentum/).

Tailwater spacing and both square-root-drop table stores match **3,072
original-executable cases**, covering three elevation scales, nine table sizes,
and eleven powers. The original level-generation loop runs in place, including
its REAL power routine. The C++ preserves the wide head difference and
reciprocal, the REAL power argument and result, and the REAL square root stored
in a DOUBLE PRECISION table. See
[`tests/reference/tailwater_spacing/`](tests/reference/tailwater_spacing/).

Channel-rating elevations, free-drop subtraction, normal flow and partial-drop
spacing match **3,072 original-executable cases**. The original CHNTAB power
loop runs in place; both FRFCHN free-flow exits retain the upstream and
downstream elevations until their final subtraction. See
[`src/channel_rating.cpp`](src/channel_rating.cpp) and
[`tests/reference/channel_rating/`](tests/reference/channel_rating/).

Transition loss smoothing and generalized conveyance means match **3,072
calls to each unchanged original routine**. The energy checks, head residuals,
both total-head stores and Froude residuals match another **3,072 original
instruction-sequence cases**. Partial-flow spacing and the independently
stored weir drop and downstream head match **3,072 cases**. The implementation
preserves the branch-specific REAL store in the conveyance mean and the wide
energy balances. See [`src/transition_energy.cpp`](src/transition_energy.cpp)
and [`the numerical evidence`](recovery/NUMERICAL_PROBES.md).

The `QCLIMIT` slot-flow extrapolation matches **3,072 original instruction
sequence cases**, including the supplied sewer table. The logarithms and
exponential round to REAL at their original stores; the resulting limiting
flow stays wide across reporting, slope calculation and individual table
stores. Both the retained flow and its REAL copies match every bit. See
[`tests/reference/critical_flow_limit/`](tests/reference/critical_flow_limit/).

The generalized Ritter wave-table step, complete `XLOOKW` interval lookup and
`FRIT` flow residual each match **3,072 original-executable cases**. The
Escoffier variable remains wide between table rows; the celerity, stored table
values and report copies retain their original REAL stores. The interval lookup
also retains the wider area and width used to compute celerity. See
[`src/ritter_flow.cpp`](src/ritter_flow.cpp) and
[`tests/reference/ritter_wave/`](tests/reference/ritter_wave/).

The standalone conveyance lookup matches **2,688 calls to the complete original
LKTK routine**, covering all fourteen accepted section table types, three
scales, interval endpoints, and increasing or decreasing conveyance. Its
linear interpolation of `sqrt(K)` stays wide through squaring. The integration
preserves the existing interval search, diagnostics and cached row. See
[`tests/reference/scalar_conveyance/`](tests/reference/scalar_conveyance/).

Full-barrel flow and entrance piezometric elevation match **3,072 calls to the
unchanged original FULBAR routine**. These cover three geometric scales,
discharge coefficients through unity, zero and positive road flow, zero and
positive barrel friction, and seven convergence tolerances. The implementation
preserves the original single-precision divisor and square-root stores, and
the iteration's choice of the previous flow estimate on convergence. See
[`src/full_barrel.cpp`](src/full_barrel.cpp) and
[`tests/reference/full_barrel/`](tests/reference/full_barrel/).

The approach-section energy balance matches **840 direct original RAPP calls**,
including every returned bit, the contraction flag, and all thirteen stored
section fields. These cover the expansion/contraction transition and both sides
of the area-ratio threshold. The same fixtures verify the untouched RQVSTW
head-difference instruction sequence. The independent implementation preserves
the wide velocity heads, friction, interpolated loss coefficients and returned
residual. See [`src/approach_residual.cpp`](src/approach_residual.cpp) and
[`tests/reference/approach_residual/`](tests/reference/approach_residual/).

Cross-section station fractions match **585 original instruction-sequence
cases**, including adjacent float stations and five distance scales. The
implementation keeps wide station differences and the original reciprocal
multiplication. These distinctions are observable: 116 fixtures differ under
direct division, and 443 differ with single-precision distances and fraction.
See [`tests/reference/station_fraction/`](tests/reference/station_fraction/).

The standard closed-section slot replacement matches **625 direct CUTTAB
calls**, including the retained row count and every value in thirteen table
columns. Of these, 354 change a slot row and 271 preserve the input table.
The implementation keeps the unrounded new area for the first-moment integral
and preserves the original zero-width skip and unit thresholds. See
[`tests/reference/section_slot/`](tests/reference/section_slot/).

The Gauss-Legendre rule generator matches **every supported order from 1
through 256**, including all 65,792 binary64 node and weight values. Its C++
implementation preserves the Legendre recurrence, implicit QL rotations,
convergence threshold and eigenvector ordering. See
[`tests/reference/gaussian_rule/`](tests/reference/gaussian_rule/).

Gaussian integration for linearly varying sinuosity matches **651 direct
FBASEL calls**, including all eight integral sums and the stored subsection
values. Both the C++ API and its engine adapter pass the same raw fixtures.
These exercise OLDBETA, NEWBETA, NEWBETAX, clipped boundaries, multiple roughness
modes and quadrature orders. See
[`tests/reference/section_sinuosity/`](tests/reference/section_sinuosity/).

Underflow-gate momentum matches **3,360 direct original residual calls**,
including squared-flow stores and all forty REAL values in the gate COMMON
block. The same fixtures verify LKTJ's distinct scalar first-moment arithmetic.
Another **678 cases** capture the original free and submerged tailwater
elevation instructions, including small drops above large datums. See
[`tests/reference/gate_residual/`](tests/reference/gate_residual/) and
[`tests/reference/gate_levels/`](tests/reference/gate_levels/).

The gate critical-flow setup and free-weir iteration match **894 original
instruction-block cases**. They preserve the stored area and square-root
velocity and retain the head and iterative depths until convergence. Inverse
specific energy also matches **5,040 full original FISE calls**, covering all
six section selectors across 840 section fixtures. See
[`tests/reference/gate_free/`](tests/reference/gate_free/) and
[`tests/reference/specific_energy/`](tests/reference/specific_energy/).

The upstream transition head and free-orifice flow match **1,278 original
instruction-block cases**. The upstream elevation remains wide until the
datum has been subtracted; effective area and square-root velocity each have
their own REAL store. These distinctions restore the complete supplied
UTLEXM function table, which now matches after masking only its timestamp.
See [`tests/reference/gate_orifice/`](tests/reference/gate_orifice/).

Power-function breakpoint spacing matches **1,531 original instruction-block
cases**, including point counts, error flags, complete point storage and
capacity failures. It preserves the REAL logarithms and the paired products
used by LSTOPF's released loop. See
[`tests/reference/power_spacing/`](tests/reference/power_spacing/).

Gate lip-contact flow, the transition midpoint and free-orifice state match
**1,280 original instruction-sequence cases**, including all eight stored
results. They preserve the unrounded coefficient-area product and midpoint,
and the separately stored jet depth and square-root velocity. See
[`tests/reference/gate_state/`](tests/reference/gate_state/).

The complete supplied gate example also matches **all 19,701 residual-entry
records**, including every trial argument and every value in the gate COMMON
block. The capture limits exceed the complete call counts. Its complete
UFGATE report section also matches every byte; see
[`recovery/gate-residual-trajectories.json`](recovery/gate-residual-trajectories.json).

Contraction adjustment and culvert velocity-head loss match **528 direct
original-executable cases**. These check the full-width coefficient return,
the caller's float store, and the head-loss result at three scales and around
the contraction threshold. The fixtures retain the exact original head-loss
instruction bytes by hash in
[`tests/reference/culvert_loss/`](tests/reference/culvert_loss/).

The type-2 culvert head-loss calculation separately matches **3,073 original
instruction-sequence cases**. RTY2 retains `Q3/A3` through its square and stores
only the completed head loss. These fixtures include the first type-2 call in
the supplied culvert example; see
[`tests/reference/type2_head_loss/`](tests/reference/type2_head_loss/).

The fitted discharge coefficients match **879 original calls** across all five
supported culvert classes, all three flow types, head and Froude thresholds,
entrance adjustment factors, and head-ratio flags. The separate critical-flow
lookup matches **840 cases in each original program**, including its distinct
zero-depth result. The fixtures are in
[`tests/reference/culvert_coefficient/`](tests/reference/culvert_coefficient/) and
[`tests/reference/critical_flow/`](tests/reference/critical_flow/).

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
sinuosity uses the separately verified Gaussian integration path described above.

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

The circular, rectangular, elliptical, and mirrored conduit constructors match
**959 direct original-executable cases**, including circular polygons with
3 through 128 sides and selected counts through 10,000. The circular constructor
preserves x87's 66-bit pi reduction, which matters for the small nonzero invert
coordinate. Ellipse area correction, box spacing, and slot intersections retain
the released intermediate precision and single precision stores. The raw point
counts and coordinates are in
[`tests/reference/conduit_boundary/`](tests/reference/conduit_boundary/).

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

List-directed REAL fields match **all 6,488 complete original output records**,
including console and report-file margins, scalar and label/scalar writes,
trailing zeros, exponent spelling and the original decimal rounding decisions.
These preserve the compiler I/O options installed by the original MAIN.
The fixtures retain both raw output streams in
[`tests/reference/list_real/`](tests/reference/list_real/).

Complete translated research engines execute all six examples. **All twelve
FEQ report files now match**, masking only execution clocks; all four FEQ
water-level and discharge histories match raw bytes. Every numerical value,
diagnostic, convergence location, and other report byte is included. Across
both programs, the strict comparison passes **all 17 files**. Both CULVERT
outputs, the complete UTLEXM report and its function table match with only
their timestamps masked. The UTLEXM cross-section file matches raw bytes.
[`recovery/cpp-research-status.json`](recovery/cpp-research-status.json) records
the actual binaries, runtime changes, and all comparisons. These research
engines are not application releases, and example coverage does not establish
complete input-space equivalence.

Tracing establishes exact active solver inputs at every matrix assembly in
FEQEX1 (621 matrices), FEQEX2 (325), FEQEX3 (578), and FEQEX4 (568). These comparisons
include every active coefficient, residual, and profile/block index, with no tolerance.
The recorded comparison and trace configurations are in
[`recovery/model-active-matrices.json`](recovery/model-active-matrices.json).

The utility state comparison also matches **all 2,873 transition head-search
entries, 540 partial-flow report states and 60 snapshots of the first 5,000
function-table words** in UTLEXM. No state fields are masked. This table-memory
comparison exposed three Ritter accumulator differences that did not change
the printed reports; those differences are now corrected. The trace hooks,
build provenance and report checks are recorded in
[`recovery/utility-state-trajectories.json`](recovery/utility-state-trajectories.json).

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
