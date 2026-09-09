// Direct original-executable fixtures for conduit boundary.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/conduit_boundary.hpp>
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
        throw std::runtime_error("Incomplete conduit boundary fixture.");
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
            const std::uint32_t kind = read_word();
            const std::uint32_t sides = read_word();
            const float rise = std::bit_cast<float>(read_word());
            const float span = std::bit_cast<float>(read_word());
            feq::ConduitPlacement placement{};
            placement.slot_width = std::bit_cast<float>(read_word());
            placement.slot_height = std::bit_cast<float>(read_word());
            placement.x_offset = std::bit_cast<float>(read_word());
            placement.y_offset = std::bit_cast<float>(read_word());
            const std::uint32_t count = read_word();
            if (count > 10000) { throw std::runtime_error("Invalid conduit fixture extent."); }
            std::vector<float> x(count); std::vector<float> y(count);
            for (std::size_t index = 0; index < count; ++index) { x[index] = std::bit_cast<float>(read_word()); }
            for (std::size_t index = 0; index < count; ++index) { y[index] = std::bit_cast<float>(read_word()); }
            feq::ConduitBoundary boundary;
            if (kind == 0) { boundary = feq::ellipse_quadrant(rise,span); }
            else if (kind == 1) { boundary = feq::circular_boundary(sides,rise,placement); }
            else if (kind == 2) { boundary = feq::box_boundary(rise,span,placement); }
            else if (kind == 3) { boundary = feq::right_half_boundary(x,y,placement); }
            else if (kind == 4) { boundary = feq::quadrant_boundary(x,y,placement); }
            else { throw std::runtime_error("Invalid conduit fixture routine."); }
            write_word(static_cast<std::uint32_t>(boundary.x.size()));
            for (std::size_t index = 0; index < boundary.x.size(); ++index) { write_float(boundary.x[index]); }
            for (std::size_t index = 0; index < boundary.y.size(); ++index) { write_float(boundary.y[index]); }
        }
        return std::cout ? 0 : 1;
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
}
