// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/elevation_arguments.hpp>
#include <limits>
#include <stdexcept>

extern "C" int feq_elevation_arguments(int capacity, int* count, float near_zero,
    float maximum_step, int added, float* elevations) {
    if (capacity < 0 || *count < 0) { throw std::invalid_argument("Negative elevation extent."); }
    const feq::ElevationArguments result = feq::elevation_arguments(
        std::span<float>(elevations,static_cast<std::size_t>(capacity)),
        static_cast<std::size_t>(*count),near_zero,maximum_step,added != 0);
    if (result.exhausted > static_cast<std::size_t>(std::numeric_limits<int>::max())) {
        throw std::overflow_error("Elevation diagnostic count exceeds int.");
    }
    *count = static_cast<int>(result.count);
    return static_cast<int>(result.exhausted);
}
