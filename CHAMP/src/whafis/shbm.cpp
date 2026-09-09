#include "engine.hpp"

namespace legacy::whafis::detail {
float Engine::shbm(float period, float /*slope*/, float depth) {
    // Miche-type limiting wave height. FEMA restored the fixed 0.78 breaking
    // index in 1987; the supplied slope therefore has no effect in this model.
    // Constants and storage points match WHAFIS4.exe 00407dd3..00407e98.
    constexpr float twice_pi = 6.283185482025146484375f;
    constexpr float gravity_over_twice_pi = 5.12478923797607421875f;
    constexpr float one_seventh = 0.14285714924335479736328125f;
    const float water_depth = std::max(0.01f, depth);
    const float deep_wavelength = static_cast<float>(
        std::max(double(0.01f), double(period) * gravity_over_twice_pi * period));
    const double wavelength = std::max(
        double(0.1f),
        deep_wavelength * std::sqrt(std::tanh((double(water_depth) / deep_wavelength) * twice_pi)));
    const float height_scale = static_cast<float>(wavelength * one_seventh);
    return static_cast<float>(
        std::max(0.0, height_scale * std::tanh((double(water_depth) * 0.78f) / height_scale)));
}
} // namespace legacy::whafis::detail
