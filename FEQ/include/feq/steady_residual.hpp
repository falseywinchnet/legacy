// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#ifndef FEQ_STEADY_RESIDUAL_HPP
#define FEQ_STEADY_RESIDUAL_HPP
namespace feq {
struct SteadyResidualInput {
    float depth;
    float area;
    float conveyance;
    float energy_factor;
    float flow;
    float neighbor_flow;
    float neighbor_conveyance;
    float distance;
    float bed_slope;
    float right_hand_side;
    float acceleration_loss;
    float deceleration_loss;
    float neighbor_area;
    float gravity_twice;
};
// SBER/SPER normalized energy residuals. Section properties come from XLKTAL
// at min(depth, barrel height), but energy uses the original query depth.
// The released REAL functions return a wide register; callers own the store.
double steady_subcritical_residual(const SteadyResidualInput& input);
double steady_supercritical_residual(const SteadyResidualInput& input);
}
#endif
