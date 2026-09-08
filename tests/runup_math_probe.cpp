// SPDX-License-Identifier: MIT
#include "legacy/runup_math.hpp"
#include <array>
#include <bit>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char** argv) {
    if (argc != 4) return 2;
    std::ifstream input(argv[2], std::ios::binary);
    std::ofstream output(argv[3], std::ios::binary);
    if (!input || !output) return 2;
    std::array<std::uint32_t, 6> words{};
    while (input.read(reinterpret_cast<char*>(words.data()), sizeof(words))) {
        std::array<std::int32_t, 6> integers{};
        std::array<float, 6> reals{};
        for (std::size_t i = 0; i < words.size(); ++i) {
            integers[i] = std::bit_cast<std::int32_t>(words[i]);
            reals[i] = std::bit_cast<float>(words[i]);
        }
        const std::string routine(argv[1]);
        std::uint32_t result;
        using namespace legacy::runup;
        if (routine == "RINT") {
            result = std::bit_cast<std::uint32_t>(linear_integer(integers[0], integers[1], integers[2], integers[3], integers[4]));
        } else if (routine == "LOGLIN") {
            result = std::bit_cast<std::uint32_t>(log_linear(integers[0], integers[1], integers[2], integers[3], integers[4]));
        } else if (routine == "LOGLOG") {
            result = std::bit_cast<std::uint32_t>(log_log(integers[0], integers[1], integers[2], integers[3], integers[4]));
        } else if (routine == "SWLINT") {
            result = std::bit_cast<std::uint32_t>(linear_real(reals[0], reals[1], reals[2], reals[3], reals[4]));
        } else return 2;
        output.write(reinterpret_cast<const char*>(&result), sizeof(result));
    }
    return input.gcount() == 0 && output ? 0 : 2;
}
