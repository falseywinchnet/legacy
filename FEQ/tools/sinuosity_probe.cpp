// Direct original-executable fixtures for Gaussian section sinuosity.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/section_sinuosity.hpp>
#include <feq/gaussian_rule.hpp>
#include <array>
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

void feq_section_sinuosity(float,int,int,const float*,const float*,const int*,const float*,const int*,
    const float*,const float*,float,float,int,int,int,const double*,const double*,
    double*,double*,double*,double*,double*,double*,double*,double*,float*,float*);

namespace {
std::uint32_t read_word() {
    unsigned char bytes[4]{};
    std::cin.read(reinterpret_cast<char*>(bytes),4);
    if (!std::cin) { throw std::runtime_error("Incomplete sinuosity fixture."); }
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
        const bool adapter = argc == 2 && std::string(argv[1]) == "--adapter";
        if (argc != 1 && !adapter) { throw std::runtime_error("Use no arguments or --adapter."); }
        while (std::cin.peek() != std::char_traits<char>::eof()) {
            const float water = read_float();
            const std::uint32_t count = read_word();
            const std::uint32_t subs = read_word();
            const std::uint32_t order = read_word();
            const std::uint32_t mode = read_word();
            const float factor = read_float();
            const float gravity = read_float();
            if (count < 2 || count > 8 || subs < 1 || subs > 4 || order < 1 || order > 21 || mode > 2) {
                throw std::runtime_error("Invalid sinuosity fixture dimensions or mode.");
            }
            std::array<std::int32_t,4> modes{};
            std::array<feq::BoundaryPoint,8> points{};
            std::array<float,8> sinuosity{};
            for (std::size_t index = 0; index < 4; ++index) { modes[index] = std::bit_cast<std::int32_t>(read_word()); }
            for (std::size_t index = 0; index < 8; ++index) {
                points[index].offset = read_float();
                points[index].elevation = read_float();
                points[index].roughness = read_float();
                points[index].subsection = read_word();
                sinuosity[index] = read_float();
            }
            std::array<float,4> roughness{0.03F,0.03F,0.03F,0.03F};
            std::array<float,4> flow{};
            std::array<float,4> conveyance{};
            const feq::GaussianRule rule = feq::gaussian_rule(order);
            const feq::SinuosityFluxModel model = mode == 0 ? feq::SinuosityFluxModel::disabled :
                (mode == 1 ? feq::SinuosityFluxModel::unit_coefficients : feq::SinuosityFluxModel::depth_coefficients);
            feq::SinuousSectionFlux result{};
            if (adapter) {
                std::array<float,8> x{},z{},lsn{};
                std::array<int,8> sb{};
                std::array<int,4> nvar{};
                for (std::size_t index = 0; index < count; ++index) {
                    x[index] = points[index].offset;
                    z[index] = points[index].elevation;
                    lsn[index] = points[index].roughness;
                    sb[index] = static_cast<int>(points[index].subsection)+1;
                }
                for (std::size_t index = 0; index < subs; ++index) { nvar[index] = modes[index]; }
                feq_section_sinuosity(water,static_cast<int>(count),static_cast<int>(subs),x.data(),z.data(),sb.data(),
                    lsn.data(),nvar.data(),roughness.data(),sinuosity.data(),factor,gravity,mode == 0 ? 0 : 1,
                    mode == 2 ? 1 : 0,static_cast<int>(order),rule.nodes.data(),rule.weights.data(),
                    &result.flux.flow,&result.flux.momentum,&result.flux.energy,&result.flux.flow_derivative,
                    &result.flux.momentum_derivative,&result.flux.energy_derivative,&result.area_sinuosity,
                    &result.flow_sinuosity,flow.data(),conveyance.data());
            } else {
                result = feq::linear_sinuosity_flux(water,
                    std::span<const feq::BoundaryPoint>(points.data(),count),std::span<const std::int32_t>(modes.data(),subs),
                    std::span<const float>(roughness.data(),subs),std::span<const float>(sinuosity.data(),count),
                    factor,gravity,model,rule.nodes,rule.weights,std::span<float>(flow.data(),subs),std::span<float>(conveyance.data(),subs));
            }
            write_double(result.flux.flow); write_double(result.flux.momentum); write_double(result.flux.energy);
            write_double(result.flux.flow_derivative); write_double(result.flux.momentum_derivative); write_double(result.flux.energy_derivative);
            write_double(result.area_sinuosity); write_double(result.flow_sinuosity);
            for (std::size_t index = 0; index < 4; ++index) { write_float(0.0F); }
            for (std::size_t index = 0; index < 4; ++index) { write_float(flow[index]); }
            for (std::size_t index = 0; index < 4; ++index) { write_float(conveyance[index]); }
        }
        return std::cout ? 0 : 1;
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
}
