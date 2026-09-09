// Analytical boundary-segment flow integrals used by FEQUTL NEWBETA.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#ifndef FEQ_SECTION_FLUX_HPP
#define FEQ_SECTION_FLUX_HPP
#include <feq/section_geometry.hpp>
#include <cstdint>
#include <span>

namespace feq {
struct SectionFlux {
    double flow;
    double momentum;
    double energy;
    double flow_derivative;
    double momentum_derivative;
    double energy_derivative;
};

// Integrate the released analytical NEWBETA formulas over the wet boundary.
// Modes 0 and 2 correspond to no sinuosity and piecewise constant sinuosity.
// The caller supplies the subsection roughness obtained after the geometry
// pass and depth-dependent roughness lookup. Positive-width segments contribute
// flow; vertical and overhanging segments retain their original zero-flow role.
// The final point's roughness/subsection fields are unused. Sinuosity is taken
// from the left endpoint and the last wet segment sets its subsection value.
// The separate piecewise linear Gaussian integration path does not use this API.
SectionFlux analytical_section_flux(float water_surface, std::span<const BoundaryPoint> points,
    std::span<const std::int32_t> roughness_modes, std::span<const float> subsection_roughness,
    std::span<const float> point_sinuosity, bool adjust_sinuosity, float manning_factor,
    std::span<float> subsection_sinuosity);
}
#endif
