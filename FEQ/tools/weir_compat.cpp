// Preserve historical table selection and reporting around verified STOTHQ.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/weir_flow.hpp>
#include "common.hpp"

extern "C" int lktab_(integer*,real*,integer*,real*,integer*,real*);

namespace {
float lookup(void* context, int selector, float argument) {
    if (selector < 0 || selector > 2) { throw std::out_of_range("Invalid weir coefficient selector."); }
    integer address = static_cast<integer*>(context)[selector];
    integer skip_lower_bound = 0;
    integer table_number = 0;
    real value = 0.0F;
    real derivative = 0.0F;
    lktab_(&address,&argument,&skip_lower_bound,&value,&table_number,&derivative);
    return value;
}
}

extern "C" int feq_submerged_weir(int high_table, int low_table, int submergence_table,
    float critical_head_ratio, float breadth, float head, float tail_head, float depth,
    float gravity, float twice_gravity, float* total_head, float* flow,
    float* iteration_head, float* iteration_flow, float* previous_flow,
    float* coefficient, float* fraction) {
    integer tables[3] = {high_table,low_table,submergence_table};
    const feq::WeirFlowInput input{critical_head_ratio,breadth,head,tail_head,depth,
                                 *total_head,*flow,gravity,twice_gravity};
    const feq::WeirFlow result = feq::submerged_weir_flow(input,lookup,tables);
    if (result.status == feq::WeirFlowStatus::zero_breadth) { return 1; }
    if (result.status == feq::WeirFlowStatus::iteration_limit) {
        *iteration_head = result.iteration_head;
        *iteration_flow = result.iteration_flow;
        *previous_flow = result.previous_flow;
        *coefficient = result.coefficient;
        *fraction = result.submergence_fraction;
        return 2;
    }
    *total_head = result.total_head;
    *flow = result.flow;
    return 0;
}
