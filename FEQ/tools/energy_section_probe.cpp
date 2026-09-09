// Direct original-executable fixtures for energy section.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/section_energy.hpp>
#include <feq/steady_residual.hpp>
#include <feq/approach_residual.hpp>
#include <bit>
#include <cstdint>
#include <cstring>
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
        throw std::runtime_error("Incomplete energy section fixture.");
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

feq::EnergySectionRow read_row() {
    feq::EnergySectionRow row{};
    row.section.depth = std::bit_cast<float>(read_word());
    row.section.top_width = std::bit_cast<float>(read_word());
    row.section.area = std::bit_cast<float>(read_word());
    row.section.sqrt_conveyance = std::bit_cast<float>(read_word());
    row.section.momentum_factor = std::bit_cast<float>(read_word());
    row.first_moment = std::bit_cast<float>(read_word());
    row.energy_factor = std::bit_cast<float>(read_word());
    row.critical_flow = std::bit_cast<float>(read_word());
    row.section.sqrt_conveyance_slope = std::bit_cast<float>(read_word());
    row.section.momentum_factor_slope = std::bit_cast<float>(read_word());
    row.energy_factor_slope = std::bit_cast<float>(read_word());
    return row;
}

}

int main(int argc, char** argv) {
#if defined(_WIN32)
    _setmode(_fileno(stdin),_O_BINARY);
    _setmode(_fileno(stdout),_O_BINARY);
#endif
    try {
        const bool critical_only = argc == 2 && std::strcmp(argv[1],"--critical-flow") == 0;
        const bool steady = argc == 2 && std::strcmp(argv[1],"--steady") == 0;
        const bool profile = argc == 2 && std::strcmp(argv[1],"--profile") == 0;
        const bool approach = argc == 2 && std::strcmp(argv[1],"--approach") == 0;
        while (std::cin.peek() != std::char_traits<char>::eof()) {
            if (profile) {
                float fields[8]{};
                for (int i = 0; i < 8; ++i) { fields[i] = std::bit_cast<float>(read_word()); }
                const double depth = static_cast<double>(fields[0])-fields[1];
                write_double(feq::steady_specific_energy(depth,fields[2],fields[3],fields[4],fields[5]));
                write_double(feq::steady_normal_flow(fields[7],fields[6]));
                continue;
            }
            const std::uint32_t table_type = read_word();
            const float depth = std::bit_cast<float>(read_word());
            const feq::EnergySectionRow lower = read_row();
            const feq::EnergySectionRow upper = read_row();
            const feq::EnergySectionRow following = read_row();
            if (approach) {
                float fields[15]{};
                for (int i = 0; i < 15; ++i) { fields[i] = std::bit_cast<float>(read_word()); }
                const feq::EnergySectionProperties properties = feq::interpolate_energy_section(
                    depth,lower,upper,table_type == 32 || table_type == 35,&following);
                const feq::ApproachResidualInput input{depth,properties.section.area,properties.section.conveyance,
                    properties.energy_factor,fields[0],fields[1],fields[2],fields[3],fields[4],fields[5],
                    fields[6],fields[7],fields[8],fields[9],fields[10],fields[11],fields[12],fields[13]};
                const feq::ApproachResidual result = feq::approach_residual(input);
                const float head = static_cast<float>(static_cast<double>(fields[1])+depth);
                write_double(result.value);
                write_word(result.contracting ? 1U : 0U);
                write_float(head);
                write_float(fields[1]);
                write_float(depth);
                write_float(properties.section.top_width);
                write_float(properties.section.top_width_slope);
                write_float(properties.section.area);
                write_float(properties.first_moment);
                write_float(properties.section.conveyance);
                write_float(properties.section.conveyance_slope);
                write_float(properties.section.momentum_factor);
                write_float(properties.section.momentum_factor_slope);
                write_float(properties.energy_factor);
                write_float(properties.energy_factor_slope);
                write_double(feq::approach_head_residual(head,fields[14]));
                continue;
            }
            if (steady) {
                float fields[11]{};
                for (int i = 0; i < 11; ++i) { fields[i] = std::bit_cast<float>(read_word()); }
                const float lookup_depth = depth < fields[0] ? depth : fields[0];
                const feq::EnergySectionProperties properties = feq::interpolate_energy_section(
                    lookup_depth,lower,upper,table_type == 32 || table_type == 35,&following);
                const feq::SteadyResidualInput input{depth,properties.section.area,properties.section.conveyance,
                    properties.energy_factor,fields[2],fields[3],fields[4],fields[5],fields[6],fields[1],
                    fields[7],fields[8],fields[9],fields[10]};
                write_double(feq::steady_subcritical_residual(input));
                write_double(feq::steady_supercritical_residual(input));
                write_float(depth);
                continue;
            }
            if (critical_only) {
                const feq::EnergySectionRow& low = lower.section.depth == 0.0F ? upper : lower;
                const feq::EnergySectionRow& high = lower.section.depth == 0.0F ? following : upper;
                write_float(feq::logarithmic_critical_flow(depth,low.section.depth,high.section.depth,
                    low.critical_flow,high.critical_flow));
                continue;
            }
            const feq::EnergySectionProperties result = feq::interpolate_energy_section(depth,lower,upper,
                table_type == 32 || table_type == 35,&following);
            write_float(result.section.area);
            write_float(result.section.top_width);
            write_float(result.section.top_width_slope);
            write_float(result.first_moment);
            write_float(result.section.conveyance);
            write_float(result.section.conveyance_slope);
            write_float(result.section.momentum_factor);
            write_float(result.section.momentum_factor_slope);
            write_float(result.energy_factor);
            write_float(result.energy_factor_slope);
            write_float(result.critical_flow);
        }
        return std::cout ? 0 : 1;
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
}
