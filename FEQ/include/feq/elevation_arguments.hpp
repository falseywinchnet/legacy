// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#ifndef FEQ_ELEVATION_ARGUMENTS_HPP
#define FEQ_ELEVATION_ARGUMENTS_HPP
#include <cstddef>
#include <span>

namespace feq {
struct ElevationArguments {
    std::size_t count;
    std::size_t exhausted;
};

// CHKARG: insert a near-zero elevation and subdivide large elevation gaps.
// The first count elements must be finite and sorted, count >= 2, with enough
// initialized storage for the original count. The remaining span is capacity.
// Return the retained count and the number of ERR:525 capacity diagnostics.
// Preserve the historical in-place tail, including entries beyond returned count.
// near_zero >= 0, maximum_step > 0, and each subdivision count fits int32.
ElevationArguments elevation_arguments(std::span<float> elevations, std::size_t count,
    float near_zero, float maximum_step, bool added_bottom_slot);
} // namespace feq
#endif
