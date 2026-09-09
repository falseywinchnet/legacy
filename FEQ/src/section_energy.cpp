// XLKT22: hydraulic section properties including alpha and critical flow.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/section_energy.hpp>
#include <bit>
#include <cmath>
#include <cstdint>
#include <stdexcept>

namespace feq {
double specific_energy_residual(float depth, float area, float energy_factor,
    float flow, float gravity, float target_energy) {
    // FEQUTL 5.80 FISE 0x411100/0x411189:
    // R = (Y + (0.5*alpha)*Q^2/(A^2*g))/ET - 1.
    // Q^2, A^2 and the returned residual retain the original wide arithmetic.
    const double squared_flow = static_cast<double>(flow)*flow;
    const double numerator = (static_cast<double>(energy_factor)*0.5)*squared_flow;
    const double denominator = (static_cast<double>(area)*area)*gravity;
    return (numerator/denominator+depth)/target_energy-1.0;
}
float logarithmic_critical_flow(float depth, float lower_depth, float upper_depth,
    float lower_flow, float upper_flow) {
    if (!std::isfinite(depth) || depth < 0.0F || !std::isfinite(lower_depth) ||
        !std::isfinite(upper_depth) || lower_depth <= 0.0F || upper_depth <= lower_depth ||
        !std::isfinite(lower_flow) || !std::isfinite(upper_flow) || lower_flow <= 0.0F || upper_flow <= 0.0F) {
        throw std::invalid_argument("Critical-flow interpolation requires positive flows and increasing positive depths.");
    }
    if (depth == 0.0F) {
        // LKTQC evaluates log(0), then the inline exponential subtracts
        // infinite integer and fractional parts. The released x87 result is
        // the negative quiet indefinite NaN, captured as REAL bits ffc00000.
        return std::bit_cast<float>(std::uint32_t{0xffc00000U});
    }
    // P = REAL(REAL(log(y/y0))*REAL(log(Qc1/Qc0))/REAL(log(y1/y0))).
    // Ratios remain wide through FYL2X; each log and then P store REAL.
    // XLKT22: 0x4496dd/0x4496f3/0x449708/0x449710.
    // LKTQC: 0x44b963/0x44b973/0x44b987/0x44b98d.
    const float depth_log = static_cast<float>(std::log(static_cast<double>(depth)/lower_depth));
    const float flow_log = static_cast<float>(std::log(static_cast<double>(upper_flow)/lower_flow));
    const float interval_log = static_cast<float>(std::log(static_cast<double>(upper_depth)/lower_depth));
    const float exponent = static_cast<float>((static_cast<double>(depth_log)*flow_log)/interval_log);
    // Qc = Qc0*REAL(exp(P)); original REAL stores 0x449732 and 0x44b9ad.
    const float multiplier = static_cast<float>(std::exp(static_cast<double>(exponent)));
    return static_cast<float>(static_cast<double>(lower_flow)*multiplier);
}

double critical_flow_limit(float depth, float lower_depth, float upper_depth,
    float lower_flow, float upper_flow, float factor) {
    // QCLIM 0x409ef1..0x409f89: P=REAL(log(Y/Y0)*log(Q1/Q0)/log(Y1/Y0)).
    // All three logarithms separately store REAL before forming P. EXP(P)
    // stores REAL at 0x409f7d; Q0*EXP(P)*factor then remains wide across the
    // report and slope calculation. Slot rows each receive a REAL copy.
    const float depth_log = static_cast<float>(std::log(static_cast<double>(depth)/lower_depth));
    const float flow_log = static_cast<float>(std::log(static_cast<double>(upper_flow)/lower_flow));
    const float interval_log = static_cast<float>(std::log(static_cast<double>(upper_depth)/lower_depth));
    const float exponent = static_cast<float>((static_cast<double>(depth_log)*flow_log)/interval_log);
    const float multiplier = static_cast<float>(std::exp(static_cast<double>(exponent)));
    return (static_cast<double>(lower_flow)*multiplier)*factor;
}

float critical_flow_limit_slope(double flow, float sqrt_conveyance) {
    // QCLIM 0x409fb8..0x409fd9; only the report value stores REAL, at
    // 0x409feb. Both Qlimit and sqrt(K)^2 retain the wide arithmetic.
    const double conveyance = static_cast<double>(sqrt_conveyance)*sqrt_conveyance;
    return static_cast<float>((flow*flow)/(conveyance*conveyance));
}

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
        result.critical_flow = logarithmic_critical_flow(depth,critical_lower->section.depth,
            critical_upper->section.depth,critical_lower->critical_flow,critical_upper->critical_flow);
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
