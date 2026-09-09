// Research FBASEL adapter; geometric integration is independently tested.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/section_geometry.hpp>
#include <cstddef>
#include <cstdint>
#include <span>
#include <stdexcept>
#include <vector>

extern "C" void feq_section_geometry(float water, int count, int subsections,
    const float* x, const float* z, const int* sb, const float* lsn, const int* nvar,
    float* ts, float* ps, double* area, double* moment, float* ns, float* ymax,
    float* perimeters, int* first, int* last) {
    // Match the source's PMXPNT=999 and PMXSUB=200 bank extents.
    if (count < 2 || count > 999 || subsections < 1 || subsections > 200) {
        throw std::invalid_argument("FBASEL section extent exceeds the released geometry banks.");
    }
    const std::size_t point_count = static_cast<std::size_t>(count);
    const std::size_t subsection_count = static_cast<std::size_t>(subsections);
    std::vector<feq::BoundaryPoint> points(point_count);
    std::vector<std::int32_t> modes(subsection_count);
    std::vector<feq::SubsectionGeometry> output(subsection_count);
    for (std::size_t index = 0; index < point_count; ++index) {
        if (index+1 < point_count && (sb[index] < 1 || sb[index] > subsections)) {
            throw std::invalid_argument("FBASEL subsection number is outside its bank.");
        }
        points[index] = feq::BoundaryPoint{x[index],z[index],index+1 < point_count ? lsn[index] : 0.0F,
            index+1 < point_count ? static_cast<std::uint32_t>(sb[index]-1) : 0U};
    }
    for (std::size_t index = 0; index < subsection_count; ++index) {
        modes[index] = nvar[index];
    }
    const feq::WetSegments wet = feq::section_geometry(water,points,modes,output,
        std::span<float>(perimeters,point_count-1));
    for (std::size_t index = 0; index < subsection_count; ++index) {
        ts[index] = output[index].top_width;
        ps[index] = output[index].perimeter;
        area[index] = output[index].area;
        moment[index] = output[index].first_moment;
        ns[index] = output[index].roughness_weight;
        ymax[index] = output[index].maximum_depth;
    }
    *first = wet.first == 0 ? 0 : static_cast<int>(wet.first)+1;
    *last = wet.last == 0 ? 0 : static_cast<int>(wet.last)+1;
}
