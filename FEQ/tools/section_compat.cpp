// Connect independently verified interpolation to the research table system.
// New work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/section_interpolation.hpp>
#include "common.hpp"

namespace {
feq::SectionTableRow read_row(const feq::BitView<real>& values, integer first, integer slope_offset) {
    feq::SectionTableRow row{};
    row.depth = values[first];
    row.top_width = values[first+1];
    row.area = values[first+2];
    row.sqrt_conveyance = values[first+3];
    row.momentum_factor = values[first+4];
    if (slope_offset != 0) {
        row.sqrt_conveyance_slope = values[first+slope_offset];
        row.momentum_factor_slope = values[first+slope_offset+1];
    }
    return row;
}
}

extern "C" void feq_interpolate_section_interval(integer first, integer next, integer slope_offset,
    real depth, real* area, real* width, real* width_slope, real* conveyance,
    real* conveyance_slope, real* beta, real* beta_slope) {
    const std::int64_t count = static_cast<std::int64_t>(sizeof(ftable_)/sizeof(real));
    const integer offsets[2] = {first,next};
    for (std::size_t index = 0; index < 2; ++index) {
        if (offsets[index] < 0 || slope_offset < 0 || static_cast<std::int64_t>(offsets[index])+4 >= count ||
            static_cast<std::int64_t>(offsets[index])+slope_offset+1 >= count) {
            throw std::out_of_range("Section interval exceeds the released table bank.");
        }
    }
    const feq::BitView<real> values(&ftable_,sizeof(ftable_));
    const feq::SectionTableRow lower = read_row(values,first,slope_offset);
    const feq::SectionTableRow upper = read_row(values,next,slope_offset);
    const feq::SectionProperties result = feq::interpolate_section(depth,lower,upper,slope_offset != 0);
    *area = result.area;
    *width = result.top_width;
    *width_slope = result.top_width_slope;
    *conveyance = result.conveyance;
    *conveyance_slope = result.conveyance_slope;
    *beta = result.momentum_factor;
    *beta_slope = result.momentum_factor_slope;
}
