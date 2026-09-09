// Research COMPEL adapter for verified section totals and critical flows.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/section_properties.hpp>
#include <cstddef>
#include <cstring>
#include <span>
#include <stdexcept>
#include <vector>

extern "C" int feq_section_properties(int subsections, int average, int mode,
    const char* beta_option, float factor, float gravity, float slot, int usgs,
    int no_warnings, int* vertical_warning, const float* width, const float* perimeter,
    const double* area, const double* moment, const float* roughness, const float* sinuosity,
    const float* discharge_integral, const float* conveyance_integral,
    double flow, double momentum, double energy, double dflow, double dmomentum,
    double denergy, double area_sinuosity, double discharge_sinuosity,
    float* previous_conveyance, float* previous_width, float* xsv,
    int* diagnostic_kind, int* diagnostic_subsection, float* diagnostic_percentage) {
    if (subsections < 1 || subsections > 200) {
        throw std::invalid_argument("COMPEL extent exceeds the released subsection bank.");
    }
    feq::BetaMethod beta = feq::BetaMethod::geometric_mean;
    if (std::memcmp(beta_option,"OLDBETA ",8) == 0) { beta = feq::BetaMethod::old_coefficients; }
    else if (std::memcmp(beta_option,"NEWBETAM",8) == 0 || std::memcmp(beta_option,"NEWBETAX",8) == 0) { beta = feq::BetaMethod::momentum; }
    else if (std::memcmp(beta_option,"NEWBETAE",8) == 0) { beta = feq::BetaMethod::energy; }
    const std::size_t count = static_cast<std::size_t>(subsections);
    std::vector<feq::SubsectionElements> elements(count);
    for (std::size_t index = 0; index < count; ++index) {
        elements[index] = feq::SubsectionElements{
            feq::SubsectionGeometry{width[index],perimeter[index],area[index],moment[index],0.0F,0.0F},
            roughness[index],sinuosity[index],discharge_integral[index],conveyance_integral[index]};
    }
    const feq::SectionPropertyOptions options{average,mode,beta,usgs == 1,factor,gravity,slot,no_warnings == 0};
    const feq::SectionFlux flux{flow,momentum,energy,dflow,dmomentum,denergy};
    const feq::SectionProperties result = feq::section_properties(options,elements,flux,area_sinuosity,discharge_sinuosity,
        std::span<float>(previous_conveyance,count),std::span<float>(previous_width,count),*vertical_warning == 1);
    for (std::size_t index = 0; index < result.values.size(); ++index) { xsv[index+1] = result.values[index]; }
    if (*vertical_warning == 1 && !result.vertical_warning_remaining) { *vertical_warning = 0; }
    if (result.diagnostics.size() > count*2+1) { throw std::logic_error("COMPEL diagnostic extent exceeded."); }
    for (std::size_t index = 0; index < result.diagnostics.size(); ++index) {
        const feq::SectionDiagnostic& event = result.diagnostics[index];
        diagnostic_kind[index] = event.kind == feq::SectionDiagnosticKind::negative_area ? 1 :
            event.kind == feq::SectionDiagnosticKind::vertical_wall ? 2 :
            event.kind == feq::SectionDiagnosticKind::conveyance_decrease ? 3 : 4;
        diagnostic_subsection[index] = static_cast<int>(event.subsection)+1;
        diagnostic_percentage[index] = event.percentage;
    }
    return static_cast<int>(result.diagnostics.size());
}
