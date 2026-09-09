// Verify inverse-trigonometric kernels against raw original-executable results.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/trigonometry.hpp>
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
    if (!std::cin) { throw std::runtime_error("Incomplete trigonometric fixture."); }
    return static_cast<std::uint32_t>(bytes[0]) | (static_cast<std::uint32_t>(bytes[1]) << 8) |
        (static_cast<std::uint32_t>(bytes[2]) << 16) | (static_cast<std::uint32_t>(bytes[3]) << 24);
}
void write_word(std::uint32_t value) {
    const unsigned char bytes[4] = {static_cast<unsigned char>(value),static_cast<unsigned char>(value >> 8),
        static_cast<unsigned char>(value >> 16),static_cast<unsigned char>(value >> 24)};
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
            const std::uint32_t kind = read_word();
            const float argument = std::bit_cast<float>(read_word());
            if (kind > 1) { throw std::runtime_error("Invalid trigonometric fixture kind."); }
            const double value = kind == 0 ? feq::legacy_arcsine(argument) : feq::legacy_arccosine(argument);
            const std::uint64_t result = std::bit_cast<std::uint64_t>(value);
            write_word(static_cast<std::uint32_t>(result));
            write_word(static_cast<std::uint32_t>(result >> 32));
        }
        return std::cout ? 0 : 1;
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
}
