// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/channel_rating.hpp>
#include <feq/power.hpp>

namespace feq {
double channel_upstream_elevation(float head, float datum) {
    // ZL = Hup+Hdatum; FRFCHN 0x406df8..0x406e09 stores YL=ZL-ZbotL
    // as REAL but retains ZL without a REAL store for both later exits.
    return static_cast<double>(datum)+head;
}

float channel_free_drop(double upstream_elevation, float downstream_depth,
    float downstream_bed) {
    // FDROP = ZL-(Yr+ZbotR). FRFCHN 0x406f7b..0x406f8d and
    // 0x40711b..0x40712d retain ZR through subtraction, then store REAL.
    return static_cast<float>(upstream_elevation-
        (static_cast<double>(downstream_depth)+downstream_bed));
}

float channel_partial_free_drop(int index, int count, float power) {
    // PFD(i) = REAL((i-1)/(N-1))**power. CHNTAB 0x407f86..0x408062
    // retains the reciprocal, stores its product as REAL, and calls _g_arxr.
    const double reciprocal = 1.0/(count-1);
    const float fraction = static_cast<float>((index-1)*reciprocal);
    return legacy_power(fraction,power);
}
}
