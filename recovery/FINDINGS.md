# Original-source recovery — 8 September 2026

**The major recovery is authentic digital WHAFIS source.** An archived FEMA distribution contains `WHAFIS4G.FOR`, with the 2007 implementation and an embedded older WHAFIS 3.0 listing. Original digital RUNUP and CHAMP development sources remain unfound in the material inspected.

## WHAFIS: recovered digital source

The [FEMA ZIP captured on 2 November 2008](https://web.archive.org/web/20081102135735id_/https://www.fema.gov/library/file?type=publishedFile&file=whafis4.zip&fileid=4a4deea0-51a4-11dc-9950-000bdba87d5b) contains four files: `WHAFIS4G.FOR`, `WHAFIS4.exe`, `MG.DAT`, and `whafis4doc.pdf`. Its preserved copy is [whafis4-2007.zip](../originals/archives/whafis4-2007.zip).

The [source](../originals/whafis4/WHAFIS4G.FOR) is 256,048 bytes and 9,332 lines, including CRLF line endings. SHA-256:

```text
29aa7eb8907344e3b645a73776f74b93a7f63c389d4b3f248a15156eef19acfb
```

The header identifies FEMA WHAFIS 4.0G, August 2007, by David Divoky, Watershed Concepts; it credits the original October 1980 program to David Harty, Dames and Moore, and the subsequent version 3.0 to Greenhorne & O'Mara. This file comes directly from the historical ZIP, not OCR or a recent reconstruction.

After the active 4.0G program, the file appends WHAFIS 3.0 as commented source. That appendix records revisions through May 1989 by Barry E. Herchenroder and Jing Wei and includes the older program and its routines. It is preserved as embedded; no independently recovered standalone 3.0 source file is claimed. The header also identifies a relationship to the August 2004 Pacific Coast PWHAFIS 3.1 branch.

The accompanying 2007 executable is byte-identical to the WHAFIS executable inside the recovered CHAMP 2.0 installer. An [older archived WHAFIS distribution](https://web.archive.org/web/20041119021327id_/http://fema.gov/media/fhm/frm_wfis.zip) separately provides a July 1989 executable, marsh data, and sample input/output. It contains no Fortran source. The [1988 manual](../originals/manuals/WHAFIS3.0_Manual_1988.pdf) also preserves a printed listing in Appendix C, PDF pages 88–179.

## RUNUP: originals recovered, digital-source gap still open

The [FEMA ZIP captured on 18 November 2004](https://web.archive.org/web/20041118144021id_/http://www.fema.gov/media/fhm/frm_run2.zip) contains the 119,691-byte `RUNUP2.EXE`, dated 6 November 1991 in its ZIP entry, plus a batch launcher and sample input/output. The ZIP is preserved as [runup2-1991.zip](../originals/archives/runup2-1991.zip), with its members [extracted here](../originals/runup2/).

The executable's SHA-256 is:

```text
e0e2b2df60b898d831c5321c9d8a09aa6c9add8333d510d88a396f2e3c2239c8
```

It is byte-identical to RUNUP inside both the recovered 2004 and 2007 CHAMP installers, and to the older RUNUP still bundled inside the current CHAMP download. This establishes a consistent recovered binary across packages; it does not establish the source code used to compile it. The standalone ZIP's README is actually a WHAFIS README. That apparent packaging error has been retained, not silently repaired.

Two historical source listings are now local:

| Original document | Listing location | What it establishes |
| --- | --- | --- |
| [Stone & Webster, *Manual for Wave Runup Analysis*, November 1981](../originals/manuals/RUNUP2.0_Manual.pdf) | Appendix A, section A.6; introduction at PDF page 74; source on pages 75–93, printed A-26–A-44 | The original printed program, including numerical tables. FEMA currently serves this under the misleading filename `RUNUP2.0_Manual.pdf`. |
| [Dewberry & Davis, *Investigation and Improvement of Capabilities for the FEMA Wave Runup Model*, April 1991](../originals/manuals/RUNUP2.0_Technical_Documentation_1991.pdf) | Appendix B begins at PDF page 143; source pages 150–187, printed 137–174 | The listing headed March 1990. Its introduction describes DEC VAX 11/750, VAX FORTRAN V5.0, one main program and 17 subroutines, and a PC-compatible form. |

The 1991 introduction says the listing retains superseded 1981 instructions as comments. That is useful lineage, but **the March 1990 listing is not automatically the November 1991 PC source**. The scans are the recovered primary source; local OCR is an unreviewed search aid, not an authenticated Fortran file. Source-page rotation was corrected for OCR of the 1981 listing without changing the original PDF.

FEMA's [2024 supplement](https://hazards.fema.gov/femaportal/docs/RUNUP/Runup_SupplementalDoc_2024.pdf) explicitly says its team lacked digital November 1991 source, transcribed the April 1991 hardcopy, and inferred intervening changes. It names the resulting version 2.1 while retaining the executable filename `Runup2.exe`. It also describes a new interpolation routine and other numerical changes. That supports treating it as a distinct reconstruction. This recovery pass has not established a specific numerical failure in that version and does not use it as the original-source baseline.

## CHAMP: authentic distributions, no VB development project yet

The [FEMA CHAMP ZIP captured on 1 November 2008](https://web.archive.org/web/20081101022843id_/https://www.fema.gov/library/file?type=publishedFile&file=champ_2_setup.zip&fileid=ab66cd30-655c-11dc-9950-000bdba87d5b) contains `setup.exe`, dated 14 September 2007. Its preserved copy is [champ2-2007.zip](../originals/archives/champ2-2007.zip).

Static extraction follows:

```text
ZIP → setup.exe PE overlay → InstallShield payload → CHAMP.msi → Data1.cab
```

The CAB contains 54 files. These include `champ.exe`, `RUNUP2.EXE`, `WHAFIS4.exe`, `sample.mdb`, transect inputs and outputs, manuals, DXF files, and runtime dependencies. No `.vbp`, `.bas`, or `.frm` project/source files were found. The extracted `champ.exe` is 868,352 bytes, SHA-256 `aa94a899e8881298e436164dbdaa35b2c51b3f691225d8a4f50e960cf9602443`.

The [2004 FEMA installer](https://web.archive.org/web/20041118092350id_/http://fema.gov/media/fhm/frm_chmp.zip) was also downloaded and unpacked. It provides an earlier CHAMP application and WHAFIS 3, but no VB project or Fortran source. Both original installers are preserved.

The current FEMA CHAMP ZIP has a different outer installer. Its extracted MSI is byte-identical to the archived 2007 MSI, and all 54 CAB files match. Thus its recent outer packaging date does not date the actual CHAMP application or its numerical engines. The [CHAMP manual](https://hazards.fema.gov/femaportal/docs/CHAMP/CHAMP2.0_Manual.pdf) identifies the program as Visual Basic and documents project, transect, erosion, numerical-engine, plotting, and export workflows. These remain part of the intended C++ port.

## Archive and microfiche work

The search followed historical FEMA download pages and library records through Wayback, inspected actual ZIP and installer contents, searched Internet Archive government and microfiche catalogs, and checked public code search. Broad web hits for unrelated programs named RUNUP or CHAMP were excluded.

A concrete microfiche holding was inspected: [Internet Archive `micro_IA41152602_0213`](https://archive.org/details/micro_IA41152602_0213), *Flood Insurance Study: Wave Height Analysis*, Groton Long Point Association, Connecticut, 17 May 1982. Its public text is a site-specific study, not a program source listing. The associated government microfiche search returned other local wave-height studies, not an identified RUNUP source master. Those search results do not prove the missing code is absent from unindexed holdings.

There is a documented physical-media trail. A [1997 FEMA Federal Register notice](https://www.govinfo.gov/content/pkg/FR-1997-02-06/pdf/97-2964.pdf) separately lists study survey notes on paper/microfiche and computer diskettes/manuals for FEMA Wave Height and Wave Runup programs. The distinction matters: a box of study microfiche is not necessarily a software archive. The old notice establishes distribution media, not current holdings or current retrieval terms.

For RUNUP's numerical tables, the FEMA-hosted originals of Stoa's *Revised Wave Runup Curves for Smooth Slopes* and *Reanalysis of Wave Runup on Structures and Beaches* (both 1978) were also downloaded locally. Their original URLs and hashes are in [acquisitions.json](acquisitions.json). Those larger supporting scans are outside Git; the source-bearing manuals and historical distributions are committed.

## The next unresolved source targets

1. **Dewberry's RUNUP 1990–1991 development/delivery media:** the April 1991 report identifies Dewberry & Davis and explicitly describes both VAX and PC forms. The high-value missing item is the final PC Fortran source or a backup/change set between the printed March 1990 listing and the November 1991 executable. VAX source, compiler command files, and disk/tape images could also close part of that gap.
2. **CHAMP 2.0 contractor deliverables:** original Visual Basic project/form/module files, resource files, and build material for the September 2007 application. Installer copies and user manuals alone cannot supply these.
3. **FEMA engineering-library/software distribution holdings:** original diskette images and delivery packages, distinguishing them from study input/output microfiche. The 1997 notice gives a concrete historical distribution trail, but holdings need confirmation.
4. **Independent WHAFIS snapshots:** the recovered 4.0G file is already usable as original source. Separate 3.0 and PWHAFIS 3.1 development media could further clarify lineage without blocking work on 4.0G.

No messages or records requests have been sent to people or organizations. No repository found in this pass supplies the missing CHAMP/RUNUP original development files. Further custody research remains open; the recovery of all three is not being marked complete.

## Reproducing the extraction

Original download URLs, member paths, byte counts, and hashes are in [manifest.json](manifest.json). Archives and imported source retain their original bytes. Scratch downloads, unpacked runtime duplicates, and unreviewed OCR remain local and ignored by Git.

For CHAMP, unzip the historical distribution, then run:

```sh
python3 tools/extract_champ_installer.py /path/to/setup.exe /path/to/payload
7zz x /path/to/payload/CHAMP.msi -o/path/to/msi
7zz x /path/to/msi/Data1.cab -o/path/to/files
```

The Python helper handles the observed InstallShield format; it does not execute the legacy programs. Its format reference and notice are included beside it. All source work in this import is recovery; no C++ translation, GUI, certification framework, or platform build has been substituted for the source search.
