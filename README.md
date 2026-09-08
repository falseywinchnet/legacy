# Legacy — CHAMP, WHAFIS, and RUNUP forward port

Recover the original FEMA **CHAMP 2.0 (Coastal Hazard Analysis Modeling Program)** and its two numerical engines, **WHAFIS** and **RUNUP**, then carry all three forward into clean, legible, modern orthodox C++ with a simple **Dear ImGui** interface.

The intended targets are **macOS, Linux, and Windows**, using **Make/CMake** and **GitHub Actions runners**. CHAMP's project and transect workflow is part of the port, alongside both numerical engines.

**Original source recovery comes first.** Search historical distributions, web archives, government document and microfiche repositories, and original contractor records. Do not replace a missing original with a convenient modern reconstruction. Testing, certification, and process scaffolding are not the current priority.

## Recovered so far

| Component | What is now in this repository | What remains missing |
| --- | --- | --- |
| WHAFIS | **Original digital `WHAFIS4G.FOR`, August 2007**, recovered from an archived FEMA ZIP. It also embeds the WHAFIS 3.0 reference source, with revision history through May 1989. Original executables, marsh data, and manuals are preserved. | Earlier independent development snapshots, if recoverable. The 2007 source is available to port. |
| RUNUP | **November 1991 DOS executable**, original sample input/output, the **1981 printed source**, and the **March 1990 source listing published in April 1991**. | Original digital Fortran, especially the revision that produced the November 1991 executable. |
| CHAMP | **Original 2007 CHAMP 2.0 installer**, extracted application and sample project/transect files, manual, and an earlier 2004 installer. | Original Visual Basic project, forms, modules, and build material. These are absent from the installers inspected. |

Read the [source recovery findings](recovery/FINDINGS.md) for exact versions, archive links, source-listing page ranges, and the unresolved leads.

## Repository layout

- [`originals/whafis4/WHAFIS4G.FOR`](originals/whafis4/WHAFIS4G.FOR): the recovered digital source, preserved byte for byte.
- [`originals/archives/`](originals/archives/): historical distribution ZIPs.
- [`originals/manuals/`](originals/manuals/): primary manuals, including the printed RUNUP source listings.
- [`originals/runup2/`](originals/runup2/), [`originals/whafis3/`](originals/whafis3/), and [`originals/champ2/`](originals/champ2/): original programs and supporting data extracted without running them.
- [`recovery/manifest.json`](recovery/manifest.json): original URLs, archive members, sizes, and SHA-256 hashes.
- [`tools/extract_champ_installer.py`](tools/extract_champ_installer.py): static extraction of the recovered CHAMP InstallShield payloads.

FEMA's 2024 RUNUP reconstruction is a separate version, not the source baseline for this effort. Its documentation acknowledges the missing November 1991 digital source and the need to infer intervening changes. Recovering the actual earlier files remains an open task.

## Port direction

Keep the original algorithms, numerical tables, data formats, and CHAMP workflow legible as they become C++. Favor explicit data and straightforward functions, with a small interface around the actual calculations. Preserve original files separately from translations and identify unresolved historical differences instead of silently choosing a replacement.

No C++ port or modern cross-platform build is implemented yet. The first import is recovered source and historical material; the macOS/Linux/Windows build and Dear ImGui interface are the intended destination.

## Attribution

Historical material retains the notices and authorship found in its original distributions and manuals. This repository does not assign a new blanket license to recovered third-party files. The small installer extraction utility credits its format reference and includes that reference project's MIT notice.
