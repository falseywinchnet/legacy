// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#ifndef FEQ_SECTION_GEOMETRY_HPP
#define FEQ_SECTION_GEOMETRY_HPP

#include <cstddef>
#include <cstdint>
#include <span>

namespace feq {
struct BoundaryPoint {
    float offset;
    float elevation;
    float roughness; // Line starting here; the final point's value is unused.
    std::uint32_t subsection; // Zero based; the final point's value is unused.
};
struct SubsectionGeometry {
    float top_width;
    float perimeter;
    double area;
    double first_moment;
    float roughness_weight;
    float maximum_depth;
};
struct WetSegments {
    // Each index identifies the right endpoint of a segment. Both are zero
    // when no segment is wet; otherwise first <= last, with first >= 1.
    std::size_t first;
    std::size_t last;
};

// Integrate a piecewise linear section boundary at a water-surface elevation.
// Mode zero accumulates perimeter-weighted line roughness. Other modes leave
// that sum zero for the caller's depth-dependent roughness calculation.
// Signed horizontal increments preserve overhanging-boundary semantics.
// segment_perimeters has one element per segment, output has one per subsection.
WetSegments section_geometry(float water_surface, std::span<const BoundaryPoint> points,
                             std::span<const std::int32_t> roughness_modes,
                             std::span<SubsectionGeometry> output,
                             std::span<float> segment_perimeters);
} // namespace feq
#endif
