// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
// FEQUTL 5.80 ufgate.for:379-408; released LSTOPF 0x47f002..0x47f174.
#include <feq/power_spacing.hpp>
#include <cmath>

namespace feq {
int power_breakpoints(float first, float last, float offset, float argument_ratio,
    float* points, int capacity, int& error_flag) {
    // R=REAL((B+offset)/(A+offset)), LB=REAL(log(R)), LR=REAL(log(r)).
    // Both logarithms cross explicit REAL stores. Their quotient remains wide
    // until IPOW=truncate(LB/LR+1); the source's POW has no REAL store here.
    const float limit_ratio = static_cast<float>((static_cast<double>(last)+offset)/
        (static_cast<double>(first)+offset));
    const float limit_log = static_cast<float>(std::log(static_cast<double>(limit_ratio)));
    const float argument_log = static_cast<float>(std::log(static_cast<double>(argument_ratio)));
    const int intervals = static_cast<int>(static_cast<double>(limit_log)/argument_log+1.0);
    const int count = intervals+1;
    // r=REAL(exp(LB/IPOW)); the retained division feeds the exponential.
    const float ratio = static_cast<float>(std::exp(static_cast<double>(limit_log)/intervals));
    if (count > capacity) {
        error_flag = 1;
        return -1;
    }
    points[0] = static_cast<float>(static_cast<double>(first)+offset);
    points[count-1] = static_cast<float>(static_cast<double>(last)+offset);
    int index = 1;
    // The released loop generates pairs: its first product is stored but
    // retained for the second multiply (0x47f0e4 FST, 0x47f0e8 FMULP).
    // Each new pair starts from the preceding pair's stored last point.
    for (; index+1 < count-1; index += 2) {
        const double product = static_cast<double>(ratio)*points[index-1];
        points[index] = static_cast<float>(product);
        points[index+1] = static_cast<float>(product*ratio);
    }
    if (index < count-1) {
        points[index] = static_cast<float>(static_cast<double>(ratio)*points[index-1]);
    }
    if (offset != 0.0F) {
        for (index = 0; index < count; ++index) {
            points[index] = static_cast<float>(static_cast<double>(points[index])-offset);
        }
    }
    return count;
}
} // namespace feq
