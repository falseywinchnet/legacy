// SPDX-License-Identifier: MIT
#include "legacy/runup.hpp"
#include <fstream>
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "RUNUP 2.0 — native C++\nUsage: runup INPUT.DAT OUTPUT.OUT\n";
        return argc == 2 && std::string(argv[1]) == "--help" ? 0 : 2;
    }
    try {
        std::ifstream input(argv[1]);
        if (!input) throw std::runtime_error("Cannot open input file: " + std::string(argv[1]));
        auto profiles = legacy::runup::read_input(input);
        if (profiles.empty()) throw std::runtime_error("The input file is empty");
        std::vector<legacy::runup::ProfileResult> results;
        bool failed = false;
        for (const auto& profile : profiles) {
            results.push_back(legacy::runup::calculate(profile));
            for (const auto& row : results.back().waves) if (!row.error.empty()) failed = true;
        }
        std::ofstream output(argv[2], std::ios::binary);
        if (!output) throw std::runtime_error("Cannot open output file: " + std::string(argv[2]));
        output << legacy::runup::legacy_report(results);
        if (!output) throw std::runtime_error("Could not write the complete output file");
        std::cout << "Wrote " << argv[2] << '\n';
        return failed ? 1 : 0;
    } catch (const std::exception& error) {
        std::cerr << "RUNUP: " << error.what() << '\n';
        return 1;
    }
}
