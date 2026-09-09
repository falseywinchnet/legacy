# Recovery and reference findings

## Exact release identity

The [USGS download page](https://water.usgs.gov/software/feq/) distributes
`feq1061.zip` as FEQ 10.61 and FEQUTL 5.80. The recovered archive is 7,653,586
bytes with SHA-256
`ec74c6fed7e8db17b2308936f5b53bf525bf7f85773faed082c4d0722944c8ab`.
It expands to 985 files. Archive members are preserved byte for byte, including
the embedded `.svn` directories. [`manifest.json`](manifest.json) records download
locations and hashes; [`archives/`](archives/) records every extracted member.

The source version routines specify FEQ **10.61, 15 October 2008**, and FEQUTL
**5.80, 6 October 2008**. The distribution instructions are dated 31 March 2009.
The supplied FEQ and FEQUTL executables are **PE32 Windows console programs** for
Intel x86, despite the download page's “DOS” terminology. Their PE imports are
Windows system libraries; a DOS-only emulator is not sufficient. The compiler
identity recorded by the supplied programs is Lahey/Fujitsu Fortran 95 5.70f.

The shipped FEQ executable reports **Solution precision: Single**. This is
verified in its captured output, not inferred from a build script. The archive
also contains a double-solver variant in `FEQ/double/`; selecting that variant
would change the target behavior. Both versions mix single- and double-precision
variables elsewhere. FEQUTL also uses the single-precision build identity.
The distribution README states that HEC-DSS support is not compiled into FEQ,
although the archived single-solver build script selects DSS library routines.
The release therefore cannot be reproduced by blindly running either archived
script. [`tools/stage_source.py`](../tools/stage_source.py) defaults to the
shipped single-solver identity with HEC-DSS dummy routines and records every
selected file. Its optional double-solver selection is a separate research
configuration. Neither configuration modifies the preserved source.

## Original-executable verification

All six cases in the supplied `TEST/test.bat` were run using Wine 11.4 on macOS:

| Case | Program | Supplied example | Files checked |
| --- | --- | --- | --- |
| FEQEX1 | FEQ | Single branch | Report, `.spi`, `.wsq` |
| FEQEX2 | FEQ | Three branches | Report, `.spi`, `.wsq` |
| FEQEX3 | FEQ | Branch network with level-pool reservoir | Report, `.spi`, `.wsq` |
| FEQEX4 | FEQ | Offline reservoir | Report, `.spi`, `.wsq` |
| UTLEXM | FEQUTL | Hydraulic table examples | Report, `.tab`, `.chx` |
| CULVERT | FEQUTL | Culvert tables | Report, `.tab` |

The 17-file comparison passes against the original distribution's `DATA/`
outputs. All four `.wsq` files and `utlexm.chx` match raw bytes. The other twelve
files match after narrowly masking `Date/time of run` values and the explicitly
labeled initialization/computation elapsed-clock values. The comparison retains
line endings, all other whitespace, all numerical results, diagnostic text,
version metadata, and convergence history. Its complete results and both raw
file hashes are in [`reference-1061-comparison.json`](reference-1061-comparison.json).

These are original-versus-original checks, not C++ acceptance results. They
establish that the recovered binaries execute correctly in the reference
environment and reproduce the publisher's captured examples.

## Earlier source and embedded snapshot

The original runtime startup has also been measured directly. A disposable copy
of each executable runs its original initialization and captures the x87 control
word at PROGRAM entry. Both produce `0x027f`: 53-bit significand precision and
round-to-nearest, with solver precision code 1 (Single). The exact eight-byte
records and original executable hashes are in [`startup-state.json`](startup-state.json).
`tools/probe_startup.py` reproduces this measurement. This establishes startup
state; individual expression rounding and runtime mathematical routines still
require their own comparisons.

The official project site still supplies the earlier **FEQ 9.98 / FEQUTL 5.46**
archive. [`source-analysis.json`](source-analysis.json) compares Fortran source,
includes, parameters, and build-identity files outside compiler staging and SVN
metadata. It records 123 identical files, 116 changed files, 51 additions, and
10 removals. The analysis normalizes only line endings for textual comparisons.
Every changed file has a complete unified diff in [`diffs/`](diffs/).

The current archive also contains SVN pristine copies. Only one selected source
file has a content difference from its pristine copy after normalizing line
endings: `FEQUTL/xsection.for`, around line 4326. The distributed copy comments
out `nvar = 0`. Its added comment dates the edit to **23 March 2009** and calls it
a bug fix documented for **version 5.93**. Thus the distributed 5.80 source
contains a specific later fix without changing the reported version number.
[`diffs/svn__fequtl__xsection.for.diff`](diffs/svn__fequtl__xsection.for.diff)
preserves the exact difference. Whether an individual input exercises this
distinction must be tested explicitly.

The archived release histories cover many earlier changes; a surviving history
entry is not evidence that an earlier binary or complete source release has
been recovered. Failed downloads remain recorded in `fetch-failures.json`.

## Documented release-specific behavior

The [USGS release notices](https://cm.water.usgs.gov/proj/feq/bug_notice3.html)
identify two significant issues:

- In FEQ 10.61, a side-weir instruction (`code=14`) with an optional time-series
  discharge factor incorrectly uses a constant factor of 1. USGS states that
  this was introduced in 10.0 and corrected in 10.72, neither of those other
  versions being distributed on that page.
- USGS advises setting `NUMGT=0` for final output after nonzero use of the
  secondary convergence criterion produced invalid results in three models.
  `EPSFAC` values at or below 1 are replaced by 2 in the original behavior.

These notices are preserved in `originals/web/bug-notice-2009.html`. Compatibility
work must keep the requested release's behavior distinct from documented later
corrections and from advice on model configuration.

## Publications and companion programs

The recovered publications include FEQ WRI 96-4240, FEQUTL WRI 97-4037, alternate
PDF/PostScript distributions, FEMA review guidance, historical release notices,
and FEQinput and FEQ-GDI user documentation. FEQinput's Windows installer and the
FEQ-GDI distribution are preserved as separate companion software. Recovery of a
companion installer does not imply that its source has been recovered or ported.

## Independent profile solver and complete research engines

The independent C++ profile solver in `src/profile_matrix.cpp` reproduces the
original `PROFAC` and `PROSLV` routines bit for bit across 62 controlled fixtures.
`tools/probe_profile_original.py` replaces only PROGRAM entry in a disposable
copy of FEQ. The original runtime initializes normally, then the driver calls
the original factorization and solution addresses with explicitly populated
COMMON arrays. It captures every resulting coefficient and solution word.
The original executable hash is checked before any temporary copy is patched.

The fixtures comprise 24 dense systems (orders 1, 2, 3, 5, 8, 12, 20, and 24,
at scales 0.0001, 1, and 10000), 24 specialized branch-block factorizations,
eight 44-equation mixed-block matrices captured during the original FEQEX1 run,
and six 74-equation matrices around FEQEX4's control-flow transition.
The native comparison also passed AddressSanitizer and UndefinedBehaviorSanitizer.
The committed fixtures are under `tests/reference/profile_matrix/` and
`tests/reference/profile_models/`; the original
instruction listings are in `recovery/assembly/feq/`.

This comparison resolves two precision details that a source-level translation
misses. Dot-product sums remain in 53-bit x87 registers across loop iterations.
Three branch-block stores use `FST`, which writes a rounded four-byte value but
retains the wider register value for the next operation. The C++ implementation
expresses those retained values as named doubles and casts only at the observed
stores. Equations, source locations, and instruction addresses accompany the code.

The original diagnostic `SAVEMAT` has a separate type mismatch. Its caller uses
the shipped single-precision matrix arrays, while `ntmatrix.for:636-647` declares
eight-byte elements. The original `_savemat_` at RVA `0x75c00` actually copies
eight bytes per element. The research adapter preserves those copies within the
complete COMMON objects and reports an error if a copy would overrun them. This
is a diagnostic-path defect in the recovered release, not a reason to reinterpret
the shipped solver as double precision.

Complete research translations compile as 55 FEQ and 59 FEQUTL translation
units, including their unified COMMON definitions and dynamic-array adapters.
All 27 callback parameters use four concrete function-pointer signatures,
derived from 91 recorded call constraints or inspected unused routine bodies.
All six supplied cases execute. The current whole-file acceptance result is
**13 of 17 files matching**; all twelve FEQ files pass, and four FEQUTL numerical outputs remain unresolved.
The full results are in `cpp-research-status.json`. Passing a direct routine test
does not establish equivalence of an entire hydraulic model.

## Section interpolation and first-divergence tracing

`src/section_interpolation.cpp` independently implements the linear top-width
integral and the linear or cubic Hermite interpolation of square-root
conveyance and momentum factor. It matches all seven binary32 outputs in 240
cases against both released lookup entry points (`XLKT20`, RVA `0x3a7f0`, and
`XXLKT20`, RVA `0xbf70`). The two original routines agree across all 480 calls.
Inputs and golden outputs are committed under `tests/reference/section_interpolation/`.

Both original routines write rounded top-width and width-derivative outputs
with `FST` while retaining the wider values for integration. Re-reading the
rounded top-width output in the area expression changes an initial-state area
in FEQEX1. The independent implementation explicitly retains those doubles.
By contrast, the square-root conveyance and its derivative are reloaded from
binary32 storage before squaring and applying the chain rule. Both rounding
patterns are recorded beside the equations.

Full-model tracing preserves flags, general registers, and the complete x87
state. Every trace run also checks that its model outputs still reproduce the
published original outputs. At the first `PROFAC` call, the earlier research
engine had 36 different coefficient words and 23 different residual words.
The current first matrix matches the complete 3,790,428-byte COMMON block.

The last rounding step needed for that first matrix was `DXDT`. The original
forms `1/DT` in double precision, multiplies by `DX`, and stores the result as
binary32 before computing `DXHDT`. Its subsequent local intermediates can again
remain wider. Blanket promotion of all local variables therefore cannot be
used as a correctness rule. Original addresses `0x40c5fd` and `0x40c680`, and
the recorded stack trace, support the explicit conversion in the research
adapter.

Subsequent tracing identified retained old/new impulse sums, original SIGN
semantics at signed zero, single-precision square-root call boundaries, and a
wider boundary-flow report temporary. With these corrections, every active
solver word matches in all 621 FEQEX1 matrices. Its main report matches except
execution clocks. The earlier candidate had three history rounding differences,
including 98.25 printed as 98.3 by the released runtime and 98.2 by printf.
Direct original `VAR_DECIMAL` probes also produce 0.12 for 0.125 in an F5.2
field, so a blanket change to half-away rounding is not justified.

## First moments, scalar tables, and steady initialization

The independent section implementation now includes `XLKT21`'s first moment,
verified in 240 additional cases with eight binary32 output words. The original
retains a wider area intermediate but reloads rounded top width in the first
moment correction. Its coefficient is the actual single-precision 0.1666667
constant, rather than exact one sixth. These distinctions are explicit beside
the formula. Section interpolation during `INTERP` also retains double-precision
interval distance, depth difference, and reciprocal multiplication. Together,
these changes reproduce all 325 FEQEX2 matrices and all three output files.

`src/table_interpolation.cpp` implements type-2 linear functions, type-3
integrated linear derivatives, and type-4 cubic Hermite functions. All 360 cases
match both original `LKTAB` output words exactly. In type 3, the original writes
the interpolated derivative as binary32 but retains the wider register for the
function integral. Reloading the rounded area in the reservoir example changed
storage by whole cubic feet. Preserving that register value reproduces every
word in all 578 FEQEX3 matrices and all three output files.

FEQEX4 additionally requires wider steady-initialization locals in `SFPSBM`,
including the compiler-generated temporary used when squaring conveyance and
velocity. Formatted output and `NINT` still receive explicitly rounded float
copies; passing the wide object at those interfaces would change the call ABI.
Initial tracing matched the first 40 FEQEX4 matrices. The first difference was
in the bidirectional-control residual. `BDFTAB` retains water-surface elevation
sums before storing its heads, and retains discharge through the final residual
subtraction. `SETEXT`'s code-13 energy junction also retains velocity quotients
and their squares, while explicitly storing the critical-speed square root as
binary32 before multiplying by area. The instruction listings and integration
comments record those separate boundaries.

With those corrections, all 568 FEQEX4 matrices match every active word. Its
water-level and discharge history also matches the distributed file exactly.
`CMPCOR` compares a wider relative correction against the stored binary32
maximum; rounding both operands first could report a different maximum-error
node. Preserving that comparison fixes the remaining location discrepancy.
The independent decimal converter described below resolves the final two
FEQEX4 report rounding differences and all three FEQEX1 history differences.

The current whole-output result is 13 of 17 files. Every FEQ output matches,
masking only execution clocks; the four failures are FEQUTL outputs.
`cpp-research-status.json` records the current executable and output hashes.
`model-active-matrices.json` records complete active-matrix trace comparisons,
with the original trace runs' independent report checks. The older full-COMMON
comparison is retained in `matrix-entry-comparison.json`. See
[NUMERICAL_PROBES.md](NUMERICAL_PROBES.md) for commands and probe limits.

## Single precision decimal conversion

The original runtime's REAL*4 branch of `_jwe_iroc` (RVA `0xe3fd0`) scales the
magnitude using a binary exponent estimate and two decimal-power tables. It
extracts sixteen trial digits to make its halfway decision, keeps at most nine
significant digits, and explicitly rounds a residual through binary32 when
propagating a nearly-ten carry. These intermediate operations explain why
98.25 prints as 98.3 in F5.1 but 0.125 prints as 0.12 in F5.2. Blanket half-away
or printf half-even policies do not reproduce the released routine.

`src/decimal.cpp` independently implements the recovered conversion with
explicit binary64 operations and observed binary32 stores. All 2,360 direct
original tests match the complete 32-byte result record: digit buffer, count,
decimal exponent, finite/special status, and general/engineering edit state.
The fixtures cover all finite exponent fields, both signs, zero, subnormals,
finite extremes, infinities, quiet/signaling NaN bit patterns, decimal halfway
values and their immediate neighbors, and signed scale factors. Special values
are inspected as bits before arithmetic. The original disassembly and power
constants are preserved alongside the probe and equations.

The research I/O bridge substitutes this conversion before F/E field layout.
No model outputs are rewritten after execution. Double precision conversion
still uses the existing research runtime; the single precision fixture result
does not imply verification of every formatted-I/O descriptor. Fresh full-model
runs produce twelve exact FEQ report comparisons and unchanged, exact active
matrix traces. FEQUTL still requires numerical recovery, and application
packaging and broader input coverage remain open.


## FEQUTL section-boundary geometry

`src/section_geometry.cpp` independently implements FBASEL's first pass over
piecewise linear boundary segments. All six geometric output arrays match every
bit in 363 controlled calls to the released FEQUTL `_fbasel_` (RVA `0x96250`).
The arrays are top width, wetted perimeter, double precision area and first
moment, weighted line roughness, and maximum depth. Cases span three scales,
multiple subsections, dry/partial/full submergence, vertical and horizontal
segments, overhangs, and the fixed/depth-dependent roughness branches. Original
flux calculations are disabled in these geometric probes with OLDBETA and no
sinuosity, so this result does not claim verification of those separate formulas.

The original water-surface intersection and its horizontal increment remain in
53-bit registers or x87 spills, while each top-width accumulation stores a
binary32 result. Truncating the intersection early changes widths and areas.
The partial-segment first moment multiplies by a binary64 one-third constant;
the fully submerged segment uses a binary32 one-third constant. The square root
for wetted perimeter has an explicit binary32 store before either perimeter or
weighted-roughness accumulation. These are separate, tested arithmetic choices,
with the formulas and instruction addresses beside the C++ implementation.

`attach_utility_components.py` selects the FBASEL definition using its syntax
tree and replaces its first geometric pass with the independent component.
It retains the roughness interpolation, second pass, and all flux formulas.
The bridge checks the released 999-point and 200-subsection extents and keeps
both geometric accumulation types intact. Fresh complete example runs still
pass all twelve FEQ files and FEQUTL's CHX file; four FEQUTL outputs remain
numerically different. A decrease in differing table lines is diagnostic only,
not an acceptance criterion.

## Analytical section flux and original power arithmetic

`src/section_flux.cpp` implements FBASEL's analytical NEWBETA second pass.
All eight double output sums and all three subsection arrays match in 458
controlled calls. The suite includes 216 isolated-segment cases and 242 cases
covering multiple subsections, variable roughness modes, vertical segments,
horizontal segments, the `1e-6` slope threshold, and unequal depth precision.
Sinuosity modes 0 and 2 are covered; mode 1's Gaussian path is separate.

Clipped offsets and right depth retain double precision. Left depth is rounded
to REAL at original VA `0x5b99a4`. Horizontal-segment powers use the REAL power
routine, while sloping-segment powers use the DOUBLE PRECISION routine. The
roughness exponent and integral exponents are the exact promoted REAL decimal
constants in the original image. The source comments preserve the formulas and
operation order rather than replacing those constants with exact fractions.

`src/power.cpp` recovers `_g_arxr`, `_g_adxd`, and their numerical kernels in
portable C++. All 3,382 committed cases match every bit, including every finite
normal exponent field and selected subnormals. The logarithm and exponential
approximation coefficients are recorded as exact hexadecimal literals; the
recovery tool checks the original executable hash and records coefficient-byte
hashes. Integer powers one through seven use sequential multiplication; eight
uses the approximation kernel. REAL powers round each small-integer product.
The DOUBLE PRECISION kernel leaves its binary exponent at the pre-normalization
value for subnormal input. The port reproduces that observed behavior.
These tests do not claim equivalence for NaN handling or legacy runtime error
callbacks; the authored API requires finite arguments and rejects invalid domains.

The analytical pass is integrated after FBASEL's roughness lookup. Full examples
still pass 13 of 17 reports: all twelve FEQ reports and the FEQUTL CHX file.
The first NEWBETA table now has the original beta/alpha values. Conveyance,
critical-flow, spline, and later utility differences remain; no numerical
comparison mask or tolerance was added. Thirteen component checks pass in both
the local release build and the address/undefined-behavior sanitizer build.

## Section properties and elevation arguments

`src/section_properties.cpp` implements COMPEL's aggregation after FBASEL.
All 415 direct original calls match every output bit and preserve updates to
roughness, previous conveyance, and previous top width. Cases cover three
scales, multiple subsections, old and new beta/alpha methods, momentum/energy
critical-flow selection, USGS coefficients, averaged roughness, and slot
conveyance retention. Nineteen cases use the exact rectangle elevations
captured from the original complete UTLEXM model.

Area and first-moment totals round after each REAL accumulation. Conveyance
retains a wider intermediate after sinuosity adjustment, including through the
slot comparison and total. The alpha sum rounds to REAL per subsection, while
the beta sum stays wider. Original power and square-root stores, coefficient
normalization, critical-flow denominators, and the section-wide n-value are
specified beside the equations. The original diagnostic formats remain in the
integration adapter. Piecewise linear sinuosity aggregation exists but awaits
verification together with its separate Gaussian integration path.

`src/elevation_arguments.cpp` implements CHKARG and its SORT/RDUP operations.
All 201 original-executable fixtures match the returned count and every byte
of the supplied array, including its unused tail and capacity-exhaustion cases.
The original keeps the gap, subdivision increment, and running elevation in
53-bit registers. Only the stored elevation rounds to REAL. The near-zero
point, stable insertion order, reciprocal duplicate threshold, zero-scale
unordered comparison, and original loop bound after removal are preserved.
Machine instructions for all three routines are retained under
`recovery/assembly/fequtl/`.

With both components integrated, the first UTLEXM report difference moves to
line 566, in the critical-flow table; the first culvert difference is line 408,
in the generated section's bottom elevation. The comparison still passes
13 of 17 complete outputs. A fresh build and complete trace rerun preserve
all twelve FEQ reports and every word of all 2,092 active matrices. Later
utility flow tables, generated section geometry, Gaussian integration, and
end-user packaging remain unfinished. No tolerance or numerical masking has
been introduced.

## Culvert root iteration

`src/root_solver.cpp` implements RGF3's modified false-position iteration.
All 423 direct calls to the original routine match every bracket field, return
flag, evaluation count, and trial argument. The temporary original driver
supplies both polynomial callbacks and scripted binary64 residuals. It records
the incoming argument before any callback adjustment. Tests exercise endpoint
precedence, residual values adjacent to a tolerance, the failure sentinel and
its strict comparison, interval collapse, the right-endpoint tie rule, repeated
sign damping, and the 101-evaluation failure path.

The original stores the trial as REAL at `0x473045`, but retains FM and FMOLD
at its 53-bit register precision. A callback result just below EPSF must pass
the residual test even when its rounded REAL value equals EPSF. FL and FR round
only when the bracket updates. The independent implementation keeps the
original ordering and output effects of each exit. The research adapter keeps
the historical trial-argument address and exposes updated bracket residuals
during nested callbacks.

After integration, all six supplied examples finish, all twelve FEQ outputs
remain exact except execution clocks, and the FEQUTL CHX remains byte-exact.
Four FEQUTL numerical outputs remain different. All 22 local component checks
pass in both release and address/undefined-behavior sanitizer builds. Full
application equivalence and end-user packaging remain in progress.
