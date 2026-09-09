// Verify real and double powers against raw original-executable results.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/power.hpp>
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
    if (!std::cin) { throw std::runtime_error("Incomplete power fixture."); }
    return static_cast<std::uint32_t>(bytes[0]) | (static_cast<std::uint32_t>(bytes[1]) << 8) |
        (static_cast<std::uint32_t>(bytes[2]) << 16) | (static_cast<std::uint32_t>(bytes[3]) << 24);
}
double read_double() {
    const std::uint64_t low = read_word();
    const std::uint64_t high = read_word();
    return std::bit_cast<double>(low | (high << 32));
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
            const std::uint32_t reserved = read_word();
            const double base = read_double();
            const double exponent = read_double();
            if (kind > 1 || reserved != 0) { throw std::runtime_error("Invalid power fixture kind."); }
            if (kind == 0) {
                write_word(std::bit_cast<std::uint32_t>(feq::legacy_power(static_cast<float>(base),static_cast<float>(exponent))));
                write_word(0);
            } else {
                const std::uint64_t result = std::bit_cast<std::uint64_t>(feq::legacy_power(base,exponent));
                write_word(static_cast<std::uint32_t>(result));
                write_word(static_cast<std::uint32_t>(result >> 32));
            }
        }
        return std::cout ? 0 : 1;
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
}
