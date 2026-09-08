// Port of WHAFIS4G.FOR: APP. Source labels support differential review.
#include "engine.hpp"
namespace legacy::whafis::detail {
float Engine::app(Array<float, 10, 8> &def, float d, int nplts, float wpi, float wl) {
    float a1{};
    float a2{};
    float aams{};
    float abms{};
    float acpl{};
    float result{};
    float at{};
    float cde{};
    float far{};
    float fcov{};
    float g{};
    float g2{};
    float hbi{};
    float hf{};
    int i{};
    float pi{};
    float ppsf{};
    float sdb{};
    float sdi{};
    float sdm{};
    float sdt{};
    float tas{};
    float wpf{};
    float z{};
    int limit_2838{};
    pi = 3.14159f;
    g2 = 1036.84f;
    g = 32.2f;
    result = 0;
    limit_2838 = nplts;
    for (i = 1; i <= limit_2838; i += 1) {
        cde = def(i, 1);
        fcov = def(i, 2);
        hbi = def(i, 3);
        ppsf = def(i, 4);
        sdb = def(i, 5);
        sdm = def(i, 6);
        sdt = def(i, 7);
        far = def(i, 8);
        abms = (wide((wide((wide(sdb) + wide(sdm))) * wide(hbi))) * wide(.25f));
        aams = (wide((wide((wide(sdm) + wide(sdt))) * wide(hbi))) * wide(.25f));
        tas = (wide(abms) + wide(aams));
        acpl = (wide((wide((wide(2) / wide(pi))) * wide(far))) * wide(tas));
        hf = (wide(.5f) * wide(hbi));
        if ((hf > d)) {
            hf = d;
        }
        if (((wide(d) / wide(wl)) < .04f)) {
            goto L5;
        }
        if (((wide(d) / wide(wl)) > .5f)) {
            goto L10;
        }
        wpf = (wide(g2) *
               wide(power(
                   (wide((wide((wide(wpi) / wide(wl))) *
                          wide(std::cosh(
                              (wide((wide((wide(2) * wide(pi))) * wide(hf))) / wide(wl)))))) /
                    wide(std::cosh((wide((wide((wide(2) * wide(pi))) * wide(d))) / wide(wl))))),
                   3)));
        goto L15;
    L5:
        wpf = std::sqrt((wide(g) / wide(d)));
        goto L15;
    L10:
        z = (wide(hf) - wide(d));
        wpf =
            (wide((wide(8) / wide(g))) *
             wide(power((wide((wide(pi) / wide(wpi))) *
                         wide(std::exp((wide((wide((wide(2) * wide(pi))) * wide(z))) / wide(wl))))),
                        3)));
    L15:
        if ((hbi != 0)) {
            goto L20;
        }
        at = 0;
        goto L50;
    L20:
        if ((d > (wide(.5f) * wide(hbi)))) {
            goto L25;
        }
        sdi = (wide(sdb) + wide((wide((wide(sdm) - wide(sdb))) / wide((wide(.5f) * wide(hbi))))));
        a1 = (wide((wide((wide(sdb) + wide(sdi))) * wide(.5f))) * wide(d));
        a2 = (wide(acpl) * wide((wide(d) / wide(hbi))));
        at = (wide(a1) + wide(a2));
        goto L50;
    L25:
        if ((d > hbi)) {
            goto L30;
        }
        sdi = (wide(sdm) +
               wide((wide((wide((wide(sdt) - wide(sdm))) / wide((wide(hbi) * wide(.5f))))) *
                     wide((wide(d) - wide((wide(hbi) * wide(.5f))))))));
        a1 = (wide((wide((wide(sdm) + wide(sdi))) * wide(.5f))) *
              wide((wide(d) - wide((wide(.5f) * wide(hbi))))));
        a2 = (wide(acpl) * wide((wide(d) / wide(hbi))));
        at = (wide((wide(abms) + wide(a1))) + wide(a2));
        goto L50;
    L30:
        at = (wide(tas) + wide(acpl));
    L50:
        result = (wide(result) +
                  wide((wide((wide((wide((wide(fcov) * wide(ppsf))) * wide(cde))) * wide(at))) *
                        wide(wpf))));
        ;
    }
    return result;
    return result;
}
} // namespace legacy::whafis::detail
