// Port of WHAFIS4G.FOR: LOOKUP. Source labels support differential review.
#include "engine.hpp"
namespace legacy::whafis::detail {
void Engine::lookup(Array<float, 10, 8> &def, float &reg, bool &test) {
    float a{};
    float b{};
    float fcovcum{};
    float fcovflt{};
    int i1{};
    int i2{};
    int ireg{};
    Array<int, 10> ityp{};
    int ncov{};
    bool test1{};
    bool test2{};
    int limit_3531{};
    int limit_3584{};
    int limit_3610{};
    int limit_3707{};
    int limit_3722{};
    ireg = reg;
    test1 = false;
    fcovcum = 0.0f;
    limit_3531 = nplts;
    for (i1 = 1; i1 <= limit_3531; i1 += 1) {
        def(i1, 1) = cde(i1);
        def(i1, 2) = fcov(i1);
        def(i1, 3) = hbi(i1);
        def(i1, 4) = ppsf(i1);
        def(i1, 5) = sdb(i1);
        def(i1, 6) = sdm(i1);
        def(i1, 7) = sdt(i1);
        def(i1, 8) = far(i1);
        test2 = false;
        if (fcov(i1) < 0)
            goto L1000;
        if (fcov(i1) == 0)
            goto L1010;
        goto L1020;
    L1000:;
        test2 = true;
        {
            auto record =
                io.writer(6, "(/10X,'FCOV WAS FOUND TO BE NEGATIVE FOR PLANT TYPE= ',       I2)");
            record.write(i1);
            record.finish();
        }
        goto L1030;
    L1010:;
        test1 = true;
        ncov = (ncov + 1);
        goto L1030;
    L1020:;
        fcovcum = (wide(fcovcum) + wide(fcov(i1)));
    L1030:;
        limit_3584 = 8;
        for (i2 = 1; i2 <= limit_3584; i2 += 1) {
            if ((type(i1) == pltyp(i2))) {
                goto L1050;
            };
        }
        goto L225;
    L1050:;
        if ((cde(i1) == 0)) {
            def(i1, 1) = .1f;
        }
        ityp(i1) = 9;
        limit_3610 = 8;
        for (i2 = 1; i2 <= limit_3610; i2 += 1) {
            if ((type(i1) == pltyp(i2))) {
                ityp(i1) = i2;
            };
        }
        if ((sdb(i1) != 0)) {
            goto L120;
        }
        if (((ityp(i1) < 9) && (reg != 0))) {
            goto L90;
        }
        test2 = true;
        goto L120;
    L90:
        if ((hbi(i1) != 0)) {
            goto L100;
        }
        def(i1, 5) = hdn(ireg, ityp(i1), 2);
        goto L120;
    L100:
        a = hdn(ireg, ityp(i1), 3);
        b = hdn(ireg, ityp(i1), 4);
        def(i1, 5) = (wide(a) * wide(power(hbi(i1), b)));
    L120:;
        if ((ppsf(i1) != 0)) {
            goto L150;
        }
        if (((ityp(i1) < 9) && (reg != 0))) {
            goto L130;
        }
        test2 = true;
        goto L150;
    L130:
        if ((hbi(i1) != 0)) {
            goto L140;
        }
        def(i1, 4) = hdn(ireg, ityp(i1), 5);
        goto L150;
    L140:
        a = hdn(ireg, ityp(i1), 6);
        b = hdn(ireg, ityp(i1), 7);
        def(i1, 4) = (wide(a) * wide(power(hbi(i1), b)));
    L150:;
        if ((hbi(i1) != 0)) {
            goto L160;
        }
        if (((ityp(i1) < 9) && (reg != 0))) {
            goto L155;
        }
        test2 = true;
        goto L160;
    L155:
        def(i1, 3) = hdn(ireg, ityp(i1), 1);
    L160:;
        if ((sdm(i1) != 0)) {
            goto L180;
        }
        if ((ityp(i1) < 9)) {
            goto L170;
        }
        test2 = true;
        goto L180;
    L170:
        def(i1, 6) = (wide(def(i1, 5)) * wide(ppsd(ityp(i1), 1)));
    L180:;
        if ((sdt(i1) != 0)) {
            goto L200;
        }
        if ((ityp(i1) < 9)) {
            goto L190;
        }
        test2 = true;
        goto L200;
    L190:
        def(i1, 7) = (wide(def(i1, 5)) * wide(ppsd(ityp(i1), 2)));
    L200:;
        if ((far(i1) != 0)) {
            goto L220;
        }
        if ((ityp(i1) < 9)) {
            goto L210;
        }
        test2 = true;
        goto L220;
    L210:
        def(i1, 8) = ppsd(ityp(i1), 3);
    L220:;
    L225:;
        if (test2) {
            {
                auto record = io.writer(6, "(/,10X,41HNO DEFAULT DATA AVAILABLE FOR PLANT TYPE "
                                           ",A4,     10H IN REGION,I2)");
                record.write(type(i1));
                record.write(ireg);
                record.finish();
            }
        }
        if (test2) {
            test = true;
        };
    }
    if ((!test1)) {
        goto L270;
    }
    if ((ncov > 0)) {
        goto L2010;
    }
    {
        auto record = io.writer(6, "(/10X,'NCOV IS .LE. ZERO IN SUB. LOOKUP WHEN IT SHOULD'     ' "
                                   "BE .GT. ZERO. ABORT RUN.')");
        record.finish();
    }
    throw CalculationStopped{};
L2010:;
    if ((fcovcum > 0.0f)) {
        goto L250;
    }
    fcovflt = (wide(1.0f) / wide(real(nplts)));
    limit_3707 = nplts;
    for (i2 = 1; i2 <= limit_3707; i2 += 1) {
        def(i2, 2) = fcovflt;
        ;
    }
    goto L270;
L250:;
    fcovflt = (wide(1.0f) / wide(real(ncov)));
    limit_3722 = nplts;
    for (i2 = 1; i2 <= limit_3722; i2 += 1) {
        if ((fcov(i2) == 0.0f)) {
            def(i2, 2) = fcovflt;
        };
    }
L270:;
}
} // namespace legacy::whafis::detail
