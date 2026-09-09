// Port of WHAFIS4G.FOR: AVG. Source labels support differential review.
#include "engine.hpp"
namespace legacy::whafis::detail {
void Engine::avg(float &bp, float &ep, float &aer, float &ats) {
    float a1{};
    float a2{};
    float as{};
    float hght1{};
    float hght2{};
    int i{};
    int icpe{};
    int icpem1{};
    int icps{};
    float slope{};
    float slope1{};
    float slope2{};
    float width{};
    float width1{};
    float width2{};
    float wt{};
    float x{};
    float y1{};
    float y2{};
    float y3{};
    float y4{};
    int limit_2722{};
    int limit_2730{};
    as = word("AS");
    wt = 0;
    icps = 0;
    icpe = 0;
    limit_2722 = nfom1;
    for (i = 1; i <= limit_2722; i += 1) {
        if (((bp >= gs(i)) && (bp < gs((i + 1))))) {
            icps = (i + 1);
        }
        if (((ep > gs(i)) && (ep <= gs((i + 1))))) {
            icpe = i;
        };
    }
    a1 = 0;
    a2 = 0;
    icpem1 = (icpe - 1);
    if ((icpem1 <= icps)) {
        goto L25;
    }
    limit_2730 = icpem1;
    for (i = icps; i <= limit_2730; i += 1) {
        if ((sa((i + 1), 5) == as)) {
            goto L20;
        }
        hght1 = (wide(sa(i, 3)) + wide(sa((i + 1), 3)));
        hght2 = (wide(ew(i)) + wide(ew((i + 1))));
        width = (wide(gs((i + 1))) - wide(gs(i)));
        wt = (wide(wt) + wide(width));
        a1 = (wide(a1) + wide((wide((wide(hght1) * wide(width))) / wide(2.0f))));
        a2 = (wide(a2) + wide((wide((wide(hght2) * wide(width))) / wide(2.0f))));
    L20:;
    }
L25:
    if ((icps == icpem1)) {
        goto L30;
    }
    if ((icps == icpe)) {
        goto L40;
    }
    if ((icps > icpe)) {
        goto L50;
    }
    goto L60;
L30:
    if ((sa(icpe, 5) == as)) {
        goto L60;
    }
    hght1 = (wide(sa(icps, 3)) + wide(sa(icpe, 3)));
    hght2 = (wide(ew(icps)) + wide(ew(icpe)));
    width = (wide(gs(icpe)) - wide(gs(icps)));
    wt = width;
    a1 = (wide((wide(hght1) * wide(width))) / wide(2.0f));
    a2 = (wide((wide(hght2) * wide(width))) / wide(2.0f));
    goto L60;
L40:
    slope1 =
        (wide((wide(ew(icpe)) - wide(ew(icpem1)))) / wide((wide(gs(icpe)) - wide(gs(icpem1)))));
    slope2 = (wide((wide(ew((icpe + 1))) - wide(ew(icpe)))) /
              wide((wide(gs((icpe + 1))) - wide(gs(icpe)))));
    y1 = (wide((wide(slope1) * wide((wide(bp) - wide(gs(icpem1)))))) + wide(ew(icpem1)));
    y2 = (wide((wide(slope2) * wide((wide(ep) - wide(gs(icpe)))))) + wide(ew(icpe)));
    y3 = (wide(sa(icpem1, 3)) + wide(sa(icpe, 3)));
    y4 = (wide(sa(icpe, 3)) + wide(sa((icpe + 1), 3)));
    width1 = (wide(gs(icpe)) - wide(bp));
    width2 = (wide(ep) - wide(gs(icpe)));
    wt = (wide(width1) + wide(width2));
    a1 = (wide((wide((wide(y3) * wide(width1))) + wide((wide(y4) * wide(width2))))) / wide(2.0f));
    a2 = (wide((wide((wide((wide(y1) + wide(ew(icpe)))) * wide(width1))) +
                wide((wide((wide(y2) + wide(ew(icpe)))) * wide(width2))))) /
          wide(2.0f));
    goto L70;
L50:
    x = (wide((wide((wide(bp) + wide(ep))) / wide(2.0f))) - wide(gs(icpe)));
    slope = (wide((wide(ew(icps)) - wide(ew(icpe)))) / wide((wide(gs(icps)) - wide(gs(icpe)))));
    y1 = (wide((wide(sa(icps, 3)) + wide(sa(icpe, 3)))) / wide(2.0f));
    y2 = (wide((wide(slope) * wide(x))) + wide(ew(icpe)));
    width = (wide(ep) - wide(bp));
    wt = width;
    a1 = (wide(y1) * wide(width));
    a2 = (wide(y2) * wide(width));
    goto L70;
L60:
    slope1 = (wide((wide(ew(icps)) - wide(ew((icps - 1))))) /
              wide((wide(gs(icps)) - wide(gs((icps - 1))))));
    slope2 = (wide((wide(ew((icpe + 1))) - wide(ew(icpe)))) /
              wide((wide(gs((icpe + 1))) - wide(gs(icpe)))));
    y1 = (wide((wide(slope1) * wide((wide(bp) - wide(gs((icps - 1))))))) + wide(ew((icps - 1))));
    y2 = (wide((wide(slope2) * wide((wide(ep) - wide(gs(icpe)))))) + wide(ew(icpe)));
    y3 = (wide((wide(sa((icps - 1), 3)) + wide(sa(icps, 3)))) / wide(2.0f));
    y4 = (wide((wide(sa((icpe + 1), 3)) + wide(sa(icpe, 3)))) / wide(2.0f));
    width1 = (wide(gs(icps)) - wide(bp));
    width2 = (wide(ep) - wide(gs(icpe)));
    a1 = (wide(a1) + wide((wide((wide(y3) * wide(width1))) + wide((wide(y4) * wide(width2))))));
    a2 = (wide((wide(a2) +
                wide((wide((wide((wide(y1) + wide(ew(icps)))) * wide(width1))) / wide(2.0f))))) +
          wide((wide((wide((wide(y2) + wide(ew(icpe)))) * wide(width2))) / wide(2.0f))));
    wt = (wide((wide(wt) + wide(width1))) + wide(width2));
L70:
    ats = (wide(a1) / wide(wt));
    aer = (wide(a2) / wide(wt));
    return;
}
} // namespace legacy::whafis::detail
