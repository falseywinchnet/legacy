// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#ifndef FEQ_CULVERT_LOSS_HPP
#define FEQ_CULVERT_LOSS_HPP
namespace feq {
// DEGCON adjusts the discharge coefficient for the degree of contraction.
// Areas must be positive. The caller controls the final REAL coefficient store.
double culvert_contraction(float coefficient, float approach_area, float control_area);
// RQVSTW's DH = (1/CD^2 - 1)*(Q/A)^2/(2*g), with the original REAL result store.
float culvert_head_loss(float coefficient, float flow, float area, float twice_gravity);
}
#endif
