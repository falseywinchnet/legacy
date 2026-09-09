# Implementation and binary fidelity

The destination is a complete native C++ implementation of RUNUP, WHAFIS, and CHAMP's project/transect workflow, with a simple Dear ImGui desktop application and ready-to-run macOS, Linux, and Windows packages. Source recovery is no longer a prerequisite. No staff requests or human-mediated archives will be pursued.

## Reference engines

The original November 1991 RUNUP executes under DOSBox-X 2026.08.31 on an Apple Silicon Mac. With `cpu core=normal` and `cpu fpu=false`, its output for the distribution's `test.in` matches the supplied `test.out` byte for byte (3,357 bytes, SHA-256 `886fd925686b8c3ba4d73aa02501eee69cef574a9b25f91903ff9be0a112d891`). The original Microsoft software floating-point emulator is active in this configuration.

Enabling the emulated coprocessor changes one profile slope's printed rounding from 6.88 to 6.87 in that same case. The numerical result rows are unchanged in that observed case. Both are executions of the same historical binary; the software path is the current reference because it reproduces the archived output exactly. Neither path should be silently mixed with the other when generating comparison data.

The original WHAFIS 4.0G Windows executable also executes through Wine 11.4 in an isolated prefix. Complete outputs were obtained for all four CHAMP WHAFIS input files. WHAFIS outputs include execution time and absolute input/output paths, which must be separated explicitly from numerical comparison.

Reproduce an original RUNUP output:

```sh
python3 tools/run_original.py runup originals/runup2/test.in build/reference.out
```

`--coprocessor` selects the alternate coprocessor execution path. All reference runs use temporary working copies; preserved originals are unchanged. The emulator and Wine are development tools, not dependencies intended for the final C++ application.

## Direct binary routine probes

`tools/probe_runup_routines.py` installs a tiny DOS driver into the main-program space of a **temporary copy** of RUNUP. The original executable startup, numerical routines, math runtime, and relocation records remain in place. It reads fixed-size binary records, calls the actual original routine, and writes raw result bytes. That avoids decimal report formatting concealing differences.

```sh
python3 tools/probe_runup_routines.py LOGLOG 10 100 100 1000 50
```

The original result is **499**, despite the idealized mathematical interpolation giving 500. Stored single-precision logarithms and truncation to an integer account for this case. Replacing the routine with a mathematically neater formula would change the program.

The C++ implementations of LOOK, RINT, SWLINT, LOGLIN, LOGLOG, and DBPLOT are in `src/runup/math.cpp`. There are 6,209 raw original-reference cases, including interval endpoints, zero-width linear intervals, constant logarithmic ordinates, and all nine positive INTEGER*4 decades. These are differential checks, not a proof of complete numerical equivalence. LOOK is compared against original lower/upper index and flag results.

C++ arithmetic uses explicit single-precision storage points, wider expression intermediates, and disabled floating-point contraction. Further routine and whole-program checks will determine where the original software floating-point implementation needs closer reproduction.

`tools/disassemble_runup.py` decodes the application's Microsoft `INT 34h–3Dh` floating-point traps along with x86 instructions and annotates the original source-line mappings. Reading these bytes as ordinary instructions alone produces misleading disassembly. Its optional research dependency is Capstone 5.

## Complete-report milestone

The `runup` executable reads the original fixed-column files and produces original-format reports without an emulator or historical runtime. Its five supplied reference cases contain 44 wave calculations and 17,633 report bytes. These have passed byte-for-byte comparison on macOS, Linux, and Windows. The current expanded suite contains 113 complete reference files, including 80 deterministic varied profiles, structure/approach/berm cases, varying roughness and water levels, nonconvergence, steepness errors, arithmetic stops, a 20-point boundary case, and a five-profile input. Formatting preserves missing leading zeroes, NUL bytes in historical headings, carriage returns, and page controls.

The first published wave also matches captured original intermediate values, including its four convergence iterations, structure and approach geometry, breaking station, effective slope, and final raw binary32 runup. The snapshot probe can stop at input, wave, and curve boundaries, including a selected repeated curve visit, to locate discrepancies before formatting.

The native geometry and curve code is in `src/runup/calculation.cpp` and `src/runup/curves.cpp`. Original variable names are retained inside the calculation record to make comparisons with original debug symbols reviewable; the public interface uses profile, wave, and result records. Table constants are generated reproducibly from the recovered binary data.

## Native desktop and project workflow

