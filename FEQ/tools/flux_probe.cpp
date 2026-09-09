// Direct original-executable fixtures for analytical section flux.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/section_flux.hpp>
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
        throw std::runtime_error("Incomplete section flux fixture.");
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
void write_double(double value) {
    const std::uint64_t bits = std::bit_cast<std::uint64_t>(value);
    write_word(static_cast<std::uint32_t>(bits));
    write_word(static_cast<std::uint32_t>(bits >> 32));
}
}

int main() {
#if defined(_WIN32)
    _setmode(_fileno(stdin),_O_BINARY);
    _setmode(_fileno(stdout),_O_BINARY);
#endif
    try {
        while (std::cin.peek() != std::char_traits<char>::eof()) {
            const float water = std::bit_cast<float>(read_word());
            const std::uint32_t point_count = read_word();
            const std::uint32_t subsection_count = read_word();
            const std::uint32_t sinuosity_mode = read_word();
            const float manning_factor = std::bit_cast<float>(read_word());
            if (sinuosity_mode != 0 && sinuosity_mode != 2) { throw std::runtime_error("Invalid analytical sinuosity mode."); }
            if (point_count < 2 || point_count > 10000 || subsection_count == 0 || subsection_count > 1000) {
                throw std::runtime_error("Invalid section flux fixture extent.");
            }
            std::vector<std::int32_t> modes(subsection_count);
            for (std::uint32_t index = 0; index < subsection_count; ++index) {
                modes[index] = std::bit_cast<std::int32_t>(read_word());
            }
            std::vector<feq::BoundaryPoint> points(point_count);
            std::vector<float> sinuosity(point_count);
            for (std::uint32_t index = 0; index < point_count; ++index) {
                points[index].offset = std::bit_cast<float>(read_word());
                points[index].elevation = std::bit_cast<float>(read_word());
                points[index].roughness = std::bit_cast<float>(read_word());
                points[index].subsection = read_word();
                sinuosity[index] = std::bit_cast<float>(read_word());
            }
            std::vector<feq::SubsectionGeometry> output(subsection_count);
            std::vector<float> perimeters(point_count-1);
            feq::section_geometry(water,points,modes,output,perimeters);
            std::vector<float> roughness(subsection_count,0.03F);
            std::vector<float> subsection_sinuosity(subsection_count);
            for (std::uint32_t index = 0; index < subsection_count; ++index) {
                if (modes[index] == 0 && output[index].perimeter > 0.0F) {
                    roughness[index] = static_cast<float>(static_cast<double>(output[index].roughness_weight)/output[index].perimeter);
                }
            }
            const feq::SectionFlux flux = feq::analytical_section_flux(water,points,modes,roughness,
                sinuosity,sinuosity_mode == 2,manning_factor,subsection_sinuosity);
            write_double(flux.flow); write_double(flux.momentum); write_double(flux.energy);
            write_double(flux.flow_derivative); write_double(flux.momentum_derivative); write_double(flux.energy_derivative);
            write_double(0.0); write_double(0.0);
            for (std::uint32_t index = 0; index < subsection_count; ++index) { write_float(subsection_sinuosity[index]); }
            for (std::uint32_t index = 0; index < subsection_count*2; ++index) { write_float(0.0F); }
        }
        return std::cout ? 0 : 1;
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
}
