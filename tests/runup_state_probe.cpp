// SPDX-License-Identifier: MIT
#include "../src/runup/calculation.hpp"
#include <array>
#include <bit>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <vector>

int main(int argc, char** argv) {
    try {
        if (argc != 5) return 2;
        std::ifstream in(argv[1], std::ios::binary);
        std::vector<unsigned char> data{std::istreambuf_iterator<char>(in), {}};
        const auto word = [&](int offset) {
            return static_cast<std::uint32_t>(data.at(offset)) |
                (static_cast<std::uint32_t>(data.at(offset + 1)) << 8) |
                (static_cast<std::uint32_t>(data.at(offset + 2)) << 16) |
                (static_cast<std::uint32_t>(data.at(offset + 3)) << 24);
        };
        const auto real = [&](int offset) { return std::bit_cast<float>(word(offset)); };
        legacy::runup::detail::Calculation c;
        c.NP = word(0x1d40); c.MAXPTS = word(0x1794);
        c.WTB = std::stof(argv[2]); c.H0 = std::stof(argv[3]); c.T = std::stof(argv[4]);
        c.WTL = 0;
        for (int i = 1; i <= 20; ++i) {
            const int a = (i - 1) * 4;
            c.DEP[i] = static_cast<int>(static_cast<double>(std::bit_cast<std::int32_t>(word(0x1bb0 + a))) - static_cast<float>(static_cast<double>(c.WTB)*100.0));
            c.DL[i] = std::bit_cast<std::int32_t>(word(0x1c00 + a));
            c.S[i] = real(0x1c50 + a); c.ROUGH[i] = real(0x1cf0 + a);
            c.RDL[i] = real(0x1798 + a); c.RDEPP[i] = real(0x1974 + a) - c.WTB*100.0f;
            c.HORIZ[i] = real(0x16f0 + a); c.VERT[i] = real(0x1740 + a);
        }
        c.run();
        std::cout << std::setprecision(12);
#define SHOW(name) std::cout << #name << " " << c.name << '\n'
        SHOW(result); SHOW(iterations); SHOW(II); SHOW(ending_slope); SHOW(breaker_depth);
        SHOW(DC); SHOW(DLE); SHOW(R); SHOW(R1); SHOW(DCS); SHOW(DS); SHOW(DS1);
        SHOW(RDSL); SHOW(RDTR); SHOW(SA); SHOW(MWST); SHOW(HST); SHOW(HSA);
        SHOW(approach_depth); SHOW(approach_length); SHOW(DXLA); SHOW(DXLA1); SHOW(CS);
        for (const auto& t : c.curve_trace) std::cout << "curve " << t.slope << ' ' << t.depth << ' '
            << t.ratio << ' ' << t.raw_runup << ' ' << t.runup_station << ' ' << t.runup_elevation << '\n';
    } catch (const std::exception& e) { std::cerr << e.what() << '\n'; return 1; }
}
