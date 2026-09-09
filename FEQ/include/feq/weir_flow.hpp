// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#ifndef FEQ_WEIR_FLOW_HPP
#define FEQ_WEIR_FLOW_HPP
namespace feq {
// EMBANK report head Hup-Fdrop*PFD. Keep the product wide until subtracting
// it from Hup; the separately displayed drop has its own REAL store.
float weir_downstream_head(float upstream_head, float free_drop, float fraction);

// Selectors 0/1/2 identify high-head, low-head and submergence tables.
typedef float (*WeirLookup)(void*, int, float);
struct WeirFlowInput {
    float critical_head_ratio;
    float breadth;
    float head;
    float tail_head;
    float approach_depth;
    float total_head;
    float free_flow;
    float gravity;
    float twice_gravity;
};
enum class WeirFlowStatus { complete, zero_breadth, iteration_limit };
struct WeirFlow {
    float total_head;
    float flow;
    int iterations;
    WeirFlowStatus status;
    // Diagnostic values for the original nonconvergence report; a failed
    // iteration leaves the caller's total head and free flow unchanged.
    float iteration_head;
    float iteration_flow;
    float previous_flow;
    float coefficient;
    float submergence_fraction;
};
// STOTHQ includes approach velocity head by fixed-point iteration, then caps
// the result at the original approach-section critical flow. Lookup returns
// the REAL coefficient for one of the three selected tables. The caller owns
// table selection, out-of-range reporting, and any lookup cursor state.
// Inputs and output arguments store binary32; internal head/flow values retain
// binary64 until the original machine-code store points.
WeirFlow submerged_weir_flow(const WeirFlowInput& input, WeirLookup lookup, void* tables);
}
#endif
