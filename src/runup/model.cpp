// SPDX-License-Identifier: MIT
#include "legacy/runup.hpp"
#include "calculation.hpp"
#include <algorithm>
#include <cmath>
#include <istream>
#include <stdexcept>

namespace legacy::runup {
namespace {
std::string field(const std::string& line, std::size_t start, std::size_t length) {
    std::string value = start < line.size() ? line.substr(start, length) : "";
    value.resize(length, ' ');
    return value;
}
float number(std::string value, int decimals, std::size_t line_number) {
    value.erase(std::remove(value.begin(), value.end(), ' '), value.end());
    if (value.empty() || value == "." || value == "+." || value == "-.") return 0;
    for (auto& c : value) if (c == 'd' || c == 'D') c = 'E';
    // Fortran accepts an exponent sign without an E.
    for (std::size_t i = 1; i < value.size(); ++i)
        if ((value[i] == '+' || value[i] == '-') && value[i - 1] != 'e' && value[i - 1] != 'E') {
            value.insert(i, "E"); break;
        }
    try {
        std::size_t used{};
        double x = std::stod(value, &used);
        if (used != value.size() || !std::isfinite(x)) throw std::invalid_argument("number");
        if (value.find('.') == std::string::npos) x /= std::pow(10.0, decimals);
        return static_cast<float>(x);
    } catch (...) {
        throw std::runtime_error("Invalid RUNUP number on line " + std::to_string(line_number) + ": " + value);
    }
}
}

std::vector<Profile> read_input(std::istream& input) {
    std::vector<Profile> result;
    std::string line;
    std::size_t line_number = 0;
    const auto read = [&]() {
        if (!std::getline(input, line)) return false;
        ++line_number;
        if (!line.empty() && line.back() == '\r') line.pop_back();
        return true;
    };
    const auto required = [&]() {
        if (!read()) throw std::runtime_error("Incomplete RUNUP profile at line " + std::to_string(line_number));
    };
    const auto value = [&](std::size_t start, std::size_t count, int decimals) {
        return number(field(line, start, count), decimals, line_number);
    };
    while (read()) {
        Profile profile;
        profile.client = field(line, 2, 26);
        profile.engineer = field(line, 60, 10);
        profile.job = field(line, 70, 10);
        required();
        profile.project = field(line, 2, 74);
        profile.run = field(line, 76, 4);
        required();
        profile.last_slope = std::max(0.0f, value(0, 4, 1));
        bool ended = false;
        for (int n = 0; n < 20; ++n) {
            required();
            profile.points.push_back({value(2, 5, 1), value(8, 6, 1), value(15, 5, 3)});
            if (value(0, 1, 0) == 1) { ended = true; break; }
        }
        if (!ended) throw std::runtime_error("MORE THAN 20 POINTS IN PROFILE, PROGRAM STOPS");
        while (read()) {
            const bool new_profile = value(0, 1, 0) == 1;
            profile.waves.push_back({value(1, 5, 2), value(7, 5, 2), value(13, 5, 2)});
            if (profile.waves.back().height <= 0 || profile.waves.back().period <= 0) {
                result.push_back(std::move(profile));
                return result;
            }
            if (new_profile) break;
        }
        result.push_back(std::move(profile));
    }
    return result;
}

ProfileResult calculate(const Profile& profile) {
    if (profile.points.size() < 2 || profile.points.size() > 19)
        throw std::invalid_argument("RUNUP requires 2 to 19 supplied points plus its landward extension");
    ProfileResult result;
    result.profile = profile;
    detail::Calculation c;
    c.MAXPTS = static_cast<int>(profile.points.size());
    c.NP = c.MAXPTS + 1;
    for (int i = 1; i <= c.MAXPTS; ++i) {
        const auto& p = profile.points[i - 1];
        c.DEP[i] = static_cast<int>(std::round(static_cast<double>(p.elevation) * 100.0)) + 1;
        c.RDEPP[i] = static_cast<float>(static_cast<double>(p.elevation) * 100.0 + 1.0);
        c.VERT[i] = static_cast<float>(c.DEP[i]);
        c.HORIZ[i] = static_cast<float>(static_cast<double>(p.station) * 100.0);
        c.DL[i] = static_cast<int>(p.station); c.RDL[i] = p.station;
        c.ROUGH[i] = p.roughness;
        result.displayed_elevations.push_back(static_cast<float>(c.DEP[i] / 100.0));
    }
    c.S[c.MAXPTS] = profile.last_slope;
    for (int i = 1; i < c.MAXPTS; ++i) {
        float rise = static_cast<float>((c.DEP[i + 1] - c.DEP[i]) / 100.0);
        if (std::abs(rise) < 0.0001f) rise = 0.0001f;
        c.S[i] = static_cast<float>((static_cast<double>(c.RDL[i + 1]) - c.RDL[i]) / rise);
    }
    result.slopes.assign(c.S.begin() + 1, c.S.begin() + c.MAXPTS + 1);
    c.DEP[c.NP] = c.DEP[c.MAXPTS] + 10000;
    c.RDEPP[c.NP] = static_cast<float>(static_cast<double>(c.RDEPP[c.MAXPTS]) + 1000.0);
    c.RDL[c.NP] = static_cast<float>((static_cast<double>(c.RDEPP[c.NP]) - c.RDEPP[c.MAXPTS]) *
                                    c.S[c.MAXPTS] / 100.0 + c.RDL[c.MAXPTS]);
    c.DL[c.NP] = static_cast<int>(static_cast<double>(c.DEP[c.NP] - c.DEP[c.MAXPTS]) * c.S[c.MAXPTS] /
                                 100.0 + c.DL[c.MAXPTS]);
    float previous_water = 0;
    for (const auto& wave : profile.waves) {
        WaveResult row;
        row.wave = wave;
        if (wave.height <= 0 || wave.period <= 0) {
            row.error = "NEGATIVE RUN PARAMETER, PROGRAM STOPS";
            result.waves.push_back(row);
            break;
        }
        c.WTB = wave.water_level; c.H0 = wave.height; c.T = wave.period;
        const float water = static_cast<float>(static_cast<double>(wave.water_level) * 100.0);
        for (int i = 1; i <= c.NP; ++i) {
            c.DEP[i] = static_cast<int>(static_cast<double>(c.DEP[i]) - water + previous_water);
            c.RDEPP[i] = static_cast<float>(static_cast<double>(c.RDEPP[i]) - water + previous_water);
        }
        previous_water = water;
        c.WTL = 0; c.CS = 0; c.STS = 0;
        try {
            c.run();
            row.runup = c.result; row.previous_runup = c.R;
            row.breaker_depth = c.breaker_depth;
            row.breaking_slope = c.II; row.runup_slope = c.ending_slope;
            row.iterations = c.iterations; row.converged = c.converged;
            row.table_exceeded = c.table_exceeded; row.may_reflect = c.CS == 1;
            row.toe_limited = c.STS == 1;
        } catch (const std::exception& error) {
            row.error = error.what();
            row.fatal_error = row.error != "RUNUP wave steepness is outside 0.002 to 0.07";
        }
        result.waves.push_back(row);
        if (row.fatal_error) break;
    }
    return result;
}
} // namespace legacy::runup
