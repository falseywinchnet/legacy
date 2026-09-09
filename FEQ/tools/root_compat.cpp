// Research adapter for the independently verified root solver.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/root_solver.hpp>

namespace {
typedef double (*HistoricalResidual)(float*);
struct Callback {
    HistoricalResidual function;
    feq::RootBracket* bracket;
    float* left;
    float* right;
    float* fl;
    float* fr;
    float* trial;
    int* flag;
};
void write_state(const Callback& callback, bool write_trial) {
    *callback.left = callback.bracket->left;
    *callback.right = callback.bracket->right;
    *callback.fl = callback.bracket->left_residual;
    *callback.fr = callback.bracket->right_residual;
    if (write_trial) { *callback.trial = callback.bracket->trial; }
    *callback.flag = callback.bracket->flag;
}
double evaluate(void* pointer, float& argument) {
    const Callback& callback = *static_cast<Callback*>(pointer);
    // Retain argument addresses and global visibility during nested residuals.
    write_state(callback,true);
    const double result = callback.function(callback.trial);
    callback.bracket->left = *callback.left;
    callback.bracket->right = *callback.right;
    callback.bracket->left_residual = *callback.fl;
    callback.bracket->right_residual = *callback.fr;
    callback.bracket->flag = *callback.flag;
    argument = *callback.trial;
    return result;
}
struct DirectCallback { HistoricalResidual function; };
double evaluate_direct(void* pointer, float& argument) {
    const DirectCallback& callback = *static_cast<DirectCallback*>(pointer);
    return callback.function(&argument);
}
}
extern "C" void feq_root_variant(int method, float epsx, float epsf, HistoricalResidual function,
    float* left, float* right, float* fl, float* fr, float* trial, int* flag) {
    // FLAG is output-only; XM is written before its first evaluation. Avoid
    // reading either output when the calling routine has not initialized it.
    feq::RootBracket bracket{*left,*right,*fl,*fr,0.0F,0};
    Callback callback{function,&bracket,left,right,fl,fr,trial,flag};
    feq::solve_root(static_cast<feq::RootMethod>(method),epsx,epsf,evaluate,&callback,bracket);
    write_state(callback,bracket.flag != 1);
}
extern "C" void feq_root3(float epsx, float epsf, HistoricalResidual function,
    float* left, float* right, float* fl, float* fr, float* trial, int* flag) {
    feq_root_variant(static_cast<int>(feq::RootMethod::rgf3),epsx,epsf,function,
        left,right,fl,fr,trial,flag);
}
extern "C" void feq_regfal(float epsx, float epsf, HistoricalResidual function,
    float* left, float* right, float* trial, int* flag) {
    DirectCallback callback{function};
    feq::solve_regfal(epsx,epsf,evaluate_direct,&callback,*left,*right,*trial,*flag);
}
extern "C" void feq_fdroot(float epsf, HistoricalResidual function,
    float* left, float* right, int* flag) {
    DirectCallback callback{function};
    feq::find_sign_change(epsf,evaluate_direct,&callback,*left,*right,*flag);
}
