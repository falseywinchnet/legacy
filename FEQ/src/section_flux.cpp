// Mixed-precision analytical FBASEL flow integration, recovered from FEQUTL.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/section_flux.hpp>
#include <feq/power.hpp>
#include <cmath>
#include <cstddef>
#include <stdexcept>

namespace feq {
SectionFlux analytical_section_flux(float water_surface, std::span<const BoundaryPoint> points,
    std::span<const std::int32_t> roughness_modes, std::span<const float> subsection_roughness,
    std::span<const float> point_sinuosity, bool adjust_sinuosity, float manning_factor,
    std::span<float> subsection_sinuosity) {
    const std::size_t subsections = roughness_modes.size();
    if (points.size() < 2 || subsections == 0 || subsection_roughness.size() != subsections ||
        subsection_sinuosity.size() != subsections || point_sinuosity.size() != points.size() ||
        !std::isfinite(water_surface) || !std::isfinite(manning_factor)) {
        throw std::invalid_argument("Invalid analytical section flux extent or value.");
    }
    for (std::size_t index = 0; index < points.size(); ++index) {
        if (!std::isfinite(points[index].offset) || !std::isfinite(points[index].elevation) ||
            (index+1 < points.size() && (points[index].subsection >= subsections || !std::isfinite(points[index].roughness))) ||
            (adjust_sinuosity && index+1 < points.size() && (!std::isfinite(point_sinuosity[index]) || point_sinuosity[index] <= 0.0F))) {
            throw std::invalid_argument("Invalid boundary point in analytical section flux.");
        }
    }
    for (std::size_t index = 0; index < subsections; ++index) {
        if (!std::isfinite(subsection_roughness[index])) {
            throw std::invalid_argument("Nonfinite subsection roughness in analytical section flux.");
        }
        subsection_sinuosity[index] = 0.0F;
    }
    SectionFlux result{};
    for (std::size_t index = 1; index < points.size(); ++index) {
        double zl = points[index-1].elevation;
        double zr = points[index].elevation;
        if (water_surface < zl && water_surface < zr) { continue; }
        double xl = points[index-1].offset;
        double xr = points[index].offset;
        const std::size_t subsection = points[index-1].subsection;
        const float sinuosity = point_sinuosity[index-1];
        if (!(water_surface >= zl && water_surface >= zr)) {
            // x_intersection = x_left + (water-z_left)*(x_right-x_left)/(z_right-z_left).
            // The original retains both clipped offsets in double precision.
            const double intersection = xl+((water_surface-zl)*(xr-xl))/(zr-zl);
            if (zl <= zr) { xr = intersection; zr = water_surface; }
            else { xl = intersection; zl = water_surface; }
        }
        // The original spills YL to a REAL location (VA 0x5b99a4), whereas YR
        // remains in a 53-bit register. Their asymmetric precision is required.
        const float yl = static_cast<float>(water_surface-zl);
        const double yr = water_surface-zr;
        const double width = xr-xl;
        if (adjust_sinuosity) { subsection_sinuosity[subsection] = sinuosity; }
        if (width <= 0.0) { continue; }
        const double slope = (zr-zl)/width;
        const float roughness = roughness_modes[subsection] > 0 ? subsection_roughness[subsection] : points[index-1].roughness;
        // C = NFAC / (n*(1+m^2)^(1/3)); the exponent is the released REAL
        // approximation 0.3333333, promoted exactly before double power.
        double coefficient = manning_factor/(roughness*legacy_power(1.0+slope*slope,static_cast<double>(0.3333333F)));
        if (adjust_sinuosity) {
            const float root = static_cast<float>(std::sqrt(static_cast<double>(sinuosity)));
            coefficient /= root;
        }
        const double coefficient2 = coefficient*coefficient;
        const double coefficient3 = coefficient*coefficient2;
        const double left = yl;
        if (std::abs(slope) > static_cast<double>(1e-6F)) {
            // Integrate h^p dx = -(h_right^(p+1)-h_left^(p+1))/((p+1)*m).
            // The decimal factors and exponent approximations below preserve
            // the published program's actual formulas and evaluation order.
            result.flow -= ((3.0*coefficient)*(legacy_power(yr,static_cast<double>(2.666667F))-
                legacy_power(left,static_cast<double>(2.666667F))))/(8.0*slope);
            result.momentum -= ((legacy_power(yr,static_cast<double>(3.333333F))-
                legacy_power(left,static_cast<double>(3.333333F)))*static_cast<double>(0.3F))*coefficient2/slope;
            const double right2 = yr*yr;
            const double left2 = left*left;
            result.energy -= ((right2*right2-left2*left2)*0.25)*coefficient3/slope;
            result.flow_derivative -= (legacy_power(yr,static_cast<double>(1.666667F))-
                legacy_power(left,static_cast<double>(1.666667F)))*coefficient/slope;
            result.momentum_derivative -= (legacy_power(yr,static_cast<double>(2.333333F))-
                legacy_power(left,static_cast<double>(2.333333F)))*coefficient2/slope;
            result.energy_derivative -= (yr*right2-left*left2)*coefficient3/slope;
        } else {
            // Horizontal segment: integral(h^p dx) = width*h^p. The original
            // uses REAL power for these bases, followed by double accumulation.
            result.flow += (width*coefficient)*legacy_power(yl,1.666667F);
            result.momentum += (width*coefficient2)*legacy_power(yl,2.333333F);
            result.energy += (width*coefficient3)*((left*left)*left);
            result.flow_derivative += ((width*coefficient)*static_cast<double>(1.666667F))*legacy_power(yl,0.6666667F);
            result.momentum_derivative += ((width*coefficient2)*static_cast<double>(2.333333F))*legacy_power(yl,1.333333F);
            result.energy_derivative += ((width*coefficient3)*3.0)*(left*left);
        }
    }
    return result;
}
}
