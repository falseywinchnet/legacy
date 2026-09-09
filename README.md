# Legacy — CHAMP, WHAFIS, and RUNUP forward port

Legacy Coastal is a native desktop application for coastal transects, dune erosion,
WHAFIS wave heights, and RUNUP. It opens original CHAMP 2.0 projects directly and
saves studies, inputs, and reports in an open `.coastal` project file.

**Work: Astra · Sponsor: Rainstar · Foundation: Hashem.** New code is MIT licensed.

## Start here

Download the package for your computer from [Releases](https://github.com/falseywinchnet/legacy/releases).
The [Actions builds](https://github.com/falseywinchnet/legacy/actions) also retain packages for each tested revision.

- **Mac:** open the DMG, drag **Legacy Coastal** into Applications, and open it.
- **Windows:** extract the ZIP and double-click **Legacy Coastal.exe**. Keep the
  example and font folders beside the application.
- **Linux:** extract the archive and open **Start Legacy Coastal.sh**, or run the
  **Legacy Coastal** executable in that folder.

Choose **Open the example project**. Four transects include surveyed, adjusted,
and eroded profiles plus historical analysis data. Select **WHAFIS wave heights**
and **Run WHAFIS**, or **RUNUP** and **Run RUNUP**. Review the Results page, then
use **Save project** to keep a copy. The Getting started page explains a new study
from profile import through results export. No emulator, Python, Fortran compiler,
Access installation, or original executable is needed to use the application.

The interface uses Dear ImGui and SDL. It supports CSV/TSV and DXF profile import,
editable profiles, shoreline adjustment, dune removal and retreat, both annual
chance scenarios, obstruction and vegetation cards, runup surface selection,
undo/redo, native file dialogs, and CSV/SVG/DXF/report export. Original `.mdb`
files are read without modification; all imported tables and fields survive a
save to `.coastal`.

## Numerical evidence

RUNUP matches **113 complete original reports and 6,209 raw routine records**.
WHAFIS matches **17 complete original reports and 4,000 raw routine records**,
excluding only execution date and file-path metadata in its reports. The connected
CHAMP workflow also matches eight newly captured original reports, the supplied
retreat coordinates, and the original mean-runup zone coordinates. The database
reader preserves every cell in all 670 rows of the supplied project. The four
recovered CHAMP geometry routines have 4,000 original raw numerical records.

These comparisons establish the tested behavior; they are not a proof of equality
for every possible input. See [implementation evidence](docs/IMPLEMENTATION.md),
[CHAMP implementation](docs/CHAMP_IMPLEMENTATION.md), and
[RUNUP historical differences](docs/RUNUP_DIFFERENCES.md).

## Recovered so far

| Component | What is now in this repository | What remains missing |
| --- | --- | --- |
| WHAFIS | **Original digital `WHAFIS4G.FOR`, August 2007**, recovered from an archived FEMA ZIP. It also embeds the WHAFIS 3.0 reference source, with revision history through May 1989. Original executables, marsh data, and manuals are preserved. | Earlier independent development snapshots, if recoverable. The 2007 source is available to port. |
| RUNUP | **November 1991 DOS executable with original debug records:** four Fortran filenames, 18 application procedures, 693 line mappings, and **3,587 original table integers extracted directly from the binary**. Original samples, 1981 printed source, March 1990 listing, and a higher-resolution archived scan are preserved. | Original digital Fortran, especially the revision that produced the November 1991 executable. Debug records preserve names and locations, not source text. |
| CHAMP | **Original 2007 CHAMP 2.0 installer**, application and sample project/transect files, manual, and earlier 2001/2004 distributions. Embedded metadata preserves the original project path, a developer credit, and 30 named VB objects in each inspected 2001/2007 application. | Original Visual Basic project, forms, modules, and build material. These are absent from the installers inspected; application p-code survives. |

Read the [source recovery findings](recovery/FINDINGS.md) for exact versions, archive links, and source-listing page ranges. The earlier archive research is preserved as provenance. No staff requests or human-mediated archive searches are needed to continue this port.

## Repository layout

- [`originals/whafis4/WHAFIS4G.FOR`](originals/whafis4/WHAFIS4G.FOR): the recovered digital source, preserved byte for byte.
- [`originals/archives/`](originals/archives/): historical distribution ZIPs.
- [`originals/manuals/`](originals/manuals/): primary manuals, including the printed RUNUP source listings.
- [`originals/runup2/`](originals/runup2/), [`originals/whafis3/`](originals/whafis3/), and [`originals/champ2/`](originals/champ2/): original programs and supporting data extracted without running them.
- [`recovery/manifest.json`](recovery/manifest.json): original URLs, archive members, sizes, and SHA-256 hashes.
- [`tools/extract_champ_installer.py`](tools/extract_champ_installer.py): static extraction of the recovered CHAMP InstallShield payloads.
- [`recovery/runup-1991-debug/`](recovery/runup-1991-debug/): original NB02 debug bytes and decoded build records.
- [`recovery/runup-1991-tables.json`](recovery/runup-1991-tables.json): original integer table data, with executable offsets and hashes.
- [`tools/extract_runup_debug.py`](tools/extract_runup_debug.py), [`tools/extract_runup_tables.py`](tools/extract_runup_tables.py), and [`tools/extract_champ_metadata.py`](tools/extract_champ_metadata.py): reproducible static readers for these recoveries.

FEMA's 2024 RUNUP reconstruction is a separate version, not the source baseline for this effort. Its documentation acknowledges the missing November 1991 digital source and the need to infer intervening changes. Recovering the actual earlier files remains an open task.

## Port direction

Keep the original algorithms, numerical tables, data formats, and CHAMP workflow legible as they become C++. Favor explicit data and straightforward functions, with a small interface around the actual calculations. Preserve original files separately from translations and identify unresolved historical differences instead of silently choosing a replacement.

The current RUNUP calculation includes profile geometry, breaking depth, curve selection, roughness, scaling, structure/composite branches, convergence, and historical reports and diagnostics. The expanded reference suite contains 113 complete report files and 6,209 raw numerical routine records. All 113 reports and the 6,209 routine records passed on macOS, Linux, and Windows at commit `d656bbc`. These fixtures do not establish universal equivalence. See [implementation evidence and remaining work](docs/IMPLEMENTATION.md).

## Build from source

Use CMake 3.24 or newer and a C++20 compiler. The desktop build downloads
hash-pinned SDL and Dear ImGui sources once. Linux additionally needs the window
system development packages listed in [the CI workflow](.github/workflows/build.yml).
`make package` runs the tests and creates a desktop package. For engines and
project libraries only, use `make test DESKTOP=OFF`; that build has no downloaded
UI dependency.

For a development build:

```sh
make test
build/native/runup originals/runup2/test.in result.out
build/native/whafis originals/champ2/w1.dat wave-result.out
```

Both command-line programs have no emulator, Python, Fortran, or original-executable dependency. WHAFIS includes the original marsh-grass defaults and exposes calculated wave points through a C++ library interface. GitHub Actions builds and checks C++ on macOS, Linux, and Windows. The same workflow installs and launches the desktop example before creating Mac, Windows, and Linux packages.

## Attribution

**Work: Astra · Sponsor: Rainstar · Foundation: Hashem.** New implementation and project tooling are [MIT licensed](LICENSE). Preserved historical material and third-party components retain their existing notices; see [credits and notices](NOTICE.md).
