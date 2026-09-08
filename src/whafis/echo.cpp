// Port of WHAFIS4G.FOR: ECHO. Source labels support differential review.
#include "engine.hpp"
namespace legacy::whafis::detail {
void Engine::echo() {
    float as = word("AS");
    float bu = word("BU");
    float du = word("DU");
    float ei = word("IE");
    float et = word("ET");
    float fi = word("IF");
    float fo = word("OF");
    int i{};
    int j{};
    int nplts{};
    Array<float, 10> param{};
    float tof{};
    float type{};
    float ve = word("VE");
    float vh = word("VH");
    int limit_2974{};
    int limit_2983{};
    io.rewind(8);
    io.rewind(9);
    {
        auto record = io.writer(6, "(1H1)");
        record.finish();
    }
L10:
    {
        auto record = io.reader(8, "(10X,A2,10F11.3)");
        record.read(tof);
        for (i = 1; i <= 10; ++i) {
            record.read(param(i));
        }
        record.finish();
    }
    if ((tof == ei)) {
        goto L50;
    }
    if ((tof == bu)) {
        goto L100;
    }
    if ((tof == du)) {
        goto L150;
    }
    if ((tof == ve)) {
        goto L200;
    }
    if ((tof == fi)) {
        goto L250;
    }
    if ((tof == fo)) {
        goto L250;
    }
    if ((tof == as)) {
        goto L250;
    }
    if ((tof == vh)) {
        goto L300;
    }
    if ((tof == et)) {
        goto L350;
    }
L50:
    {
        auto record = io.writer(
            6, "(//,T13,3HEND,T24,3HEND,T33,5HFETCH,T39,10HSURGE ELEV,      T50,10HSURGE "
               "ELEV,T64,7HINITIAL,T75,7HINITIAL,                    T98,6HBOTTOM,T108,7HAVERAGE)");
        record.finish();
    }
    if (case500) {
        {
            auto record = io.writer(6, "(T9,7HSTATION,T18,9HELEVATION,T32,6HLENGTH,T42,7H10-YEAR,  "
                                       " T52,8H500-YEAR,T61,11HWAVE HEIGHT,T74,9HW. PERIOD,        "
                                       "        T99,5HSLOPE,T108,7HA-ZONES)");
            record.finish();
        }
    } else {
        {
            auto record = io.writer(6, "(T9,7HSTATION,T18,9HELEVATION,T32,6HLENGTH,T42,7H10-YEAR,  "
                                       " T52,8H100-YEAR,T61,11HWAVE HEIGHT,T74,9HW. PERIOD,        "
                                       "        T99,5HSLOPE,T108,7HA-ZONES)");
            record.finish();
        }
    }
    {
        auto record = io.writer(6, "(2X,A2,10F11.3)");
        record.write(tof);
        for (i = 1; i <= 10; ++i) {
            record.write(param(i));
        }
        record.finish();
    }
    goto L10;
L100:
    {
        auto record = io.writer(6, "(//,T13,3HEND,T24,3HEND,T28,10HOPEN SPACE,T43,6HNO. OF,T51, "
                                   "9HNEW SURGE,T62,9HNEW SURGE,T98,6HBOTTOM,T108,7HAVERAGE)");
        record.finish();
    }
    if (case500) {
        {
            auto record = io.writer(6, "(T9,7HSTATION,T18,9HELEVATION,T33,5HRATIO,T45,4HROWS,T53,  "
                                       " 7H10-YEAR,T63,8H500-YEAR,T99,5HSLOPE,T108,7HA-ZONES)");
            record.finish();
        }
    } else {
        {
            auto record = io.writer(6, "(T9,7HSTATION,T18,9HELEVATION,T33,5HRATIO,T45,4HROWS,T53,  "
                                       " 7H10-YEAR,T63,8H100-YEAR,T99,5HSLOPE,T108,7HA-ZONES)");
            record.finish();
        }
    }
    {
        auto record = io.writer(6, "(2X,A2,10F11.3)");
        record.write(tof);
        for (i = 1; i <= 10; ++i) {
            record.write(param(i));
        }
        record.finish();
    }
    goto L10;
L150:
    {
        auto record = io.writer(6, "(//,T6,10HDUNE CREST,T17,10HDUNE CREST,T31,7HDUNE OR,T40,   "
                                   "9HNEW SURGE,T51,9HNEW SURGE,T98,6HBOTTOM,T108,7HAVERAGE)");
        record.finish();
    }
    {
        auto record = io.writer(6, "(T9,7HSTATION,T18,9HELEVATION,T31,7HSEAWALL,T42,            "
                                   "7H10-YEAR,T52,8H100-YEAR,T99,5HSLOPE,T108,7HA-ZONES)");
        record.finish();
    }
    {
        auto record = io.writer(6, "(2X,A2,10F11.3)");
        record.write(tof);
        for (i = 1; i <= 10; ++i) {
            record.write(param(i));
        }
        record.finish();
    }
    goto L10;
L200:
    {
        auto record = io.writer(6, "(//,T13,3HEND,T24,3HEND,T31,7HAVERAGE,T42,7HAVERAGE,T53,    "
                                   "7HAVERAGE,T67,4HDRAG,T73,9HNEW SURGE,T84,9HNEW SURGE,          "
                                   "   T98,6HBOTTOM,T108,7HAVERAGE)");
        record.finish();
    }
    if (case500) {
        {
            auto record = io.writer(6, "(T9,7HSTATION,T18,9HELEVATION,T30,8HDIAMETER,T43,6HHEIGHT, "
                                       " T53,7HSPACING,T65,6HCOEFF.,T75,7H10-YEAR,T85,8H500-YEAR,  "
                                       "        T99,5HSLOPE,T108,7HA-ZONES)");
            record.finish();
        }
    } else {
        {
            auto record = io.writer(6, "(T9,7HSTATION,T18,9HELEVATION,T30,8HDIAMETER,T43,6HHEIGHT, "
                                       " T53,7HSPACING,T65,6HCOEFF.,T75,7H10-YEAR,T85,8H100-YEAR,  "
                                       "        T99,5HSLOPE,T108,7HA-ZONES)");
            record.finish();
        }
    }
    {
        auto record = io.writer(6, "(2X,A2,10F11.3)");
        record.write(tof);
        for (i = 1; i <= 10; ++i) {
            record.write(param(i));
        }
        record.finish();
    }
    goto L10;
L250:
    {
        auto record = io.writer(6, "(//,T13,3HEND,T24,3HEND,T29,9HNEW SURGE,T40,9HNEW SURGE,    "
                                   "T98,6HBOTTOM,T108,7HAVERAGE)");
        record.finish();
    }
    if (case500) {
        {
            auto record = io.writer(6, "(T9,7HSTATION,T18,9HELEVATION,T31,7H10-YEAR,T41,8H500-YEAR,"
                                       " T99,5HSLOPE,T108,7HA-ZONES)");
            record.finish();
        }
    } else {
        {
            auto record = io.writer(6, "(T9,7HSTATION,T18,9HELEVATION,T31,7H10-YEAR,T41,8H100-YEAR,"
                                       " T99,5HSLOPE,T108,7HA-ZONES)");
            record.finish();
        }
    }
    {
        auto record = io.writer(6, "(2X,A2,10F11.3)");
        record.write(tof);
        for (i = 1; i <= 10; ++i) {
            record.write(param(i));
        }
        record.finish();
    }
    goto L10;
L300:
    {
        auto record = io.writer(6, "(//,T13,3HEND,T24,3HEND,T41,8HREGION 1,T65,6HNO. OF,T73,    "
                                   "9HNEW SURGE,T84,9HNEW SURGE,T98,6HBOTTOM,T108,7HAVERAGE)");
        record.finish();
    }
    if (case500) {
        {
            auto record = io.writer(
                6,
                "(T9,7HSTATION,T18,9HELEVATION,T30,8HREGION 1,T43,6HWEIGHT,  T52,8HREGION "
                "2,T61,11HPLANT TYPES,T75,7H10-YEAR,T85,8H500-YEAR,   T99,5HSLOPE,T108,7HA-ZONES)");
            record.finish();
        }
    } else {
        {
            auto record = io.writer(
                6,
                "(T9,7HSTATION,T18,9HELEVATION,T30,8HREGION 1,T43,6HWEIGHT,  T52,8HREGION "
                "2,T61,11HPLANT TYPES,T75,7H10-YEAR,T85,8H100-YEAR,   T99,5HSLOPE,T108,7HA-ZONES)");
            record.finish();
        }
    }
    {
        auto record = io.writer(6, "(2X,A2,10F11.3)");
        record.write(tof);
        for (i = 1; i <= 10; ++i) {
            record.write(param(i));
        }
        record.finish();
    }
    nplts = param(6);
    limit_2974 = nplts;
    for (j = 1; j <= limit_2974; j += 1) {
        {
            auto record = io.reader(8, "(10X,A2,7X,A4,9F11.3)");
            record.read(tof);
            record.read(param(1));
            for (i = 2; i <= 10; ++i) {
                record.read(param(i));
            }
            record.finish();
        }
        {
            auto record = io.writer(6, "(//,T11,5HPLANT,T23,4HDRAG,T30,8HCOVERAGE,T40,9HAVG. STEM, "
                                       " T54,6HNUMBERT62,9HBASE STEM,T74,8HMID STEM,T85,8HTOP "
                                       "STEM,        T96,9HLEAF-STEM)");
            record.finish();
        }
        {
            auto record = io.writer(6, "(T12,4HTYPE,T21,6HCOEFF.,T33,5HRATIO,T43,6HHEIGHT,T53,     "
                                       " 7HDENSITYT63,8HDIAMETER,T74,8HDIAMETER,T85,8HDIAMETER,    "
                                       "        T95,10HAREA RATIO)");
            record.finish();
        }
        {
            auto record = io.writer(6, "(2X,A2,7X,A4,9F11.3)");
            record.write(tof);
            record.write(param(1));
            for (i = 2; i <= 10; ++i) {
                record.write(param(i));
            }
            record.finish();
        };
    }
    {
        auto record = io.writer(6, "(//,2X,112(1H-),/,T27,31HPLANT CHARACTERISTICS INCLUDING,   "
                                   "31H VALUES SUPPLIED BY THE PROGRAM)");
        record.finish();
    }
    limit_2983 = nplts;
    for (i = 1; i <= limit_2983; i += 1) {
        {
            auto record = io.writer(6, "(//,T11,5HPLANT,T23,4HDRAG,T30,8HCOVERAGE,T40,9HAVG. STEM, "
                                       " T54,6HNUMBERT62,9HBASE STEM,T74,8HMID STEM,T85,8HTOP "
                                       "STEM,        T96,9HLEAF-STEM)");
            record.finish();
        }
        {
            auto record = io.writer(6, "(T12,4HTYPE,T21,6HCOEFF.,T33,5HRATIO,T43,6HHEIGHT,T53,     "
                                       " 7HDENSITYT63,8HDIAMETER,T74,8HDIAMETER,T85,8HDIAMETER,    "
                                       "        T95,10HAREA RATIO)");
            record.finish();
        }
        {
            auto record = io.reader(9, "(A4,8F16.8)");
            record.read(type);
            for (j = 1; j <= 8; ++j) {
                record.read(param(j));
            }
            record.finish();
        }
        param(5) = (wide(param(5)) * wide(12));
        param(6) = (wide(param(6)) * wide(12));
        param(7) = (wide(param(7)) * wide(12));
        {
            auto record = io.writer(6, "(11X,A4,9F11.3)");
            record.write(type);
            for (j = 1; j <= 8; ++j) {
                record.write(param(j));
            }
            record.finish();
        };
    }
    {
        auto record = io.writer(6, "(//,2X,112(1H-))");
        record.finish();
    }
    goto L10;
L350:
    {
        auto record = io.writer(6, "(//,2X,48(1H-),15HEND OF TRANSECT,49(1H-))");
        record.finish();
    }
    {
        auto record = io.writer(6, "(//,2X,5HNOTE:)");
        record.finish();
    }
    {
        auto record = io.writer(6, "(/,2X,43HSURGE ELEVATION INCLUDES CONTRIBUTIONS FROM,       "
                                   "1X,29HASTRONOMICAL AND STORM TIDES.)");
        record.finish();
    }
    io.rewind(8);
    io.rewind(9);
    {
        auto record = io.writer(6, "(1H1)");
        record.finish();
    }
    return;
}
} // namespace legacy::whafis::detail
