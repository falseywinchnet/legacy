#pragma once
#include <cmath>

namespace legacy::whafis::detail {
struct WindCoefficients {
    float period_growth;
    float height_limit;
    float period_limit;
    float height_depth;
    float period_depth;
    float energy_input;
    float energy_limit;
    float shallow_period_factor;
};

inline WindCoefficients wind_coefficients(float miles_per_hour) {
    // These combined constants are the original compiler's binary32 folds of
    // the SPM constants, before the wind-dependent part is evaluated.
    constexpr float gravity = 32.2f;
    const double wind = std::pow(double(miles_per_hour), double(1.23f)) *
                        0.86386668682098388671875f;
    const float wind_squared = static_cast<float>(wind * wind);
    const float inverse_wind_scale = static_cast<float>(double(gravity) / wind_squared);
    WindCoefficients result;
    result.period_growth = static_cast<float>(wind * .023336283862590789794921875f /
                                             1036.840087890625f);
    result.height_limit = static_cast<float>(wind * .283f * wind / gravity);
    result.period_limit = static_cast<float>(wind * 7.54f / gravity);
    result.height_depth = static_cast<float>(std::pow(double(inverse_wind_scale), .75) * .53f);
    result.period_depth = static_cast<float>(std::pow(double(inverse_wind_scale), .375) * .833f);
    result.energy_input = static_cast<float>(double(wind_squared) * 2.556641220508027e-6f / gravity);
    result.energy_limit = static_cast<float>(double(.0010279046837240458f) / wind_squared);
    const double shallow_ratio = result.height_depth /
        (double(result.period_depth) * result.period_depth);
    result.shallow_period_factor = static_cast<float>(shallow_ratio * shallow_ratio);
    return result;
}
}
