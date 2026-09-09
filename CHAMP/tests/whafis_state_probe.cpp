#include "../src/whafis/engine.hpp"
#include "../src/whafis/marsh_data.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <memory>

int main(int argc, char **argv) {
    if (argc != 2)
        return 2;
    std::ifstream input(argv[1], std::ios::binary);
    const std::string content{std::istreambuf_iterator<char>(input), {}};
    auto engine = std::make_unique<legacy::whafis::detail::Engine>();
    auto &e = *engine;
    e.io.load(5, content);
    e.io.load(7, legacy::whafis::detail::marsh_data);
    e.whafis4();
    std::cout << std::setprecision(12);
    for (int i = 1; i <= e.nfo; ++i)
        std::cout << e.gs(i) << ' ' << e.hbw(i) << ' ' << e.ew(i) << ' ' << e.sa(i, 4) << '\n';
}
