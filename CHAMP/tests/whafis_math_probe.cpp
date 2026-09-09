#include "../src/whafis/engine.hpp"
#include <array>
#include <fstream>
#include <memory>
#include <string>

int main(int argc, char **argv) {
    if (argc != 4)
        return 2;
    const std::string routine = argv[1];
    std::ifstream input(argv[2], std::ios::binary);
    std::ofstream output(argv[3], std::ios::binary);
    if (!input || !output)
        return 2;
    auto e = std::make_unique<legacy::whafis::detail::Engine>();
    std::array<float, 5> a{};
    while (input.read(reinterpret_cast<char *>(a.data()), sizeof(a))) {
        float result{};
        if (routine == "SHBM")
            result = e->shbm(a[0], a[1], a[2]);
        else if (routine == "HIN")
            result = e->hin(a[0], a[1], a[2], a[3], a[4]);
        else if (routine == "T")
            result = e->t(a[0], a[1], a[2], a[3]);
        else if (routine == "HM0")
            result = e->hm0(a[0], a[1], a[2]);
        else
            return 2;
        output.write(reinterpret_cast<const char *>(&result), sizeof(result));
    }
    return output ? 0 : 1;
}
