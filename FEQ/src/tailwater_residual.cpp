// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/tailwater_residual.hpp>
#include <feq/power.hpp>
#include <cmath>

namespace feq {
float culvert_tailwater_level(float free_level, float upstream, int index,
    int count, float power) {
    // ZT(i) = Zfree + (Zup-Zfree)*(1-REAL((N-i)/(N-1))**power).
    // QVSTW 0x412fbf retains 1/(N-1); 0x41301c stores its product as
    // REAL. _g_arxr returns REAL; DZ and the subsequent arithmetic stay wide.
    const double reciprocal = 1.0/(count-1);
    const float fraction = static_cast<float>((count-index)*reciprocal);
    const float powered = legacy_power(fraction,power);
    const double difference = static_cast<double>(upstream)-free_level;
    return static_cast<float>(free_level+difference*(1.0-powered));
}

double culvert_sqrt_drop(float upstream, float tailwater) {
    // SQRTDP = DOUBLE(REAL(sqrt(Zup-Ztail))); 0x412efa..0x412f08 and
    // 0x414012..0x414021 store and reload REAL before the DOUBLE table store.
    return static_cast<float>(std::sqrt(static_cast<double>(upstream)-tailwater));
}

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
