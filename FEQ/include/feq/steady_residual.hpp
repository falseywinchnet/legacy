// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#ifndef FEQ_STEADY_RESIDUAL_HPP
#define FEQ_STEADY_RESIDUAL_HPP
namespace feq {
// E = y + alpha*(Q/A)^2/(2g). Profile routines may retain a wide depth
// difference even after storing its REAL copy in the output depth vector.
double steady_specific_energy(double depth, float flow, float area,
    float energy_factor, float gravity_twice);
// Qn = K*REAL(sqrt(S)) for positive S, otherwise zero. The square root
// stores REAL before multiplication; the product remains wide.
double steady_normal_flow(float conveyance, float slope);
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
