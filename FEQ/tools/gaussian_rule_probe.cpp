// Direct original-executable fixture driver for GRULE.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/gaussian_rule.hpp>
#include <bit>
#include <cstdint>
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
    if (!std::cin) {
        throw std::runtime_error("Incomplete Gaussian-rule fixture.");
    }
    return static_cast<std::uint32_t>(bytes[0]) | (static_cast<std::uint32_t>(bytes[1]) << 8) |
        (static_cast<std::uint32_t>(bytes[2]) << 16) | (static_cast<std::uint32_t>(bytes[3]) << 24);
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

int main() {
#if defined(_WIN32)
    _setmode(_fileno(stdin),_O_BINARY);
    _setmode(_fileno(stdout),_O_BINARY);
#endif
    try {
        while (std::cin.peek() != std::char_traits<char>::eof()) {
            const std::uint32_t count = read_word();
            const feq::GaussianRule rule = feq::gaussian_rule(count);
            if (rule.unconverged_index != 0) {
                throw std::runtime_error("Gaussian-rule fixture did not converge.");
            }
            for (std::size_t index = 0; index < rule.nodes.size(); ++index) {
                write_double(rule.nodes[index]);
            }
            for (std::size_t index = 0; index < rule.weights.size(); ++index) {
                write_double(rule.weights[index]);
            }
        }
        return std::cout ? 0 : 1;
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
}
