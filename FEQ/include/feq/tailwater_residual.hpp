// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#ifndef FEQ_TAILWATER_RESIDUAL_HPP
#define FEQ_TAILWATER_RESIDUAL_HPP

namespace feq {
// QVSTW interior tailwater level, with one-based index 2..count-1.
// Require finite elevations, upstream > free_level, count >= 3 and power > 0.
float culvert_tailwater_level(float free_level, float upstream, int index,
    int count, float power);

// The head difference remains wide through SQRT, then crosses a REAL store
// before entering QVSTW's DOUBLE PRECISION square-root-drop table.
double culvert_sqrt_drop(float upstream, float tailwater);

// Momentum flux plus hydrostatic impulse at section 43, including road flow.
// Evaluate before downstream section calculations can change the input state.
double tailwater_upstream_momentum(float flow, float momentum_factor, float area,
    float road_momentum, float first_moment, float gravity);

// RTY7RF = (M43 - flap_force)/M44 - 1. The caller supplies flap force;
// M43, M44 and the residual remain wide through the root-solver return.
double tailwater_momentum_residual(double upstream_momentum, double flap_force,
    float momentum_factor, float flow, float area, float first_moment, float gravity);
}
#endif
