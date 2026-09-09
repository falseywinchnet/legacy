// XLKT22: hydraulic section properties including alpha and critical flow.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/section_energy.hpp>
#include <cmath>
#include <stdexcept>

namespace feq {
EnergySectionProperties interpolate_energy_section(float depth,
    const EnergySectionRow& lower, const EnergySectionRow& upper,
    bool has_slopes, const EnergySectionRow* following) {
    const SectionTableRow& low = lower.section;
    const SectionTableRow& high = upper.section;
    if (!std::isfinite(depth) || !std::isfinite(low.depth) || !std::isfinite(high.depth) ||
        low.depth < 0.0F || high.depth <= low.depth || depth < low.depth || depth > high.depth) {
        throw std::invalid_argument("Energy section interpolation requires an increasing interval containing the depth.");
    }
    const double dy = static_cast<double>(high.depth)-low.depth;
    const double h = static_cast<double>(depth)-low.depth;
    const double half_h = h*0.5;
    // Unlike XLKT20/21, XLKT22 uses division, not a retained reciprocal.
    // DT, T, A store REAL while retaining their wider registers (0x4495f3,
    // 0x44960b, 0x449625). J reloads stored T at 0x449635.
    const double width_slope = (static_cast<double>(high.top_width)-low.top_width)/dy;
    const double width = low.top_width+h*width_slope;
    const double area = low.area+half_h*(width+low.top_width);
    EnergySectionProperties result{};
    result.section.top_width_slope = static_cast<float>(width_slope);
    result.section.top_width = static_cast<float>(width);
    result.section.area = static_cast<float>(area);
    // J = J0 + h/2*(A+A0-h*(REAL(T)-T0)*REAL(0.1666667)).
    const double correction = ((static_cast<double>(result.section.top_width)-low.top_width)*h)*
        static_cast<double>(0.1666667F);
    result.first_moment = static_cast<float>(lower.first_moment+half_h*((area+low.area)-correction));

    if (depth > 0.0F) {
        const EnergySectionRow* critical_lower = &lower;
        const EnergySectionRow* critical_upper = &upper;
        if (low.depth == 0.0F) {
            if (following == nullptr) {
                throw std::invalid_argument("Critical flow at a zero-depth interval needs the following row.");
            }
            critical_lower = &upper; critical_upper = following;
        }
        if (!std::isfinite(critical_upper->section.depth) ||
            critical_upper->section.depth <= critical_lower->section.depth ||
            !std::isfinite(critical_lower->critical_flow) || !std::isfinite(critical_upper->critical_flow) ||
            critical_lower->critical_flow <= 0.0F || critical_upper->critical_flow <= 0.0F) {
            throw std::invalid_argument("Critical-flow interpolation requires positive flows and increasing positive depths.");
        }
        // P = REAL(REAL(log(y/y0))*REAL(log(Qc1/Qc0))/REAL(log(y1/y0))).
        // Ratios stay wide through FYL2X; logs store REAL at 0x4496dd,
        // 0x4496f3 and 0x449708, then P stores REAL at 0x449710.
        const float depth_log = static_cast<float>(std::log(static_cast<double>(depth)/critical_lower->section.depth));
        const float flow_log = static_cast<float>(std::log(static_cast<double>(critical_upper->critical_flow)/critical_lower->critical_flow));
        const float interval_log = static_cast<float>(std::log(static_cast<double>(critical_upper->section.depth)/critical_lower->section.depth));
        const float exponent = static_cast<float>((static_cast<double>(depth_log)*flow_log)/interval_log);
        // Qc = Qc0*REAL(exp(P)); original exponential store at 0x449732.
        const float multiplier = static_cast<float>(std::exp(static_cast<double>(exponent)));
        result.critical_flow = static_cast<float>(static_cast<double>(critical_lower->critical_flow)*multiplier);
    }

    float root = 0.0F;
    float root_slope = 0.0F;
    if (!has_slopes) {
        const double beta_slope = (static_cast<double>(high.momentum_factor)-low.momentum_factor)/dy;
        const double alpha_slope = (static_cast<double>(upper.energy_factor)-lower.energy_factor)/dy;
        const double conveyance_slope = (static_cast<double>(high.sqrt_conveyance)-low.sqrt_conveyance)/dy;
        result.section.momentum_factor_slope = static_cast<float>(beta_slope);
        result.section.momentum_factor = static_cast<float>(low.momentum_factor+h*beta_slope);
        result.energy_factor_slope = static_cast<float>(alpha_slope);
        result.energy_factor = static_cast<float>(lower.energy_factor+h*alpha_slope);
        root_slope = static_cast<float>(conveyance_slope);
        root = static_cast<float>(low.sqrt_conveyance+h*conveyance_slope);
    } else {
        // Hermite interpolation in p=h/dy, preserving the original factors
        // and their reuse for beta, alpha and sqrt(K), 0x4497be..0x449a22.
        const double p = h/dy;
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
        const double difference_derivative = ((complement*6.0)*p)/dy;
        result.section.momentum_factor = static_cast<float>(
            ((left_slope*low.momentum_factor_slope+right_slope*high.momentum_factor_slope)+
             left_value*low.momentum_factor)+right_value*high.momentum_factor);
        result.section.momentum_factor_slope = static_cast<float>(
            (left_derivative*low.momentum_factor_slope+right_derivative*high.momentum_factor_slope)+
            difference_derivative*(static_cast<double>(high.momentum_factor)-low.momentum_factor));
        result.energy_factor = static_cast<float>(
            ((left_slope*lower.energy_factor_slope+right_slope*upper.energy_factor_slope)+
             left_value*lower.energy_factor)+right_value*upper.energy_factor);
        result.energy_factor_slope = static_cast<float>(
            (left_derivative*lower.energy_factor_slope+right_derivative*upper.energy_factor_slope)+
            difference_derivative*(static_cast<double>(upper.energy_factor)-lower.energy_factor));
        root = static_cast<float>(
            ((left_slope*low.sqrt_conveyance_slope+right_slope*high.sqrt_conveyance_slope)+
             left_value*low.sqrt_conveyance)+right_value*high.sqrt_conveyance);
        root_slope = static_cast<float>(
            (left_derivative*low.sqrt_conveyance_slope+right_derivative*high.sqrt_conveyance_slope)+
            difference_derivative*(static_cast<double>(high.sqrt_conveyance)-low.sqrt_conveyance));
    }
    // Both sqrt(K) and its derivative reload their REAL output storage.
    result.section.conveyance_slope = static_cast<float>((static_cast<double>(root)+root)*root_slope);
    result.section.conveyance = static_cast<float>(static_cast<double>(root)*root);
    return result;
}
}
