// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/transition_energy.hpp>
#include <feq/power.hpp>
#include <cmath>

namespace feq {
double transition_loss_factor(float argument, float smoothing,
    float acceleration_coefficient, float deceleration_coefficient) {
    // FACDC 0x433d90..0x433e33. Outside [-s,s], losses follow the
    // acceleration/deceleration line. Inside, p=(x+s)/(2s) and
    // f=s*(Kd+p*((Kd+Ka)*p-2Kd)); no intermediate or return REAL store.
    if (smoothing == 0.0F) {
        if (argument <= 0.0F) {
            return -(static_cast<double>(argument)*deceleration_coefficient);
        }
        return static_cast<double>(argument)*acceleration_coefficient;
    }
    if (argument <= -smoothing) {
        return -(static_cast<double>(argument)*deceleration_coefficient);
    }
    if (argument >= smoothing) {
        return static_cast<double>(argument)*acceleration_coefficient;
    }
    const double width = static_cast<double>(smoothing)+smoothing;
    const double fraction = (static_cast<double>(argument)+smoothing)/width;
    const double coefficient_sum = static_cast<double>(deceleration_coefficient)+acceleration_coefficient;
    const double twice_deceleration = static_cast<double>(deceleration_coefficient)+deceleration_coefficient;
    return smoothing*(deceleration_coefficient+
        fraction*(coefficient_sum*fraction-twice_deceleration));
}

double transition_conveyance_mean(float left, float right, float exponent) {
    // GMEAN 0x433e40..0x433ed2. If |t|<REAL(.01), return X*Y wide.
    // Otherwise return REAL((Y*(.5*(X/Y)^t+.5)^(1/t))^2), preserving
    // both DOUBLE power calls and the final, branch-specific REAL store.
    if (std::abs(exponent) < 0.01F) {
        return static_cast<double>(right)*left;
    }
    const double ratio = static_cast<double>(left)/right;
    const double power = exponent;
    const double average = legacy_power(ratio,power)*0.5+0.5;
    const double reciprocal = 1.0/power;
    const double mean = legacy_power(average,reciprocal)*right;
    return static_cast<float>(mean*mean);
}

double transition_energy_check(const TransitionEnergyInput& input, float minimum_drop) {
    // ECECHK 0x433c70..0x433d86. F=Dx*Q^2/GMEAN and
    // L=Q*FACDC(Q*(sqrt(alphaR)/AR-sqrt(alphaL)/AL))*
    //   (sqrt(alphaR)/AR+sqrt(alphaL)/AL)/(2g).
    // Each SQRT crosses a REAL store; the quotients, F, L, downstream
    // total head and normalized residual never cross a REAL store.
    const double flow_squared = static_cast<double>(input.flow)*input.flow;
    const double friction = (flow_squared*input.distance)/
        transition_conveyance_mean(input.left_conveyance,input.right_conveyance,input.mean_exponent);
    const float root_right = static_cast<float>(std::sqrt(static_cast<double>(input.right_energy_factor)));
    const float root_left = static_cast<float>(std::sqrt(static_cast<double>(input.left_energy_factor)));
    const double right = static_cast<double>(root_right)/input.right_area;
    const double left = static_cast<double>(root_left)/input.left_area;
    const float argument = static_cast<float>((right-left)*input.flow);
    const double factor = transition_loss_factor(argument,input.smoothing,
        input.acceleration_coefficient,input.deceleration_coefficient);
    const double transition = ((factor*input.flow)*(right+left))/input.gravity_twice;
    const double right_total = (flow_squared*input.right_energy_factor)/
        ((static_cast<double>(input.right_area)*input.right_area)*input.gravity_twice)+input.right_piezometric_head;
    const double head_difference = static_cast<double>(input.left_total_head)-right_total;
    const double denominator = head_difference > minimum_drop ? head_difference : minimum_drop;
    return ((head_difference-transition)-friction)/denominator;
}

double transition_head_residual(const TransitionEnergyInput& input) {
    // FHPL 0x433fc1..0x434094 evaluates
    // [HTL-HPR-Q^2*(alphaR/(2g*AR^2)+Dx/GMEAN)-FACDC(X)*Y/(2g)]/HTL.
    // X=REAL(Q*(sqrt(alphaR)/AR-sqrt(alphaL)/AL)); Y uses the sum and
    // remains wide. Both roots store REAL before either quotient is formed.
    const float root_right = static_cast<float>(std::sqrt(static_cast<double>(input.right_energy_factor)));
    const float root_left = static_cast<float>(std::sqrt(static_cast<double>(input.left_energy_factor)));
    const double right = static_cast<double>(root_right)/input.right_area;
    const double left = static_cast<double>(root_left)/input.left_area;
    const float argument = static_cast<float>((right-left)*input.flow);
    const double sum = (right+left)*input.flow;
    const double head_difference = static_cast<double>(input.left_total_head)-input.right_piezometric_head;
    const double flow_squared = static_cast<double>(input.flow)*input.flow;
    const double right_velocity_factor = static_cast<double>(input.right_energy_factor)/
        ((static_cast<double>(input.right_area)*input.right_area)*input.gravity_twice);
    const double friction_factor = static_cast<double>(input.distance)/
        transition_conveyance_mean(input.left_conveyance,input.right_conveyance,input.mean_exponent);
    const double before_transition = head_difference-flow_squared*(right_velocity_factor+friction_factor);
    const double factor = transition_loss_factor(argument,input.smoothing,
        input.acceleration_coefficient,input.deceleration_coefficient);
    return (before_transition-(factor*sum)/input.gravity_twice)/input.left_total_head;
}

double transition_froude_residual(float flow, float critical_flow) {
    // FRLRES 0x433c45..0x433c57 returns without a REAL result store.
    return 1.0-static_cast<double>(flow)/critical_flow;
}

float transition_partial_free_flow(int index, int count, float power) {
    // PFQ(i)=REAL((i-1)/(N-1))**power; EXPCON 0x4368f9..0x436a07
    // multiplies by the retained reciprocal and calls the REAL power kernel.
    const double reciprocal = 1.0/(count-1);
    const float fraction = static_cast<float>((index-1)*reciprocal);
    return legacy_power(fraction,power);
}
}
