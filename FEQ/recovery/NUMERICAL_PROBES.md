# Reproducing numerical probes

These tools distinguish routine verification, whole-model memory comparison,
and complete output comparison. Each answers a different question. A successful
routine test does not establish that the application as a whole is equivalent.

The tools open `originals/` read-only. Patched executables and working inputs
are created only in new directories under `FEQ/build/`. The original FEQ 10.61
executable must have SHA-256
`16e46628e3d55f654e5b39ceecc621bcfcec86a0b881197a6e5f5fd17ec42399`.

## Environment

Build the independent C++ test drivers using the README's CMake commands.
Their normal regression checks need only C++, CMake, and Python's standard
library. Recapturing original results also needs Wine with PE32 support on
macOS/Linux, or Windows itself, and these pinned research dependencies:

```sh
python3.12 -m venv FEQ/build/research-python
FEQ/build/research-python/bin/python -m pip install -r FEQ/tools/requirements-research.txt
```

The recorded original environment uses Wine 11.4. Python 3.12 with the pinned
syntax-tree versions is the verified research environment. The Python 3.14 /
tree-sitter 0.26 combination used during exploration crashed while processing
large generated files; it is not the supported reproduction environment.
On Windows use the equivalent virtual-environment `Scripts/python.exe` path.

## Direct routine calls

From the collection root, with a new output directory for each command:

```sh
FEQ/build/research-python/bin/python FEQ/tools/probe_profile_original.py \
  --native FEQ/build/core/feq_profile_probe --output FEQ/build/profile-recapture

FEQ/build/research-python/bin/python FEQ/tools/probe_section_original.py \
  --native FEQ/build/core/feq_section_probe --output FEQ/build/section-recapture

FEQ/build/research-python/bin/python FEQ/tools/probe_section_moment_original.py \
  --native FEQ/build/core/feq_section_probe --output FEQ/build/moment-recapture

FEQ/build/research-python/bin/python FEQ/tools/probe_table_original.py \
  --native FEQ/build/core/feq_table_probe --output FEQ/build/table-recapture
```

Use the corresponding `Release/*.exe` driver paths for a multi-configuration
Windows build. Both original executables initialize the Lahey runtime normally.
The temporary driver replaces PROGRAM entry, initializes specific COMMON words,
and calls the unchanged routine instructions. Inputs, original bytes, native
bytes, and comparisons are retained. No numerical tolerance is used.

The profile generator exercises 48 synthetic matrices. The section generator
exercises 240 intervals and calls each of `XLKT20` and `XXLKT20`, requiring the
two original implementations to agree before comparing C++. It preserves all
seven binary32 output words, including signed zeros.
The first-moment generator adds 240 `XLKT21` cases with eight output words and
also checks the original `XLKT20` shared properties. The function-table generator
adds 360 cases across types 2, 3, and 4. Their committed binary fixtures run as
ordinary CTest tests without Wine.

## Model traces and captured matrix tests

```sh
FEQ/build/research-python/bin/python FEQ/tools/trace_original.py \
  --config FEQ/recovery/probes/matrix-and-branch-trace.json \
  --case feqex1 --output FEQ/build/model-trace

FEQ/build/research-python/bin/python FEQ/tools/compare_matrix_traces.py \
  FEQ/build/model-trace/test/trace-00.bin \
  --extract-fixtures FEQ/build/model-matrices.json

FEQ/build/research-python/bin/python FEQ/tools/probe_profile_original.py \
  --fixtures FEQ/build/model-matrices.json \
  --native FEQ/build/core/feq_profile_probe --output FEQ/build/model-matrix-recapture
```

The trace hook adds one temporary PE section and redirects whole instructions
at a selected routine boundary. It saves and restores flags, general registers,
the x87 environment and all eight x87 registers. Original code/data addresses
remain unchanged. It preserves the original symbol/debug overlay. The manifest
records displaced instructions, trace ranges, replaced unused header text, and
hashes. An interior offset must be a decoded instruction boundary.

`trace_original.py` also compares the resulting model reports against the
published outputs, masking only the same explicitly named execution clocks
used by `compare_reports.py`. A trace run fails if those model outputs change.
The selected configuration captures eight full matrix COMMON records and eight
branch-state records. All eight captured mixed-block matrices also pass direct
original-versus-C++ factorization and solution tests.

`probes/branch-distance-trace.json` captures the original stack frame, static
local values, and x87 state immediately before the momentum coefficient
calculations. It established that `DXDT` uses a double-precision reciprocal but
is explicitly stored as binary32 before the following `DXHDT` expression.
The instructions are in `assembly/feq/_setinx_.asm` at `0x40c5fd` and `0x40c680`.

## Research integration

`probe_local_precision.py` creates candidates for non-addressed local variables
held in wider registers. This is deliberately labeled an experiment: blanket
promotion is not a proof of the original rounding behavior. `SETINX`'s explicit
`DXDT` store demonstrates why that distinction matters.

`attach_verified_components.py` selects actual C++ function definitions through
the syntax tree, connects section and scalar lookup routines to the independent
interval implementations, and optionally restores traced register/store behavior.
It records each change and all source hashes. The standalone profile adapter
connects the independently tested solver to the research COMMON layout.
`matrix_trace.cpp` is an optional development adapter, controlled by explicit
trace environment variables; it is not an end-user interface.

The current integration options are `--setinx-distance-rounding`,
`--traced-register-stores`, `--steady-initialization-registers`, and
`--control-register-stores`. These
preserve specific observed conversions, including single-precision call and
formatted-I/O boundaries within wider steady-initialization expressions.

After generating and integrating a translation, compile and link it explicitly:

```sh
python3 FEQ/tools/compile_cpp_probe.py FEQ/build/candidate --runtime FEQ/build/f2c/compat
python3 FEQ/tools/link_feq_research.py FEQ/build/candidate --runtime FEQ/build/f2c/compat \
  --output FEQ/build/feq-candidate --matrix-trace
```

The linker requires successful current compilation receipts. It verifies the
source set, source hashes, complete local/runtime header inventory, and object
hashes before rebuilding the independent components. Its manifest records the
compiler, commands, headers, objects, runtime archive, and executable hashes.
The source staging and compatibility runtime remain research prerequisites;
these commands do not constitute the final application installation procedure.

## Complete active-matrix traces

`probes/active-matrix-feqex1.json` through `active-matrix-feqex4.json` capture every
active matrix field for each supplied model at `PROFAC` entry. Each configuration
allows 1024 records; each completed run has fewer records, so the capture limit
does not truncate these examples. The counts are 621, 325, 578, and 568.
`compare_active_matrices.py configure` can derive the capture ranges from one
full COMMON record. Original trace ranges are fixed for the selected model;
the comparison validates the dimensions in each record.

