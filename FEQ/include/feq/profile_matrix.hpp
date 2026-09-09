#ifndef FEQ_PROFILE_MATRIX_HPP
#define FEQ_PROFILE_MATRIX_HPP

#include <cstddef>
#include <cstdint>
#include <stdexcept>

namespace feq {

template <typename T>
class IndexedView final {
public:
    IndexedView(T* storage, std::size_t count, std::int32_t lower = 1)
        : storage_(storage), count_(count), lower_(lower) {
        if (storage == nullptr && count != 0) {
            throw std::invalid_argument("Array view has no storage.");
        }
    }

    T& operator[](std::int32_t index) const {
        const std::int64_t offset = static_cast<std::int64_t>(index)-lower_;
        if (offset < 0 || static_cast<std::uint64_t>(offset) >= count_) {
            throw std::out_of_range("Profile-matrix index exceeds its declared array.");
        }
        return storage_[static_cast<std::size_t>(offset)];
    }

    std::size_t size() const noexcept { return count_; }

private:
    T* storage_;
    std::size_t count_;
    std::int32_t lower_;
};

class ProfileMatrixError final : public std::runtime_error {
public:
    enum Kind { invalid_block, zero_pivot };
    ProfileMatrixError(Kind reason, std::int32_t offset, std::int32_t row, std::int32_t column);
    const Kind kind;
    const std::int32_t offset;
    const std::int32_t row;
    const std::int32_t column;
};

// Storage follows FEQ's unsymmetric profile convention. C[j] is the diagonal
// offset; R[j] ends row j's strict lower triangle. C[0] is valid and equals 0.
// The lower triangle and upper-column profile alternate in one coefficient bank.
void factor_profile(std::int32_t block_count,
                    IndexedView<const std::int32_t> block_start,
                    IndexedView<const std::int32_t> block_end,
                    IndexedView<const std::int32_t> block_kind,
                    IndexedView<const std::int32_t> diagonal,
                    IndexedView<const std::int32_t> lower_end,
                    IndexedView<float> coefficients);

void solve_profile(std::int32_t equation_count,
                   IndexedView<const std::int32_t> diagonal,
                   IndexedView<const std::int32_t> lower_end,
                   IndexedView<const float> factors,
                   IndexedView<float> right_hand_side);

} // namespace feq
#endif
