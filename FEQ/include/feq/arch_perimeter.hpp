// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#ifndef FEQ_ARCH_PERIMETER_HPP
#define FEQ_ARCH_PERIMETER_HPP
#include <array>
#include <span>
namespace feq {
struct ArchStandardRow {
    float rise;
    float span;
    float bottom_radius;
    float corner_radius;
};
enum class ArchInputError { none, rise_outside_table, span_outside_table };
struct ArchPerimeter {
    float rise;
    float span;
    float invert_offset;
    std::array<float,23> x;
    std::array<float,23> y;
    ArchInputError error;
    bool span_warning;
    float requested_span;
    float tabulated_span;
};
// RHARCH constructs the right half of a standard pipe arch and adjusts its
// polygonal area to the original analytic area. Table dimensions use inches;
// conversion is inches per working unit. A positive rise takes precedence.
// Out-of-table inputs retain the original converted dimensions and error kind.
ArchPerimeter arch_perimeter(std::span<const ArchStandardRow> standards,
    float conversion, float rise, float span);
}
#endif
