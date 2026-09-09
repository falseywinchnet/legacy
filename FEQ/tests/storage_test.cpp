#include "feq/storage.hpp"

#include <array>
#include <bit>
#include <cstdint>
#include <iostream>
#include <limits>
#include <stdexcept>

namespace {

void require(bool condition, const char* message) {
    if (!condition) {
        throw std::runtime_error(message);
    }
}

void change_scalar(float* value) { *value = -2.5F; }

void check_storage() {
    std::array<unsigned char, 24> memory{};
    feq::BitView<std::uint32_t> integers(memory.data(), memory.size());
    feq::BitView<float> singles(memory.data(), memory.size());
    feq::BitView<double> doubles(memory.data(), memory.size());

    integers[0] = UINT32_C(0x3f800000);
    require(static_cast<float>(singles[0]) == 1.0F, "Integer bits must become the same float bits.");
    singles[1] = -0.0F;
    require(static_cast<std::uint32_t>(integers[1]) == UINT32_C(0x80000000), "Signed zero must retain its sign bit.");
    integers[2] = UINT32_C(0x7fc12345);
    const float payload_nan = static_cast<float>(singles[2]);
    require(std::bit_cast<std::uint32_t>(payload_nan) == UINT32_C(0x7fc12345), "NaN payload bits must survive a view read.");
    integers[3] = integers[2];
    integers[2] = UINT32_C(0);
    require(static_cast<std::uint32_t>(integers[3]) == UINT32_C(0x7fc12345), "Proxy assignment must copy a value, not rebind its address.");

    doubles[2] = 3.25;
    const std::uint64_t combined = std::bit_cast<std::uint64_t>(3.25);
    if (std::endian::native == std::endian::little) {
        require(static_cast<std::uint32_t>(integers[4]) == static_cast<std::uint32_t>(combined), "Double low word overlay.");
        require(static_cast<std::uint32_t>(integers[5]) == static_cast<std::uint32_t>(combined >> 32), "Double high word overlay.");
    } else {
        require(static_cast<std::uint32_t>(integers[4]) == static_cast<std::uint32_t>(combined >> 32), "Double high word overlay.");
        require(static_cast<std::uint32_t>(integers[5]) == static_cast<std::uint32_t>(combined), "Double low word overlay.");
    }

    change_scalar(singles.lease(0).data());
    require(static_cast<std::uint32_t>(integers[0]) == UINT32_C(0xc0200000), "Scalar argument copy-back must retain the updated bits.");
    bool caught = false;
    try { singles[-1] = 1.0F; } catch (const std::out_of_range&) { caught = true; }
    require(caught, "Reject a negative bank index.");
    caught = false;
    try { singles[6] = 1.0F; } catch (const std::out_of_range&) { caught = true; }
    require(caught, "Reject an index beyond the bank.");

    float values[6] = {1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 6.0F};
    feq::IndexedPointer<float> one_based(values, 1);
    require(one_based[1] == values[0] && one_based[6] == values[5], "One-based index mapping.");
    require(one_based + 1 == values, "Pointer arithmetic must return a pointer into the actual array.");
    feq::IndexedPointer<float> matrix(values, 3); // 2 rows; i+2*j; bias=1+2*1.
    require(matrix[2+2*3] == 6.0F, "Column-major matrix index mapping.");
    feq::IndexedPointer<float> negative_lower(values, -2);
    require(negative_lower[-2] == 1.0F && negative_lower[3] == 6.0F, "Negative Fortran lower bound.");
    caught = false;
    try { one_based[0] = 0.0F; } catch (const std::out_of_range&) { caught = true; }
    require(caught, "Reject a pointer before the declared array.");
    require(feq::checked_extent(3, 4) == 12 && feq::checked_extent(0, 4) == 0, "Automatic-array extents.");
    caught = false;
    try { feq::checked_extent(-1); } catch (const std::invalid_argument&) { caught = true; }
    require(caught, "Reject a negative automatic extent.");
    caught = false;
    try { feq::checked_extent(std::numeric_limits<std::int64_t>::max(), 8); }
    catch (const std::length_error&) { caught = true; }
    require(caught, "Reject automatic-array extent overflow.");
    feq::BitView<std::int32_t> signed_integers(memory.data(), memory.size());
    signed_integers[0] = std::numeric_limits<std::int32_t>::max();
    ++signed_integers[0];
    require(static_cast<std::int32_t>(signed_integers[0]) == std::numeric_limits<std::int32_t>::min(), "Integer bit arithmetic must wrap without signed-overflow UB.");
    caught = false;
    try { signed_integers[0] /= -1; } catch (const std::overflow_error&) { caught = true; }
    require(caught, "Reject an unrepresentable signed quotient.");
}

} // namespace

int main() {
    try {
        check_storage();
        std::cout << "storage: bit overlays, scalar copy-back, bounds, and index mappings passed\n";
        return 0;
    } catch (const std::exception& error) {
        std::cerr << "storage test: " << error.what() << '\n';
        return 1;
    }
}
