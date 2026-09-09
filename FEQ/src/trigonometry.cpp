// Original Lahey REAL inverse-trigonometric approximation kernels.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/trigonometry.hpp>
#include <bit>
#include <cmath>
#include <cstdint>
#include <stdexcept>

namespace feq {
namespace {
constexpr double coefficient(std::uint32_t bits) {
    return static_cast<double>(std::bit_cast<float>(bits));
}
constexpr double half_pi = 1.5707963272;
constexpr double pi = 3.1415926536;
constexpr double boundary = coefficient(0x3f3504f3U);
void require_domain(float value) {
    if (!std::isfinite(value) || value < -1.0F || value > 1.0F) {
        throw std::invalid_argument("Inverse-trigonometric argument must be finite and in [-1,1].");
    }
}
}

double legacy_arcsine(float value) {
    require_domain(value);
    const double magnitude = std::abs(static_cast<double>(value));
    const double square = static_cast<double>(value)*value;
    if (magnitude <= 0.5) {
        // Original 0x4a108b: asin(x) = x*(1+x^2*P(x^2)).
        // P coefficients are the exact REAL words at VA 0x54dd04..0x54dd14.
        double polynomial = coefficient(0x3d2ea2b3U);
        polynomial = polynomial*square+coefficient(0x3cc3723fU);
        polynomial = polynomial*square+coefficient(0x3d3a92d3U);
        polynomial = polynomial*square+coefficient(0x3d997c6cU);
        polynomial = polynomial*square+coefficient(0x3e2aaafeU);
        polynomial = polynomial*square+1.0;
        return polynomial*value;
    }
    if (magnitude <= boundary) {
        // Original 0x4a10c6: second polynomial, VA 0x54dd18..0x54dd30.
        // Add b0 and 1 separately, preserving the original operation order.
        double polynomial = coefficient(0x3e83b788U);
        polynomial = polynomial*square+coefficient(0xbebec946U);
        polynomial = polynomial*square+coefficient(0x3ea6a484U);
        polynomial = polynomial*square+coefficient(0xbd9dad31U);
        polynomial = polynomial*square+coefficient(0x3dd45521U);
        polynomial = polynomial*square+coefficient(0x3e26f164U);
        polynomial = polynomial*square+coefficient(0x394a2d37U);
        polynomial += 1.0;
        return polynomial*value;
    }
    // The released half-pi constant is intentionally not mathematical pi/2.
    const double result = half_pi-legacy_arccosine(static_cast<float>(magnitude));
    return value < 0.0F ? -result : result;
}

double legacy_arccosine(float value) {
    require_domain(value);
    const double magnitude = std::abs(static_cast<double>(value));
    if (magnitude <= boundary) { return half_pi-legacy_arcsine(value); }
    // Original 0x4a1abf: acos(|x|) = sqrt(1-|x|)*(1+P(1-|x|)).
    // The square root and Horner steps retain binary64. Coefficients are
    // exact REAL words at VA 0x55039c..0x5503ac, separate from ASIN's tables.
    const double distance = 1.0-magnitude;
    const double root = std::sqrt(distance);
    double polynomial = coefficient(0x3b6a26caU);
    polynomial = polynomial*distance+coefficient(0x3bfaa250U);
    polynomial = polynomial*distance+coefficient(0x3cd97060U);
    polynomial = polynomial*distance+coefficient(0x3df15b6aU);
    polynomial = polynomial*distance+coefficient(0x3ed413cdU);
    polynomial += 1.0;
    const double result = polynomial*root;
    return value < 0.0F ? pi-result : result;
}
}
