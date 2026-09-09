// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/root_solver.hpp>
#include <cmath>

namespace feq {
void solve_root3(float argument_tolerance, float residual_tolerance,
    RootResidual residual, void* context, RootBracket& bracket) {
    bracket.flag = 0;
    double left = bracket.left;
    double right = bracket.right;
    if (std::abs(bracket.left_residual) <= residual_tolerance) {
        bracket.trial = bracket.left;
        return;
    }
    if (std::abs(bracket.right_residual) <= residual_tolerance) {
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
        // Relative interval collapse precedes residual convergence. Ties
        // choose the right endpoint and copy FR into the reported FL.
        if (std::abs(left-right)/(std::abs(left)+std::abs(right)) < argument_tolerance) {
            bracket.left = static_cast<float>(left);
            bracket.right = static_cast<float>(right);
            if (std::abs(bracket.left_residual) < std::abs(bracket.right_residual)) {
                bracket.trial = static_cast<float>(left);
            } else {
                bracket.trial = static_cast<float>(right);
                bracket.left_residual = bracket.right_residual;
            }
            return;
        }
        if (std::abs(middle) < residual_tolerance) {
            bracket.left = static_cast<float>(left);
            bracket.right = static_cast<float>(right);
            bracket.left_residual = static_cast<float>(middle);
            return;
        }
        ++iterations;
        if (iterations > 100) {
            bracket.left = static_cast<float>(left);
            bracket.right = static_cast<float>(right);
            bracket.flag = 2;
            return;
        }
        // Retain the sign change. Repeated residuals of the same sign halve
        // the opposite endpoint residual (Illinois modified false position).
        // FR/FL are REAL stores at 0x4731a1/0x4731d1; the next comparison
        // still uses the unrounded callback result.
        if (bracket.left_residual*middle <= 0.0) {
            right = bracket.trial;
            bracket.right_residual = static_cast<float>(middle);
            if (previous*middle > 0.0) {
                bracket.left_residual = static_cast<float>(0.5*bracket.left_residual);
            }
        } else {
            left = bracket.trial;
            bracket.left_residual = static_cast<float>(middle);
            if (middle*previous > 0.0) {
                bracket.right_residual = static_cast<float>(0.5*bracket.right_residual);
            }
        }
        previous = middle;
    }
}
}
