// Port of WHAFIS4G.FOR: READIN. Source labels support differential review.
#include "engine.hpp"
namespace legacy::whafis::detail {
void Engine::readin() {
    int i{};
    int j{};
    int k{};
    int limit_2799{};
    int limit_2800{};
    int limit_2805{};
    int limit_2806{};
    int limit_2811{};
    io.rewind(7);
    limit_2799 = 7;
    for (i = 1; i <= limit_2799; i += 1) {
        limit_2800 = 8;
        for (j = 1; j <= limit_2800; j += 1) {
            {
                auto record = io.reader(7, "(7F8.0)");
                for (k = 1; k <= 7; ++k) {
                    record.read(hdn(i, j, k));
                }
                record.finish();
            };
        }
    }
    limit_2805 = 8;
    for (i = 1; i <= limit_2805; i += 1) {
        limit_2806 = 7;
        for (j = 1; j <= limit_2806; j += 1) {
            hdn(8, i, j) = 0;
            ;
        }
    }
    limit_2811 = 8;
    for (i = 1; i <= limit_2811; i += 1) {
        {
            auto record = io.reader(7, "(3F8.0)");
            for (j = 1; j <= 3; ++j) {
                record.read(ppsd(i, j));
            }
            record.finish();
        };
    }
    {
        auto record = io.reader(7, "(8(4X,A4))");
        for (i = 1; i <= 8; ++i) {
            record.read(pltyp(i));
        }
        record.finish();
    }
    return;
}
} // namespace legacy::whafis::detail
