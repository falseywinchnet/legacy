// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#ifndef FEQ_GATE_RESIDUAL_HPP
#define FEQ_GATE_RESIDUAL_HPP

namespace feq {
// Section properties have already been looked up at the trial depth. The
// upstream surface is upstream_bottom + upstream_depth; section 3 is the jet
// and section 4 is the tailwater. All fields correspond to stored REAL values.
struct GateResidualInput {
    float upstream_depth;
    float upstream_bottom;
    float jet_bottom;
    float effective_area;
    float upstream_area;
    float upstream_energy_factor;
    float discharge_coefficient;
    float gate_width;
    float contraction_coefficient;
    float gate_area;
    float gravity;
    float gravity_twice;
    float tailwater_area;
    float tailwater_momentum_factor;
    float tailwater_first_moment;
    float jet_first_moment;
    float squared_flow;
    float jet_depth;
    float jet_depth_offset;
};

struct GateResidual {
    double value;
    float squared_flow;
};

// The section-3 residuals compute and store squared flow before evaluating
// momentum. Tailwater residuals use the supplied squared flow unchanged.
GateResidual gate_orifice_jet_residual(const GateResidualInput& input);
GateResidual gate_weir_jet_residual(const GateResidualInput& input);
GateResidual gate_orifice_tailwater_residual(const GateResidualInput& input);
GateResidual gate_weir_tailwater_residual(const GateResidualInput& input);

struct GateTailwaterLevels {
    double head;
    double drop;
};

// Retain the tailwater surface while subtracting the datum and upstream
// surface. This is significant when a small drop sits above a large datum.
GateTailwaterLevels gate_tailwater_levels(float upstream_depth, float upstream_bottom,
    float tailwater_depth, float tailwater_bottom, float datum);

struct GateSubmergedLevels {
    float depth;
    double head;
    double drop;
};

// Store the trial section-4 depth as REAL while retaining its head and drop.
GateSubmergedLevels gate_submerged_levels(float upstream_depth, float upstream_bottom,
    double free_drop, float drop_fraction, float tailwater_bottom, float datum);

struct GateCriticalSetup {
    float area;
    float depth;
    float flow;
    float specific_energy;
    float initial_depth;
};

// Establish the free-weir upper limit when critical depth equals the opening.
// The stored energy and first depth estimate feed the inverse-energy solver.
GateCriticalSetup gate_critical_setup(float opening, float width, float gravity,
    float gravity_twice, float discharge_coefficient, float gate_bottom, float upstream_bottom);

struct GateFreeWeir {
    float depth;
    float flow;
};

// Original UFGATE fixed-point iteration. The input must describe a convergent
// free-weir state; the released routine has no iteration limit. The head and
// iterates remain wide until the converged gate depth is stored as REAL.
GateFreeWeir gate_free_weir(double head, float discharge_coefficient,
    float upstream_energy_factor, float width, float upstream_area, float gravity,
    float relative_tolerance);

// The upstream limit is stored only after subtracting the head datum from
// the retained water-surface elevation.
float gate_upstream_head(float depth, float upstream_bottom, float datum);

struct GateFreeOrifice {
    float effective_area;
    float flow;
};

// FNDFOQ arithmetic after the upstream section lookup. The contraction
// surface and velocity correction remain wide; area and speed have separate
// REAL stores in the released program.
GateFreeOrifice gate_free_orifice(float head, float datum, float discharge_coefficient,
    float contraction_coefficient, float gate_area, float opening, float gate_bottom,
    float upstream_area, float upstream_energy_factor, float gravity_twice);

// Squared flow when the rising tailwater reaches the gate lip. This limit
// uses a retained CD*AG product; it does not store an effective area first.
// At the transition midpoint, depth is the retained head and bottom is its
// datum; their sum is the same upstream surface used by the released block.
float gate_contact_squared_flow(float opening, float gate_area, float discharge_coefficient,
    double upstream_depth, float upstream_bottom, float gate_bottom, float upstream_area,
    float upstream_energy_factor, float gravity_twice);

struct GateOrificeState {
    float effective_area;
    float depth;
    float flow;
};

// UFGATE's free-orifice state stores the contracted depth before computing
// the available head. FNDFOQ's separate contraction-head calculation above
// keeps that product wide; these two released store sequences are distinct.
GateOrificeState gate_orifice_state(float opening, float gate_area, float discharge_coefficient,
    float contraction_coefficient, float upstream_depth, float upstream_bottom,
    float gate_bottom, float upstream_area, float upstream_energy_factor, float gravity_twice);
} // namespace feq
#endif
