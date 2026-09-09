#ifndef FEQ_STORAGE_HPP
#define FEQ_STORAGE_HPP

// Original project contribution. Work: Astra. Sponsor: Rainstar.
// Foundation: Hashem. MIT licensed; see FEQ/LICENSE.

#include <cstddef>
#include <bit>
#include <cstdint>
#include <cstring>
#include <limits>
#include <stdexcept>
#include <type_traits>

namespace feq {

// Copy bytes only within complete object representations. This supports an
// observed historical diagnostic copy whose width differs from its caller's
// scalar type, while rejecting the original program's memory overrun cases.
inline void copy_object_bytes(void* destination, std::size_t destination_bytes,
                              std::size_t destination_offset, const void* source,
                              std::size_t source_bytes, std::size_t source_offset,
                              std::size_t count) {
    if (destination_offset > destination_bytes || count > destination_bytes-destination_offset ||
        source_offset > source_bytes || count > source_bytes-source_offset) {
        throw std::out_of_range("Historical byte copy exceeds its COMMON storage.");
    }
    if (count == 0) {
        return;
    }
    if (destination == nullptr || source == nullptr) {
        throw std::invalid_argument("Historical byte copy has no storage.");
    }
    std::memmove(static_cast<unsigned char*>(destination)+destination_offset,
                 static_cast<const unsigned char*>(source)+source_offset, count);
}

namespace detail {

template <typename T>
T arithmetic(T left, T right, char operation) noexcept {
    if constexpr (std::is_integral<T>::value) {
        typedef typename std::make_unsigned<T>::type Unsigned;
        const std::uint64_t a = static_cast<Unsigned>(left);
        const std::uint64_t b = static_cast<Unsigned>(right);
        // Unsigned arithmetic defines the low N bits even at overflow.
        const std::uint64_t bits = operation == '+' ? a+b : operation == '-' ? a-b : a*b;
        const Unsigned result = static_cast<Unsigned>(bits);
        return std::bit_cast<T>(result);
    } else {
        return operation == '+' ? left+right : operation == '-' ? left-right : left*right;
    }
}

} // namespace detail

// FEQ's function-table bank has overlapping REAL*4, INTEGER*4, and REAL*8
// views. A word at index i has byte offset i*sizeof(T), with index zero valid.
// The Fortran EQUIVALENCE operation preserves the object bits; it does not
// numerically convert an integer to a real. memcpy implements that operation
// without violating C++ aliasing or object-lifetime rules.
// Source: SHARE/ftable.cmn and SHARE/fqshrftb.for in the 10.61 distribution.
template <typename T>
T load_bits(const void* address) noexcept {
    static_assert(std::is_trivially_copyable<T>::value,
                  "Bit storage requires a trivially copyable value.");
    T value;
    std::memcpy(&value, address, sizeof(T));
    return value;
}

template <typename T>
void store_bits(void* address, const T& value) noexcept {
    static_assert(std::is_trivially_copyable<T>::value,
                  "Bit storage requires a trivially copyable value.");
    std::memcpy(address, &value, sizeof(T));
}

// A legacy procedure may receive the address of one overlaid scalar. The
// temporary owns a correctly typed object, then writes its bits back after
// the call. Its lifetime is one full C++ expression. It never exposes a
// pointer of the wrong type into another object. This scalar adapter must
// not be used for an array argument; an array requires its declared extent.
template <typename T>
class ScalarLease final {
public:
    explicit ScalarLease(void* address) noexcept
        : address_(address), value_(load_bits<T>(address)) {}

    ~ScalarLease() noexcept {
        store_bits<T>(address_, value_);
    }

    ScalarLease(const ScalarLease&) = delete;
    ScalarLease& operator=(const ScalarLease&) = delete;

    T* data() noexcept { return &value_; }

private:
    void* address_;
    T value_;
};

template <typename T>
class BitReference final {
public:
    explicit BitReference(void* address) noexcept : address_(address) {}
    BitReference(const BitReference&) noexcept = default;

    operator T() const noexcept { return load_bits<T>(address_); }

    BitReference& operator=(const T& value) noexcept {
        store_bits<T>(address_, value);
        return *this;
    }

    BitReference& operator=(const BitReference& other) noexcept {
        // Assignment copies the represented value, never the proxy address.
        const T value = static_cast<T>(other);
        store_bits<T>(address_, value);
        return *this;
    }

    BitReference& operator+=(const T& value) noexcept {
        const T result = detail::arithmetic<T>(static_cast<T>(*this), value, '+');
        return operator=(result);
    }

    BitReference& operator-=(const T& value) noexcept {
        const T result = detail::arithmetic<T>(static_cast<T>(*this), value, '-');
        return operator=(result);
    }

    BitReference& operator*=(const T& value) noexcept {
        const T result = detail::arithmetic<T>(static_cast<T>(*this), value, '*');
        return operator=(result);
    }

