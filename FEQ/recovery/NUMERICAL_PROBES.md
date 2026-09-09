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
