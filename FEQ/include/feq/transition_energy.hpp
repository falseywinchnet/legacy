// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#ifndef FEQ_TRANSITION_ENERGY_HPP
#define FEQ_TRANSITION_ENERGY_HPP

namespace feq {
// FACDC smoothing for expansion/contraction losses. Require finite inputs
// and nonnegative smoothing. The original returns a wide value in every branch.
double transition_loss_factor(float argument, float smoothing,
    float acceleration_coefficient, float deceleration_coefficient);

// GMEAN = square of the generalized mean of two positive conveyances.
// Require finite positive conveyances and a finite exponent. The geometric
// branch returns their wide product; the power branch stores REAL at return.
double transition_conveyance_mean(float left, float right, float exponent);

struct TransitionEnergyInput {
    float left_total_head;
    float right_piezometric_head;
    float left_area;
    float right_area;
    float left_energy_factor;
    float right_energy_factor;
    float left_conveyance;
    float right_conveyance;
    float distance;
    float smoothing;
    float acceleration_coefficient;
    float deceleration_coefficient;
    float gravity_twice;
    float flow;
    float mean_exponent;
};

// ECECHK's imbalance divided by max(total-head difference, minimum_drop).
// Require positive areas, conveyances, gravity, left total head and minimum
// drop; nonnegative energy factors and smoothing; finite remaining inputs.
double transition_energy_check(const TransitionEnergyInput& input, float minimum_drop);

// FHPL's residual after its section lookup and stored left total head.
// The same input requirements apply, without the minimum-drop parameter.
double transition_head_residual(const TransitionEnergyInput& input);

// FRLRES's successful-lookup branch: 1-Q/Qcritical, retained wide.
double transition_froude_residual(float flow, float critical_flow);

// EXPCON partial free flow for one-based index 1..count, count >= 2,
// finite positive power; preserve the original REAL power argument/result.
float transition_partial_free_flow(int index, int count, float power);
}
#endif
