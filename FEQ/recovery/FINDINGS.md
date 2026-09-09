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
