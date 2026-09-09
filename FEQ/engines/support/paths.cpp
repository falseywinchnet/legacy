// Native interpretation of the released Windows file-name conventions.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include "feq_path.hpp"
#include <cstring>
#include <cstdlib>
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
// Component comparisons prevent /model-other from being mistaken for /model.
// Input decks retain the Windows convention of ASCII-insensitive file names.
bool suffix_within(const std::filesystem::path& root, const std::filesystem::path& path,
                   std::filesystem::path& suffix) {
    std::filesystem::path::const_iterator child = path.begin();
    for (std::filesystem::path::const_iterator parent = root.begin(); parent != root.end(); ++parent) {
        if (child == path.end() || folded(parent->string()) != folded(child->string())) return false;
        ++child;
    }
    suffix.clear();
    for (; child != path.end(); ++child) suffix /= *child;
    return true;
}

std::filesystem::path confined_path(const std::filesystem::path& requested,
                                    const std::filesystem::path& sourceRoot,
                                    const std::filesystem::path& copyRoot) {
    const std::filesystem::path absolute = std::filesystem::absolute(requested).lexically_normal();
    std::filesystem::path suffix;
    if (suffix_within(sourceRoot, absolute, suffix)) return copyRoot/suffix;
    if (suffix_within(copyRoot, absolute, suffix)) return absolute;
    // Native aliases such as macOS /var -> /private/var can name the same
    // model root. Resolve them only after preserving literal in-model paths.
    const std::filesystem::path canonical = std::filesystem::weakly_canonical(absolute);
    if (suffix_within(sourceRoot, canonical, suffix)) return copyRoot/suffix;
    if (suffix_within(copyRoot, canonical, suffix)) return canonical;
    throw std::runtime_error("The model refers outside its copied folder: "+requested.generic_string()+
        ". Choose a model folder containing all referenced files.");
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
    std::filesystem::path requested(source);
    const char* sourceSetting = std::getenv("FEQ_RUN_SOURCE_ROOT");
    const char* copySetting = std::getenv("FEQ_RUN_COPY_ROOT");
    const bool confined = sourceSetting != nullptr || copySetting != nullptr;
    std::filesystem::path copyRoot;
    if (confined) {
        if (sourceSetting == nullptr || copySetting == nullptr || *sourceSetting == '\0' || *copySetting == '\0') {
            throw std::runtime_error("The desktop model-copy paths are incomplete.");
        }
        const std::filesystem::path sourceRoot = std::filesystem::weakly_canonical(sourceSetting);
        copyRoot = std::filesystem::weakly_canonical(copySetting);
        requested = confined_path(requested, sourceRoot, copyRoot);
    }
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
    if (confined) {
        std::filesystem::path suffix;
        if (!suffix_within(copyRoot, std::filesystem::weakly_canonical(resolved), suffix)) {
            throw std::runtime_error("A model file link escapes the copied run folder: "+source);
        }
    }
    const std::string result = resolved.generic_string();
    if (result.size() >= capacity) {
        throw std::length_error("File name exceeds the engine's storage capacity.");
    }
    std::memcpy(path, result.c_str(), result.size()+1);
}
