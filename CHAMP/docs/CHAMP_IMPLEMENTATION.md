# CHAMP implementation evidence

The native project layer implements project and transect editing, adjustment,
erosion, WHAFIS preparation, RUNUP preparation, plots, exports, and separate
100-/500-year analyses. The Dear ImGui application exposes that workflow directly.

## Database recovery

The C++ reader opens Jet 3 (Access 97) and Jet 4 (Access 2000–2003) databases
directly. The preserved CHAMP sample has 19 user tables and 670 rows. Every cell,
including raw floating-point values, nulls, empty strings, and Booleans, matches
an independent MDB Tools extraction. The original database is opened read-only.
Table definitions, allocation maps, variable-column offset/jump tables, overflow
records, memo chains, and Jet 4 Unicode compression are decoded in C++.

The reader has also opened the MDB Tools Northwind (Jet 3) and DateTest (Jet 4)
research fixtures. Those exploratory reads are not counted as complete-cell
comparisons. Encrypted/newer Access formats and additional character sets need
explicit compatibility review before a broader support claim.

## P-code recovery and direct execution

The application retains 30 Visual Basic objects. `visualbasic-rs` at commit
`a1fd81087e10ac02aea5646219b0bc1a82b5e24c` disassembles their p-code, and
`tools/disassemble_champ.py` resolves original string-pool entries and numerical
constants. This is disassembly, not a claim that original VB source was recovered.
The research dump's GUI entries need to be indexed across the 29 forms only,
excluding the first `Main` module; its initial example counted that module as a
form. Method and constant-pool locations are verified independently against the
preserved executable.

The original GUI was installed into the isolated Wine prefix from the preserved
MSI. Its startup currently reaches the VB host but not the usable project window;
DAO/Jet initialization is being examined. Original numerical p-code can already
be called independently through the preserved `msvbvm60.dll` runtime. Only the
copied procedure descriptor's context pointer is replaced. The computation bytes
are unchanged; the native product never loads VB or original executable code.

`tools/probe_champ_routines.py` captures raw original results. Four C++ routines
in `src/champ/geometry.cpp` each match 1,000 raw original records:

| Procedure | Original location | Compared output |
| --- | --- | --- |
| Main interpolation | `0x00479AFC` | binary32 ordinate |
| Main general-form line | `0x00478714` | three binary32 coefficients |
| Main line intersection | `0x00478254` | two binary32 coordinates |
| Main polygon area | `0x0047A72C` | binary64 area |

The interpolation stores intermediate differences, ratio, and product as Single.
The line routine retains expression intermediates more widely. Polygon accumulation
stores a Single each iteration but returns its final expression as Double; a
compensated final sum reproduces extended-register results across the native
platforms without depending on the host's `long double` representation.
The historical intersection assumes slope/intercept lines (`b=-1`), overwrites its
initial general determinant, and returns `-99999` coordinates for parallel slopes.
These are compatibility details, not invitations to use this helper as a generic
analytic-geometry library.

The raw routine fixtures establish the tested cases, rather than universal
equivalence for every possible input. The connected workflow has the additional
comparisons described below.

## Connected project workflow

`legacy::champ::Project` now imports the actual Access project and saves a native
`.coastal` document. The JSON envelope has an explicit format/version, the complete
original table schemas and rows, and per-transect/per-scenario input and report
records. Imported MDBs are read-only. Saving uses a temporary file followed by an
atomic replacement. Copy, rename, and delete traverse every table containing the
transect ID, including tables unknown to the current user interface.

The native workflow includes surveyed and adjusted profiles, an interpolated zero
shoreline with original stations retained, separate 100/500-year parameters and
erosion/results, dune removal and retreat, RUNUP selection/roughness and nine-wave
setup, WHAFIS card population and editing, and both in-memory engines. WHAFIS
records retain CM/PS and raw MG records. Erosion follows the original manual's
interactive selection, rather than inventing an automatic optimization criterion.

The sample's two retreat profiles reproduce **every saved station and elevation
bit for bit** after sorting by station. Both removal intersections match the saved
geometry coordinates. Matching required the original Single-to-text-to-Single
conversions, graph extent used to construct the approach line, and the original
zero-crossing arithmetic. Full erosion branch equivalence remains under review;
these sample comparisons establish the stated cases, not every possible profile.

Eight additional original executable runs use decks generated by the native project
workflow, including project headings: four RUNUP and four WHAFIS. Their untouched
inputs and outputs are in `tests/reference/champ/workflow`. The workflow test
checks input generation, complete original reports (only WHAFIS execution metadata
excluded), project save/reopen, transect operations, original erosion coordinates,
new shoreline adjustment, and independent 100/500-year analysis. This exposed and
fixed the Compaq runtime's suppression of a minus sign for F-format values that
round to zero.

The sample has historical inconsistencies: its saved erosion controls and RUNUP
selection were edited at different times, and transect 2's stored average differs
from its supplied RUNUP input/output. The port preserves the imported values and
replaces a result only when that analysis is run. New averages accumulate the
original printed decimal runup values with the original Single storage step.

## Results and desktop integration

WHAFIS reports populate all six historical result tables. The parser retains the
report's printed precision and excludes the ET terminator from PART 1. In PART 6,
an interval without a printed designation becomes X and retains the preceding
zone elevation and FHF, as the original form does at p-code offsets 14ED–1547.
The first generated transect produces 9/29/1/3/1/17 rows in Parts 1–6. This is
checked alongside the current report stations so stale imported values cannot
masquerade as a fresh result.

RUNUP's zone boundary uses mean runup + stillwater − 3 feet, despite its separately
displayed 2% estimate using the 2.23 multiplier. The native first-transect zone
coordinates match the saved original coordinates exactly. Failed calculations
retain their input and diagnostic report and clear the affected result tables.

The interface applies parameter, profile, card, and selection edits before save,
calculation, or transect/scenario changes. It validates a candidate project before
replacing the current project, preserves undo history, and saves atomically.
Erosion preview controls remain explicit: Save eroded profile commits a treatment.
The full WHAFIS deck and card table are alternative editors; simultaneous edits
require choosing which editor to apply rather than silently overwriting one.

CSV/TSV import supports headers, quotes, source labels, and quoted line breaks.
DXF import reads 2D LWPOLYLINE, POLYLINE/VERTEX, and LINE geometry, with X as station
and Y as elevation. Export writes open DXF polylines and standalone SVG charts.
Result charts include wave crests or the 2% runup elevation. Original project
tables can also be exported as CSV or edited through the advanced table view.
Original CHAMP, WHAFIS, and RUNUP manuals are bundled with the application.

The desktop is implemented in `src/desktop/`; project geometry, import/export, and
workflow code remain independently usable libraries. All application calculations
use native C++ and do not launch original executables or historical runtimes.
