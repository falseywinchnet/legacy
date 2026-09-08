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
    // __FHfexp uses FYL2X followed by the original software F2XM1 path.
    // For positive integral base-10 exponents its result lies just below the
    // integer. Preserve truncation even where binary64 exp2 rounds back up.
    // Original routine probes cover each representable INTEGER*4 decade.
    if (exponent >= 1.0 && exponent <= 9.0 && exponent == std::trunc(exponent))
        return static_cast<std::int32_t>(std::pow(10.0, exponent)) - 1;
    return static_cast<std::int32_t>(std::exp2(std::log2(10.0) * exponent));
}

float breaking_depth(float deep_water_height, float period, float slope_cotangent) {
    // DBPLOT, 0000:31e8, November 1991 coefficients and high-steepness caps.
    const float pi = static_cast<float>(4.0 * std::atan(1.0));
    const float wavelength = static_cast<float>(static_cast<double>(period) * period * 16.1f / pi);
    const float steepness = static_cast<float>(static_cast<double>(deep_water_height) / wavelength);
    if (steepness < 0.002f || steepness > 0.07f) {
        throw std::domain_error("RUNUP wave steepness is outside 0.002 to 0.07");
    }
    const float x = static_cast<float>(std::log10(static_cast<double>(steepness)));
    const float slope = static_cast<float>(1.0 / slope_cotangent);
    constexpr float slope30 = 1.0f / 30.0f;
    struct Line { float x1, difference_y, difference_x, y1; };
    // The 1991 compiler folded these constant differences to binary32.
    constexpr Line mild{-1.2218f, -0.7842f - (-0.382f), -1.2218f - (-2.5229f), -0.7842f};
    constexpr Line middle{-1.2596f, -0.7986f - (-0.3511f), -1.2596f - (-2.6990f), -0.7986f};
    constexpr Line steep{-1.3468f, -0.8262f - (-0.3978f), -1.3468f - (-2.6990f), -0.8262f};
    constexpr Line steepest{-1.6021f, -0.9838f - (-0.4783f), -1.6021f - (-2.6990f), -0.9838f};
    const auto ordinate = [x](Line line) {
        return static_cast<float>((static_cast<double>(x) - line.x1) * line.difference_y /
                                   line.difference_x + line.y1);
    };
    const auto blend = [slope](float x1, float x2, float upper, float lower) {
        return static_cast<float>((static_cast<double>(upper) - lower) *
                                   (static_cast<double>(slope) - x1) /
                                   (static_cast<double>(x1) - x2) + upper);
    };
    float y;
    if (slope <= 0.02f) {
        y = steepness > 0.06f ? mild.y1 : ordinate(mild);
    } else if (slope <= slope30) {
        const float upper = ordinate(mild);
        const float lower = steepness > 0.055f ? middle.y1 : ordinate(middle);
        y = blend(0.02f, slope30, upper, lower);
    } else if (slope <= 0.05f) {
        const float upper = ordinate(middle);
        const float lower = steepness > 0.045f ? steep.y1 : ordinate(steep);
        y = blend(slope30, 0.05f, upper, lower);
    } else if (slope <= 0.1f) {
        const float upper = ordinate(steep);
        const float lower = steepness > 0.025f ? steepest.y1 : ordinate(steepest);
        y = blend(0.05f, 0.1f, upper, lower);
    } else {
        y = steepness > 0.025f ? steepest.y1 : ordinate(steepest);
    }
    const float ratio = static_cast<float>(std::pow(10.0, std::pow(10.0, static_cast<double>(y))));
    return static_cast<float>(static_cast<double>(deep_water_height) * ratio);
}

}  // namespace legacy::runup
