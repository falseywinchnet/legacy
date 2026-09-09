// SPDX-License-Identifier: MIT
#include "legacy/project.hpp"
#include <algorithm>
#include <array>
#include <cmath>
#include <sstream>
#include <stdexcept>

namespace legacy::champ::detail {
namespace {
std::string trim(std::string text) {
  auto a = text.find_first_not_of(" \t\r\n");
  return a == text.npos
             ? ""
             : text.substr(a, text.find_last_not_of(" \t\r\n") - a + 1);
}
std::optional<float> number(std::string_view text) {
  try {
    auto s = trim(std::string(text));
    if (s.empty())
      return {};
    std::size_t used{};
    float value = std::stof(s, &used);
    if (used == s.size() && std::isfinite(value))
      return value;
  } catch (const std::exception &) {
  }
  return {};
}
std::string field(const std::string &line, std::size_t offset,
                  std::size_t count) {
  return offset < line.size() ? trim(line.substr(offset, count)) : "";
}
Json zone(Point a, Point b, const char *kind) {
  return {{"STATION_B", a.station},
          {"ELEVATION_B", a.elevation},
          {"STATION_E", b.station},
          {"ELEVATION_E", b.elevation},
          {"ZONE", kind}};
}
} // namespace
void extract_whafis_tables(Project &project, std::string_view id,
                           Scenario scenario, const std::string &report) {
  std::array<std::vector<Json>, 6> tables;
  int part = 0;
  std::istringstream stream(report);
  std::string line;
  std::optional<Point> last;
  Json designation;
  while (std::getline(stream, line)) {
    for (int i = 1; i <= 6; ++i)
      if (trim(line).starts_with("PART" + std::to_string(i) + ":") ||
          trim(line).starts_with("PART" + std::to_string(i) + " "))
        part = i;
    if (part == 1 && line.starts_with("          ") && line.size() > 12) {
      auto kind = field(line, 10, 2);
      const std::string codes = " IE IF OF AS DU BU VE VH MG ET ";
      if (kind.size() != 2 || kind == "ET" ||
          codes.find(" " + kind + " ") == codes.npos)
        continue;
      Json row = {{"WHAFIS CARD", kind}};
      for (int i = 0; i < 10; ++i)
        row["FIELD " + std::to_string(i + 1)] = field(line, 12 + i * 11, 11);
      row["FIELD 11"] = "0"; // Original CHAMP retains this unused field.
      tables[0].push_back(std::move(row));
    }
    if (part == 2 && line.size() >= 53) {
      auto station = number(field(line, 42, 11));
      auto height = number(field(line, 53, 13));
      auto period = number(field(line, 66, 13));
      auto crest = number(field(line, 79, 13));
      if (station && height && period && crest)
        tables[1].push_back({{"WHAFIS CARD", field(line, 40, 2)},
                             {"STATION", *station},
                             {"WAVE HEIGHT", *height},
                             {"WAVE PERIOD", *period},
                             {"WAVE CREST ELEVATION", *crest}});
    }
    if (part == 3) {
      std::istringstream row(trim(line));
      std::string between, and_word;
      float begin, end;
      if (row >> between >> begin >> and_word >> end && between == "BETWEEN" &&
          and_word == "AND")
        tables[2].push_back({{"STATION BEGIN", begin}, {"STATION END", end}});
    }
    if (part == 4) {
      std::istringstream row(trim(line));
      float station, ten, hundred;
      if (row >> station >> ten >> hundred)
        tables[3].push_back({{"STATION", station},
                             {"10-Year Surge", ten},
                             {"100-Year Surge", hundred}});
    }
    if (part == 5) {
      std::istringstream row(trim(line));
      float station;
      std::string location;
      if (row >> station >> location)
        tables[4].push_back({{"STATION", station}, {"Location", location}});
    }
    if (part == 6) {
      std::istringstream row(trim(line));
      float station, elevation;
      if (row >> station >> elevation) {
        Point current{station, elevation};
        if (last && !designation.empty()) {
          auto entry = designation;
          entry["STATION BEGIN"] = last->station;
          entry["ELEVATION BEGIN"] = last->elevation;
          entry["STATION END"] = current.station;
          entry["ELEVATION END"] = current.elevation;
          tables[5].push_back(std::move(entry));
        }
        last = current;
        // CHAMP labels an unprinted interval X and carries its previous
        // zone elevation and FHF (FrmWhafisEditor p-code 14ED..1547).
        designation["ZONE"] = "X";
        if (!designation.contains("ZONE ELEVATION"))
          designation["ZONE ELEVATION"] = 0;
        if (!designation.contains("FHF"))
          designation["FHF"] = 0;
      } else {
        auto text = trim(line);
        if (!text.empty() &&
            (text[0] == 'V' || text[0] == 'A' || text[0] == 'X')) {
          std::istringstream values(text);
          std::string kind, el;
          float fhf;
          values >> kind >> el;
          if (el.starts_with("EL=")) {
            auto value = number(el.substr(3));
            if (value) {
              designation = {{"ZONE", kind}, {"ZONE ELEVATION", *value}};
              if (values >> fhf)
                designation["FHF"] = fhf;
            }
          } else if (kind == "X")
            designation = {{"ZONE", kind}, {"ZONE ELEVATION", 0}, {"FHF", 0}};
        }
      }
    }
  }
  for (int i = 0; i < 6; ++i)
    project.replace_rows(
        scenario_table("WHAFIS PART " + std::to_string(i + 1), scenario), id,
        std::move(tables[i]));
}
void update_runup_zones(Project &project, std::string_view id,
                        Scenario scenario, float average) {
  auto rows = project.rows(scenario_table("RUNUP", scenario), id);
  std::vector<Point> points;
  for (const auto &r : rows)
    if (numeric(r, "REMOVESTATUS") == 0)
      points.push_back({numeric(r, "STATION_B"), numeric(r, "ELEVATION_B")});
  std::stable_sort(points.begin(), points.end(),
                   [](auto a, auto b) { return a.station < b.station; });
  std::vector<Json> zones;
  if (points.size() < 2) {
    project.replace_rows(scenario_table("RUNUP ZONE", scenario), id, {});
    return;
  }
  const auto p = project.parameters(id, scenario);
  // Original CHAMP uses its mean runup here, although its separate 2% estimate
  // multiplies the mean by 2.23. Retain that distinction in the saved tables.
  const float boundary = double(p.stillwater) + average - 3;
  const Line water{0, -1, boundary};
  for (std::size_t i = 1; i < points.size(); ++i) {
    auto a = points[i - 1], b = points[i];
    if (boundary < a.elevation || boundary > b.elevation)
      continue;
    const auto corner = intersect(general_line(a, b), water);
    if (corner.station < a.station || corner.station > b.station)
      continue;
    zones.push_back(zone(points.front(), corner, "VE"));
    zones.push_back(zone(corner, points.back(), "AE"));
    break;
  }
  if (zones.empty())
    zones.push_back(zone(points.front(), points.back(),
                         boundary >= points.back().elevation ? "VE" : "AE"));
  project.replace_rows(scenario_table("RUNUP ZONE", scenario), id,
                       std::move(zones));
}
} // namespace legacy::champ::detail
