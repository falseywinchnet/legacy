// Pipe-arch standard interpolation and right-half perimeter (RHARCH).
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/arch_perimeter.hpp>
#include <feq/trigonometry.hpp>
#include <cmath>
#include <cstddef>
#include <stdexcept>

namespace feq {
ArchPerimeter arch_perimeter(std::span<const ArchStandardRow> standards,
    float conversion, float rise, float span) {
    if (standards.size() < 2 || !std::isfinite(conversion) || conversion <= 0.0F ||
        !std::isfinite(rise) || !std::isfinite(span) || (rise <= 0.0F && span <= 0.0F)) {
        throw std::invalid_argument("Invalid pipe-arch dimensions or conversion.");
    }
    for (std::size_t index = 0; index < standards.size(); ++index) {
        const ArchStandardRow& row = standards[index];
        if (!std::isfinite(row.rise) || !std::isfinite(row.span) ||
            !std::isfinite(row.bottom_radius) || !std::isfinite(row.corner_radius) ||
            row.rise <= 0.0F || row.span <= 0.0F || row.bottom_radius <= 0.0F || row.corner_radius <= 0.0F ||
            (index > 0 && (row.rise <= standards[index-1].rise || row.span <= standards[index-1].span))) {
            throw std::invalid_argument("Invalid or unsorted pipe-arch standard table.");
        }
    }
    // Original 0x40f9a4/0x40f9ad write REAL dimensions while retaining the
    // initial products for the first branch and range comparisons.
    const double initial_rise = static_cast<double>(conversion)*rise;
    const double initial_span = static_cast<double>(conversion)*span;
    ArchPerimeter result{};
    result.rise = static_cast<float>(initial_rise);
    result.span = static_cast<float>(initial_span);
    std::size_t upper = 1;
    double fraction = 0.0;
    if (initial_rise > 0.0) {
        if (initial_rise < standards[0].rise && initial_rise+static_cast<double>(0.1F) > standards[0].rise) {
            result.rise = standards[0].rise;
        }
        if (result.rise > standards.back().rise && static_cast<double>(result.rise)-static_cast<double>(0.1F) < standards.back().rise) {
            result.rise = standards.back().rise;
        }
        if (result.rise < standards[0].rise || result.rise > standards.back().rise) {
            result.error = ArchInputError::rise_outside_table;
            return result;
        }
        while (upper+1 < standards.size() && standards[upper].rise < result.rise) { ++upper; }
        fraction = (static_cast<double>(result.rise)-standards[upper-1].rise)/
                   (static_cast<double>(standards[upper].rise)-standards[upper-1].rise);
        const double selected_span = standards[upper-1].span+fraction*
            (static_cast<double>(standards[upper].span)-standards[upper-1].span);
        result.span_warning = result.span > 0.0F &&
            std::abs(static_cast<double>(result.span)-selected_span)/selected_span > static_cast<double>(0.02F);
        result.requested_span = static_cast<float>(static_cast<double>(result.span)/conversion);
        result.tabulated_span = static_cast<float>(selected_span/conversion);
        result.span = static_cast<float>(selected_span);
    } else {
        if (initial_span < standards[0].span || initial_span > standards.back().span) {
            if (initial_span < standards[0].span && initial_span+static_cast<double>(0.1F) > standards[0].span) {
                result.span = standards[0].span;
            }
            if (result.span > standards.back().span && static_cast<double>(result.span)-static_cast<double>(0.1F) < standards.back().span) {
                result.span = standards.back().span;
            }
            // The released span branch still reports ERR:572 after clamping.
            result.error = ArchInputError::span_outside_table;
            return result;
        }
        while (upper+1 < standards.size() && standards[upper].span < initial_span) { ++upper; }
        fraction = (static_cast<double>(result.span)-standards[upper-1].span)/
                   (static_cast<double>(standards[upper].span)-standards[upper-1].span);
        result.rise = static_cast<float>(standards[upper-1].rise+fraction*
            (static_cast<double>(standards[upper].rise)-standards[upper-1].rise));
    }
    const double bottom_radius = (standards[upper-1].bottom_radius+fraction*
        (static_cast<double>(standards[upper].bottom_radius)-standards[upper-1].bottom_radius))/conversion;
    const double corner_radius = (standards[upper-1].corner_radius+fraction*
        (static_cast<double>(standards[upper].corner_radius)-standards[upper-1].corner_radius))/conversion;
    result.rise = static_cast<float>(static_cast<double>(result.rise)/conversion);
    const double wide_span = static_cast<double>(result.span)/conversion;
    result.span = static_cast<float>(wide_span);
    // conduit.for:2353-2356. r1/r3 and the converted span stay wide, while
    // both square-root subexpressions and the returned offset A store REAL.
    const double c = wide_span*0.5-corner_radius;
    const double radius_difference = bottom_radius-corner_radius;
    const double difference_square = radius_difference*radius_difference;
    const double c_square = c*c;
    const float root = static_cast<float>(std::sqrt(difference_square-c_square));
    const double b = bottom_radius-root;
    const double rise_difference = static_cast<double>(result.rise)-b;
    const double corner_square = corner_radius*corner_radius;
    const double crown_radius = ((corner_square-c_square)-rise_difference*rise_difference)/
        ((b-result.rise+corner_radius)*2.0);
    result.invert_offset = static_cast<float>(static_cast<double>(result.rise)-crown_radius);
    double theta = legacy_arcsine(static_cast<float>(c/(crown_radius-corner_radius)));
    double orientation = 1.0;
    if (result.invert_offset > b) {
        orientation = -1.0;
        theta = static_cast<double>(3.1415927F)-theta;
    }
    const double omega = legacy_arcsine(static_cast<float>(c/radius_difference));
    // The released PHI constant is 3.14593, including this source discrepancy.
    const double phi = (static_cast<double>(3.14593F)-theta)-omega;
    const double upper_difference = crown_radius-corner_radius;
    const float upper_root = static_cast<float>(std::sqrt(upper_difference*upper_difference-c_square));
    // True area of the semi-perimeter, conduit.for:2371. Preserve its
    // subtraction and product order; do not algebraically cancel factors.
    double true_area = theta*(crown_radius*crown_radius)-(orientation*c)*upper_root;
    true_area += (((c*(2.0*bottom_radius-corner_radius))*(bottom_radius-b))*corner_radius)/difference_square;
    true_area += phi*corner_square;
    true_area += (bottom_radius*bottom_radius)*(omega-(c*(bottom_radius-b))/difference_square);
    true_area *= 0.5;
    // Nine crown segments, eight corner segments, five invert segments.
    // The original uses rounded REAL reciprocal constants for division by
    // nine/five, stores each angle as REAL, and retains SIN/COS through the
    // radius multiplication. Coordinates themselves store REAL.
    for (std::size_t index = 0; index < 10; ++index) {
        const float angle = static_cast<float>((static_cast<double>(index)*theta)*static_cast<double>(0.1111111119389534F));
        result.x[index] = static_cast<float>(crown_radius*std::sin(static_cast<double>(angle)));
        result.y[index] = static_cast<float>(crown_radius*std::cos(static_cast<double>(angle)));
    }
    const double angle_step = phi*0.125;
    float angle = static_cast<float>(static_cast<double>(1.570796F)-theta);
    for (std::size_t index = 10; index < 18; ++index) {
        angle = static_cast<float>(static_cast<double>(angle)-angle_step);
        result.x[index] = static_cast<float>(c+corner_radius*std::cos(static_cast<double>(angle)));
        result.y[index] = static_cast<float>((b-result.invert_offset)+corner_radius*std::sin(static_cast<double>(angle)));
    }
    for (std::size_t index = 18; index < 23; ++index) {
        angle = static_cast<float>((static_cast<double>(22-index)*omega)*static_cast<double>(0.2F));
        result.x[index] = static_cast<float>(bottom_radius*std::sin(static_cast<double>(angle)));
        result.y[index] = static_cast<float>(bottom_radius*(1.0-std::cos(static_cast<double>(angle)))-result.invert_offset);
    }
    // EA = sum((yi+yi-1)/2 * (xi-xi-1)); scale = REAL(sqrt(TA/EA)).
    // This area correction is part of the released boundary construction.
    double polygon_area = 0.0;
    for (std::size_t index = 1; index < 23; ++index) {
        polygon_area += ((static_cast<double>(result.y[index])+result.y[index-1])*0.5)*
            (static_cast<double>(result.x[index])-result.x[index-1]);
    }
    const float scale = static_cast<float>(std::sqrt(true_area/polygon_area));
    for (std::size_t index = 0; index < 23; ++index) {
        result.x[index] = static_cast<float>(static_cast<double>(scale)*result.x[index]);
        result.y[index] = static_cast<float>(static_cast<double>(scale)*result.y[index]);
    }
    return result;
}
}
