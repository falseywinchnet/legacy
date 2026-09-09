// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/root_solver.hpp>
#include <cmath>

namespace feq {
void solve_root(RootMethod method, float argument_tolerance, float residual_tolerance,
    RootResidual residual, void* context, RootBracket& bracket) {
    const bool collapse_first = method == RootMethod::rgf3 || method == RootMethod::rgf5;
    const double damping = collapse_first ? 0.5 : static_cast<double>(0.9F);
    if (method == RootMethod::rgf5 && argument_tolerance < 1.0E-6F) {
        argument_tolerance = 1.0E-6F;
    }
    bracket.flag = 0;
    double left = bracket.left;
    double right = bracket.right;
    if (method == RootMethod::rgf3 && std::abs(bracket.left_residual) <= residual_tolerance) {
        bracket.trial = bracket.left;
        return;
    }
    if (method == RootMethod::rgf3 && std::abs(bracket.right_residual) <= residual_tolerance) {
        bracket.trial = bracket.right;
        bracket.left_residual = bracket.right_residual;
        return;
    }
    double previous = bracket.left_residual;
    if (static_cast<double>(bracket.left_residual)*bracket.right_residual > 0.0) {
        bracket.flag = 1;
        return;
    }
    int iterations = 0;
    for (;;) {
        // XM = (FR*XL - FL*XR)/(FR - FL). Original 0x473045 stores
        // binary32 XM before the callback; FM and FMOLD remain binary64.
        bracket.trial = static_cast<float>((bracket.right_residual*left -
            bracket.left_residual*right)/(static_cast<double>(bracket.right_residual) -
            bracket.left_residual));
        const double middle = residual(context,bracket.trial);
        if (middle < -0.99E30F) {
            bracket.flag = 3;
            return;
        }
        if (middle == 0.0) {
            bracket.left = static_cast<float>(left);
            bracket.right = static_cast<float>(right);
            bracket.left_residual = static_cast<float>(middle);
            return;
        }
        // REGFLT/RGF test residual convergence first (0x4726df/0x47294f).
        // RGF3/RGF5 test interval collapse first (0x4730a9/0x47333f).
        if (!collapse_first && std::abs(middle) < residual_tolerance) {
            bracket.left = static_cast<float>(left);
            bracket.right = static_cast<float>(right);
            bracket.left_residual = static_cast<float>(middle);
            return;
        }
        const double relative_width = std::abs(left-right)/(std::abs(left)+std::abs(right));
        const bool collapsed = method == RootMethod::rgf5 ?
            relative_width <= argument_tolerance : relative_width < argument_tolerance;
        if (collapsed) {
            bracket.left = static_cast<float>(left);
            bracket.right = static_cast<float>(right);
            // RGF retains XM and returns FM; the other variants select the
            // endpoint with smaller |F|, with ties going to the right.
            if (method == RootMethod::rgf) {
                bracket.left_residual = static_cast<float>(middle);
            } else if (std::abs(bracket.left_residual) < std::abs(bracket.right_residual)) {
                bracket.trial = static_cast<float>(left);
            } else {
                bracket.trial = static_cast<float>(right);
                bracket.left_residual = bracket.right_residual;
            }
            return;
        }
        if (collapse_first && std::abs(middle) < residual_tolerance) {
            bracket.left = static_cast<float>(left);
            bracket.right = static_cast<float>(right);
            bracket.left_residual = static_cast<float>(middle);
            return;
        }
        ++iterations;
        if (iterations > 100) {
            bracket.left = static_cast<float>(left);
            bracket.right = static_cast<float>(right);
            if (method == RootMethod::rgf) {
                bracket.left_residual = static_cast<float>(middle);
            }
            bracket.flag = 2;
            return;
        }
        // Retain the sign change. Repeated residuals of the same sign damp
        // the opposite residual by 0.5 (RGF3/5) or REAL(0.9) (REGFLT/RGF).
        // FR/FL are REAL stores at 0x4731a1/0x4731d1; the next comparison
        // still uses the unrounded callback result.
        if (bracket.left_residual*middle <= 0.0) {
            right = bracket.trial;
            bracket.right_residual = static_cast<float>(middle);
            if (previous*middle > 0.0) {
                bracket.left_residual = static_cast<float>(damping*bracket.left_residual);
            }
        } else {
            left = bracket.trial;
            bracket.left_residual = static_cast<float>(middle);
            if (middle*previous > 0.0) {
                bracket.right_residual = static_cast<float>(damping*bracket.right_residual);
            }
        }
        previous = middle;
    }
}
void solve_root3(float argument_tolerance, float residual_tolerance,
    RootResidual residual, void* context, RootBracket& bracket) {
    solve_root(RootMethod::rgf3,argument_tolerance,residual_tolerance,residual,context,bracket);
}
void solve_regfal(float argument_tolerance, float residual_tolerance,
    RootResidual residual, void* context, float& left, float& right,
    float& trial, int& flag) {
    flag = 0;
    // Both REAL copies precede either callback (original 0x47231e..0x472331).
    // Changes to these local arguments do not immediately change A or B.
    float local_left = left;
    float local_right = right;
    double left_value = residual(context,local_left);
    double right_value = residual(context,local_right);
    if (std::abs(left_value) <= residual_tolerance) {
        trial = local_left;
        return;
    }
    if (std::abs(right_value) <= residual_tolerance) {
        trial = local_right;
        return;
    }
    double previous = left_value;
    if (left_value*right_value > 0.0) {
        flag = 1;
        return;
    }
    int iterations = 0;
    for (;;) {
        // XM = (FR*XL-FL*XR)/(FR-FL); only XM is stored as REAL.
        // FL, FR, FM and FMOLD retain the released x87 binary64 precision.
        trial = static_cast<float>((right_value*local_left-left_value*local_right)/
            (right_value-left_value));
        const double middle = residual(context,trial);
        const double relative_width =
            std::abs(static_cast<double>(local_left)-local_right)/
            (std::abs(static_cast<double>(local_left))+std::abs(static_cast<double>(local_right)));
        // Ordering is part of REGFAL's contract. A zero FM with EPSF=0
        // requires another trial before the endpoint-zero test can stop it.
        if (relative_width < argument_tolerance || std::abs(middle) < residual_tolerance ||
            left_value == 0.0 || right_value == 0.0) {
            left = local_left;
            right = local_right;
            return;
        }
        ++iterations;
        if (iterations > 100) {
            left = local_left;
            right = local_right;
            flag = 2;
            return;
        }
        // Retain the sign change; two consecutive residuals of the same
        // sign halve the opposite residual, without a binary32 store.
        if (left_value*middle <= 0.0) {
            local_right = trial;
            right_value = middle;
            if (previous*middle > 0.0) { left_value *= 0.5; }
        } else {
            local_left = trial;
            left_value = middle;
            if (middle*previous > 0.0) { right_value *= 0.5; }
        }
        previous = middle;
    }
}
void find_sign_change(float residual_tolerance, RootResidual residual,
    void* context, float& left, float& right, int& flag) {
    const double left_value = residual(context,left);
    const double right_value = residual(context,right);
    if (left_value*right_value <= 0.0 || std::abs(left_value) <= residual_tolerance ||
        std::abs(right_value) <= residual_tolerance) { return; }
    // The released unrolled loop caches A and B-A after both callbacks.
    // Subsequent callback changes to the external endpoints do not change
    // the remaining search positions (original 0x471eab..0x471eb5).
    const double initial_left = left;
    const double span = static_cast<double>(right)-left;
    float trial = 0.0F;
    for (int i = -8; i <= 15; ++i) {
        // XM = A + ((B-A)*i)/16, one REAL store before the positivity test.
        trial = static_cast<float>(initial_left+(span*static_cast<double>(i))*0.0625);
        if (trial <= 0.0F) { continue; }
        const double middle = residual(context,trial);
        if (middle*right_value <= 0.0) {
            left = trial;
            return;
        }
    }
    flag = 1;
}
}
