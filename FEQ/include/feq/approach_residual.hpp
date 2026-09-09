// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#ifndef FEQ_APPROACH_RESIDUAL_HPP
#define FEQ_APPROACH_RESIDUAL_HPP
namespace feq {
struct ApproachResidualInput {
    float depth;
    float area;
    float conveyance;
    float energy_factor;
    float flow;
    float bottom_elevation;
    float neighbor_flow;
    float neighbor_bottom_elevation;
    float neighbor_depth;
    float neighbor_area;
    float neighbor_conveyance;
    float neighbor_energy_factor;
    float distance;
    float entrance_loss;
    float expansion_loss;
    float discharge_coefficient;
    float velocity_loss;
    float gravity_twice;
};
struct ApproachResidual {
    double value;
    bool contracting;
};
// RAPP energy balance following XLKTAL. The original REAL function returns
// a wide register. All inputs reflect the stored section properties.
ApproachResidual approach_residual(const ApproachResidualInput& input);
// RQVSTW returns the wide difference of the stored approach and target heads.
double approach_head_residual(float head, float target_head);
}
#endif
