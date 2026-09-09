# Legacy

A collection of legacy software recovered, understood, and brought forward to
modern computers. Each project contains its usable programs, source, documentation,
and the historical material needed to understand where it came from.

## Available now: CHAMP, WHAFIS, and RUNUP

**Looking for FEMA CHAMP 2.0, WHAFIS, or RUNUP?** This repository offers
**Legacy Coastal**, a native desktop application that brings the CHAMP coastal
study workflow and both numerical engines to **Mac, Windows, and Linux**. It opens
original CHAMP projects, runs the analyses locally, and saves reusable studies.

**[Download Legacy Coastal 0.1.0](https://github.com/falseywinchnet/legacy/releases/tag/v0.1.0)**
· **[CHAMP project and source](CHAMP/)**
· **[How to use it](CHAMP/docs/DESKTOP.md)**

| Program | What you can do with it here |
| --- | --- |
| **CHAMP 2.0 — Coastal Hazard Analysis Modeling Program** | Open original Access `.mdb` studies, import and edit transect profiles, adjust the shoreline, prepare dune removal or retreat, and manage separate 100-year and 500-year analyses. Save the complete study as an open `.coastal` project. |
| **WHAFIS — Wave Height Analysis for Flood Insurance Studies** | Calculate coastal wave heights across a transect with dunes, buildings, vegetation, and marshes. Edit the original input cards, inspect wave crests and result tables, and export original-format reports. |
| **RUNUP** | Calculate wave runup using the reconstructed November 1991 engine. Select profile points and surface roughness, review the wave calculations and runup estimates, and export original-format reports. |

The downloads include the desktop application, standalone `whafis` and `runup`
command-line programs, a four-transect example study, and the original operating
manuals. **No Access installation, emulator, Python, Fortran compiler, or original
executable is needed to use the modern programs.** CSV/TSV and DXF profile imports
and CSV, SVG, DXF, and report exports are available in the desktop application.

### Get running

- **[Mac — Apple Silicon and Intel](https://github.com/falseywinchnet/legacy/releases/download/v0.1.0/Legacy-Coastal-0.1.0-macOS-universal.dmg):** open the DMG, drag **Legacy Coastal** into Applications, and open it.
- **[Windows x64](https://github.com/falseywinchnet/legacy/releases/download/v0.1.0/Legacy-Coastal-0.1.0-Windows-x64.zip):** extract the ZIP and open **Legacy Coastal.exe**. Keep the extracted folders together; no separate Visual C++ runtime installation is required.
- **[Linux x64](https://github.com/falseywinchnet/legacy/releases/download/v0.1.0/Legacy-Coastal-0.1.0-Linux-x86_64.tar.gz):** extract the archive and open **Start Legacy Coastal.sh** on an Ubuntu 22.04-compatible desktop.

Choose **Open the example project**, select a transect, then choose **Run WHAFIS**
or **Run RUNUP** on the corresponding page. Review the Results page and use
**Save project** to keep your study. The [desktop guide](CHAMP/docs/DESKTOP.md)
covers a new study, imports, exports, keyboard controls, and first-launch OS
approval for these releases without a publisher signature or Apple notarization.

### Source, original software, and numerical behavior

Everything for this project is under **[`CHAMP/`](CHAMP/)**:

- **[Modern C++20 implementation](CHAMP/src/)** and **[build instructions](CHAMP/README.md#build-from-source)**, using CMake/Make and Dear ImGui/SDL. From the repository root, run `cd CHAMP` before the project's build commands.
- **[Original distributions and manuals](CHAMP/originals/)**, including recovered WHAFIS 4.0G Fortran source and preserved CHAMP, WHAFIS, and RUNUP executables.
- **[Recovery findings](CHAMP/recovery/FINDINGS.md)** and **[research tools](CHAMP/tools/)** for examining original binaries, extracting numerical tables, and running comparisons against the historical programs.
- **[Implementation evidence](CHAMP/docs/IMPLEMENTATION.md)**, **[RUNUP differences from earlier listings](CHAMP/docs/RUNUP_DIFFERENCES.md)**, and **[WHAFIS source and compiler differences](CHAMP/docs/WHAFIS_DIFFERENCES.md)**.

The native engines match 113 complete original RUNUP reports and 17 WHAFIS
reports, with only WHAFIS execution metadata excluded. Additional raw routine,
geometry, database, and connected-workflow comparisons are documented with the
project. These establish the captured cases, not equality for every possible
input. The original RUNUP digital Fortran and CHAMP Visual Basic project remain
missing; surviving binaries, debug data, tables, and p-code supplied the evidence
used to reconstruct their behavior.

## Available now: FEQ / FEQUTL

**[Download FEQ Workbench 0.1.0](https://github.com/falseywinchnet/legacy/releases/tag/FEQ-v0.1.0)**
· **[FEQ project, instructions, and evidence](FEQ/)**

FEQ Workbench includes **FEQ 10.61** for unsteady channel-network flow and
**FEQUTL 5.80** for hydraulic function tables. Both engines are native C++20.
Windows x64, Apple silicon macOS, and Ubuntu 24.04 x64 packages include the
desktop interface, six supplied models, original manuals, and a report viewer.
Open **Examples**, choose a model, click **Use selected example**, then **Run model**.

The native builds pass 69 automated checks on all three operating systems;
desktop builds pass 70. Actual installed applications reproduce all 17 supplied
output files with only run timestamps and execution clocks masked. The project
also preserves original-machine-code fixtures, source revision comparisons,
formula comments, and the recovered USGS distributions. The documented evidence
establishes the tested cases, rather than every possible model input.

## Collection structure and licensing

CHAMP and its associated engines, and FEQ/FEQUTL, have separate project directories.
Project-specific code, assets, research, licenses, and instructions live in each
project's directory; repository-wide GitHub workflows live in [`.github/`](.github/).

The new CHAMP implementation and tooling are **[MIT licensed](CHAMP/LICENSE)**.
Historical material and third-party dependencies retain their existing
[authorship and notices](CHAMP/NOTICE.md).

**Work: Astra · Sponsor: Rainstar · Foundation: Hashem.**
