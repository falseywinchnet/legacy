// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/md5.hpp>

#include <array>
#include <bit>
#include <cstddef>
#include <cstdint>

namespace feq {
namespace {

// K[i] = floor(2^32 * abs(sin(i+1))), with the sine argument in radians.
// Fixed constants avoid a dependency on the platform's sine implementation.
constexpr std::array<std::uint32_t, 64> constants = {
    0xd76aa478u, 0xe8c7b756u, 0x242070dbu, 0xc1bdceeeu,
    0xf57c0fafu, 0x4787c62au, 0xa8304613u, 0xfd469501u,
    0x698098d8u, 0x8b44f7afu, 0xffff5bb1u, 0x895cd7beu,
    0x6b901122u, 0xfd987193u, 0xa679438eu, 0x49b40821u,
    0xf61e2562u, 0xc040b340u, 0x265e5a51u, 0xe9b6c7aau,
    0xd62f105du, 0x02441453u, 0xd8a1e681u, 0xe7d3fbc8u,
    0x21e1cde6u, 0xc33707d6u, 0xf4d50d87u, 0x455a14edu,
    0xa9e3e905u, 0xfcefa3f8u, 0x676f02d9u, 0x8d2a4c8au,
    0xfffa3942u, 0x8771f681u, 0x6d9d6122u, 0xfde5380cu,
    0xa4beea44u, 0x4bdecfa9u, 0xf6bb4b60u, 0xbebfbc70u,
    0x289b7ec6u, 0xeaa127fau, 0xd4ef3085u, 0x04881d05u,
    0xd9d4d039u, 0xe6db99e5u, 0x1fa27cf8u, 0xc4ac5665u,
    0xf4292244u, 0x432aff97u, 0xab9423a7u, 0xfc93a039u,
    0x655b59c3u, 0x8f0ccc92u, 0xffeff47du, 0x85845dd1u,
    0x6fa87e4fu, 0xfe2ce6e0u, 0xa3014314u, 0x4e0811a1u,
    0xf7537e82u, 0xbd3af235u, 0x2ad7d2bbu, 0xeb86d391u
};

constexpr std::array<int, 16> rotations = {
    7, 12, 17, 22, 5, 9, 14, 20, 4, 11, 16, 23, 6, 10, 15, 21
};

void consume(std::array<std::uint32_t, 4>& state, const unsigned char* block) {
    std::array<std::uint32_t, 16> words{};
    for (std::size_t index = 0; index < words.size(); ++index) {
        const std::size_t offset = 4*index;
        // RFC 1321 uses little-endian words, independent of the host CPU.
        words[index] = static_cast<std::uint32_t>(block[offset]) |
            (static_cast<std::uint32_t>(block[offset+1]) << 8) |
            (static_cast<std::uint32_t>(block[offset+2]) << 16) |
            (static_cast<std::uint32_t>(block[offset+3]) << 24);
    }
    std::uint32_t a = state[0];
    std::uint32_t b = state[1];
    std::uint32_t c = state[2];
    std::uint32_t d = state[3];
    for (std::size_t step = 0; step < 64; ++step) {
        std::uint32_t selection = 0;
        std::size_t word = 0;
        const std::size_t round = step/16;
        if (round == 0) {
            selection = (b & c) | (~b & d);
            word = step;
        } else if (round == 1) {
            selection = (b & d) | (c & ~d);
            word = (5*step+1)%16;
        } else if (round == 2) {
            selection = b ^ c ^ d;
            word = (3*step+5)%16;
        } else {
            selection = c ^ (b | ~d);
            word = (7*step)%16;
        }
        // Each round performs b + ROTL(a + F(b,c,d) + X[k] + K[i], s).
        // uint32_t makes every addition explicitly modulo 2^32.
        const std::uint32_t next = b + std::rotl(a+selection+words[word]+constants[step],
                                                rotations[4*round+step%4]);
        a = d;
        d = c;
        c = b;
        b = next;
    }
    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
}

} // namespace

std::string md5_hex(std::string_view message) {
    std::array<std::uint32_t, 4> state = {
        0x67452301u, 0xefcdab89u, 0x98badcfeu, 0x10325476u
    };
    std::size_t consumed = 0;
    while (message.size()-consumed >= 64) {
        consume(state, reinterpret_cast<const unsigned char*>(message.data()+consumed));
        consumed += 64;
    }
    std::array<unsigned char, 128> tail{};
    const std::size_t remaining = message.size()-consumed;
    for (std::size_t index = 0; index < remaining; ++index) {
        tail[index] = static_cast<unsigned char>(message[consumed+index]);
    }
    tail[remaining] = 0x80;
    const std::size_t tail_size = remaining < 56 ? 64 : 128;
    const std::uint64_t bits = static_cast<std::uint64_t>(message.size())*8u;
    for (std::size_t index = 0; index < 8; ++index) {
        tail[tail_size-8+index] = static_cast<unsigned char>(bits >> (8*index));
    }
    consume(state, tail.data());
    if (tail_size == 128) {
        consume(state, tail.data()+64);
    }
    constexpr char digits[] = "0123456789ABCDEF";
    std::string digest(32, '0');
    for (std::size_t index = 0; index < 16; ++index) {
        const std::uint32_t byte = (state[index/4] >> (8*(index%4))) & 255u;
        digest[2*index] = digits[byte >> 4];
        digest[2*index+1] = digits[byte & 15u];
    }
    return digest;
}

} // namespace feq
