// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
// FEQUTL 5.80 numrmath.for:121-331, IMTQL2 and GRULE.
#include <feq/gaussian_rule.hpp>
#include <cmath>
#include <stdexcept>
#include <vector>

namespace feq {
namespace {

// Implicit QL diagonalization of a symmetric tridiagonal matrix, carrying
// only the first component of each eigenvector. Preserve the original 30
// iterations per eigenvalue and 2.2e-16 deflation threshold.
std::size_t first_component_ql(std::vector<double>& diagonal,
                              std::vector<double>& vector,
                              std::vector<double>& off_diagonal) {
    const std::size_t order = diagonal.size();
    if (order == 1) {
        return 0;
    }
    off_diagonal[order-1] = 0.0;
    for (std::size_t left = 0; left < order; ++left) {
        unsigned int iteration = 0;
        while (true) {
            std::size_t last = left;
            for (; last < order; ++last) {
                if (last+1 == order || std::fabs(off_diagonal[last]) <=
                    2.2e-16*(std::fabs(diagonal[last])+std::fabs(diagonal[last+1]))) {
                    break;
                }
            }
            double p = diagonal[left];
            if (last == left) {
                break;
            }
            if (iteration == 30) {
                return left+1;
            }
            ++iteration;
            // Form the Wilkinson shift. Original SIGN selects positive R
            // for a negative-zero G; copysign would change that choice.
            double g = (diagonal[left+1]-p)/(2.0*off_diagonal[left]);
            double r = std::sqrt(g*g+1.0);
            const double signed_r = g >= 0.0 ? std::fabs(r) : -std::fabs(r);
            g = (diagonal[last]-p)+off_diagonal[left]/(g+signed_r);
            double s = 1.0;
            double c = 1.0;
            p = 0.0;
            const std::size_t rotations = last-left;
            for (std::size_t step = 0; step < rotations; ++step) {
                const std::size_t index = last-step-1;
                double f = s*off_diagonal[index];
                const double b = c*off_diagonal[index];
                if (std::fabs(f) < std::fabs(g)) {
                    s = f/g;
                    r = std::sqrt(s*s+1.0);
                    off_diagonal[index+1] = g*r;
                    c = 1.0/r;
                    s *= c;
                } else {
                    c = g/f;
                    r = std::sqrt(c*c+1.0);
                    off_diagonal[index+1] = f*r;
                    s = 1.0/r;
                    c *= s;
                }
                g = diagonal[index+1]-p;
                r = (diagonal[index]-g)*s+(2.0*c)*b;
                p = s*r;
                diagonal[index+1] = g+p;
                g = c*r-b;
                // Apply the same rotation to the first eigenvector components.
                f = vector[index+1];
                vector[index+1] = s*vector[index]+c*f;
                vector[index] = c*vector[index]-s*f;
            }
            diagonal[left] -= p;
            off_diagonal[left] = g;
            off_diagonal[last] = 0.0;
        }
    }
    // Preserve the original selection sort and strict less-than tie handling.
    for (std::size_t index = 0; index+1 < order; ++index) {
        std::size_t selected = index;
        double value = diagonal[index];
        for (std::size_t next = index+1; next < order; ++next) {
            if (diagonal[next] >= value) {
                continue;
            }
            selected = next;
            value = diagonal[next];
        }
        if (selected != index) {
            diagonal[selected] = diagonal[index];
            diagonal[index] = value;
            value = vector[index];
            vector[index] = vector[selected];
            vector[selected] = value;
        }
    }
    return 0;
}
} // namespace

GaussianRule gaussian_rule(std::size_t order) {
    if (order < 1 || order > 256) {
        throw std::invalid_argument("Gaussian rule order must be between 1 and 256.");
    }
    GaussianRule result{std::vector<double>(order,0.0),std::vector<double>(order,0.0),0};
    std::vector<double> off_diagonal(order,0.0);
    // Golub-Welsch construction from the Legendre three-term recurrence:
    // diagonal_i=0; off_diagonal_i=i/sqrt(4*i*i-1). Eigenvalues are nodes;
    // weights are twice the squared first components of the eigenvectors.
    for (std::size_t index = 1; index < order; ++index) {
        const double value = static_cast<double>(index);
        off_diagonal[index-1] = value/std::sqrt((value*4.0)*value-1.0);
    }
    result.weights[0] = 1.0;
    result.unconverged_index = first_component_ql(result.nodes,result.weights,off_diagonal);
    for (std::size_t index = 0; index < order; ++index) {
        result.weights[index] = (2.0*result.weights[index])*result.weights[index];
    }
    return result;
}
} // namespace feq
