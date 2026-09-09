// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#ifndef FEQ_CONDUIT_BOUNDARY_HPP
#define FEQ_CONDUIT_BOUNDARY_HPP
#include <cstddef>
#include <span>
#include <vector>
namespace feq {
struct ConduitBoundary {
    std::vector<float> x;
    std::vector<float> y;
};
struct ConduitPlacement {
    float slot_width;
    float slot_height;
    float x_offset;
    float y_offset;
};
// URQTE: eleven points in the upper right quadrant, corrected to the
// released ellipse area. Both dimensions are positive, in working units.
ConduitBoundary ellipse_quadrant(float rise, float span);
// RHMAK/URQMAK: traverse counterclockwise from the left edge of the slot.
// Input points start at the crown and follow the right perimeter downward.
// Output includes the original extra point 0.01 units above the slot.
ConduitBoundary right_half_boundary(std::span<const float> x,
    std::span<const float> y, const ConduitPlacement& placement);
ConduitBoundary quadrant_boundary(std::span<const float> x,
    std::span<const float> y, const ConduitPlacement& placement);
// MKPIPE/MKBOX: area-equivalent regular polygon and the released 41-point
// box boundary. y_offset is the invert datum for these two constructors.
ConduitBoundary circular_boundary(std::size_t sides, float diameter,
    const ConduitPlacement& placement);
ConduitBoundary box_boundary(float rise, float span,
    const ConduitPlacement& placement);
}
#endif
