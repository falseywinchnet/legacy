// Record-boundary regression: narrow and unaligned scalar storage, character
// formats without NUL terminators, and logical values with zero low bytes.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/storage.hpp>
#include "../engines/support/format.hpp"
#include <array>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <string>
#define FEQ_RUNTIME_BUILD
#include "f2c.h"
#undef abs
#undef min
#undef max
extern "C" void f_init();

namespace {
void require(bool value, const std::string& message) {
    if (!value) throw std::runtime_error(message);
}

template<class Value>
void formatted(const std::string& text, const std::string& format,
               Value expected, const std::string& output) {
    alignas(16) std::array<char, sizeof(Value)+2> storage{};
    storage.fill('!');
    std::string input(text);
    char* value = storage.data()+1;
    // format.data() contains only the Fortran characters in this test; the
    // bounded adapter owns the terminating NUL required by the record parser.
    icilist record{1, input.data(), 1, feq::format_text(format.data(), format.size()),
                   static_cast<ftnlen>(input.size()), 1};
    integer count = 1;
    require(s_rsfi(&record) == 0, "Begin formatted input");
    require(do_fio(&count, value, sizeof(Value)) == 0, "Read formatted scalar");
    require(e_rsfi() == 0, "End formatted input");
    require(feq::load_bits<Value>(value) == expected, "Parsed scalar: "+format);
    require(storage.front() == '!' && storage.back() == '!', "Scalar store exceeds its width");
    std::string actual(output.size(), '?');
    record.iciunit = actual.data();
    record.icirlen = static_cast<ftnlen>(actual.size());
    require(s_wsfi(&record) == 0, "Begin formatted output");
    require(do_fio(&count, value, sizeof(Value)) == 0, "Write formatted scalar");
    require(e_wsfi() == 0, "End formatted output");
    require(actual == output, "Formatted scalar differs: "+format+": "+actual);
}

template<class Value>
void listed(const std::string& text, integer type, Value expected) {
    alignas(16) std::array<char, sizeof(Value)+2> storage{};
    storage.fill('!');
    std::string input(text);
    char* value = storage.data()+1;
    icilist record{1, input.data(), 1, nullptr, static_cast<ftnlen>(input.size()), 1};
    integer count = 1;
    require(s_rsli(&record) == 0, "Begin list input");
    require(do_lio(&type, &count, value, sizeof(Value)) == 0, "Read list scalar");
    require(e_rsli() == 0, "End list input");
    require(feq::load_bits<Value>(value) == expected, "Parsed list scalar");
    require(storage.front() == '!' && storage.back() == '!', "List store exceeds its width");
    // Round-trip through list output and input, exercising both byte accesses.
    std::string written(64, ' ');
    record.iciunit = written.data();
    record.icirlen = static_cast<ftnlen>(written.size());
    require(s_wsli(&record) == 0, "Begin list output");
    require(do_lio(&type, &count, value, sizeof(Value)) == 0, "Write list scalar");
    require(e_wsli() == 0, "End list output");
    std::memset(value, 0, sizeof(Value));
    require(s_rsli(&record) == 0, "Begin list round-trip");
    require(do_lio(&type, &count, value, sizeof(Value)) == 0, "Read list round-trip");
    require(e_rsli() == 0, "End list round-trip");
    require(feq::load_bits<Value>(value) == expected, "List round-trip differs");
}
}

int main() {
    f_init();
    try {
        formatted<signed char>(" -7", "(I3)", -7, " -7");
        formatted<short>(" -321", "(I5)", -321, " -321");
        formatted<int>("123456789", "(I9)", 123456789, "123456789");
        formatted<float>(" 1.250", "(F6.3)", 1.25F, " 1.250");
        formatted<double>(" 1234.50", "(F8.2)", 1234.5, " 1234.50");
        formatted<signed char>("   T", "(L4)", 1, "   T");
        formatted<short>("   T", "(L4)", 1, "   T");
        formatted<int>("   T", "(L4)", 1, "   T");
        listed<signed char>("-7", 11, -7);
        listed<short>("-321", 2, -321);
        listed<int>("123456789", 3, 123456789);
        listed<float>("1.25", 4, 1.25F);
        listed<double>("1234.5", 5, 1234.5);
        listed<signed char>("T", 12, 1);
        listed<short>("T", 13, 1);
        listed<int>("T", 8, 1);
        alignas(16) char logical_bytes[6]{};
        feq::store_bits<int>(logical_bytes+1, 65536);
        std::string output(4, '?');
        char logical_format[4] = {'(', 'L', '4', ')'};
        icilist record{1, output.data(), 1, feq::format_text(logical_format, 4), 4, 1};
        integer count = 1;
        require(s_wsfi(&record) == 0 && do_fio(&count, logical_bytes+1, 4) == 0 && e_wsfi() == 0,
                "Full-width logical output");
        require(output == "   T", "Logical output must inspect all four bytes");
        f_exit();
        std::cout << "Unaligned scalar I/O and bounded formats pass.\n";
    } catch (const std::exception& error) {
        f_exit();
        std::cerr << error.what() << '\n';
        return 1;
    }
    return 0;
}
