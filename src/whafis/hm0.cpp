// Port of WHAFIS4G.FOR: HM0. Source labels support differential review.
#include "engine.hpp"
namespace legacy::whafis::detail {
float Engine::hm0(float whi, float dnew, float wpi) {
    float akapa{};
    float akapc{};
    float c1log{};
    float c2log{};
    float c3log{};
    float cdnew{};
    float cl1{};
    float cl2{};
    float cl3{};
    float cp1{};
    float cp2{};
    float cp3{};
    float cp4{};
    float crav{};
    float d0{};
    float dc{};
    float dd{};
    float ddp{};
    float deleppn{};
    float derivqa{};
    float derivqc{};
    float dnewstr{};
    float epp{};
    float eppinit{};
    float eppn{};
    float eppnp1{};
    float epsp{};
    float g{};
    float result{};
    float hm0b{};
    float hm0d{};
    float hm0e{};
    float hm0init{};
    float hs{};
    float hsb{};
    float hsd{};
    float hse{};
    int n{};
    int nmax{};
    float part1{};
    float phia{};
    float phib{};
    float phic{};
    float phid{};
    float phie{};
    float pi{};
    float pi2{};
    float qa{};
    float qc{};
    float ratstar{};
    float rav{};
    float tmp{};
    float tmp1{};
    float wl0{};
    float wli{};
    int limit_3369{};
    int limit_3454{};
    if ((whi == 0)) {
        result = 0;
    }
    if ((whi == 0)) {
        return result;
    }
    pi = 3.1415926536f;
    g = 32.2f;
    crav = power((wide(1.357e-3f) * wide(g)), .8557f);
    dnewstr = maximum(0.01f, dnew);
    pi2 = (wide(2.f) * wide(pi));
    hs = (wide(whi) / wide(1.6f));
    nmax = 25;
    d0 = 1.357e-3f;
    dc = 5.5722e-5f;
    c1log = std::log10(2.0f);
    c2log = (wide(.394528f) * wide(c1log));
    c3log = (wide(1.411296f) * wide(c1log));
    cp1 = .983508529f;
    cp2 = .708568578f;
    cp3 = .10387032f;
    cp4 = .195628183f;
    wl0 = (wide(5.12f) * wide(power(wpi, 2)));
    dd = (wide(dnewstr) / wide((wide((wide(g) * wide(wpi))) * wide(wpi))));
    wl0 = maximum(wl0, 0.1f);
    cdnew = (wide(dnewstr) / wide(wl0));
    wli = (wide(wl0) * wide(std::sqrt(std::tanh((wide(pi2) * wide(cdnew))))));
    cl1 = (wide(.008f) * wide(wli));
    cl2 = (wide(2.f) * wide(cl1));
    cl3 = (wide(1.25f) / wide(wli));
    epsp = (wide(hs) / wide(cl1));
    tmp1 = (wide(crav) * wide(power(wpi, 1.7114f)));
    tmp = (wide(tmp1) / wide(power(dnewstr, .8557f)));
    rav = (wide(1.477f) + wide((wide(.477f) * wide((wide(tmp) - wide(1.0f))))));
    if ((rav > 1.7f)) {
        rav = 1.7f;
    }
    if ((rav < 1)) {
        rav = 1;
    }
    phie = rav;
    ddp = (wide(dd) / wide(dc));
    part1 = (wide(.9f) + wide((wide(.42707f) * wide(std::log10(ddp)))));
    phib = (wide(part1) - wide(c3log));
    akapa = (wide(.2303028f) / wide(power(ddp, .302608f)));
    akapc = (wide(.170474016f) / wide(power(ddp, .420026987f)));
    if ((wide(phib) - wide(phie)) < 0)
        goto L30;
    if ((wide(phib) - wide(phie)) == 0)
        goto L20;
    goto L20;
L20:;
    hm0e = (wide((wide(cl1) / wide(akapc))) * wide(power(10, (wide((-cp1)) * wide(phie)))));
    goto L40;
L30:;
    hm0e = (wide((wide(cl1) / wide(akapa))) * wide(power(10, (wide((-cp2)) * wide(phie)))));
L40:;
    hse = (wide(phie) * wide(hm0e));
    phid = 1.0f;
    if ((wide(phib) - wide(1.0f)) < 0)
        goto L60;
    if ((wide(phib) - wide(1.0f)) == 0)
        goto L50;
    goto L50;
L50:;
    hm0d = (wide((wide(cl1) / wide(akapc))) * wide(cp3));
    goto L70;
L60:;
    hm0d = (wide((wide(cl1) / wide(akapa))) * wide(cp4));
L70:;
    hsd = hm0d;
    hm0b = cl2;
    hsb = (wide(hm0b) * wide(phib));
    if ((hs >= hsd)) {
        goto L220;
    }
    if ((hs <= hse)) {
        goto L230;
    }
    goto L240;
L220:;
    result = hs;
    epp = (wide(result) / wide(cl1));
    goto L320;
L230:;
    result = (wide(hs) / wide(phie));
    epp = (wide(result) / wide(cl1));
    goto L320;
L240:;
    if ((wide(hsb) - wide(hs)) < 0)
        goto L80;
    if ((wide(hsb) - wide(hs)) == 0)
        goto L140;
    goto L150;
L80:;
    if ((wide(phib) - wide(phie)) < 0)
        goto L90;
    if ((wide(phib) - wide(phie)) == 0)
        goto L100;
    goto L100;
L90:;
    ratstar = (wide((wide(hm0b) - wide(hm0d))) / wide((wide(hsb) - wide(hsd))));
    goto L110;
L100:;
    ratstar = (wide((wide(hm0e) - wide(hm0d))) / wide((wide(hse) - wide(hsd))));
L110:;
    hm0init = (wide(hm0d) + wide((wide(ratstar) * wide((wide(hs) - wide(hsd))))));
    eppinit = (wide(hm0init) / wide(cl1));
    eppn = eppinit;
    limit_3369 = nmax;
    for (n = 1; n <= limit_3369; n += 1) {
        phic = (wide((-1.016768f)) * wide(std::log10((wide(akapc) * wide(eppn)))));
        qc = (wide((wide(eppn) * wide(phic))) - wide(epsp));
        derivqc = (wide(phic) - wide(.441576731f));
        deleppn = (wide((-qc)) / wide(derivqc));
        eppnp1 = (wide(eppn) + wide(deleppn));
        if ((std::abs(deleppn) < cl3)) {
            goto L130;
        }
        eppn = eppnp1;
        ;
    }
L130:;
    epp = eppnp1;
    result = (wide(cl1) * wide(epp));
    goto L310;
L140:;
    result = cl2;
    epp = 2.0f;
    goto L310;
L150:;
    if ((wide(phib) - wide(phid)) < 0)
        goto L160;
    if ((wide(phib) - wide(phid)) == 0)
        goto L160;
    goto L170;
L160:;
    ratstar = (wide((wide(hm0d) - wide(hm0e))) / wide((wide(hsd) - wide(hse))));
    goto L180;
L170:;
    ratstar = (wide((wide(hm0b) - wide(hm0e))) / wide((wide(hsb) - wide(hse))));
L180:;
    hm0init = (wide(hm0e) + wide((wide(ratstar) * wide((wide(hs) - wide(hse))))));
    eppinit = (wide(hm0init) / wide(cl1));
    eppn = eppinit;
    limit_3454 = nmax;
    for (n = 1; n <= limit_3454; n += 1) {
        phia = (wide((-1.411296f)) * wide(std::log10((wide(akapa) * wide(eppn)))));
        qa = (wide((wide(eppn) * wide(phia))) - wide(epsp));
        derivqa = (wide(phia) - wide(.612918065f));
        deleppn = (wide((-qa)) / wide(derivqa));
        eppnp1 = (wide(eppn) + wide(deleppn));
        if ((std::abs(deleppn) < cl3)) {
            goto L300;
        }
        eppn = eppnp1;
        ;
    }
L300:;
    epp = eppnp1;
    result = (wide(cl1) * wide(epp));
L310:;
L320:;
    return result;
    return result;
}
} // namespace legacy::whafis::detail
