#include "engine.hpp"

namespace legacy::whafis::detail {
float Engine::hm0(float controlling_height, float depth, float period) {
    // Thompson–Vincent conversion from controlling height to zero-moment height.
    // The original uses two logarithmic branches and at most 25 Newton steps.
    // Binary32 storage is retained at the locations in 00409ffe..0040a6b9;
    // the remaining expressions correspond to the original x87 intermediates.
    if (controlling_height == 0)
        return 0;
    constexpr float gravity = 32.2f;
    constexpr float twice_pi = 6.283185482025146484375f;
    constexpr float rav_coefficient = 0.068646885454654693603515625f;
    constexpr float three_log_coefficient = 0.4248424470424652099609375f;
    const float water_depth = std::max(0.01f, depth);
    const float significant_height = static_cast<float>(double(controlling_height) / 1.6f);
    const float relative_depth =
        static_cast<float>(water_depth / (double(period) * gravity * period));
    const float deep_wavelength =
        static_cast<float>(std::max(double(0.1f), double(period) * period * 5.12f));
    const double wavelength =
        std::sqrt(std::tanh((double(water_depth) / deep_wavelength) * twice_pi)) * deep_wavelength;
    const float height_scale = static_cast<float>(wavelength * 0.008f);
    const float transition_height = static_cast<float>(double(height_scale) * 2);
    const float tolerance = static_cast<float>(1.25 / wavelength);
    const float target_epsilon = static_cast<float>(double(significant_height) / height_scale);
    const float period_factor =
        static_cast<float>(std::pow(double(period), double(1.7114f)) * rav_coefficient);
    float limiting_ratio = static_cast<float>(
        (period_factor / std::pow(double(water_depth), double(.8557f)) - 1) * .477f + 1.477f);
    limiting_ratio = std::clamp(limiting_ratio, 1.0f, 1.7f);
    const float depth_ratio = static_cast<float>(double(relative_depth) / 5.5722e-5f);
    const float transition_ratio =
        static_cast<float>(std::log10(double(depth_ratio)) * .42707f + .9f - three_log_coefficient);
    const float kappa_a =
        static_cast<float>(double(.2303028f) / std::pow(double(depth_ratio), double(.302608f)));
    const float kappa_c = static_cast<float>(double(.170474016f) /
                                             std::pow(double(depth_ratio), double(.420026987f)));

    const bool lower_limiting_branch = transition_ratio < limiting_ratio;
    const double limiting_zero_moment =
        (double(height_scale) / (lower_limiting_branch ? kappa_a : kappa_c)) *
        std::pow(10.0, -double(lower_limiting_branch ? .708568578f : .983508529f) * limiting_ratio);
    const double limiting_significant = double(limiting_ratio) * limiting_zero_moment;
    const double linear_zero_moment =
        (double(height_scale) / (transition_ratio < 1 ? kappa_a : kappa_c)) *
        (transition_ratio < 1 ? .195628183f : .10387032f);
    const double transition_significant = double(transition_height) * transition_ratio;
    if (significant_height >= linear_zero_moment)
        return significant_height;
    if (significant_height <= limiting_significant)
        return static_cast<float>(double(significant_height) / limiting_ratio);
    if (transition_significant == significant_height)
        return transition_height;

    double initial_height;
    float kappa, logarithm_coefficient, derivative_offset;
    if (transition_significant < significant_height) {
        const double anchor_height =
            lower_limiting_branch ? transition_height : limiting_zero_moment;
        const double anchor_significant =
            lower_limiting_branch ? transition_significant : limiting_significant;
        const double slope =
            (anchor_height - linear_zero_moment) / (anchor_significant - linear_zero_moment);
        initial_height = linear_zero_moment + slope * (significant_height - linear_zero_moment);
        kappa = kappa_c;
        logarithm_coefficient = 1.016768f;
        derivative_offset = .441576731f;
    } else {
        const double anchor_height = transition_ratio <= 1 ? linear_zero_moment : transition_height;
        const double anchor_significant =
            transition_ratio <= 1 ? linear_zero_moment : transition_significant;
        const double slope =
            (anchor_height - limiting_zero_moment) / (anchor_significant - limiting_significant);
        initial_height = limiting_zero_moment + slope * (significant_height - limiting_significant);
        kappa = kappa_a;
        logarithm_coefficient = 1.411296f;
        derivative_offset = .612918065f;
    }
    float epsilon = static_cast<float>(initial_height / height_scale);
    for (int iteration = 0; iteration < 25; ++iteration) {
        const double phi = -std::log10(double(kappa) * epsilon) * logarithm_coefficient;
        const double residual = double(epsilon) * phi - target_epsilon;
        const double delta = -residual / (phi - derivative_offset);
        epsilon = static_cast<float>(double(epsilon) + delta);
        if (std::abs(delta) < tolerance)
            break;
    }
    return static_cast<float>(double(epsilon) * height_scale);
}
} // namespace legacy::whafis::detail
