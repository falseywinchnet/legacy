// Direct original-executable fixtures for elevation argument.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/elevation_arguments.hpp>
#include <bit>
#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <vector>
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
        throw std::runtime_error("Incomplete elevation argument fixture.");
    }
    return static_cast<std::uint32_t>(bytes[0]) | (static_cast<std::uint32_t>(bytes[1]) << 8) |
        (static_cast<std::uint32_t>(bytes[2]) << 16) | (static_cast<std::uint32_t>(bytes[3]) << 24);
}
void write_word(std::uint32_t word) {
    const unsigned char bytes[4] = {static_cast<unsigned char>(word),static_cast<unsigned char>(word >> 8),
        static_cast<unsigned char>(word >> 16),static_cast<unsigned char>(word >> 24)};
    std::cout.write(reinterpret_cast<const char*>(bytes),4);
 }
void write_float(float value) { write_word(std::bit_cast<std::uint32_t>(value)); }

}

int main() {
#if defined(_WIN32)
    _setmode(_fileno(stdin),_O_BINARY);
    _setmode(_fileno(stdout),_O_BINARY);
#endif
    try {
        while (std::cin.peek() != std::char_traits<char>::eof()) {
            const std::uint32_t count = read_word();
            const std::uint32_t capacity = read_word();
            const float near_zero = std::bit_cast<float>(read_word());
            const float maximum_step = std::bit_cast<float>(read_word());
            const bool added = read_word() != 0;
            if (capacity > 10000 || count > capacity) { throw std::runtime_error("Invalid elevation fixture extent."); }
            std::vector<float> elevations(capacity);
            for (std::uint32_t index = 0; index < capacity; ++index) {
                elevations[index] = std::bit_cast<float>(read_word());
            }
            const feq::ElevationArguments result = feq::elevation_arguments(elevations,count,near_zero,maximum_step,added);
            write_word(static_cast<std::uint32_t>(result.count));
            for (std::uint32_t index = 0; index < capacity; ++index) { write_float(elevations[index]); }
            std::cerr << result.exhausted << '\n';
        }
        return std::cout ? 0 : 1;
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
}