For a native candidate linked with `--matrix-trace`, set `FEQ_MATRIX_TRACE` to
a new absolute output filename, `FEQ_MATRIX_TRACE_ACTIVE=1`, and
`FEQ_TRACE_LIMIT=1024` while running the corresponding example. Compare it using:

```sh
python3 FEQ/tools/compare_active_matrices.py compare \
  FEQ/build/original-trace/test/trace-00.bin FEQ/build/native-trace.bin \
  --output FEQ/build/matrix-comparison.json
```

Every active word now matches throughout all four models, including 568 FEQEX4
matrices. The current full-output comparison passes 13 of 17 files. `model-active-matrices.json` preserves all
trace hashes, counts, and independent original-output checks.
Unused COMMON capacity is outside this compact comparison. The older full-COMMON
capture remains in `matrix-entry-comparison.json` as historical evidence.

The six control-transition solver fixtures can be recaptured with
`probe_profile_original.py --fixtures FEQ/tests/reference/profile_controls/fixtures.json`,
using the same `--native` and new `--output` arguments as the earlier examples.
They cover FEQEX4 matrices 38 through 43 and preserve every factorized coefficient
and solution word.


## Original decimal digits

The REAL*4 digit probe replaces only the temporary PROGRAM driver and invokes
unchanged `_jwe_iroc` after original runtime startup. It captures 2,360 cases in
bounded batches; the preserved executable is hash-checked and never edited.
The native fixture driver uses explicit little-endian records on every platform.

```sh
FEQ/build/research-python/bin/python FEQ/tools/probe_decimal_original.py \
  --native FEQ/build/core/feq_decimal_probe --output FEQ/build/decimal-recapture
```

Input records are 16 bytes: float bits, edit kind, signed precision, and signed
scale as four 32-bit words. Output records are 32 bytes: signed count and
exponent, unsigned status, 16-bit general state and engineering shift, followed
by sixteen digit/padding bytes. F/E/G/EN kinds are 4/0/8/12. Precision is an
unsigned descriptor byte; scale is signed 16 bit. Captured fixtures and the
complete generator are committed under `tests/reference/decimal_digits/` and
`tools/probe_decimal_original.py`. The CMake test needs no Wine or original
binary. This verifies digit conversion, including special-value tokens; signs,
field overflow, and descriptor layout require separate report checks.

`prepare_probe_runtime.py` now connects REAL*4 F/E output to the independently
verified digit converter before field layout. Rebuild that isolated runtime,
recompile translated sources so their header receipts are current, then use
`link_feq_research.py`. The linker also accepts `--program fequtl` for the utility
research engine; matrix tracing is restricted to FEQ. Its final application
runtime and installation workflow are still being developed.


## FEQUTL boundary geometry

The section-geometry probe calls the original FEQUTL FBASEL with explicit
boundary points and subsection parameters. The input and six output arrays
preserve their mixed binary32/binary64 representations. The complete 363-case
fixture set includes fixed and depth-dependent roughness modes. OLDBETA and
zero sinuosity isolate geometric outputs from the separate flux calculations.

```sh
FEQ/build/research-python/bin/python FEQ/tools/probe_geometry_original.py \
  --native FEQ/build/core/feq_geometry_probe --output FEQ/build/geometry-recapture
```

`--fixtures` accepts an explicit JSON case list, for recapturing a selected
boundary. The manifest records per-case output offsets and input/output hashes.
The committed fixture set combines the 336 initial geometric cases and 27
additional depth-dependent roughness cases; both original capture hashes are
retained. The normal CMake replay needs no original executable or Wine.

To connect the component to a prepared FEQUTL translation:

```sh
FEQ/build/research-python/bin/python FEQ/tools/attach_utility_components.py \
  FEQ/build/prepared-utility FEQ/build/utility-candidate
python3 FEQ/tools/compile_cpp_probe.py FEQ/build/utility-candidate --runtime FEQ/build/f2c/compat
python3 FEQ/tools/link_feq_research.py FEQ/build/utility-candidate --program fequtl \
  --runtime FEQ/build/f2c/compat --output FEQ/build/fequtl-candidate
```

The utility integration now includes geometric and analytical flux passes,
section-property aggregation, elevation spacing, pipe-arch geometry, and section
and scalar table interpolation. Native output verification still uses complete
reports with the existing clock-only comparison policy. The remaining weir and
culvert flow differences require further recovery work.

## Powers and analytical flow integrals

The power driver calls the unchanged original `_g_arxr` and `_g_adxd` after
normal startup. Input records contain a 32-bit kind (0=REAL, 1=DOUBLE), a zero
reserved word, and two binary64 values. Outputs occupy eight bytes: a binary64
result or a binary32 result followed by four zero bytes. The default suite
reconstructs all 3,382 committed cases, including the full normal exponent
range and selected subnormal inputs.

```sh
FEQ/build/python312/bin/python FEQ/tools/probe_power_original.py \
  --native FEQ/build/core/feq_power_probe --output FEQ/build/power-recapture
```

The flow driver reuses the section geometry driver's temporary PROGRAM setup
and supplies NEWBETA with sinuosity modes 0 or 2. It writes the eight original
double sums, followed by SBSN, QS, and KS arrays in their original order. The
first six sums are the flow, momentum flux, energy flux, and their depth
derivatives. The remaining sums and QS/KS remain zero in this analytical path;
SBSN records the last wet segment's sinuosity for each subsection in mode 2.
The default suite has 216 isolated-segment cases. The committed full suite adds
242 multi-segment and boundary cases and can be recaptured explicitly:

```sh
FEQ/build/python312/bin/python FEQ/tools/probe_flux_original.py \
  --fixtures FEQ/tests/reference/section_flux/fixtures.json \
  --native FEQ/build/core/feq_flux_probe --output FEQ/build/flux-recapture
```

`tools/recover_power_tables.py` independently extracts the three numerical
coefficient tables to hexadecimal C++ literals. `src/power_coefficients.inc`
records the original executable and table-byte hashes. The compiler receipt
inventory includes `.inc` files so a coefficient change invalidates old object
receipts. All new fixture comparisons are raw-byte equality tests.

## Pipe-arch geometry and original inverse trigonometry

`probe_arch_original.py` reconstructs seven standard arch families from the
released conduit tables. It captures 757 cases with three unit conversions,
rise/span selection, both table endpoints, and values on either side of the
0.1-inch clamping threshold. Every returned dimension, error flag, point count,
invert offset, and coordinate word is compared, including untouched output
sentinels on error. The original span branch emits an error even after a small
out-of-range value has been clamped; the independent implementation retains it.

