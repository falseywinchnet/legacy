// SPDX-License-Identifier: MIT
#include "legacy/project.hpp"
#include <algorithm>

#include <cmath>
#include <iomanip>
#include <locale>
#include <sstream>
#include <stdexcept>

namespace legacy::champ {
namespace detail {
void extract_whafis_tables(Project &, std::string_view, Scenario,
                           const std::string &);
void update_runup_zones(Project &, std::string_view, Scenario, float);
} // namespace detail
namespace {
std::string trim(std::string s) {
  auto first = s.find_first_not_of(" \t\r\n");
  return first == s.npos
             ? ""
             : s.substr(first, s.find_last_not_of(" \t\r\n") - first + 1);
}
std::string decimal(double value, int precision) {
  if (!std::isfinite(value))
    throw std::invalid_argument("Model input must contain finite numbers.");
  std::ostringstream out;
  out.imbue(std::locale::classic());
  out << std::fixed << std::setprecision(precision) << value;
  return out.str();
}
std::string text_field(std::string value, std::size_t width) {
  for (auto &c : value)
    if (c == '\n' || c == '\r')
      c = ' ';
  value.resize(width, ' ');
  return value;
}
std::string number_field(double value, std::size_t width, int precision) {
  auto s = decimal(value, precision);
  if (precision == 1) {
    while (s.size() > 1 && s.back() == '0')
      s.pop_back();
    if (s.starts_with("0."))
      s.erase(0, 1);
    if (s.starts_with("-0."))
      s.erase(1, 1);
  }
  if (s.size() > width)
    throw std::invalid_argument(
        "A value does not fit the original model's fixed-column input: " + s);
  return std::string(width - s.size(), ' ') + s;
}
std::string single_text(float value) {
  std::ostringstream text;
  text.imbue(std::locale::classic());
  text << std::setprecision(7) << value;
  return text.str();
}
Json &stored_document(Project &p, std::string_view id, Scenario s,
                      const char *engine) {
  return p.documents[std::string(id)]
                    [s == Scenario::annual_0_2_percent ? "500" : "100"][engine];
}
std::string printed_text(float n) {
  return decimal(std::round(double(n) * 100) / 100, 2);
}
float printed(float n) { return std::stof(printed_text(n)); }
} // namespace
std::string write_runup_input(const runup::Profile &p) {
  if (p.points.size() < 2 || p.points.size() > 20)
    throw std::invalid_argument("RUNUP requires 2 to 20 selected points. Edit "
                                "the selection before running.");
  std::string out = "  " + text_field(p.client, 26) + std::string(32, ' ') +
                    text_field(p.engineer, 10) + text_field(p.job, 10) + "\r\n";
  out += "  " + text_field(p.project, 74) + text_field(p.run, 4) + "\r\n";
  out += number_field(p.last_slope, 4, 1) + "\r\n";
  for (std::size_t i = 0; i < p.points.size(); ++i) {
    const auto &v = p.points[i];
    out += (i + 1 == p.points.size() ? "1 " : "  ") +
           number_field(v.elevation, 5, 1) + " " +
           number_field(v.station, 6, 1) + " " +
           number_field(v.roughness, 5, 3) + "\r\n";
  }
  for (const auto &w : p.waves)
    out += " " + number_field(w.water_level, 5, 1) + " " +
           number_field(w.height, 5, 1) + " " + number_field(w.period, 5, 1) +
           "\r\n";
  return out;
}
std::string write_whafis_input(std::string_view title,
                               std::span<const WhafisCard> cards,
                               Scenario scenario) {
  std::string clean_title(title);
  for (auto &c : clean_title)
    if (c == '\n' || c == '\r')
      c = ' ';
  if (scenario == Scenario::annual_0_2_percent &&
      !clean_title.starts_with(":500:"))
    clean_title = ":500:" + clean_title;
  if (scenario == Scenario::annual_1_percent &&
      clean_title.starts_with(":500:"))
    clean_title.erase(0, 5);
  std::string out = clean_title.substr(0, 80) + "\r\n";
  bool ended = false;
  for (const auto &card : cards) {
    if (ended)
      throw std::invalid_argument("WHAFIS cards appear after the ET end card.");
    if (card.kind == "ET") {
      out += "ET\r\n";
      ended = true;
      continue;
    }
    if (card.kind.size() != 2)
      throw std::invalid_argument("A WHAFIS card code must have two letters.");
    if (!card.text.empty()) {
      out += card.kind + card.text + "\r\n";
      continue;
    }
    out += card.kind;
    for (std::size_t i = 0; i < card.fields.size(); ++i) {
      auto s = trim(card.fields[i]);
      if (s == "0")
        s = "0.00";
      const std::size_t width = i == 0 ? 6 : 8;
      // FrmWhafisEditor.reformat truncates the string before left-padding.
      if (s.size() > width)
        s.resize(width);
      out += std::string(width - s.size(), ' ') + s;
    }
    out += "\r\n";
  }
  if (!ended)
    out += "ET\r\n";
  return out + "\r\n\r\n";
}
std::vector<WhafisCard> read_whafis_cards(std::string_view input) {
  std::istringstream stream{std::string(input)};
  std::string line;
  std::getline(stream, line); // Title is stored by the project separately.
  std::vector<WhafisCard> cards;
  while (std::getline(stream, line)) {
    if (!line.empty() && line.back() == '\r')
      line.pop_back();
    if (trim(line).empty())
      continue;
    WhafisCard card;
    card.kind = line.substr(0, 2);
    if (card.kind == "CM" || card.kind == "PS" || card.kind == "MG")
      card.text = line.substr(2);
    else
      for (std::size_t i = 0; i < card.fields.size(); ++i) {
        const auto offset = i == 0 ? 2u : 8u + unsigned(i - 1) * 8;
        if (offset < line.size())
          card.fields[i] = trim(line.substr(offset, i == 0 ? 6 : 8));
      }
    cards.push_back(std::move(card));
    if (cards.back().kind == "ET")
      break;
  }
  return cards;
}
void Project::populate_runup(std::string_view id, Scenario scenario) {
  auto points = analysis_profile(id, scenario);
  auto peak = std::max_element(
      points.begin(), points.end(),
      [](const auto &a, const auto &b) { return a.elevation < b.elevation; });
  std::vector<Json> records;
  for (std::size_t i = 0; i < points.size(); ++i) {
    const auto &a = points[i], &b = points[std::min(i + 1, points.size() - 1)];
    records.push_back({{"STATION_B", a.station},
                       {"ELEVATION_B", a.elevation},
                       {"STATION_E", b.station},
                       {"ELEVATION_E", b.elevation},
                       {"ROUGHNESS COEFF", 1.f},
                       {"SURFACE DESCRIPTION", "SMOOTH"},
                       {"REMOVESTATUS", a.station > peak->station},
                       {"NOTE", nullptr}});
  }
  replace_rows(scenario_table("RUNUP", scenario), id, std::move(records));
}
runup::Profile Project::runup_profile(std::string_view id,
                                      Scenario scenario) const {
  runup::Profile result;
  const auto &m = metadata(), &t = transect(id);
  const auto p = parameters(id, scenario);
  result.client = textual(m, "CLIENT NAME");
  result.engineer = textual(m, "ENGINEER NAME");
  result.job = textual(t, "JOBNUMBER", "1");
  result.project = textual(m, "TITLE");
  result.run = std::string(id);
  result.last_slope = p.last_slope;
  auto records = rows(scenario_table("RUNUP", scenario), id);
  std::stable_sort(records.begin(), records.end(),
                   [](const auto &a, const auto &b) {
                     return numeric(a, "STATION_B") < numeric(b, "STATION_B");
                   });
  for (const auto &r : records)
    if (numeric(r, "REMOVESTATUS") == 0)
      result.points.push_back({numeric(r, "ELEVATION_B"),
                               numeric(r, "STATION_B"),
                               numeric(r, "ROUGHNESS COEFF", 1)});
  if (p.mean_height <= 0 || p.mean_period <= 0)
    throw std::invalid_argument("Enter a positive mean wave height and mean "
                                "period in the transect parameters.");
  if (p.spread_percent < 0 || p.spread_percent >= 100)
    throw std::invalid_argument(
        "Wave spread must be at least 0 and less than 100 percent.");
  for (int h : {-1, 0, 1})
    for (int period : {-1, 0, 1})
      result.waves.push_back(
          {p.stillwater,
           float(double(p.mean_height) *
                 (1 + h * double(p.spread_percent) / 100)),
           float(double(p.mean_period) *
                 (1 + period * double(p.spread_percent) / 100))});
  return result;
}
RunupSummary Project::run_runup(std::string_view id, Scenario scenario) {
  RunupSummary summary;
  summary.input = write_runup_input(runup_profile(id, scenario));
  // CHAMP rounds its deck before launching RUNUP. Re-read that same deck so the
  // native calculation sees exactly what the original executable would see.
  std::istringstream input(summary.input);
  summary.result = runup::calculate(runup::read_input(input).at(0));
  summary.report = runup::legacy_report({summary.result});
  std::vector<Json> output;
  float sum = 0;
  for (const auto &w : summary.result.waves) {
    if (w.fatal_error || !w.error.empty()) {
      const auto error = "RUNUP could not complete this wave: " + w.error;
      stored_document(*this, id, scenario,
                      "runup") = {{"input", summary.input},
                                  {"report", summary.report},
                                  {"error", error}};
      replace_rows(scenario_table("RUNUP OUTPUT", scenario), id, {});
      replace_rows(scenario_table("RUNUP ZONE", scenario), id, {});
      throw std::runtime_error(error);
    }
    const auto value = printed(w.runup);
    sum = double(sum) + std::stod(printed_text(w.runup));
    output.push_back({{"WATER LEVEL ABOVE DATUM", w.wave.water_level},
                      {"DEEP WATER WAVE HEIGHT", w.wave.height},
                      {"WAVE PERIOD", w.wave.period},
                      {"BREAKER DEPTH", printed(w.breaker_depth)},
                      {"BREAKING SLOPE NUMBER", w.breaking_slope},
                      {"RUNUP SLOPE NUMBER", w.runup_slope},
                      {"RUNUP ABOVE WATER LEVEL", value}});
  }
  if (!output.empty())
    summary.average_runup = double(sum) / output.size();
  summary.two_percent_runup = double(summary.average_runup) * 2.23;
  summary.two_percent_elevation =
      double(summary.two_percent_runup) + parameters(id, scenario).stillwater;
  replace_rows(scenario_table("RUNUP OUTPUT", scenario), id, std::move(output));
  transect(id)[scenario == Scenario::annual_0_2_percent ? "AVERAGERUNUP500"
                                                        : "AVERAGERUNUP"] =
      summary.average_runup;
  detail::update_runup_zones(*this, id, scenario, summary.average_runup);
  stored_document(*this, id, scenario, "runup") = {
      {"input", summary.input},
      {"report", summary.report},
      {"average_runup", summary.average_runup},
      {"two_percent_runup", summary.two_percent_runup},
      {"two_percent_elevation", summary.two_percent_elevation}};
  return summary;
}
std::vector<WhafisCard> Project::whafis_cards(std::string_view id,
                                              Scenario scenario) const {
  std::vector<WhafisCard> cards;
  for (const auto &r : rows(scenario_table("WHAFIS INPUT", scenario), id)) {
    WhafisCard c;
    c.kind = textual(r, "WHAFIS CARD");
    c.text = textual(r, "RAW TEXT");
    for (std::size_t i = 0; i < c.fields.size(); ++i)
      c.fields[i] = textual(r, "FIELD " + std::to_string(i + 1));
    cards.push_back(std::move(c));
  }
  return cards;
}
void Project::set_whafis_cards(std::string_view id, Scenario scenario,
                               std::span<const WhafisCard> cards) {
  std::vector<Json> records;
  for (const auto &c : cards) {
    Json r = {{"WHAFIS CARD", c.kind}, {"RAW TEXT", c.text}};
    for (std::size_t i = 0; i < c.fields.size(); ++i)
      r["FIELD " + std::to_string(i + 1)] = c.fields[i];
    records.push_back(std::move(r));
  }
  replace_rows(scenario_table("WHAFIS INPUT", scenario), id,
               std::move(records));
}
void Project::populate_whafis(std::string_view id, Scenario scenario) {
  const auto ground = analysis_profile(id, scenario);
  const auto p = parameters(id, scenario);
  const float water = double(p.stillwater) + p.wave_setup;
  if (water <= 0 || p.significant_height <= 0 || p.peak_period <= 0)
    throw std::invalid_argument(
        "Enter the stillwater, wave setup, significant height, and peak period "
        "before preparing WHAFIS.");
  std::vector<TransectPoint> points;
  // Include every water crossing, even when both surrounding points would
  // otherwise be discarded. The returning crossing starts an AS card.
  for (std::size_t i = 0; i < ground.size(); ++i) {
    if (i)
      for (float level : {0.f, water}) {
        const auto &a = ground[i - 1], &b = ground[i];
        if ((double(a.elevation) - level) * (double(b.elevation) - level) < 0) {
          auto line =
              general_line({a.station, a.elevation}, {b.station, b.elevation});
          points.push_back({float((double(level) - line.c) / line.a), level,
                            "Interpolated"});
        }
      }
    points.push_back(ground[i]);
  }
  std::stable_sort(
      points.begin(), points.end(),
      [](const auto &a, const auto &b) { return a.station < b.station; });
  auto first = std::find_if(points.begin(), points.end(),
                            [](const auto &a) { return a.elevation == 0; });
  if (first == points.end())
    throw std::invalid_argument(
        "WHAFIS requires a shoreline at zero elevation.");
  std::vector<WhafisCard> cards;
  WhafisCard ie;
  ie.kind = "IE";
  std::array<float, 10> fields{first->station,
                               0,
                               p.fetch_miles,
                               p.ten_year_stillwater,
                               water,
                               float(double(p.significant_height) * 1.6),
                               p.peak_period,
                               p.wind_inland,
                               p.wind_overwater,
                               p.wind_vegetation};
  for (std::size_t i = 0; i < fields.size(); ++i)
    ie.fields[i] = single_text(fields[i]);
  cards.push_back(ie);
  bool above = false;
  for (auto it = std::next(first); it != points.end(); ++it) {
    if (it->elevation > water) {
      above = true;
      continue;
    }
    WhafisCard c;
    c.kind = above ? "AS" : "IF";
    c.fields[0] = single_text(it->station);
    c.fields[1] = single_text(it->elevation);
    c.fields[2] = above ? single_text(p.ten_year_stillwater) : "0";
    c.fields[3] = above ? single_text(water) : "0";
    cards.push_back(c);
    above = false;
  }
  if (cards.size() > 1000)
    throw std::invalid_argument(
        "The WHAFIS profile exceeds 1,000 points. Reduce the point count "
        "before preparing the cards.");
  cards.push_back({"ET", {}, {}});
  set_whafis_cards(id, scenario, cards);
}
whafis::Report Project::run_whafis(std::string_view id, Scenario scenario,
                                   const whafis::Options &options) {
  const auto cards = whafis_cards(id, scenario);
  if (cards.empty())
    throw std::invalid_argument(
        "Prepare or import the WHAFIS input cards before running.");
  const auto input = write_whafis_input(textual(metadata(), "TITLE") +
                                            " - Transect: " + std::string(id),
                                        cards, scenario);
  auto result = whafis::calculate(input, options);
  stored_document(*this, id, scenario, "whafis") = {
      {"input", input}, {"report", result.text}, {"error", result.error}};
  if (result.error.empty())
    detail::extract_whafis_tables(*this, id, scenario, result.text);
  else
    for (int part = 1; part <= 6; ++part)
      replace_rows(
          scenario_table("WHAFIS PART " + std::to_string(part), scenario), id,
          {});
  return result;
}
} // namespace legacy::champ
