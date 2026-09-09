// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#ifndef FEQ_GAUSSIAN_RULE_HPP
#define FEQ_GAUSSIAN_RULE_HPP
#include <cstddef>
#include <vector>

namespace feq {
struct GaussianRule {
    std::vector<double> nodes;
    std::vector<double> weights;
    // Zero on convergence; otherwise the original one-based IMTQL2 index.
    // A failed QL iteration preserves its partial results, as GRULE does.
    std::size_t unconverged_index;
};

// GRULE: Gauss-Legendre nodes and weights on [-1,1], in ascending node order.
// The released routine has storage for orders 1 through 256. FEQUTL's shared
// cross-section quadrature bank uses at most 21 of these supported points.
GaussianRule gaussian_rule(std::size_t order);
} // namespace feq
#endif
