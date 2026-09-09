// Original COMPEL mixed-precision aggregation in explicit portable C++.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/section_properties.hpp>
#include <feq/power.hpp>
#include <algorithm>
#include <cmath>
#include <stdexcept>

namespace feq {
SectionTotals section_properties(const SectionPropertyOptions& options,
    std::span<const SubsectionElements> subsections, const SectionFlux& flux,
    double area_sinuosity, double discharge_sinuosity,
    std::span<float> previous_conveyance, std::span<float> previous_width,
    bool vertical_warning) {
    const std::size_t count = subsections.size();
    if (count == 0 || previous_conveyance.size() != count || previous_width.size() != count ||
        (options.average_roughness != 0 && options.average_roughness != 1) ||
        options.sinuosity_mode < 0 || options.sinuosity_mode > 2 || !std::isfinite(options.manning_factor) ||
        !std::isfinite(options.gravity) || !std::isfinite(options.slot_width)) {
        throw std::invalid_argument("Invalid section property extent or option.");
    }
    SectionTotals result{};
    result.vertical_warning_remaining = vertical_warning;
    std::vector<float> conveyance(count,0.0F);
    double area = 0.0;
    double width = 0.0;
    double perimeter = 0.0;
    double first_moment = 0.0;
    double total_conveyance = 0.0;
    double alpha_sum = 0.0;
    double beta_sum = 0.0;
    double roughness_weight = 0.0;
    const double slot_limit = static_cast<double>(1.0001F)*options.slot_width;
    const double maximum_slot = options.gravity > 15.0F ? static_cast<double>(0.07F) : static_cast<double>(0.02134F);
    for (std::size_t index = 0; index < count; ++index) {
        const SubsectionElements& section = subsections[index];
        double section_area = section.geometry.area;
        const double section_width = section.geometry.top_width;
        const double section_perimeter = section.geometry.perimeter;
        width += section_width;
        perimeter += section_perimeter;
        if (options.average_roughness == 1) { roughness_weight += section_perimeter*section.roughness; }
        if (section_perimeter == 0.0) { continue; }
        // COMPEL accumulates ASUM and YBASUM with an explicit REAL store after
        // every double-precision subsection increment (VAs 0x497bf5/0x497c04).
        area = static_cast<float>(area+section_area);
        first_moment = static_cast<float>(first_moment+section.geometry.first_moment);
        if (options.average_roughness == 0) {
            if (section_area < 0.0) {
                result.diagnostics.push_back({SectionDiagnosticKind::negative_area,index,0.0F});
                section_area = std::abs(section_area);
            } else if (section_area == 0.0) {
                if (section_width == 0.0 && result.vertical_warning_remaining) {
                    result.diagnostics.push_back({SectionDiagnosticKind::vertical_wall,index,0.0F});
                    result.vertical_warning_remaining = false;
                }
                continue;
            }
            // Manning conveyance K = NFAC*A*(A/P)^0.666667/n. Radius and the
            // initial K are REAL; sinuosity adjustment then remains double.
            const float radius = static_cast<float>(section_area/section_perimeter);
            double section_conveyance = static_cast<float>(((options.manning_factor*section_area)*
                legacy_power(radius,0.666667F))/section.roughness);
            if (options.sinuosity_mode == 2) {
                const float root = static_cast<float>(std::sqrt(static_cast<double>(section.sinuosity)));
                section_conveyance /= root;
                area_sinuosity += section_area*section.sinuosity;
                discharge_sinuosity += section_conveyance*section.sinuosity;
            } else if (options.sinuosity_mode == 1 && section.conveyance_integral != 0.0F) {
                section_conveyance = (section_conveyance*section.discharge_integral)/section.conveyance_integral;
            }
            if (section_conveyance < previous_conveyance[index] && section_width <= slot_limit && previous_width[index] <= slot_limit) {
                section_conveyance = previous_conveyance[index];
            }
            conveyance[index] = static_cast<float>(section_conveyance);
            total_conveyance += section_conveyance;
            double alpha = 1.0;
            double beta = 1.0;
            if (options.usgs_coefficients) {
                // USGS subsection relation: alpha = clamp(14.8*n+0.884,1,2),
                // beta = 1+0.3467*(alpha-1), with original REAL constants.
                alpha = std::clamp(static_cast<double>(14.8F)*section.roughness+static_cast<double>(0.884F),1.0,2.0);
                beta = 1.0+static_cast<double>(0.3467F)*(alpha-1.0);
            }
            const float temporary = static_cast<float>((section_conveyance*section_conveyance)/section_area);
            beta_sum += beta*temporary;
            alpha_sum = static_cast<float>(alpha_sum+((alpha*section_conveyance)*temporary)/section_area);
        }
        previous_width[index] = section.geometry.top_width;
    }
    if (options.average_roughness == 1) {
        total_conveyance = perimeter > 0.0 ? ((options.manning_factor*area)*
            legacy_power(static_cast<float>(area/perimeter),0.666667F))*perimeter/roughness_weight : 0.0;
    }
    if (total_conveyance > 0.0) {
        const double temporary = area/(total_conveyance*total_conveyance);
        beta_sum *= temporary;
        alpha_sum = ((alpha_sum*temporary)*area)/total_conveyance;
    }
    beta_sum = std::max(1.0,beta_sum);
    alpha_sum = std::max(1.0,alpha_sum);
    for (std::size_t index = 0; index < count; ++index) {
        if (conveyance[index] < previous_conveyance[index] && options.conveyance_warnings) {
            const double drop = ((static_cast<double>(conveyance[index])-previous_conveyance[index])/previous_conveyance[index])*100.0;
            if (subsections[index].geometry.top_width > maximum_slot && std::abs(drop) > 1.0) {
                result.diagnostics.push_back({SectionDiagnosticKind::conveyance_decrease,index,static_cast<float>(std::abs(drop))});
            }
        }
        previous_conveyance[index] = conveyance[index];
    }
    std::array<float,16>& value = result.values;
    value[0] = static_cast<float>(width);
    value[1] = static_cast<float>(area);
    value[2] = static_cast<float>(first_moment);
    value[3] = static_cast<float>(std::sqrt(total_conveyance));
    value[14] = static_cast<float>(perimeter);
    value[15] = area > 0.0 ? static_cast<float>(((options.manning_factor*area)*
        legacy_power(static_cast<float>(area/perimeter),0.666667F))/total_conveyance) : 0.0F;
    if (options.beta_method == BetaMethod::old_coefficients) {
        value[4] = static_cast<float>(beta_sum);
        value[5] = static_cast<float>(alpha_sum);
        value[11] = width > 0.0 ? static_cast<float>(area*static_cast<float>(std::sqrt((options.gravity*area)/width))) : 0.0F;
    } else {
        if (flux.flow > 0.0) {
            const double flow2 = flux.flow*flux.flow;
            const double flow3 = flow2*flux.flow;
            const double flow4 = flow2*flow2;
            const double area2 = area*area;
            // beta = A*momentum/Q^2; alpha = A^2*energy/Q^3.
            // Differentiate using dA/dy=T and the analytical/Gaussian flux sums.
            value[4] = static_cast<float>((area*flux.momentum)/flow2);
            value[5] = static_cast<float>((area2*flux.energy)/flow3);
            value[6] = static_cast<float>((width*flux.momentum/flow2-
                ((2.0*area*flux.momentum)*flux.flow_derivative)/flow3)+(area*flux.momentum_derivative)/flow2);
            value[7] = static_cast<float>((((2.0*area)*width)*flux.energy)/flow3-
                ((3.0*area2*flux.energy)*flux.flow_derivative)/flow4+(area2*flux.energy_derivative)/flow3);
        } else {
            value[4] = 1.0F;
            value[5] = 1.0F;
        }
        if (area > 0.0) {
            // Momentum/energy critical flow: Qc=A*sqrt(g*A/denominator).
            // The sqrt result is rounded to REAL before multiplying by A.
            double denominator = static_cast<double>(value[4])*width-static_cast<double>(value[6])*area;
            value[8] = denominator <= 0.0 ? -9876541.0F : static_cast<float>(area*
                static_cast<float>(std::sqrt((options.gravity*area)/denominator)));
            denominator = static_cast<double>(value[5])*width-(0.5*value[7])*area;
            value[9] = denominator <= 0.0 ? -9876543.0F : static_cast<float>(area*
                static_cast<float>(std::sqrt((options.gravity*area)/denominator)));
            value[10] = width > 0.0 ? static_cast<float>(area*static_cast<float>(std::sqrt((options.gravity*area)/width))) : 0.0F;
            if (value[8] >= 0.0F && value[9] >= 0.0F) {
                if (options.beta_method == BetaMethod::momentum) { value[11] = value[8]; }
                else if (options.beta_method == BetaMethod::energy) { value[11] = value[9]; }
                else { value[11] = static_cast<float>(std::sqrt(static_cast<double>(value[8])*value[9])); }
            } else { value[11] = value[10]; }
        }
        if (value[4] < 1.0F || value[5] < 1.0F) {
            result.diagnostics.push_back({SectionDiagnosticKind::invalid_coefficients,0,0.0F});
        }
    }
    if (options.sinuosity_mode == 1) {
        value[12] = area == 0.0 ? 1.0F : static_cast<float>(area_sinuosity/area);
        value[13] = area == 0.0 ? 1.0F : static_cast<float>(discharge_sinuosity/flux.flow);
    } else if (options.sinuosity_mode == 2) {
        value[12] = area == 0.0 ? 1.0F : static_cast<float>(area_sinuosity/area);
        value[13] = area == 0.0 ? 1.0F : static_cast<float>(discharge_sinuosity/total_conveyance);
    } else {
        value[12] = 1.0F;
        value[13] = 1.0F;
    }
    return result;
}
}
