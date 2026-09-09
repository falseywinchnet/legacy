// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
// Algorithm: FEQ 10.61 single/linsys.for, PROFAC and PROSLV.
// The released PE32 implementation defines the intermediate rounding points:
// PROFAC RVA 0x6a5d0; PROSLV RVA 0x6a9f0; startup control word 0x027f.
#include <feq/profile_matrix.hpp>

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <vector>

namespace feq {

static_assert(std::numeric_limits<float>::is_iec559 && std::numeric_limits<float>::digits == 24);
static_assert(std::numeric_limits<double>::is_iec559 && std::numeric_limits<double>::digits == 53);

namespace {

void validate_layout(IndexedView<const std::int32_t> diagonal,
                     IndexedView<const std::int32_t> lower_end, std::size_t coefficients) {
    const std::size_t safe_limit = static_cast<std::size_t>(std::numeric_limits<std::int32_t>::max()/8);
    // Bound every offset before combinations of profile indices are formed.
    // This keeps the original indexed formulas inside defined int32 arithmetic.
    if (coefficients == 0 || coefficients > safe_limit || lower_end.size() == 0 ||
        lower_end.size() > safe_limit || diagonal.size() != lower_end.size()+1) {
        throw std::invalid_argument("Inconsistent profile-matrix storage dimensions.");
    }
    for (std::int32_t index = 0; static_cast<std::size_t>(index) < diagonal.size(); ++index) {
        if (diagonal[index] < 0 || static_cast<std::size_t>(diagonal[index]) > coefficients) {
            throw std::out_of_range("Diagonal offset exceeds the profile-matrix bank.");
        }
    }
    for (std::int32_t index = 1; static_cast<std::size_t>(index) <= lower_end.size(); ++index) {
        if (lower_end[index] < 0 || static_cast<std::size_t>(lower_end[index]) > coefficients) {
            throw std::out_of_range("Lower-triangle offset exceeds the profile-matrix bank.");
        }
    }
}

} // namespace

ProfileMatrixError::ProfileMatrixError(Kind reason, std::int32_t at,
                                     std::int32_t row_number, std::int32_t column_number)
    : std::runtime_error(reason == invalid_block ? "Invalid FEQ matrix block type." : "Zero FEQ profile-matrix pivot."),
      kind(reason), offset(at), row(row_number), column(column_number) {}

void factor_profile(std::int32_t block_count,
                    IndexedView<const std::int32_t> block_start,
                    IndexedView<const std::int32_t> block_end,
                    IndexedView<const std::int32_t> block_kind,
                    IndexedView<const std::int32_t> diagonal,
                    IndexedView<const std::int32_t> lower_end,
                    IndexedView<float> coefficients) {
    validate_layout(diagonal,lower_end,coefficients.size());
    if (block_count < 0 || static_cast<std::size_t>(block_count) > block_start.size() ||
        static_cast<std::size_t>(block_count) > block_end.size() ||
        static_cast<std::size_t>(block_count) > block_kind.size()) {
        throw std::invalid_argument("Inconsistent profile-matrix block count.");
    }
    for (std::int32_t block = 1; block <= block_count; ++block) {
        const std::int32_t first = block_start[block];
        const std::int32_t last = block_end[block];
        const std::int32_t kind = block_kind[block];
        if (kind == 1) {
            if (first < 1 || static_cast<std::size_t>(last) > lower_end.size()) {
                throw std::out_of_range("Profile-matrix block row exceeds the declared equations.");
            }
            for (std::int32_t column = first; column <= last; ++column) {
                std::int32_t begin = diagonal[column-1]+1;
                std::int32_t end = lower_end[column];
                std::int32_t row = column-1-end+begin;
                for (std::int32_t entry = begin; entry <= end; ++entry) {
                    const std::int32_t left = entry-1;
                    const std::int32_t pivot = diagonal[row];
                    const std::int32_t upper = pivot-1;
                    const std::int32_t upper_limit = lower_end[row]+1;
                    const std::int32_t terms = std::min(left-begin, upper-upper_limit);
                    // Crout L[j,i] = (A[j,i] - sum_k L[j,k]U[k,i]) / U[i,i].
                    // Original 0x46a6d7..0x46a7dc retains SUM in x87; no REAL*4
                    // store occurs between additions or before the division.
                    double sum = 0.0;
                    for (std::int32_t term = 0; term <= terms; ++term) {
                        sum += static_cast<double>(coefficients[left-term])*coefficients[upper-term];
                    }
                    if (coefficients[pivot] == 0.0f) {
                        throw ProfileMatrixError(ProfileMatrixError::zero_pivot, pivot, row, column);
                    }
                    coefficients[entry] = static_cast<float>((static_cast<double>(coefficients[entry])-sum)/coefficients[pivot]);
                    ++row;
                }
                begin = end+1;
                end = diagonal[column];
                row = column-end+begin;
                for (std::int32_t entry = begin; entry <= end; ++entry) {
                    const std::int32_t left = lower_end[row];
                    const std::int32_t upper = entry-1;
                    const std::int32_t left_limit = diagonal[row-1]+1;
                    const std::int32_t terms = std::min(left-left_limit, upper-begin);
                    // U[i,j] = A[i,j] - sum_k L[i,k]U[k,j].
                    double sum = 0.0;
                    for (std::int32_t term = 0; term <= terms; ++term) {
                        sum += static_cast<double>(coefficients[left-term])*coefficients[upper-term];
                    }
                    coefficients[entry] = static_cast<float>(static_cast<double>(coefficients[entry])-sum);
                    ++row;
                }
            }
        } else if (kind == 2) {
            // The branch block has two four-entry rows per iteration. FST
            // writes a rounded float while retaining its unrounded register
            // value. FSTP writes and discards that register. The named doubles
            // below preserve the three FST -> arithmetic dependencies in the
            // original instructions at 0x46a958, 0x46a982, and 0x46a99e.
            const std::int32_t first_entry = lower_end[first];
            if (first_entry <= last && (first_entry < 4 ||
                static_cast<std::uint64_t>(last)+7 >= coefficients.size()+1)) {
                throw std::out_of_range("Branch-block stencil exceeds the profile-matrix bank.");
            }
            for (std::int32_t base = first_entry; base <= last; base += 8) {
                coefficients[base] = static_cast<float>(static_cast<double>(coefficients[base])/coefficients[base-1]);
                const double second = static_cast<double>(coefficients[base+2])-
                    static_cast<double>(coefficients[base+1])*coefficients[base-3];
                coefficients[base+2] = static_cast<float>(second);
                coefficients[base+3] = static_cast<float>(static_cast<double>(coefficients[base+3])-second*coefficients[base]);
                const double fourth = static_cast<double>(coefficients[base+4])/coefficients[base-1];
                coefficients[base+4] = static_cast<float>(fourth);
                const double fifth = (static_cast<double>(coefficients[base+5])-
                    fourth*coefficients[base+2])/coefficients[base+3];
                coefficients[base+5] = static_cast<float>(fifth);
                coefficients[base+7] = static_cast<float>(static_cast<double>(coefficients[base+7])-fifth*coefficients[base+6]);
            }
        } else {
            throw ProfileMatrixError(ProfileMatrixError::invalid_block, kind, 0, 0);
        }
    }
}

void solve_profile(std::int32_t equation_count,
                   IndexedView<const std::int32_t> diagonal,
                   IndexedView<const std::int32_t> lower_end,
                   IndexedView<const float> factors,
                   IndexedView<float> right_hand_side) {
    validate_layout(diagonal,lower_end,factors.size());
    if (equation_count <= 0 || static_cast<std::size_t>(equation_count) > lower_end.size() ||
        static_cast<std::size_t>(equation_count) > right_hand_side.size()) {
        throw std::invalid_argument("Profile solve requires at least one equation.");
    }
    std::vector<float> workspace(static_cast<std::size_t>(equation_count), 0.0f);
    IndexedView<float> work(workspace.data(), workspace.size());
    // Forward substitution: y[i] = b[i] - sum_j L[i,j]y[j], diag(L)=1.
    for (std::int32_t row = 2; row <= equation_count; ++row) {
        const std::int32_t begin = diagonal[row-1]+1;
        const std::int32_t end = lower_end[row];
        std::int32_t column = row-1-end+begin;
        double sum = right_hand_side[row];
        for (std::int32_t entry = begin; entry <= end; ++entry) {
            sum -= static_cast<double>(factors[entry])*right_hand_side[column];
            ++column;
        }
        right_hand_side[row] = static_cast<float>(sum);
    }
    // Back substitution: x[i] = (y[i] - sum_j U[i,j]x[j]) / U[i,i].
    right_hand_side[equation_count] = static_cast<float>(static_cast<double>(right_hand_side[equation_count])/factors[diagonal[equation_count]]);
    for (std::int32_t row = equation_count-1; row >= 1; --row) {
        const std::int32_t begin = diagonal[row+1]-1;
        const std::int32_t end = lower_end[row+1]+1;
        std::int32_t column = row;
        const double known = right_hand_side[row+1];
        for (std::int32_t entry = begin; entry >= end; --entry) {
            work[column] = static_cast<float>(static_cast<double>(work[column])+static_cast<double>(factors[entry])*known);
            --column;
        }
        right_hand_side[row] = static_cast<float>((static_cast<double>(right_hand_side[row])-work[row])/factors[diagonal[row]]);
    }
}

} // namespace feq
