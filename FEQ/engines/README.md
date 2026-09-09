# Complete native engine source

`feq/` contains the FEQ 10.61 engine; `fequtl/` contains FEQUTL 5.80. Both
compile as strict C++20 and call the independently verified library in `src/`.
There is no run-time translation or emulation. The source lists in `cmake/` are
explicit, and every build starts from these checked-in files.

The historical implementation retains its source-line annotations, equations,
comments and notices. Its initial promotion was a byte-for-byte copy of the
accepted research candidate, with each source, header, object and executable
checked against its link receipt. `provenance/initial-source-manifest.json`
records that initial snapshot; subsequent source changes are tracked in Git.
The original `LINSYS` implementation is omitted from FEQ's build because the
independently verified profile-matrix solver supplies those operations.

Thirty-one automatic work arrays of at least 64 KiB use scoped vectors. This
includes FEQ's 744,000-integer input workspace, which would exceed the default
Windows thread stack by itself. Their original types, element counts and
indexing are unchanged. The arrays are value-initialized and freed when the
routine returns; `provenance/heap-workspaces.json` records every conversion.

`runtime/` is the required subset of the Netlib record I/O and intrinsic
support library, compiled as C++20. It preserves Netlib's
[license and warranty notice](runtime/NOTICE.txt). This code is linked into each
executable, so users do not install a separate runtime. The compatibility
changes that preceded promotion are recorded in
`provenance/runtime-compatibility.json`. Application integration additionally:

- Gives C++ declarations consistent linkage and removes obsolete `register`
  specifiers. The private character-class header is renamed to avoid shadowing
  the operating system's `ctype.h`.
- Transfers scalar record data with explicit `memcpy` operations. A four-byte
  caller is never accessed as an eight-byte union, and byte-aligned buffers do
  not require a typed pointer cast. Integer, real, double and logical widths
  remain explicit.
- Copies internal record settings into an actual external-error descriptor,
  preserving their meanings without aliasing incompatible structures.
- Supplies owned, NUL-terminated copies of all 29 dynamic Fortran format
  assignments. Their original character extents are recorded in
  `provenance/bounded-formats.json`.
- Checks filename buffer lengths, normalizes Windows separators, and resolves
  an existing filename's unique ASCII case match on a case-sensitive host.
  Ambiguous names produce an explicit error.

`support/platform.cpp` provides native clock, command-line, character,
directory and input-fingerprint services. Only the specific historical
directory operations are implemented; input decks cannot inject shell commands.
Independent runs use separate processes because the historical solver and I/O
state are not reentrant.

The `complete_engine_examples` CTest test creates a fresh working directory,
runs all six supplied models and compares every byte of all 17 expected
reports, allowing only the explicitly identified execution clocks. It rejects
sanitizer diagnostics even when the sanitizer allows execution to continue.
`runtime_io_storage` checks one-, two-, four- and eight-byte unaligned values,
bounded dynamic formats, logical widths, and formatted/list-directed round trips.
These run alongside the original-executable numerical fixtures.

The MIT license covers new work by Astra, sponsored by Rainstar and founded
on Hashem. It does not relicense the historical implementation or Netlib code;
see the collection's [notice](../NOTICE.md) for the preserved historical terms.
