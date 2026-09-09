// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#ifndef FEQ_DECIMAL_HPP
#define FEQ_DECIMAL_HPP

#include <array>
#include <cstdint>

namespace feq {

enum class DecimalEdit : std::uint32_t {
    exponential = 0,
    fixed = 4,
    general = 8,
    engineering = 12
};

struct DecimalDigits {
    std::array<char,16> digits;
    std::int32_t count;
    // For F/E/G, value magnitude is 0.<digits> * 10^exponent, before the
    // edit descriptor's scale factor. EN subtracts engineering_shift here.
    std::int32_t exponent;
    std::uint32_t status; // 0: finite; 4: Inf or NaN, with three text bytes.
    std::uint16_t general_state; // 4 selects fixed rendering for a G descriptor.
    std::int16_t engineering_shift;
};

// Reproduce the released REAL*4 conversion stage, including its nine digit
// ceiling, binary scaling and halfway decisions. This does not apply a sign,
// field width, decimal point, exponent suffix or leading/trailing padding.
// precision is an unsigned descriptor byte (0..255); scale is signed 16 bit.
// Both input signs produce the same magnitude digits. IEEE special values are
// handled by bit inspection; no arithmetic is performed on signaling NaNs.
DecimalDigits decimal_digits(float value, DecimalEdit edit, int precision, int scale = 0);

} // namespace feq
#endif