```sh
FEQ/build/python312/bin/python FEQ/tools/probe_arch_original.py \
  --native FEQ/build/core/feq_arch_probe --output FEQ/build/arch-recapture
FEQ/build/python312/bin/python FEQ/tools/probe_trigonometry_original.py \
  --native FEQ/build/core/feq_trigonometry_probe --output FEQ/build/trigonometry-recapture
```

The ASIN/ACOS probe captures the binary64 register result for 2,780 calls,
including signed zeros, endpoints, polynomial-branch neighbors, exponent-field
samples and random finite arguments. The C++ retains the original polynomial
coefficients and approximate pi constants. `arch_perimeter.cpp` documents the
original REAL square-root and angle stores, reciprocal constants, and area
correction. Its finite-angle sine/cosine calls use the host math library; the
committed arch fixture replay checks their final coordinate bits on each CI
platform. These finite fixtures do not establish equivalence outside their
covered inputs.

The section, first-moment, and scalar table drivers now accept `--program
fequtl`. Their independently captured utility outputs are byte-identical to
the existing FEQ fixtures; separate utility manifests retain that evidence.
`attach_utility_components.py` verifies that every required target source is
present before reporting a successful integration. The normal CMake build
also compiles all public headers together to detect conflicting declarations.

## Submerged-weir iteration

`probe_weir_original.py` installs three linear coefficient tables and uses a
bounded loop in a temporary PROGRAM driver to call the unchanged `STOTHQ`.
Input data starts with binary32 gravity and twice gravity, then three tables
(32-bit row count followed by binary32 argument/value pairs). Each case contains
seven binary32 inputs: critical head ratio, breadth, piezometric head, tailwater
head, approach depth, initial total head, and initial free flow. Each output is
the returned total head followed by discharge, as two unmodified binary32 words.

```sh
FEQ/build/python312/bin/python FEQ/tools/probe_weir_original.py \
  --native FEQ/build/core/feq_weir_probe --output FEQ/build/weir-recapture
```

The committed fixture JSON supplies 2,691 distinct model calls and 210 explicit
coefficient-boundary and submergence cases. Its source trace manifest records
the original hook locations, argument captures and unchanged model-output
comparison. The original trace captures the first 4,096 calls; the fixtures
select calls that use its initial coefficient-table snapshot. This is a bounded
component capture, not a claim to cover every call in the full example.

`weir_flow.cpp` retains the original reciprocal-depth multiplication, wide
iteration head and flow, REAL lookup ratios, and both REAL square-root stores.
The compatibility adapter retains the generated table lookup and original
diagnostic formats. The caller's Simpson integration also retains its wide
segment values and the original REAL reciprocal of six. Drop-fraction generation
uses the already verified REAL power kernel, including the original ratio
rounding before the call. Whole-output comparisons remain separate from these
component fixtures.


## Conduit boundary constructors

`probe_conduit_original.py` captures unchanged `URQTE`, `MKPIPE`, `MKBOX`,
`RHMAK`, and `URQMAK` code with a temporary PROGRAM driver. The 959 fixtures
contain 192 ellipse quadrants, 459 circular polygons, 84 boxes, 140 right-half
mirrors, and 84 quadrant mirrors. They cover varied dimensions and offsets,
all circular side counts from 3 through 128, selected counts through 10,000,
and right-half coordinates taken directly from the original arch fixtures.

```sh
FEQ/build/python312/bin/python FEQ/tools/probe_conduit_original.py \
  --native FEQ/build/core/feq_conduit_probe --output FEQ/build/conduit-recapture
```

Each input record has two little-endian 32-bit integers (constructor kind and
side count), six binary32 values (rise, span, slot width, slot height, horizontal
offset, vertical offset), and a 32-bit input point count. The input x and y
vectors follow as separate binary32 arrays. Constructor kinds 0 through 4 name
the five routines above in that order. Each output is a 32-bit point count,
followed by its complete x vector and complete y vector, both binary32.

The released circular constructor uses DOUBLE angles with x87 `FSINCOS`.
Its internal pi is rounded to 66 significant bits. At angles near pi, its sine
is observably different from a host library sine even after storing the final
coordinate as REAL. `conduit_boundary.cpp` reduces the angle using both parts
of that historical constant before the host sine/cosine call. The ellipse and
box constructors also store their square roots as REAL before multiplying,
while the ellipse analytic area and mirror slot intersection stay wide.
The committed fixtures compare every output bit, including near-zero coordinates.

`attach_utility_components.py` connects all five constructors and preserves the
original `RHMAK` zero-divide diagnostic. With this integration, the combined
conduit geometry differences in the supplied utility example are resolved;
the first remaining report difference is in culvert flow at line 1,731. This
is component and example evidence; complete application acceptance remains open.


## Energy-section and critical-flow lookup

`probe_energy_section_original.py` captures `XLKT22` and its `XLKTAL` wrapper
from either released program. All 840 controlled intervals agree across both
executables and with the independent C++ implementation. Each capture checks
that all ten wrapper outputs agree with the corresponding `XLKT22` outputs;
the latter also supplies the eleventh output, critical flow. Table types 12,
22, 25, 32 and 35 cover linear and cubic Hermite coefficient interpolation,
three depth scales, seven interval fractions and zero-depth lower rows.

```sh
FEQ/build/python312/bin/python FEQ/tools/probe_energy_section_original.py \
  --program fequtl --native FEQ/build/core/feq_energy_section_probe \
  --output FEQ/build/energy-section-recapture
FEQ/build/python312/bin/python FEQ/tools/probe_energy_section_original.py \
  --program feq --native FEQ/build/core/feq_energy_section_probe \
  --output FEQ/build/energy-section-feq-recapture
```

Each input contains the little-endian 32-bit table type, binary32 depth and
three rows of eleven binary32 values. Row order is depth, width, area,
square root of conveyance, beta, first moment, alpha, critical flow,
square-root-conveyance slope, beta slope and alpha slope. The driver places
the alpha derivative in the distinct type-32 and type-35 table columns.
Each output is eleven binary32 words in the original argument order:
A, T, DT, J, K, DK, B, DB, ALP, DALP, QC.

`section_energy.cpp` retains direct division where `XLKT20/21` use a reciprocal.
Its width and area stores retain wider registers, while first moment reloads
stored width. The three logarithm results, combined exponent and exponential
result each store REAL. Ratios supplied to the logarithms remain wide. A
zero-depth lower row selects the upper and following rows for critical flow
without changing the geometric interpolation interval. The integration retains
the original table selection, cached pointers, clamping and diagnostics.

## False-position variants and steady-flow energy residuals

