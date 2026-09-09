// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/tailwater_residual.hpp>

namespace feq {
double tailwater_upstream_momentum(float flow, float momentum_factor, float area,
    float road_momentum, float first_moment, float gravity) {
    // M43 = beta3*Q3*Q3/A3 + Mroad + g*J43.
    // RTY7RF 0x41222b..0x41225d has no REAL store. M43 survives calls
    // to downstream calculations in a wide spill at EBP-0x1c.
    const double flux = ((static_cast<double>(flow)*momentum_factor)*flow)/area;
    return (flux+road_momentum)+static_cast<double>(first_moment)*gravity;
}

double tailwater_momentum_residual(double upstream_momentum, double flap_force,
    float momentum_factor, float flow, float area, float first_moment, float gravity) {
    // M44 = beta44*Q4*Q4/A44 + g*J44.
    // RTY7RF 0x4123ec..0x412422 computes M44 and the normalized momentum
    // imbalance without a REAL store, including the nominal REAL return.
    const double flux = ((static_cast<double>(momentum_factor)*flow)*flow)/area;
    const double downstream_momentum = flux+static_cast<double>(first_moment)*gravity;
    return (upstream_momentum-flap_force)/downstream_momentum-1.0;
}
}
