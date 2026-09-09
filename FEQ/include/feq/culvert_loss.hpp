// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#ifndef FEQ_CULVERT_LOSS_HPP
#define FEQ_CULVERT_LOSS_HPP
namespace feq {
enum class CulvertShape { pipe, flared, box, miter, rcptg };
struct CulvertCoefficientInput {
    CulvertShape shape;
    int flow_type;
    float upstream_height;
    float upstream_level;
    float entrance_bed;
    float flow;
    float critical_flow;
    float rounding_factor;
    float wing_factor;
    float projection_factor;
};
// FCD123's fitted discharge curves and entrance adjustments. For box type 3,
// the caller supplies critical flow from the section with smaller flow area.
// ratio_flag retains its prior nonzero value when an invalid head ratio occurs.
double culvert_discharge_coefficient(const CulvertCoefficientInput& input, int& ratio_flag);
// DEGCON adjusts the discharge coefficient for the degree of contraction.
// Areas must be positive. The caller controls the final REAL coefficient store.
double culvert_contraction(float coefficient, float approach_area, float control_area);
// RQVSTW's DH = (1/CD^2 - 1)*(Q/A)^2/(2*g), with the original REAL result store.
float culvert_head_loss(float coefficient, float flow, float area, float twice_gravity);
}
#endif
