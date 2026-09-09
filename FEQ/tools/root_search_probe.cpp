// Direct original-executable fixtures for REGFAL and FDROOT.
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

extern "C" void feq_regfal(float,float,double(*)(float*),float*,float*,float*,int*);
extern "C" void feq_fdroot(float,double(*)(float*),float*,float*,int*);

namespace {
std::uint32_t read_word() {
    unsigned char bytes[4]{};
    std::cin.read(reinterpret_cast<char*>(bytes),4);
    if (!std::cin) { throw std::runtime_error("Incomplete root search fixture."); }
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
struct State { float left; float right; float trial; int flag; };
struct Trace { float argument; State state; std::uint32_t argument_class; };
struct Callback {
    std::uint32_t kind;
    std::uint32_t mutate;
    double coefficients[3];
    double sequence[128];
    float mutations[128];
    Trace trace[128];
    unsigned int calls;
    State* state;
    float* first_local;
};
double evaluate(void* pointer, float& argument) {
    Callback& callback = *static_cast<Callback*>(pointer);
    if (callback.calls >= 128) { throw std::runtime_error("Too many root search evaluations."); }
    const unsigned int index = callback.calls;
    State& state = *callback.state;
    std::uint32_t argument_class = 0;
    if (&argument == &state.left) { argument_class = 1; }
    else if (&argument == &state.right) { argument_class = 2; }
    else if (&argument == &state.trial) { argument_class = 3; }
    else {
        if (callback.first_local == nullptr) { callback.first_local = &argument; }
        argument_class = &argument == callback.first_local ? 4U : 5U;
    }
    callback.trace[index] = Trace{argument,state,argument_class};
    if ((callback.mutate & 1U) != 0) { argument = callback.mutations[index]; }
    if ((callback.mutate & 2U) != 0) {
        state.left = callback.mutations[index];
        state.right = std::bit_cast<float>(std::bit_cast<std::uint32_t>(callback.mutations[index]) ^ 0x80000000U);
        state.trial = callback.mutations[index];
        state.flag = static_cast<int>(index)+17;
    }
    ++callback.calls;
    if (callback.kind == 0) { return callback.sequence[index]; }
    return (callback.coefficients[2]*argument+callback.coefficients[1])*argument+callback.coefficients[0];
}
Callback* active_callback = nullptr;
double historical(float* argument) { return evaluate(active_callback,*argument); }
}
int main(int argc, char** argv) {
#if defined(_WIN32)
    _setmode(_fileno(stdin),_O_BINARY);
    _setmode(_fileno(stdout),_O_BINARY);
#endif
    try {
        bool adapter = false;
        bool fdroot = false;
        for (int i = 1; i < argc; ++i) {
            if (std::strcmp(argv[i],"--adapter") == 0) { adapter = true; }
            else if (std::strcmp(argv[i],"--regfal") == 0) { fdroot = false; }
            else if (std::strcmp(argv[i],"--fdroot") == 0) { fdroot = true; }
            else { throw std::runtime_error("Unknown root search probe option."); }
        }
        while (std::cin.peek() != std::char_traits<char>::eof()) {
            Callback callback{};
            callback.kind = read_word();
            callback.mutate = read_word();
            const float epsx = read_float();
            const float epsf = read_float();
            State state{};
            state.left = read_float();
            state.right = read_float();
            state.trial = read_float();
            state.flag = std::bit_cast<std::int32_t>(read_word());
            callback.state = &state;
            for (int i = 0; i < 3; ++i) { callback.coefficients[i] = read_double(); }
            for (int i = 0; i < 128; ++i) { callback.sequence[i] = read_double(); }
            for (int i = 0; i < 128; ++i) { callback.mutations[i] = read_float(); }
            if (adapter) {
                active_callback = &callback;
                if (fdroot) { feq_fdroot(epsf,historical,&state.left,&state.right,&state.flag); }
                else { feq_regfal(epsx,epsf,historical,&state.left,&state.right,&state.trial,&state.flag); }
            } else if (fdroot) {
                feq::find_sign_change(epsf,evaluate,&callback,state.left,state.right,state.flag);
            } else {
                feq::solve_regfal(epsx,epsf,evaluate,&callback,state.left,state.right,state.trial,state.flag);
            }
            write_float(state.left);
            write_float(state.right);
            write_float(state.trial);
            write_word(static_cast<std::uint32_t>(state.flag));
            write_word(callback.calls);
            for (int i = 0; i < 128; ++i) {
                const Trace& trace = callback.trace[i];
                write_float(trace.argument);
                write_float(trace.state.left);
                write_float(trace.state.right);
                write_float(trace.state.trial);
                write_word(static_cast<std::uint32_t>(trace.state.flag));
                write_word(trace.argument_class);
            }
        }
        return std::cout ? 0 : 1;
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
}
