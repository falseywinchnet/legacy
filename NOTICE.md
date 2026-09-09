# Credits and notices

**Work:** Astra  
**Sponsor:** Rainstar  
**Foundation:** Hashem

The new C++ implementation, interface, and original project tooling are offered under the [MIT License](LICENSE).

Recovered historical files in `originals/` and external research material retain their existing authorship and notices; they are preserved as evidence, not relicensed by this project. Third-party libraries retain their own licenses. `tools/ISx-LICENSE.txt` accompanies the installer-format reference used by the extraction utility.

`third_party/nlohmann/json.hpp` is JSON for Modern C++ version 3.12.0, copyright
Niels Lohmann and contributors, distributed under its adjacent MIT license.

The optional CHAMP research disassembler uses `visualbasic-rs` by ATRAPS LLC,
Apache-2.0 licensed, at commit `a1fd81087e10ac02aea5646219b0bc1a82b5e24c`.
It is not a runtime dependency. The original p-code probe's minimal VB runtime
initialization follows David Zimmer's published [binary reuse research](https://sandsprite.com/blogs/files/Binary%20Reuse%20of%20VB6%20P-Code%20Functions%20-%20Avast%20Threat%20Labs.pdf).
Original VB runtime binaries are used only for research and are not included in
native application packages.

The desktop uses **Dear ImGui 1.92.9b**, copyright Omar Cornut and contributors,
under the MIT License, and **SDL 3.4.16**, copyright Sam Lantinga and contributors,
under the zlib License. Their release archives and SHA-256 checksums are pinned in
`cmake/Desktop.cmake`; their licenses are included in desktop packages.

The **Inter** interface font is copyright the Inter Project Authors and is
provided under the SIL Open Font License 1.1 in `resources/fonts/Inter-OFL.txt`.
It was obtained from the Google Fonts `ofl/inter/Inter[opsz,wght].ttf` distribution.
The example `.coastal` file is a lossless conversion of the original CHAMP sample
project; historical example data retains its original provenance.
