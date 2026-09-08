# Implementation and binary fidelity

The destination is a complete native C++ implementation of RUNUP, WHAFIS, and CHAMP's project/transect workflow, with a simple Dear ImGui desktop application and ready-to-run macOS, Linux, and Windows packages. Source recovery is no longer a prerequisite. No staff requests or human-mediated archives will be pursued.

## Reference engines

The original November 1991 RUNUP executes under DOSBox-X 2026.08.31 on an Apple Silicon Mac. With `cpu core=normal` and `cpu fpu=false`, its output for the distribution's `test.in` matches the supplied `test.out` byte for byte (3,357 bytes, SHA-256 `886fd925686b8c3ba4d73aa02501eee69cef574a9b25f91903ff9be0a112d891`). The original Microsoft software floating-point emulator is active in this configuration.

Enabling the emulated coprocessor changes one profile slope's printed rounding from 6.88 to 6.87 in that same case. The numerical result rows are unchanged in that observed case. Both are executions of the same historical binary; the software path is the current reference because it reproduces the archived output exactly. Neither path should be silently mixed with the other when generating comparison data.

The original WHAFIS 4.0G Windows executable also executes through Wine 11.4 in an isolated prefix. A complete output was obtained for CHAMP's `w1.dat`. WHAFIS outputs include execution time and absolute input/output paths, which must be separated explicitly from numerical comparison.

Reproduce an original RUNUP output:

```sh
python3 tools/run_original.py runup originals/runup2/test.in build/reference.out
```

`--coprocessor` selects the alternate coprocessor execution path. All reference runs use temporary working copies; preserved originals are unchanged. The emulator and Wine are development tools, not dependencies intended for the final C++ application.

## Direct binary routine probes

`tools/probe_runup_routines.py` installs a tiny DOS driver into the main-program space of a **temporary copy** of RUNUP. The original executable startup, numerical routines, math runtime, and relocation records remain in place. It reads fixed-size binary records, calls the actual original routine, and writes raw result bytes. That avoids decimal report formatting concealing differences.

```sh
python3 tools/probe_runup_routines.py LOGLOG 10 100 100 1000 50
```

The original result is **499**, despite the idealized mathematical interpolation giving 500. Stored single-precision logarithms and truncation to an integer account for this case. Replacing the routine with a mathematically neater formula would change the program.

The C++ implementations of LOOK, RINT, SWLINT, LOGLIN, LOGLOG, and DBPLOT are in `src/runup/math.cpp`. There are 6,209 raw original-reference cases, including interval endpoints, zero-width linear intervals, constant logarithmic ordinates, and all nine positive INTEGER*4 decades. These are differential checks, not a proof of complete numerical equivalence. LOOK is compared against original lower/upper index and flag results.

C++ arithmetic uses explicit single-precision storage points, wider expression intermediates, and disabled floating-point contraction. Further routine and whole-program checks will determine where the original software floating-point implementation needs closer reproduction.

`tools/disassemble_runup.py` decodes the application's Microsoft `INT 34h–3Dh` floating-point traps along with x86 instructions and annotates the original source-line mappings. Reading these bytes as ordinary instructions alone produces misleading disassembly. Its optional research dependency is Capstone 5.

## Complete-report milestone

The `runup` executable reads the original fixed-column files and produces original-format reports without an emulator or historical runtime. Its five supplied reference cases contain 44 wave calculations and 17,633 report bytes. These have passed byte-for-byte comparison on macOS, Linux, and Windows. The current expanded suite contains 113 complete reference files, including 80 deterministic varied profiles, structure/approach/berm cases, varying roughness and water levels, nonconvergence, steepness errors, arithmetic stops, a 20-point boundary case, and a five-profile input. Formatting preserves missing leading zeroes, NUL bytes in historical headings, carriage returns, and page controls.

The first published wave also matches captured original intermediate values, including its four convergence iterations, structure and approach geometry, breaking station, effective slope, and final raw binary32 runup. The snapshot probe can stop at input, wave, and curve boundaries, including a selected repeated curve visit, to locate discrepancies before formatting.

The native geometry and curve code is in `src/runup/calculation.cpp` and `src/runup/curves.cpp`. Original variable names are retained inside the calculation record to make comparisons with original debug symbols reviewable; the public interface uses profile, wave, and result records. Table constants are generated reproducibly from the recovered binary data.

## Work still required

- Continue RUNUP boundary review while integrating the desktop application. The current fixtures cover normal results, nonconvergence, reflection notes, model steepness limits, multiple profiles, and observed arithmetic stops. Malformed-input UX must remain clear, and new discrepancies must become reproducible tests.
- Translate all active WHAFIS 4.0G computational and input/output paths from the recovered source; verify against the original Windows executable, including marsh data and 500-year behavior.
- Recover CHAMP's p-code logic and file/database formats, then implement its project, transect, erosion, wave-setup, plotting, and export workflows.
- Complete the Dear ImGui application, bundled examples, file dialogs, useful errors, and installable packages so ordinary users need no development tools or knowledge of this recovery work.
- Verify the completed applications on macOS, Linux, and Windows and publish the corresponding artifacts.

The complete model and first 26 report fixtures passed GitHub Actions on macOS, Linux, and Windows at commit `11df6f3`. The subsequent 80-profile and boundary additions pass locally; their cross-platform results must be checked after the next push. Address, undefined-behavior, and float-to-integer sanitizers passed the first complete model suite; the expanded final suite is rerun before its commit.

Confirmed changes between the printed listing and executable are recorded in [RUNUP historical differences](RUNUP_DIFFERENCES.md).
