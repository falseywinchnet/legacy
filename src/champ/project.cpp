// SPDX-License-Identifier: MIT
#include "legacy/project.hpp"
#include <algorithm>
#include <chrono>
#include <cmath>
#include <fstream>
#include <set>
#include <stdexcept>
#ifdef _WIN32
#define NOMINMAX
#include <windows.h>
#endif

namespace legacy::champ {
namespace {
std::string lower(std::string s) {
  for (auto &c : s)
    if (c >= 'A' && c <= 'Z')
      c += 'a' - 'A';
  return s;
}
const Json *cell(const Json &row, std::string_view name) {
  if (auto it = row.find(std::string(name)); it != row.end())
    return &*it;
  const auto target = lower(std::string(name));
  for (auto it = row.begin(); it != row.end(); ++it)
    if (lower(it.key()) == target)
      return &*it;
  return nullptr;
}
void valid_id(std::string_view id) {
  if (id.empty() || id.size() > 15 || id.find_first_of("\r\n\t") != id.npos)
    throw std::invalid_argument("A transect ID must contain 1 to 15 "
                                "characters, without tabs or newlines.");
}
std::string profile_table(ProfileKind kind, Scenario scenario) {
  if (kind == ProfileKind::surveyed)
    return "TRANSECT";
  if (kind == ProfileKind::adjusted)
    return "ADJTRANS";
  return scenario_table("EROSION", scenario);
}
void update_count(Project &p) {
  p.metadata()["NUMBER TRANSECT"] = std::to_string(p.transects().size());
}
} // namespace
float numeric(const Json &row, std::string_view field, float fallback) {
  const auto *v = cell(row, field);
  if (!v || v->is_null())
    return fallback;
  if (v->is_number())
    return v->get<float>();
  if (v->is_boolean())
    return v->get<bool>() ? 1.f : 0.f;
  if (v->is_string()) {
    auto s = v->get<std::string>();
    if (s.empty())
      return fallback;
    try {
      std::size_t used;
      const float n = std::stof(s, &used);
      if (s.find_first_not_of(' ', used) == s.npos && std::isfinite(n))
        return n;
    } catch (const std::exception &) {
    }
  }
  throw std::invalid_argument("Invalid numeric value in " + std::string(field));
}
std::string textual(const Json &row, std::string_view field,
                    std::string fallback) {
  const auto *v = cell(row, field);
  if (!v || v->is_null())
    return fallback;
  return v->is_string() ? v->get<std::string>() : v->dump();
}
std::string scenario_table(std::string_view base, Scenario scenario) {
  return std::string(base) +
         (scenario == Scenario::annual_0_2_percent ? "_500" : "");
}
Project Project::create(std::string title) {
  Project p;
  p.tables["PROJECT"].rows.push_back({{"TITLE", std::move(title)},
                                      {"ENGINEER NAME", ""},
                                      {"CLIENT NAME", ""},
                                      {"COMMUNITY NAME", ""},
                                      {"NUMBER TRANSECT", "0"},
                                      {"VDATUM", "NAVD 88"},
                                      {"PROJECTION", "Lat/Long"},
                                      {"UNITS", "English"},
                                      {"SCALE", ""}});
  return p;
}
Project Project::open(const std::filesystem::path &path) {
  std::ifstream input(path, std::ios::binary);
  if (!input)
    throw std::runtime_error("Cannot open project: " + path.string());
  std::array<char, 20> signature{};
  input.read(signature.data(), signature.size());
  if (std::string_view(signature.data() + 4, 15) ==
      std::string_view("Standard Jet DB", 15)) {
    Project p;
    p.tables = database::read_access(path);
    if (!p.tables.contains("PROJECT") || !p.tables.contains("TRANSECTCTL"))
      throw std::runtime_error("This Access file is not a CHAMP project.");
    return p;
  }
  input.clear();
  input.seekg(0);
  return deserialize(Json::parse(input));
}
Json Project::serialize() const {
  Json encoded = Json::object();
  for (const auto &[name, table] : tables) {
    Json columns = Json::array();
    for (const auto &c : table.columns)
      columns.push_back({{"name", c.name}, {"type", c.type}});
    encoded[name] = {{"columns", columns}, {"rows", table.rows}};
  }
  return {{"format", "Legacy Coastal Project"},
          {"version", 1},
          {"tables", encoded},
          {"documents", documents}};
}
Project Project::deserialize(const Json &document) {
  if (document.value("format", "") != "Legacy Coastal Project" ||
      document.value("version", 0) != 1)
    throw std::runtime_error("Unsupported coastal project format or version.");
  Project p;
  for (const auto &[name, encoded] : document.at("tables").items()) {
    auto &table = p.tables[name];
    for (const auto &c : encoded.at("columns"))
      table.columns.push_back({c.at("name"), c.at("type")});
    for (const auto &r : encoded.at("rows")) {
      if (!r.is_object())
        throw std::runtime_error("A project table contains an invalid row.");
      table.rows.push_back(r);
    }
  }
  p.documents = document.value("documents", Json::object());
  if (!p.documents.is_object() || !p.tables.contains("PROJECT") ||
      p.tables.at("PROJECT").rows.size() != 1)
    throw std::runtime_error("The project header is missing or invalid.");
  std::set<std::string> ids;
  for (const auto &id : p.transects()) {
    valid_id(id);
    if (!ids.insert(lower(id)).second)
      throw std::runtime_error("Duplicate transect ID.");
  }
  return p;
}
void Project::save(const std::filesystem::path &path) const {
  if (lower(path.extension().string()) == ".mdb" ||
      lower(path.extension().string()) == ".accdb")
    throw std::invalid_argument("Save as a .coastal project; original Access "
                                "files are imported read-only.");
  auto temporary = path;
  temporary +=
      "." +
      std::to_string(
          std::chrono::steady_clock::now().time_since_epoch().count()) +
      ".tmp";
  try {
    std::ofstream out(temporary, std::ios::binary | std::ios::trunc);
    if (!out)
      throw std::runtime_error("Cannot create project: " + path.string());
    out << serialize().dump(2) << '\n';
    out.flush();
    if (!out)
      throw std::runtime_error("Could not finish writing project: " +
                               path.string());
    out.close();
#ifdef _WIN32
    if (!MoveFileExW(temporary.c_str(), path.c_str(),
                     MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH))
      throw std::runtime_error("Could not replace the saved project.");
#else
    std::filesystem::rename(temporary, path);
#endif
  } catch (...) {
    std::error_code ec;
    std::filesystem::remove(temporary, ec);
    throw;
  }
}
Json &Project::metadata() { return tables.at("PROJECT").rows.at(0); }
const Json &Project::metadata() const {
  return tables.at("PROJECT").rows.at(0);
}
std::vector<std::string> Project::transects() const {
  std::vector<std::string> ids;
  if (auto it = tables.find("TRANSECTCTL"); it != tables.end())
    for (const auto &r : it->second.rows)
      ids.push_back(textual(r, "trans_id"));
  std::sort(ids.begin(), ids.end());
  return ids;
}
Json &Project::transect(std::string_view id) {
  for (auto &r : tables["TRANSECTCTL"].rows)
    if (textual(r, "trans_id") == id)
      return r;
  throw std::invalid_argument("Unknown transect: " + std::string(id));
}
const Json &Project::transect(std::string_view id) const {
  if (auto it = tables.find("TRANSECTCTL"); it != tables.end())
    for (const auto &r : it->second.rows)
      if (textual(r, "trans_id") == id)
        return r;
  throw std::invalid_argument("Unknown transect: " + std::string(id));
}
void Project::add_transect(std::string id) {
  valid_id(id);
  for (const auto &existing : transects())
    if (lower(existing) == lower(id))
      throw std::invalid_argument("That transect ID already exists.");
  tables["TRANSECTCTL"].rows.push_back({{"trans_id", id},
                                        {"JOBNUMBER", "1"},
                                        {"LASTSLOPE", 7.f},
                                        {"SPREAD", 5.f},
                                        {"SPREAD500", 5.f}});
  update_count(*this);
}
void Project::copy_transect(std::string_view source, std::string destination) {
  transect(source);
  valid_id(destination);
  for (const auto &id : transects())
    if (lower(id) == lower(destination))
      throw std::invalid_argument("That transect ID already exists.");
  for (auto &[name, table] : tables) {
    std::vector<Json> copies;
    for (const auto &r : table.rows)
      if (textual(r, "trans_id") == source) {
        auto copy = r;
        copy["trans_id"] = destination;
        copies.push_back(std::move(copy));
      }
    table.rows.insert(table.rows.end(), copies.begin(), copies.end());
  }
  if (documents.contains(std::string(source)))
    documents[destination] = documents.at(std::string(source));
  update_count(*this);
}
void Project::rename_transect(std::string_view source,
                              std::string destination) {
  if (source == destination)
    return;
  copy_transect(source, std::move(destination));
  delete_transect(source);
}
void Project::delete_transect(std::string_view id) {
  transect(id);
  for (auto &[name, table] : tables)
    std::erase_if(table.rows,
                  [&](const Json &r) { return textual(r, "trans_id") == id; });
  documents.erase(std::string(id));
  update_count(*this);
}
std::vector<Json> Project::rows(std::string_view table,
                                std::string_view id) const {
  std::vector<Json> result;
  if (auto it = tables.find(std::string(table)); it != tables.end())
    for (const auto &r : it->second.rows)
      if (textual(r, "trans_id") == id)
        result.push_back(r);
  return result;
}
void Project::replace_rows(std::string_view name, std::string_view id,
                           std::vector<Json> replacement) {
  transect(id);
  for (auto &r : replacement) {
    if (!r.is_object())
      throw std::invalid_argument("Invalid table row.");
    r["trans_id"] = id;
  }
  auto &table = tables[std::string(name)];
  std::erase_if(table.rows,
                [&](const Json &r) { return textual(r, "trans_id") == id; });
  table.rows.insert(table.rows.end(), replacement.begin(), replacement.end());
  // Preserve original schema; add a descriptive type for newly introduced
  // fields.
  for (const auto &r : replacement)
    for (auto it = r.begin(); it != r.end(); ++it)
      if (std::none_of(table.columns.begin(), table.columns.end(),
                       [&](const auto &c) { return c.name == it.key(); }))
        table.columns.push_back({it.key(), it->is_string()    ? 10u
                                           : it->is_boolean() ? 1u
                                                              : 6u});
}
Parameters Project::parameters(std::string_view id, Scenario s) const {
  const auto &r = transect(id);
  const bool five = s == Scenario::annual_0_2_percent;
  Parameters p;
  p.stillwater = numeric(r, five ? "SWFL500" : "SWFL1");
  p.ten_year_stillwater = numeric(r, "SWFL10");
  p.fifty_year_stillwater = numeric(r, "SWFL50");
  p.significant_height = numeric(r, five ? "DWH500" : "DWH");
  p.peak_period = numeric(r, five ? "DWP500" : "DWP");
  p.wave_setup = numeric(r, five ? "WSM500" : "WSM");
  p.fetch_miles = numeric(r, "FETCHLEN");
  p.mean_height =
      numeric(r, five ? "MDWH500" : "MDWH",
              static_cast<float>(double(p.significant_height) * .626));
  p.mean_period = numeric(r, five ? "MDWP500" : "MDWP",
                          static_cast<float>(double(p.peak_period) * .85));
  p.spread_percent = numeric(r, five ? "SPREAD500" : "SPREAD", 5);
  p.last_slope = numeric(r, "LASTSLOPE", 7);
  p.wind_overwater =
      numeric(r, five ? "WINDOF500" : "WINDOF", five ? 100.f : 80.f);
  p.wind_inland = numeric(r, five ? "WINDIF500" : "WINDIF", five ? 75.f : 60.f);
  p.wind_vegetation =
      numeric(r, five ? "WINDVH500" : "WINDVH", five ? 75.f : 60.f);
  return p;
}
void Project::set_parameters(std::string_view id, Scenario s,
                             const Parameters &p) {
  auto &r = transect(id);
  const bool five = s == Scenario::annual_0_2_percent;
  const auto put = [&](const char *one, const char *five_key, float v) {
    if (!std::isfinite(v))
      throw std::invalid_argument("Parameters must be finite numbers.");
    r[five ? five_key : one] = v;
  };
  put("SWFL1", "SWFL500", p.stillwater);
  put("SWFL10", "SWFL10", p.ten_year_stillwater);
  put("SWFL50", "SWFL50", p.fifty_year_stillwater);
  put("DWH", "DWH500", p.significant_height);
  put("DWP", "DWP500", p.peak_period);
  put("WSM", "WSM500", p.wave_setup);
  put("FETCHLEN", "FETCHLEN", p.fetch_miles);
  put("MDWH", "MDWH500", p.mean_height);
  put("MDWP", "MDWP500", p.mean_period);
  put("SPREAD", "SPREAD500", p.spread_percent);
  put("LASTSLOPE", "LASTSLOPE", p.last_slope);
  put("WINDOF", "WINDOF500", p.wind_overwater);
  put("WINDIF", "WINDIF500", p.wind_inland);
  put("WINDVH", "WINDVH500", p.wind_vegetation);
}
std::vector<TransectPoint>
Project::profile(std::string_view id, ProfileKind kind, Scenario s) const {
  std::vector<TransectPoint> points;
  for (const auto &r : rows(profile_table(kind, s), id))
    points.push_back(
        {numeric(r, kind == ProfileKind::adjusted ? "ADJSTATION" : "STATION"),
         numeric(r, "ELEVATION"), textual(r, "SOURCE")});
  std::stable_sort(
      points.begin(), points.end(),
      [](const auto &a, const auto &b) { return a.station < b.station; });
  return points;
}
std::vector<TransectPoint> Project::analysis_profile(std::string_view id,
                                                     Scenario s) const {
  auto points = profile(id, ProfileKind::eroded, s);
  if (points.empty())
    points = profile(id, ProfileKind::adjusted, s);
  if (points.empty())
    throw std::invalid_argument(
        "Adjust the transect before preparing an analysis.");
  validate_profile(points);
  return points;
}
void Project::set_profile(std::string_view id, ProfileKind kind,
                          std::span<const TransectPoint> points, Scenario s) {
  validate_profile(points);
  std::vector<Json> replacement;
  for (const auto &p : points) {
    Json r = {{"STATION", p.station},
              {"ELEVATION", p.elevation},
              {"SOURCE", p.source}};
    if (kind == ProfileKind::adjusted)
      r["ADJSTATION"] = p.station;
    replacement.push_back(std::move(r));
  }
  replace_rows(profile_table(kind, s), id, std::move(replacement));
}
void Project::adjust(std::string_view id, std::optional<float> shoreline) {
  auto source = profile(id, ProfileKind::surveyed);
  auto adjusted = adjust_shoreline(source, shoreline);
  const float offset = source.front().station - adjusted.front().station;
  std::vector<Json> replacement;
  for (const auto &p : adjusted)
    replacement.push_back(
        {{"STATION", static_cast<float>(double(p.station) + offset)},
         {"ADJSTATION", p.station},
         {"ELEVATION", p.elevation},
         {"SOURCE", p.source}});
  replace_rows("ADJTRANS", id, std::move(replacement));
}
} // namespace legacy::champ
