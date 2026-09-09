// SPDX-License-Identifier: MIT
#pragma once
#include <iosfwd>
#include <string>
#include <vector>

namespace legacy::runup {
struct ProfilePoint {
    float elevation{}; // Feet above the input datum.
    float station{};   // Feet, increasing from sea to land.
    float roughness{1.0f};
};
struct Wave {
    float water_level{};
    float height{};
    float period{};
};
struct Profile {
    std::string client, engineer, job, project, run;
    float last_slope{}; // Cotangent of the landward extension slope.
    std::vector<ProfilePoint> points;
    std::vector<Wave> waves;
};
struct WaveResult {
    Wave wave;
    float runup{}, previous_runup{}, breaker_depth{};
    int breaking_slope{}, runup_slope{}, iterations{};
    bool converged{}, table_exceeded{}, may_reflect{}, toe_limited{};
    bool fatal_error{};
    int steepness_error{}; // -1 below the model range, +1 above it.
    std::string error;
};
struct ProfileResult {
    Profile profile;
    std::vector<float> slopes;
    std::vector<float> displayed_elevations;
    std::vector<WaveResult> waves;
};

// Reads the original fixed-column RUNUP 2.0 file format, including multiple profiles.
std::vector<Profile> read_input(std::istream& input);
ProfileResult calculate(const Profile& profile);
std::string legacy_report(const std::vector<ProfileResult>& profiles);
} // namespace legacy::runup