`probe_root_original.py` calls the unmodified `REGFLT`, `RGF`, `RGF3`, or
`RGF5` routine selected by `--method`. Each has 434 cases with scripted wide
residuals, quadratic functions, mutable trial arguments, endpoint and tolerance
boundaries, and iteration-limit exits. Each record contains all five mutable
REAL fields, the flag, callback count, and 101 trial slots. There is no numeric
mask. Core and adapter comparisons independently require every captured byte.

The four routines share the false-position formula, but their state transitions
are not interchangeable. Only RGF3 accepts an initially small endpoint residual
without evaluating a trial. REGFLT and RGF test residual convergence before
interval collapse and damp repeated endpoint residuals by the stored REAL
constant 0.9. RGF3 and RGF5 test collapse first and damp by 0.5. RGF5 enforces a
REAL 1E-6 argument-tolerance floor and accepts equality at interval collapse.
RGF returns the most recent residual at collapse and iteration failure; REGFLT,
RGF3 and RGF5 choose the better endpoint at collapse and retain the previous
left residual at iteration failure. Callback results and their previous values
stay wide; bracket residuals and trial arguments store REAL.

`probe_root_search_original.py` independently captures REGFAL and FDROOT, with
894 cases per routine. Unlike the four routines above, REGFAL evaluates its own
endpoint residuals and keeps FL and FR wide through every update and damping
step. It copies both REAL endpoints before either callback, calls both before
testing either residual, and sends subsequent trials through the caller's
actual XM object. Its strict residual test means FM=0 with EPSF=0 needs another
trial before the endpoint-zero test terminates. The iteration limit permits
101 trial callbacks in addition to the two endpoint callbacks.

FDROOT calls the supplied A and B objects directly. An existing sign change or
small endpoint residual returns with the incoming flag untouched. Otherwise
the original caches A and B-A after both endpoint callbacks, tries
`XM = A + ((B-A)*i)/16` for i=-8 through 15, and skips nonpositive REAL trial
arguments. A discovered sign change writes the possibly callback-adjusted XM
to A and preserves the flag; exhausting the search sets it to one.

The 1,592-byte inputs contain tolerances, initial bracket and status, scripted
binary64 residuals or polynomial coefficients, and optional callback mutations.
Each 3,092-byte output contains final A/B/XM/status, callback count, and 128
trace slots. Each slot records the argument and external A/B/XM/status before
the callback's changes, plus whether the argument is external A, B or XM, the
first local argument object, or a different local object. This tests observable
aliasing without comparing process-specific addresses. Fixtures cover both
argument mutations and external state mutations. Both direct C++ and adapter
tests require every byte in both original traces. The oracle reads a regular
input file because redirected host pipes may return partial Windows reads.

```sh
FEQ/build/python312/bin/python FEQ/tools/probe_root_search_original.py \
  --method regfal --native FEQ/build/core/feq_root_search_probe \
  --output FEQ/build/regfal-recapture
FEQ/build/python312/bin/python FEQ/tools/probe_root_search_original.py \
  --method fdroot --native FEQ/build/core/feq_root_search_probe \
  --output FEQ/build/fdroot-recapture
```

`probe_steady_residual_original.py` calls original SBER and SPER with synthetic
section tables and populated COMMON values. Their original XLKTAL calls run
unchanged. The 840 cases cover five table types, three depth scales, endpoints,
barrel-height clamping, forward and reverse flow, signed bed slopes, and both
eddy-loss branches. Each output contains both binary64 return values and the
unchanged query depth. All 1,680 return values match bit for bit. The independent
C++ keeps the velocity, energy, eddy losses and normalized residual wide, as
shown by the original instruction streams, and retains the distinction between
the depth used for lookup and the depth used for energy.

These kernels are integrated into the utility research engine. They do not
complete whole-program equivalence: four supplied utility numerical outputs
still differ. The complete FEQ report and active-matrix checks remain separate
and are rerun on the integrated binaries.

`probe_steady_profile_original.py` captures 432 additional cases for SFPSBE's
specific-energy and normal-flow instruction sequences. Both copied sequences
retain their complete original bytes, including internal branches; the manifest
records each RVA interval and instruction hash. The wrapper only supplies the
original frame and COMMON values. The energy sequence receives the wide initial
ZDN-ZBR difference. The normal-flow sequence includes the positive-slope test,
the REAL square-root store, and the wide multiplication by conveyance.

The SFPSBE integration retains YR, ER, EL, QN, Froude ratios and temporary
differences as binary64. Initial YR has an FST REAL vector output at 0x426aa6,
but the unrounded register survives in an x87 spill and supplies the energy
calculation. The initial-depth error message separately stores a REAL copy at
0x426ae5. The energy and normal-flow expressions call the verified independent
helpers; table lookups, root callbacks, traversal, COMMON stores and diagnostics
retain their existing interfaces. The first supplied utility report difference
moves from line 1732 to line 1785, and the first culvert table difference moves
from line 10 to line 55. Those are progress measurements, not acceptance of the
remaining utility outputs.


## Approach-section energy balance

`probe_approach_residual_original.py` calls the unchanged RAPP routine and its
original XLKTAL lookup for 840 synthetic intervals. It covers five table types,
three depth scales, both interval endpoints, the contraction/expansion boundary,
and adjacent area ratios around the original REAL 0.95 threshold. Each 200-byte
input contains an energy-table fixture and fifteen hydraulic fields. Each
72-byte output contains the wide RAPP return, integer contraction flag, thirteen
stored section fields, and the wide RQVSTW head residual. All output bits match
the independent C++ implementation.

RAPP retains both velocity heads, friction, the interpolated discharge and
expansion coefficients, and the clamped expansion loss in wide registers.
At area ratio r > REAL(0.95), its transition factor is 20*(1-r), while the
limiting discharge coefficient is the original REAL(0.98) constant. The
contraction branch has a different entrance-loss placement. The explicit
formulas and operation order are documented in `src/approach_residual.cpp`.
The wrapper keeps the original REAL section stores and lookup interface.

RQVSTW's final subtraction at 0x42dd67..0x42dd73 has no REAL store. The probe
copies that complete instruction sequence unchanged and records its hash.
The integration returns the helper result directly; earlier failure returns
retain their existing sentinel values.

With these changes the first culvert-flow table in UTLEXM agrees with the
original. Its first report difference moves from line 1785 to line 1921 and
its first table difference from line 257 to line 545. The CULVERT table's
first difference moves from line 55 back to line 13, demonstrating that
independent rounding errors can cancel. Four utility outputs still differ;
these changes do not establish whole-program equivalence. Fresh complete
FEQ runs retain all twelve matching outputs and all 2,092 exact active matrices.


## Cross-section station fractions

