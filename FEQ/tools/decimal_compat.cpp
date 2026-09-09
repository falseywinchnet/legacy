// Bridge the independently verified digit converter to the research runtime.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/decimal.hpp>
#include <bit>
#include <cstddef>
#include <cstring>
#include <string>

namespace {
char digit(const feq::DecimalDigits& converted, int index) {
    return index >= 0 && index < converted.count ? converted.digits[static_cast<std::size_t>(index)] : '0';
}
int copy_result(char* buffer, int capacity, const std::string& text) {
    if (capacity <= 0 || text.size() >= static_cast<std::size_t>(capacity)) {
        return -1;
    }
    std::memcpy(buffer,text.c_str(),text.size()+1);
    return static_cast<int>(text.size());
}
}

extern "C" int feq_decimal_fixed(char* buffer, int capacity, float value, int precision, int scale) {
    try {
        if (precision < 0 || precision >= capacity) {
            return -1;
        }
        const feq::DecimalDigits converted = feq::decimal_digits(value,feq::DecimalEdit::fixed,
                                                               precision < 255 ? precision : 255,scale);
        if (converted.status != 0) {
            return copy_result(buffer,capacity,std::string(converted.digits.data(),3));
        }
        const int before = converted.exponent+scale;
        if (before > capacity-precision-2) {
            return -1;
        }
        std::string text;
        if (before <= 0) {
            text += '0';
        } else {
            for (int index = 0; index < before; ++index) {
                text += digit(converted,index);
            }
        }
        text += '.';
        for (int index = 0; index < precision; ++index) {
            text += digit(converted,before+index);
        }
        return copy_result(buffer,capacity,text);
    } catch (...) {
        return -1;
    }
}

extern "C" int feq_decimal_exponential(char* buffer, int capacity, float value, int precision) {
    try {
        if (precision < 0 || precision > 254 || precision > capacity-8) {
            return -1;
        }
        const feq::DecimalDigits converted = feq::decimal_digits(value,feq::DecimalEdit::exponential,precision+1);
        if (converted.status != 0) {
            return copy_result(buffer,capacity,std::string(converted.digits.data(),3));
        }
        std::string text;
        text += digit(converted,0);
        text += '.';
        for (int index = 1; index <= precision; ++index) {
            text += digit(converted,index);
        }
        const bool zero = (std::bit_cast<std::uint32_t>(value)&0x7fffffffU) == 0;
        const int exponent = zero ? 0 : converted.exponent-1;
        const int magnitude = exponent < 0 ? -exponent : exponent;
        text += 'E';
        text += exponent < 0 ? '-' : '+';
        if (magnitude < 10) {
            text += '0';
        }
        text += std::to_string(magnitude);
        return copy_result(buffer,capacity,text);
    } catch (...) {
        return -1;
    }
}

extern "C" int feq_decimal_list_real(char* buffer, int capacity, float value) {
    try {
        return copy_result(buffer,capacity," "+feq::list_real(value));
    } catch (...) {
        return -1;
    }
}
