// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#ifndef FEQ_ROOT_SOLVER_HPP
#define FEQ_ROOT_SOLVER_HPP
namespace feq {
struct RootBracket {
    float left;
    float right;
    float left_residual;
    float right_residual;
    float trial;
    int flag;
};
// The original REAL function returns its unrounded result in an x87 register.
// A callback may also adjust its argument through the Fortran reference.
typedef double (*RootResidual)(void* context, float& argument);
enum class RootMethod { regflt, rgf, rgf3, rgf5 };
// The four released routines differ in endpoint tests, convergence ordering,
// damping and failure outputs. RGF5 enforces EPSX >= REAL(1E-6).
void solve_root(RootMethod method, float argument_tolerance, float residual_tolerance,
    RootResidual residual, void* context, RootBracket& bracket);
// RGF3 modified regula falsi. Flag: 0 convergence, 1 no initial sign change,
// 2 more than 100 iterations, 3 callback failure (< -0.99E30F).
// Preserves the original order of convergence tests and every output update;
// the bracket and residual outputs on failure are part of that contract.
void solve_root3(float argument_tolerance, float residual_tolerance,
    RootResidual residual, void* context, RootBracket& bracket);
}
#endif
