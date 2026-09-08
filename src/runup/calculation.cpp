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
}

bool Calculation::classify_structure() {
    wavelength_required = true;
    const float water = stored(static_cast<double>(WTB) * 100.0);
    Integer i = 1;
    while (i < MAXPTS && water > VERT[i + 1]) ++i;
    const Integer j = i + 1;
    const auto slope = [&](Integer landward, Integer seaward) {
        if (seaward < 1 || landward > 20) return 10000.0f;
        const double rise = static_cast<double>(VERT[landward]) - VERT[seaward];
        return rise > 0 ? stored((static_cast<double>(HORIZ[landward]) - HORIZ[seaward]) / rise) : 10000.0f;
    };
    const auto station = [&](Integer point) { return stored(HORIZ[point] / 100.0); };
    const auto depth = [&](Integer point) { return integer(static_cast<double>(water) - VERT[point]); };
    const auto length = [&](Integer from, Integer to) { return stored((static_cast<double>(HORIZ[to]) - HORIZ[from]) / 100.0); };
    const auto entire_approach = [&](Integer toe) {
        SA = slope(toe, 1);
        approach_length = length(1, toe);
        approach_depth = depth(1);
        HSA = station(1);
    };
    const bool at_vertex = static_cast<double>(water) + 1.0 == VERT[j];
    const float local_slope = at_vertex ? slope(j + 1, j) : slope(j, i);
    const float seaward_slope = at_vertex ? slope(j, i) : slope(i, i - 1);
    if (local_slope >= 1.5 * seaward_slope) return false;

    float x, y;
    if (at_vertex) {
        if (j >= MAXPTS) throw std::domain_error("RUNUP vertex classification needs a landward segment");
        // 0000:1651 reads the distinct, never-assigned local HOSCALE (=0).
        if (VERT[j + 1] > water) {
            y = water;
            x = linear_real(VERT[j], VERT[j + 1], HORIZ[j], HORIZ[j + 1], y);
        } else { y = VERT[j + 1]; x = HORIZ[j + 1]; }
        const float initial = stored((static_cast<double>(x) - HORIZ[j]) / (static_cast<double>(y) - VERT[j]));
        Integer l = 1;
        for (; l <= j; ++l) {
            const Integer p = j + 1 - l;
            MWA[p] = stored((static_cast<double>(x) - HORIZ[p]) / (static_cast<double>(y) - VERT[p]));
            if (MWA[p] > 1.2f * static_cast<double>(initial)) break;
        }
        Integer toe;
        if (l == 2) {
            MWST = initial; HST = station(j); DS1 = 0;
            MS1 = seaward_slope; MS1H = station(i); toe = j;
        } else if (l == j + 1) {
            MWST = MWA[1]; HST = HORIZ[1]; DS1 = depth(1);
            SA = 10000; approach_length = 1; approach_depth = DS1; HSA = HST;
            return true;
        } else {
            toe = j + 2 - l;
            MWST = MWA[toe]; HST = station(toe); DS1 = depth(toe);
            MS1 = slope(toe, toe - 1); MS1H = station(toe - 1);
            if (i == 1) { entire_approach(j); return true; }
        }
        for (Integer b = 1; b <= i - l + 1; ++b) {
            if (toe - b - 1 < 1) break;
            SA1[b] = slope(toe, toe - b - 1);
            if (SA1[b] > 1.2f * static_cast<double>(MS1) || SA1[b] > 15.0f) {
                if (b == 1) {
                    approach_depth = depth(toe - 1); SA = MS1; HSA = MS1H;
                    approach_length = length(toe - 1, toe);
                } else {
                    SA = SA1[b - 1]; approach_length = length(toe - b + 1, toe);
                    approach_depth = depth(toe - b + 1); HSA = station(toe - b + 1);
                }
                return true;
            }
        }
        entire_approach(toe);
        return true;
    }

    if (VERT[j] > static_cast<double>(water) + H0SCALE) {
        y = stored(static_cast<double>(water) + H0SCALE);
        x = linear_real(VERT[i], VERT[j], HORIZ[i], HORIZ[j], y);
    } else { y = VERT[j]; x = HORIZ[j]; }
    Integer a = 1;
    for (; a <= i; ++a) {
        const Integer p = j - a;
        MWA[p] = stored((static_cast<double>(x) - HORIZ[p]) / (static_cast<double>(y) - VERT[p]));
        if (MWA[p] > 1.2f * static_cast<double>(local_slope)) break;
    }
    if (a > i) {
        const Integer toe = j - a + 1;
        MWST = MWA[toe]; HST = station(toe); DS1 = depth(toe);
        approach_length = 1; SA = 10000;
        // Original GO TO 911 deliberately bypasses wavelength calculation.
        wavelength_required = false;
        return true;
    }
    const Integer toe = a == 1 ? i : j - a + 1;
    MWST = a == 1 ? local_slope : MWA[toe];
    HST = station(toe); DS1 = depth(toe);
    MS1 = slope(toe, toe - 1); MS1H = toe > 1 ? station(toe - 1) : 0.0f;
    if (a != 1 && a == i) { entire_approach(2); return true; }
    const Integer approach_toe = j - a + 1;
    for (Integer b = 1; b <= i - a + 1; ++b) {
        const Integer seaward = approach_toe - b;
        // The historical loop can reach point zero after examining all points.
        // Stop at the real seaward endpoint before completing the whole approach.
        if (seaward < 1) break;
        SA1[b] = slope(approach_toe, seaward);
        if (SA1[b] > 1.2f * static_cast<double>(MS1) || (SA1[b] > 15.0f && b != 1)) {
            SA = b == 1 ? HSA : SA1[b - 1]; // SA1(0) aliases HSA in the original.
            approach_length = length(approach_toe - b + 1, approach_toe);
            approach_depth = depth(approach_toe - b + 1);
            HSA = station(approach_toe - b + 1);
            return true;
        }
    }
    entire_approach(approach_toe);
    return true;
}

