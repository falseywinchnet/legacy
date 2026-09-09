// Direct original-executable fixtures for type-2, -3, and -4 tables.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/table_interpolation.hpp>
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
        throw std::runtime_error("Incomplete function-table fixture.");
    }
    return static_cast<std::uint32_t>(bytes[0]) | (static_cast<std::uint32_t>(bytes[1]) << 8) |
        (static_cast<std::uint32_t>(bytes[2]) << 16) | (static_cast<std::uint32_t>(bytes[3]) << 24);
}
float read_float() { return std::bit_cast<float>(read_word()); }
feq::FunctionTableRow read_row() {
    feq::FunctionTableRow row{};
    row.argument = read_float();
    row.value = read_float();
    row.derivative = read_float();
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
            const std::uint32_t method = read_word();
            const float argument = read_float();
            const feq::FunctionTableRow lower = read_row();
            const feq::FunctionTableRow upper = read_row();
            const feq::FunctionTableResult result = feq::interpolate_function_table(
                static_cast<feq::TableInterpolation>(method),argument,lower,upper);
            write_float(result.value);
            write_float(result.derivative);
        }
        return std::cout ? 0 : 1;
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
}
