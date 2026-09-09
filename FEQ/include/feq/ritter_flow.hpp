// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#ifndef FEQ_RITTER_FLOW_HPP
#define FEQ_RITTER_FLOW_HPP

namespace feq {
struct RitterWaveStep {
    float celerity;
    double escoffier;
};

// Advance the Escoffier stage variable through one RITTER table interval.
// Require finite inputs, positive gravity/area/width, and a positive sum of
// current and previous celerities. The accumulator remains wide between rows.
RitterWaveStep advance_ritter_wave(float depth, float previous_depth,
    float area, float width, float gravity, float previous_celerity,
    double previous_escoffier);

struct RitterSectionRow {
    float depth;
    float top_width;
    float area;
    float celerity;
    float escoffier;
};

struct RitterSectionProperties {
    float area;
    float top_width;
    float top_width_slope;
    float celerity;
    float escoffier;
};

// XLOOKW arithmetic after the original interval search. Require an increasing
// interval containing the finite nonnegative depth; positive gravity and, at
// positive depth, positive interpolated area, width and celerity denominator.
// At zero depth, celerity and the Escoffier variable are both zero.
RitterSectionProperties interpolate_ritter_section(float depth, float gravity,
    const RitterSectionRow& lower, const RitterSectionRow& upper);

// FRIT after its wave and constriction lookups. A nonpositive area is replaced
// with one, as in the original COMMON state. Require finite inputs and a
// nonzero initial_escoffier+initial_velocity. Return the wide residual.
double ritter_flow_residual(float initial_escoffier, float initial_velocity,
    float current_escoffier, float flow, float& area);
}
#endif
