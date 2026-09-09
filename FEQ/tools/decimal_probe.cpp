// Direct original-executable fixtures for REAL*4 decimal conversion.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/decimal.hpp>
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
        throw std::runtime_error("Incomplete decimal fixture.");
    }
    return static_cast<std::uint32_t>(bytes[0]) | (static_cast<std::uint32_t>(bytes[1]) << 8) |
        (static_cast<std::uint32_t>(bytes[2]) << 16) | (static_cast<std::uint32_t>(bytes[3]) << 24);
}
void write_word(std::uint32_t word) {
    const unsigned char bytes[4] = {static_cast<unsigned char>(word),static_cast<unsigned char>(word >> 8),
        static_cast<unsigned char>(word >> 16),static_cast<unsigned char>(word >> 24)};
    std::cout.write(reinterpret_cast<const char*>(bytes),4);
}
}

int main(int argc, char** argv) {
#if defined(_WIN32)
    _setmode(_fileno(stdin),_O_BINARY);
    _setmode(_fileno(stdout),_O_BINARY);
#endif
    try {
        const bool list_mode = argc == 2 && std::string(argv[1]) == "--list-real";
        if (argc != 1 && !list_mode) {
            throw std::runtime_error("Unknown decimal probe mode.");
        }
        while (std::cin.peek() != std::char_traits<char>::eof()) {
            const float value = std::bit_cast<float>(read_word());
            if (list_mode) {
                const std::uint32_t style = read_word();
                if (style > 3) {
                    throw std::runtime_error("Unknown list-output fixture style.");
                }
                // The original unit 6 suppresses the report file's leading
                // carriage-control blank. The item separator is one blank.
                if (style >= 2) {
                    std::cout << ' ';
                }
                if (style%2 == 0) {
                    std::cout << " FW flow at its upper limit= ";
                }
                std::cout << feq::list_real(value) << "\r\n";
                continue;
            }
            const feq::DecimalEdit edit = static_cast<feq::DecimalEdit>(read_word());
            const int precision = std::bit_cast<std::int32_t>(read_word());
            const int scale = std::bit_cast<std::int32_t>(read_word());
            const feq::DecimalDigits result = feq::decimal_digits(value,edit,precision,scale);
            write_word(static_cast<std::uint32_t>(result.count));
            write_word(static_cast<std::uint32_t>(result.exponent));
            write_word(result.status);
            write_word(static_cast<std::uint32_t>(result.general_state) |
                       (static_cast<std::uint32_t>(static_cast<std::uint16_t>(result.engineering_shift)) << 16));
            std::cout.write(result.digits.data(),16);
        }
        return std::cout ? 0 : 1;
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
}
