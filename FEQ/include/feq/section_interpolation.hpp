// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#ifndef FEQ_SECTION_INTERPOLATION_HPP
#define FEQ_SECTION_INTERPOLATION_HPP

namespace feq {

// FEQ table rows store sqrt(conveyance), not conveyance. The two slopes
// are present only when the table header specifies a derivative offset.
struct SectionTableRow {
    float depth;
    float top_width;
    float area;
    float sqrt_conveyance;
    float momentum_factor;
    float sqrt_conveyance_slope;
    float momentum_factor_slope;
};

struct SectionProperties {
    float area;
    float top_width;
    float top_width_slope;
    float conveyance;
    float conveyance_slope;
    float momentum_factor;
    float momentum_factor_slope;
};

// Interpolate within one already selected interval. Interval selection,
// out-of-range diagnostics, and the cached row pointer belong to the caller.
SectionProperties interpolate_section(float depth, const SectionTableRow& lower,
                                      const SectionTableRow& upper, bool has_slopes);

} // namespace feq
#endif
