// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/elevation_arguments.hpp>
#include <cmath>
#include <cstdint>
#include <limits>
#include <stdexcept>

namespace feq {
ElevationArguments elevation_arguments(std::span<float> elevations, std::size_t count,
    float near_zero, float maximum_step, bool added_bottom_slot) {
    if (count < 2 || count > elevations.size() || !std::isfinite(near_zero) || near_zero < 0.0F ||
        !std::isfinite(maximum_step) || maximum_step <= 0.0F) {
        throw std::invalid_argument("Invalid elevation argument dimensions or spacing.");
    }
    for (std::size_t index = 0; index < count; ++index) {
        if (!std::isfinite(elevations[index]) || (index > 0 && elevations[index] < elevations[index-1])) {
            throw std::invalid_argument("Elevation arguments must be finite and sorted.");
        }
    }
    std::size_t retained = count;
    std::size_t exhausted = 0;
    // FEQUTL xsection.for:1317; the original subtraction and division remain
    // binary64. Its threshold is NRZERO / 16.
    if (static_cast<double>(elevations[1])-elevations[0] <= static_cast<double>(near_zero)/16.0) {
        for (std::size_t index = 2; index < retained; ++index) {
            elevations[index-1] = elevations[index];
        }
        --retained;
    }
    // xsection.for:1327-1340, original VA 0x494380: REAL constant 1.1,
    // binary64 multiplication and addition, one binary32 store on insertion.
    if (!added_bottom_slot && static_cast<double>(elevations[1]) >
        static_cast<double>(elevations[0])+static_cast<double>(1.1F)*near_zero) {
        if (retained < elevations.size()) {
            elevations[retained] = static_cast<float>(static_cast<double>(elevations[0])+near_zero);
            ++retained;
        } else {
            ++exhausted;
        }
    }
    // xsection.for:1344-1362. Keep the original input count as the loop bound,
    // even when its second element was removed above. This deliberately
    // preserves CHKARG's in-place ordering and reuse of the original tail.
    for (std::size_t index = 1; index < count; ++index) {
        const double difference = static_cast<double>(elevations[index])-elevations[index-1];
        if (difference > maximum_step) {
            // m = trunc(dz / DZLIM + 1); delz = dz / m; tp += delz.
            // Original 0x49443d-0x49448f keeps dz, delz, and tp in registers.
            // Writing Z(n) rounds tp to REAL without rounding the running tp.
            const double divisions = difference/maximum_step+1.0;
            if (divisions >= static_cast<double>(std::numeric_limits<std::int32_t>::max())+1.0) {
                throw std::overflow_error("Elevation subdivision count exceeds int32.");
            }
            const std::int32_t pieces = static_cast<std::int32_t>(divisions);
            const double increment = difference/pieces;
            double current = elevations[index-1];
            for (std::int32_t piece = 1; piece < pieces; ++piece) {
                current += increment;
                if (retained < elevations.size()) {
                    elevations[retained] = static_cast<float>(current);
                    ++retained;
                } else {
                    ++exhausted;
                }
            }
        }
    }
    // Original SORT is stable insertion sort (VA 0x476c38). Preserve equal
    // values' order, including the sign bit of equal positive/negative zero.
    for (std::size_t index = 1; index < retained; ++index) {
        const float value = elevations[index];
        std::size_t position = index;
        while (position > 0 && elevations[position-1] > value) {
            elevations[position] = elevations[position-1];
            --position;
        }
        elevations[position] = value;
    }
    // SHARE/fqshrstr.for RDUP: scale = (|A1|+|AN|)/2-A1.
    // The original computes a reciprocal once and multiplies the absolute
    // difference of datum-relative elevations. Retain that operation order.
    const double datum = elevations[0];
    const double scale = (std::abs(datum)+std::abs(static_cast<double>(elevations[retained-1])))*0.5-datum;
    const double inverse = 1.0/scale;
    std::size_t unique = 1;
    for (std::size_t index = 1; index < retained; ++index) {
        const double previous = static_cast<double>(elevations[unique-1])-datum;
        const double current = static_cast<double>(elevations[index])-datum;
        const double relative_difference = std::abs(current-previous)*inverse;
        // Preserve unordered behavior when the original scale is zero:
        // 0 * infinity is NaN, so an equal value is retained by this branch.
        if (!(relative_difference <= static_cast<double>(1.0e-5F))) {
            if (unique != index) { elevations[unique] = elevations[index]; }
            ++unique;
        }
    }
    return ElevationArguments{unique,exhausted};
}
} // namespace feq
