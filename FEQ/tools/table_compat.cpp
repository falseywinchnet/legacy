// Connect verified scalar interpolation to the research table bank.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/table_interpolation.hpp>
#include "common.hpp"

extern "C" void feq_interpolate_function_interval(integer method, integer first, integer stride,
    real argument, real* value, real* derivative) {
    if (method < 2 || method > 4 || stride != (method == 2 ? 2 : 3)) {
        throw std::invalid_argument("Invalid function-table interpolation layout.");
    }
    const std::int64_t count = static_cast<std::int64_t>(sizeof(ftable_)/sizeof(real));
    if (first < 0 || static_cast<std::int64_t>(first)+2*stride > count) {
        throw std::out_of_range("Function-table interval exceeds the released table bank.");
    }
    const feq::BitView<real> values(&ftable_,sizeof(ftable_));
    const feq::FunctionTableRow lower{values[first],values[first+1],stride == 3 ? values[first+2] : 0.0f};
    const feq::FunctionTableRow upper{values[first+stride],values[first+stride+1],
                                    stride == 3 ? values[first+stride+2] : 0.0f};
    const feq::FunctionTableResult result = feq::interpolate_function_table(
        static_cast<feq::TableInterpolation>(method),argument,lower,upper);
    *value = result.value;
    *derivative = result.derivative;
}
