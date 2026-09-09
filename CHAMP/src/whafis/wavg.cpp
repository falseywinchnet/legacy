// Port of WHAFIS4G.FOR: WAVG. Source labels support differential review.
#include "engine.hpp"
namespace legacy::whafis::detail {
void Engine::wavg(Array<float, 10, 8> &def1, Array<float, 10, 8> &def2, Array<float, 10, 8> &def,
                  float &wf1, float &reg1, float &reg2, int &nplts, Array<float, 10> &type,
                  bool &test) {
    int i{};
    int ireg1{};
    int ireg2{};
    int j{};
    int limit_3126{};
    int limit_3130{};
    int limit_3151{};
    ireg1 = reg1;
    ireg2 = reg2;
    limit_3126 = nplts;
    for (i = 1; i <= limit_3126; i += 1) {
        limit_3130 = 7;
        for (j = 3; j <= limit_3130; j += 1) {
            if ((j == 4)) {
                goto L20;
            }
            if (((def1(i, j) == 0) && (def2(i, j) == 0))) {
                goto L10;
            }
            if ((def1(i, j) == 0)) {
                def1(i, j) = def2(i, j);
            }
            if ((def2(i, j) == 0)) {
                def2(i, j) = def1(i, j);
            }
            goto L20;
        L10:
            test = true;
            if ((j == 3)) {
                {
                    auto record = io.writer(6, "(/,10X,45HHEIGHT BELOW INFLORESENCE = 0 FOR PLANT "
                                               "TYPE ,    A4,10H IN REGION,I2,11H AND REGION,I2)");
                    record.write(type(i));
                    record.write(ireg1);
                    record.write(ireg2);
                    record.finish();
                }
            }
            if ((j == 5)) {
                {
                    auto record = io.writer(6, "(/,10X,38HBASE STEM DIAMATER = 0 FOR PLANT TYPE ,  "
                                               "         A4,10H IN REGION,I2,11H AND REGION,I2)");
                    record.write(type(i));
                    record.write(ireg1);
                    record.write(ireg2);
                    record.finish();
                }
            }
            if ((j == 6)) {
                {
                    auto record = io.writer(6, "(/,10X,37HMID STEM DIAMATER = 0 FOR PLANT TYPE ,   "
                                               "         A4,10H IN REGION,I2,11H AND REGION,I2)");
                    record.write(type(i));
                    record.write(ireg1);
                    record.write(ireg2);
                    record.finish();
                }
            }
            if ((j == 7)) {
                {
                    auto record = io.writer(6, "(/,10X,37HTOP STEM DIAMATER = 0 FOR PLANT TYPE ,   "
                                               "         A4,10H IN REGION,I2,11H AND REGION,I2)");
                    record.write(type(i));
                    record.write(ireg1);
                    record.write(ireg2);
                    record.finish();
                }
            }
            {
                auto record = io.writer(6, "(/,10X,19HINVALID INPUT DATA.)");
                record.finish();
            }
        L20:;
        }
        limit_3151 = 8;
        for (j = 1; j <= limit_3151; j += 1) {
            def(i, j) = (wide((wide(wf1) * wide(def1(i, j)))) +
                         wide((wide((wide(1) - wide(wf1))) * wide(def2(i, j)))));
            ;
        }
    }
    return;
}
} // namespace legacy::whafis::detail