`probe_station_fraction_original.py` captures 585 station fractions from the
released FEQUTL INTERP instruction blocks. The temporary PROGRAM driver copies
the complete input table, loops over its records, and writes each retained
fraction as binary64. The numerical blocks at 0x442e8d..0x442ea5,
0x443756..0x443773 and 0x4438a5..0x4438b7 are copied byte for byte; the manifest
records their hashes. Original runtime startup establishes the original
floating-point precision before the driver executes. The preserved executable
is hash-checked and never modified.

Each input has three binary32 values: left station, right station, and requested
station. Each output is one binary64 fraction. Cases cover both endpoints,
near-endpoint stations, negative coordinates, adjacent float coordinates and
five distance scales. All output bits match `section_station_fraction`.
The formula is `(station-left) * (1/(right-left))`, with wide subtraction and
reciprocal multiplication. Direct wide division differs in 116 fixture cases;
single-precision distances and fraction differ in 443. Neither is a valid
replacement for the observed arithmetic.

```sh
FEQ/build/python312/bin/python FEQ/tools/probe_station_fraction_original.py \
  --native FEQ/build/core/feq_section_probe --output FEQ/build/station-recapture
```

The integration applies the same station-fraction helper in FEQ and FEQUTL,
retains wide INTERP distances, and preserves the existing property stores.
The supplied UTLEXM table now agrees through line 1045; its first difference
moves from the interpolated top width at line 545 to the first moment in the
closed-section extension at line 1046. The report and culvert differences
remain at lines 1921, 711 and 13. All twelve FEQ outputs still agree with only
execution clocks excluded, and all 2,092 active FEQ matrices remain byte-exact.
The full comparison still passes 13 of 17 files; four FEQUTL outputs and the
final application release remain incomplete.


## Standard closed-section slot

`probe_slot_original.py` calls unchanged CUTTAB at RVA 0x93530 with 625 table
fixtures. Its temporary PROGRAM driver streams fixed-size records through
Win32 ReadFile and WriteFile and scatters the input columns to the original
PMXPNT=999 stride. The preserved executable is hash-checked and never edited.
Original runtime startup and the complete CUTTAB routine execute normally.

Each 424-byte record contains the row count, gravity and eight rows of thirteen
column-major float fields. The output has the same layout, including all rows
after the returned count. Every output bit matches the independent
`cut_section_slot` implementation. There are 354 modified slot rows and 271
unchanged tables. Fixtures exercise both unit systems, gravity immediately
around 15, width and relative-change thresholds, zero-width skip behavior,
odd/even loop positions, short tables and random field values.

CUTTAB detects a slot when `abs(Tnew-Told)/Tnew <= REAL(0.001)` and the width is
at most REAL(0.07) for gravity greater than 15, or REAL(0.02134) otherwise.
It extends the detected row to depth 500 or 150, copies conveyance, beta, alpha
and critical flow from the preceding row, and integrates area and first moment.
The original FST instructions at 0x493652, 0x493735 and 0x493830 store new area
as REAL without discarding the wide register used in the next integral.
Depth difference also remains wide. Zero-width rows leave the prior width
unchanged for the next detection test.

```sh
FEQ/build/python312/bin/python FEQ/tools/probe_slot_original.py \
  --native FEQ/build/core/feq_slot_probe --output FEQ/build/slot-recapture
```

The whole-program integration fixes the first-moment difference at UTLEXM table
line 1046. The table now agrees through line 1369, with the next difference in
velocity-distribution properties at line 1370. UTLEXM and CULVERT report
differences remain at lines 1921 and 711; the CULVERT table still differs at
line 13. The combined comparison remains 13 of 17 files, with all twelve FEQ
outputs and all 2,092 active matrices still exact apart from report clocks.
Four utility outputs and final application release work remain incomplete.


## Gauss-Legendre quadrature rules

`probe_gaussian_rule_original.py` calls the unchanged GRULE routine for every
order from 1 through 256, the full extent of its local work array. The temporary
PROGRAM driver loops over these calls in one process and writes the nodes and
weights as raw binary64 values. The preserved executable is hash-checked and
never modified; the original startup, GRULE and IMTQL2 instructions execute
normally. The FEQUTL cross-section quadrature bank uses at most 21 points, which
is covered within this larger supported domain.

Each input record is a four-byte unsigned order. Each output record has the
ordered nodes followed by the corresponding weights, both arrays of `order`
binary64 values. All 65,792 values match the independent C++ implementation.
The initial translated routine also matched every captured value, ruling out
the rule generator as the cause of the remaining sinuosity-table difference.

The C++ implementation forms the symmetric Legendre recurrence matrix with
zero diagonal and `i/sqrt(4*i*i-1)` off-diagonal. Implicit QL rotations carry
the first eigenvector components; weights are `2*v*v`. It preserves the
original 2.2e-16 deflation threshold, 30-iteration limit, SIGN treatment of
negative zero, selection-sort tie handling, and arithmetic order. Partial
results retain the original one-based unconverged index in the core API.
The GRULE adapter copies the nodes and weights through the original interface.

```sh
FEQ/build/python312/bin/python FEQ/tools/probe_gaussian_rule_original.py \
  --native FEQ/build/core/feq_gaussian_rule_probe --output FEQ/build/gaussian-recapture
```

The integration preserves the previous complete-report comparison: 13 of 17
files match, and all 2,092 active FEQ matrices remain byte-exact. The remaining
first differences are UTLEXM report line 1921, UTLEXM table line 1370, CULVERT
report line 711 and CULVERT table line 13. This component establishes quadrature
rule behavior; the separate linearly varying sinuosity integration and final
application release work remain incomplete.


## Linearly varying sinuosity integrals

`probe_sinuous_flux_original.py` streams 651 controlled cross sections into a
temporary PROGRAM driver. The driver calls unchanged GRULE and FBASEL after
original runtime startup. The preserved executable is hash-checked and never
modified. Cases cover OLDBETA, NEWBETA and NEWBETAX, rising/falling/horizontal
boundaries, vertical and overhanging segments, dry and clipped sections, three
coordinate scales, multiple subsections and roughness modes, seven quadrature
orders, and the supplied triangular-channel geometry.

Each 204-byte input contains water level, point/subsection counts, quadrature
order, flux model, Manning factor, gravity, four roughness modes and eight
padded boundary records. Each 112-byte output contains eight binary64 integral
sums followed by four-element REAL arrays for SBSN, QS and KS. All output bits
match both the independent core and its C++ engine adapter. The core receives
subsection roughness after the existing geometry and depth-dependent lookup.

Original clipped offsets and endpoint sinuosity stay wide. YL is stored as
REAL while YR remains wide; the midpoint, half-width and local velocity have
explicit REAL stores. The area-weighted sinuosity integral multiplies by the
original REAL reciprocal of three at 0x496f8d. QS and KS round after every
sample. NEWBETAX preserves the REAL gravity square-root store and the released
DALOC expression's use of C2 in both derivative terms. Constant derivative
factors are applied only after all segments have been integrated.

