// Direct original-executable fixtures for submerged-weir iteration.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/weir_flow.hpp>
#include <feq/table_interpolation.hpp>
#include <array>
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
        throw std::runtime_error("Incomplete submerged-weir fixture.");
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

float lookup(void* context, int index, float argument) {
    const std::array<std::vector<feq::FunctionTableRow>,3>& tables =
        *static_cast<std::array<std::vector<feq::FunctionTableRow>,3>*>(context);
    const std::vector<feq::FunctionTableRow>& rows = tables.at(static_cast<std::size_t>(index));
    if (argument < rows.front().argument || argument > rows.back().argument) {
        throw std::out_of_range("Weir lookup exceeds the fixture table.");
    }
    std::size_t upper = 1;
    while (upper+1 < rows.size() && argument > rows[upper].argument) { ++upper; }
    return feq::interpolate_function_table(feq::TableInterpolation::linear,argument,rows[upper-1],rows[upper]).value;
}

}

int main() {
#if defined(_WIN32)
    _setmode(_fileno(stdin),_O_BINARY);
    _setmode(_fileno(stdout),_O_BINARY);
#endif
    try {
        std::array<std::vector<feq::FunctionTableRow>,3> tables;
        const float gravity = std::bit_cast<float>(read_word());
        const float twice_gravity = std::bit_cast<float>(read_word());
        for (std::size_t index = 0; index < 3; ++index) {
            const std::uint32_t count = read_word();
            if (count < 2 || count > 10000) { throw std::runtime_error("Invalid weir table."); }
            for (std::size_t row = 0; row < count; ++row) {
                const float x = std::bit_cast<float>(read_word());
                const float y = std::bit_cast<float>(read_word());
                tables[index].push_back(feq::FunctionTableRow{x,y,0.0F});
            }
        }
        while (std::cin.peek() != std::char_traits<char>::eof()) {
            feq::WeirFlowInput input{};
            input.critical_head_ratio = std::bit_cast<float>(read_word());
            input.breadth = std::bit_cast<float>(read_word());
            input.head = std::bit_cast<float>(read_word());
            input.tail_head = std::bit_cast<float>(read_word());
            input.approach_depth = std::bit_cast<float>(read_word());
            input.total_head = std::bit_cast<float>(read_word());
            input.free_flow = std::bit_cast<float>(read_word());
            input.gravity = gravity;
            input.twice_gravity = twice_gravity;
            const feq::WeirFlow result = feq::submerged_weir_flow(input,lookup,&tables);
            if (result.status != feq::WeirFlowStatus::complete) { throw std::runtime_error("Weir fixture failed to converge."); }
            write_float(result.total_head); write_float(result.flow);
        }
        return std::cout ? 0 : 1;
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
}
