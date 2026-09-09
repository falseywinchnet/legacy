// SPDX-License-Identifier: MIT
#pragma once

#include <cstdint>
#include <span>
#include <stdexcept>

namespace legacy::runup {

class WaveSteepnessError final : public std::domain_error {
public:
    explicit WaveSteepnessError(bool low)
        : std::domain_error(low ? "RUNUP H0/L0 is less than 0.002" : "RUNUP H0/L0 is greater than 0.07"), too_low(low) {}
    bool too_low;
};

struct Bracket {
    std::int32_t lower;  // One-based indices used by the original tables.
    std::int32_t upper;
    bool outside;
};

float breaking_depth(float deep_water_height, float period, float slope_cotangent);

Bracket bracket(std::span<const std::int32_t> table, std::int32_t value);
std::int32_t linear_integer(std::int32_t x1, std::int32_t x2,
                            std::int32_t y1, std::int32_t y2, std::int32_t x);
float linear_real(float x1, float x2, float y1, float y2, float x);
std::int32_t log_linear(std::int32_t x1, std::int32_t x2,
                        std::int32_t y1, std::int32_t y2, std::int32_t x);
std::int32_t log_log(std::int32_t x1, std::int32_t x2,
                     std::int32_t y1, std::int32_t y2, std::int32_t x);

}  // namespace legacy::runup
