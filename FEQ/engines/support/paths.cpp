// Native interpretation of the released Windows file-name conventions.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include "feq_path.hpp"
#include <cstring>
#include <filesystem>
#include <stdexcept>
#include <string>
#include <system_error>

namespace {
std::string folded(const std::string& text) {
    std::string result(text);
    for (std::size_t index = 0; index < result.size(); ++index) {
        if (result[index] >= 'A' && result[index] <= 'Z') {
            result[index] = static_cast<char>(result[index]-'A'+'a');
        }
    }
    return result;
}
}

extern "C" void feq_compat_path(char* path, std::size_t capacity) {
    if (path == nullptr || capacity == 0) {
        throw std::invalid_argument("A file name requires valid storage.");
    }
    std::string source(path);
    for (std::size_t index = 0; index < source.size(); ++index) {
        if (source[index] == '\\') source[index] = '/';
    }
    const std::filesystem::path requested(source);
    std::filesystem::path resolved;
    // Windows input decks commonly mix upper/lowercase and backslashes. On
    // case-sensitive filesystems, preserve an exact existing spelling first;
    // otherwise accept exactly one ASCII case-insensitive sibling. Missing
    // components stay unchanged so OPEN/INQUIRE retain their normal errors.
    for (std::filesystem::path::const_iterator part = requested.begin(); part != requested.end(); ++part) {
        std::filesystem::path component(*part);
        std::error_code error;
        if (component != "." && component != ".." && !component.has_root_path() &&
            !std::filesystem::exists(resolved/component, error)) {
            const std::filesystem::path parent = resolved.empty() ? std::filesystem::path(".") : resolved;
            const std::string key = folded(component.string());
            std::filesystem::path match;
            std::filesystem::directory_iterator entry(parent, error);
            const std::filesystem::directory_iterator end;
            for (; !error && entry != end; entry.increment(error)) {
                if (folded(entry->path().filename().string()) == key) {
                    if (!match.empty()) {
                        throw std::runtime_error("Ambiguous letter case in file name: "+source);
                    }
                    match = entry->path().filename();
                }
            }
            if (!match.empty()) component = match;
        }
        resolved /= component;
    }
    const std::string result = resolved.generic_string();
    if (result.size() >= capacity) {
        throw std::length_error("File name exceeds the engine's storage capacity.");
    }
    std::memcpy(path, result.c_str(), result.size()+1);
}
