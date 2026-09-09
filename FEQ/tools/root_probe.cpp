// Direct original-executable fixtures for REGFLT, RGF, RGF3 and RGF5.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/root_solver.hpp>
#include <bit>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <stdexcept>
#if defined(_WIN32)
#include <fcntl.h>
#include <io.h>
#include <cstdio>
#endif

extern "C" void feq_root3(float,float,double(*)(float*),float*,float*,float*,float*,float*,int*);
extern "C" void feq_root_variant(int,float,float,double(*)(float*),float*,float*,float*,float*,float*,int*);

namespace {
std::uint32_t read_word() {
    unsigned char bytes[4]{};
    std::cin.read(reinterpret_cast<char*>(bytes),4);
    if (!std::cin) { throw std::runtime_error("Incomplete root fixture."); }
    return static_cast<std::uint32_t>(bytes[0]) | (static_cast<std::uint32_t>(bytes[1]) << 8) |
        (static_cast<std::uint32_t>(bytes[2]) << 16) | (static_cast<std::uint32_t>(bytes[3]) << 24);
}
float read_float() { return std::bit_cast<float>(read_word()); }
double read_double() {
    const std::uint64_t low = read_word();
    const std::uint64_t high = read_word();
    return std::bit_cast<double>(low | (high << 32));
}
void write_word(std::uint32_t word) {
    const unsigned char bytes[4] = {static_cast<unsigned char>(word),static_cast<unsigned char>(word >> 8),
        static_cast<unsigned char>(word >> 16),static_cast<unsigned char>(word >> 24)};
    std::cout.write(reinterpret_cast<const char*>(bytes),4);
}
void write_float(float value) { write_word(std::bit_cast<std::uint32_t>(value)); }
struct Callback {
    std::uint32_t kind;
    std::uint32_t mutate;
    double coefficients[3];
    double sequence[101];
    float mutations[101];
    float trace[101];
    unsigned int calls;
};
double evaluate(void* pointer, float& argument) {
    Callback& callback = *static_cast<Callback*>(pointer);
    if (callback.calls >= 101) { throw std::runtime_error("Too many root evaluations."); }
    const unsigned int index = callback.calls;
    callback.trace[index] = argument;
    if (callback.mutate != 0) { argument = callback.mutations[index]; }
    ++callback.calls;
    if (callback.kind == 0) { return callback.sequence[index]; }
    return (callback.coefficients[2]*argument + callback.coefficients[1])*argument + callback.coefficients[0];
}
Callback* active_callback = nullptr;
float* expected_argument = nullptr;
double historical(float* argument) {
    if (argument != expected_argument) { throw std::runtime_error("Changed historical argument address."); }
    return evaluate(active_callback,*argument);
}
}
int main(int argc, char** argv) {
#if defined(_WIN32)
    _setmode(_fileno(stdin),_O_BINARY);
    _setmode(_fileno(stdout),_O_BINARY);
#endif
    try {
        bool adapter = false;
        feq::RootMethod method = feq::RootMethod::rgf3;
        for (int i = 1; i < argc; ++i) {
            if (std::strcmp(argv[i],"--adapter") == 0) { adapter = true; }
            else if (std::strcmp(argv[i],"--regflt") == 0) { method = feq::RootMethod::regflt; }
            else if (std::strcmp(argv[i],"--rgf") == 0) { method = feq::RootMethod::rgf; }
            else if (std::strcmp(argv[i],"--rgf3") == 0) { method = feq::RootMethod::rgf3; }
            else if (std::strcmp(argv[i],"--rgf5") == 0) { method = feq::RootMethod::rgf5; }
            else { throw std::runtime_error("Unknown root probe option."); }
        }
        while (std::cin.peek() != std::char_traits<char>::eof()) {
            Callback callback{};
            callback.kind = read_word();
            callback.mutate = read_word();
            const float epsx = read_float();
            const float epsf = read_float();
            feq::RootBracket bracket{};
            bracket.left = read_float();
            bracket.right = read_float();
            bracket.left_residual = read_float();
            bracket.right_residual = read_float();
            bracket.trial = read_float();
            for (int i = 0; i < 3; ++i) { callback.coefficients[i] = read_double(); }
            for (int i = 0; i < 101; ++i) { callback.sequence[i] = read_double(); }
            for (int i = 0; i < 101; ++i) { callback.mutations[i] = read_float(); }
            if (adapter) {
                active_callback = &callback;
                expected_argument = &bracket.trial;
                feq_root_variant(static_cast<int>(method),epsx,epsf,historical,&bracket.left,&bracket.right,
                    &bracket.left_residual,&bracket.right_residual,&bracket.trial,&bracket.flag);
            } else {
                feq::solve_root(method,epsx,epsf,evaluate,&callback,bracket);
            }
            write_float(bracket.left);
            write_float(bracket.right);
            write_float(bracket.left_residual);
            write_float(bracket.right_residual);
            write_float(bracket.trial);
            write_word(static_cast<std::uint32_t>(bracket.flag));
            write_word(callback.calls);
            for (int i = 0; i < 101; ++i) { write_float(callback.trace[i]); }
        }
        return std::cout ? 0 : 1;
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
}
