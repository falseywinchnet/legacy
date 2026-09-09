// SPDX-License-Identifier: MIT
#pragma once
#include "champ_geometry.hpp"
#include "database.hpp"
#include "runup.hpp"
#include "whafis.hpp"
#include <array>
#include <limits>
#include <optional>

namespace legacy::champ {
using Json = database::Value;
enum class Scenario { annual_1_percent, annual_0_2_percent };
enum class ProfileKind { surveyed, adjusted, eroded };
struct TransectPoint {
  float station{}, elevation{};
  std::string source;
  bool operator==(const TransectPoint &) const = default;
};
struct Parameters {
  float stillwater{}, ten_year_stillwater{}, fifty_year_stillwater{};
  float significant_height{}, peak_period{}, wave_setup{}, fetch_miles{};
  float mean_height{}, mean_period{}, spread_percent{5}, last_slope{7};
  float wind_overwater{80}, wind_inland{60}, wind_vegetation{60};
  bool operator==(const Parameters &) const = default;
};
struct ErosionSettings {
  float peak_station{}, toe_station{}, face_station{};
  Point approach{}, seaward{};
  float seaward_extent{std::numeric_limits<float>::quiet_NaN()};
  float landward_extent{std::numeric_limits<float>::quiet_NaN()};
  float seaward_slope{12}, approach_slope{40}, face_slope{1}, removal_slope{50};
};
struct ErosionResult {
  bool retreat{};
  double reservoir_area{}, eroded_area{}, eroded_above_stillwater{},
      deposited_area{};
  float critical_area{};
  Point peak{}, toe{}, face{}, face_stillwater{}, approach{}, seaward{},
      seaward_approach{}, removal_end{};
  std::vector<TransectPoint> profile;
};
struct WhafisCard {
  std::string kind;
  std::array<std::string, 10> fields{};
  // CM/PS and unusual legacy records can be retained verbatim.
  std::string text;
  bool operator==(const WhafisCard &) const = default;
};
struct RunupSummary {
  runup::ProfileResult result;
  std::string input, report;
  float average_runup{}, two_percent_runup{}, two_percent_elevation{};
};

std::string scenario_table(std::string_view base, Scenario scenario);
void validate_profile(std::span<const TransectPoint> points);
Point point_at(std::span<const TransectPoint> points, float station);
std::vector<TransectPoint>
adjust_shoreline(std::span<const TransectPoint> points,
                 std::optional<float> shoreline = {});
ErosionResult assess_erosion(std::span<const TransectPoint> points,
                             const Parameters &parameters,
                             const ErosionSettings &settings,
                             Scenario scenario);
std::string write_runup_input(const runup::Profile &profile);
std::string write_whafis_input(std::string_view title,
                               std::span<const WhafisCard> cards,
                               Scenario scenario);
std::vector<WhafisCard> read_whafis_cards(std::string_view input);

// Original Access tables are retained, including columns unknown to this
// version. Modern projects use an openly documented JSON envelope and never
// modify an MDB.
class Project {
public:
  database::Tables tables;
  Json documents = Json::object();
  static Project create(std::string title = "Untitled coastal project");
  static Project open(const std::filesystem::path &path);
  void save(const std::filesystem::path &path) const;
  Json serialize() const;
  static Project deserialize(const Json &document);
  Json &metadata();
  const Json &metadata() const;
  std::vector<std::string> transects() const;
  Json &transect(std::string_view id);
  const Json &transect(std::string_view id) const;
  void add_transect(std::string id);
  void copy_transect(std::string_view source, std::string destination);
  void rename_transect(std::string_view source, std::string destination);
  void delete_transect(std::string_view id);
  Parameters parameters(std::string_view id, Scenario scenario) const;
  void set_parameters(std::string_view id, Scenario scenario,
                      const Parameters &parameters);
  std::vector<Json> rows(std::string_view table, std::string_view id) const;
  void replace_rows(std::string_view table, std::string_view id,
                    std::vector<Json> rows);
  std::vector<TransectPoint>
  profile(std::string_view id, ProfileKind kind,
          Scenario scenario = Scenario::annual_1_percent) const;
  std::vector<TransectPoint> analysis_profile(std::string_view id,
                                              Scenario scenario) const;
  void set_profile(std::string_view id, ProfileKind kind,
                   std::span<const TransectPoint> points,
                   Scenario scenario = Scenario::annual_1_percent);
  void adjust(std::string_view id, std::optional<float> shoreline = {});
  ErosionSettings erosion_settings(std::string_view id,
                                   Scenario scenario) const;
  ErosionResult erode(std::string_view id, Scenario scenario,
                      const ErosionSettings &settings);
  void clear_erosion(std::string_view id, Scenario scenario);
  void populate_runup(std::string_view id, Scenario scenario);
  runup::Profile runup_profile(std::string_view id, Scenario scenario) const;
  RunupSummary run_runup(std::string_view id, Scenario scenario);
  std::vector<WhafisCard> whafis_cards(std::string_view id,
                                       Scenario scenario) const;
  void set_whafis_cards(std::string_view id, Scenario scenario,
                        std::span<const WhafisCard> cards);
  void populate_whafis(std::string_view id, Scenario scenario);
  whafis::Report run_whafis(std::string_view id, Scenario scenario,
                            const whafis::Options &options = {});
};
float numeric(const Json &row, std::string_view field, float fallback = 0);
std::string textual(const Json &row, std::string_view field,
                    std::string fallback = {});
} // namespace legacy::champ
