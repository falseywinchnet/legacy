// SPDX-License-Identifier: MIT
#include "calculation.hpp"
#include "tables.hpp"
#include "legacy/runup_math.hpp"
#include <cmath>
#include <stdexcept>

namespace legacy::runup::detail {
namespace {
float stored(double x) { return static_cast<float>(x); }
Integer integer(double x) { return static_cast<Integer>(x); }
double square(double x) { return x * x; }
Integer ordinate(Integer slope, Integer wave, Integer family) {
    if (slope < 1 || slope > 27 || wave < 1 || wave > 13 || family < 1 || family > 8)
        throw std::domain_error("RUNUP curve coordinate exceeds the original tables");
    return tables::DB.at((slope - 1) + 27 * (wave - 1) + 27 * 13 * (family - 1));
}
constexpr std::array<Integer, 12> scale_slopes{10,20,40,60,80,100,140,200,300,500,800,1500};
constexpr std::array<Integer, 12> scale_factors{1000,1049,1097,1119,1131,1136,1140,1136,1120,1089,1052,1000};
}

float Calculation::roughness() const {
    // RRUFF. CURVE passes its zero-initialized local N, so LI is found each time.
    Integer first = 1;
    while (first < NP && WTL >= DEP[first + 1]) ++first;
    const Integer limit = integer(static_cast<double>(R1) * 100.0 + WTL);
    Integer last = 1;
    while (last < NP && limit >= DEP[last + 1]) ++last;
    if (first >= NP || last >= NP)
        throw std::domain_error("RUNUP roughness interval exceeds the profile extension");
    float total_length = 0, weighted_length = 0;
    for (Integer k = first; k <= last; ++k) {
        const auto horizontal = DL[k + 1] - DL[k];
        // The executable squares the horizontal difference as INTEGER*4.
        const auto horizontal_squared = static_cast<Integer>(
            static_cast<std::uint32_t>(horizontal) * static_cast<std::uint32_t>(horizontal));
        float length = stored(std::pow(square((DEP[k + 1] - DEP[k]) / 100.0) + horizontal_squared, 0.5));
        if (k == first) {
            const double vertical = (static_cast<double>(DEP[k + 1]) - WTL) / 100.0;
            length = stored(std::pow(square((static_cast<double>(DEP[k + 1]) - WTL) * S[k] / 100.0) +
                                     square(vertical), 0.5));
        }
        if (k == last) {
            // Historical formula is relative to datum here, even for a partial segment.
            const double vertical = static_cast<double>(R1) - DEP[k] / 100.0;
            length = stored(std::pow(square(vertical * S[k]) + square(vertical), 0.5));
        }
        const float weighted = stored(static_cast<double>(length) * ROUGH[k]);
        total_length = stored(static_cast<double>(length) + total_length);
        weighted_length = stored(static_cast<double>(weighted) + weighted_length);
    }
    return stored(static_cast<double>(weighted_length) / total_length);
}

void Calculation::curve() {
    auto family = bracket(tables::PCH, DS);
    Integer lower = family.lower, upper = family.upper;
    if (lower == 5 || lower == 8) upper = lower;
    if (lower == 5 && SA >= 15.0f) { ++lower; ++upper; }
    if (lower == 1 && DS1 == 0) upper = lower;
    const bool extrapolate = !(DCS < 1000 || (DCS < 3000 && lower > 5));
    const auto slope = bracket(tables::PDB, DCS);
    // Original CURVE writes this flag through its own local IQ=0, outside the
    // result flag array. RUN's valid wave flag is therefore not changed here.
    const float xn = extrapolate ? stored(std::log10(DCS / 100.0)) : 0.0f;
    const auto at_wave = [&](Integer wave, Integer which_family) {
        if (!extrapolate) {
            return log_log(tables::PDB[slope.lower - 1], tables::PDB[slope.upper - 1],
                           ordinate(slope.lower, wave, which_family),
                           ordinate(slope.upper, wave, which_family), DCS);
        }
        const bool flat = lower > 5;
        const float high = stored(std::log10(static_cast<double>(stored(ordinate(flat ? 27 : 24, wave, which_family)))));
        const float low = stored(std::log10(static_cast<double>(stored(ordinate(flat ? 24 : 21, wave, which_family)))));
        return integer(std::pow(10.0, (static_cast<double>(high) - low) /
            (flat ? 0.477f : 0.222f) * (static_cast<double>(xn) - (flat ? 1.477f : 1.0f)) + high));
    };
    const auto at_family = [&](Integer which_family) {
        return log_log(tables::PDB1[KK - 1], tables::PDB1[LL - 1],
                       at_wave(KK, which_family), at_wave(LL, which_family), H0T2);
    };
    Integer ratio = at_family(lower);
    if (lower != upper)
        ratio = linear_integer(tables::PCH[lower - 1], tables::PCH[upper - 1],
                               ratio, at_family(upper), DS);
    R1 = stored(static_cast<double>(H0) * ratio / 100.0);
    curve_trace.push_back({DCS, DS, ratio, R1, RDSL, RDTR});
    const float rough = roughness();
    R1 = stored(static_cast<double>(R1) * rough);
    if (1.0 - rough > 0.01f) return;
    RS = 1000;
    if (DCS < 1500 && DCS > 10) {
        const auto scale = bracket(scale_slopes, DCS);
        RS = log_linear(scale_slopes[scale.lower - 1], scale_slopes[scale.upper - 1],
                        scale_factors[scale.lower - 1], scale_factors[scale.upper - 1], DCS);
    }
    R1 = stored(static_cast<double>(R1) * RS / 1000.0);
}

void Calculation::simple() {
    DS = integer(static_cast<double>(DS1 + 1) / H0 * 10.0 + 1000.0);
    DCS = integer((static_cast<double>(RDSL) - HST) * 10000.0 / (static_cast<double>(RDTR) + DS1));
    curve();
}

void Calculation::structure_with_sloping_approach() {
    DS = integer(static_cast<double>(DS1 + 1) / H0);
    DCS = DS1 == 0 && R == 0 ? integer(100.0 * MWST) :
        integer((static_cast<double>(RDSL) - HST) * 10000.0 / (static_cast<double>(RDTR) + DS1));
    curve();
}

void Calculation::composite() {
    const float steepness = stored(static_cast<double>(H0) / (static_cast<double>(T) * T * 5.12f));
    const float reflection = stored(0.195f / square(S[II]));
    if (steepness < reflection && S[II] < 10.0f) CS = 1;
    if (S[II] < 15.0f && BDLP == 1.0f) STS = 1;
    SA = S[II];
    DS = S[II] < 15.0f ? integer(static_cast<double>(DC) / H0) :
        integer(static_cast<double>(DC) / H0 * 10.0 + 1000.0);
    DCS = integer((static_cast<double>(RDSL) - DLE) * 10000.0 / (static_cast<double>(RDTR) + DC));
    curve();
}

void Calculation::blend_by_breaker_location() {
    if (DLE < static_cast<double>(HSA) - DXLA1) composite();
    if (static_cast<double>(HSA) - DXLA1 <= DLE && DLE <= static_cast<double>(HSA) + DXLA1) {
        // SIMPCOMP1's I3 is INTEGER*4 in the executable, unlike the printed listing.
        const Integer weight = integer((static_cast<double>(DLE) - HSA + DXLA1) / (0.2f * static_cast<double>(DXLA)));
        structure_with_sloping_approach();
        const float structure = R1;
        composite();
        RB = R1;
        R1 = stored(static_cast<double>(1 - weight) * RB + static_cast<double>(weight) * structure);
    }
    if (DLE > static_cast<double>(HSA) + DXLA1) structure_with_sloping_approach();
}

void Calculation::blend_by_toe_depth() {
    if (DS1 >= 3.0 * H0SCALE) { simple(); return; }
    if (DS1 > DC && DS1 < 3.0 * H0SCALE) {
        simple();
        RZ = R1;
        composite();
        RB = R1;
        const float weight = stored(static_cast<double>(DS1 - DC) / (3.0 * H0SCALE - DC));
        R1 = stored((1.0 - weight) * RB + static_cast<double>(weight) * RZ);
    } else composite();
}
} // namespace legacy::runup::detail
