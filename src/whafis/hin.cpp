// Port of WHAFIS4G.FOR: HIN. Source labels support differential review.
#include "engine.hpp"
namespace legacy::whafis::detail {
float Engine::hin(float whi, float afl, float w, float d, float wpt) {
    float alpha{};
    float beta{};
    float c2log{};
    float ca{};
    float cdnew{};
    float crav{};
    float dc{};
    float dd{};
    float dnewstr{};
    float dstr{};
    float efl{};
    float epp{};
    float f{};
    float g{};
    float hbm{};
    float result{};
    float hs{};
    float part1{};
    float phi{};
    float pi{};
    float pi2{};
    float rav{};
    float tanhi{};
    float tmp{};
    float tmp1{};
    float u{};
    float whii{};
    float wht{};
    float wli{};
    float wlnew{};
    float wlonew{};
    float wpi{};
    float wpistr{};
    float wptstr{};
    float x{};
    float yi{};
    float ynew{};
    pi = 3.1415926536f;
    g = 32.2f;
    crav = power((wide(1.357e-3f) * wide(g)), .8557f);
    wptstr = maximum(.01f, wpt);
    dstr = maximum(.01f, d);
    ca = power((wide(3.6f) / wide(5.28f)), 0.23f);
    u = (wide((wide(0.589f) * wide(ca))) * wide(power(w, 1.23f)));
    hbm = shbm(wptstr, 0.0f, dstr);
    whii = minimum(whi, hbm);
    yi = hm0(whii, dstr, wptstr);
    alpha = (wide((wide((wide(.283f) / wide(g))) * wide(u))) * wide(u));
    beta = std::tanh(
        (wide(.53f) * wide(power((wide((wide(g) * wide(d))) / wide(power(u, 2))), .75f))));
    x = (wide(yi) / wide((wide(alpha) * wide(beta))));
    if ((x < 1)) {
        goto L20;
    }
    ynew = yi;
    goto L100;
L20:;
    tanhi = (wide(.5f) * wide(std::log((wide((wide(1) + wide(x))) / wide((wide(1) - wide(x)))))));
    efl = (wide((wide(power((wide((wide(beta) / wide(.00565f))) * wide(tanhi)), 2)) *
                 wide(power(u, 2)))) /
           wide(g));
    f = (wide(efl) + wide(afl));
    ynew = (wide((wide(alpha) * wide(beta))) *
            wide(std::tanh((wide((wide(.00565f) / wide(beta))) *
                            wide(std::sqrt((wide((wide(g) * wide(f))) / wide(power(u, 2)))))))));
L100:;
    pi2 = (wide(2.f) * wide(pi));
    wlonew = (wide((wide((wide(g) / wide(pi2))) * wide(wptstr))) * wide(wptstr));
    wlonew = maximum(0.1f, wlonew);
    dnewstr = maximum(0.01f, d);
    cdnew = (wide(dnewstr) / wide(wlonew));
    wlnew = (wide(wlonew) * wide(std::sqrt(std::tanh((wide(pi2) * wide(cdnew))))));
    wlnew = maximum(0.01f, wlnew);
    wpi = wptstr;
    wpistr = maximum(0.1f, wpi);
    wli = wlnew;
    c2log = (wide(.394528f) * wide(std::log10(2.0f)));
    epp = (wide(ynew) / wide((wide((wide(4) * wide(wli))) * wide(.002f))));
    epp = maximum(1.0e-4f, epp);
    dd = (wide(dnewstr) / wide((wide(g) * wide(power(wpi, 2)))));
    dc = 5.5722e-5f;
    part1 = (wide(.9f) + wide((wide(.42707f) * wide(std::log10((wide(dd) / wide(dc)))))));
    if ((epp <= 2)) {
        phi = (wide(part1) - wide((wide(1.411296f) * wide(std::log10(epp)))));
    }
    if ((epp > 2)) {
        phi = (wide((wide(part1) - wide(c2log))) - wide((wide(1.016768f) * wide(std::log10(epp)))));
    }
    tmp1 = (wide(crav) * wide(power(wpistr, 1.7114f)));
    tmp = (wide(tmp1) / wide(power(dnewstr, .8557f)));
    rav = (wide(1.477f) + wide((wide(.477f) * wide((wide(tmp) - wide(1.0f))))));
    if ((rav > 1.7f)) {
        rav = 1.7f;
    }
    if ((rav < 1.0f)) {
        rav = 1.0f;
    }
    if ((phi < 1)) {
        phi = 1;
    }
    if ((phi > rav)) {
        phi = rav;
    }
    hs = (wide(phi) * wide(ynew));
    wht = (wide(1.6f) * wide(hs));
    hbm = shbm(wptstr, 0.0f, dstr);
    wht = minimum(wht, hbm);
    result = wht;
    return result;
    return result;
}
} // namespace legacy::whafis::detail
