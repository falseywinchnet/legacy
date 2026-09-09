// Direct original-executable fixtures for energy section.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/section_energy.hpp>
#include <feq/steady_residual.hpp>
#include <feq/approach_residual.hpp>
#include <feq/gate_residual.hpp>
#include <feq/power_spacing.hpp>
#include <array>
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
        const bool gate = argc == 2 && std::strcmp(argv[1],"--gate") == 0;
        const bool gate_levels = argc == 2 && std::strcmp(argv[1],"--gate-levels") == 0;
        const bool gate_free = argc == 2 && std::strcmp(argv[1],"--gate-free") == 0;
        const bool gate_orifice = argc == 2 && std::strcmp(argv[1],"--gate-orifice") == 0;
        const bool power_spacing = argc == 2 && std::strcmp(argv[1],"--power-spacing") == 0;
        const bool specific_energy = argc == 2 && std::strcmp(argv[1],"--specific-energy") == 0;
        while (std::cin.peek() != std::char_traits<char>::eof()) {
            if (power_spacing) {
                float fields[4]{};
                for (int i = 0; i < 4; ++i) { fields[i] = std::bit_cast<float>(read_word()); }
                const std::int32_t capacity = std::bit_cast<std::int32_t>(read_word());
                int flag = std::bit_cast<std::int32_t>(read_word());
                if (capacity < 0 || capacity > 512) { throw std::runtime_error("Invalid breakpoint fixture capacity."); }
                float points[512]{};
                for (int i = 0; i < 512; ++i) { points[i] = -7.25F; }
                const int count = feq::power_breakpoints(fields[0],fields[1],fields[2],fields[3],points,capacity,flag);
                write_word(std::bit_cast<std::uint32_t>(static_cast<std::int32_t>(count)));
                write_word(std::bit_cast<std::uint32_t>(static_cast<std::int32_t>(flag)));
                for (int i = 0; i < 512; ++i) { write_float(points[i]); }
                continue;
            }
            if (gate_orifice) {
                float fields[12]{};
                for (int i = 0; i < 12; ++i) { fields[i] = std::bit_cast<float>(read_word()); }
                write_float(feq::gate_upstream_head(fields[0],fields[1],fields[2]));
                const feq::GateFreeOrifice result = feq::gate_free_orifice(fields[3],fields[2],
                    fields[4],fields[5],fields[6],fields[7],fields[8],fields[9],fields[10],fields[11]);
                write_float(result.effective_area);
                write_float(result.flow);
                continue;
            }
            if (gate_free) {
                const std::uint64_t low = read_word();
                const std::uint64_t high = read_word();
                const double head = std::bit_cast<double>(low | (high << 32));
                float fields[13]{};
                for (int i = 0; i < 13; ++i) { fields[i] = std::bit_cast<float>(read_word()); }
                const feq::GateCriticalSetup setup = feq::gate_critical_setup(
                    fields[0],fields[1],fields[2],fields[3],fields[4],fields[5],fields[6]);
                write_float(setup.area);
                write_float(setup.depth);
                write_float(setup.flow);
                write_float(setup.specific_energy);
                write_float(setup.initial_depth);
                const feq::GateFreeWeir result = feq::gate_free_weir(head,
                    fields[7],fields[8],fields[9],fields[10],fields[11],fields[12]);
                write_float(result.depth);
                write_float(result.flow);
                continue;
            }
            if (gate_levels) {
                float fields[6]{};
                for (int i = 0; i < 6; ++i) { fields[i] = std::bit_cast<float>(read_word()); }
                const feq::GateTailwaterLevels result = feq::gate_tailwater_levels(
                    fields[0],fields[1],fields[2],fields[3],fields[4]);
                write_double(result.head);
                write_double(result.drop);
                const feq::GateSubmergedLevels submerged = feq::gate_submerged_levels(
                    fields[0],fields[1],result.drop,fields[5],fields[3],fields[4]);
                write_float(submerged.depth);
                write_double(submerged.head);
                write_double(submerged.drop);
                continue;
            }
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
            if (specific_energy) {
                float fields[3]{};
                for (int i = 0; i < 3; ++i) { fields[i] = std::bit_cast<float>(read_word()); }
                const feq::EnergySectionProperties properties = feq::interpolate_energy_section(
                    depth,lower,upper,table_type == 32 || table_type == 35,&following);
                for (int type = 20; type <= 25; ++type) {
                    const float factor = type == 22 || type == 25 ? properties.energy_factor : 1.0F;
                    write_double(feq::specific_energy_residual(depth,properties.section.area,
                        factor,fields[0],fields[2],fields[1]));
                }
                write_float(depth);
                continue;
            }
            if (gate) {
                static_cast<void>(read_word());
                static_cast<void>(read_word());
                std::array<float,40> initial{};
                for (std::size_t i = 0; i < initial.size(); ++i) { initial[i] = std::bit_cast<float>(read_word()); }
                const feq::EnergySectionProperties properties = feq::interpolate_energy_section(
                    depth,lower,upper,table_type == 32 || table_type == 35,&following);
                for (int routine = 0; routine < 4; ++routine) {
                    std::array<float,40> fields = initial;
                    fields[14] = depth;
                    if (routine < 2) {
                        fields[38] = feq::interpolate_scalar_first_moment(depth,lower.section.depth,
                            lower.section.top_width,lower.section.area,lower.first_moment,
                            upper.section.depth,upper.section.top_width);
                    } else {
                        fields[6] = properties.section.area;
                        fields[15] = properties.section.top_width;
                        fields[9] = properties.first_moment;
                        fields[19] = properties.section.conveyance;
                        fields[20] = properties.section.conveyance_slope;
                        fields[26] = properties.section.momentum_factor;
                        fields[35] = properties.section.momentum_factor_slope;
                        fields[39] = properties.energy_factor;
                        fields[34] = properties.energy_factor_slope;
                        fields[23] = properties.critical_flow;
                    }
                    const feq::GateResidualInput input{fields[0],fields[10],fields[12],fields[17],fields[5],
                        fields[25],fields[30],fields[29],fields[31],fields[28],fields[32],fields[33],fields[6],
                        fields[26],fields[9],fields[38],fields[36],routine < 2 ? depth : fields[2],fields[37]};
                    const feq::GateResidual result = routine == 0 ? feq::gate_orifice_jet_residual(input) :
                        routine == 1 ? feq::gate_weir_jet_residual(input) :
                        routine == 2 ? feq::gate_orifice_tailwater_residual(input) : feq::gate_weir_tailwater_residual(input);
                    fields[36] = result.squared_flow;
                    write_double(result.value);
                    for (std::size_t i = 0; i < fields.size(); ++i) { write_float(fields[i]); }
                }
                continue;
            }
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
