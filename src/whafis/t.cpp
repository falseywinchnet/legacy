#include "engine.hpp"

namespace legacy::whafis::detail {
float Engine::t(float incident_period, float fetch_length, float wind_speed, float depth) {
    // SPM 1984 wave-period growth. Wind speed is in feet per second; the
    // coefficient combines the historical speed conversion and drag correction.
    // Preserve the compiler's three binary32 intermediates (00409ac5..00409bc3).
    constexpr float gravity = 32.2f;
    constexpr float wind_coefficient = 0.539335548877716064453125f;
    constexpr float period_coefficient = 0.23416148126125335693359375f;
    constexpr float fetch_coefficient = 0.0379f;
    const double adjusted_wind = std::pow(double(wind_speed), double(1.23f)) * wind_coefficient;
    const float wind_squared = static_cast<float>(adjusted_wind * adjusted_wind);
    const float alpha = static_cast<float>(adjusted_wind * period_coefficient);
    const float beta = static_cast<float>(
        std::tanh(std::pow((double(depth) * gravity) / wind_squared, 0.375) * 0.833f));
    const float limiting_period = static_cast<float>(double(beta) * alpha);
    const double ratio = double(incident_period) / limiting_period;
    if (ratio >= 1)
        return incident_period;
    const double inverse_tanh = 0.5 * std::log((ratio + 1) / (1 - ratio));
    const double fetch_root = (double(beta) / fetch_coefficient) * inverse_tanh;
    const double equivalent_fetch = fetch_root * fetch_root * fetch_root * wind_squared / gravity;
    const double total_fetch = equivalent_fetch + fetch_length;
    const double growth = (double(fetch_coefficient) / beta) *
                          std::pow((total_fetch * gravity) / wind_squared, double(1.0f / 3.0f));
    return static_cast<float>(std::tanh(growth) * limiting_period);
}
} // namespace legacy::whafis::detail
