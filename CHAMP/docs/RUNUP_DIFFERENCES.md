# RUNUP: differences established from the original executable

Baseline binary: November 6, 1991 `RUNUP2.EXE`, SHA-256 `e0e2b2df60b898d831c5321c9d8a09aa6c9add8333d510d88a396f2e3c2239c8`. Addresses below are load-relative code addresses, as printed by `tools/disassemble_runup.py`.

Printed comparison: March 1990 listing in the April 1991 report. Page numbers here refer to the preserved 188-page [archived scan](../originals/manuals/RUNUP_Technical_Documentation_1991_archived2009.pdf).

## Breaking-depth curves

The printed DBPLOT on PDF pages 178–179 rejects wave steepness above 0.05. The executable compares against the binary32 constant **0.07** at `0000:3255`. This is direct instruction/constant evidence, not an inference from a selected result.

The executable also contains revised logarithmic curve coefficients and high-steepness caps. For example, the mild-slope branch at `0000:3332` uses x-origin `-1.2218`, y-origin `-0.7842`, folded ordinate difference `-0.40220001339912415`, and folded abscissa difference `1.3011001348495483`. It caps that branch above 0.06. The intermediate branches contain further changes, including 0.055 and 0.045 caps; the steepest branch retains a 0.025 cap. The exact constants and their storage precision are carried into `breaking_depth` in `src/runup/math.cpp`.

One thousand valid original DBPLOT calls, covering the slope branches and high-steepness region, match the C++ result bytes exactly on the initial macOS comparison. This does not establish every possible input or error path.

## Signed elevations and additional profile coordinates

The printed input routine at PDF page 154 uses:

```fortran
DEP(J)=NINT(RDEP(J)*100.)+ SIGN(1.0,RDEP(J))
```

The executable at `0000:046a` calls `__FInint` after multiplication by 100, then **adds +1 unconditionally**, rather than using the sign of the elevation. For example, the original sample's -16.7-foot elevation becomes integer -1669, not -1671. This is confirmed by a data-memory capture after the original INPUT routine, using `tools/capture_runup_state.py`.

The executable additionally maintains the REAL*4 array `RDEPP` at data offset `0x1974`, calculated as the unrounded input elevation times 100 plus 1. Its synthetic final point adds **1000** to this real coordinate, while the integer DEP final point adds **10000**. The sample's final real station is 141, while its last supplied station is 131. Later geometry uses additional real coordinates `RDTR` and `RDSL`; the native geometry follows these executable coordinates and is checked by the complete-report and intermediate-state fixtures. They should not be replaced with the older integer-coordinate formulas without inspecting the executable.

## Arithmetic and execution environment

LOGLOG and LOGLIN store logarithms and slopes as REAL*4 and truncate the final result to INTEGER*4. This is retained from the older implementation rather than a newly discovered change. Direct probing gives 499 for LOGLOG(10,100,100,1000,50), demonstrating why idealized mathematical results cannot replace the compiled operation sequence.

The binary includes Microsoft's floating-point emulation library. DOSBox-X with `fpu=false` reproduces the archived sample output byte for byte. With its coprocessor enabled, the same executable prints one slope as 6.87 rather than the archived 6.88; captured software-path slope storage is exactly 6.875. Report formatting and floating-point execution mode therefore require explicit treatment.

This is a growing list of established differences, not an exhaustive comparison of the full programs.
## Additional executable findings from the complete calculation

- The executable's RUN `I2` and SIMPCOMP1 `I3` blending weights are INTEGER*4. Their intermediate fractional values truncate before blending. The printed listing declares these weights real.
- RUN's source line 579 uses `J-A+1` for the approach toe, where the scanned listing shows `I-A+1`. Label 503 tests `A == I`, not `A == 1`.
- The exact-vertex geometry branch reads a distinct local `HOSCALE` (letter O), which remains zero, while the other branch reads common-block `H0SCALE` (zero). The disassembly distinguishes the addresses.
- `__FHfexp` uses `FYL2X` and the software `F2XM1` path. The integer logarithmic interpolation result can lie immediately below an exact power of ten. Direct probes give 9 for constant ordinates of 10 and 999 for 1,000; native `std::pow` alone changes complete RUNUP results.
- The original formatter suppresses leading zeroes in fractional fixed-point fields. Empty portions of its static page heading contain NUL bytes. The compatibility report preserves both.
- Half-decimal ties are rounded away from zero: a binary32 result of 1.125 prints as 1.13. Ordinary C++ stream rounding printed 1.12 and changed a varied-profile report.
- A 20-point input needs a 21st synthetic point, but the original COMMON arrays have only 20 slots. Its extension overwrites the first integer station and first slope. This can stop the original during arithmetic before the first output row. C++ reproduces those observed byte effects explicitly, without an out-of-bounds access, and reports the numerical failure to the caller.
