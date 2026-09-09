// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
// FEQUTL 5.80 xsection.for:2500-2621; original FBASEL RVA 0x96250.
#include <feq/section_geometry.hpp>
#include <cmath>
#include <limits>
#include <stdexcept>

namespace feq {
static_assert(std::numeric_limits<float>::is_iec559 && std::numeric_limits<float>::digits == 24);
static_assert(std::numeric_limits<double>::is_iec559 && std::numeric_limits<double>::digits == 53);

WetSegments section_geometry(float water_surface, std::span<const BoundaryPoint> points,
                             std::span<const std::int32_t> roughness_modes,
                             std::span<SubsectionGeometry> output,
                             std::span<float> segment_perimeters) {
    if (!std::isfinite(water_surface) || points.size() < 2 || output.empty() ||
        roughness_modes.size() != output.size() || segment_perimeters.size() != points.size()-1) {
        throw std::invalid_argument("Section geometry requires finite water level and consistent point/subsection extents.");
    }
    for (std::size_t index = 0; index < points.size(); ++index) {
        if (!std::isfinite(points[index].offset) || !std::isfinite(points[index].elevation) ||
            (index+1 < points.size() && (!std::isfinite(points[index].roughness) ||
                                       points[index].subsection >= output.size()))) {
            throw std::invalid_argument("Invalid section boundary point or subsection index.");
        }
    }
    for (std::size_t index = 0; index < output.size(); ++index) {
        output[index] = SubsectionGeometry{};
    }
    for (std::size_t index = 0; index < segment_perimeters.size(); ++index) {
        segment_perimeters[index] = 0.0F;
    }
    WetSegments wet{};
    for (std::size_t right = 1; right < points.size(); ++right) {
        const BoundaryPoint& left_point = points[right-1];
        const BoundaryPoint& right_point = points[right];
        const double zl = left_point.elevation;
        const double zr = right_point.elevation;
        if (water_surface < zl && water_surface < zr) {
            continue;
        }
        if (wet.first == 0) {
            wet.first = right;
        }
        wet.last = right;
        SubsectionGeometry& result = output[left_point.subsection];
        const double xl = left_point.offset;
        const double xr = right_point.offset;
        double dx = 0.0;
        double dz = 0.0;
        if (water_surface < zl || water_surface < zr) {
            // The intersection XI and DX remain wider than binary32. Original
            // 0x496638 stores XI in an x87 spill; there is no REAL assignment.
            const double xi = xl+((static_cast<double>(water_surface)-zl)*(xr-xl))/(zr-zl);
            if (zl <= zr) {
                dx = xi-xl;
                dz = static_cast<double>(water_surface)-zl;
            } else {
                dx = xr-xi;
                dz = static_cast<double>(water_surface)-zr;
            }
            if (dz > result.maximum_depth) {
                result.maximum_depth = static_cast<float>(dz);
            }
            result.top_width = static_cast<float>(result.top_width+dx);
            const double area = (dx*dz)*0.5;
            result.area += area;
            // Triangle: J=A*depth/3. Original uses a binary64 reciprocal.
            result.first_moment += (area*dz)*0.3333333333333333;
        } else {
            dx = xr-xl;
            dz = zr-zl;
            const double yl = static_cast<double>(water_surface)-zl;
            const double yr = static_cast<double>(water_surface)-zr;
            double deepest = result.maximum_depth;
            if (yl > deepest) {
                deepest = yl;
            }
            if (yr > deepest) {
                deepest = yr;
            }
            result.maximum_depth = static_cast<float>(deepest);
            result.top_width = static_cast<float>(result.top_width+dx);
            result.area += (dx*(yl+yr))*0.5;
            // Trapezoid: J=DX*(YL*YR+(YR-YL)^2/3)/2. Unlike the triangle
            // path, 0x4967e1 multiplies by the stored binary32 reciprocal.
            const double difference = yr-yl;
            const double term = yl*yr+(difference*difference)*static_cast<double>(0.3333333432674408F);
            result.first_moment += (term*dx)*0.5;
        }
        // 0x496809 explicitly stores SQRT as REAL before perimeter or weighted
        // roughness accumulation; retaining an unrounded root changes n.
        const float perimeter = static_cast<float>(std::sqrt(dx*dx+dz*dz));
        segment_perimeters[right-1] = perimeter;
        if (left_point.roughness > 0.0F) {
            result.perimeter = static_cast<float>(static_cast<double>(result.perimeter)+perimeter);
        }
        if (roughness_modes[left_point.subsection] == 0) {
            result.roughness_weight = static_cast<float>(result.roughness_weight+
                static_cast<double>(perimeter)*left_point.roughness);
        }
    }
    return wet;
}
} // namespace feq
