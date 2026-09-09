#ifndef FEQ_MD5_HPP
#define FEQ_MD5_HPP

#include <string>
#include <string_view>

namespace feq {

// Historical input fingerprints, expressed as 32 uppercase hexadecimal digits.
// Implements the mathematical algorithm in RFC 1321, sections 3.1-3.5.
std::string md5_hex(std::string_view message);

} // namespace feq
#endif
