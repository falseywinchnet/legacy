// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
// FEQUTL 5.80 xsection.for:965-1025; original CUTTAB RVA 0x93530.
#include <feq/section_extension.hpp>

#include <cmath>
#include <stdexcept>

namespace feq {

std::size_t cut_section_slot(std::span<float> table, std::size_t row_stride,
                             std::size_t count, float gravity) {
    if (row_stride == 0 || row_stride > table.size()/13 || count > row_stride) {
        throw std::invalid_argument("Invalid closed-section table dimensions.");
    }
    const float maximum_width = gravity > 15.0F ? 0.07F : 0.02134F;
    const float maximum_depth = gravity > 15.0F ? 500.0F : 150.0F;
    float old_width = table[row_stride];
    for (std::size_t row = 1; row < count; ++row) {
        const float new_width = table[row+row_stride];
        // Old bridge tables may close to zero without a slot. Skipping such
        // a row preserves the last nonzero width for the next comparison.
        if (new_width == 0.0F) {
            continue;
        }
        // Detect |Tnew-Told|/Tnew <= REAL(0.001) and Tnew <= the unit-specific
        // slot width. The original subtraction and division retain precision.
        if (std::fabs(static_cast<double>(new_width)-old_width)/new_width <= 0.001F &&
            new_width <= maximum_width) {
            table[row] = maximum_depth;
            table[row+4*row_stride] = table[row-1+4*row_stride];
            table[row+5*row_stride] = table[row-1+5*row_stride];
            table[row+6*row_stride] = table[row-1+6*row_stride];
            table[row+12*row_stride] = table[row-1+12*row_stride];
            // Anew=Aold+(dy/2)*(Tnew+Told).
            // Jnew=Jold+(dy/2)*(Anew+Aold).
            // FST at 0x493652, 0x493735 and 0x493830 stores Anew as REAL
            // while retaining its wider register value for Jnew. DY is also
            // retained; neither float storage value can replace that register.
            const double half_depth = (static_cast<double>(maximum_depth)-table[row-1])*0.5;
            const float old_area = table[row-1+2*row_stride];
            const double area = old_area+half_depth*(static_cast<double>(new_width)+old_width);
            table[row+2*row_stride] = static_cast<float>(area);
            table[row+3*row_stride] = static_cast<float>(
                table[row-1+3*row_stride]+half_depth*(area+old_area));
            return row+1;
        }
        old_width = new_width;
    }
    return count;
}

} // namespace feq
