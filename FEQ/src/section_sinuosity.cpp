// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
// FEQUTL 5.80 xsection.for:2631-2857 and 2922-2926; FBASEL RVA 0x96250.
#include <feq/section_sinuosity.hpp>
#include <feq/power.hpp>
#include <cmath>
#include <stdexcept>

namespace feq {
SinuosityDepthError::SinuosityDepthError(const SinuosityDepthState& values)
    : std::runtime_error("Negative depth at a section quadrature point."), state(values) {}

SinuousSectionFlux linear_sinuosity_flux(float water_surface,
    std::span<const BoundaryPoint> points, std::span<const std::int32_t> roughness_modes,
    std::span<const float> subsection_roughness, std::span<const float> point_sinuosity,
    float manning_factor, float gravity, SinuosityFluxModel model,
    std::span<const double> nodes, std::span<const double> weights,
    std::span<float> subsection_flow, std::span<float> subsection_conveyance) {
    const std::size_t subsections = roughness_modes.size();
    if (points.size() < 2 || subsections == 0 || subsection_roughness.size() != subsections ||
        subsection_flow.size() != subsections || subsection_conveyance.size() != subsections ||
        point_sinuosity.size() != points.size() || nodes.empty() || nodes.size() != weights.size() ||
        !std::isfinite(water_surface) || !std::isfinite(manning_factor) || !std::isfinite(gravity)) {
        throw std::invalid_argument("Invalid linear-sinuosity integration dimensions or value.");
    }
    for (std::size_t index = 0; index < points.size(); ++index) {
        if (!std::isfinite(points[index].offset) || !std::isfinite(points[index].elevation) ||
            (index+1 < points.size() && (points[index].subsection >= subsections || !std::isfinite(points[index].roughness))) ||
            !std::isfinite(point_sinuosity[index]) || point_sinuosity[index] <= 0.0F) {
            throw std::invalid_argument("Invalid boundary point in linear-sinuosity integration.");
        }
    }
    for (std::size_t index = 0; index < subsections; ++index) {
        if (!std::isfinite(subsection_roughness[index])) {
            throw std::invalid_argument("Nonfinite subsection roughness in linear-sinuosity integration.");
        }
        subsection_flow[index] = 0.0F;
        subsection_conveyance[index] = 0.0F;
    }
    SinuousSectionFlux result{};
    for (std::size_t index = 1; index < points.size(); ++index) {
        double zl = points[index-1].elevation;
        double zr = points[index].elevation;
        if (water_surface < zl && water_surface < zr) {
            continue;
        }
        double xl = points[index-1].offset;
        double xr = points[index].offset;
        double snl = point_sinuosity[index-1];
        double snr = point_sinuosity[index];
        const std::size_t subsection = points[index-1].subsection;
        if (!(water_surface >= zl && water_surface >= zr)) {
            // Clip the boundary and linearly interpolate sinuosity at the
            // water intersection. Original XL/XR/SNL/SNR remain wide.
            const double span = xr-xl;
            const double intersection = xl+((water_surface-zl)*span)/(zr-zl);
            const double intersection_sinuosity = xr > xl ? snl+((intersection-xl)*(snr-snl))/span : 1.0;
            if (zl <= zr) {
                xr = intersection;
                zr = water_surface;
                snr = intersection_sinuosity;
            } else {
                xl = intersection;
                zl = water_surface;
                snl = intersection_sinuosity;
            }
        }
        // Original 0x496c27/0x496c91 stores YL as REAL. YR stays wide.
        const float yl = static_cast<float>(water_surface-zl);
        const double yr = water_surface-zr;
        const double width = xr-xl;
        if (width <= 0.0 || (yl <= 0.0F && yr <= 0.0)) {
            continue;
        }
        const double slope = (zr-zl)/width;
        const float roughness = roughness_modes[subsection] > 0 ? subsection_roughness[subsection] : points[index-1].roughness;
        const double slope_factor = 1.0+slope*slope;
        // K(h)=C*h^(5/3), C=NFAC/[n*(1+m*m)^REAL(0.3333333)].
        const double coefficient = manning_factor/(roughness*legacy_power(slope_factor,static_cast<double>(0.3333333F)));
        double c2 = 0.0;
        double c3 = 0.0;
        double c4 = 0.0;
        if (model == SinuosityFluxModel::depth_coefficients) {
            const double c1 = manning_factor/(roughness*legacy_power(slope_factor,0.083333333333333));
            const double c1_squared = c1*c1;
            const double wide_gravity = gravity;
            c2 = (wide_gravity*75.0F)/(4.0*c1_squared);
            // The original REAL gravity^(1.5) uses a REAL sqrt store before
            // the wide multiplications at 0x496e0d and 0x496f0c.
            const float root_gravity = static_cast<float>(std::sqrt(wide_gravity));
            c3 = -((wide_gravity*root_gravity)*125.0F)/(4.0*(c1*c1_squared));
            c4 = (wide_gravity*6.251F)/c1_squared;
        }
        // Integral h(x)*sinuosity(x) dx. Original 0x496f8d multiplies by
        // the REAL reciprocal of 3, not a binary64 division by 3.
        const double area_integrand = (snl*yl+0.5*(snl*yr+snr*yl))+snr*yr;
        result.area_sinuosity += (width*area_integrand)*0.3333333432674408;
        const double sinuosity_slope = (snr-snl)/width;
        // Explicit REAL stores at 0x496fc1 and 0x496fd5 precede sampling.
        const float midpoint = static_cast<float>((xl+xr)*0.5);
        const float half_width = static_cast<float>(width*0.5);
        for (std::size_t sample = 0; sample < nodes.size(); ++sample) {
            const double weight = half_width*weights[sample];
            const double station = half_width*nodes[sample]+midpoint;
            const double distance = station-xl;
            double depth = yl-slope*distance;
            if (depth < 0.0) {
                if (std::fabs(width) < 0.10F) {
                    depth = 0.0;
                } else {
                    throw SinuosityDepthError(SinuosityDepthState{sample,depth,station,xl,xr,zl,zr,
                        width,slope,yl,midpoint,half_width});
                }
            }
            const double sinuosity = snl+sinuosity_slope*distance;
            const double conveyance = coefficient*legacy_power(depth,1.666666666666666);
            const double flow = conveyance/std::sqrt(sinuosity);
            result.flow_sinuosity += (weight*sinuosity)*flow;
            const double weighted_flow = weight*flow;
            result.flux.flow += weighted_flow;
            subsection_flow[subsection] = static_cast<float>(subsection_flow[subsection]+weighted_flow);
            subsection_conveyance[subsection] = static_cast<float>(subsection_conveyance[subsection]+weight*conveyance);
            if (model == SinuosityFluxModel::disabled) {
                continue;
            }
            // V=Q/h is stored as REAL at 0x497307 before flux products.
            const float stored_velocity = depth > 0.0 ? static_cast<float>(flow/depth) : 0.0F;
            const double velocity = stored_velocity;
            double momentum = flow*velocity;
            double energy = momentum*velocity;
            double momentum_derivative = velocity*velocity;
            double energy_derivative = momentum_derivative*velocity;
            if (model == SinuosityFluxModel::depth_coefficients && depth != 0.0) {
                const double third_power = legacy_power(depth,0.33333333333333);
                const double root_depth = std::sqrt(depth);
                const double alpha = (1.0+c2/third_power)+c3/root_depth;
                const double derivative_denominator = 3.0*legacy_power(depth,1.3333333333333);
                // Preserve the released DALOC expression, which uses C2 in
                // both terms, including -C2/[2*h*sqrt(h)].
                const double alpha_derivative = -(c2/derivative_denominator)-c2/((depth*root_depth)*2.0);
                const double beta = 1.0+c4/third_power;
                const double beta_derivative = -(c4/derivative_denominator);
                momentum_derivative = beta_derivative*momentum+momentum_derivative*beta;
                energy_derivative = alpha_derivative*energy+energy_derivative*alpha;
                momentum *= beta;
                energy *= alpha;
            }
            result.flux.flow_derivative += weight*velocity;
            result.flux.momentum += weight*momentum;
            result.flux.energy += weight*energy;
            result.flux.momentum_derivative += weight*momentum_derivative;
            result.flux.energy_derivative += weight*energy_derivative;
        }
    }
    if (model != SinuosityFluxModel::disabled) {
        // FBASEL applies the constant derivative factors after all segments.
        result.flux.flow_derivative *= 1.666667F;
        result.flux.momentum_derivative *= 2.333333F;
        result.flux.energy_derivative *= 3.0;
    }
    return result;
}
} // namespace feq
