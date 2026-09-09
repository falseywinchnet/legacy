// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#ifndef FEQ_TABLE_INTERPOLATION_HPP
#define FEQ_TABLE_INTERPOLATION_HPP

#include <cstdint>

namespace feq {

enum class TableInterpolation : std::uint32_t {
    linear = 2,
    integrated_linear_derivative = 3,
    cubic_hermite = 4
};

struct FunctionTableRow {
    float argument;
    float value;
    float derivative;
};

struct FunctionTableResult {
    float value;
    float derivative;
};

// Evaluate one already selected interval of a FEQ type-2, -3, or -4 table.
// Type 3 integrates the linearly varying derivative; in a reservoir table
// the function is storage volume and its derivative is surface area.
FunctionTableResult interpolate_function_table(TableInterpolation method, float argument,
                                               const FunctionTableRow& lower,
                                               const FunctionTableRow& upper);

} // namespace feq
#endif
