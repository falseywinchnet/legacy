// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
// Equations: FEQ 10.61 SHARE/fqshrftb.for:5204-5260 (XLKT20).
// Original XLKT20 RVA 0x3a7f0 and XXLKT20 RVA 0xbf70 define rounding points.
#include <feq/section_interpolation.hpp>

#include <cmath>
#include <limits>
#include <stdexcept>

namespace feq {

static_assert(std::numeric_limits<float>::is_iec559 && std::numeric_limits<float>::digits == 24);
static_assert(std::numeric_limits<double>::is_iec559 && std::numeric_limits<double>::digits == 53);

double section_station_fraction(float left, float right, float station) {
    // f = (station-left) * [1/(right-left)]. INTERP retains the reciprocal
    // across stations. Replacing this multiplication with division changes
    // output bits. FEQUTL 5.80: 0x442e8d, 0x443756, 0x4438a5.
    const double offset = static_cast<double>(station)-left;
    const double span = static_cast<double>(right)-left;
    return offset*(1.0/span);
}

SectionProperties interpolate_section(float depth, const SectionTableRow& lower,
                                      const SectionTableRow& upper, bool has_slopes) {
    if (!std::isfinite(depth) || !std::isfinite(lower.depth) || !std::isfinite(upper.depth) ||
        upper.depth <= lower.depth || depth < lower.depth || depth > upper.depth) {
        throw std::invalid_argument("Section interpolation requires an increasing interval containing the depth.");
    }
    const double dy = static_cast<double>(upper.depth)-lower.depth;
    const double h = static_cast<double>(depth)-lower.depth;
    const double inverse_dy = 1.0/dy;
    // T(y) = T0 + (y-y0)(T1-T0)/(y1-y0).
    // A(y) = A0 + (y-y0)(T(y)+T0)/2, the integral of the linear width.
    // Original FST at 0x43abd9 and 0x43abed stores DT and T as binary32,
    // retaining the wider register values for the following expression.
    const double width_slope = (static_cast<double>(upper.top_width)-lower.top_width)*inverse_dy;
    const double width = lower.top_width+h*width_slope;
    SectionProperties result{};
    result.top_width_slope = static_cast<float>(width_slope);
    result.top_width = static_cast<float>(width);
    result.area = static_cast<float>(lower.area+(0.5*h)*(width+lower.top_width));

    float root_conveyance = 0.0f;
    float root_slope = 0.0f;
    if (!has_slopes) {
        // B and sqrt(K) use linear interpolation. Their derivative stores
        // also retain the unrounded registers (0x43ac45 and 0x43ac6a).
        const double beta_slope = (static_cast<double>(upper.momentum_factor)-lower.momentum_factor)*inverse_dy;
        const double k_slope = (static_cast<double>(upper.sqrt_conveyance)-lower.sqrt_conveyance)*inverse_dy;
        result.momentum_factor_slope = static_cast<float>(beta_slope);
        result.momentum_factor = static_cast<float>(lower.momentum_factor+h*beta_slope);
        root_slope = static_cast<float>(k_slope);
        root_conveyance = static_cast<float>(lower.sqrt_conveyance+h*k_slope);
    } else {
        // Cubic Hermite interpolation for B and sqrt(K). With p=h/dy:
        // F = h10*dy*F0' + h11*dy*F1' + h00*F0 + h01*F1.
        // h10=(1-p)^2*p, h11=-(1-p)*p^2,
        // h00=(2*p+1)*(1-p)^2, h01=(3-2*p)*p^2.
        // Keep the released expression ordering, including reused factors.
        const double p = h*inverse_dy;
        const double complement = 1.0-p;
        const double initial_left_slope = (complement*p)*dy;
        const double right_slope = -(initial_left_slope*p);
        const double left_slope = initial_left_slope*complement;
        const double initial_left_value = (p+p)+1.0;
        const double right_value = ((4.0-initial_left_value)*p)*p;
        const double left_value = initial_left_value*(complement*complement);
        const double initial_left_derivative = 1.0-3.0*p;
        const double right_derivative = -((1.0+initial_left_derivative)*p);
        const double left_derivative = initial_left_derivative*complement;
        const double difference_derivative = ((6.0*complement)*p)*inverse_dy;
        result.momentum_factor = static_cast<float>(
            ((left_slope*lower.momentum_factor_slope+right_slope*upper.momentum_factor_slope)+
             left_value*lower.momentum_factor)+right_value*upper.momentum_factor);
        result.momentum_factor_slope = static_cast<float>(
            (left_derivative*lower.momentum_factor_slope+right_derivative*upper.momentum_factor_slope)+
            difference_derivative*(static_cast<double>(upper.momentum_factor)-lower.momentum_factor));
        root_conveyance = static_cast<float>(
            ((left_slope*lower.sqrt_conveyance_slope+right_slope*upper.sqrt_conveyance_slope)+
             left_value*lower.sqrt_conveyance)+right_value*upper.sqrt_conveyance);
        root_slope = static_cast<float>(
            (left_derivative*lower.sqrt_conveyance_slope+right_derivative*upper.sqrt_conveyance_slope)+
            difference_derivative*(static_cast<double>(upper.sqrt_conveyance)-lower.sqrt_conveyance));
    }
    // K=(sqrt(K))^2 and K'=2*sqrt(K)*(sqrt(K))'. Both values are reloaded
    // from binary32 output storage before this calculation (0x43adef onward).
    result.conveyance_slope = static_cast<float>(
        (static_cast<double>(root_conveyance)+root_conveyance)*root_slope);
    result.conveyance = static_cast<float>(static_cast<double>(root_conveyance)*root_conveyance);
    return result;
}

float interpolate_section_first_moment(float depth, const SectionTableRow& lower,
                                       const SectionTableRow& upper, float lower_first_moment) {
    if (!std::isfinite(depth) || !std::isfinite(lower.depth) || !std::isfinite(upper.depth) ||
        upper.depth <= lower.depth || depth < lower.depth || depth > upper.depth) {
        throw std::invalid_argument("Section interpolation requires an increasing interval containing the depth.");
    }
    const double dy = static_cast<double>(upper.depth)-lower.depth;
    const double h = static_cast<double>(depth)-lower.depth;
    const double half_h = 0.5*h;
    const double width_slope = (static_cast<double>(upper.top_width)-lower.top_width)*(1.0/dy);
    const double wide_width = lower.top_width+h*width_slope;
    const double wide_area = lower.area+half_h*(wide_width+lower.top_width);
    // J(y) = J0 + h/2 * [A(y)+A0-h*(T(y)-T0)*0.1666667].
    // The released decimal approximation to 1/6 is a binary32 constant.
    // XLKT21 FST at 0x43b2c0 retains wide A. The subtraction at 0x43b2d2
    // reloads T from binary32 storage; substituting wide T changes J's bits.
    const float stored_width = static_cast<float>(wide_width);
    const double correction = (h*(static_cast<double>(stored_width)-lower.top_width))*0.1666667f;
    return static_cast<float>(lower_first_moment+half_h*((wide_area+lower.area)-correction));
}

float interpolate_scalar_first_moment(float depth, float lower_depth,
    float lower_width, float lower_area, float lower_first_moment,
    float upper_depth, float upper_width) {
    const double interval = static_cast<double>(upper_depth)-lower_depth;
    const double h = static_cast<double>(depth)-lower_depth;
    const double half_h = h*0.5;
    const double slope = (static_cast<double>(upper_width)-lower_width)/interval;
    const double width = h*slope+lower_width;
    const double area = (width+lower_width)*half_h+lower_area;
    // J=J0+h/2*[A+A0-h*(T-T0)*REAL(1/6)]. LKTJ 0x4784af..0x4784ef
    // has no intermediate REAL stores; its constant is bits 0x3e2aaaab.
    const double correction = ((width-lower_width)*h)*0.1666666716337204;
    return static_cast<float>(((area+lower_area)-correction)*half_h+lower_first_moment);
}

} // namespace feq
