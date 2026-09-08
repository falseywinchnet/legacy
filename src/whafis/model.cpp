#include "engine.hpp"
#include "legacy/whafis.hpp"
#include "marsh_data.hpp"
#include <ctime>
#include <memory>

namespace legacy::whafis {
void detail::Engine::record_transect(std::string_view title) {
    TransectResult result;
    result.title = trim(adjust_left(title));
    for (int i = 1; i <= nfo; ++i) {
        const float tag = sa(i, 5);
        result.points.push_back({tag == 1 || tag == 2 ? "" : trim(word_text(tag)), gs(i), hbw(i),
                                 hbw(i) == 0 ? 0 : spwp(i), ew(i), sa(i, 4)});
    }
    transects.push_back(std::move(result));
}

Report calculate(std::string_view input, const Options &options) {
    auto engine = std::make_unique<detail::Engine>();
    auto &e = *engine;
    e.io.load(5, input);
    e.io.load(7, options.marsh_data.empty() ? detail::marsh_data : options.marsh_data);
    e.xinname = options.input_name;
    e.xoutname = options.output_name;
    Report report;
    try {
        e.whafis4();
    } catch (const std::exception &error) {
        report.error = error.what();
    }
    report.text = e.io.content(6);
    report.transects = std::move(e.transects);
    std::string executed_on = options.executed_on;
    if (executed_on.empty()) {
        const auto now = std::time(nullptr);
        std::tm calendar{};
#ifdef _WIN32
        localtime_s(&calendar, &now);
#else
        localtime_r(&now, &calendar);
#endif
        char date[32]{};
        std::strftime(date, sizeof(date), "%a %b %d %H:%M:%S %Y", &calendar);
        executed_on = date;
        if (executed_on.size() > 8 && executed_on[8] == '0')
            executed_on[8] = ' ';
    }
    executed_on.resize(24, ' ');
    const auto heading_end = report.text.find("\r\n");
    if (heading_end != std::string::npos)
        report.text.insert(heading_end + 2, " Executed on: " + executed_on + "\r\n");
    return report;
}
} // namespace legacy::whafis
