// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/weir_flow.hpp>
#include <cmath>
#include <stdexcept>
namespace feq {
float weir_downstream_head(float upstream_head, float free_drop, float fraction) {
    // 0x432734..0x43273c retains DROP; 0x432762..0x43276e subtracts
    // that wide product. Only 0x432795 stores the downstream head as REAL.
    const double drop = static_cast<double>(free_drop)*fraction;
    return static_cast<float>(upstream_head-drop);
}

WeirFlow submerged_weir_flow(const WeirFlowInput& input, WeirLookup lookup, void* tables) {
    if (lookup == nullptr || !std::isfinite(input.head) || !std::isfinite(input.tail_head) ||
        !std::isfinite(input.critical_head_ratio) || !std::isfinite(input.breadth) ||
        !std::isfinite(input.approach_depth) || !std::isfinite(input.total_head) ||
        !std::isfinite(input.free_flow) || !std::isfinite(input.gravity) || !std::isfinite(input.twice_gravity) ||
        input.approach_depth <= 0.0F || input.total_head <= 0.0F ||
        input.gravity <= 0.0F || input.twice_gravity <= 0.0F) {
        throw std::invalid_argument("Invalid submerged-weir input.");
    }
    WeirFlow result{};
    result.total_head = input.total_head;
    result.flow = input.free_flow;
    // The initial submergence coefficient can return the free-flow inputs
    // directly, or set Q=0 while retaining HTOT (embank.for:294-305).
    float ratio = static_cast<float>(static_cast<double>(input.tail_head)/input.total_head);
    float fraction = lookup(tables,2,ratio);
    if (fraction == 0.0F) { result.flow = 0.0F; return result; }
    if (fraction > 0.9999F && input.head > input.tail_head) { return result; }
    double previous = static_cast<double>(fraction)*input.free_flow;
    if (input.breadth == 0.0F) { result.status = WeirFlowStatus::zero_breadth; return result; }
    ratio = static_cast<float>(static_cast<double>(input.head)/input.breadth);
    const float coefficient = ratio > input.critical_head_ratio ?
        lookup(tables,0,ratio) : lookup(tables,1,input.total_head);
    // Original 0x42f83b forms 1/DEPTH once. Each iteration multiplies by this
    // retained reciprocal; direct division can select a different last bit.
    const double reciprocal_depth = 1.0/input.approach_depth;
    while (true) {
        // Htotal = H + (Qold/DEPTH)^2/(2*g). HEAD is retained wide across
        // LKTAB while the lookup ratio is stored REAL at 0x42f879.
        const double velocity = previous*reciprocal_depth;
        const double head = input.head+(velocity*velocity)/input.twice_gravity;
        ratio = static_cast<float>(static_cast<double>(input.tail_head)/head);
        fraction = lookup(tables,2,ratio);
        // Q = Cw * Htotal * REAL(sqrt(Htotal)) * submergence_fraction.
        // The square root stores REAL at 0x42f8b6; Q itself remains wide.
        const float root = static_cast<float>(std::sqrt(head));
        const double flow = ((static_cast<double>(coefficient)*head)*root)*fraction;
        if (std::abs(flow-previous)/((previous+flow)+static_cast<double>(0.001F)) <= static_cast<double>(0.0005F)) {
            result.flow = static_cast<float>(flow);
            result.total_head = static_cast<float>(head);
            break;
        }
        ++result.iterations;
        if (result.iterations > 100) {
            result.status = WeirFlowStatus::iteration_limit;
            result.iteration_head = static_cast<float>(head);
            result.iteration_flow = static_cast<float>(flow);
            result.previous_flow = static_cast<float>(previous);
            result.coefficient = coefficient;
            result.submergence_fraction = fraction;
            return result;
        }
        previous = flow;
    }
    // Qmax = DEPTH * REAL(sqrt(g*DEPTH)). The store at 0x42f9d9 precedes
    // multiplication, and the comparison uses the already stored REAL Q.
    const float critical_speed = static_cast<float>(std::sqrt(static_cast<double>(input.gravity)*input.approach_depth));
    const double maximum = static_cast<double>(input.approach_depth)*critical_speed;
    if (result.flow > maximum) { result.flow = static_cast<float>(maximum); }
    return result;
}
}
