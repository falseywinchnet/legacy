// SPDX-License-Identifier: MIT
#include "legacy/runup_math.hpp"

#include <cmath>
#include <stdexcept>

namespace legacy::runup {
namespace {
float log10_stored(std::int32_t value) {
    if (value <= 0) {
        throw std::domain_error("RUNUP logarithmic interpolation requires positive coordinates");
    }
    return static_cast<float>(std::log10(static_cast<double>(static_cast<float>(value))));
}
}

Bracket bracket(std::span<const std::int32_t> table, std::int32_t value) {
    if (table.empty()) {
        throw std::invalid_argument("RUNUP lookup table is empty");
    }
    // LOOK, 0000:0c84. Preserve the original endpoint bracket convention.
    auto count = static_cast<std::int32_t>(table.size());
    std::int32_t lower = 1;
    std::int32_t upper = count;
    if (table.front() > value) return {1, 1, true};
    if (table.back() < value) return {count, count, true};
    auto previous_upper = upper;
    upper = (upper - lower) / 2 + lower;
    while (upper != lower) {
        if (table[upper - 1] <= value) {
            lower = upper;
            upper = previous_upper;
        }
        previous_upper = upper;
        upper = (upper - lower) / 2 + lower;
    }
    if (count != upper) upper = lower + 1;
    return {lower, upper, false};
}

std::int32_t linear_integer(std::int32_t x1, std::int32_t x2,
                            std::int32_t y1, std::int32_t y2, std::int32_t x) {
    // RINT, 0000:3095: differences are INTEGER*4; G and RAT are stored REAL*4.
    const float width = static_cast<float>(x2 - x1);
    if (width == 0.0f) return y1;
    const float ratio = static_cast<float>(static_cast<double>(x - x1) / width);
    return static_cast<std::int32_t>(static_cast<double>(y2 - y1) * ratio + y1);
}

float linear_real(float x1, float x2, float y1, float y2, float x) {
    // SWLINT, 0000:3156: store only at the same points as the original.
    const float width = static_cast<float>(static_cast<double>(x2) - x1);
    if (width == 0.0f) return y1;
    const float ratio = static_cast<float>((static_cast<double>(x) - x1) / width);
    return static_cast<float>((static_cast<double>(y2) - y1) * ratio + y1);
}

std::int32_t log_linear(std::int32_t x1, std::int32_t x2,
                        std::int32_t y1, std::int32_t y2, std::int32_t x) {
    // LOGLIN, 0000:0f18. Each logarithm and the slope are stored as REAL*4.
    const float lx1 = log10_stored(x1);
    const float lx2 = log10_stored(x2);
    const float lx = log10_stored(x);
    if (lx1 == lx2) throw std::domain_error("RUNUP logarithmic interval has zero width");
    const float slope = static_cast<float>(static_cast<double>(y1 - y2) /
                                           (static_cast<double>(lx1) - lx2));
    return static_cast<std::int32_t>((static_cast<double>(lx) - lx1) * slope + y1);
}

std::int32_t log_log(std::int32_t x1, std::int32_t x2,
                     std::int32_t y1, std::int32_t y2, std::int32_t x) {
    // LOGLOG, 0000:0e10. Integer conversion truncates, including at endpoints.
    const float lx1 = log10_stored(x1);
    const float lx2 = log10_stored(x2);
    const float ly1 = log10_stored(y1);
    const float ly2 = log10_stored(y2);
    const float lx = log10_stored(x);
    if (lx1 == lx2) throw std::domain_error("RUNUP logarithmic interval has zero width");
    const float slope = static_cast<float>((static_cast<double>(ly1) - ly2) /
                                           (static_cast<double>(lx1) - lx2));
    const double exponent = (static_cast<double>(lx) - lx1) * slope + ly1;
    return static_cast<std::int32_t>(std::pow(10.0, exponent));
}

}  // namespace legacy::runup
