// Native platform and character adapters. Work: Astra. Sponsor: Rainstar. Foundation: Hashem.
// MIT licensed. These functions do not replace any hydraulic calculation.
#include <feq/md5.hpp>
#include <feq/storage.hpp>

#include <algorithm>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <locale>
#include <stdexcept>
#include <string>
#include <string_view>

#include "f2c.h"
#undef min
#undef max
#undef abs

static_assert(sizeof(integer) == 4 && sizeof(real) == 4 && sizeof(doublereal) == 8);

namespace {

std::size_t character_length(ftnlen length) {
    if (length < 0) {
        throw std::out_of_range("Negative Fortran character length.");
    }
    return static_cast<std::size_t>(length);
}

void assign_character(char* output, ftnlen length, std::string_view input) {
    const std::size_t capacity = character_length(length);
    const std::size_t count = std::min(capacity, input.size());
    if (count != 0) {
        std::memmove(output, input.data(), count);
    }
    if (capacity > count) {
        std::memset(output+count, ' ', capacity-count);
    }
}

std::string native_path(std::string path) {
    for (std::size_t index = 0; index < path.size(); ++index) {
        if (path[index] == '\\') {
            path[index] = '/';
        }
    }
    return path;
}

int known_system_command(const std::string& command) {
    if (command == "cd > pwd.pwd") {
        std::ofstream output("pwd.pwd", std::ios::binary);
        output << std::filesystem::current_path().string() << '\n';
        if (!output) {
            throw std::runtime_error("Unable to record the current directory.");
        }
        return 0;
    }
    if (command == "del \\q temp.zxcv_ > NUL 2>&1") {
        std::filesystem::remove("temp.zxcv_");
        return 0;
    }
    throw std::runtime_error("Unimplemented historical platform command: "+command);
}

} // namespace

extern "C" {

int xargc = 0;
char** xargv = nullptr;
void f_init();
void f_exit();
int feq_gen_MAIN_d_();

integer feq_gen_feq_len_trim_d_(char* text, ftnlen length) {
    integer count = length;
    character_length(length);
    while (count > 0 && text[count-1] == ' ') {
        --count;
    }
    return count;
}

int feq_gen_feq_adjustl_d_(char* source, char* destination, ftnlen source_length, ftnlen destination_length) {
    const std::string snapshot(source, character_length(source_length));
    std::size_t first = 0;
    while (first < snapshot.size() && snapshot[first] == ' ') {
        ++first;
    }
    // ADJUSTL preserves LEN(source); leading blanks become trailing blanks.
    const std::string adjusted = snapshot.substr(first)+std::string(first, ' ');
    assign_character(destination, destination_length, adjusted);
    return 0;
}

int feq_gen_feq_adjustr_d_(char* source, char* destination, ftnlen source_length, ftnlen destination_length) {
    const std::string snapshot(source, character_length(source_length));
    std::size_t last = snapshot.size();
    while (last > 0 && snapshot[last-1] == ' ') {
        --last;
    }
    const std::string adjusted = std::string(snapshot.size()-last, ' ')+snapshot.substr(0, last);
    assign_character(destination, destination_length, adjusted);
    return 0;
}

doublereal feq_gen_feq_transfer_cd_d_(char* source, ftnlen length) {
    if (length != 8) {
        throw std::invalid_argument("Character-to-double TRANSFER requires eight bytes.");
    }
    return feq::load_bits<doublereal>(source);
}

void feq_gen_feq_transfer_dc_d_(char* destination, ftnlen length, doublereal* source) {
    if (length != 8) {
        throw std::invalid_argument("Double-to-character TRANSFER requires eight bytes.");
    }
    feq::store_bits<doublereal>(destination, *source);
}

integer feq_gen_feq_transfer_ri_d_(real* source) {
    return feq::load_bits<integer>(source);
}

int getcl_(char* destination, ftnlen length) {
    std::string command;
    for (int index = 1; index < xargc; ++index) {
        if (index != 1) {
            command += ' ';
        }
        const std::string argument(xargv[index]);
        if (argument.find(' ') != std::string::npos) {
            command += '"'+argument+'"';
        } else {
            command += argument;
        }
    }
    assign_character(destination, length, command);
    return 0;
}

int feq_gen_date_and_time_d_(char* date, char* time, char* zone, integer* values,
                             ftnlen date_length, ftnlen time_length, ftnlen zone_length) {
    const std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    const std::time_t seconds = std::chrono::system_clock::to_time_t(now);
    const std::tm* temporary = std::localtime(&seconds);
    if (temporary == nullptr) {
        throw std::runtime_error("Local clock conversion failed.");
    }
    const std::tm local = *temporary;
    const int milliseconds = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count()%1000);
    char formatted_date[32]{};
    char formatted_time[32]{};
    char formatted_zone[32]{};
    std::strftime(formatted_date, sizeof(formatted_date), "%Y%m%d", &local);
    std::strftime(formatted_zone, sizeof(formatted_zone), "%z", &local);
    std::snprintf(formatted_time, sizeof(formatted_time), "%02d%02d%02d.%03d",
                  local.tm_hour, local.tm_min, local.tm_sec, milliseconds);
    assign_character(date, date_length, formatted_date);
    assign_character(time, time_length, formatted_time);
    assign_character(zone, zone_length, formatted_zone);
    const int offset = std::atoi(formatted_zone);
    values[0] = local.tm_year+1900;
    values[1] = local.tm_mon+1;
    values[2] = local.tm_mday;
    values[3] = (offset/100)*60+offset%100;
    values[4] = local.tm_hour;
    values[5] = local.tm_min;
    values[6] = local.tm_sec;
    values[7] = milliseconds;
    return 0;
}

int system_(char* source, ftnlen length) {
    return known_system_command(std::string(source, character_length(length)));
}

int feq_gen_feq_system3_d_(char* first, char* second, char* third,
                          ftnlen first_length, ftnlen second_length, ftnlen third_length) {
    const std::string prefix(first, character_length(first_length));
    const std::string argument(second, character_length(second_length));
    const std::string suffix(third, character_length(third_length));
    if (prefix == "mkdir " && suffix == " > temp.zxcv_ 2>&1") {
        std::ofstream diagnostic("temp.zxcv_", std::ios::binary);
        std::error_code error;
        const bool created = std::filesystem::create_directories(native_path(argument), error);
        if (!created) {
            diagnostic << (error ? error.message() : "Directory already exists") << '\n';
        }
        if (!diagnostic) {
            throw std::runtime_error("Unable to record directory-creation result.");
        }
        return 0;
    }
    return known_system_command(prefix+argument+suffix);
}

int md5_(char* message, char* digest, ftnlen message_length, ftnlen digest_length) {
    const integer trimmed = feq_gen_feq_len_trim_d_(message, message_length);
    const std::string result = feq::md5_hex(std::string_view(message, static_cast<std::size_t>(trimmed)));
    assign_character(digest, digest_length, result);
    return 0;
}

} // extern "C"

int main(int argc, char** argv) {
    xargc = argc;
    xargv = argv;
    std::locale::global(std::locale::classic());
    f_init();
    std::atexit(f_exit);
    try {
        return feq_gen_MAIN_d_();
    } catch (const std::exception& error) {
        std::cerr << "FEQ engine stopped: " << error.what() << '\n';
        return 2;
    }
}
