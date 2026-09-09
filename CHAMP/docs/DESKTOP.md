# Legacy Coastal desktop

## Use the application

1. Download your computer's package from the [Legacy Coastal release](https://github.com/falseywinchnet/legacy/releases/tag/v0.1.0).
2. On Mac, open the DMG and drag Legacy Coastal to Applications. On Windows,
   extract the ZIP and open Legacy Coastal.exe. On Linux, extract the archive
   and open Start Legacy Coastal.sh or the Legacy Coastal executable.
3. Choose **Open the example project**. Select a transect on the left.
4. Open **WHAFIS wave heights** and choose **Run WHAFIS**, or open **RUNUP** and
   choose **Run RUNUP**. Results open when the calculation finishes.
5. Choose **Save project** to save a separate `.coastal` study containing its
   tables, inputs, and reports. Original Access projects are never overwritten.

Packages target Windows x64, macOS 11+ (Intel and Apple Silicon), and Linux x64
with an Ubuntu 22.04-compatible C/C++ runtime and a graphical desktop. The Actions
run records the operating systems actually used for each release check.

The application needs no original executable, emulator, Access installation,
Python, or compiler. Calculation takes place on the computer running the app.

The release currently has local integrity signatures on Mac, rather than an
Apple Developer ID/notarization, and no commercial Windows publisher signature.
An operating-system first-launch approval may therefore be required. On macOS,
use the Open Anyway control in System Settings → Privacy & Security after the
first launch attempt. This uses [Apple's documented per-app approval](https://support.apple.com/en-us/102445)
and does not require disabling Gatekeeper. Windows may
show an unknown-publisher prompt for the downloaded executable. The release's
SHA256SUMS file identifies the exact distributed archives.

## A new study

**Project & parameters:** enter the study identity, vertical datum, and wave/water
conditions for the selected annual chance. Mean-wave derivation uses the original
CHAMP height multiplier 0.626 and period multiplier 0.85. Geometry and water
levels use feet, periods use seconds, fetch uses miles, and winds use mph.

**Transect profile:** import a CSV/TSV/text profile or a 2D DXF polyline, or paste
station/elevation columns. Source labels are optional. Stations increase landward.
The import dialog can convert metre coordinates to feet. Adjust shoreline inserts
zero crossings and moves the shoreline station to zero while retaining original
survey stations in the adjusted table.

**Erosion treatment:** select peak and toe on the adjusted ground. For retreat,
select face and seaward points. Preview the area balance and save the eroded
profile when satisfied. Both annual-chance scenarios retain their own erosion
geometry and profiles. Erosion can be skipped when the adjusted profile already
represents the intended terrain.

**WHAFIS:** populate from the analysis profile, assign obstruction and vegetation
cards, and run. The card table supports insertion and removal. The full input
editor preserves fixed-column decks, comments, and marsh records. The bundled
WHAFIS manual provides the complete card-field definitions.

**RUNUP:** populate the selection, include the required 2–20 points, choose surface
roughness, and run the nine-wave combination. The historical 20-point boundary
can trigger the original engine's arithmetic-stop behavior; the report records
that outcome without a native out-of-bounds memory access.

**Results:** view profiles, wave crests, the 2% runup estimate, and result tables.
Export CSV data, SVG charts, DXF geometry, or the original-format report. Original
WHAFIS reports retain their execution metadata and original formatting.

Pending parameter, profile, card, and selection edits are validated before saving,
running, or switching transects/scenarios. Undo/redo retains up to 40 project
snapshots. Changing upstream parameters or profiles does not automatically replace
historical results: prepare the affected engine again when needed, then run it.
Erosion previews are committed through **Save eroded profile**.

## Keyboard and plots

- Ctrl/Cmd + 1–8 opens a page.
- Ctrl/Cmd + Enter runs the selected engine.
- Ctrl/Cmd + S saves; Ctrl/Cmd + Shift + S saves a copy.
- Ctrl/Cmd + O opens a project; Ctrl/Cmd + N starts one.
- Ctrl/Cmd + Z undoes; Ctrl/Cmd + Shift + Z redoes.
- Tab and arrow keys navigate controls.
- Scroll over a plot to zoom; right-drag to pan; Fit plot resets the view.

Getting started includes buttons for the original CHAMP, RUNUP, and WHAFIS
manuals, including the WHAFIS 4 supplement. These PDFs are included in the package.

## Build and verify

CMake 3.24+, a C++20 compiler, and Python for the test scripts are required for a
source build. Python is not a runtime dependency of the resulting application.
Run the build commands below from the repository's `CHAMP/` directory. From the
repository root, enter `cd CHAMP` first.

```sh
make test
make package
```

For just the native engines and project libraries:

```sh
make test DESKTOP=OFF
```

The first desktop configuration downloads SHA-256-pinned SDL 3.4.16 and Dear ImGui
1.92.9b sources. Subsequent builds reuse them. Linux window-system development
packages are listed in `../.github/workflows/build.yml`. Inter and the original
example project are included locally. Dependency licenses accompany the package.

For a universal Mac build:

```sh
cmake -S . -B build/universal -DCMAKE_BUILD_TYPE=Release \
  '-DCMAKE_OSX_ARCHITECTURES=arm64;x86_64' -DCMAKE_OSX_DEPLOYMENT_TARGET=11.0
cmake --build build/universal --parallel
ctest --test-dir build/universal --output-on-failure
python3 tests/check_macos_intel.py build/universal
cmake --install build/universal --prefix build/installed
cpack --config build/universal/CPackConfig.cmake -B build/packages
```

Mac targets and the completed bundle receive ad-hoc integrity signatures for all
architectures. The install step signs again after bundling command-line programs,
manuals, and notices. CI verifies that signature and launches both Mac slices.

Windows builds link the C/C++ runtime statically. CI also inspects PE imports
to reject accidental dependencies on a separately installed Visual C++ runtime.

The desktop's `--smoke-test` option opens the packaged example, checks pending
edits and undo, runs both engines, saves and reopens a temporary project, renders
five frames, and exits with an error status on failure. `--screenshot FILE.bmp`
captures the rendered frame for inspection. CI performs this check on the installed
contents on all three operating systems before creating distributable archives.
