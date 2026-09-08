// Port of WHAFIS4G.FOR: FETCH. Source labels support differential review.
#include "engine.hpp"
namespace legacy::whafis::detail {
void Engine::fetch(float &wpi, bool &test, float &wpt, float &w) {
    float aavg{};
    float abgf{};
    float ah{};
    float ats{};
    float bavg{};
    float bethavg{};
    float bettavg{};
    float bettold{};
    float bpavg{};
    float c1d3{};
    float c1log{};
    float c2log{};
    float ca{};
    float caavg{};
    float capgam{};
    float cavg{};
    float cbavg{};
    float cbeth{};
    float cbett{};
    float ccavg{};
    float cdavg{};
    float cdnew{};
    float cdold{};
    float cdpavg{};
    float cfnut{};
    float cgtavg{};
    float cgtnew{};
    float cgtold{};
    float clo{};
    float cnut{};
    float cpavg{};
    float crav{};
    float crstr{};
    float cslavg{};
    float ctau{};
    float cwpf{};
    double davg{};
    float davgstr{};
    float dc{};
    float dd{};
    float delta1{};
    float delta2{};
    float delta3{};
    float deltau{};
    float dg{};
    float dgsl{};
    float dltaold{};
    float dltapld{};
    float dltappd{};
    float dnew{};
    float dnewstr{};
    float dold{};
    float doldstr{};
    float dpavg{};
    float ds{};
    float dsoom{};
    float dts{};
    float dx{};
    float dxmax{};
    float dxn{};
    float dxnew{};
    float dxold{};
    float eefo{};
    float efavg{};
    float epp{};
    float epshb{};
    float esfo{};
    float fdavg{};
    float fi{};
    float fl1avg{};
    float fl5avg{};
    float flavg{};
    float flnew{};
    float flold{};
    float fnut{};
    float fo{};
    float ftavg{};
    float g{};
    float gamh{};
    float gamt{};
    double gavg{};
    float gnew{};
    float gold{};
    float gou2{};
    double gslavg{};
    float gslnew{};
    float gslold{};
    float hbm{};
    float hs{};
    int ipass{};
    int nfom1{};
    float nutavg{};
    float oom{};
    float p{};
    float part1{};
    float phi{};
    float pi{};
    float pi2{};
    float pi4{};
    float pid2{};
    float q17{};
    float q18{};
    float q27{};
    float q28{};
    float q2a{};
    float q3{};
    float rat1{};
    float rat2{};
    float ratx{};
    float rav{};
    float rnew{};
    float rold{};
    float rstravg{};
    double savg{};
    float sdpavg{};
    float sen{};
    float setn{};
    float sig{};
    float sigh{};
    float sigt{};
    float slavg{};
    float slnew{};
    float slold{};
    float snew{};
    float sold{};
    float sslavg{};
    double stmp{};
    float stof{};
    float t2avg{};
    float t4avg{};
    float t5avg{};
    float t78avg{};
    float t7avg{};
    float t8avg{};
    float taunew{};
    float tauold{};
    float tdx{};
    float tdxmax{};
    float tmp{};
    float tmp1{};
    double tsavg{};
    float tsnew{};
    float tsold{};
    float ua{};
    float wf1{};
    float whm{};
    float wlavg{};
    float wli{};
    float wlistr{};
    float wlnew{};
    float wloavg{};
    float wlold{};
    float wlonew{};
    float wloold{};
    float wpavg{};
    float wpfold{};
    float wpistr{};
    float wpnew{};
    float wpold{};
    float x{};
    float xnew{};
    float xold{};
    float xsum{};
    float ynew{};
    float yold{};
    float ytest{};
    epshb = 1.0e-5f;
    fo = word("OF");
    fi = word("IF");
    delta1 = 0.0f;
    delta2 = 0.0f;
    delta3 = 0.0f;
    stof = tof;
    esfo = param(1);
    eefo = param(2);
    setn = param(3);
    sen = param(4);
    abgf = param(10);
    if ((tof == fi)) {
        tof = 1.0f;
    }
    if ((tof == fo)) {
        tof = 2.0f;
    }
    if ((esfo > bsfo)) {
        goto L10;
    }
    if ((w == windif)) {
        {
            auto record = io.writer(6, "(/,10X,34HINVALID DATA IN FIELD 1 OF IF CARD)");
            record.finish();
        }
    }
    if ((w == windof)) {
        {
            auto record = io.writer(6, "(/,10X,34HINVALID DATA IN FIELD 1 OF OF CARD)");
            record.finish();
        }
    }
    test = true;
L10:;
    if (test) {
        goto L90;
    }
    if ((wf1 == 0)) {
        wf1 = 1;
    }
    if ((setn == 0)) {
        setn = set;
    }
    if ((sen == 0)) {
        sen = se;
    }
L90:
    if ((wpi > 0)) {
        goto L95;
    }
    {
        auto record = io.writer(6, "(/,10X,'WAVE PERIOD LESS THAN OR EQUAL TO ZERO',/              "
                                   "      10X,'IN SUBROUTINE FETCH.ABORT RUN')");
        record.finish();
    }
    test = true;
L95:
    if ((!test)) {
        goto L100;
    }
    {
        auto record = io.writer(6, "(/,10X,11HJOB DUMPED.)");
        record.finish();
    }
    io.rewind(8);
    io.rewind(9);
    return;
L100:;
    if ((wpi < .1f)) {
        wpi = .1f;
    }
    ca = (wide((wide(5.28f) * wide(.589f))) / wide(3.6f));
    ua = (wide(ca) * wide(power(w, 1.23f)));
    ats = 7.54f;
    sigt = .0379f;
    g = 32.2f;
    crav = power((wide(1.357e-3f) * wide(g)), .8557f);
    ah = 0.283f;
    gamh = 0.53f;
    sigh = .00565f;
    gamt = 0.833f;
    pi = 3.1415926536f;
    ctau =
        (wide((wide(power((wide(ats) * wide(sigt)), 3)) * wide(ua))) / wide((wide(g) * wide(g))));
    crstr = (wide((wide((wide(ah) * wide(ua))) * wide(ua))) / wide(g));
    cwpf = (wide((wide(ats) * wide(ua))) / wide(g));
    cnut = (wide(power(sigt, 3)) / wide((wide(sigh) * wide(sigh))));
    cbeth = (wide(gamh) * wide(power((wide(g) / wide((wide(ua) * wide(ua)))), 0.75f)));
    cbett = (wide(gamt) * wide(power((wide(g) / wide((wide(ua) * wide(ua)))), 0.375f)));
    pi2 = (wide(2) * wide(pi));
    pid2 = (wide(pi) * wide(0.5f));
    clo = (wide(g) / wide(pi2));
    pi4 = (wide(4) * wide(pi));
    caavg =
        (wide((wide(power((wide(sigh) * wide(ah)), 2)) * wide((wide(ua) * wide(ua))))) / wide(g));
    cbavg = (wide((wide(power(sigh, 2)) * wide(g))) / wide((wide(ua) * wide(ua))));
    cpavg = (wide(power((wide(sigt) * wide(ats)), 2)) / wide(pi4));
    ccavg = (wide(1.f) / wide((wide((wide(3.f) * wide(pi))) * wide(std::sqrt(2.0f)))));
    c1d3 = (wide(1.f) / wide(3.f));
    cfnut = power((wide(cbeth) / wide(power(cbett, 2))), 2);
    dx = 25;
    x = (wide(esfo) - wide(bsfo));
    if ((x < 500)) {
        dx = (wide(x) / wide(20.0f));
    }
    dts = (wide((wide(dx) * wide((wide(setn) - wide(sa(nfo, 3)))))) / wide(x));
    ds = (wide((wide(dx) * wide((wide(sen) - wide(sa(nfo, 4)))))) / wide(x));
    dg = (wide((wide(dx) * wide((wide(eefo) - wide(befo))))) / wide(x));
    dgsl = (wide((wide(dx) * wide((wide(gsle) - wide(gslb))))) / wide(x));
    sig = .0125f;
    gou2 = .00415806f;
    oom = 2.38095f;
    c1log = std::log10(2.0f);
    c2log = (wide(.394528f) * wide(c1log));
    dsoom = .68057f;
    xsum = 0;
    xold = 0;
    tsold = sa(nfo, 3);
    sold = sa(nfo, 4);
    gold = befo;
    gslold = gslb;
    wpold = wpi;
    dold = (wide(sold) - wide(gold));
    doldstr = maximum(0.01f, (wide(sold) - wide(gold)));
    ipass = 0;
    tdx = minimum((wide(2) * wide(dx)), x);
    ynew = 0;
    yold = hm0(whi, (wide(sold) - wide(befo)), wpi);
L110:;
    xnew = (wide(xold) + wide(tdx));
    if ((xnew > x)) {
        goto L135;
    }
    if ((xnew == x)) {
        ipass = 1;
    }
    tsavg = (wide(tsold) + wide(dts));
    savg = (wide(sold) + wide(ds));
    gavg = (wide(gold) + wide(dg));
    davg = (wide(savg) - wide(gavg));
    davgstr = maximum(0.01f, davg);
    gslavg = (wide(gslold) + wide(dgsl));
    gslnew = (wide(gslavg) + wide(dgsl));
    dxn = (wide(2.f) * wide(dx));
    dnew = (wide(davg) + wide((wide(ds) - wide(dg))));
    dnewstr = maximum(0.01f, dnew);
    tsnew = (wide(tsavg) + wide(dts));
    snew = (wide(savg) + wide(ds));
    gnew = (wide(gavg) + wide(dg));
    bethavg = std::tanh((wide(cbeth) * wide(power(davgstr, 0.75f))));
    bettavg = std::tanh((wide(cbett) * wide(power(davgstr, 0.375f))));
    if ((bettavg > 0.1f)) {
        fnut = power((wide(bethavg) / wide(power(bettavg, 2))), 2);
    } else {
        fnut = cfnut;
    }
    bettold = std::tanh((wide(cbett) * wide(power(doldstr, 0.375f))));
    wpfold = (wide(cwpf) * wide(bettold));
    nutavg = (wide((wide(cnut) * wide(bettavg))) * wide(fnut));
    rstravg = power((wide(crstr) * wide(bethavg)), 2);
    rold = (wide(yold) * wide(yold));
    rat2 = (wide(rold) / wide(rstravg));
    rat1 = minimum(rat2, 1.0f);
    ftavg = power((wide(1.f) - wide(rat1)), nutavg);
    dltaold = 1;
    if (((rat2 >= 1) || (wpold >= wpfold))) {
        dltaold = 0.0f;
    }
    if ((rat2 <= 1.0f)) {
        dltapld = 1.0f;
    } else {
        dltapld = (wide(1.0f) / wide(rat2));
    }
    if ((rat2 < 1.0f)) {
        dltappd = 1.0f;
    } else {
        dltappd = 0.0f;
    }
    deltau = (wide((wide((wide(dxn) * wide(ctau))) * wide(ftavg))) * wide(dltaold));
    tauold = power(wpold, 3);
    taunew = (wide(tauold) + wide(deltau));
    wpnew = power(taunew, c1d3);
    dltaold = 1.0f;
    dltapld = 1.0f;
    dltappd = 1.0f;
    bavg = (wide(cbavg) / wide(power(bethavg, 2)));
    wloold = (wide((wide(clo) * wide(wpold))) * wide(wpold));
    wloold = maximum(0.1f, wloold);
    wlonew = (wide((wide(clo) * wide(wpnew))) * wide(wpnew));
    wlonew = maximum(0.1f, wlonew);
    cdnew = (wide(dnewstr) / wide(wlonew));
    cdold = (wide(doldstr) / wide(wloold));
    wlold = (wide(wloold) * wide(std::sqrt(std::tanh((wide(pi2) * wide(cdold))))));
    wlold = maximum(0.1f, wlold);
    wlnew = (wide(wlonew) * wide(std::sqrt(std::tanh((wide(pi2) * wide(cdnew))))));
    wlnew = maximum(0.1f, wlnew);
    wli = wlnew;
    slold = (wide((wide(pi4) * wide(doldstr))) / wide(wlold));
    slold = maximum(0.01f, slold);
    slnew = (wide((wide(pi4) * wide(dnewstr))) / wide(wlnew));
    slnew = maximum(0.01f, slnew);
    if ((slold > 0.04f)) {
        flold = (wide(slold) / wide(std::sinh(minimum(50.0f, slold))));
    } else {
        flold = 1.0f;
    }
    if ((slnew > 0.04f)) {
        flnew = (wide(slnew) / wide(std::sinh(minimum(50.0f, slnew))));
    } else {
        flnew = 1.0f;
    }
    cgtold = (wide((wide(0.5f) * wide(wlold))) * wide((wide(1.0f) + wide(flold))));
    cgtnew = (wide((wide(0.5f) * wide(wlnew))) * wide((wide(1.0f) + wide(flnew))));
    wloavg =
        (wide((wide(0.5f) * wide(clo))) * wide((wide(power(wpold, 2)) + wide(power(wpnew, 2)))));
    wloavg = maximum(0.1f, wloavg);
    cdavg = (wide(davgstr) / wide(wloavg));
    dpavg = (wide(pi2) * wide(cdavg));
    sdpavg = minimum(1.e9f, std::sinh(minimum(50.0f, dpavg)));
    cdpavg = minimum(1.e9f, std::cosh(minimum(50.0f, dpavg)));
    fdavg = std::sqrt(std::tanh((wide(pi2) * wide(cdavg))));
    wlavg = (wide(wloavg) * wide(fdavg));
    wlavg = maximum(0.1f, wlavg);
    slavg = (wide((wide(pi4) * wide(davgstr))) / wide(wlavg));
    slavg = maximum(0.01f, slavg);
    sslavg = minimum(1.e9f, std::sinh(minimum(50.0f, slavg)));
    cslavg = minimum(1.e9f, std::cosh(minimum(50.0f, slavg)));
    if ((slavg > 0.04f)) {
        flavg = (wide(slavg) / wide(sslavg));
    } else {
        flavg = 1.0f;
    }
    if ((slavg > 0.04f)) {
        fl1avg =
            (wide((wide(sslavg) - wide((wide(slavg) * wide(cslavg))))) / wide(power(sslavg, 2)));
        fl5avg = (wide(1.0f) + wide((wide(power(flavg, 2)) * wide(cslavg))));
    } else {
        fl1avg = 0.0f;
        fl5avg = 2.0f;
    }
    if ((dpavg > 0.04f)) {
        t2avg = std::sqrt(
            (wide((wide(wloavg) * wide(cdavg))) / wide((wide(sdpavg) * wide(power(cdpavg, 3))))));
    } else {
        t2avg = std::sqrt((wide(wloavg) / wide(pi2)));
    }
    t4avg = (wide(pi2) * wide(fl1avg));
    t5avg = (wide((wide(pid2) * wide(fl5avg))) * wide(t2avg));
    cgtavg = (wide((wide(0.5f) * wide(wlavg))) * wide((wide(1.f) + wide(flavg))));
    if ((dpavg > 0.04f)) {
        t78avg = (wide(std::sqrt(davgstr)) / wide(cgtavg));
    } else {
        t78avg = (wide(1.f) / wide(std::sqrt((wide(pi2) * wide(wloavg)))));
    }
    t7avg = (wide((wide(2.f) * wide(t4avg))) * wide(t78avg));
    t8avg = (wide(t5avg) * wide(t78avg));
    aavg = caavg;
    wpavg = (wide(0.5f) * wide((wide(wpold) + wide(wpnew))));
    capgam = 0.0f;
    cavg = 0.0f;
    bpavg = (wide((wide(bavg) + wide((wide(cavg) * wide(yold))))) * wide(dxn));
    p = (-bpavg);
    q2a = (wide(aavg) * wide(dxn));
    efavg = std::exp(p);
    if ((std::abs(p) > 0.001f)) {
        q3 = (wide((wide(1.f) - wide(efavg))) / wide(bpavg));
    } else {
        q3 = 1.0f;
    }
    q27 = std::exp((wide((-t7avg)) * wide((wide(std::sqrt(dnewstr)) - wide(std::sqrt(davgstr))))));
    q17 = std::exp((wide((-t7avg)) * wide((wide(std::sqrt(dnewstr)) - wide(std::sqrt(doldstr))))));
    q28 = power((wide(davgstr) / wide(dnewstr)), t8avg);
    q18 = power((wide(doldstr) / wide(dnewstr)), t8avg);
    rnew = (wide((wide((wide((wide(rold) * wide(q18))) * wide(q17))) * wide(efavg))) +
            wide((wide((wide((wide(q2a) * wide(q28))) * wide(q27))) * wide(q3))));
    ynew = std::sqrt(rnew);
    wpi = wpnew;
    wlistr = maximum(0.1f, wli);
    epp = (wide(ynew) / wide((wide((wide(4) * wide(wlistr))) * wide(.002f))));
    epp = maximum(1.0e-4f, epp);
    wpistr = maximum(0.1f, wpi);
    dd = (wide(dnewstr) / wide((wide(g) * wide(power(wpistr, 2)))));
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
    hbm = shbm(wpnew, gslnew, dnewstr);
    if ((wht >= (wide(hbm) - wide(epshb)))) {
        wht = hbm;
        ynew = hm0(wht, dnewstr, wpi);
    };
    xsum = (wide(xsum) + wide(tdx));
    if ((xsum < 100)) {
        goto L120;
    }
    nfo = (nfo + 1);
    if ((nfo > 1000)) {
        {
            auto record = io.writer(6, "(/,10X,38HARRAY DIMENSIONS EXCEEDED. JOB DUMPED.)");
            record.finish();
        }
    }
    if ((nfo > 1000)) {
        throw CalculationStopped{};
    }
    gs(nfo) = (wide(bsfo) + wide(xnew));
    hbm = shbm(wpnew, gslnew, dnewstr);
    whm = hbm;
    if ((wht > whm)) {
        wht = whm;
    }
    hbw(nfo) = wht;
    stmp = (wide(gnew) + wide(dnew));
    ew(nfo) = (wide((wide(.7f) * wide(hbw(nfo)))) + wide(stmp));
    spwp(nfo) = wpnew;
    nfom1 = (nfo - 1);
    sa(nfo, 1) = gs(nfom1);
    sa(nfo, 2) = gs(nfo);
    sa(nfo, 3) = tsnew;
    sa(nfo, 4) = snew;
    if ((gs(nfo) == esfo)) {
        sa(nfo, 5) = stof;
    } else {
        sa(nfo, 5) = tof;
    }
    xsum = 0;
L120:;
    if ((ipass == 1)) {
        goto L135;
    }
    ytest = std::abs((wide(ynew) - wide(yold)));
    tdxmax = (wide(x) - wide(xnew));
    dxmax = (wide(0.5f) * wide(tdxmax));
    if ((ytest > .05f)) {
        goto L125;
    }
    dxold = dx;
    dxnew = minimum((wide(2.f) * wide(dx)), dxmax);
    ratx = (wide((wide(0.5f) * wide(dxnew))) / wide(dxold));
    dx = dxnew;
    tdx = minimum((wide(2.f) * wide(dx)), tdxmax);
    dts = (wide((wide(2) * wide(dts))) * wide(ratx));
    ds = (wide((wide(2) * wide(ds))) * wide(ratx));
    dg = (wide((wide(2) * wide(dg))) * wide(ratx));
    dgsl = (wide((wide(2.f) * wide(dgsl))) * wide(ratx));
    goto L130;
L125:
    if ((ytest < 0.1f)) {
        goto L1000;
    }
    if ((dx < 5.0f)) {
        goto L1000;
    }
    dxold = dx;
    dxnew = minimum((wide(0.5f) * wide(dx)), dxmax);
    ratx = (wide((wide(2.f) * wide(dxnew))) / wide(dxold));
    dx = dxnew;
    tdx = minimum((wide(2.f) * wide(dx)), tdxmax);
    dts = (wide((wide(.5f) * wide(dts))) * wide(ratx));
    ds = (wide((wide(.5f) * wide(ds))) * wide(ratx));
    dg = (wide((wide(.5f) * wide(dg))) * wide(ratx));
    dgsl = (wide((wide(0.5f) * wide(dgsl))) * wide(ratx));
    goto L130;
L1000:;
    dxold = dx;
    dxnew = minimum(dx, dxmax);
    ratx = (wide(dxnew) / wide(dxold));
    dx = dxnew;
    tdx = minimum((wide(2.f) * wide(dx)), tdxmax);
    dts = (wide(dts) * wide(ratx));
    ds = (wide(ds) * wide(ratx));
    dg = (wide(dg) * wide(ratx));
    dgsl = (wide(dgsl) * wide(ratx));
L130:
    xold = xnew;
    yold = ynew;
    tsold = tsnew;
    sold = snew;
    gold = gnew;
    gslold = gslnew;
    wpold = wpnew;
    dold = dnew;
    doldstr = maximum(0.01f, dold);
    goto L110;
L135:
    if ((gs(nfo) == esfo)) {
        goto L140;
    }
    nfo = (nfo + 1);
    gs(nfo) = esfo;
    hbm = shbm(wpnew, gslnew, dnewstr);
    whm = hbm;
    wht = minimum(wht, whm);
    hbw(nfo) = minimum(wht, whm);
    stmp = (wide(gnew) + wide(dnew));
    ew(nfo) = (wide((wide(.7f) * wide(hbw(nfo)))) + wide(stmp));
    spwp(nfo) = wpnew;
    sa(nfo, 1) = xold;
    sa(nfo, 2) = esfo;
    sa(nfo, 3) = setn;
    sa(nfo, 4) = sen;
    sa(nfo, 5) = stof;
L140:;
    if ((abgf != 1)) {
        goto L150;
    }
    nap = (nap + 1);
    ap(nap) = esfo;
    m = (m + 1);
    steg(m) = gs(nfo);
    elz(m) = ew(nfo);
L150:
    bsfo = esfo;
    befo = eefo;
    wpt = wpnew;
    return;
}
} // namespace legacy::whafis::detail
