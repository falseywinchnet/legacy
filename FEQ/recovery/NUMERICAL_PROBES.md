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
