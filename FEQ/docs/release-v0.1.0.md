FEQ Workbench runs **FEQ 10.61** and **FEQUTL 5.80** as native C++20 programs,
with a desktop interface, six supplied models, original PDF manuals, a report
viewer, and saved run history. It includes the required interface libraries;
no Fortran compiler, Wine, Python, or separate runtime download is needed to use it.

| Computer | Download | Open |
| --- | --- | --- |
| Windows 10 version 1903 or later / Windows 11, x64 | `Windows-AMD64.exe` | Follow the installer, then open **FEQ Workbench** from Start. |
| macOS 13 or later, Apple silicon | `Darwin-arm64.dmg` | Drag **FEQ Workbench** into Applications. |
| Ubuntu 24.04, x64 | `Linux-x86_64.deb` | Use the system package installer, then open **FEQ Workbench**. |

Choose **Examples**, select a model, click **Use selected example**, then
**Run model**. Every run has a new folder with the copied inputs, results,
console log, and hashes. Existing model files use the same historical formats.
The Windows ZIP and Linux tar.gz are portable alternatives; extract the whole
archive and use `Start-FEQ.cmd` or `Start-FEQ.sh`. The Linux archive requires
the system libraries listed in the Debian package metadata.

The native engines pass 69 checks on Windows, macOS, and Linux, including a
separate ASan/UBSan build. Desktop builds pass 70 checks on each platform.
Actual installer acceptance runs all six supplied models from relocated folders
containing spaces and Unicode characters. All 17 original output files match
with only run timestamps and elapsed clocks masked; five match raw bytes,
including all four FEQ water-level and discharge histories. No hydraulic value,
diagnostic, convergence result, or other report byte is excluded.

`FEQ-verification.zip` preserves the CI reports, logs, run records and screenshots.
`FEQ-release.json` identifies the exact tested source revision and package hashes;
`SHA256SUMS.txt` covers the downloads. Detailed original-machine-code fixtures,
formula comments, source comparisons, and reproduction tools are in the
[FEQ project](https://github.com/falseywinchnet/legacy/tree/main/FEQ).
These comparisons establish the captured cases and supplied models; they do
not prove equivalence for every possible input deck.

The fourth FEQ example completes with its original `ERR:174` and `ERR/WRN:234`
diagnostics. Workbench displays those counts and preserves the original outputs.
The released programs' behavior and known historical defects are documented
in the project's recovery findings.

The Windows packages are unsigned. The macOS app is ad hoc signed and is not
notarized. Windows may show SmartScreen; macOS may require **System Settings →
Privacy & Security → Open Anyway** after the first launch attempt.

**Work: Astra · Sponsor: Rainstar · Foundation: Hashem.** New project work is MIT
licensed. Historical FEQ/FEQUTL and Netlib notices remain in force. Qt is
dynamically linked under LGPL version 3, with its notices and complete matching
source archives included. This release does not imply USGS endorsement.
