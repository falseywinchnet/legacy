// Model-copy isolation includes absolute paths and rejects lexical/link escapes.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include "../engines/runtime/feq_path.hpp"
#include <array>
#include <chrono>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
namespace {
void require(bool condition, const char* message) { if (!condition) throw std::runtime_error(message); }
void setting(const char* name, const std::string& value) {
#ifdef _WIN32
    require(_putenv_s(name, value.c_str()) == 0, "Cannot set path test environment");
#else
    require(setenv(name, value.c_str(), 1) == 0, "Cannot set path test environment");
#endif
}
std::filesystem::path translated(const std::filesystem::path& path) {
    const std::string input = path.generic_string();
    std::array<char, 4096> buffer{};
    require(input.size() < buffer.size(), "Test path too long");
    std::memcpy(buffer.data(), input.c_str(), input.size()+1);
    feq_compat_path(buffer.data(), buffer.size());
    return std::filesystem::path(buffer.data());
}
bool rejected(const std::filesystem::path& path) {
    try { translated(path); }
    catch (const std::runtime_error&) { return true; }
    return false;
}
}
int main() {
    const std::filesystem::path previous = std::filesystem::current_path();
    const std::filesystem::path root = std::filesystem::temp_directory_path()/
        ("feq-path-"+std::to_string(std::chrono::steady_clock::now().time_since_epoch().count()));
    try {
        const std::filesystem::path source = root/"source model";
        const std::filesystem::path copy = root/"copy model";
        std::filesystem::create_directories(source/"data");
        std::filesystem::create_directories(copy/"data");
        std::filesystem::create_directories(copy/"test");
        std::ofstream(source/"data/TABLE.TAB") << "original";
        std::ofstream(copy/"data/TABLE.TAB") << "copy";
        std::filesystem::current_path(copy/"test");
        require(std::filesystem::equivalent(translated("..\\data\\table.tab"), "../data/TABLE.TAB"), "Default Windows path convention changed");
        setting("FEQ_RUN_SOURCE_ROOT", source.string());
        setting("FEQ_RUN_COPY_ROOT", copy.string());
        require(std::filesystem::equivalent(translated(source/"data/table.tab"), copy/"data/TABLE.TAB"), "Absolute source input was not redirected");
        require(std::filesystem::equivalent(translated("..\\data\\table.tab"), copy/"data/TABLE.TAB"), "Relative copied input did not resolve");
        const std::filesystem::path output = translated(source/"new-output.out");
        std::ofstream(output) << "result";
        require(!std::filesystem::exists(source/"new-output.out") && std::filesystem::exists(copy/"new-output.out"), "Absolute output modified source");
        require(rejected("../../outside.out"), "Relative escape was accepted");
        require(rejected(root/"source model-other/new.out"), "Sibling-prefix escape was accepted");
        std::error_code error;
        std::filesystem::create_directory_symlink(source, copy/"escape-link", error);
        if (!error) require(rejected(std::filesystem::canonical(copy)/"escape-link/data/TABLE.TAB"), "Link escape was accepted");
        std::filesystem::current_path(previous);
        std::filesystem::remove_all(root);
        std::cout << "Native path compatibility and desktop copy isolation passed\n";
    } catch (const std::exception& error) {
        std::filesystem::current_path(previous);
        std::filesystem::remove_all(root);
        std::cerr << error.what() << '\n';
        return 1;
    }
    return 0;
}
