// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#ifndef FEQ_SECTION_EXTENSION_HPP
#define FEQ_SECTION_EXTENSION_HPP
#include <cstddef>
#include <span>

namespace feq {

// CUTTAB: detect an approximately constant, narrow top width and replace that
// row with the standard closed-section slot endpoint. Return the retained row
// count. The column-major table has thirteen columns, each with row_stride
// elements of storage; count is the number of initialized rows to examine.
// Values after the returned count remain untouched. Columns are depth, width,
// area, first moment, sqrt(conveyance), beta, alpha, five auxiliary fields, and Qc.
std::size_t cut_section_slot(std::span<float> table, std::size_t row_stride,
                             std::size_t count, float gravity);

} // namespace feq
#endif
