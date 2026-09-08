# Original numerical routine records

Each `.input.bin` contains 1,000 little-endian records of six 32-bit words: X1, X2, Y1, Y2, X, and initial Y. SWLINT uses IEEE binary32; the other routines use signed integers. The `.expected.bin` file contains the corresponding 1,000 four-byte results produced by the original November 1991 routine through `tools/probe_runup_routines.py`, with DOSBox-X 2026.08.31 and `fpu=false`.

The original mathematical routines and runtime execute unchanged. Only a temporary main-program driver is replaced to supply and capture values. The original executable SHA-256 is `e0e2b2df60b898d831c5321c9d8a09aa6c9add8333d510d88a396f2e3c2239c8`.

Cases cover interior points, endpoints, signed linear ordinates, positive logarithmic ordinates, and zero-width linear intervals. The recorded inputs are the complete reproducible case definition. They are regression evidence, not a proof that all possible inputs or full model paths have been checked.
