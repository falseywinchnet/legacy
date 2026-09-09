#include <feq/md5.hpp>

#include <array>
#include <cstddef>
#include <iostream>
#include <string>
#include <string_view>
#include <stdexcept>

namespace {
void require(bool condition) {
    if (!condition) {
        throw std::runtime_error("MD5 differs from the published expected digest.");
    }
}
}

int main() {
    // Published RFC 1321, Appendix A.5 test vectors, including block padding.
    constexpr std::array<std::string_view, 7> inputs = {
        "", "a", "abc", "message digest", "abcdefghijklmnopqrstuvwxyz",
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789",
        "12345678901234567890123456789012345678901234567890123456789012345678901234567890"
    };
    constexpr std::array<std::string_view, 7> digests = {
        "D41D8CD98F00B204E9800998ECF8427E", "0CC175B9C0F1B6A831C399E269772661",
        "900150983CD24FB0D6963F7D28E17F72", "F96B697D7CB7938D525A2F31AAF161D0",
        "C3FCD3D76192E4007DFB496CCA67E13B", "D174AB98D277D9F5A5611C2C9F419D9F",
        "57EDF4A22BE3C955AC49DA2E2107B67A"
    };
    for (std::size_t index = 0; index < inputs.size(); ++index) {
        require(feq::md5_hex(inputs[index]) == digests[index]);
    }
    require(feq::md5_hex(std::string(1000000, 'a')) == "7707D6AE4E027C70EEA2A935C2296F21");
    std::cout << "MD5 published vectors and million-byte case passed.\n";
}
