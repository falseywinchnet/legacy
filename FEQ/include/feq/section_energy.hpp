// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#ifndef FEQ_SECTION_ENERGY_HPP
#define FEQ_SECTION_ENERGY_HPP
#include <feq/section_interpolation.hpp>
namespace feq {
struct EnergySectionRow {
    SectionTableRow section;
    float first_moment;
    float energy_factor;
    float energy_factor_slope;
    float critical_flow;
};
struct EnergySectionProperties {
    SectionProperties section;
    float first_moment;
    float energy_factor;
    float energy_factor_slope;
    float critical_flow;
};
// Shared logarithmic interpolation of critical flow. Both row depths and flows
// must be positive. Standalone LKTQC returns the original negative quiet NaN at
// zero query depth; XLKT22 separately returns zero before evaluating logarithms.
float logarithmic_critical_flow(float depth, float lower_depth, float upper_depth,
    float lower_flow, float upper_flow);

// QCLIMIT extrapolates the last two open-section critical flows into the slot.
// Require positive finite depths and flows, increasing row depths, and a finite
// factor. Preserve the wide scaled result through table stores and slope use.
double critical_flow_limit(float depth, float lower_depth, float upper_depth,
    float lower_flow, float upper_flow, float factor);

// The reported limiting critical slope is REAL(Qlimit^2/sqrt(K)^4).
// Require finite flow and finite positive sqrt(conveyance).
float critical_flow_limit_slope(double flow, float sqrt_conveyance);
// XLKT22 interpolates the selected interval and its tabulated critical flow.
// If the lower row has zero depth, critical-flow interpolation uses the upper
// and following rows. Supply following in that case. The caller retains table
// selection, depth clamping, cached pointers, and historical diagnostics.
EnergySectionProperties interpolate_energy_section(float depth,
    const EnergySectionRow& lower, const EnergySectionRow& upper,
    bool has_slopes, const EnergySectionRow* following = nullptr);

// FISE residual for inversion of specific energy, after the table lookup.
// Pass energy_factor=1 when the selected section model omits ALPHA. The
// original function returns the retained result without a REAL conversion.
double specific_energy_residual(float depth, float area, float energy_factor,
    float flow, float gravity, float target_energy);
}
#endif
