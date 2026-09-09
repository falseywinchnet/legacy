// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/steady_residual.hpp>
#include <cmath>

namespace feq {
double steady_specific_energy(double depth, float flow, float area,
    float energy_factor, float gravity_twice) {
    // SFPSBE 0x426d83..0x426da4: velocity and energy have no REAL store.
    // Initial depth comes from the wide ZDN-ZBR register at 0x426aa4;
    // FST stores a REAL vector entry while retaining the original register.
    const double velocity = static_cast<double>(flow)/area;
    return ((velocity*velocity)*energy_factor)/gravity_twice+depth;
}

double steady_normal_flow(float conveyance, float slope) {
    if (slope > 0.0F) {
        // SFPSBE 0x426c8c and 0x4274dc store the square root as REAL.
        const float root = static_cast<float>(std::sqrt(static_cast<double>(slope)));
        return static_cast<double>(conveyance)*root;
    }
    return 0.0;
}

double normal_flow_residual(float root_slope, float conveyance, float flow) {
    // NDRSD 0x428627..0x42863c: (RTSBOT*K-FLOW)/FLOW. All operands
    // were stored REAL, but every arithmetic result remains wide through RET.
    return (static_cast<double>(root_slope)*conveyance-flow)/flow;
}

double steady_subcritical_residual(const SteadyResidualInput& input) {
    const double area = input.area;
    const double neighbor_area = input.neighbor_area;
    const double flow = input.flow;
    double eddy = 0.0;
    // EDDY = Kdec*(1/A^2 - 1/Ar^2)*Q^2/(2g), when A < Ar;
    // otherwise Kacc*(1/Ar^2 - 1/A^2)*Q^2/(2g).
    // Original 0x425882..0x425902 has no intervening REAL stores.
    if (area < neighbor_area) {
        eddy = ((1.0/(area*area)-1.0/(neighbor_area*neighbor_area))*input.deceleration_loss)*
            (flow*flow)/input.gravity_twice;
    } else {
        eddy = ((1.0/(neighbor_area*neighbor_area)-1.0/(area*area))*input.acceleration_loss)*
            (flow*flow)/input.gravity_twice;
    }
    // E = y + alpha*(Q/A)^2/(2g).
    // SBER = [E - {DX*(Q^2/(K*Kr) + Se) + RHS + EDDY}]/E.
    // Velocity, energy, and the returned residual remain wide through RET
    // at 0x425950; even the nominal REAL return has no binary32 store.
    const double energy = steady_specific_energy(input.depth,input.flow,input.area,
        input.energy_factor,input.gravity_twice);
    const double friction = (flow*flow)/(static_cast<double>(input.neighbor_conveyance)*input.conveyance);
    const double demand = ((friction+input.bed_slope)*input.distance+input.right_hand_side)+eddy;
    return (energy-demand)/energy;
}

double steady_supercritical_residual(const SteadyResidualInput& input) {
    const double area = input.area;
    const double neighbor_area = input.neighbor_area;
    const double flow = input.flow;
    double eddy = 0.0;
    // EDDY = Kdec*(1/Al^2 - 1/A^2)*Qr^2/(2g), when Al < A;
    // otherwise Kacc*(1/A^2 - 1/Al^2)*Qr^2/(2g).
    // Original 0x426042..0x4260bf retains all intermediates in registers.
    if (neighbor_area < area) {
        eddy = ((1.0/(neighbor_area*neighbor_area)-1.0/(area*area))*input.deceleration_loss)*
            (flow*flow)/input.gravity_twice;
    } else {
        eddy = ((1.0/(area*area)-1.0/(neighbor_area*neighbor_area))*input.acceleration_loss)*
            (flow*flow)/input.gravity_twice;
    }
    // E = y + alpha*(Qr/A)^2/(2g).
    // SPER = [RHS - {E + DX*(Ql*Qr/(K*Kl) + Se) + EDDY}]/E.
    const double energy = steady_specific_energy(input.depth,input.flow,input.area,
        input.energy_factor,input.gravity_twice);
    const double friction = (static_cast<double>(input.neighbor_flow)*flow)/
        (static_cast<double>(input.neighbor_conveyance)*input.conveyance);
    const double demand = ((friction+input.bed_slope)*input.distance+energy)+eddy;
    return (input.right_hand_side-demand)/energy;
}
}
