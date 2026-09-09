# WHAFIS: source versions and binary behavior

The native engine follows the active August 2007 WHAFIS 4.0G source and its
preserved Windows executable. `originals/whafis4/WHAFIS4G.FOR` contains both the
active implementation and an appended, commented WHAFIS 3.0 listing, beginning
near line 4610. The header explicitly identifies the appended listing as change
documentation and identifies the 2007 implementation as partly based on the
special August 2004 Pacific Coast version 3.1.

## Changes from the appended older source

- **500-year cases:** a `:500:` title prefix selects 500-year default winds.
  SCANE's defaults at source lines 3780–3781 are IF/OF/VH = 60/80/60 mph for
  100-year cases and 75/100/75 mph for 500-year cases. The prefix is detected at
  lines 3806–3813. The native parser and CHAMP deck writer retain this convention.
- **User winds:** IE fields 8–10 specify inland, overwater, and vegetation winds.
  Zero selects the scenario default. The active source reads them at lines
  3819–3825 and propagates them through the wind-dependent calculations. The
  appended older code's fixed-wind formulas are not substituted for these paths.
- **Comments and postscripts:** the active FIVEHUNDRED module stores CM and PS
  records, SCANE collects them, and the output includes postscript notes. They
  survive native input parsing and report generation. They are also retained by
  the project's full-deck editor.
- **Windows execution/reporting:** 4.0G accepts input/output paths as command-line
  arguments and uses Compaq DFPORT/DFLIB for file prompts, dates, and runtime
  functions. The C++ implementation uses standard/native file handling and an
  in-memory calculation API. Numerical reports preserve the original text;
  differential tests exclude only the three execution-metadata lines.
- **Marsh defaults:** the original MG.DAT parameters are embedded in the native
  library. Plant selection, interpolation, and weighting follow the active
  source; users need no external scratch files or marsh database to run it.

The source header is evidence for the version lineage, rather than a claim that
all intermediate digital source snapshots were recovered. The 2004 special source
has not been independently recovered as a separate complete development tree.

## Compiler behavior that source translation alone misses

The original x87 control word is `0x027f`, with a 53-bit significand. Some Fortran
REAL quantities remain in wider registers across assignments, while other
operations explicitly store binary32 temporaries. The native FETCH implementation
retains the verified boundaries for averaged depths, drag terms, ratios, and
period powers. The period is squared into a binary32 temporary before its wider
cube; some wind coefficients use constants folded at single precision.

SCANE, intermediate echo/scratch formatting, and report formatting also affect
later arithmetic and output. The port performs the original scratch conversions
in memory. Compaq fixed-field formatting suppresses negative zero when the
printed field rounds entirely to zero; native formatting reproduces that rule.

These details were established by original executable reports and COMMON-state
captures, rather than assuming that a direct Fortran-to-C++ expression rewrite
would produce the same result. The active report suite has 17 full cases and
154,499 compared bytes after excluding only execution metadata. SHBM, T, HM0,
and HIN each have 1,000 raw binary32 reference results. The CHAMP workflow adds
four complete WHAFIS runs with newly generated project inputs.

The larger C++ routines preserve original labels and scalar names so an engineer
can compare them directly with the recovered source. State is owned by each
calculation, arrays are bounded, and the runtime no longer depends on Compaq,
Fortran, Wine, Access, or temporary scratch files. The fixtures establish their
listed cases; additional parameter combinations remain subject to differential
validation through the retained original-binary probes.
