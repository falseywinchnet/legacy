#pragma once
#include <string>
#include <string_view>
#include <vector>

namespace legacy::whafis {
struct WavePoint {
    std::string kind;
    float station{};
    float height{};
    float period{};
    float crest_elevation{};
    float surge_elevation{};
};
struct TransectResult {
    std::string title;
    std::vector<WavePoint> points;
};
struct Options {
    std::string input_name = "INPUT.DAT";
    std::string output_name = "OUTPUT.OUT";
    std::string executed_on;
    std::string marsh_data;
};
struct Report {
    std::string text;
    std::vector<TransectResult> transects;
    std::string error;
};

// All calculation and report generation are native C++ and operate in memory.
// The original marsh defaults are included, so no MG.DAT installation is needed.
Report calculate(std::string_view input, const Options &options = {});
} // namespace legacy::whafis
