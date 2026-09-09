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
// XLKT22 interpolates the selected interval and its tabulated critical flow.
// If the lower row has zero depth, critical-flow interpolation uses the upper
// and following rows. Supply following in that case. The caller retains table
// selection, depth clamping, cached pointers, and historical diagnostics.
EnergySectionProperties interpolate_energy_section(float depth,
    const EnergySectionRow& lower, const EnergySectionRow& upper,
    bool has_slopes, const EnergySectionRow* following = nullptr);
}
#endif
