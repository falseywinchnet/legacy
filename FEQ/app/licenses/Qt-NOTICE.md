# Qt in FEQ Workbench

FEQ Workbench uses the Qt 6.11.2 Core, GUI, Widgets and Concurrent libraries,
platform plugins, and their dependencies. Depending on the platform, the
installation also includes Qt DBus, SVG, and Wayland support.

Qt is copyright The Qt Company Ltd. and other contributors. These Qt libraries
are distributed under the GNU Lesser General Public License, version 3. Their
use in this application is covered by that license. Qt and its contributors'
work is not relicensed under FEQ's MIT license.

The `notices` directory contains the LGPL-3.0 and GPL-3.0 license texts, Qt's
other license files, third-party notices, and attribution records from the
unchanged Qt sources. The `sources` directory contains the complete matching
Qt Base, Qt SVG and Qt Wayland source archives. `sources.json` records their
upstream download addresses and SHA-256 checksums. Not every component in those
source archives is linked into this application.

Qt is linked dynamically. You may replace its shared libraries with compatible
modified versions, and may modify or reverse engineer this application to debug
those modifications. This project adds no restriction on those activities.
On macOS, changing a framework invalidates its signature; sign the modified
bundle locally or rebuild it using the CMake instructions in the FEQ source.
The application and its build instructions are available at:
https://github.com/falseywinchnet/legacy/tree/main/FEQ

General Qt licensing information: https://doc.qt.io/qt-6/lgpl.html
