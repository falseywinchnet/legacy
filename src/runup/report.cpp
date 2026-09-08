// SPDX-License-Identifier: MIT
#include "legacy/runup.hpp"
#include <cmath>
#include <iomanip>
#include <locale>
#include <sstream>

namespace legacy::runup {
namespace {
std::string real(float x, int width, int decimals) {
    if (!std::isfinite(x)) return std::string(width, '*');
    std::ostringstream stream;
    stream.imbue(std::locale::classic());
    stream << std::fixed << std::setprecision(decimals) << x;
    auto value = stream.str();
    if (value.starts_with("0.")) value.erase(0, 1);
    else if (value.starts_with("-0.")) value.erase(1, 1);
    if (value.size() > static_cast<std::size_t>(width)) return std::string(width, '*');
    return std::string(width - value.size(), ' ') + value;
}
std::string integer(int x, int width) {
    const auto value = std::to_string(x);
    return value.size() > static_cast<std::size_t>(width) ? std::string(width, '*') :
        std::string(width - value.size(), ' ') + value;
}
void put(std::string& line, std::size_t column, const std::string& text) {
    if (line.size() < column + text.size()) line.resize(column + text.size(), ' ');
    line.replace(column, text.size(), text);
}
std::string padded(std::string value, std::size_t size) { value.resize(size, ' '); return value; }
void line(std::string& report, const std::string& value = "") { report += value; report += "\r\n"; }
void header(std::string& report, const Profile& p, int page) {
    std::string heading(236, '\0');
    put(heading, 0, "CLIENT- "); put(heading, 40, "** WAVE RUNUP-VERSION 2.0  ** ");
    put(heading, 78, "ENGINEERED BY "); put(heading, 104, "JOB ");
    put(heading, 118, "PROJECT-"); put(heading, 218, "RUN "); put(heading, 228, " PAGE ");
    put(heading, 8, padded(p.client, 26)); put(heading, 92, padded(p.engineer, 10));
    put(heading, 108, padded(p.job, 10)); put(heading, 126, padded(p.project, 74));
    put(heading, 222, padded(p.run, 4));
    line(report, "\f " + heading.substr(0, 118));
    auto second = " " + heading.substr(118);
    put(second, 118, integer(page, 2));
    line(report, second); line(report); line(report, std::string(120, '*'));
    line(report); line(report); line(report);
}
}

std::string legacy_report(const std::vector<ProfileResult>& profiles) {
    std::string report;
    int page = 0;
    for (const auto& result : profiles) {
        const auto& p = result.profile;
        header(report, p, ++page);
        line(report, "                      CROSS SECTION PROFILE"); line(report);
        line(report, "                    LENGTH   ELEV.    SLOPE     ROUGHNESS"); line(report);
        for (std::size_t n = 0; n < p.points.size(); ++n) {
            std::string point;
            put(point, 9, integer(static_cast<int>(n + 1), 2));
            put(point, 19, real(p.points[n].station, 7, 1));
            put(point, 29, real(result.displayed_elevations[n], 5, 1));
            line(report, point);
            std::string slope;
            if (n + 1 == p.points.size()) slope.resize(54, ' ');
            else {
                if (result.slopes[n] > 1000.0f) put(slope, 40, "FLAT");
                else put(slope, 37, real(result.slopes[n], 7, 2));
                put(slope, 50, real(p.points[n].roughness, 5, 2));
            }
            line(report, slope);
        }
        line(report, "                         LAST SLOPE" + real(p.last_slope, 7, 2) +
                     "     LAST ROUGHNESS" + real(p.points.back().roughness, 7, 2));
        header(report, p, ++page);
        line(report, "                                            OUTPUT TABLE");
        line(report, "                                            ------------");
        line(report); line(report); line(report);
        line(report, "                   INPUT PARAMETERS                                 RUNUP RESULTS");
        line(report, "                   ----------------                                 -------------"); line(report);
        line(report, "        WATER LEVEL    DEEP WATER                        BREAKING SLOPE    RUNUP SLOPE    RUNUP ABOVE        BREAKER");
        line(report, "        ABOVE DATUM    WAVE HEIGHT    WAVE PERIOD            NUMBER           NUMBER      WATER LEVEL        DEPTH");
        line(report, "           (FT.)          (FT.)          (SEC.)                                              (FT.)            (FT.)"); line(report);
        for (const auto& row : result.waves) {
            if (!row.error.empty()) { line(report, " " + row.error); continue; }
            line(report);
            std::string output;
            put(output, 9, real(row.wave.water_level, 6, 2));
            put(output, 24, real(row.wave.height, 6, 2));
            put(output, 39, real(row.wave.period, 6, 2));
            put(output, 63, integer(row.breaking_slope, 2));
            put(output, 80, integer(row.runup_slope, 2));
            put(output, 92, real(row.runup, 6, 2));
            put(output, 109, real(row.breaker_depth, 6, 2));
            line(report, output);
        }
    }
    return report;
}
} // namespace legacy::runup
