// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
// Original FEQ 10.61 runtime: _jwe_iroc RVA 0xe3fd0, _jwe_igetfig 0xe55a0.
#include <feq/decimal.hpp>

#include <bit>
#include <cstddef>
#include <limits>
#include <stdexcept>

namespace feq {
namespace {
static_assert(sizeof(float) == 4 && std::numeric_limits<float>::is_iec559 &&
              std::numeric_limits<float>::digits == 24);
static_assert(sizeof(double) == 8 && std::numeric_limits<double>::is_iec559 &&
              std::numeric_limits<double>::digits == 53);

int figure_count(DecimalEdit edit, int precision, int scale, int exponent, DecimalDigits& result) {
    int count = precision+scale;
    if (edit == DecimalEdit::fixed) {
        count += exponent;
    } else if (edit == DecimalEdit::general) {
        result.general_state = 0;
        if (exponent > -1 && exponent <= precision) {
            result.general_state = 4;
            count = precision;
        }
    } else if (edit == DecimalEdit::engineering) {
        // Three decimal digits per engineering exponent step. C++ remainder,
        // like the released IDIV, has the sign of the dividend.
        const int shifts[5] = {1,2,3,1,2};
        result.engineering_shift = static_cast<std::int16_t>(shifts[exponent%3+2]);
        count = precision+result.engineering_shift;
    }
    return count < 9 ? count : 9;
}

void carry(std::array<char,16>& digits, int count) {
    int index = count-1;
    while (index >= 0 && digits[static_cast<std::size_t>(index)] == '9') {
        --index;
    }
    // The released routine leaves an all-nine buffer unchanged here; its
    // preceding normalization handles carries that cross the decimal decade.
    if (index >= 0) {
        ++digits[static_cast<std::size_t>(index)];
        for (++index; index < count; ++index) {
            digits[static_cast<std::size_t>(index)] = '0';
        }
    }
}
}

DecimalDigits decimal_digits(float value, DecimalEdit edit, int precision, int scale) {
    if (precision < 0 || precision > 255 || scale < -32768 || scale > 32767 ||
        (edit != DecimalEdit::exponential && edit != DecimalEdit::fixed &&
         edit != DecimalEdit::general && edit != DecimalEdit::engineering)) {
        throw std::invalid_argument("Decimal conversion requires a supported edit, byte precision and signed 16-bit scale.");
    }
    DecimalDigits result{};
    result.digits.fill(' ');
    const std::uint32_t bits = std::bit_cast<std::uint32_t>(value)&0x7fffffffU;
    if (bits >= 0x7f800000U) {
        const char* text = bits == 0x7f800000U ? "Inf" : "NaN";
        for (int index = 0; index < 3; ++index) {
            result.digits[static_cast<std::size_t>(index)] = text[index];
        }
        result.count = 3;
        result.status = 4;
        return result;
    }
    const double magnitude = std::bit_cast<float>(bits);
    int binary_exponent = static_cast<int>((bits >> 23)&255U)-127;
    if (binary_exponent == -127) {
        // Subnormal normalization has a deliberate binary32 store. Zero also
        // takes this path in the released digit converter (layout handles it).
        const float normalized = static_cast<float>(magnitude*33554432.0);
        binary_exponent = static_cast<int>((std::bit_cast<std::uint32_t>(normalized) >> 23)&255U)-152;
    }
    int exponent = static_cast<int>(binary_exponent*0.301029995664);
    const int power = 56-exponent;
    const int group = static_cast<int>(power*0.07142857142857142);
    const int remainder = power-14*group;
    const double powers[15] = {1.0,1e1,1e2,1e3,1e4,1e5,1e6,1e7,1e8,1e9,1e10,1e11,1e12,1e13,1e14};
    const double groups[8] = {1e-56,1e-42,1e-28,1e-14,1.0,1e14,1e28,1e42};
    // x = |value|*10^-exponent. The two products and subsequent divisions
    // must remain separate binary64 operations, as in the 53-bit x87 mode.
    double x = (powers[remainder]*groups[group])*magnitude;
    for (int index = 0; index < 2 && x >= 1.0; ++index) {
        x *= 0.1;
        ++exponent;
    }
    int count = figure_count(edit,precision,scale,exponent,result);
    if (count >= 0) {
        double y = x;
        double ninth_tail = 0.0;
        std::array<char,16> unrounded{};
        for (int index = 0; index < 16; ++index) {
            y *= 10.0;
            const int digit = static_cast<int>(y);
            unrounded[static_cast<std::size_t>(index)] = static_cast<char>('0'+digit);
            y -= digit;
            if (index == 8) {
                ninth_tail = y;
            }
        }
        // Original 0x4e41ab/0x4e42ef: binary32 is intentional. It repairs a
        // decimal tail that scaled just below 10 in binary64.
        if (static_cast<int>(static_cast<float>(ninth_tail*10.0)) == 10) {
            carry(unrounded,16);
        }
        bool halfway = unrounded[static_cast<std::size_t>(count)] == '5';
        for (int index = count+1; index < 16 && halfway; ++index) {
            halfway = unrounded[static_cast<std::size_t>(index)] == '0';
        }
        const bool even = count == 0 ? exponent == 0 :
            (unrounded[static_cast<std::size_t>(count-1)]-'0')%2 == 0;
        if (!(halfway && even)) {
            const double half[10] = {0.5,0.05,0.005,0.0005,0.00005,0.000005,
                                    0.0000005,0.00000005,0.000000005,0.0000000005};
            x += half[count];
        }
    }
    if (x >= 1.0) {
        x *= 0.1;
        ++exponent;
        if (edit == DecimalEdit::fixed) {
            count = count < 9 ? count+1 : 9;
        } else if (edit != DecimalEdit::exponential) {
            count = figure_count(edit,precision,scale,exponent,result);
        }
    }
    result.count = count > 0 ? count : 0;
    for (int index = 0; index < result.count; ++index) {
        x *= 10.0;
        const int digit = static_cast<int>(x);
        result.digits[static_cast<std::size_t>(index)] = static_cast<char>('0'+digit);
        x -= digit;
    }
    if (result.count > 0 && static_cast<int>(static_cast<float>(x*10.0)) == 10) {
        carry(result.digits,result.count);
    }
    result.exponent = exponent;
    if (edit == DecimalEdit::engineering) {
        result.exponent -= result.engineering_shift;
    }
    return result;
}

std::string list_real(float value) {
    const std::uint32_t bits = std::bit_cast<std::uint32_t>(value);
    const std::uint32_t magnitude = bits&0x7fffffffU;
    if (magnitude == 0) {
        return "0.00000000E+00";
    }
    const DecimalDigits converted = decimal_digits(value,DecimalEdit::general,9);
    std::string text;
    if ((bits&0x80000000U) != 0) {
        text += '-';
    }
    if (converted.status != 0) {
        text.append(converted.digits.data(),3);
        return text;
    }
    // _jwe_ilor selects a G field for 0.1 <= |value| < 10^9, and a
    // one-leading-digit exponential field outside that interval. G's decimal
    // point follows exponent digits: value = 0.<digits> * 10^exponent.
    if (converted.general_state == 4) {
        if (converted.exponent == 0) {
            text += "0.";
        }
        for (int index = 0; index < 9; ++index) {
            text += converted.digits[static_cast<std::size_t>(index)];
            if (index+1 == converted.exponent) {
                text += '.';
            }
        }
    } else {
        text += converted.digits[0];
        text += '.';
        text.append(converted.digits.data()+1,8);
        const int exponent = converted.exponent-1;
        const int absolute_exponent = exponent < 0 ? -exponent : exponent;
        text += exponent < 0 ? "E-" : "E+";
        if (absolute_exponent < 10) {
            text += '0';
        }
        text += std::to_string(absolute_exponent);
    }
    return text;
}
} // namespace feq
