// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#ifndef FEQ_FULL_BARREL_HPP
#define FEQ_FULL_BARREL_HPP
namespace feq {
struct FullBarrelInput {
    float upstream_area;
    float upstream_energy_factor;
    float upstream_conveyance;
    float upstream_elevation;
    float entrance_area;
    float entrance_conveyance;
    float exit_area;
    float discharge_coefficient;
    float velocity_area;
    float exit_piezometric_elevation;
    float approach_length;
    float approach_loss;
    float gravity_twice;
    float road_flow;
    float relative_tolerance;
    double barrel_friction_factor;
};
struct FullBarrelResult {
    float flow;
    float entrance_piezometric_elevation;
};
// FULBAR for a barrel flowing full along its entire length. Inputs are stored
// section properties in one consistent unit system. Positive road flow adds
// the original fixed-point iteration, with the original relative tolerance.
FullBarrelResult full_barrel(const FullBarrelInput& input);
}
#endif