The core carries the original negative-depth diagnostic values in
`SinuosityDepthError`. The adapter catches that state, stores the original REAL
diagnostic copies, and runs an unchanged copy of the existing FBASEL diagnostic
and STOP block. The 651 raw fixtures cover normal returns; they do not exercise
that fatal diagnostic.

```sh
FEQ/build/python312/bin/python FEQ/tools/probe_sinuous_flux_original.py \
  --native FEQ/build/core/feq_sinuosity_probe --output FEQ/build/sinuosity-recapture
```

The whole-program integration fixes the UTLEXM table difference at line 1370.
The table now agrees through line 1627, and the next difference is the first
FDROP value in a UFGATE table at line 1628. Report differences remain at
UTLEXM line 1921 and CULVERT line 711; the CULVERT table still differs at line
13. All twelve FEQ outputs match with only report clocks excluded, and all
2,092 active matrices remain byte-exact. The full comparison remains 13 of
17 files. Four utility outputs and final application release work remain
incomplete.

## Underflow-gate momentum and tailwater levels

`probe_gate_residual_original.py` streams 840 cross-section intervals into a
temporary original PROGRAM driver. For each interval it restores the original
gate COMMON block and calls each unchanged RSOMY3, RSWMY3, RSOMY4 and RSWMY4.
The 3,360 calls retain their original LKTJ or XLKT22 lookups. All binary64
returns and all forty REAL COMMON values match the independent C++ component.
The section fixtures span five table types, three depth scales, zero/nonzero
lower depths, and seven positions per interval. The residual cases vary
gravity, gate geometry, contraction/discharge coefficients and both section
properties. No report masking or numerical tolerance is used.

The jet residuals explicitly store QSQR as REAL before the momentum equation.
Their intermediate area ratios and the final normalized momentum residual
remain wide. These fixtures also distinguish LKTJ from the other first-moment
lookups: LKTJ retains width and area throughout and multiplies by the REAL
sixth `0x3e2aaaab`. The independent `interpolate_scalar_first_moment` preserves
that ordering; the engine retains original interval selection, bounds
diagnostics and its cached row pointer.

`probe_gate_levels_original.py` captures two unchanged UFGATE instruction
sequences, at RVAs `0x819a9..0x819d3` and `0x81b76..0x81bab`. The first keeps
the tailwater elevation while computing free-flow head and drop. The second
multiplies the retained free drop by its fraction, keeps the resulting
tailwater elevation, stores the trial section-4 depth as REAL, and retains
the head and drop. All five outputs match for 678 cases, including drops
above positive and negative large datums and zero/full-drop endpoints.
The engine uses explicit REAL report copies for the retained quantities.

```sh
FEQ/build/python312/bin/python FEQ/tools/probe_gate_residual_original.py \
  --native FEQ/build/core/feq_energy_section_probe --output FEQ/build/gate-residual-recapture
FEQ/build/python312/bin/python FEQ/tools/probe_gate_levels_original.py \
  --native FEQ/build/core/feq_energy_section_probe --output FEQ/build/gate-levels-recapture
```

The integrated UFGATE free-drop row now matches. The next UTLEXM table
difference is line 1630, where a submerged-flow entry is `7934-2` in the
original and `7935-2` in C++. Other first differences remain at UTLEXM report
line 1921, CULVERT report line 711 and CULVERT table line 13. The full
comparison remains 13 of 17 files; four utility outputs and final application
release work remain incomplete.


## Gate critical setup, free-weir flow and inverse energy

`probe_gate_free_original.py` captures the unchanged UFGATE instruction blocks
at RVAs `0x80b47..0x80bbd` and `0x816af..0x81762`. The first stores the gate
area, critical speed, discharge, specific-energy target and initial upstream
depth. The second executes the original fixed-point loop, with its head and
intermediate depths retained until convergence. The square root then crosses
a separate REAL store before multiplication into discharge. All 894 fixtures
match all seven output floats. Cases cover three dimensional scales, both
gravity conventions, cancellation above large datums, retained heads between
adjacent floats, convergence tolerances and zero head.

`probe_specific_energy_original.py` calls the complete unchanged FISE routine
six times for each of 840 section fixtures, selecting each TYPE from 20 to 25.
The actual section tables independently exercise types 12, 22, 25, 32 and 35.
The original XLKT20/XLKT22 lookup and NOALP selector execute normally. All
5,040 binary64 residuals and all 840 unchanged query depths match. FISE copies
the query into YLOC for lookup and returns the residual without a REAL store;
the C++ integration preserves both behaviors. The residual formula and exact
operation order are documented beside `specific_energy_residual`.

Both probes stream input through a regular file, hash-check the preserved
original executable, and write complete input/output provenance. The CMake
gate fixture checks verify the recorded hashes before comparing every byte.
The utility integration uses the verified routines after preserving the
original table selection and diagnostic paths. The full examples still have
four numerically different utility outputs; these isolated matches do not
establish whole-program equivalence.

```sh
FEQ/build/python312/bin/python FEQ/tools/probe_gate_free_original.py \
  --native FEQ/build/core/feq_energy_section_probe --output FEQ/build/gate-free-recapture
FEQ/build/python312/bin/python FEQ/tools/probe_specific_energy_original.py \
  --native FEQ/build/core/feq_energy_section_probe --output FEQ/build/specific-energy-recapture
```

## Upstream gate transition and free-orifice flow

The original FNDFOQ entry trace exposed an upstream transition-head difference
despite matching INVTSE inputs and section properties. UFGATE's instructions
at `0x480bf8..0x480c10` add depth to the upstream bottom, subtract the datum,
and only then store H1FWUL as REAL. The translated Z1FWUL assignment had
introduced an earlier REAL store, losing small depths above a large datum.
`gate_upstream_head` preserves the original operation order and final store.

`gate_free_orifice` implements FNDFOQ's arithmetic after its original XLKT22
lookup. The effective area is `REAL(CD*CC*AG)`. The contracted surface and the
approach-velocity denominator remain wide. The square-root velocity is stored
as REAL before multiplication by effective area and the final discharge store.
The formula and instruction addresses are documented beside the implementation.
The complete original FNDFOQ disassembly is preserved in
`assembly/fequtl/_fndfoq_.asm`.

`probe_gate_orifice_original.py` captures the unchanged upstream-head block
and FNDFOQ block at RVAs `0x80bf8..0x80c10` and `0x7ee92..0x7eef4`. It records
1,278 cases covering three scales, gravity conventions, cancellation above
six datums, zero flow, small positive heads and approach-velocity denominators
close to zero. All three output floats match in every case: 15,336 bytes
without tolerance. Both instruction blocks and all fixture bytes are hashed.

