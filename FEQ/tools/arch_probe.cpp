// Direct original-executable fixtures for pipe-arch.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/arch_perimeter.hpp>
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
        throw std::runtime_error("Incomplete pipe-arch fixture.");
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
            const float conversion = std::bit_cast<float>(read_word());
            const float rise = std::bit_cast<float>(read_word());
            const float span = std::bit_cast<float>(read_word());
            if (count > 10000) { throw std::runtime_error("Invalid arch fixture extent."); }
            std::vector<feq::ArchStandardRow> rows(count);
            for (std::uint32_t index = 0; index < count; ++index) {
                rows[index].rise = std::bit_cast<float>(read_word());
                rows[index].span = std::bit_cast<float>(read_word());
                rows[index].bottom_radius = std::bit_cast<float>(read_word());
                rows[index].corner_radius = std::bit_cast<float>(read_word());
            }
            const feq::ArchPerimeter result = feq::arch_perimeter(rows,conversion,rise,span);
            const bool failed = result.error != feq::ArchInputError::none;
            write_float(result.rise); write_float(result.span); write_word(failed ? 1 : 0); write_word(failed ? 0 : 23);
            write_float(failed ? 9002.0F : result.invert_offset);
            for (std::size_t index = 0; index < 23; ++index) { write_float(failed ? 9000.0F : result.x[index]); }
            for (std::size_t index = 0; index < 23; ++index) { write_float(failed ? 9001.0F : result.y[index]); }
        }
        return std::cout ? 0 : 1;
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
}
