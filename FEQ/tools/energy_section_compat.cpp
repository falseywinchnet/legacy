// Connect independently verified XLKT22 arithmetic to the research table bank.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/section_energy.hpp>
#include "common.hpp"

namespace {
feq::EnergySectionRow read_energy_row(const feq::BitView<real>& values,
    integer first, integer slope_offset, integer table_type) {
    const std::int64_t count = static_cast<std::int64_t>(sizeof(ftable_)/sizeof(real));
    const integer alpha_offset = table_type == 32 ? 2 : 4;
    if (first < 0 || slope_offset < 0 || static_cast<std::int64_t>(first)+7 >= count ||
        (slope_offset != 0 && static_cast<std::int64_t>(first)+slope_offset+alpha_offset >= count)) {
        throw std::out_of_range("Energy section interval exceeds the released table bank.");
    }
    feq::EnergySectionRow row{};
    row.section.depth = values[first];
    row.section.top_width = values[first+1];
    row.section.area = values[first+2];
    row.section.sqrt_conveyance = values[first+3];
    row.section.momentum_factor = values[first+4];
    row.first_moment = values[first+5];
    row.energy_factor = values[first+6];
    row.critical_flow = values[first+7];
    if (slope_offset != 0) {
        row.section.sqrt_conveyance_slope = values[first+slope_offset];
        row.section.momentum_factor_slope = values[first+slope_offset+1];
        row.energy_factor_slope = values[first+slope_offset+alpha_offset];
    }
    return row;
}
}

extern "C" void feq_interpolate_energy_section_interval(integer first, integer next,
    integer slope_offset, integer table_type, real depth, real* area, real* width,
    real* width_slope, real* moment, real* conveyance, real* conveyance_slope,
    real* beta, real* beta_slope, real* alpha, real* alpha_slope, real* critical_flow) {
    const feq::BitView<real> values(&ftable_,sizeof(ftable_));
    const feq::EnergySectionRow lower = read_energy_row(values,first,slope_offset,table_type);
    const feq::EnergySectionRow upper = read_energy_row(values,next,slope_offset,table_type);
    feq::EnergySectionRow following{};
    const feq::EnergySectionRow* following_pointer = nullptr;
    if (lower.section.depth == 0.0F && depth > 0.0F) {
        // The original zero-depth rule obtains critical-flow values from
        // the next interval, without changing the geometric interval.
        if (next < first || static_cast<std::int64_t>(next)+(next-first) >=
            static_cast<std::int64_t>(sizeof(ftable_)/sizeof(real))) {
            throw std::out_of_range("Energy section following row exceeds the released table bank.");
        }
        following = read_energy_row(values,next+(next-first),slope_offset,table_type);
        following_pointer = &following;
    }
    const feq::EnergySectionProperties result = feq::interpolate_energy_section(
        depth,lower,upper,slope_offset != 0,following_pointer);
    *area = result.section.area;
    *width = result.section.top_width;
    *width_slope = result.section.top_width_slope;
    *moment = result.first_moment;
    *conveyance = result.section.conveyance;
    *conveyance_slope = result.section.conveyance_slope;
    *beta = result.section.momentum_factor;
    *beta_slope = result.section.momentum_factor_slope;
    *alpha = result.energy_factor;
    *alpha_slope = result.energy_factor_slope;
    *critical_flow = result.critical_flow;
}