The fresh complete example run passes 14 of 17 outputs. UTLEXM's entire
function table now agrees with only the execution timestamp masked; its
cross-section output remains byte-identical. All twelve FEQ outputs still
match with only clocks masked, and all 2,092 active solver matrices match
every word. The remaining first numerical differences are UTLEXM report
line 1921 (`2.7975` versus `2.7976`), CULVERT report line 711 (`2.79815`
versus `2.79818`) and CULVERT table line 13 (`1138-2` versus `1137-2`).
The executable and comparison hashes are in `cpp-research-status.json`.

```sh
FEQ/build/python312/bin/python FEQ/tools/probe_gate_orifice_original.py \
  --native FEQ/build/core/feq_energy_section_probe --output FEQ/build/gate-orifice-recapture
```

## Power-function breakpoint spacing

`probe_power_spacing_original.py` captures LSTOPF's complete arithmetic block
at RVA `0x7f002..0x7f174`, after the argument-ratio table lookup. The driver
provides the ratio, retained interval bounds and original stack arguments,
then executes the unchanged instruction bytes. All 1,531 cases match the
point count, error flag and every byte of the 512-float output buffer.
There are 736 successful sequences containing 9,803 points, and 795 capacity
failures that preserve the entire input buffer while returning `N=-1` and
setting `EFLAG=1`. Successful calls preserve the incoming error flag.

The interval ratio and both logarithms have REAL stores. The logarithm
quotient remains wide until conversion of `LB/LR+1` to the interval count.
The spacing factor is `REAL(exp(LB/IPOW))`, using the stored logarithm and
retained division. Each pair of points begins from a previously stored point;
the first multiplication is stored but also retained for the second one.
This detail is visible at `0x47f0e4` (FST) and `0x47f0e8` (FMULP). Reloading
the stored first product changes 236 successful fixture sequences. Removing
the logarithm store changes the spacing factor in 79 successful cases.

The original lookup, table choice and invalid-range diagnostic remain in the
research integration. The bounds are captured before that lookup, as in the
released routine. The C++ API documents its valid input domain, preserves the
capacity failure behavior and performs the final offset subtraction only
after every point has been stored. Formula comments and the complete LSTOPF
disassembly accompany the implementation. These arithmetic fixtures do not
claim to verify the preceding two-dimensional ratio lookup.

In the supplied UTLEXM report this removes 90 differing gate lines, reducing
the complete report's differing line count from 184 to 94. The UTLEXM table
continues to match after masking its timestamp. The complete run still passes
14 of 17 files; the first remaining report differences are unchanged in the
culvert calculations. Fresh FEQ traces retain all 2,092 exact active matrices.

```sh
FEQ/build/python312/bin/python FEQ/tools/probe_power_spacing_original.py \
  --native FEQ/build/core/feq_energy_section_probe --output FEQ/build/power-spacing-recapture
```

## Gate contact, midpoint and free-orifice states

`probe_gate_state_original.py` captures six unchanged UFGATE instruction
blocks, covering lip-contact squared flow, the free-orifice state, the
transition midpoint, its contact flow and root bound, and normalized
tailwater depth. All eight output floats match in each of 1,280 cases:
40,960 bytes without tolerance. Inputs cover three scales, six large and
small datums, zero contact head, approach-velocity corrections near their
singular limit and two states from the supplied original gate traces.
The instruction ranges and hashes are recorded in the fixture manifest.

Lip-contact flow retains `E=AG*CD` through both the numerator and the
approach-area ratio before storing squared flow. Its transition midpoint
retains `0.5*(HG+H1FWUL)` through the section-depth calculation and root
bound; normalized tailwater similarly divides the retained head by HG.
The integration replaces both contact-flow expressions and preserves the
original section lookups and all four residual solvers.

The UFGATE free-orifice block stores `AT=REAL(CD*CC*AG)` and
`Y2=REAL(HG*CC)` before computing the available head. It also stores the
square-root velocity before multiplication by AT. Its contracted-depth
store is distinct from FNDFOQ, which retains that product in its head
calculation. Separate C++ functions preserve both released sequences.
The fixtures execute the arithmetic around supplied section properties;
the intervening section lookup is covered separately by the section fixtures
and complete-example comparisons.

The complete original gate trajectory was then recaptured with a 100,000-call
limit for each residual, exceeding every actual count. All 12,866 RSOMY3,
823 RSOMY4, 5,444 RSWMY3 and 568 RSWMY4 entry records match the integrated
C++ engine. Each 172-byte record contains the two table addresses, forty
COMMON REAL values and the trial argument. This establishes identical
residual inputs throughout the supplied gate computation, with no tolerance
or skipped fields. Capture, binary and input hashes are preserved in
`gate-residual-trajectories.json`.

`tools/instrument_gate_entries.py` reproduces the diagnostic candidate from
an integrated source directory. Its generated sources and headers were
compared byte for byte with the compiled tracing candidate. Compile and link
that disposable output with the regular research tools, then run UTLEXM;
the four `gate-00.bin` through `gate-03.bin` files use the original record
layout. The original hook configuration is embedded in the trajectory receipt.

The gate report is left with twenty list-directed formatting differences;
its hydraulic rows match. Across the complete examples, 14 of 17 files still
match with only execution clocks masked. The numerical culvert differences
remain, and all 2,092 FEQ solver matrices still match every word.

```sh
FEQ/build/python312/bin/python FEQ/tools/probe_gate_state_original.py \
  --native FEQ/build/core/feq_energy_section_probe --output FEQ/build/gate-state-recapture
```

## List-directed REAL output

`probe_list_real_original.py` captures 6,488 complete records through the
released `_jwe_ilst` and `_jwe_ilor` runtime. It repeats MAIN's original
`_jwe_xcop(0x707013,0,0,0)` compiler-options call before writing. This is
essential: omitting those options changes item separators, exponent case
and zero formatting. The driver executes a bounded loop over literal input
bits; the decimal conversion and I/O runtime remain unchanged.

The cases cover console unit 6 and a sequential report file on unit 10,
with both scalar and label/scalar descriptors. Console records omit the
report file's initial carriage-control blank; numeric item separators use
one blank. Both untouched streams are retained, and their records are merged
in input order without rewriting any byte. All 199,836 resulting bytes match
the independent C++ fixture writer. Coverage includes both signs, zeros,
subnormals, all finite exponent fields, infinities, quiet/signaling NaNs,
decimal decades and adjacent floats, halfway cases and actual gate outputs.

