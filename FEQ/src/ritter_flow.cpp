// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/ritter_flow.hpp>
#include <cmath>

namespace feq {
RitterWaveStep advance_ritter_wave(float depth, float previous_depth,
    float area, float width, float gravity, float previous_celerity,
    double previous_escoffier) {
    // RITTER 0x471b7a..0x471bcd: C=REAL(sqrt(g*A/T)),
    // W=Wold+2*g*(Y-Yold)/(C+Cold). Only C rounds to REAL here.
    // W stays wide across reporting and subsequent table intervals; each
    // table/report value separately stores REAL from that retained register.
    RitterWaveStep result{};
    result.celerity = static_cast<float>(std::sqrt((static_cast<double>(gravity)*area)/width));
    const double depth_difference = static_cast<double>(depth)-previous_depth;
    const double gravity_twice = static_cast<double>(gravity)+gravity;
    const double celerity_sum = static_cast<double>(result.celerity)+previous_celerity;
    result.escoffier = previous_escoffier+(gravity_twice*depth_difference)/celerity_sum;
    return result;
}

RitterSectionProperties interpolate_ritter_section(float depth, float gravity,
    const RitterSectionRow& lower, const RitterSectionRow& upper) {
    // XLOOKW 0x4777a4..0x47785f: T=T0+(H/DY)*(T1-T0),
    // dT/dY=(T1-T0)/DY and A=A0+(H/2)*(T+T0). FST stores T and A as
    // REAL while retaining their wide registers for the celerity calculation.
    const double interval = static_cast<double>(upper.depth)-lower.depth;
    const double height = static_cast<double>(depth)-lower.depth;
    const double width_difference = static_cast<double>(upper.top_width)-lower.top_width;
    const double width = lower.top_width+(height/interval)*width_difference;
    const double area = lower.area+(height*0.5)*(width+lower.top_width);
    RitterSectionProperties result{};
    result.area = static_cast<float>(area);
    result.top_width = static_cast<float>(width);
    result.top_width_slope = static_cast<float>(width_difference/interval);
    if (depth == 0.0F) { return result; }
    // C=REAL(sqrt(g*A/T)); W=REAL(W0+2*g*H/(C+C0)).
    result.celerity = static_cast<float>(std::sqrt((gravity*area)/width));
    const double gravity_twice = static_cast<double>(gravity)+gravity;
    const double celerity_sum = static_cast<double>(result.celerity)+lower.celerity;
    result.escoffier = static_cast<float>(lower.escoffier+(gravity_twice*height)/celerity_sum);
    return result;
}

double ritter_flow_residual(float initial_escoffier, float initial_velocity,
    float current_escoffier, float flow, float& area) {
    // FRIT 0x4716ba..0x4716ff: [(W1+V1-W)-Q/A]/(W1+V1).
    // The original substitutes A=1 for A<=0. Neither the initial sum,
    // velocity, subtractions nor returned residual crosses a REAL store.
    if (area <= 0.0F) { area = 1.0F; }
    const double initial = static_cast<double>(initial_escoffier)+initial_velocity;
    return ((initial-current_escoffier)-static_cast<double>(flow)/area)/initial;
}
}
