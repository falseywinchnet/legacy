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

The initial C++ implementations of LOOK, RINT, SWLINT, LOGLIN, and LOGLOG are in `src/runup/math.cpp`. The five lookup/interpolation routines and DBPLOT each have 1,000 raw original-reference cases, including interval endpoints and zero-width linear intervals. These are useful differential checks, not a claim of complete numerical equivalence or full program completion. LOOK is compared against original lower/upper index and flag results.

C++ arithmetic uses explicit single-precision storage points, wider expression intermediates, and disabled floating-point contraction. Further routine and whole-program checks will determine where the original software floating-point implementation needs closer reproduction.

`tools/disassemble_runup.py` decodes the application's Microsoft `INT 34h–3Dh` floating-point traps along with x86 instructions and annotates the original source-line mappings. Reading these bytes as ordinary instructions alone produces misleading disassembly. Its optional research dependency is Capstone 5.

## Work still required

- Complete RUNUP's profile parsing, wave-breaking, structure classification, curve selection, roughness, convergence, reports, and error behavior; compare each against the original binary and the earlier printed source.
- Translate all active WHAFIS 4.0G computational and input/output paths from the recovered source; verify against the original Windows executable, including marsh data and 500-year behavior.
- Recover CHAMP's p-code logic and file/database formats, then implement its project, transect, erosion, wave-setup, plotting, and export workflows.
- Complete the Dear ImGui application, bundled examples, file dialogs, useful errors, and installable packages so ordinary users need no development tools or knowledge of this recovery work.
- Verify the completed applications on macOS, Linux, and Windows and publish the corresponding artifacts.

The first four-routine build passed GitHub Actions on macOS, Linux, and Windows at commit `600adb2`. The subsequent LOOK and DBPLOT additions pass locally; their cross-platform results must be checked after the next push.

Confirmed changes between the printed listing and executable are recorded in [RUNUP historical differences](RUNUP_DIFFERENCES.md).
