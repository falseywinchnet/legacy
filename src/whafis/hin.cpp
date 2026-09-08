#include "engine.hpp"

namespace legacy::whafis::detail {
float Engine::hin(float incident_height, float fetch_length, float wind_speed, float depth,
                  float transmitted_period) {
    // SPM 1984 fetch growth, with Thompson–Vincent significant-height conversion
    // and the model's Miche breaking limit. The Windows compiler inlines SHBM;
    // its observable binary32 intermediates are retained here (00407e9b..0040839e).
    constexpr float gravity = 32.2f;
    constexpr float twice_pi = 6.283185482025146484375f;
    constexpr float gravity_over_twice_pi = 5.12478923797607421875f;
    constexpr float wind_coefficient = 0.539335548877716064453125f;
    constexpr float height_coefficient = 0.008788819424808025360107421875f;
    constexpr float rav_coefficient = 0.068646885454654693603515625f;
    constexpr float two_log_coefficient = 0.118764765560626983642578125f;
    const float period = std::max(.01f, transmitted_period);
    const float water_depth = std::max(.01f, depth);
    const float adjusted_wind =
        static_cast<float>(std::pow(double(wind_speed), double(1.23f)) * wind_coefficient);
    const float incident_limit = shbm(period, 0, water_depth);
    const float incident_zero_moment =
        hm0(std::min(incident_height, incident_limit), water_depth, period);
    const float alpha =
        static_cast<float>(double(adjusted_wind) * height_coefficient * adjusted_wind);
    const float wind_squared = static_cast<float>(double(adjusted_wind) * adjusted_wind);
    const float beta = static_cast<float>(
        std::tanh(std::pow((double(depth) * gravity) / wind_squared, .75) * .53f));
    const float limiting_height = static_cast<float>(double(beta) * alpha);
    const double ratio = double(incident_zero_moment) / limiting_height;
    float zero_moment = incident_zero_moment;
    if (ratio < 1) {
        const double inverse_tanh = .5 * std::log((ratio + 1) / (1 - ratio));
        const double fetch_root = (double(beta) / .00565f) * inverse_tanh;
        const double equivalent_fetch = fetch_root * fetch_root * wind_squared / gravity;
        const double growth =
            (double(.00565f) / beta) *
            std::sqrt(((equivalent_fetch + fetch_length) * gravity) / wind_squared);
        zero_moment = static_cast<float>(std::tanh(growth) * limiting_height);
    }

    const float deep_wavelength =
        static_cast<float>(double(period) * gravity_over_twice_pi * period);
    const float wavelength_scale = std::max(.1f, deep_wavelength);
    const double wavelength = std::max(
        double(.01f), std::sqrt(std::tanh((double(water_depth) / wavelength_scale) * twice_pi)) *
                          wavelength_scale);
    const float epsilon =
        static_cast<float>(std::max(double(1.e-4f), zero_moment / (wavelength * 4 * .002f)));
    const float depth_term = static_cast<float>(
        std::log10((water_depth / (double(period) * period * gravity)) / 5.5722e-5f) * .42707f +
        .9f);
    float phi =
        static_cast<float>(epsilon <= 2 ? depth_term - std::log10(double(epsilon)) * 1.411296f
                                        : double(depth_term) - two_log_coefficient -
                                              std::log10(double(epsilon)) * 1.016768f);
    const float period_factor = static_cast<float>(
        std::pow(double(std::max(.1f, period)), double(1.7114f)) * rav_coefficient);
    const double limiting_ratio = std::clamp(
        (period_factor / std::pow(double(water_depth), double(.8557f)) - 1) * .477f + 1.477f, 1.0,
        double(1.7f));
    phi = std::max(phi, 1.0f);
    if (phi > limiting_ratio)
        phi = static_cast<float>(limiting_ratio);
    const float controlling_height = static_cast<float>(double(phi) * zero_moment * 1.6f);
    return std::min(controlling_height, shbm(period, 0, water_depth));
}
} // namespace legacy::whafis::detail
