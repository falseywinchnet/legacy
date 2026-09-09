// Deterministic power evaluation with the released FEQ/FEQUTL arithmetic.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#ifndef FEQ_POWER_HPP
#define FEQ_POWER_HPP

namespace feq {
// Preserve the released real/double power approximations, including sequential
// multiplication for positive integral exponents less than eight. Arguments
// must be finite. A negative base requires an integral exponent; zero requires
// a nonnegative exponent. Invalid arguments throw std::invalid_argument.
// Overflow returns the released finite saturation value; underflow follows
// the corresponding original kernel. These functions do not use host libm pow.
float legacy_power(float base, float exponent);
double legacy_power(double base, double exponent);
}
#endif
