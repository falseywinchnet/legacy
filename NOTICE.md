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
