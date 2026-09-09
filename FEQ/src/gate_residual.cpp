// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
// FEQUTL 5.80 ufgate.for; released residuals and free/submerged gate states.
#include <feq/gate_residual.hpp>
#include <cmath>

namespace feq {
namespace {
double momentum(const GateResidualInput& input, float squared_flow, double jet_area) {
    // R = [g*(J3-J4) + Q^2*(1/Ajet-beta4/A4)]/(g*J4).
    // The released routines retain this entire result in the FPU register.
    const double hydrostatic = input.gravity*(static_cast<double>(input.jet_first_moment)-input.tailwater_first_moment);
    const double jet_velocity = 1.0/jet_area;
    const double tailwater_velocity = static_cast<double>(input.tailwater_momentum_factor)/input.tailwater_area;
    const double numerator = hydrostatic+squared_flow*(jet_velocity-tailwater_velocity);
    const double denominator = static_cast<double>(input.gravity)*input.tailwater_first_moment;
    return numerator/denominator;
}
}

GateResidual gate_orifice_jet_residual(const GateResidualInput& input) {
    // Q^2 = AT^2*2g*(Z1+Y1-Y3-Z3)/(1-alpha1*(AT/A1)^2).
    const double effective_area = input.effective_area;
    const double surface = static_cast<double>(input.upstream_depth)+input.upstream_bottom;
    const double head = (surface-input.jet_depth)-input.jet_bottom;
    const double numerator = (effective_area*effective_area)*(head*input.gravity_twice);
    const double ratio = effective_area/input.upstream_area;
    const double denominator = 1.0-(ratio*ratio)*input.upstream_energy_factor;
    // Original 0x47ea68 stores QSQR as REAL before momentum uses it.
    const float squared_flow = static_cast<float>(numerator/denominator);
    const double jet_area = static_cast<double>(input.gate_area)*input.contraction_coefficient;
    return GateResidual{momentum(input,squared_flow,jet_area),squared_flow};
}

GateResidual gate_weir_jet_residual(const GateResidualInput& input) {
    // Q^2 = 2g*(Z1+Y1-Z3-Y3) /
    //       [1/(CD*BG*(Y3+DZ))^2-alpha1/A1^2].
    const double surface = static_cast<double>(input.upstream_depth)+input.upstream_bottom;
    const double head = (surface-input.jet_bottom)-input.jet_depth;
    const double depth = static_cast<double>(input.jet_depth_offset)+input.jet_depth;
    const double coefficient_width = static_cast<double>(input.gate_width)*input.discharge_coefficient;
    const double effective_area = coefficient_width*depth;
    const double upstream_area = input.upstream_area;
    const double denominator = 1.0/(effective_area*effective_area)-
        input.upstream_energy_factor/(upstream_area*upstream_area);
    // Original 0x47ebea stores QSQR; the width and depth remain wide.
    const float squared_flow = static_cast<float>((head*input.gravity_twice)/denominator);
    const double jet_area = input.gate_width*depth;
    return GateResidual{momentum(input,squared_flow,jet_area),squared_flow};
}

GateResidual gate_orifice_tailwater_residual(const GateResidualInput& input) {
    const double jet_area = static_cast<double>(input.gate_area)*input.contraction_coefficient;
    return GateResidual{momentum(input,input.squared_flow,jet_area),input.squared_flow};
}

GateResidual gate_weir_tailwater_residual(const GateResidualInput& input) {
    const double depth = static_cast<double>(input.jet_depth)+input.jet_depth_offset;
    const double jet_area = depth*input.gate_width;
    return GateResidual{momentum(input,input.squared_flow,jet_area),input.squared_flow};
}

GateTailwaterLevels gate_tailwater_levels(float upstream_depth, float upstream_bottom,
    float tailwater_depth, float tailwater_bottom, float datum) {
    // UFGATE 0x4819a9..0x4819d3: ZW4F=Z4B+Y4F remains wide, then
    // H4F=ZW4F-HDATUM and FDROP=(Y1+Z1B)-ZW4F also remain wide.
    const double surface = static_cast<double>(tailwater_bottom)+tailwater_depth;
    const double upstream_surface = static_cast<double>(upstream_depth)+upstream_bottom;
    return GateTailwaterLevels{surface-datum,upstream_surface-surface};
}

GateSubmergedLevels gate_submerged_levels(float upstream_depth, float upstream_bottom,
    double free_drop, float drop_fraction, float tailwater_bottom, float datum) {
    // UFGATE 0x481b76..0x481bab: DROP=FDROP*PFD, ZW4=Y1+Z1B-DROP.
    // Y4=REAL(ZW4-Z4B), but H4=ZW4-HDATUM uses the retained ZW4.
    const double drop = free_drop*drop_fraction;
    const double surface = (static_cast<double>(upstream_depth)+upstream_bottom)-drop;
    return GateSubmergedLevels{static_cast<float>(surface-tailwater_bottom),surface-datum,drop};
}

GateCriticalSetup gate_critical_setup(float opening, float width, float gravity,
    float gravity_twice, float discharge_coefficient, float gate_bottom, float upstream_bottom) {
    // UFGATE 0x480b47..0x480bbd: AG=REAL(HG*BG), V=REAL(sqrt(HG*g)),
    // Q=REAL(AG*V). Both REAL stores precede the energy calculation.
    const float area = static_cast<float>(static_cast<double>(opening)*width);
    const float speed = static_cast<float>(std::sqrt(static_cast<double>(opening)*gravity));
    const float flow = static_cast<float>(static_cast<double>(area)*speed);
    const double surface = static_cast<double>(opening)+gate_bottom;
    const double velocity = flow/(static_cast<double>(area)*discharge_coefficient);
    // RHS=REAL(Z2+HG+(Q/(AG*CD))^2/(2g)-Z1), Y=REAL(Z2+HG-Z1).
    const float energy = static_cast<float>((surface+(velocity*velocity)/gravity_twice)-upstream_bottom);
    return GateCriticalSetup{area,opening,flow,energy,static_cast<float>(surface-upstream_bottom)};
}

GateFreeWeir gate_free_weir(double head, float discharge_coefficient,
    float upstream_energy_factor, float width, float upstream_area, float gravity,
    float relative_tolerance) {
    // UFGATE 0x4816af..0x481762: D=1+0.5/CD^2,
    // Y=H1/(D-F), F=0.5*alpha1*(Y*BG/A1)^2.
    const double coefficient = discharge_coefficient;
    const double divisor = 0.5/(coefficient*coefficient)+1.0;
    double factor = 0.0;
    double previous_depth = 0.0;
    double depth = 0.0;
    for (;;) {
        depth = head/(divisor-factor);
        // Preserve the original unordered-comparison exit for zero depth.
        if (!(std::abs(depth-previous_depth)/depth > relative_tolerance)) { break; }
        previous_depth = depth;
        const double ratio = (depth*width)/upstream_area;
        factor = (static_cast<double>(upstream_energy_factor)*0.5)*(ratio*ratio);
    }
    // Only the converged depth is stored. The square root is separately
    // rounded to REAL at 0x481750 before Q=REAL(Y*BG*REAL(sqrt(Y*g))).
    const float stored_depth = static_cast<float>(depth);
    const float speed = static_cast<float>(std::sqrt(static_cast<double>(stored_depth)*gravity));
    const float flow = static_cast<float>((static_cast<double>(stored_depth)*width)*speed);
    return GateFreeWeir{stored_depth,flow};
}

float gate_upstream_head(float depth, float upstream_bottom, float datum) {
    // UFGATE 0x480bf8..0x480c10: H1FWUL=REAL((Z1B+Y)-HDATUM).
    // There is no intervening REAL store of Z1FWUL=Z1B+Y.
    return static_cast<float>((static_cast<double>(upstream_bottom)+depth)-datum);
}

GateFreeOrifice gate_free_orifice(float head, float datum, float discharge_coefficient,
    float contraction_coefficient, float gate_area, float opening, float gate_bottom,
    float upstream_area, float upstream_energy_factor, float gravity_twice) {
    // FNDFOQ 0x47ee92..0x47eef4: AT=REAL(CD*CC*AG),
    // HVC=(HG*CC+Z2B)-HDATUM, V=REAL(sqrt((H1-HVC)*2g /
    // (1-(AT/A1)^2*alpha1))), Q=REAL(AT*V).
    const float area = static_cast<float>((static_cast<double>(discharge_coefficient)*
        contraction_coefficient)*gate_area);
    const double contraction_head = (static_cast<double>(opening)*
        contraction_coefficient+gate_bottom)-datum;
    const double numerator = (head-contraction_head)*gravity_twice;
    const double ratio = static_cast<double>(area)/upstream_area;
    const double denominator = 1.0-(ratio*ratio)*upstream_energy_factor;
    const float speed = static_cast<float>(std::sqrt(numerator/denominator));
    const float flow = static_cast<float>(static_cast<double>(area)*speed);
    return GateFreeOrifice{area,flow};
}
} // namespace feq