void Calculation::transform_wavelength() {
    const Integer relative_depth = integer(100.0 * approach_depth / (5.12f * static_cast<double>(T) * T));
    if (relative_depth <= 100) {
        wavelength_index = relative_depth;
        wavelength_lower = relative_depth;
        wavelength_upper = wavelength_lower + 1;
    } else if (relative_depth <= 6000) {
        wavelength_index = integer(90.0 + relative_depth / 10.0);
        wavelength_lower = integer((relative_depth / 10.0) * 10.0);
        wavelength_upper = wavelength_lower + 10;
    } else if (relative_depth <= 10000) {
        wavelength_index = integer(630.0 + relative_depth / 100.0);
        // The original uses the previous DLO1 here, not DLO.
        wavelength_lower = integer((wavelength_lower / 100.0) * 100.0);
        wavelength_upper = wavelength_lower + 100;
    }
    if (wavelength_index < 1 || wavelength_index >= static_cast<Integer>(tables::DLL.size()))
        throw std::domain_error("RUNUP approach depth exceeds the wavelength table");
    const auto denominator = linear_integer(wavelength_lower, wavelength_upper,
        tables::DLL[wavelength_index - 1], tables::DLL[wavelength_index], relative_depth);
    if (denominator == 0) throw std::domain_error("RUNUP wavelength division by zero");
    DXLA = 100 * approach_depth / denominator;
    DXLA1 = DXLA / 10; DXLA2 = DXLA / 2; DXLA4 = DXLA / 4;
}

void Calculation::run() {
    H0T2 = integer(static_cast<double>(H0) * 10000.0 / (static_cast<double>(T) * T) + 0.5);
    Integer ix = 1, breaking_elevation = 0;
    bool beyond_profile = false;
    for (; ix <= 10; ++ix) {
        breaker_depth = breaking_depth(H0, T, S[ix]);
        DC = integer(static_cast<double>(breaker_depth) * 100.0);
        BDLP = 0;
        breaking_elevation = integer(static_cast<double>(WTL) - DC);
        if (breaking_elevation < DEP[ix + 1]) break;
        if (breaking_elevation > DEP[NP - 1]) { beyond_profile = true; break; }
    }
    if (beyond_profile) {
        II = NP - 1;
        DLE = integer((static_cast<double>(WTL) - DEP[II] - DC) * S[II] / 100.0 + DL[II] + 0.5);
    } else {
        if (ix >= NP) throw std::domain_error("RUNUP breaker lies outside the profile");
        if (breaking_elevation < DEP[ix]) {
            DC = integer(static_cast<double>(WTL) - DEP[ix]);
            breaking_elevation = integer(static_cast<double>(WTL) - DC);
            BDLP = 1;
        }
        II = ix;
        DLE = linear_integer(DEP[II], DEP[II + 1], DL[II], DL[II + 1], breaking_elevation);
    }
    R = 0;
    const auto wave = bracket(tables::PDB1, H0T2);
    KK = wave.lower; LL = wave.upper; table_exceeded = wave.outside;
    converged = false;
    for (iterations = 1; iterations <= 10; ++iterations) {
        const float runup_scaled = stored(static_cast<double>(R) * 100.0);
        DTR = integer(static_cast<double>(WTL) + runup_scaled);
        RDTR = stored(static_cast<double>(WTL) + runup_scaled);
        Integer it = 1;
        while (it <= NP - 1 && RDTR >= RDEPP[it]) ++it;
        ending_slope = it <= NP - 1 ? it - 1 : NP - 1;
        if (ending_slope < 1) throw std::domain_error("RUNUP limit precedes the first profile segment");
        if (it <= NP - 1)
            RDSL = linear_real(RDEPP[it - 1], RDEPP[it], RDL[it - 1], RDL[it], RDTR);
        H0SCALE = stored(static_cast<double>(H0) * 100.0);
        if (R != 0)
            RDSL = stored((static_cast<double>(WTL) - DEP[ending_slope] + runup_scaled) *
                          S[ending_slope] / 100.0 + DL[ending_slope] + 0.5);
        const bool structure = classify_structure();
        if (!structure) composite();
        else {
            if (wavelength_required) transform_wavelength();
            if (SA < 15.0f) {
                if (MWST >= 4.0f) blend_by_breaker_location();
                else {
                    if (approach_length >= DXLA2) blend_by_breaker_location();
                    if (approach_length <= DXLA4) blend_by_toe_depth();
                    if (approach_length > DXLA4 && approach_length < DXLA2) {
                        // RUN's I2 is also stored as INTEGER*4.
                        const Integer weight = integer((static_cast<double>(approach_length) - DXLA4) / DXLA4);
                        blend_by_breaker_location();
                        const float first = R1;
                        blend_by_toe_depth();
                        R1 = stored(static_cast<double>(1 - weight) * R1 + static_cast<double>(weight) * first);
                    }
                }
            } else blend_by_toe_depth();
        }
        if ((structure || R != 0) && std::abs(static_cast<double>(R) - R1) < 0.15f) {
            result = stored((static_cast<double>(R) + R1) / 2.0);
            converged = true;
            return;
        }
        previous_result = R;
        R = R1;
    }
    iterations = 10;
    result = R1;
}
} // namespace legacy::runup::detail
