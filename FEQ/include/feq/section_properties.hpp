// Section totals, conveyance, coefficients, and critical flows for FEQUTL.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#ifndef FEQ_SECTION_PROPERTIES_HPP
#define FEQ_SECTION_PROPERTIES_HPP
#include <feq/section_flux.hpp>
#include <array>
#include <cstddef>
#include <span>
#include <vector>

namespace feq {
enum class BetaMethod { old_coefficients, geometric_mean, momentum, energy };
struct SubsectionElements {
    SubsectionGeometry geometry;
    float roughness;
    float sinuosity;
    float discharge_integral;
    float conveyance_integral;
};
struct SectionPropertyOptions {
    int average_roughness;
    int sinuosity_mode;
    BetaMethod beta_method;
    bool usgs_coefficients;
    float manning_factor;
    float gravity;
    float slot_width;
    bool conveyance_warnings;
};
enum class SectionDiagnosticKind { negative_area, vertical_wall, conveyance_decrease, invalid_coefficients };
struct SectionDiagnostic {
    SectionDiagnosticKind kind;
    std::size_t subsection;
    float percentage;
};
struct SectionTotals {
    // The sixteen computed COMPEL values, in original XSV(2)..XSV(17) order.
    // XSV(1) and XSV(18)..XSV(22) belong to the caller and are not overwritten.
    std::array<float,16> values;
    std::vector<SectionDiagnostic> diagnostics;
    bool vertical_warning_remaining;
};

// Combine the geometry and flux passes using the released arithmetic. Previous
// conveyance/top-width banks are updated exactly as COMPEL updates KOLD/TSOLD.
// The initial sinuosity sums are supplied by the Gaussian pass for mode 1 and
// are normally zero for modes 0/2. Diagnostics are returned in original order
// so callers can preserve their own reporting and error-flag conventions.
SectionTotals section_properties(const SectionPropertyOptions& options,
    std::span<const SubsectionElements> subsections, const SectionFlux& flux,
    double area_sinuosity, double discharge_sinuosity,
    std::span<float> previous_conveyance, std::span<float> previous_width,
    bool vertical_warning);
}
#endif
