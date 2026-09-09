// Optional COMMON snapshot adapter for the translated research engine.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <cstddef>
#include <bit>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <stdexcept>
#include <vector>
#include "common.hpp"

namespace {
void write_words(const char* environment, const void* object, std::size_t size,
                 unsigned int& count) {
    const char* path = std::getenv(environment);
    if (path == nullptr || count >= 8) {
        return;
    }
    std::vector<unsigned char> bytes(size);
    const unsigned char* source = static_cast<const unsigned char*>(object);
    // All fields are 32-bit integer or binary32. Serialize object words as
    // little-endian bits without type-punned reads or host byte-order assumptions.
    for (std::size_t offset = 0; offset < bytes.size(); offset += 4) {
        std::uint32_t word = 0;
        std::memcpy(&word,source+offset,4);
        bytes[offset] = static_cast<unsigned char>(word);
        bytes[offset+1] = static_cast<unsigned char>(word >> 8);
        bytes[offset+2] = static_cast<unsigned char>(word >> 16);
        bytes[offset+3] = static_cast<unsigned char>(word >> 24);
    }
    std::ofstream output(path,std::ios::binary | (count == 0 ? std::ios::trunc : std::ios::app));
    output.write(reinterpret_cast<const char*>(bytes.data()),static_cast<std::streamsize>(bytes.size()));
    output.close();
    if (!output) {
        throw std::runtime_error("Research matrix trace could not be written.");
    }
    ++count;
}
} // namespace

extern "C" void feq_research_trace_matrix() {
    static_assert(sizeof(Common_matcom_) == 3790428);
    static_assert(offsetof(Common_matcom_,pdavec) == 516828);
    static_assert(offsetof(Common_matcom_,rhs) == 3492828);
    static unsigned int count = 0;
    write_words("FEQ_MATRIX_TRACE",&matcom_,sizeof(matcom_),count);
}

extern "C" void feq_research_trace_branch() {
    static_assert(sizeof(Common_bnelem_) == 1176008);
    static unsigned int count = 0;
    write_words("FEQ_BRANCH_TRACE",&bnelem_,sizeof(bnelem_),count);
}

extern "C" void feq_research_trace_branch_scalars(const double* values, unsigned int size) {
    static unsigned int count = 0;
    const char* path = std::getenv("FEQ_BRANCH_SCALARS_TRACE");
    if (path == nullptr || count >= 8) {
        return;
    }
    if (size > 64) {
        throw std::invalid_argument("Too many research scalar trace fields.");
    }
    std::vector<unsigned char> bytes(static_cast<std::size_t>(size)*8);
    for (unsigned int index = 0; index < size; ++index) {
        const std::uint64_t word = std::bit_cast<std::uint64_t>(values[index]);
        for (unsigned int byte = 0; byte < 8; ++byte) {
            bytes[static_cast<std::size_t>(index)*8+byte] = static_cast<unsigned char>(word >> (byte*8));
        }
    }
    std::ofstream output(path,std::ios::binary | (count == 0 ? std::ios::trunc : std::ios::app));
    output.write(reinterpret_cast<const char*>(bytes.data()),static_cast<std::streamsize>(bytes.size()));
    output.close();
    if (!output) {
        throw std::runtime_error("Research branch trace could not be written.");
    }
    ++count;
}
