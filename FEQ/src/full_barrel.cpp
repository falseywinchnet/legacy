// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/full_barrel.hpp>
#include <cmath>

namespace feq {
FullBarrelResult full_barrel(const FullBarrelInput& input) {
    const double coefficient = input.discharge_coefficient;
    const double velocity_area = input.velocity_area;
    const double energy_factor = static_cast<double>(input.upstream_energy_factor)-input.approach_loss;
    const double conveyance_product = static_cast<double>(input.entrance_conveyance)*input.upstream_conveyance;
    const double exit_ratio = velocity_area/input.exit_area;
    const double upstream_ratio = velocity_area/input.upstream_area;
    // NUM=(2g)*(Z1-Z3P).
    const double numerator = (static_cast<double>(input.upstream_elevation)-
        input.exit_piezometric_elevation)*input.gravity_twice;
    // DIV=1+CD^2*[(AVH/A3)^2-1-(ALP1-APPLOS)*(AVH/A1)^2
    //             +(2g)*AVH^2*(APPLEN/(K1*K2)+FRCFAC)].
    // FULBAR stores DIV to REAL at 0x4259ef; NUM remains in a wide spill.
    const double friction = (velocity_area*velocity_area)*input.gravity_twice*
        (static_cast<double>(input.approach_length)/conveyance_product+input.barrel_friction_factor);
    const float divisor = static_cast<float>((coefficient*coefficient)*
        ((exit_ratio*exit_ratio-1.0)-energy_factor*(upstream_ratio*upstream_ratio)+friction)+1.0);
    // Q=CD*AVH*REAL(sqrt(NUM/DIV)). The speed is stored at 0x425a02.
    const double effective_area = coefficient*velocity_area;
    float flow = static_cast<float>(effective_area*static_cast<float>(std::sqrt(numerator/divisor)));
    if (input.road_flow > 0.0F) {
        for (;;) {
            // NUM1=NUM+WFRD*[(ALP1-APPLOS)*(WFRD+Q+Q)/(2g*A1^2)
            //                -APPLEN*Q/(K1*K2)].
            const double road_numerator = numerator+static_cast<double>(input.road_flow)*
                (energy_factor*((static_cast<double>(input.road_flow)+flow)+flow)/
                    ((static_cast<double>(input.upstream_area)*input.upstream_area)*input.gravity_twice)-
                 (static_cast<double>(input.approach_length)*flow)/conveyance_product);
            // QT retains the product after a REAL square-root store (0x425a9f).
            const double candidate = effective_area*static_cast<float>(std::sqrt(road_numerator/divisor));
            // The released routine returns the previous stored Q when this
            // comparison converges. It stores QT only on the repeat branch.
            if (!(std::abs(candidate-flow)/flow > input.relative_tolerance)) { break; }
            flow = static_cast<float>(candidate);
        }
    }
    // CCON=1/[REAL(sqrt(1/CD^2-1))+1]; only the root is stored (0x425afe).
    const double contraction = 1.0/(static_cast<double>(
        static_cast<float>(std::sqrt(1.0/(coefficient*coefficient)-1.0)))+1.0);
    const double upstream_velocity = (static_cast<double>(input.road_flow)+flow)/input.upstream_area;
    const double entrance_velocity = static_cast<double>(flow)/(contraction*input.entrance_area);
    // ZAT2=ALP1*((Q+WFRD)/A1)^2/(2g)+Z1-(Q/(CCON*A2))^2/(2g).
    const float elevation = static_cast<float>(((upstream_velocity*upstream_velocity)*
        input.upstream_energy_factor/input.gravity_twice+input.upstream_elevation)-
        (entrance_velocity*entrance_velocity)/input.gravity_twice);
    return FullBarrelResult{flow,elevation};
}
}
