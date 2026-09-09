#include "legacy/whafis.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <iterator>

int main(int argc, char **argv) {
    if (argc == 2 && std::string_view(argv[1]) == "--help") {
        std::cout << "WHAFIS 4G — native C++ coastal wave calculations\n"
                     "Usage: whafis INPUT.DAT OUTPUT.OUT\n"
                     "Marsh grass defaults are included. No emulator is required.\n";
        return 0;
    }
    if (argc != 3) {
        std::cerr << "Usage: whafis INPUT.DAT OUTPUT.OUT\n";
        return 2;
    }
    try {
        if (std::filesystem::absolute(argv[1]).lexically_normal() ==
            std::filesystem::absolute(argv[2]).lexically_normal())
            throw std::runtime_error("Input and output must be different files");
        std::ifstream source(argv[1], std::ios::binary);
        if (!source)
            throw std::runtime_error("Cannot read input file");
        const std::string input{std::istreambuf_iterator<char>(source), {}};
        legacy::whafis::Options options;
        options.input_name = argv[1];
        options.output_name = argv[2];
        const auto report = legacy::whafis::calculate(input, options);
        std::ofstream output(argv[2], std::ios::binary);
        if (!output)
            throw std::runtime_error("Cannot create output file");
        output << report.text;
        if (!output)
            throw std::runtime_error("Cannot write output file");
        if (!report.error.empty())
            throw std::runtime_error(report.error);
        return 0;
    } catch (const std::exception &error) {
        std::cerr << "whafis: " << error.what() << '\n';
        return 1;
    }
}
