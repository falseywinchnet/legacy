// Recovered, portable implementation of the original Lahey power arithmetic.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/power.hpp>
#include <bit>
#include <cmath>
#include <cstdint>
#include <stdexcept>

namespace feq {
namespace {
#include "power_coefficients.inc"

constexpr double double_limit = 0x1.fffffffffffb6p+1023;
constexpr float real_limit = 0x1.ffffdcp+127F;

// Split at 26 significant bits. This exactly reproduces the original low-word
// mask used to retain separate high and low logarithm/product contributions.
double high_part(double value) {
    return std::bit_cast<double>(std::bit_cast<std::uint64_t>(value) & UINT64_C(0xfffffffff8000000));
}

bool negative_result(double base, double exponent) {
    if (!std::isfinite(base) || !std::isfinite(exponent) ||
        (base == 0.0 && exponent < 0.0) || (base < 0.0 && std::trunc(exponent) != exponent)) {
        throw std::invalid_argument("Invalid argument to the released power calculation.");
    }
    // Integers above 2^53 are even in binary64; subtraction avoids converting
    // arbitrary floating exponents to an overflowing integer type.
    return base < 0.0 && std::trunc(exponent*0.5) != exponent*0.5;
}

double double_kernel(double base, double exponent) {
    std::uint64_t word = std::bit_cast<std::uint64_t>(base);
    std::uint32_t upper = static_cast<std::uint32_t>(word >> 32);
    const int binary_exponent = std::bit_cast<std::int32_t>(upper-0x3fe80000U) >> 20;
    // The original leaves binary_exponent at its pre-normalization value for
    // subnormal input. Preserve that released behavior, rather than substituting
    // an algebraically corrected result for this uncommon input class.
    if (upper < 0x00100000U) {
        base *= 4503599627370496.0;
        word = std::bit_cast<std::uint64_t>(base);
        upper = static_cast<std::uint32_t>(word >> 32);
    }
    const int normalized_exponent = std::bit_cast<std::int32_t>(upper-0x3fe80000U) >> 20;
    upper -= static_cast<std::uint32_t>(normalized_exponent) << 20;
    const unsigned int index = (upper >> 11) & 511U;
    const double mantissa = std::bit_cast<double>((static_cast<std::uint64_t>(upper) << 32) | (word & 0xffffffffU));
    const double center = std::bit_cast<double>(static_cast<std::uint64_t>(upper & 0x7ffff800U) << 32);
    // log2(m) = log2(center) + 2/ln(2) * (u + u^3/3 + u^5/5),
    // u = (m-center)/(m+center). The released coefficients and operation order
    // include the approximation's original last-bit rounding.
    const double u = (mantissa-center)/(mantissa+center);
    const double square = u*u;
    const double logarithm_high = logarithm_table[index*2];
    const double logarithm_low = (0.5770786084392676*square+0.9617966939257624)*(square*u) +
        (logarithm_table[index*2+1]+2.8853900817779268*u);
    const double logarithm = (logarithm_high+binary_exponent)+logarithm_low;
    const double residual = ((binary_exponent-logarithm)+logarithm_high)+logarithm_low;
    const double high_exponent = high_part(exponent);
    const double high_logarithm = high_part(logarithm);
    const std::uint32_t log_upper = static_cast<std::uint32_t>(std::bit_cast<std::uint64_t>(logarithm) >> 32);
    const std::uint32_t exp_upper = static_cast<std::uint32_t>(std::bit_cast<std::uint64_t>(exponent) >> 32);
    if ((log_upper & 0x7ff00000U)+(exp_upper & 0x7ff00000U) > 0x80900000U) {
        return ((log_upper ^ exp_upper) & 0x80000000U) != 0 ? 0.0 : double_limit;
    }
    const double high_product = high_logarithm*high_exponent;
    const double rounded = 105553116266496.0+high_product;
    const std::uint32_t rounded_word = static_cast<std::uint32_t>(std::bit_cast<std::uint64_t>(rounded));
    const unsigned int fraction_index = rounded_word & 63U;
    const double remainder = (((logarithm-high_logarithm)+residual)*exponent+
        (exponent-high_exponent)*high_logarithm)+(high_product-(rounded-105553116266496.0));
    // 2^(k/64+r) = 2^(k/64) * (1 + r*P(r)). The table splits its
    // exponential into high/low words; scale is the integral power of two.
    const double polynomial = ((0.0013333546285662563*remainder+0.009618143209793031)*(remainder*remainder)+
        (0.0555041086649867*remainder+0.24022650695877795))*remainder+0.6931471805599453;
    const double value = ((remainder*exponential_table[fraction_index*2])*polynomial+
        exponential_table[fraction_index*2+1])+exponential_table[fraction_index*2];
    const std::uint32_t value_upper = static_cast<std::uint32_t>(std::bit_cast<std::uint64_t>(value) >> 32);
    const std::int32_t integral = (std::bit_cast<std::int32_t>((value_upper & 0x7ff00000U)-0x3fefc001U) >> 14) -
        static_cast<std::int32_t>(fraction_index)+std::bit_cast<std::int32_t>(rounded_word);
    if (integral >= 0x10000) { return double_limit; }
    if (integral <= -0xffc0) { return 0.0; }
    const std::uint32_t scale_upper = (rounded_word-fraction_index+0xffc0U) << 14;
    const double scale = std::bit_cast<double>(static_cast<std::uint64_t>(scale_upper) << 32);
    return scale*value;
}

float real_kernel(float base, float exponent) {
    const std::uint64_t word = std::bit_cast<std::uint64_t>(static_cast<double>(base));
    const std::uint32_t upper = static_cast<std::uint32_t>(word >> 32);
    const std::uint32_t exponent_mask = upper & 0xfff00000U;
    const std::uint32_t shift = exponent_mask-0x3fe00000U-((upper-0x6a09eU-exponent_mask) & 0x100000U);
    const int binary_exponent = std::bit_cast<std::int32_t>(shift) >> 20;
    const double mantissa = std::bit_cast<double>((static_cast<std::uint64_t>(upper-shift) << 32) | (word & 0xffffffffU));
    const double difference = mantissa-1.0;
    const double u = difference/(mantissa+1.0);
    const double square = u*u;
    const double polynomial = (0.2992565069*square+0.3997479494)*square+0.6666681595;
    const double exponent_log2e = static_cast<double>(exponent)*1.442695040888963;
    const double logarithm = ((square*u)*exponent_log2e)*polynomial -
        ((difference*u-difference)*exponent_log2e-static_cast<double>(exponent)*binary_exponent);
    if (logarithm < -127.0) { return 0.0F; }
    if (logarithm >= 128.0) { return real_limit; }
    const double rounded = logarithm+422212465065984.0;
    const std::uint32_t rounded_word = static_cast<std::uint32_t>(std::bit_cast<std::uint64_t>(rounded));
    const unsigned int index = rounded_word & 15U;
    const double remainder = (422212465065984.0-rounded)+logarithm;
    const std::uint32_t scale_upper = ((rounded_word-index) << 16)+0x3ff00000U;
    const double scale = std::bit_cast<double>(static_cast<std::uint64_t>(scale_upper) << 32);
    const double exponential = (0.009617941096744*remainder+0.05550573627825)*(remainder*remainder)+
        (0.2402265072804*remainder+0.6931471801626);
    const double value = ((remainder*real_exponential_table[index])*exponential+real_exponential_table[index])*scale;
    return static_cast<float>(value);
}
}

float legacy_power(float base, float exponent) {
    const bool negative = negative_result(base,exponent);
    if (exponent == 0.0F) { return 1.0F; }
    if (exponent > 0.0F && exponent < 8.0F && std::trunc(exponent) == exponent) {
        float value = base;
        const int count = static_cast<int>(exponent);
        for (int index = 1; index < count; ++index) { value = static_cast<float>(static_cast<double>(value)*base); }
        return value;
    }
    if (base == 0.0F) { return 0.0F; }
    const float value = real_kernel(std::abs(base),exponent);
    return negative ? -value : value;
}

double legacy_power(double base, double exponent) {
    const bool negative = negative_result(base,exponent);
    if (exponent == 0.0) { return 1.0; }
    if (exponent > 0.0 && exponent < 8.0 && std::trunc(exponent) == exponent) {
        double value = base;
        const int count = static_cast<int>(exponent);
        for (int index = 1; index < count; ++index) { value *= base; }
        return value;
    }
    if (base == 0.0) { return 0.0; }
    const double value = double_kernel(std::abs(base),exponent);
    return negative ? -value : value;
}
}