    BitReference& operator/=(const T& value) {
        if constexpr (std::is_integral<T>::value) {
            if (value == 0) {
                throw std::domain_error("Integer division by zero in bit storage.");
            }
            if constexpr (std::is_signed<T>::value) {
                if (static_cast<T>(*this) == std::numeric_limits<T>::min() && value == T(-1)) {
                    throw std::overflow_error("Integer division overflow in bit storage.");
                }
            }
        }
        const T result = static_cast<T>(static_cast<T>(*this) / value);
        return operator=(result);
    }

    T operator++() noexcept {
        const T result = detail::arithmetic<T>(static_cast<T>(*this), T(1), '+');
        store_bits<T>(address_, result);
        return result;
    }

    T operator++(int) noexcept {
        const T previous = static_cast<T>(*this);
        operator++();
        return previous;
    }

    T operator--() noexcept {
        const T result = detail::arithmetic<T>(static_cast<T>(*this), T(1), '-');
        store_bits<T>(address_, result);
        return result;
    }

    T operator--(int) noexcept {
        const T previous = static_cast<T>(*this);
        operator--();
        return previous;
    }

    ScalarLease<T> lease() const noexcept { return ScalarLease<T>(address_); }

private:
    void* address_;
};

template <typename T>
class BitView final {
public:
    BitView(void* address, std::size_t bytes)
        : address_(static_cast<unsigned char*>(address)), count_(bytes / sizeof(T)) {
        if (bytes % sizeof(T) != 0) {
            throw std::invalid_argument("Bit view has a partial final element.");
        }
        if (address == nullptr && bytes != 0) {
            throw std::invalid_argument("Nonempty bit view has no storage.");
        }
    }

    BitReference<T> operator[](std::ptrdiff_t index) const {
        if (index < 0 || static_cast<std::size_t>(index) >= count_) {
            throw std::out_of_range("Legacy overlaid-storage index is out of bounds.");
        }
        return BitReference<T>(address_ + static_cast<std::size_t>(index) * sizeof(T));
    }

    BitReference<T> operator*() const { return operator[](0); }
    ScalarLease<T> lease(std::ptrdiff_t index) const { return operator[](index).lease(); }
    std::size_t size() const noexcept { return count_; }

private:
    unsigned char* address_;
    std::size_t count_;
};

// Preserve the Fortran index expression without constructing a pointer before
// its C++ array. For a declared lower bound L, element i is storage[i-L].
// For a column-major matrix A(L1:U1,L2:U2), f2c forms i+n1*j and subtracts
// L1+n1*L2; this adapter applies that subtraction to the integer index only.
// The storage pointer itself always denotes an actual array element.
template <typename T>
class IndexedPointer final {
public:
    IndexedPointer(T* storage, std::ptrdiff_t bias) noexcept
        : storage_(storage), bias_(bias) {}

    T& operator[](std::ptrdiff_t index) const {
        return *address(index);
    }

    T* operator+(std::ptrdiff_t index) const { return address(index); }
    T* operator-(std::ptrdiff_t index) const {
        if (index == std::numeric_limits<std::ptrdiff_t>::min()) {
            throw std::out_of_range("Legacy pointer-index subtraction overflow.");
        }
        return address(-index);
    }

    T& operator*() const { return operator[](0); }

private:
    T* address(std::ptrdiff_t index) const {
        if (storage_ == nullptr) {
            throw std::invalid_argument("Legacy argument has no array storage.");
        }
        if (index < bias_) {
            throw std::out_of_range("Legacy argument index precedes its lower bound.");
        }
        if (bias_ < 0 && index > std::numeric_limits<std::ptrdiff_t>::max() + bias_) {
            throw std::out_of_range("Legacy argument index subtraction overflow.");
        }
        return storage_ + (index - bias_);
    }

    T* storage_;
    std::ptrdiff_t bias_;
};

inline std::size_t checked_extent(std::int64_t first, std::int64_t second = 1) {
    if (first < 0 || second < 0) {
        throw std::invalid_argument("Negative automatic-array extent.");
    }
    const std::uint64_t a = static_cast<std::uint64_t>(first);
    const std::uint64_t b = static_cast<std::uint64_t>(second);
    const std::uint64_t limit = static_cast<std::uint64_t>(std::numeric_limits<std::size_t>::max());
    if (b != 0 && a > limit / b) {
        throw std::length_error("Automatic-array extent multiplication overflow.");
    }
    return static_cast<std::size_t>(a * b);
}

static_assert(sizeof(std::int32_t) == 4, "FEQ requires 32-bit integer words.");
static_assert(sizeof(float) == 4 && std::numeric_limits<float>::is_iec559,
              "FEQ requires IEEE-754 binary32 values.");
static_assert(sizeof(double) == 8 && std::numeric_limits<double>::is_iec559,
              "FEQ requires IEEE-754 binary64 values.");

} // namespace feq

#endif
