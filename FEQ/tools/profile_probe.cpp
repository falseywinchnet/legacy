// Direct test driver for the independent profile-matrix implementation.
#include <feq/profile_matrix.hpp>

#include <bit>
#include <cstddef>
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

template <typename T>
T read_one() {
    static_assert(sizeof(T) == 4);
    unsigned char bytes[4]{};
    std::cin.read(reinterpret_cast<char*>(bytes),4);
    if (!std::cin) {
        throw std::runtime_error("Incomplete matrix test word.");
    }
    const std::uint32_t bits = static_cast<std::uint32_t>(bytes[0]) |
        (static_cast<std::uint32_t>(bytes[1]) << 8) |
        (static_cast<std::uint32_t>(bytes[2]) << 16) |
        (static_cast<std::uint32_t>(bytes[3]) << 24);
    return std::bit_cast<T>(bits);
}

template <typename T>
void read_values(std::vector<T>& values, std::size_t count) {
    values.resize(count);
    for (std::size_t index = 0; index < count; ++index) {
        values[index] = read_one<T>();
    }
}

template <typename T>
void write_values(const std::vector<T>& values) {
    for (std::size_t index = 0; index < values.size(); ++index) {
        const std::uint32_t bits = std::bit_cast<std::uint32_t>(values[index]);
        const unsigned char bytes[4] = {static_cast<unsigned char>(bits),
            static_cast<unsigned char>(bits >> 8),static_cast<unsigned char>(bits >> 16),
            static_cast<unsigned char>(bits >> 24)};
        std::cout.write(reinterpret_cast<const char*>(bytes),4);
    }
    if (!std::cout) {
        throw std::runtime_error("Matrix test output failed.");
    }
}

} // namespace

int main() {
#if defined(_WIN32)
    _setmode(_fileno(stdin),_O_BINARY);
    _setmode(_fileno(stdout),_O_BINARY);
#endif
    try {
        for (;;) {
            if (std::cin.peek() == std::char_traits<char>::eof()) {
                return 0;
            }
            std::uint32_t header[4]{};
            for (std::size_t index = 0; index < 4; ++index) {
                header[index] = read_one<std::uint32_t>();
            }
            if (!std::cin || header[0] == 0 || header[0] > 1000 || header[1] > 1000000 ||
                header[2] > 1000 || header[3] > 1) {
                throw std::runtime_error("Invalid matrix test header.");
            }
            const std::int32_t equations = static_cast<std::int32_t>(header[0]);
            const std::int32_t blocks = static_cast<std::int32_t>(header[2]);
            std::vector<std::int32_t> begin, end, kinds, diagonal, lower;
            std::vector<float> coefficients, rhs;
            read_values(begin, header[2]);
            read_values(end, header[2]);
            read_values(kinds, header[2]);
            read_values(diagonal, header[0]+1);
            read_values(lower, header[0]);
            read_values(coefficients, header[1]);
            read_values(rhs, header[0]);
            feq::factor_profile(blocks,
                feq::IndexedView<const std::int32_t>(begin.data(),begin.size()),
                feq::IndexedView<const std::int32_t>(end.data(),end.size()),
                feq::IndexedView<const std::int32_t>(kinds.data(),kinds.size()),
                feq::IndexedView<const std::int32_t>(diagonal.data(),diagonal.size(),0),
                feq::IndexedView<const std::int32_t>(lower.data(),lower.size()),
                feq::IndexedView<float>(coefficients.data(),coefficients.size()));
            if (header[3] != 0) {
                feq::solve_profile(equations,
                    feq::IndexedView<const std::int32_t>(diagonal.data(),diagonal.size(),0),
                    feq::IndexedView<const std::int32_t>(lower.data(),lower.size()),
                    feq::IndexedView<const float>(coefficients.data(),coefficients.size()),
                    feq::IndexedView<float>(rhs.data(),rhs.size()));
            }
            write_values(coefficients);
            write_values(rhs);
        }
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 2;
    }
}
