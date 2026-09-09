// Research FBASEL adapter for independently verified Gaussian sinuosity flux.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/section_sinuosity.hpp>
#include <cstddef>
#include <cstdint>
#include <span>
#include <stdexcept>
#include <vector>

extern "C" void feq_section_sinuosity(float water, int count, int subsections,
    const float* x, const float* z, const int* sb, const float* lsn, const int* nvar,
    const float* roughness, const float* sinuosity, float factor, float gravity,
    int new_beta, int local_coefficients, int order, const double* nodes, const double* weights,
    double* flow, double* momentum, double* energy, double* dflow, double* dmomentum,
    double* denergy, double* area_sinuosity, double* flow_sinuosity,
    float* subsection_flow, float* subsection_conveyance) {
    if (count < 2 || count > 999 || subsections < 1 || subsections > 200 || order < 1 || order > 21) {
        throw std::invalid_argument("FBASEL sinuosity extent exceeds the released banks.");
    }
    const std::size_t point_count = static_cast<std::size_t>(count);
    const std::size_t subsection_count = static_cast<std::size_t>(subsections);
    const std::size_t rule_order = static_cast<std::size_t>(order);
    std::vector<feq::BoundaryPoint> points(point_count);
    std::vector<std::int32_t> modes(subsection_count);
    for (std::size_t index = 0; index < point_count; ++index) {
        if (index+1 < point_count && (sb[index] < 1 || sb[index] > subsections)) {
            throw std::invalid_argument("FBASEL subsection number is outside its sinuosity bank.");
        }
        points[index] = feq::BoundaryPoint{x[index],z[index],index+1 < point_count ? lsn[index] : 0.0F,
            index+1 < point_count ? static_cast<std::uint32_t>(sb[index]-1) : 0U};
    }
    for (std::size_t index = 0; index < subsection_count; ++index) {
        modes[index] = nvar[index];
    }
    const feq::SinuosityFluxModel model = new_beta == 1 ?
        (local_coefficients == 1 ? feq::SinuosityFluxModel::depth_coefficients : feq::SinuosityFluxModel::unit_coefficients) :
        feq::SinuosityFluxModel::disabled;
    const feq::SinuousSectionFlux result = feq::linear_sinuosity_flux(water,points,modes,
        std::span<const float>(roughness,subsection_count),std::span<const float>(sinuosity,point_count),
        factor,gravity,model,std::span<const double>(nodes,rule_order),std::span<const double>(weights,rule_order),
        std::span<float>(subsection_flow,subsection_count),std::span<float>(subsection_conveyance,subsection_count));
    *flow = result.flux.flow;
    *momentum = result.flux.momentum;
    *energy = result.flux.energy;
    *dflow = result.flux.flow_derivative;
    *dmomentum = result.flux.momentum_derivative;
    *denergy = result.flux.energy_derivative;
    *area_sinuosity = result.area_sinuosity;
    *flow_sinuosity = result.flow_sinuosity;
}
