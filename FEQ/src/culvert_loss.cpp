// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/culvert_loss.hpp>

namespace feq {
double culvert_discharge_coefficient(const CulvertCoefficientInput& input, int& ratio_flag) {
    double coefficient = 0.95F;
    if (input.shape == CulvertShape::pipe || input.shape == CulvertShape::flared ||
        input.shape == CulvertShape::miter) {
        // R = (Z1TRUE-ZB2)/DUP. Original FCD123 keeps R wide throughout
        // its bounds, reset, and polynomial; no REAL R store intervenes.
        double ratio = (static_cast<double>(input.upstream_level)-input.entrance_bed)/input.upstream_height;
        if (ratio <= 0.0 || ratio > 1.6F) {
            if (ratio_flag == 0) { ratio_flag = 1; }
            ratio = 1.599F;
        }
        if (input.shape == CulvertShape::miter) {
            // C = .74542+R*(.50912+R*(-.46277+R*.077665)).
            coefficient = ratio < 0.4F ? static_cast<double>(0.88F) :
                0.74542F+ratio*(0.50912F+ratio*(-0.46277F+ratio*0.077665F));
        } else {
            // C = .86773+R*(.31564+R*(-.48463+R*(.22841-R*.04183))).
            coefficient = ratio < 0.4F ? static_cast<double>(0.93F) :
                0.86773F+ratio*(0.31564F+ratio*(-0.48463F+ratio*(0.22841F-ratio*0.04183F)));
        }
        if (input.shape != CulvertShape::flared) {
            coefficient = (static_cast<double>(input.rounding_factor)*input.projection_factor)*coefficient;
        }
    } else if (input.shape == CulvertShape::box) {
        if (input.flow_type == 3) {
            // FR = Q3/QC remains wide at 0x429f20, including the strict
            // 1.1F bound. C = .7269+FR*(.3333-FR*.1102).
            double froude = static_cast<double>(input.flow)/input.critical_flow;
            if (froude > 1.1F) { froude = 1.0; }
            coefficient = 0.7269F+froude*(0.3333F-froude*0.1102F);
        }
        coefficient = ((static_cast<double>(input.rounding_factor)*input.wing_factor)*
            input.projection_factor)*coefficient;
    }
    // Cap the wide return before the caller's REAL store (0x42a05c).
    return coefficient > 0.98F ? static_cast<double>(0.98F) : coefficient;
}

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
