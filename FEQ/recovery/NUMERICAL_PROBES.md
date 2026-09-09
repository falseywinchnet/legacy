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
the syntax tree, connects the two lookup routines to the independent interval
implementation, and optionally restores the traced `SETINX` distance rounding.
It records each change and all source hashes. The standalone profile adapter
connects the independently tested solver to the research COMMON layout.
`matrix_trace.cpp` is an optional development adapter, controlled by explicit
trace environment variables; it is not an end-user interface.

The current first FEQEX1 matrix matches every COMMON byte. The next seven have
14, 19, 17, 22, 29, 26, and 36 differing words. The strict whole-output comparison
still passes 5 of 17 files. Those remaining differences are active work.
