// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/culvert_loss.hpp>

namespace feq {
double culvert_contraction(float coefficient, float approach_area, float control_area) {
    // M = max(0,1-A/A1). Original DEGCON retains M in a 53-bit register.
    double contraction = 1.0-static_cast<double>(control_area)/approach_area;
    if (contraction < 0.0) { contraction = 0.0; }
    if (contraction > 0.80F) { return coefficient; }
    // CD = .98-(.98-C123)*M/.80. Original 0x429229 multiplies by the
    // stored REAL reciprocal 1.25 at VA 0x569888, and returns without a
    // REAL rounding store. Preserve the exact .98F and .80F constants.
    return static_cast<double>(0.98F)-((static_cast<double>(0.98F)-coefficient)*contraction)*1.25;
}
float culvert_head_loss(float coefficient, float flow, float area, float twice_gravity) {
    // Original 0x42dbd1..0x42dc04 retains Q/A through the square. The first
    // REAL store is DH at 0x42dc01. GRAV2 is the supplied 2*g constant.
    const double velocity = static_cast<double>(flow)/area;
    const double multiplier = 1.0/(static_cast<double>(coefficient)*coefficient)-1.0;
    return static_cast<float>((multiplier*(velocity*velocity))/twice_gravity);
}
}
