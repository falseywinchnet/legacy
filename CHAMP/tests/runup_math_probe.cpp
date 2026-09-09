// SPDX-License-Identifier: MIT
#include "legacy/runup_math.hpp"
#include <array>
#include <bit>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char** argv) {
    if (argc != 4) return 2;
    std::ifstream input(argv[2], std::ios::binary);
    std::ofstream output(argv[3], std::ios::binary);
    if (!input || !output) return 2;
    const std::string routine(argv[1]);
    std::vector<std::uint32_t> words(routine == "LOOK" ? 15 : 6);
    while (input.read(reinterpret_cast<char*>(words.data()), words.size() * sizeof(words[0]))) {
        std::vector<std::int32_t> integers(words.size());
        std::vector<float> reals(words.size());
        for (std::size_t i = 0; i < words.size(); ++i) {
            integers[i] = std::bit_cast<std::int32_t>(words[i]);
            reals[i] = std::bit_cast<float>(words[i]);
        }
        std::uint32_t result;
        using namespace legacy::runup;
        if (routine == "LOOK") {
            const auto found = bracket(std::span(integers.data(), integers[10]), integers[11]);
            const std::array<std::int32_t, 3> result{found.lower, found.upper, found.outside ? 1 : integers[14]};
            output.write(reinterpret_cast<const char*>(result.data()), sizeof(result));
            continue;
        } else if (routine == "DBPLOT") {
            result = std::bit_cast<std::uint32_t>(breaking_depth(reals[0], reals[1], reals[2]));
        } else if (routine == "RINT") {
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
