// Research FBASEL adapter for the independently verified analytical flow pass.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/section_flux.hpp>
#include <cstddef>
#include <cstdint>
#include <span>
#include <stdexcept>
#include <vector>

extern "C" void feq_section_flux(float water, int count, int subsections,
    const float* x, const float* z, const int* sb, const float* lsn, const int* nvar,
    const float* roughness, const float* sinuosity, int mode, float factor,
    double* flow, double* momentum, double* energy, double* dflow,
    double* dmomentum, double* denergy, float* subsection_sinuosity) {
    if (count < 2 || count > 999 || subsections < 1 || subsections > 200) {
        throw std::invalid_argument("FBASEL section extent exceeds the released flux banks.");
    }
    const std::size_t point_count = static_cast<std::size_t>(count);
    const std::size_t subsection_count = static_cast<std::size_t>(subsections);
    std::vector<feq::BoundaryPoint> points(point_count);
    std::vector<std::int32_t> modes(subsection_count);
    for (std::size_t index = 0; index < point_count; ++index) {
        if (index+1 < point_count && (sb[index] < 1 || sb[index] > subsections)) {
            throw std::invalid_argument("FBASEL subsection number is outside its flux bank.");
        }
        points[index] = feq::BoundaryPoint{x[index],z[index],index+1 < point_count ? lsn[index] : 0.0F,
            index+1 < point_count ? static_cast<std::uint32_t>(sb[index]-1) : 0U};
    }
    for (std::size_t index = 0; index < subsection_count; ++index) { modes[index] = nvar[index]; }
    const feq::SectionFlux result = feq::analytical_section_flux(water,points,modes,
        std::span<const float>(roughness,subsection_count),std::span<const float>(sinuosity,point_count),
        mode == 2,factor,std::span<float>(subsection_sinuosity,subsection_count));
    *flow = result.flow;
    *momentum = result.momentum;
    *energy = result.energy;
    *dflow = result.flow_derivative;
    *dmomentum = result.momentum_derivative;
    *denergy = result.energy_derivative;
}