`feq::list_real` preserves nine significant digits and trailing zeros. The
released runtime uses fixed notation for magnitudes from 0.1 through values
below 10^9, and a one-leading-digit exponential field elsewhere. The existing
verified digit converter supplies the original rounding, including
`82432.40625` rendered as `82432.4063`. Both signed zeros render as
`0.00000000E+00`. The C++ field function is independent of the C locale and
leaves record margins and item separators to the caller.

The research runtime now dispatches scalar REAL list output to that function.
All twenty remaining UFGATE formatting differences are resolved, and the
complete UFGATE report section matches every byte. A fresh instrumented run
also retains all 19,701 identical gate residual-entry records. The complete
examples still pass 14 of 17 files; UTLEXM has 68 differing non-clock lines
in its earlier culvert and expansion/contraction calculations. The first
remaining differences are unchanged. All 2,092 FEQ active matrices remain
identical, and all 51 CMake checks pass in Release and sanitizer builds.

These scalar field tests do not assert complete list-runtime equivalence
for complex values, other numeric types, long-record wrapping or input.

```sh
FEQ/build/python312/bin/python FEQ/tools/probe_list_real_original.py \
  --native FEQ/build/core/feq_decimal_probe --output FEQ/build/list-real-recapture
```

## Full-barrel flow

`probe_full_barrel_original.py` calls the entire unchanged `FULBAR` routine in
the released FEQUTL executable. Only MAIN is replaced by the input/output
driver. All 3,072 cases match both output REAL words: barrel discharge and
entrance piezometric elevation. The fixtures vary geometry over three scales,
approach and barrel friction, six discharge coefficients including unity,
zero and positive road flow, and seven relative convergence tolerances.

`full_barrel.cpp` records the source equations and the executable's rounding
boundaries. FULBAR stores the energy divisor at `0x4259ef`; the initial and
iterated square-root velocities store at `0x425a02` and `0x425a9f`.
The numerator and the candidate flow product remain wide. On convergence,
the released routine returns the previous stored Q, because assignment of
the candidate occurs only on the repeat branch. The contraction calculation
likewise rounds the square root at `0x425afe`, while retaining its reciprocal
and subsequent velocity calculations. The original never increments its
declared iteration counter; the port preserves the released loop behavior.

Integration fixes one line of the supplied culvert report. The earliest
remaining differences are unchanged: UTLEXM line 1921 and CULVERT line 711.
There are 68 and 176 differing non-clock report lines respectively. All
twelve FEQ outputs, the UTLEXM function table and cross-section file remain
exact after masking only execution clocks. Fresh tracing preserves every
word in all 2,092 FEQ matrices and all 19,701 gate residual entries, plus
the entire 276,813-byte UFGATE report section. All 52 CMake checks pass in
Release and sanitizer builds. This component does not complete the three
remaining FEQUTL output comparisons or the application release.

```sh
FEQ/build/python312/bin/python FEQ/tools/probe_full_barrel_original.py \
  --native FEQ/build/core/feq_energy_section_probe --output FEQ/build/full-barrel-recapture
```

## Type-2 head loss and normal-flow residual

`probe_type2_head_loss_original.py` executes the unchanged RTY2 arithmetic at
`0x42e25c..0x42e293`. All 3,073 results match every output bit. The fixtures
cover three flow/area scales, signed flow, eight discharge coefficients and
three gravity values, plus the first RTY2 call in the supplied culvert example.
The equation is `DH = (1/CD^2-1)*(Q3/A3)^2/(2g)`. The velocity ratio remains
wide through squaring; DH is the only REAL store. The research adapter now
uses the independently verified `culvert_head_loss` implementation here as
well as in RQVSTW.

`probe_normal_flow_original.py` executes the unchanged NDRSD arithmetic at
`0x428627..0x42863c`, after section lookup. All 3,072 returned binary64 values
match exactly, including cases close to the normal-flow root, three scales,
signed flow and zero slope. The equation is `(RTSBOT*K-FLOW)/FLOW`; all three
inputs are stored REAL values, but the residual has no REAL store before
return. The adapter preserves the private depth copy passed to LKTK, whose
range handling can change its argument. These arithmetic fixtures do not
independently validate LKTK's table lookup or the whole FNDND search.

All 54 CMake checks pass in Release and sanitizer builds. Fresh full-model
runs preserve the existing 14 of 17 report comparisons, all 2,092 active FEQ
matrices and all 19,701 gate residual entries. The complete 276,813-byte gate
report section remains exact. UTLEXM and CULVERT retain 68 and 176 differing
non-clock report lines, and seven culvert-table lines still differ.

```sh
FEQ/build/python312/bin/python FEQ/tools/probe_type2_head_loss_original.py \
  --native FEQ/build/core/feq_culvert_loss_probe --output FEQ/build/type2-loss-recapture
FEQ/build/python312/bin/python FEQ/tools/probe_normal_flow_original.py \
  --native FEQ/build/core/feq_energy_section_probe --output FEQ/build/normal-flow-recapture
```

## Scalar conveyance lookup

`probe_scalar_conveyance_original.py` calls the complete unchanged LKTK routine
in FEQUTL 5.80 with controlled two-row tables. The released FEQ solver does not
include this utility helper. All 2,688 outputs match exactly across fourteen
accepted table types, three scales, both interval endpoints and six interior
fractions, zero endpoints and increasing or decreasing conveyance. Each type
uses its original OFFCOM row stride, ranging from five to fifteen words.

The equation is
`K(y) = [sqrt(K0)+(y-y0)*(sqrt(K1)-sqrt(K0))/(y1-y0)]^2`.
LKTK retains the depth interval, derivative and interpolated square root in
wide registers at `0x477a9b..0x477ace`, then stores only the final squared value
as REAL at `0x477ad0`. It uses division for the slope. This differs from the
multi-property section lookup, which stores its interpolated square root
before squaring. The adapter replaces only interval arithmetic; the existing
search, range diagnostics and cached-row update remain in place. These
fixtures stay within a selected interval and do not cover range diagnostics.

This correction fixes eight differing culvert report lines and one table line.
The earliest culvert-report difference moves from line 711 to line 804; 168
non-clock report lines and six table lines still differ. UTLEXM retains its
68 differing report lines. All 55 CMake checks pass in Release and sanitizer
builds. Fresh regression captures preserve all 2,092 active FEQ matrices,
all 19,701 gate residual entries and the complete 276,813-byte gate report
section. Fourteen of seventeen combined outputs pass; three FEQUTL outputs
and the application release remain unfinished.

```sh
FEQ/build/python312/bin/python FEQ/tools/probe_scalar_conveyance_original.py \
  --native FEQ/build/core/feq_section_probe --output FEQ/build/scalar-conveyance-recapture
```
