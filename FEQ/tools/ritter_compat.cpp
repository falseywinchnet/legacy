// Connect original-verified Ritter interpolation to the research table bank.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/ritter_flow.hpp>
#include "common.hpp"

extern "C" void feq_interpolate_ritter_section_interval(integer first, integer next,
    real depth, real gravity, real* area, real* width, real* width_slope,
    real* celerity, real* escoffier) {
    const std::int64_t count = static_cast<std::int64_t>(sizeof(ftable_)/sizeof(real));
    if (first < 0 || next <= first || static_cast<std::int64_t>(next)+4 >= count) {
        throw std::out_of_range("Ritter section interval exceeds the released table bank.");
    }
    const feq::BitView<real> values(&ftable_,sizeof(ftable_));
    const feq::RitterSectionRow lower{values[first],values[first+1],values[first+2],values[first+3],values[first+4]};
    const feq::RitterSectionRow upper{values[next],values[next+1],values[next+2],values[next+3],values[next+4]};
    const feq::RitterSectionProperties result = feq::interpolate_ritter_section(depth,gravity,lower,upper);
    *area = result.area;
    *width = result.top_width;
    *width_slope = result.top_width_slope;
    *celerity = result.celerity;
    *escoffier = result.escoffier;
}
