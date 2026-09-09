// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#ifndef FEQ_SECTION_SINUOSITY_HPP
#define FEQ_SECTION_SINUOSITY_HPP
#include <feq/section_flux.hpp>
#include <cstddef>
#include <cstdint>
#include <span>
#include <stdexcept>

namespace feq {
enum class SinuosityFluxModel { disabled, unit_coefficients, depth_coefficients };

struct SinuousSectionFlux {
    SectionFlux flux;
    double area_sinuosity;
    double flow_sinuosity;
};

// Values required by the original negative-depth diagnostic. The numerical
// caller decides how to present the diagnostic and terminate its calculation.
struct SinuosityDepthState {
    std::size_t quadrature_index;
    double depth;
    double station;
    double left_offset;
    double right_offset;
    double left_elevation;
    double right_elevation;
    double width;
    double slope;
    float left_depth;
    float midpoint;
    float half_width;
};

struct SinuosityDepthError final : std::runtime_error {
    explicit SinuosityDepthError(const SinuosityDepthState& values);
    SinuosityDepthState state;
};

// FBASEL's Gaussian integration for linearly varying point sinuosity. The
// caller supplies roughness after geometry/depth lookup and the chosen rule.
// Subsection flow and conveyance are cleared and accumulated with the original
// REAL store after each sample. The result contains all eight integral sums.
SinuousSectionFlux linear_sinuosity_flux(float water_surface,
    std::span<const BoundaryPoint> points, std::span<const std::int32_t> roughness_modes,
    std::span<const float> subsection_roughness, std::span<const float> point_sinuosity,
    float manning_factor, float gravity, SinuosityFluxModel model,
    std::span<const double> nodes, std::span<const double> weights,
    std::span<float> subsection_flow, std::span<float> subsection_conveyance);
} // namespace feq
#endif
