// SPDX-License-Identifier: MIT
#pragma once
#include <array>
#include <cstdint>
#include <vector>

namespace legacy::runup::detail {
using Integer = std::int32_t;

// Original variable names keep the binary/source correspondence reviewable.
// Arrays retain one-based model indices; element zero is never a profile point.
struct Calculation {
    struct CurveTrace { Integer slope, depth, ratio; float raw_runup, runup_station, runup_elevation; };
    std::vector<CurveTrace> curve_trace;
    std::array<Integer, 21> DEP{}, DL{};
    std::array<float, 21> S{}, ROUGH{}, RDL{}, RDEPP{}, HORIZ{}, VERT{}, MWA{}, SA1{};
    Integer NP{}, MAXPTS{};
    float WTL{}, WTB{}, H0{}, T{};
    Integer DS1{}, DTR{}, DLE{}, DS{}, DC{}, II{}, DCS{}, KK{}, LL{}, H0T2{}, RS{};
    Integer DXLA{}, DXLA1{}, DXLA2{}, DXLA4{};
    float SA{}, MS1{}, MS1H{}, H0SCALE{}, R{}, R1{}, RB{}, RZ{};
    float HST{}, MWST{}, HSA{}, RDTR{}, RDSL{}, CS{}, BDLP{}, STS{};
    Integer ending_slope{}, iterations{};
    bool table_exceeded{}, converged{};
    float result{}, breaker_depth{};
    Integer approach_depth{}, wavelength_lower{}, wavelength_upper{}, wavelength_index{};
    float approach_length{};
    bool wavelength_required{};

    float roughness() const;
    void curve();
    void simple();
    void structure_with_sloping_approach();
    void composite();
    void blend_by_breaker_location();
    void blend_by_toe_depth();
    bool classify_structure();
    void transform_wavelength();
    void run();
};
} // namespace legacy::runup::detail
