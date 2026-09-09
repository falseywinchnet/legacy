// Port of WHAFIS4G.FOR: WHAFIS4. Source labels support differential review.
#include "engine.hpp"
namespace legacy::whafis::detail {
void Engine::whafis4() {
    float adf{};
    float adfhold{};
    float adv{};
    float aeg{};
    float aer{};
    float afl{};
    float ah{};
    float ahs{};
    float ammb{};
    float as = word("AS");
    float ase{};
    float ats{};
    float awh{};
    bool azone{};
    float b{};
    float beg{};
    float big{};
    float blee = word(" LEE");
    float bp{};
    float bu = word("BU");
    float d{};
    float dc{};
    float diff{};
    float du = word("DU");
    float eeb{};
    float eefo{};
    float ei = word("IE");
    float end{};
    float ep{};
    float esfo{};
    float et = word("ET");
    float fi = word("IF");
    float fl{};
    float fo = word("OF");
    float gtst{};
    float hb{};
    float hbm{};
    float hsg{};
    float hsg1{};
    float hsg2{};
    int i{};
    int i1{};
    int i2{};
    int ielz{};
    int ifhf{};
    int ii{};
    int index{};
    int indx{};
    int insz{};
    int itrnk{};
    int j{};
    int k{};
    int mm1{};
    int n{};
    int ns{};
    Array<int, 1000> nse{};
    int padnum{};
    float part1{};
    float part2{};
    float pi = 3.14159f;
    float r{};
    float rb{};
    Array<float, 1000> save{};
    Array<float, 1000> sbp{};
    float sdeb{};
    Array<float, 1000> selz{};
    float sen{};
    Array<float, 1000> sep{};
    float setn{};
    float slope{};
    float small{};
    float spdof{};
    float start{};
    double stmp{};
    float stop{};
    Array<float, 1000> stvg{};
    float temp{};
    bool test{};
    Array<float, 80> title{};
    Text<132> title2{};
    float tsg{};
    float tsg1{};
    float tsg2{};
    float tst{};
    float ve = word("VE");
    float vh = word("VH");
    Array<float, 1000> vzne{};
    bool vzone{};
    float w{};
    float ward = word("WARD");
    float whm{};
    float wind = word("WIND");
    float wpi{};
    float wpt{};
    float x{};
    int limit_164{};
    int limit_636{};
    int limit_674{};
    int limit_694{};
    int limit_711{};
    int limit_745{};
    int limit_752{};
    int limit_781{};
    int limit_788{};
    int limit_789{};
    int limit_799{};
    int limit_800{};
    int limit_813{};
    int limit_814{};
    int limit_822{};
    int limit_828{};
    int limit_830{};
    int limit_851{};
    int limit_865{};
    int limit_885{};
    int limit_904{};
    int limit_924{};
    int limit_931{};
    int limit_945{};
    {
        auto record = io.writer(6, "(1X,'WAVE HEIGHT COMPUTATIONS FOR ',                          "
                                   "'FLOOD INSURANCE STUDIES (WHAFIS VERSION 4.0G, 08_2007)')");
        record.finish();
    }
    {
        auto record = io.writer(6, "(1X,'Input file:  ', A128)");
        record.write(xinname);
        record.finish();
    }
    {
        auto record = io.writer(6, "(1X,'Output file: ', A128, ///)");
        record.write(xoutname);
        record.finish();
    }
    readin();
    scane();
    {
        auto record = io.reader(10, "(a80)");
        record.read(title2);
        record.finish();
    }
    if (case500) {
        title2 = title2.slice(6, 80);
    }
    title2 = trim(adjust_left(title2));
    padnum = (130 - trimmed_length(title2));
    padnum = (padnum / 2);
    limit_164 = padnum;
    for (ii = 1; ii <= limit_164; ii += 1) {
        title2 = concatenate(" ", title2);
    }
L4:
    bsfo = 0;
    n = 0;
    m = 0;
    nfo = 0;
    nap = 0;
    spdof = (wide((wide(5280.0f) * wide(windof))) / wide(3600.0f));
    {
        auto record = io.writer(6, "(a132)");
        record.write(title2);
        record.finish();
    }
    if (case500) {
        {
            auto record = io.writer(6, "(53X,'THIS IS A 500-YEAR CASE')");
            record.finish();
        }
    } else {
        {
            auto record = io.writer(6, "(53X,'THIS IS A 100-YEAR CASE')");
            record.finish();
        }
    }
    if ((((windif != wwndif) || (windof != wwndof)) || (windvh != wwndvh))) {
        {
            auto record =
                io.writer(6, "(//,39X,'THE FOLLOWING NON-DEFAULT WIND SPEEDS ARE BEING USED')");
            record.finish();
        }
        {
            auto record = io.writer(6, "(44X,'WINDIF',F7.2,2X,'WINDOF',F7.2,2X,'WINDVH',F7.2)");
            record.write(windif);
            record.write(windof);
            record.write(windvh);
            record.finish();
        }
    }
    {
        auto record = io.writer(6, "(/,60X,12H PART1 INPUT,/)");
        record.finish();
    }
L5:
    {
        auto record = io.reader(10, "(A2,F7.0,9F8.0)");
        record.read(tof);
        for (i = 1; i <= 10; ++i) {
            record.read(param(i));
        }
        record.finish();
    }
    {
        auto record = io.writer(6, "(10X,A2,10F11.3)");
        record.write(tof);
        for (i = 1; i <= 10; ++i) {
            record.write(param(i));
        }
        record.finish();
    }
    {
        auto record = io.writer(8, "(10X,A2,10F11.3)");
        record.write(tof);
        for (i = 1; i <= 10; ++i) {
            record.write(param(i));
        }
        record.finish();
    }
    if ((tof == du)) {
        goto L50;
    }
    if ((tof == bu)) {
        goto L100;
    }
    if ((tof == ve)) {
        goto L125;
    }
    if ((tof == fi)) {
        goto L150;
    }
    if ((tof == fo)) {
        goto L200;
    }
    if ((tof == as)) {
        goto L230;
    }
    if ((tof == vh)) {
        goto L240;
    }
    if ((tof == et)) {
        goto L300;
    }
    if ((tof != ei)) {
        {
            auto record = io.writer(6, "(10X,39HTHE ABOVE CARD CONTAINS ILLEGAL DATA IN,1X,        "
                                       " 20HTHE FIRST 2 COLUMNS.)");
            record.finish();
        }
    }
    if ((tof != ei)) {
        goto L1000;
    }
    esfo = param(1);
    eefo = param(2);
    fl = param(3);
    set = param(4);
    se = param(5);
    wht = param(6);
    wpt = param(7);
    wpi = wpt;
    whi = wht;
    gslb = param(9);
    gsle = gslb;
    ase = se;
    if ((eefo > se)) {
        {
            auto record = io.writer(6, "(5X,46H GROUND ELEVATION GREATER THAN SURGE ELEVATION,1X,  "
                                       " 24HENCOUNTERED. JOB DUMPED.)");
            record.finish();
        }
    }
    if ((eefo > se)) {
        goto L1000;
    }
    if ((wpt > 0)) {
        goto L20;
    }
    afl = (wide(5280) * wide(fl));
    if ((afl == 0.0f)) {
        afl = (wide(5280.f) * wide(24.f));
    }
    wpt = t(0.f, afl, spdof, 26.0f);
L20:;
    if ((wht == 0.0f)) {
        afl = (wide(5280.f) * wide(fl));
        if ((afl == 0.0f)) {
            afl = (wide(5280.f) * wide(24.f));
        }
        wht = hin(0.0f, afl, spdof, 26.0f, wpt);
    }
    sdeb = maximum(0.0f, (wide(se) - wide(eefo)));
    hb = shbm(wpt, gsle, sdeb);
    wht = minimum(wht, hb);
    goto L250;
L50:
    esfo = param(1);
    eefo = param(2);
    ammb = param(3);
    setn = param(4);
    sen = param(5);
    gslb = gsle;
    wpi = wpt;
    whi = wht;
    gsle = param(9);
    if ((setn != 0)) {
        set = setn;
    }
    if ((sen != 0)) {
        se = sen;
    }
    if (((eefo > se) && (ammb == 0))) {
        {
            auto record = io.writer(6, "(5X,46H GROUND ELEVATION GREATER THAN SURGE ELEVATION,1X,  "
                                       " 24HENCOUNTERED. JOB DUMPED.)");
            record.finish();
        }
    }
    if (((eefo > se) && (ammb == 0))) {
        goto L1000;
    }
    ase = (wide((wide(sa(nfo, 4)) + wide(se))) / wide(2.0f));
    eeb = eefo;
    sdeb = (wide(se) - wide(eeb));
    hbm = shbm(wpi, gsle, sdeb);
    if ((whi < hbm)) {
        b = 1.0f;
    }
    if ((whi == 0)) {
        goto L80;
    }
    if ((ammb != 0)) {
        goto L75;
    }
    if ((whi >= hbm)) {
        b = (wide(hbm) / wide(whi));
    }
    goto L80;
L75:
    if ((eeb >= (wide(se) + wide((wide(.5f) * wide(whi)))))) {
        b = 0;
    }
    if ((eeb >= (wide(se) + wide((wide(.5f) * wide(whi)))))) {
        goto L80;
    }
    if ((whi >= hbm)) {
        b = (wide((wide(1) / wide((wide(2) * wide(whi))))) * wide((wide(hbm) + wide(whi))));
    }
    if ((eeb > se)) {
        b = (wide(.5f) - wide((wide((wide(eeb) - wide(se))) / wide(whi))));
    }
L80:
    wht = (wide(b) * wide(whi));
    wpt = wpi;
    goto L250;
L100:
    esfo = param(1);
    eefo = param(2);
    r = param(3);
    rb = param(4);
    setn = param(5);
    sen = param(6);
    gslb = gsle;
    wpi = wpt;
    whi = wht;
    gsle = param(9);
    if ((setn != 0)) {
        set = setn;
    }
    if ((sen != 0)) {
        se = sen;
    }
    ase = (wide((wide(sa(nfo, 4)) + wide(se))) / wide(2.0f));
    if ((eefo > se)) {
        {
            auto record = io.writer(6, "(5X,46H GROUND ELEVATION GREATER THAN SURGE ELEVATION,1X,  "
                                       " 24HENCOUNTERED. JOB DUMPED.)");
            record.finish();
        }
    }
    if ((eefo > se)) {
        goto L1000;
    }
    b = power(r, (wide(rb) / wide(2.0f)));
    wht = (wide(whi) * wide(b));
    if ((eefo == se)) {
        wht = 0;
    }
    wpt = wpi;
    goto L250;
L125:
    esfo = param(1);
    eefo = param(2);
    d = param(3);
    ah = param(4);
    ahs = param(5);
    dc = param(6);
    setn = param(7);
    sen = param(8);
    gslb = gsle;
    wpi = wpt;
    whi = wht;
    gsle = param(9);
    if ((setn != 0)) {
        set = setn;
    }
    if ((sen != 0)) {
        se = sen;
    }
    ase = (wide((wide(sa(nfo, 4)) + wide(se))) / wide(2.0f));
    if ((dc == 0)) {
        dc = 1.0f;
    }
    w = (wide(esfo) - wide(bsfo));
    if ((eefo > se)) {
        {
            auto record = io.writer(6, "(5X,46H GROUND ELEVATION GREATER THAN SURGE ELEVATION,1X,  "
                                       " 24HENCOUNTERED. JOB DUMPED.)");
            record.finish();
        }
    }
    if ((eefo > se)) {
        goto L1000;
    }
    aeg = (wide((wide(befo) + wide(eefo))) / wide(2.0f));
    adv = (wide(ase) - wide(aeg));
    if ((adv <= 0)) {
        {
            auto record = io.writer(
                6, "(5X,42H AVERAGE DEPTH LESS THAN OR EQUAL TO ZERO.,1X,       11HJOB DUMPED.)");
            record.finish();
        }
    }
    if ((adv <= 0.f)) {
        {
            auto record = io.writer(6, "(/2X,'TOF= ',A2,2X,'STATION= ',F8.2/)");
            record.write(tof);
            record.write(param(1));
            record.finish();
        }
    }
    if ((adv <= 0)) {
        goto L1000;
    }
    awh = minimum(ah, adv);
    part1 = (wide((wide((wide((wide(dc) * wide(whi))) * wide(awh))) * wide(d))) * wide(w));
    part2 = (wide((wide((wide(3) * wide(pi))) * wide(power(ahs, 2)))) * wide(power(adv, 2)));
    b = (wide(1) / wide((wide(1) + wide((wide(part1) / wide(part2))))));
    wht = (wide(whi) * wide(b));
    if ((eefo == se)) {
        wht = 0;
    }
    wpt = wpi;
    goto L250;
L150:
    esfo = param(1);
    eefo = param(2);
    setn = param(3);
    sen = param(4);
    gslb = gsle;
    wpi = wpt;
    whi = wht;
    gsle = param(9);
    if ((setn != 0)) {
        set = setn;
    }
    if ((sen != 0)) {
        se = sen;
    }
    if ((eefo > se)) {
        {
            auto record = io.writer(6, "(5X,46H GROUND ELEVATION GREATER THAN SURGE ELEVATION,1X,  "
                                       " 24HENCOUNTERED. JOB DUMPED.)");
            record.finish();
        }
        goto L1000;
    }
    ase = (wide((wide(sa(nfo, 4)) + wide(se))) / wide(2.0f));
    aeg = (wide((wide(eefo) + wide(befo))) / wide(2.0f));
    adf = (wide(ase) - wide(aeg));
    adfhold = adf;
    if ((adf <= 0)) {
        {
            auto record = io.writer(
                6, "(5X,42H AVERAGE DEPTH LESS THAN OR EQUAL TO ZERO.,1X,       11HJOB DUMPED.)");
            record.finish();
        }
    }
    if ((adf <= 0.f)) {
        {
            auto record = io.writer(6, "(/2X,'TOF= ',A2,2X,'STATION= ',F8.2/)");
            record.write(tof);
            record.write(param(1));
            record.finish();
        }
    }
    if ((adf <= 0)) {
        goto L1000;
    }
    test = false;
    w = windif;
    fetch(wpi, test, wpt, w);
    if (test) {
        goto L1000;
    }
    goto L5;
L200:
    esfo = param(1);
    eefo = param(2);
    setn = param(3);
    sen = param(4);
    gslb = gsle;
    wpi = wpt;
    whi = wht;
    gsle = param(9);
    if ((setn != 0)) {
        set = setn;
    }
    if ((sen != 0)) {
        se = sen;
    }
    ase = (wide((wide(sa(nfo, 4)) + wide(se))) / wide(2.0f));
    if ((eefo > se)) {
        {
            auto record = io.writer(6, "(5X,46H GROUND ELEVATION GREATER THAN SURGE ELEVATION,1X,  "
                                       " 24HENCOUNTERED. JOB DUMPED.)");
            record.finish();
        }
    }
    if ((eefo > se)) {
        goto L1000;
    }
    aeg = (wide((wide(eefo) + wide(befo))) / wide(2.0f));
    adf = (wide(ase) - wide(aeg));
    if ((adf <= 0)) {
        {
            auto record = io.writer(
                6, "(5X,42H AVERAGE DEPTH LESS THAN OR EQUAL TO ZERO.,1X,       11HJOB DUMPED.)");
            record.finish();
        }
    }
    if ((adf <= 0.f)) {
        {
            auto record = io.writer(6, "(/2X,'TOF= ',A2,2X,'STATION= ',F8.2/)");
            record.write(tof);
            record.write(param(1));
            record.finish();
        }
    }
    if ((adf <= 0)) {
        goto L1000;
    }
    test = false;
    w = windof;
    fetch(wpi, test, wpt, w);
    if (test) {
        goto L1000;
    }
    goto L5;
L230:
    esfo = param(1);
    eefo = param(2);
    setn = param(3);
    sen = param(4);
    gslb = gsle;
    wpi = wpt;
    whi = 0.0f;
    gsle = param(9);
    if ((setn != 0)) {
        set = setn;
    }
    if ((sen != 0)) {
        se = sen;
    }
    if ((eefo < se)) {
        {
            auto record = io.writer(
                6, "(/1X,'*** AS CARD GROUND ELEVATION LESS THAN',              ' STILLWATER "
                   "ELEVATION, SHOULD USE OTHER TYPE CARD, JOB',         ' DUMPED  ***'/,          "
                   "                                        'TOF= ',A2,' STATION= ',F9.2,' GROUND "
                   "ELEVATION= ',                F8.2,' STILLWATER ELEVATION= ',F8.2)");
            record.write(tof);
            record.write(param(1));
            record.write(param(2));
            record.write(se);
            record.finish();
        }
        goto L1000;
    }
    m = (m + 1);
    steg(m) = bsfo;
    elz(m) = ew(nfo);
    m = (m + 1);
    steg(m) = esfo;
    elz(m) = se;
    wht = 0;
    wpt = 0.1f;
    goto L250;
L240:
    esfo = param(1);
    eefo = param(2);
    setn = param(7);
    sen = param(8);
    gslb = gsle;
    wpi = wpt;
    whi = wht;
    gsle = param(9);
    if ((setn != 0)) {
        set = setn;
    }
    if ((sen != 0)) {
        se = sen;
    }
    if ((eefo > se)) {
        {
            auto record = io.writer(6, "(5X,46H GROUND ELEVATION GREATER THAN SURGE ELEVATION,1X,  "
                                       " 24HENCOUNTERED. JOB DUMPED.)");
            record.finish();
        }
    }
    if ((eefo > se)) {
        goto L1000;
    }
    ase = (wide((wide(sa(nfo, 4)) + wide(se))) / wide(2.0f));
    aeg = (wide((wide(befo) + wide(eefo))) / wide(2.0f));
    adf = (wide(ase) - wide(aeg));
    if ((adf <= 0)) {
        {
            auto record = io.writer(
                6, "(5X,42H AVERAGE DEPTH LESS THAN OR EQUAL TO ZERO.,1X,       11HJOB DUMPED.)");
            record.finish();
        }
    }
    if ((adf <= 0.f)) {
        {
            auto record = io.writer(6, "(/2X,'TOF= ',A2,2X,'STATION= ',F8.2/)");
            record.write(tof);
            record.write(param(1));
            record.finish();
        }
    }
    if ((adf <= 0)) {
        goto L1000;
    }
    test = false;
    w = windvh;
    veg(wpi, test, wpt, w);
    if (test) {
        goto L1000;
    }
    goto L5;
L250:
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
    gs(nfo) = esfo;
    sdeb = maximum(0.0f, (wide(se) - wide(eefo)));
    whm = shbm(wpt, gsle, sdeb);
    if (((tof == du) && (ammb != 0))) {
        whm = wht;
    }
    hbw(nfo) = minimum(wht, whm);
    stmp = (wide(eefo) + wide(sdeb));
    ew(nfo) = (wide((wide(.7f) * wide(hbw(nfo)))) + wide(stmp));
    if ((tof == as)) {
        ew(nfo) = eefo;
    }
    spwp(nfo) = wpt;
    sa(nfo, 1) = bsfo;
    sa(nfo, 2) = esfo;
    sa(nfo, 3) = set;
    sa(nfo, 4) = se;
    sa(nfo, 5) = tof;
    if ((param(10) != 1)) {
        goto L275;
    }
    nap = (nap + 1);
    ap(nap) = esfo;
    m = (m + 1);
    steg(m) = gs(nfo);
    elz(m) = ew(nfo);
L275:
    wht = hbw(nfo);
    bsfo = esfo;
    befo = eefo;
    goto L5;
L300:
    record_transect(std::string_view(title2));
    echo();
    {
        auto record = io.writer(6, "(///,48X,'PART2: CONTROLLING WAVE HEIGHTS, SPECTRAL '        "
                                   ",/55X,'PEAK WAVE PERIOD, AND WAVE CREST ELEVATIONS')");
        record.finish();
    }
    {
        auto record = io.writer(6, "(/,42X,10HLOCATION  ,6X,11HCONTROLLING,2X,                   "
                                   "14HSPECTRAL PEAK ,2X,10HWAVE CREST,/58X,11HWAVE HEIGHT,        "
                                   "   2X,14HWAVE PERIOD   ,2X,10HELEVATION )");
        record.finish();
    }
    limit_636 = nfo;
    for (i = 1; i <= limit_636; i += 1) {
        temp = sa(i, 5);
        if (((sa(i, 5) == 1.0f) || (sa(i, 5) == 2.0f))) {
            temp = word("  ");
        }
        if ((hbw(i) == 0.0f)) {
            spwp(i) = 0.0f;
        }
        {
            auto record = io.writer(6, "(/,40X,A2,F11.2,3F13.2)");
            record.write(temp);
            record.write(gs(i));
            record.write(hbw(i));
            record.write(spwp(i));
            record.write(ew(i));
            record.finish();
        };
    }
    if ((hbw(nfo) > .5f)) {
        {
            auto record = io.writer(
                6, "(5X,40HTRANSMITTED WAVE HEIGHT AT LAST FETCH OR,1X,         13HOBSTRUCTION "
                   "=F5.2,                                             19H WHICH EXCEEDS 0.5.)");
            record.write(hbw(nfo));
            record.finish();
        }
    }
    if (case500) {
        {
            auto record = io.writer(6, "(///,40X,44HPART3 LOCATION OF AREAS ABOVE 500-YEAR SURGE)");
            record.finish();
        }
    } else {
        {
            auto record = io.writer(6, "(///,40X,44HPART3 LOCATION OF AREAS ABOVE 100-YEAR SURGE)");
            record.finish();
        }
    }
    mm1 = (m - 1);
    if ((m == 0)) {
        goto L316;
    }
    limit_674 = nfo;
    for (i = 1; i <= limit_674; i += 1) {
        if ((sa(i, 5) == as)) {
            {
                auto record = io.writer(6, "(/,45X,7HBETWEEN,F10.2,1X,3HAND,F10.2)");
                record.write(sa(i, 1));
                record.write(sa(i, 2));
                record.finish();
            }
        };
    }
L316:
    if ((m == 0)) {
        if (case500) {
            {
                auto record =
                    io.writer(6, "(/,40X,46HNO AREAS ABOVE 500-YEAR SURGE IN THIS TRANSECT)");
                record.finish();
            }
        } else {
            {
                auto record =
                    io.writer(6, "(/,40X,46HNO AREAS ABOVE 100-YEAR SURGE IN THIS TRANSECT)");
                record.finish();
            }
        }
    }
    {
        auto record = io.writer(6, "(///,50X,31HPART4 LOCATION OF SURGE CHANGES)");
        record.finish();
    }
    if (case500) {
        {
            auto record =
                io.writer(6, "(/,40X,7HSTATION,10X,13H10-YEAR SURGE,10X,14H500-YEAR SURGE)");
            record.finish();
        }
    } else {
        {
            auto record =
                io.writer(6, "(/,40X,7HSTATION,10X,13H10-YEAR SURGE,10X,14H100-YEAR SURGE)");
            record.finish();
        }
    }
    nfom1 = (nfo - 1);
    limit_694 = nfom1;
    for (i = 1; i <= limit_694; i += 1) {
        if (((sa(i, 3) == sa((i + 1), 3)) && (sa(i, 4) == sa((i + 1), 4)))) {
            goto L318;
        }
        if (((sa(i, 5) == 1.0f) || (sa(i, 5) == 2.0f))) {
            goto L317;
        }
        m = (m + 1);
        steg(m) = gs(i);
        elz(m) = ew(i);
    L317:
        if (((sa((i + 1), 5) == 1.0f) || (sa((i + 1), 5) == 2.0f))) {
            goto L318;
        }
        m = (m + 1);
        steg(m) = gs((i + 1));
        elz(m) = ew((i + 1));
        {
            auto record = io.writer(6, "(/,35X,F11.2,10X,F11.2,10X,F11.2)");
            record.write(steg(m));
            record.write(sa((i + 1), 3));
            record.write(sa((i + 1), 4));
            record.finish();
        }
    L318:;
    }
    if (((m - 1) == mm1)) {
        {
            auto record = io.writer(6, "(/,50X,33HNO SURGE CHANGES IN THIS TRANSECT)");
            record.finish();
        }
    }
    limit_711 = nfom1;
    for (i = 1; i <= limit_711; i += 1) {
        test = false;
        slope =
            (wide((wide(hbw((i + 1))) - wide(hbw(i)))) / wide((wide(gs((i + 1))) - wide(gs(i)))));
        if (((i == 1) && (hbw(1) != 3))) {
            goto L319;
        }
        if ((i != 1)) {
            goto L319;
        }
        n = (n + 1);
        m = (m + 1);
        stvg(n) = gs(1);
        steg(m) = gs(1);
        elz(m) = ew(1);
        test = true;
    L319:
        if ((slope == 0)) {
            goto L320;
        }
        if ((hbw(1) == 3)) {
            goto L325;
        }
        x = (wide((wide((wide(3) - wide(hbw(i)))) / wide(slope))) + wide(gs(i)));
        if (((x <= gs(i)) || (x > gs((i + 1))))) {
            goto L330;
        }
        n = (n + 1);
        m = (m + 1);
        stvg(n) = x;
        steg(m) = x;
        elz(m) = (wide(2.1f) + wide((wide((wide(sa(i, 4)) + wide(sa((i + 1), 4)))) / wide(2.0f))));
        test = true;
    L320:
        if (((hbw(i) != 3) && (hbw((i + 1)) != 3))) {
            goto L325;
        }
        n = (n + 1);
        stvg(n) = gs((i + 1));
        test = true;
    L325:
        if ((test && (slope > 0))) {
            vzne(n) = blee;
        }
        if ((test && (slope <= 0))) {
            vzne(n) = wind;
        }
    L330:;
    }
    if ((n == 0)) {
        goto L336;
    }
    {
        auto record = io.writer(6, "(///,55X,26HPART5  LOCATION OF V ZONES)");
        record.finish();
    }
    {
        auto record = io.writer(
            6, "(/,45X,17HSTATION OF GUTTER,10X,                            16HLOCATION OF ZONE)");
        record.finish();
    }
    limit_745 = n;
    for (i = 1; i <= limit_745; i += 1) {
        {
            auto record = io.writer(6, "(/,45X,F15.2,15X,2A4)");
            record.write(stvg(i));
            record.write(vzne(i));
            record.write(ward);
            record.finish();
        };
    }
L336:
    limit_752 = nfom1;
    for (i = 1; i <= limit_752; i += 1) {
        big = maximum(ew(i), ew((i + 1)));
        small = minimum(ew(i), ew((i + 1)));
        itrnk = integer(small);
        tst = (wide(small) - wide(itrnk));
        if ((tst < .5f)) {
            gtst = (wide(real(itrnk)) + wide(.5f));
        }
        if ((tst > .5f)) {
            gtst = (wide(real(itrnk)) + wide(1.5f));
        }
        if ((tst == .5f)) {
            gtst = small;
        }
    L340:
        if ((gtst > big)) {
            goto L370;
        }
        test = false;
        slope = (wide((wide(ew((i + 1))) - wide(ew(i)))) / wide((wide(gs((i + 1))) - wide(gs(i)))));
        if ((slope == 0)) {
            goto L370;
        }
        m = (m + 1);
        steg(m) = (wide((wide((wide(gtst) - wide(ew(i)))) / wide(slope))) + wide(gs(i)));
        elz(m) = gtst;
        gtst = (wide(gtst) + wide(1.0f));
        goto L340;
    L370:;
    }
    m = (m + 1);
    steg(m) = gs(1);
    elz(m) = ew(1);
    m = (m + 1);
    steg(m) = gs(nfo);
    elz(m) = ew(nfo);
    limit_781 = m;
    for (i = 1; i <= limit_781; i += 1) {
        save(i) = steg(i);
        ;
    }
    mm1 = (m - 1);
    limit_788 = m;
    for (j = 1; j <= limit_788; j += 1) {
        limit_789 = mm1;
        for (i = 1; i <= limit_789; i += 1) {
            small = minimum(steg(i), steg((i + 1)));
            big = maximum(steg(i), steg((i + 1)));
            steg(i) = small;
            steg((i + 1)) = big;
            ;
        };
    }
    limit_799 = m;
    for (j = 1; j <= limit_799; j += 1) {
        limit_800 = m;
        for (i = 1; i <= limit_800; i += 1) {
            if ((save(i) == steg(j))) {
                ns = i;
            };
        }
        selz(j) = elz(ns);
        ;
    }
    {
        auto record = io.writer(6, "(///,51X,34HPART6 NUMBERED A ZONES AND V ZONES)");
        record.finish();
    }
    {
        auto record = io.writer(6, "(/,40X,17HSTATION OF GUTTER,2X,9HELEVATION,2X,              "
                                   "16HZONE DESIGNATION,3X,3HFHF,/)");
        record.finish();
    }
    limit_813 = nfo;
    for (i1 = 1; i1 <= limit_813; i1 += 1) {
        limit_814 = m;
        for (i2 = 1; i2 <= limit_814; i2 += 1) {
            if ((sa(i1, 5) != as)) {
                goto L396;
            }
            if (((steg(i2) > sa(i1, 1)) && (steg(i2) < sa(i1, 2)))) {
                steg(i2) = (-10.0f);
            }
        L396:;
        };
    }
    limit_822 = mm1;
    for (i = 1; i <= limit_822; i += 1) {
        if ((steg(((m - i) + 1)) == steg((m - i)))) {
            steg(((m - i) + 1)) = (-10);
        };
    }
    limit_828 = m;
    for (j = 1; j <= limit_828; j += 1) {
        nse(j) = 0;
        limit_830 = nfom1;
        for (i = 1; i <= limit_830; i += 1) {
            if (((steg(j) >= gs(i)) && (steg(j) < gs((i + 1))))) {
                nse(j) = i;
            };
        };
    }
    if ((steg(m) == gs(nfo))) {
        nse(m) = nfom1;
    }
    k = 0;
    if ((n != 0)) {
        goto L425;
    }
    if ((hbw(1) > 3.0f)) {
        goto L445;
    }
    k = 1;
    sbp(k) = gs(1);
    sep(k) = gs(nfo);
    goto L445;
L425:
    if ((vzne(1) == wind)) {
        goto L430;
    }
    k = 1;
    sbp(k) = gs(1);
    sep(k) = stvg(1);
L430:
    limit_851 = n;
    for (i = 1; i <= limit_851; i += 1) {
        if ((vzne(i) == blee)) {
            goto L440;
        }
        k = (k + 1);
        sbp(k) = stvg(i);
        if ((i == n)) {
            sep(k) = gs(nfo);
        }
        if ((i == n)) {
            goto L440;
        }
        sep(k) = stvg((i + 1));
    L440:;
    }
L445:
    {
        auto record = io.writer(6, "(/,35X,F16.2,F15.2,/)");
        record.write(gs(1));
        record.write(ew(1));
        record.finish();
    }
    limit_865 = mm1;
    for (i = 1; i <= limit_865; i += 1) {
        if ((steg(i) == (-10))) {
            goto L500;
        }
        index = (i + 1);
    L450:
        if ((index > m)) {
            goto L500;
        }
        if (((index == m) && (steg(index) == (-10)))) {
            goto L500;
        }
        if ((steg(index) == (-10))) {
            index = (index + 1);
        }
        if ((steg(index) == (-10))) {
            goto L450;
        }
        indx = (nse(i) + 1);
        if (((sa(indx, 5) == as) && (sa(indx, 1) == steg(i)))) {
            {
                auto record = io.writer(6, "(/,35X,F16.2,F15.2,/)");
                record.write(steg(index));
                record.write(selz(index));
                record.finish();
            }
        }
        if (((sa(indx, 5) == as) && (sa(indx, 1) == steg(i)))) {
            goto L500;
        }
        azone = false;
        vzone = false;
        if ((k == 0)) {
            goto L460;
        }
        limit_885 = k;
        for (j = 1; j <= limit_885; j += 1) {
            if (((steg(i) >= sbp(j)) && (steg(i) < sep(j)))) {
                azone = true;
            }
            if (((steg(i) >= sbp(j)) && (steg(i) < sep(j)))) {
                indx = j;
            };
        }
        if (azone) {
            goto L462;
        }
    L460:
        vzone = true;
        tsg1 = (wide(sa(nse(i), 3)) + wide(sa((nse(i) + 1), 3)));
        tsg2 = (wide(sa(nse(index), 3)) + wide(sa((nse(index) + 1), 3)));
        hsg1 = (wide(sa(nse(i), 4)) + wide(sa((nse(i) + 1), 4)));
        hsg2 = (wide(sa(nse(index), 4)) + wide(sa((nse(index) + 1), 4)));
        tsg = (wide((wide(tsg1) + wide(tsg2))) / wide(4.0f));
        hsg = (wide((wide(hsg1) + wide(hsg2))) / wide(4.0f));
        diff = (wide(1.55f) * wide((wide(hsg) - wide(tsg))));
        goto L470;
    L462:
        bp = sbp(indx);
        ep = sep(indx);
        start = bp;
        stop = ep;
        if ((nap == 0)) {
            goto L468;
        }
        limit_904 = nap;
        for (j = 1; j <= limit_904; j += 1) {
            if (((ap(j) > bp) && (ap(j) <= steg(i)))) {
                start = ap(j);
            };
        }
        j = nap;
    L465:
        if (((ap(j) >= steg(index)) && (ap(j) < ep))) {
            goto L466;
        }
        if ((j == 1)) {
            goto L468;
        }
        j = (j - 1);
        goto L465;
    L466:
        stop = ap(j);
    L468:
        avg(start, stop, aer, ats);
        diff = (wide(aer) - wide(ats));
    L470:
        bp = steg(i);
        ep = steg(index);
        avg(bp, ep, aer, ats);
        itrnk = integer(aer);
        tst = (wide(aer) - wide(itrnk));
        if ((tst < .5f)) {
            ielz = itrnk;
        }
        if ((tst >= .5f)) {
            ielz = (itrnk + 1);
        }
        if (((diff >= 0) && (diff < .75f))) {
            insz = 1;
        }
        beg = .75f;
        limit_924 = 19;
        for (i1 = 2; i1 <= limit_924; i1 += 1) {
            end = (wide(beg) + wide(.5f));
            if (((diff >= beg) && (diff < end))) {
                insz = i1;
            }
            beg = (wide(beg) + wide(.5f));
            ;
        }
        if (((diff >= 9.75f) && (diff < 10.5f))) {
            insz = 20;
        }
        beg = 10.5f;
        limit_931 = 30;
        for (i1 = 21; i1 <= limit_931; i1 += 1) {
            end = (wide(beg) + wide(1.0f));
            if (((diff >= beg) && (diff < end))) {
                insz = i1;
            }
            beg = (wide(beg) + wide(1.0f));
            ;
        }
        if ((diff >= 20.5f)) {
            insz = 30;
        }
        if ((insz <= 20)) {
            ifhf = (5 * insz);
        }
        if ((insz > 20)) {
            ifhf = (100 + (10 * (insz - 20)));
        }
        if (azone) {
            {
                auto record = io.writer(6, "(74X,1HA,I2,2X,3HEL=,I2,5X,I3)");
                record.write(insz);
                record.write(ielz);
                record.write(ifhf);
                record.finish();
            }
        }
        if (vzone) {
            {
                auto record = io.writer(6, "(74X,1HV,I2,2X,3HEL=,I2,5X,I3)");
                record.write(insz);
                record.write(ielz);
                record.write(ifhf);
                record.finish();
            }
        }
        {
            auto record = io.writer(6, "(/,35X,F16.2,F15.2,/)");
            record.write(steg(index));
            record.write(selz(index));
            record.finish();
        }
    L500:;
    }
    {
        auto record = io.writer(6, "(//,50X,34HZONE TERMINATED AT END OF TRANSECT)");
        record.finish();
    }
    {
        auto record = io.writer(6, "(///,50X,25HPART 7   POSTSCRIPT NOTES,//)");
        record.finish();
    }
    limit_945 = pscount;
    for (i = 1; i <= limit_945; i += 1) {
        {
            auto record = io.writer(6, "(25X,'PS# ', I2, '  ', A78)");
            record.write(i);
            record.write(psline(i));
            record.finish();
        };
    }
L505:
    {
        auto record = io.reader(10, "(a80)");
        record.read(title2);
        record.finish();
    }
    test = false;
    if ((trimmed_length(title2) == 0)) {
        test = true;
    }
    if (test) {
        goto L1010;
    }
    goto L4;
L1000:
    {
        auto record = io.reader(10, "(A2,78A1)");
        record.read(tof);
        for (i = 1; i <= 78; ++i) {
            record.read(title(i));
        }
        record.finish();
    }
    if ((tof != et)) {
        goto L1000;
    }
    goto L505;
L1010:;
}
} // namespace legacy::whafis::detail
