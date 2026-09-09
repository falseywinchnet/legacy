// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#ifndef FEQ_POWER_SPACING_HPP
#define FEQ_POWER_SPACING_HPP

namespace feq {
// LSTOPF's geometric breakpoint sequence after its argument-ratio lookup.
// Inputs must be finite, first < last, first+offset > 0, argument_ratio > 1,
// and the calculated interval count must fit in a positive int below INT_MAX.
// On success, return the point count and preserve error_flag. If capacity is
// insufficient, return -1, set error_flag to 1, and leave all points unchanged.
// The caller supplies storage for capacity floats (or none for zero capacity).
int power_breakpoints(float first, float last, float offset, float argument_ratio,
    float* points, int capacity, int& error_flag);
} // namespace feq
#endif
