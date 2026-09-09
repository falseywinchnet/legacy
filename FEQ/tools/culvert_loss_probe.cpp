// Direct original-executable fixtures for contraction and head loss.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/culvert_loss.hpp>
#include <bit>
#include <cstdint>
#include <cstring>
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
    if (!std::cin) { throw std::runtime_error("Incomplete culvert-loss fixture."); }
    return static_cast<std::uint32_t>(bytes[0]) | (static_cast<std::uint32_t>(bytes[1]) << 8) |
        (static_cast<std::uint32_t>(bytes[2]) << 16) | (static_cast<std::uint32_t>(bytes[3]) << 24);
}
float read_float() { return std::bit_cast<float>(read_word()); }
void write_word(std::uint32_t word) {
    const unsigned char bytes[4] = {static_cast<unsigned char>(word),static_cast<unsigned char>(word >> 8),
        static_cast<unsigned char>(word >> 16),static_cast<unsigned char>(word >> 24)};
    std::cout.write(reinterpret_cast<const char*>(bytes),4);
}
void write_float(float value) { write_word(std::bit_cast<std::uint32_t>(value)); }
void write_double(double value) {
    const std::uint64_t word = std::bit_cast<std::uint64_t>(value);
    write_word(static_cast<std::uint32_t>(word));
    write_word(static_cast<std::uint32_t>(word >> 32));
}
}
int main(int argc, char** argv) {
#if defined(_WIN32)
    _setmode(_fileno(stdin),_O_BINARY);
    _setmode(_fileno(stdout),_O_BINARY);
#endif
    try {
        const bool coefficient_only = argc == 2 && std::strcmp(argv[1],"--coefficient") == 0;
        while (std::cin.peek() != std::char_traits<char>::eof()) {
            if (coefficient_only) {
                feq::CulvertCoefficientInput input{};
                input.shape = static_cast<feq::CulvertShape>(read_word());
                input.flow_type = static_cast<int>(read_word());
                int flag = std::bit_cast<std::int32_t>(read_word());
                input.upstream_height = read_float();
                input.upstream_level = read_float();
                input.entrance_bed = read_float();
                input.flow = read_float();
                input.critical_flow = read_float();
                input.rounding_factor = read_float();
                input.wing_factor = read_float();
                input.projection_factor = read_float();
                write_double(feq::culvert_discharge_coefficient(input,flag));
                write_word(static_cast<std::uint32_t>(flag));
                continue;
            }
            const float coefficient = read_float();
            const float approach = read_float();
            const float area = read_float();
            const float flow = read_float();
            const float gravity = read_float();
            const double adjusted = feq::culvert_contraction(coefficient,approach,area);
            const float stored = static_cast<float>(adjusted);
            write_double(adjusted);
            write_float(stored);
            write_float(feq::culvert_head_loss(stored,flow,area,gravity));
        }
        return std::cout ? 0 : 1;
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
}
