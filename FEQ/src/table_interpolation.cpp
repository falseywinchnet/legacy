// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
// FEQ 10.61 fqshrftb.for:2793-2846; original LKTAB RVA 0x35d40.
#include <feq/table_interpolation.hpp>

#include <cmath>
#include <limits>
#include <stdexcept>

namespace feq {

static_assert(std::numeric_limits<float>::is_iec559 && std::numeric_limits<float>::digits == 24);
static_assert(std::numeric_limits<double>::is_iec559 && std::numeric_limits<double>::digits == 53);

FunctionTableResult interpolate_function_table(TableInterpolation method, float argument,
                                               const FunctionTableRow& lower,
                                               const FunctionTableRow& upper) {
    if (!std::isfinite(argument) || !std::isfinite(lower.argument) || !std::isfinite(upper.argument) ||
        upper.argument <= lower.argument || argument < lower.argument || argument > upper.argument) {
        throw std::invalid_argument("Function-table interpolation requires an increasing interval containing the argument.");
    }
    const double h = static_cast<double>(upper.argument)-lower.argument;
    const double step = static_cast<double>(argument)-lower.argument;
    const double p = step/h;
    FunctionTableResult result{};
    if (method == TableInterpolation::linear) {
        // F(x)=F0+p*(F1-F0), F'(x)=(F1-F0)/h.
        // Original 0x435feb retains p until the final binary32 function store.
        const double difference = static_cast<double>(upper.value)-lower.value;
        result.value = static_cast<float>(lower.value+p*difference);
        result.derivative = static_cast<float>(difference/h);
    } else if (method == TableInterpolation::integrated_linear_derivative) {
        // F'(x)=F0'+p*(F1'-F0'); F(x)=F0+step*(F0'+F'(x))/2.
        // The FST at 0x43605e stores F' as binary32 but retains its wider
        // value for the volume integral. Reloading the stored area changes
        // storage by whole cubic feet in the published reservoir example.
        const double derivative = lower.derivative+p*(static_cast<double>(upper.derivative)-lower.derivative);
        result.derivative = static_cast<float>(derivative);
        result.value = static_cast<float>(lower.value+(0.5*step)*(lower.derivative+derivative));
    } else if (method == TableInterpolation::cubic_hermite) {
        // With D=F1-F0, a2=3D-h*(2F0'+F1'), a3=h*(F0'+F1')-2D:
        // F=F0+step*F0'+p^2*(a2+p*a3),
        // F'=F0'+p*(2a2+3a3*p)/h.
        // Preserve the released evaluation order (0x43607b-0x43612a).
        const double difference = static_cast<double>(upper.value)-lower.value;
        const double a2 = 3.0*difference-h*((static_cast<double>(lower.derivative)+lower.derivative)+upper.derivative);
        const double a3 = h*(static_cast<double>(lower.derivative)+upper.derivative)-(difference+difference);
        result.derivative = static_cast<float>(lower.derivative+(p*((a2+a2)+(3.0*a3)*p))/h);
        result.value = static_cast<float>((lower.value+step*lower.derivative)+(p*p)*(a2+p*a3));
    } else {
        throw std::invalid_argument("Unsupported function-table interpolation method.");
    }
    return result;
}

} // namespace feq
