// Direct original-executable fixture driver for section interpolation.
#include <feq/section_interpolation.hpp>
#include <bit>
#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <string>
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
void write_double(double value) {
    const std::uint64_t word = std::bit_cast<std::uint64_t>(value);
    unsigned char bytes[8]{};
    for (unsigned int index = 0; index < 8; ++index) {
        bytes[index] = static_cast<unsigned char>(word >> (8*index));
    }
    std::cout.write(reinterpret_cast<const char*>(bytes),8);
}
}

int main(int argc, char** argv) {
#if defined(_WIN32)
    _setmode(_fileno(stdin),_O_BINARY);
    _setmode(_fileno(stdout),_O_BINARY);
#endif
    try {
        const bool with_moment = argc == 2 && std::string(argv[1]) == "--first-moment";
        const bool station_mode = argc == 2 && std::string(argv[1]) == "--station";
        const bool conveyance_mode = argc == 2 && std::string(argv[1]) == "--scalar-conveyance";
        if (argc != 1 && !with_moment && !station_mode && !conveyance_mode) {
            throw std::runtime_error("Use no arguments, --first-moment, --station, or --scalar-conveyance.");
        }
        while (std::cin.peek() != std::char_traits<char>::eof()) {
            if (conveyance_mode) {
                // The original fixtures exercise all accepted section table types.
                // Their selected intervals use the same scalar arithmetic.
                static_cast<void>(read_word());
                float fields[5]{};
                for (int i = 0; i < 5; ++i) { fields[i] = read_float(); }
                write_float(feq::interpolate_scalar_conveyance(fields[0],fields[1],fields[2],fields[3],fields[4]));
                continue;
            }
            if (station_mode) {
                const float left = read_float();
                const float right = read_float();
                const float station = read_float();
                write_double(feq::section_station_fraction(left,right,station));
                continue;
            }
            const std::uint32_t mode = read_word();
            if (mode > 1) {
                throw std::runtime_error("Invalid section fixture interpolation mode.");
            }
            const float depth = read_float();
            const feq::SectionTableRow lower = read_row();
            const feq::SectionTableRow upper = read_row();
            const float lower_moment = with_moment ? read_float() : 0.0f;
            if (with_moment) {
                // Retain the complete upper table row in the fixture even
                // though this integral uses only the lower first moment.
                static_cast<void>(read_float());
            }
            const feq::SectionProperties result = feq::interpolate_section(depth,lower,upper,mode != 0);
            write_float(result.area);
            write_float(result.top_width);
            write_float(result.top_width_slope);
            write_float(result.conveyance);
            write_float(result.conveyance_slope);
            write_float(result.momentum_factor);
            write_float(result.momentum_factor_slope);
            if (with_moment) {
                write_float(feq::interpolate_section_first_moment(depth,lower,upper,lower_moment));
            }
        }
        return std::cout ? 0 : 1;
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
}
