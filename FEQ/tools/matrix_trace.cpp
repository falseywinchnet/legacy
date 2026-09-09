// Optional COMMON snapshot adapter for the translated research engine.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <cstddef>
#include <bit>
#include <charconv>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <stdexcept>
#include <vector>
#include "common.hpp"

namespace {
unsigned int trace_limit() {
    const char* text = std::getenv("FEQ_TRACE_LIMIT");
    if (text == nullptr) {
        return 8;
    }
    unsigned int limit = 0;
    const char* end = text+std::strlen(text);
    const std::from_chars_result parsed = std::from_chars(text,end,limit);
    if (parsed.ec != std::errc{} || parsed.ptr != end || limit > 1024) {
        throw std::invalid_argument("FEQ_TRACE_LIMIT must be an integer from 0 through 1024.");
    }
    return limit;
}

void append_storage(std::vector<unsigned char>& target, const void* source, std::size_t bytes) {
    const std::size_t first = target.size();
    target.resize(first+bytes);
    std::memcpy(target.data()+first,source,bytes);
}

void write_words(const char* environment, const void* object, std::size_t size,
                 unsigned int& count) {
    const char* path = std::getenv(environment);
    if (path == nullptr || count >= trace_limit()) {
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
    const char* active_only = std::getenv("FEQ_MATRIX_TRACE_ACTIVE");
    if (active_only != nullptr && std::strcmp(active_only,"1") == 0) {
        if (std::getenv("FEQ_MATRIX_TRACE") == nullptr || count >= trace_limit()) {
            return;
        }
        if (matcom_.numeq <= 0 || matcom_.numeq > 24800 || matcom_.matblk < 0 || matcom_.matblk > 4401) {
            throw std::invalid_argument("Invalid active matrix trace dimensions.");
        }
        const integer entries = matcom_.feq_gen_c_d_[matcom_.numeq];
        if (entries < 0 || entries > 744000) {
            throw std::invalid_argument("Invalid active matrix coefficient count.");
        }
        const std::size_t rows = static_cast<std::size_t>(matcom_.numeq);
        const std::size_t blocks = static_cast<std::size_t>(matcom_.matblk);
        std::vector<unsigned char> record;
        append_storage(record,&matcom_,12);
        append_storage(record,matcom_.feq_gen_r_d_,rows*4);
        append_storage(record,matcom_.feq_gen_c_d_,(rows+1)*4);
        append_storage(record,matcom_.begrow,blocks*4);
        append_storage(record,matcom_.endcon,blocks*4);
        append_storage(record,matcom_.mbtype,blocks*4);
        append_storage(record,matcom_.pdavec,static_cast<std::size_t>(entries)*4);
        append_storage(record,matcom_.rhs,rows*4);
        write_words("FEQ_MATRIX_TRACE",record.data(),record.size(),count);
        return;
    }
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
    if (path == nullptr || count >= trace_limit()) {
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
