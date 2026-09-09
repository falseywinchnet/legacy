// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#ifndef FEQ_SECTION_INTERPOLATION_HPP
#define FEQ_SECTION_INTERPOLATION_HPP

namespace feq {

// Fraction of the distance between two cross sections at a requested station.
// The caller validates the station and distinct bounds. Distances and the
// reciprocal remain binary64 until individual table properties are stored.
double section_station_fraction(float left, float right, float station);

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

// Integral of area from the interval's lower depth, added to the tabulated
// first moment. Preserves XLKT21's stored-width and retained-area distinction.
float interpolate_section_first_moment(float depth, const SectionTableRow& lower,
                                       const SectionTableRow& upper, float lower_first_moment);

// LKTJ's scalar first-moment lookup retains width and area throughout and
// uses a different REAL sixth from XLKT21/22. The caller selects the interval.
float interpolate_scalar_first_moment(float depth, float lower_depth,
    float lower_width, float lower_area, float lower_first_moment,
    float upper_depth, float upper_width);

} // namespace feq
#endif
