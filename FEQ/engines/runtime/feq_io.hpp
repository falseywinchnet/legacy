// Typed transfers at the Fortran record boundary. The caller provides bytes
// for one scalar, not a union object; memcpy preserves both alignment and the
// C++ object-lifetime/aliasing rules. Arithmetic still uses the original types.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#ifndef FEQ_IO_BITS_HPP
#define FEQ_IO_BITS_HPP
#include <cstring>
#include <type_traits>
template<class Value> Value feq_io_load(const void* source) {
    static_assert(std::is_trivially_copyable_v<Value>);
    Value value{};
    std::memcpy(&value, source, sizeof(Value));
    return value;
}
template<class Value> void feq_io_store(void* destination, Value value) {
    static_assert(std::is_trivially_copyable_v<Value>);
    std::memcpy(destination, &value, sizeof(Value));
}
#endif
