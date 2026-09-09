// Connect the original-verified RHARCH perimeter to the research utility.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/arch_perimeter.hpp>
#include <vector>
#include <stdexcept>

extern "C" int feq_arch_perimeter(int count, const float* rises, const float* spans,
    const float* bottom_radii, const float* corner_radii, float conversion,
    float* rise, float* span, int* points, float* x, float* y, float* offset,
    int* span_warning, float* warning_values) {
    if (count < 2) { throw std::invalid_argument("An arch standard needs two rows."); }
    std::vector<feq::ArchStandardRow> standards(static_cast<std::size_t>(count));
    for (int index = 0; index < count; ++index) {
        standards[static_cast<std::size_t>(index)] =
            feq::ArchStandardRow{rises[index],spans[index],bottom_radii[index],corner_radii[index]};
    }
    const feq::ArchPerimeter result = feq::arch_perimeter(standards,conversion,*rise,*span);
    *rise = result.rise;
    *span = result.span;
    *span_warning = result.span_warning ? 1 : 0;
    warning_values[0] = result.requested_span;
    warning_values[1] = result.tabulated_span;
    if (result.error == feq::ArchInputError::rise_outside_table) { return 571; }
    if (result.error == feq::ArchInputError::span_outside_table) { return 572; }
    *points = 23;
    *offset = result.invert_offset;
    for (std::size_t index = 0; index < 23; ++index) {
        x[index] = result.x[index];
        y[index] = result.y[index];
    }
    return 0;
}