The C++20 project layer, Dear ImGui desktop, and packages are implemented. The
application opens the original Access database without an Access dependency,
retains all imported tables, and saves native `.coastal` projects. Its workflow
covers shoreline adjustment, dune removal/retreat, separate annual-chance
scenarios, WHAFIS cards, RUNUP selection, both native engines, plots, and exports.
See [CHAMP implementation](CHAMP_IMPLEMENTATION.md) and
[desktop operation and builds](DESKTOP.md).

The 16-test suite includes database and project round trips, original geometry,
complete original reports, raw routine comparisons, result table extraction,
CSV/TSV/DXF import, CSV/DXF float round trips, SVG escaping, malformed imports,
and atomic parameter validation. Desktop smoke checks additionally exercise
pending-edit application, undo, both engines, project save/reopen, and rendering
from the installed application with its packaged example and font. Windows and
Linux packages passed these checks at `92658ad`; the final release's Actions run
records the subsequent Mac compatibility and packaging checks.

## Limits of the evidence

The available original cases do not prove equivalence for every floating-point
input or malformed historical project. RUNUP's observed arithmetic stops and
20-point array effects are modeled explicitly without reproducing unsafe memory
access. WHAFIS's active source paths are ported, with full report and selected raw
routine comparisons. Additional combinations of obstruction geometry, marsh
parameters, and degenerate input can be checked using the preserved probe tools.
The CHAMP erosion sample covers two retreat profiles and two removal endpoints;
four numerical geometry routines have direct original-byte fixtures. Database
compatibility is constrained to the implemented unencrypted Jet 3/4 formats.

New discrepancies should be minimized into an input fixture and captured against
the original executable before changing numerical code. The engineering models
retain their historical assumptions and limits; the new interface does not
silently substitute a newer coastal model.

The expanded RUNUP suite passed GitHub Actions on macOS, Linux, and Windows at commit `d656bbc`. The same 113-report and 6,209-routine suite also passed local address, undefined-behavior, and float-to-integer sanitizers.

## WHAFIS native milestone

The `whafis` C++ program covers the complete active 4.0G source: surge preprocessing, inland and overwater fetch, dunes, buildings, vegetation and marshes, default plant lookup, above-surge sections, all report sections, and 100-/500-year wind options. The current 17-report suite includes all four supplied CHAMP reports, dunes, buildings, trees, marsh defaults and region weighting, surge changes, above-surge sections, comments, nondefault winds, and all four supplied transects under 500-year winds. It matches 154,499 bytes after excluding exactly three metadata lines: execution date, input filename, and output filename. Every remaining byte, including spacing and line endings, is compared. Coverage of a source path does not establish its numerical equivalence. The two previously failing 500-year cases are now included in the passing suite.

The historical scratch-file conversions are performed in memory, with the same field widths and decimal precision. The included `MG.DAT` table eliminates an external runtime data-file requirement. One-based arrays have bounds checks, and each calculation owns its state. `tools/port_whafis.py` preserves the source control-flow labels while producing the initial readable C++ statements; binary-verified routines are maintained directly. The larger routines retain source labels and original scalar names for direct differential review; the public C++ API, state ownership, input/output handling, and desktop workflow are independent of those labels.

WHAFIS's retained `.trace` section names 17 original procedures. `tools/disassemble_whafis.py` locates these procedures without guessed boundaries. `tools/probe_whafis_routines.py` patches only temporary executable copies to call the original routines on binary inputs. The breaking-height routine SHBM, period-growth routine T, zero-moment wave-height routine HM0, and inland wave-height routine HIN each match 1,000 original binary32 results. All four are hand-maintained C++ routines. `tools/capture_whafis_state.py` captures original COMMON storage just before the report phase, allowing differences hidden by printed rounding to be inspected.

The supplied Windows compiler retains some intermediate quantities in x87 registers across source assignments. The C++ implementation preserves those wider intermediates where established from the executable, including fetch-cell midpoint elevations and the breaking-height wavelength calculation. This prevents a one-hundredth-foot station discrepancy and a boundary flood-zone elevation discrepancy found in the supplied reports.

Confirmed RUNUP changes between the printed listing and executable are recorded in [RUNUP historical differences](RUNUP_DIFFERENCES.md). The recovered WHAFIS version changes and compiler effects are described in [WHAFIS differences](WHAFIS_DIFFERENCES.md).

The original WHAFIS x87 control word is `0x027f` (53-bit significand). FETCH keeps several averages, ratios, and drag terms in those registers across Fortran assignments; other quantities are explicitly stored to binary32 temporaries. For example, the old period is squared into a single-precision temporary before its wider cube is computed. Wind coefficients also use single-precision constants folded by the original compiler. The preserved storage boundaries resolve both remaining 500-year station-rounding differences. The direct-state probe now supports fetch coefficient and completed-fetch boundaries as well as the reporting boundary.
