// Direct original-executable fixtures for section properties.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/section_properties.hpp>
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
        throw std::runtime_error("Incomplete section properties fixture.");
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
            const float water = std::bit_cast<float>(read_word());
            const std::uint32_t point_count = read_word();
            const std::uint32_t subsection_count = read_word();
            const std::uint32_t average_roughness = read_word();
            const std::uint32_t sinuosity_mode = read_word();
            const std::uint32_t beta_mode = read_word();
            const std::uint32_t usgs_coefficients = read_word();
            const float manning_factor = std::bit_cast<float>(read_word());
            const float gravity = std::bit_cast<float>(read_word());
            const float slot = std::bit_cast<float>(read_word());
            if ((sinuosity_mode != 0 && sinuosity_mode != 2) || average_roughness > 1 || beta_mode > 4 || usgs_coefficients > 1) {
                throw std::runtime_error("Invalid section properties option.");
            }
            if (point_count < 2 || point_count > 10000 || subsection_count == 0 || subsection_count > 1000) {
                throw std::runtime_error("Invalid section properties fixture extent.");
            }
            std::vector<std::int32_t> modes(subsection_count);
            std::vector<float> previous_conveyance(subsection_count);
            std::vector<float> previous_width(subsection_count);
            for (std::uint32_t index = 0; index < subsection_count; ++index) {
                modes[index] = std::bit_cast<std::int32_t>(read_word());
                previous_conveyance[index] = std::bit_cast<float>(read_word());
                previous_width[index] = std::bit_cast<float>(read_word());
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
            std::vector<feq::SubsectionElements> elements(subsection_count);
            for (std::uint32_t index = 0; index < subsection_count; ++index) {
                elements[index] = feq::SubsectionElements{output[index],roughness[index],subsection_sinuosity[index],0.0F,0.0F};
            }
            const feq::BetaMethod beta = beta_mode == 0 ? feq::BetaMethod::old_coefficients :
                beta_mode == 2 || beta_mode == 4 ? feq::BetaMethod::momentum :
                beta_mode == 3 ? feq::BetaMethod::energy : feq::BetaMethod::geometric_mean;
            const feq::SectionPropertyOptions options{static_cast<int>(average_roughness),static_cast<int>(sinuosity_mode),
                beta,usgs_coefficients != 0,manning_factor,gravity,slot,false};
            const feq::SectionProperties properties = feq::section_properties(options,elements,
                beta_mode == 0 ? feq::SectionFlux{} : flux,0.0,0.0,previous_conveyance,previous_width,false);
            for (std::uint32_t index = 0; index < 22; ++index) {
                write_float(index >= 1 && index <= 16 ? properties.values[index-1] : static_cast<float>(9000+index));
            }
            for (std::uint32_t index = 0; index < subsection_count; ++index) { write_float(roughness[index]); }
            for (std::uint32_t index = 0; index < subsection_count; ++index) { write_float(previous_conveyance[index]); }
            for (std::uint32_t index = 0; index < subsection_count; ++index) { write_float(previous_width[index]); }
        }
        return std::cout ? 0 : 1;
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
}
