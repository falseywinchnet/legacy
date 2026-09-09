// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#ifndef FEQ_FORMAT_TEXT_HPP
#define FEQ_FORMAT_TEXT_HPP
#include <cstddef>
#include <stdexcept>
#include <string>
namespace feq {
inline char* format_text(const char* source, std::ptrdiff_t length) {
    if (length < 0) throw std::invalid_argument("Negative Fortran format length.");
    // The I/O runtime retains this pointer through one statement. A subsequent
    // format assignment starts the next statement. Independent engine runs use
    // separate processes; each engine executes one active record at a time.
    thread_local std::string format;
    format.assign(source, static_cast<std::size_t>(length));
    return format.data();
}
}
#endif
