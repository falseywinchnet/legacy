// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#ifndef FEQ_TRIGONOMETRY_HPP
#define FEQ_TRIGONOMETRY_HPP
namespace feq {
// Original REAL ASIN/ACOS accept binary32 but return an unrounded register
// result. Keep that result binary64 until the caller's observed REAL store.
// Inputs must be finite and in [-1,1]. Legacy runtime error callbacks are
// outside these numerical kernels; invalid domains throw invalid_argument.
double legacy_arcsine(float value);
double legacy_arccosine(float value);
}
#endif
