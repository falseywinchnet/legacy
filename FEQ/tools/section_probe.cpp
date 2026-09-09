// Direct original-executable fixture driver for section interpolation.
#include <feq/section_interpolation.hpp>
#include <bit>
#include <cstdint>
#include <iostream>
#include <stdexcept>
#if defined(_WIN32)
#include <fcntl.h>
#include <io.h>
#include <cstdio>
#endif

namespace {
std::uint32_t read_word() {
    unsigned char bytes[4]{};
    std::cin.read(reinterpret_cast<char*>(bytes),4);
    if (!std::cin) {
        throw std::runtime_error("Incomplete section fixture.");
    }
    return static_cast<std::uint32_t>(bytes[0]) | (static_cast<std::uint32_t>(bytes[1]) << 8) |
        (static_cast<std::uint32_t>(bytes[2]) << 16) | (static_cast<std::uint32_t>(bytes[3]) << 24);
}
float read_float() { return std::bit_cast<float>(read_word()); }
feq::SectionTableRow read_row() {
    feq::SectionTableRow row{};
    row.depth = read_float();
    row.top_width = read_float();
    row.area = read_float();
    row.sqrt_conveyance = read_float();
    row.momentum_factor = read_float();
    row.sqrt_conveyance_slope = read_float();
    row.momentum_factor_slope = read_float();
    return row;
}
void write_float(float value) {
    const std::uint32_t word = std::bit_cast<std::uint32_t>(value);
    const unsigned char bytes[4] = {static_cast<unsigned char>(word),static_cast<unsigned char>(word >> 8),
        static_cast<unsigned char>(word >> 16),static_cast<unsigned char>(word >> 24)};
    std::cout.write(reinterpret_cast<const char*>(bytes),4);
}
}

int main() {
#if defined(_WIN32)
    _setmode(_fileno(stdin),_O_BINARY);
    _setmode(_fileno(stdout),_O_BINARY);
#endif
    try {
        while (std::cin.peek() != std::char_traits<char>::eof()) {
            const std::uint32_t mode = read_word();
            if (mode > 1) {
                throw std::runtime_error("Invalid section fixture interpolation mode.");
            }
            const float depth = read_float();
            const feq::SectionTableRow lower = read_row();
            const feq::SectionTableRow upper = read_row();
            const feq::SectionProperties result = feq::interpolate_section(depth,lower,upper,mode != 0);
            write_float(result.area);
            write_float(result.top_width);
            write_float(result.top_width_slope);
            write_float(result.conveyance);
            write_float(result.conveyance_slope);
            write_float(result.momentum_factor);
            write_float(result.momentum_factor_slope);
        }
        return std::cout ? 0 : 1;
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
}
