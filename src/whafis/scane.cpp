// Port of WHAFIS4G.FOR: SCANE. Source labels support differential review.
#include "engine.hpp"
namespace legacy::whafis::detail {
void Engine::scane() {
    float bel{};
    float bfo{};
    float blank = word(" ");
    float bsen{};
    float d{};
    float ddsg{};
    float dsg{};
    float dx{};
    float eel{};
    float efo{};
    Array<float, 2> elmx{};
    float esen{};
    float high{};
    int i{};
    int itemp{};
    int j{};
    int ja{};
    int jb{};
    Array<int, 2> jm{};
    int jmb{};
    int jp{};
    int k{};
    int kk{};
    int kplts{};
    int linecount{};
    int nb{};
    int ne{};
    int nfo{};
    int nk{};
    int nmb{};
    int nme{};
    int nplts{};
    int nvh{};
    int nvh1{};
    int nvh2{};
    Array<float, 1000, 10> param{};
    float sa{};
    float sb{};
    Array<float, 1000> sgnew{};
    Array<float, 1000> sgold{};
    float ss{};
    bool test{};
    bool test1{};
    Text<80> title2{};
    Array<Text<2>, 1000> tof{};
    Text<2> toff{};
    float wif100 = 60.0f;
    float wif500 = 75.0f;
    float wof100 = 80.0f;
    float wof500 = 100.0f;
    float wvh100 = 60.0f;
    float wvh500 = 75.0f;
    int limit_3829{};
    int limit_3851{};
    int limit_3939{};
    int limit_4070{};
    int limit_4087{};
    int limit_4114{};
    int limit_4158{};
    int limit_4177{};
    int limit_4194{};
    int limit_4214{};
    int limit_4230{};
    int limit_4243{};
    int limit_4270{};
    int limit_4282{};
    int limit_4300{};
    int limit_4312{};
    int limit_4327{};
    int limit_4485{};
    nplts = 0;
    nvh = 0;
    nvh1 = 0;
    nvh2 = 0;
    io.rewind(5);
L1:
    {
        auto record = io.reader(5, "(a80)");
        record.read(title2);
        record.finish();
    }
    test = false;
    if ((trimmed_length(title2) == 0)) {
        test = true;
    }
    test1 = true;
    if (test) {
        {
            auto record = io.writer(10, "(80A1)");
            record.write(blank);
            record.finish();
        }
        io.rewind(10);
        return;
    }
    wwndif = wif100;
    wwndof = wof100;
    wwndvh = wvh100;
    code500 = title2.slice(1, 5);
    case500 = false;
    if ((trim(code500) == trim(":500:"))) {
        case500 = true;
        wwndif = wif500;
        wwndof = wof500;
        wwndvh = wvh500;
    }
    {
        auto record = io.reader(5, "(A2,F6.0,9F8.0)");
        record.read(tof(1));
        for (i = 1; i <= 10; ++i) {
            record.read(param(1, i));
        }
        record.finish();
    }
    windif = param(1, 8);
    windof = param(1, 9);
    windvh = param(1, 10);
    if ((windif == 0.0f)) {
        windif = wwndif;
    }
    if ((windof == 0.0f)) {
        windof = wwndof;
    }
    if ((windvh == 0.0f)) {
        windvh = wwndvh;
    }
    nb = 1;
    if ((trim(tof(1)) != trim("IE"))) {
        {
            auto record = io.writer(6, "(10X,'  THE FIRST CARD IS NOT AN IE CARD, THIS'            "
                                       " ' TRANSECT IS ABORTED.  CONTINUED TO NEXT TRANSECT'/)");
            record.finish();
        }
        limit_3829 = 1000;
        for (j = 1; j <= limit_3829; j += 1) {
            {
                auto record = io.reader(5, "(A2,F6.0,9F8.0)");
                record.read(tof(j));
                record.finish();
            }
            if ((trim(tof(j)) == trim("ET"))) {
                goto L1;
            };
        }
    }
    bfo = param(1, 1);
    bel = param(1, 2);
    bsen = param(1, 5);
    sgold(1) = bsen;
    sgnew(1) = bsen;
    if ((bel > bsen)) {
        {
            auto record = io.writer(6, "(5X,'GROUND ELEVATION GREATER THAN STILLWATER ELEVATION '  "
                                       " 'ON THE IE CARD. JOB DUMPED.'/)");
            record.finish();
        }
        limit_3851 = 1000;
        for (j = 1; j <= limit_3851; j += 1) {
            {
                auto record = io.reader(5, "(A2,F6.0,9F8.0)");
                record.read(tof(j));
                record.finish();
            }
            if ((trim(tof(j)) == trim("ET"))) {
                goto L1;
            };
        }
    }
    cmcount = 0;
    pscount = 0;
    nfo = 1;
    linecount = 2;
L5:
    nfo = (nfo + 1);
    {
        auto record = io.reader(5, "(a2, a78)");
        record.read(toff);
        record.read(cmstring);
        record.finish();
    }
    linecount = (linecount + 1);
    if ((trim(toff) == trim("CM"))) {
        cmcount = (cmcount + 1);
        cmline(cmcount) = cmstring;
        nfo = (nfo - 1);
        goto L5;
    } else if ((trim(toff) == trim("PS"))) {
        pscount = (pscount + 1);
        psline(pscount) = cmstring;
        nfo = (nfo - 1);
        goto L5;
    } else {
        {
            auto record = io.reader(cmstring, "(F6.0,9F8.0)");
            for (i = 1; i <= 10; ++i) {
                record.read(param(nfo, i));
            }
            record.finish();
        }
        tof(nfo) = toff;
    }
    efo = param(nfo, 1);
    eel = param(nfo, 2);
    if ((trim(tof(nfo)) == trim("DU"))) {
        goto L50;
    }
    if ((trim(tof(nfo)) == trim("BU"))) {
        goto L100;
    }
    if (((trim(tof(nfo)) == trim("VE")) || (trim(tof(nfo)) == trim("VH")))) {
        goto L150;
    }
    if (((trim(tof(nfo)) == trim("IF")) || (trim(tof(nfo)) == trim("OF")))) {
        goto L200;
    }
    if ((trim(tof(nfo)) == trim("AS"))) {
        goto L250;
    }
    if ((trim(tof(nfo)) == trim("ET"))) {
        ne = nfo;
        goto L400;
    }
L50:
    esen = param(nfo, 5);
    goto L350;
L100:
    esen = param(nfo, 6);
    goto L350;
L150:
    esen = param(nfo, 8);
    if ((trim(tof(nfo)) == trim("VE"))) {
        goto L350;
    }
    high = maximum(bsen, esen);
    if ((eel > high)) {
        {
            auto record = io.writer(
                6,
                "(10X,'****  THE STILLWATER ELEVATION (BEFORE',                   ' INTERPOLATION) "
                "AT',                                             '  STATION=',F8.0,' ,  WHICH IS "
                "ON AN ',A2,' CARD,'/,         10X,' IS LESS THAN THE GROUND ELEVATION.'/          "
                "              10X,'THE INTERPOLATION PROCESS WAS CONTINUED.'/)");
            record.write(efo);
            record.write(tof(nfo));
            record.finish();
        }
    }
    sgold(nfo) = esen;
    sgnew(nfo) = esen;
    if ((esen == 0.f)) {
        sgold(nfo) = sgold((nfo - 1));
        sgnew(nfo) = sgold(nfo);
    }
    kplts = nplts;
    nplts = param(nfo, 6);
    limit_3939 = nplts;
    for (i = 1; i <= limit_3939; i += 1) {
    L154:
        {
            auto record = io.reader(5, "(A2,A78)");
            record.read(toff);
            record.read(cmstring);
            record.finish();
        }
        linecount = (linecount + 1);
        if ((trim(toff) == trim("CM"))) {
            cmcount = (cmcount + 1);
            cmline(cmcount) = cmstring;
            goto L154;
        } else if ((trim(toff) == trim("PS"))) {
            pscount = (pscount + 1);
            psline(pscount) = cmstring;
            goto L154;
        }
        nfo = (nfo + 1);
        {
            auto record = io.reader(cmstring, "(2X,A4,9F8.0)");
            for (k = 1; k <= 10; ++k) {
                record.read(param(nfo, k));
            }
            record.finish();
        }
        tof(nfo) = toff;
        sgold(nfo) = sgold((nfo - 1));
        sgnew(nfo) = sgold(nfo);
        ;
    }
    if ((esen != 0.f)) {
        nvh = 1;
        ne = (nfo - nplts);
        if ((ne == 2)) {
            nvh1 = ne;
            goto L400;
        }
    }
    if ((nvh == 1)) {
        nvh = 0;
        nvh2 = ((nfo - nplts) - kplts);
        if ((nvh2 == (nvh1 + 1))) {
            nvh1 = ne;
            goto L400;
        }
        nvh1 = ne;
    }
    if ((esen == 0.f)) {
        goto L5;
    }
    goto L351;
L200:
    esen = param(nfo, 4);
    goto L350;
L250:
    esen = param(nfo, 4);
    ne = nfo;
    if ((esen == 0.f)) {
        sgold(nfo) = sgold((nfo - 1));
        sgnew(nfo) = sgold(nfo);
    } else {
        sgold(nfo) = esen;
        sgnew(nfo) = esen;
    }
    goto L400;
L350:;
    high = maximum(bsen, esen);
    if ((eel > high)) {
        {
            auto record = io.writer(
                6,
                "(10X,'****  THE STILLWATER ELEVATION (BEFORE',                   ' INTERPOLATION) "
                "AT',                                             '  STATION=',F8.0,' ,  WHICH IS "
                "ON AN ',A2,' CARD,'/,         10X,' IS LESS THAN THE GROUND ELEVATION.'/          "
                "              10X,'THE INTERPOLATION PROCESS WAS CONTINUED.'/)");
            record.write(efo);
            record.write(tof(nfo));
            record.finish();
        }
        {
            auto record = io.writer(
                6, "( 10X, 'THIS IS ',                                             'A WARNING "
                   "(I.E. INFORMATIONAL) MESSAGE ONLY.'/                   10X,'NO ERROR WAS FOUND "
                   "BUT THE INPUT LOOKS SUSPICIOUS.'//         5X,'***  PLEASE DOUBLE-CHECK THE "
                   "STILLWATER AND GROUND',             ' ELEVATIONS IN THE VICINITY OF THIS "
                   "STATION',                    ' !!!!!!'//)");
            record.finish();
        }
    }
    sgold(nfo) = esen;
    sgnew(nfo) = esen;
    if ((esen == 0.f)) {
        sgold(nfo) = sgold((nfo - 1));
        sgnew(nfo) = sgold(nfo);
        goto L5;
    }
    ne = nfo;
L351:
    dx = (wide(efo) - wide(bfo));
    dsg = (wide(esen) - wide(bsen));
    ddsg = (wide(dsg) / wide(dx));
    nme = (ne - 1);
    nmb = (nb + 1);
    if ((nme < nmb)) {
        goto L400;
    }
    limit_4070 = nme;
    for (j = nmb; j <= limit_4070; j += 1) {
        if ((trim(tof(j)) == trim("MG"))) {
            sgnew(j) = sgnew((j - 1));
        } else {
            sgnew(j) =
                (wide(sgold(j)) + wide((wide(ddsg) * wide((wide(param(j, 1)) - wide(bfo))))));
        };
    }
    nk = 0;
    elmx(1) = 0.f;
    elmx(2) = 0.f;
    test1 = true;
    limit_4087 = nme;
    for (j = nmb; j <= limit_4087; j += 1) {
        if ((trim(tof(j)) == trim("MG"))) {
            goto L370;
        }
        if ((sgnew(j) >= param(j, 2))) {
            goto L365;
        }
        if (test1) {
            nk = (nk + 1);
            test1 = false;
        }
        if ((nk > 2)) {
            if (case500) {
                {
                    auto record =
                        io.writer(6, "(10X,'INTERPOLATION LINE CUTS OFF MORE THAN',                "
                                     " ' TWO PORTIONS OF HIGH GROUND RIDGE'//,                     "
                                     "     10X,'THIS TRANSECT IS ABORTED, RE-ASSIGN 500-YR ',      "
                                     "              'ELEVATIONS AT HIGH GROUND STATIONS'///)");
                    record.finish();
                }
            } else {
                {
                    auto record =
                        io.writer(6, "(10X,'INTERPOLATION LINE CUTS OFF MORE THAN',                "
                                     " ' TWO PORTIONS OF HIGH GROUND RIDGE'//,                     "
                                     "     10X,'THIS TRANSECT IS ABORTED, RE-ASSIGN 100-YR ',      "
                                     "              'ELEVATIONS AT HIGH GROUND STATIONS'///)");
                    record.finish();
                }
            }
            limit_4114 = 1000;
            for (i = 1; i <= limit_4114; i += 1) {
                {
                    auto record = io.reader(5, "(A2,F6.0,9F8.0)");
                    record.read(tof(i));
                    record.finish();
                }
                if ((trim(tof(i)) == trim("ET"))) {
                    goto L1;
                };
            }
        }
        if ((param(j, 2) >= elmx(nk))) {
            elmx(nk) = param(j, 2);
            jm(nk) = j;
        }
        goto L370;
    L365:
        test1 = true;
    L370:;
    }
    if ((nk == 0)) {
        goto L400;
    }
    if ((dsg > 0.f)) {
        goto L600;
    }
    if ((nk == 1)) {
        goto L380;
    }
    if ((param(jm(2), 2) < param(jm(1), 2))) {
        goto L390;
    }
    jm(1) = jm(2);
L380:
    limit_4158 = jm(1);
    for (j = nmb; j <= limit_4158; j += 1) {
        sgnew(j) = bsen;
        if ((trim(tof(j)) == trim("MG"))) {
            goto L373;
        }
        if ((sgnew(j) >= param(j, 2))) {
            goto L373;
        }
        {
            auto record = io.writer(
                6, "(//10X,'****  UNREASONABLE HIGH GROUND ELEVATION',             ' AT STATION "
                   "(',F8.2,' ) WHICH IS ',A2,' CARD.'/,10X,             'THIS TRANSECT IS "
                   "ABORTED, CONTINUED TO NEXT TRANSECT'//,          10X,'***  DOUBLE-CHECK THE "
                   "STILLWATER AND GROUND ELEVATIONS',         ' IN THE VICINITY OF THIS STATION.  "
                   "IF THE GROUND'/,          15X,' ELEVATIONS ARE CORRECT, EITHER ASSIGN A "
                   "HIGHER',                ' STILLWATER ELEVATION OR USE AS CARDS !!!!'//)");
            record.write(param(j, 1));
            record.write(tof(j));
            record.finish();
        }
        limit_4177 = 1000;
        for (kk = 1; kk <= limit_4177; kk += 1) {
            {
                auto record = io.reader(5, "(A2,F6.0,9F8.0)");
                record.read(tof(kk));
                record.finish();
            }
            if ((trim(tof(kk)) == trim("ET"))) {
                goto L1;
            };
        }
    L373:;
    }
    d = (wide(sgnew(jm(1))) - wide(param(jm(1), 2)));
    jmb = (jm(1) + 1);
    limit_4194 = nme;
    for (j = jmb; j <= limit_4194; j += 1) {
        if ((trim(tof(j)) == trim("MG"))) {
            sgnew(j) = sgnew((j - 1));
        } else {
            sgnew(j) = maximum((wide(param(j, 2)) + wide(d)), esen);
        };
    }
    goto L400;
L390:;
    limit_4214 = jm(1);
    for (j = nmb; j <= limit_4214; j += 1) {
        sgnew(j) = bsen;
        if ((sgnew(j) >= param(j, 2))) {
            goto L393;
        }
        {
            auto record = io.writer(
                6, "(//10X,'****  UNREASONABLE HIGH GROUND ELEVATION',             ' AT STATION "
                   "(',F8.2,' ) WHICH IS ',A2,' CARD.'/,10X,             'THIS TRANSECT IS "
                   "ABORTED, CONTINUED TO NEXT TRANSECT'//,          10X,'***  DOUBLE-CHECK THE "
                   "STILLWATER AND GROUND ELEVATIONS',         ' IN THE VICINITY OF THIS STATION.  "
                   "IF THE GROUND'/,          15X,' ELEVATIONS ARE CORRECT, EITHER ASSIGN A "
                   "HIGHER',                ' STILLWATER ELEVATION OR USE AS CARDS !!!!'//)");
            record.write(param(j, 1));
            record.write(tof(j));
            record.finish();
        }
    L393:;
    }
    d = (wide(sgnew(jm(1))) - wide(param(jm(1), 2)));
    dx = (wide(efo) - wide(param(jm(1), 1)));
    ddsg = (wide((wide(esen) - wide(bsen))) / wide(dx));
    jmb = (jm(1) + 1);
    limit_4230 = nme;
    for (j = jmb; j <= limit_4230; j += 1) {
        if ((trim(tof(j)) == trim("MG"))) {
            sgnew(j) = sgnew((j - 1));
        } else {
            sgnew(j) = (wide(sgold(j)) +
                        wide((wide(ddsg) * wide((wide(param(j, 1)) - wide(param(jm(1), 1)))))));
        };
    }
    limit_4243 = nme;
    for (j = jmb; j <= limit_4243; j += 1) {
        if ((trim(tof(j)) == trim("MG"))) {
            sgnew(j) = sgnew((j - 1));
        } else {
            sgnew(j) = maximum(sgnew(j), (wide(param(j, 2)) + wide(d)), esen);
        };
    }
    goto L400;
L600:;
    if ((nk == 1)) {
        goto L605;
    }
    if ((param(jm(1), 2) < param(jm(2), 2))) {
        goto L620;
    }
L605:;
    limit_4270 = nme;
    for (j = jm(1); j <= limit_4270; j += 1) {
        sgnew(j) = esen;
        ;
    }
    d = (wide(sgnew(jm(1))) - wide(param(jm(1), 2)));
    jp = (jm(1) - 1);
    limit_4282 = jp;
    for (j = nmb; j <= limit_4282; j += 1) {
        if ((trim(tof(j)) == trim("MG"))) {
            sgnew(j) = sgnew((j - 1));
        } else {
            sgnew(j) = maximum((wide(param(j, 2)) + wide(d)), bsen);
        };
    }
    goto L400;
L620:;
    limit_4300 = nme;
    for (j = jm(2); j <= limit_4300; j += 1) {
        sgnew(j) = esen;
        ;
    }
    d = (wide(sgnew(jm(2))) - wide(param(jm(2), 2)));
    dx = (wide(param(jm(2), 1)) - wide(bfo));
    ddsg = (wide((wide(esen) - wide(bsen))) / wide(dx));
    jp = (jm(2) - 1);
    limit_4312 = jp;
    for (j = nmb; j <= limit_4312; j += 1) {
        if ((trim(tof(j)) == trim("MG"))) {
            sgnew(j) = sgnew((j - 1));
        } else {
            sgnew(j) = (wide(esen) +
                        wide((wide(ddsg) * wide((wide(param(j, 1)) - wide(param(jm(2), 1)))))));
        };
    }
    jp = (jm(2) - 1);
    limit_4327 = jp;
    for (j = nmb; j <= limit_4327; j += 1) {
        if ((trim(tof(j)) == trim("MG"))) {
            sgnew(j) = sgnew((j - 1));
        } else {
            sgnew(j) = maximum(sgnew(j), (wide(param(j, 2)) + wide(d)), bsen);
        };
    }
L400:
    if ((nb != 1)) {
        goto L402;
    }
    {
        auto record = io.writer(10, "(a80)");
        record.write(title2);
        record.finish();
    }
L402:;
    j = nb;
L410:
    j = (j + 1);
    if ((trim(tof(j)) == trim("MG"))) {
        goto L410;
    }
    if ((trim(tof(j)) == trim("DU"))) {
        goto L450;
    }
    if ((trim(tof(j)) == trim("BU"))) {
        goto L460;
    }
    if (((trim(tof(j)) == trim("VE")) || (trim(tof(j)) == trim("VH")))) {
        goto L470;
    }
    if (((trim(tof(j)) == trim("IF")) || (trim(tof(j)) == trim("OF")))) {
        goto L480;
    }
    if ((trim(tof(j)) == trim("AS"))) {
        goto L480;
    }
    goto L490;
L450:
    param(j, 5) = sgnew(j);
    goto L490;
L460:
    param(j, 6) = sgnew(j);
    goto L490;
L470:
    param(j, 8) = sgnew(j);
    goto L490;
L480:
    param(j, 4) = sgnew(j);
L490:
    if ((trim(tof(j)) == trim("ET"))) {
        goto L700;
    }
    if ((j == ne)) {
        bsen = sgnew(j);
        bfo = param(j, 1);
        nb = ne;
        goto L5;
    } else {
        goto L410;
    }
L700:;
    j = 2;
    sa = (wide((wide(param(j, 2)) - wide(param((j - 1), 2)))) /
          wide((wide(param(j, 1)) - wide(param((j - 1), 1)))));
    param((j - 1), 9) = sa;
    ja = (j - 1);
    jb = (j + 1);
L705:
    if ((trim(tof(jb)) == trim("AS"))) {
        param(j, 9) = sa;
        goto L720;
    }
    if ((trim(tof(j)) == trim("VH"))) {
        nplts = param(j, 6);
        jb = (jb + nplts);
    }
    if ((trim(tof(jb)) == trim("ET"))) {
        param(j, 9) = sa;
        goto L770;
    }
    sb = (wide((wide(param(jb, 2)) - wide(param(j, 2)))) /
          wide((wide(param(jb, 1)) - wide(param(j, 1)))));
    if ((trim(tof(j)) == trim("AS"))) {
        param(j, 9) = sb;
        goto L710;
    }
    ss = (wide((wide((wide(param(j, 1)) - wide(param(ja, 1)))) * wide(sa))) +
          wide((wide((wide(param(jb, 1)) - wide(param(j, 1)))) * wide(sb))));
    param(j, 9) = (wide(ss) / wide((wide(param(jb, 1)) - wide(param(ja, 1)))));
L710:
    sa = sb;
    if ((trim(tof(j)) == trim("VH"))) {
        ja = j;
        j = jb;
        jb = (j + 1);
        goto L705;
    }
L720:
    j = (j + 1);
    ja = (j - 1);
    jb = (j + 1);
    goto L705;
L770:;
    limit_4485 = 1000;
    for (j = 1; j <= limit_4485; j += 1) {
        if ((trim(tof(j)) == trim("MG"))) {
            {
                auto record = io.writer(10, "(A2,2X,A4,9F8.2)");
                record.write(tof(j));
                for (i = 1; i <= 10; ++i) {
                    record.write(param(j, i));
                }
                record.finish();
            }
        } else {
            if ((param(j, 1) > 99999.f)) {
                itemp = integer(param(j, 1));
                {
                    auto record = io.writer(10, "(A2,I7,  7F8.3,F8.4,F8.3)");
                    record.write(tof(j));
                    record.write(itemp);
                    for (i = 2; i <= 10; ++i) {
                        record.write(param(j, i));
                    }
                    record.finish();
                }
            } else {
                {
                    auto record = io.writer(10, "(A2,F7.1,7F8.3,F8.4,F8.3)");
                    record.write(tof(j));
                    for (i = 1; i <= 10; ++i) {
                        record.write(param(j, i));
                    }
                    record.finish();
                }
            }
        }
        if ((trim(tof(j)) == trim("ET"))) {
            goto L1;
        };
    }
}
} // namespace legacy::whafis::detail
