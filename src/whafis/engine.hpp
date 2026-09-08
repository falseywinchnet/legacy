#pragma once
#include "legacy/whafis.hpp"
#include "support.hpp"
namespace legacy::whafis::detail {
class Engine {
  public:
    RecordFiles io;
    std::vector<TransectResult> transects;
    void record_transect(std::string_view title);
    Array<float, 1000> ap{};
    float befo{};
    float bsfo{};
    bool case500{};
    Array<float, 10> cde{};
    int cmcount{};
    Array<Text<78>, 100> cmline{};
    Text<78> cmstring{};
    Text<5> code500{};
    Array<float, 1000> elz{};
    Array<float, 1000> ew{};
    Array<float, 10> far{};
    Array<float, 10> fcov{};
    Array<float, 10> fff{};
    Array<float, 10> ffl{};
    Array<float, 10> gff{};
    Array<float, 10> gfl{};
    Array<float, 1000> gs{};
    float gslb{};
    float gsle{};
    Array<float, 10> hbi{};
    Array<float, 1000> hbw{};
    Array<float, 8, 8, 7> hdn{};
    int m{};
    int nap{};
    int nfo{};
    int nfom1{};
    int nplts{};
    Array<float, 10> param{};
    Array<float, 8> pltyp{};
    Array<float, 8, 3> ppsd{};
    Array<float, 10> ppsf{};
    int pscount{};
    Array<Text<78>, 100> psline{};
    Array<float, 1000, 5> sa{};
    Array<float, 10> sdb{};
    Array<float, 10> sdm{};
    Array<float, 10> sdt{};
    float se{};
    float set{};
    Array<float, 1000> spwp{};
    Array<float, 1000> steg{};
    float tof{};
    Array<float, 10> type{};
    float whi{};
    float wht{};
    float windif{};
    float windof{};
    float windvh{};
    float wwndif{};
    float wwndof{};
    float wwndvh{};
    Text<128> xinname{};
    Text<128> xoutname{};
    void whafis4();
    void fetch(float &wpi, bool &test, float &wpt, float &w);
    void veg(float &wpi, bool &test, float &wpt, float &w);
    float shbm(float wpi, float slope, float dnew);
    float hin(float whi, float afl, float w, float d, float wpt);
    void avg(float &bp, float &ep, float &aer, float &ats);
    void readin();
    float app(Array<float, 10, 8> &def, float d, int nplts, float wpi, float wl);
    void echo();
    float t(float wpi, float afl, float w, float d);
    void wavg(Array<float, 10, 8> &def1, Array<float, 10, 8> &def2, Array<float, 10, 8> &def,
              float &wf1, float &reg1, float &reg2, int &nplts, Array<float, 10> &type, bool &test);
    float hm0(float whi, float dnew, float wpi);
    void lookup(Array<float, 10, 8> &def, float &reg, bool &test);
    void scane();
};
} // namespace legacy::whafis::detail
