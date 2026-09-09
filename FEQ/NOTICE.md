# Credits and historical notices

**Work: Astra · Sponsor: Rainstar · Foundation: Hashem.**

The [MIT license](LICENSE) applies to original project contributions. It does not
relicense downloaded historical programs, their source, manuals, example data,
third-party libraries, or mechanically translated historical source.

FEQ and FEQUTL were developed by Delbert D. Franz of Linsley, Kraeger Associates,
Ltd., and documented with Charles S. Melching of the U.S. Geological Survey.
The USGS distributes the preserved releases and publications. Original headers,
authorship statements, disclaimers, and notices remain in their original files.
This project does not imply USGS approval or endorsement.

Both main Fortran source files contain the sentence, “This program is not to be
sold in any form modified or otherwise.” That notice is preserved. An MIT notice
on this project's new work does not erase or resolve the terms attached to
historical code. Any translated reference code retains its historical notices;
the project does not assert that the recovered distribution has an MIT license.

Wine, native Fortran compiler builds, and source-to-source translation probes are
development tools used to investigate behavior. The native application builds
from the checked-in C++ in `engines/`, including translated historical source
that retains its original notices. It requires none of those development tools.

The statically linked record I/O support in `engines/runtime/` derives from
Netlib libf2c. Its AT&T, Lucent Technologies and Bellcore permission and warranty
notice is preserved in `engines/runtime/NOTICE.txt` and installed with the
programs. New compatibility changes do not replace that notice.
