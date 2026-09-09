// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/approach_residual.hpp>

namespace feq {
double approach_head_residual(float head, float target_head) {
    // Original RQVSTW 0x42dd67..0x42dd73 has no REAL result store.
    return static_cast<double>(head)-target_head;
}

ApproachResidual approach_residual(const ApproachResidualInput& input) {
    // VH1=(Q1/A1)^2/(2g), VH2=(Q2/A2)^2/(2g).
    // Original 0x42b249..0x42b285 retains both velocity heads in registers.
    const double velocity = static_cast<double>(input.flow)/input.area;
    const double neighbor_velocity = static_cast<double>(input.neighbor_flow)/input.neighbor_area;
    const double velocity_head = (velocity*velocity)/input.gravity_twice;
    const double neighbor_velocity_head = (neighbor_velocity*neighbor_velocity)/input.gravity_twice;
    // Friction = Q1*L*Q2/(K1*K2); each product is wide and ordered as released.
    const double friction = ((static_cast<double>(input.flow)*input.distance)*input.neighbor_flow)/
        (static_cast<double>(input.conveyance)*input.neighbor_conveyance);
    const double neighbor_energy = (neighbor_velocity_head*input.neighbor_energy_factor+
        input.neighbor_bottom_elevation)+input.neighbor_depth;
    const bool contracting = !(input.area <= input.neighbor_area);
    double coefficient = input.discharge_coefficient;
    double energy = 0.0;
    double demand = 0.0;
    if (!contracting) {
        // For r=A1/A2 > REAL(.95), f=20*(1-r), CD=CDIN+f*(REAL(.98)-CDIN),
        // and APPFAC=f*APPEXP. Otherwise CD=REAL(.98), APPFAC=APPEXP.
        // Threshold and asymptote are the original binary32 constants.
        const double ratio = static_cast<double>(input.area)/input.neighbor_area;
        double expansion_factor = input.expansion_loss;
        if (ratio > static_cast<double>(0.95F)) {
            const double factor = (1.0-ratio)*20.0;
            coefficient = (static_cast<double>(0.98F)-input.discharge_coefficient)*factor+
                input.discharge_coefficient;
            expansion_factor = factor*input.expansion_loss;
        } else {
            coefficient = 0.98F;
        }
        // EXLOSS=max(0,APPFAC*(ALP1*VH1-ALP2*VH2)).
        double expansion = (velocity_head*input.energy_factor-
            neighbor_velocity_head*input.neighbor_energy_factor)*expansion_factor;
        if (expansion < 0.0) { expansion = 0.0; }
        // RAPP = (ALP1-APPLOS)*VH1+ZB1+Y1 -
        //        [ALP2*VH2+ZB2+Y2+friction+EXLOSS+(1/CD^2-1)*VHLOSS].
        energy = ((static_cast<double>(input.energy_factor)-input.entrance_loss)*velocity_head+
            input.bottom_elevation)+input.depth;
        demand = (neighbor_energy+friction)+expansion;
    } else {
        // Contracting approach: RAPP=ALP1*VH1+ZB1+Y1 -
        // [ALP2*VH2+ZB2+Y2+friction+APPLOS*VH1+(1/CDIN^2-1)*VHLOSS].
        energy = (velocity_head*input.energy_factor+input.bottom_elevation)+input.depth;
        demand = (neighbor_energy+friction)+velocity_head*input.entrance_loss;
    }
    const double contraction_loss = (1.0/(coefficient*coefficient)-1.0)*input.velocity_loss;
    return ApproachResidual{energy-(demand+contraction_loss),contracting};
}
}
