# Legacy — CHAMP, WHAFIS, and RUNUP forward port

Recover the original FEMA **CHAMP 2.0 (Coastal Hazard Analysis Modeling Program)** and its two numerical engines, **WHAFIS** and **RUNUP**, then carry all three forward into clean, legible, modern orthodox C++ with a simple **Dear ImGui** interface.

The intended targets are **macOS, Linux, and Windows**, using **Make/CMake** and **GitHub Actions runners**. CHAMP's project and transect workflow is part of the port, alongside both numerical engines.

**Native implementation is underway.** RUNUP and WHAFIS now run as standalone C++ programs. RUNUP matches 113 complete original reports; WHAFIS matches 15 complete reports after excluding only execution metadata, including all four supplied CHAMP reports. The CHAMP workflow and Dear ImGui application remain in progress. The original executables and recovered source are the behavior baseline; further source hunting is not a prerequisite.

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

For the current development build:

```sh
make test
build/native/runup originals/runup2/test.in result.out
build/native/whafis originals/champ2/w1.dat wave-result.out
```

Both command-line programs have no emulator, Python, Fortran, or original-executable dependency. WHAFIS includes the original marsh-grass defaults and exposes calculated wave points through a C++ library interface. GitHub Actions builds and checks C++ on macOS, Linux, and Windows. Ready-to-run desktop packages will follow the completed interface.

## Attribution

**Work: Astra · Sponsor: Rainstar · Foundation: Hashem.** New implementation and project tooling are [MIT licensed](LICENSE). Preserved historical material and third-party components retain their existing notices; see [credits and notices](NOTICE.md).
