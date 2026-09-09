// SPDX-License-Identifier: MIT
#include "legacy/project.hpp"
#include <algorithm>
#include <charconv>
#include <cmath>
#include <limits>
#include <stdexcept>

namespace legacy::champ {
namespace {
Point point(const TransectPoint &p) { return {p.station, p.elevation}; }
// VB6 CStr(Single), followed by the form's conversion back to Single. CHAMP
// passes geometry through its text boxes between each interactive operation.
float textbox(float x) {
  char buffer[64];
  auto r = std::to_chars(buffer, buffer + sizeof buffer, x,
                         std::chars_format::general, 7);
  float stored{};
  std::from_chars(buffer, r.ptr, stored);
  return stored;
}
Point textbox(Point p) { return {textbox(p.station), textbox(p.elevation)}; }
void append(std::vector<TransectPoint> &v, Point p,
            std::string source = "Erosion treatment") {
  if (!v.empty() && v.back().station == p.station) {
    v.back().elevation = p.elevation;
    return;
  }
  v.push_back({p.station, p.elevation, std::move(source)});
}
std::vector<Point> ground_between(std::span<const TransectPoint> ground,
                                  Point a, Point b) {
  std::vector<Point> polygon{a};
  for (const auto &p : ground)
    if (p.station > a.station && p.station < b.station)
      polygon.push_back(point(p));
  polygon.push_back(b);
  return polygon;
}
double form_area(std::span<const Point> vertices) {
  if (vertices.size() < 3)
    return 0;
  float sum = 0;
  for (std::size_t i = 1; i < vertices.size(); ++i) {
    const auto a = vertices[i - 1], b = vertices[i];
    sum = double(sum) +
          (double(a.station) * b.elevation - double(a.elevation) * b.station);
  }
  // Closing the polygon at its first vertex makes the final cross-product zero.
  // The form retains the final addition until the Double return.
  const auto a = vertices.back(), b = vertices.front();
  return .5 * std::abs(double(sum) + double(a.station) * b.elevation -
                       double(a.elevation) * b.station);
}
Point water_crossing(std::span<const TransectPoint> ground, float level,
                     float before) {
  for (std::size_t i = ground.size() - 1; i > 0; --i) {
    auto a = point(ground[i - 1]), b = point(ground[i]);
    if (a.station >= before || a.elevation > level || b.elevation < level ||
        a.elevation == b.elevation)
      continue;
    const auto line = general_line(a, b);
    Point p{float((double(level) - line.c) / line.a), level};
    if (p.station <= before)
      return textbox(p);
  }
  throw std::invalid_argument("No seaward crossing of the stillwater level was "
                              "found before the selected dune peak.");
}
std::optional<Point> crossing(std::span<const TransectPoint> ground, Line line,
                              float low, float high, bool last) {
  std::optional<Point> result;
  for (std::size_t i = 1; i < ground.size(); ++i) {
    auto a = point(ground[i - 1]), b = point(ground[i]);
    if (a.station > high || b.station < low)
      continue;
    auto p = intersect(line, general_line(a, b));
    if (p.station >= a.station && p.station <= b.station && p.station > low &&
        p.station < high) {
      result = textbox(p);
      if (!last)
        break;
    }
  }
  return result;
}
std::vector<TransectPoint> insert_zero(std::span<const TransectPoint> input) {
  std::vector<TransectPoint> out;
  for (std::size_t i = 0; i < input.size(); ++i) {
    if (i && input[i - 1].elevation * double(input[i].elevation) < 0) {
      const auto a = point(input[i - 1]), b = point(input[i]);
      append(out,
             {float(double(b.station) -
                    double(b.elevation) * (double(b.station) - a.station) /
                        (double(b.elevation) - a.elevation)),
              0},
             "Interpolated");
    }
    append(out, point(input[i]), input[i].source);
  }
  return out;
}
} // namespace
void validate_profile(std::span<const TransectPoint> points) {
  if (points.size() < 2)
    throw std::invalid_argument("A transect needs at least two points.");
  if (points.size() > 100000)
    throw std::invalid_argument(
        "A transect exceeds the supported 100,000 points.");
  for (std::size_t i = 0; i < points.size(); ++i) {
    if (!std::isfinite(points[i].station) ||
        !std::isfinite(points[i].elevation))
      throw std::invalid_argument(
          "Transect coordinates must be finite numbers.");
    if (i && points[i].station <= points[i - 1].station)
      throw std::invalid_argument("Transect stations must increase from sea to "
                                  "land, without duplicates.");
  }
}
Point point_at(std::span<const TransectPoint> points, float station) {
  if (points.size() < 2 || station < points.front().station ||
      station > points.back().station || !std::isfinite(station))
    throw std::invalid_argument(
        "The selected station is outside the transect.");
  for (std::size_t i = 1; i < points.size(); ++i)
    if (station <= points[i].station) {
      auto line = general_line(point(points[i - 1]), point(points[i]));
      return {station, float(-(double(line.a) * station + line.c) / line.b)};
    }
  throw std::invalid_argument("Cannot locate the selected station.");
}
std::vector<TransectPoint>
adjust_shoreline(std::span<const TransectPoint> points,
                 std::optional<float> shoreline) {
  validate_profile(points);
  auto adjusted = insert_zero(points);
  float origin{};
  if (shoreline) {
    origin = *shoreline;
    point_at(points, origin);
  } else {
    auto zero = std::find_if(adjusted.begin(), adjusted.end(),
                             [](const auto &p) { return p.elevation == 0; });
    if (zero == adjusted.end())
      throw std::invalid_argument(
          "The transect does not cross zero elevation. Extend it to the "
          "shoreline before adjusting.");
    origin = zero->station;
  }
  for (auto &p : adjusted)
    p.station = double(p.station) - origin;
  return adjusted;
}
ErosionResult assess_erosion(std::span<const TransectPoint> points,
                             const Parameters &parameters,
                             const ErosionSettings &settings,
                             Scenario scenario) {
  validate_profile(points);
  for (float slope : {settings.face_slope, settings.approach_slope,
                      settings.seaward_slope, settings.removal_slope})
    if (!std::isfinite(slope) || slope <= 0)
      throw std::invalid_argument(
          "Erosion slope denominators must be positive.");
  ErosionResult out;
  out.critical_area = scenario == Scenario::annual_0_2_percent ? 1030.f : 540.f;
  out.peak = textbox(point_at(points, settings.peak_station));
  const float swel = parameters.stillwater;
  if (out.peak.elevation > swel) {
    auto start = water_crossing(points, swel, out.peak.station);
    auto polygon = ground_between(points, start, out.peak);
    polygon.push_back({out.peak.station, swel});
    out.reservoir_area = form_area(polygon);
  }
  out.retreat = out.reservoir_area >= out.critical_area;
  if (!out.retreat) {
    out.toe = textbox(point_at(points, settings.toe_station));
    const auto end_station = std::isfinite(settings.landward_extent)
                                 ? settings.landward_extent
                                 : points.back().station;
    Point extension{end_station, float(double(out.toe.elevation) +
                                       (double(end_station) - out.toe.station) /
                                           settings.removal_slope)};
    auto line = general_line(extension, out.toe);
    const auto end = crossing(
        points, line, out.toe.station,
        std::nextafter(end_station, std::numeric_limits<float>::infinity()),
        false);
    if (!end)
      throw std::invalid_argument(
          "The removal slope does not meet the landward profile. Extend the "
          "transect or change the toe/slope.");
    out.removal_end = *end;
    auto polygon = ground_between(points, out.toe, *end);
    out.eroded_area = form_area(polygon);
    for (const auto &p : points)
      if (p.station < out.toe.station)
        append(out.profile, point(p), p.source);
    append(out.profile, out.toe);
    append(out.profile, *end);
    for (const auto &p : points)
      if (p.station > end->station)
        append(out.profile, point(p), p.source);
  } else {
    out.face = textbox(point_at(points, settings.face_station));
    const Point raw_face_stillwater{
        float(double(out.face.station) -
              (double(out.face.elevation) - swel) * settings.face_slope),
        swel};
    out.face_stillwater = textbox(raw_face_stillwater);
    if (out.face.elevation <= swel)
      throw std::invalid_argument(
          "Select the retreat face above the stillwater level.");
    // CHAMP extends the approach line from the face/SWEL intersection to the
    // seaward graph extent before intersecting the surveyed profile.
    const float seaward_extent = std::isfinite(settings.seaward_extent)
                                     ? settings.seaward_extent
                                     : points.front().station;
    Point extension{seaward_extent,
                    float(double(swel) - (double(raw_face_stillwater.station) -
                                          seaward_extent) /
                                             settings.approach_slope)};
    const auto approach_line = general_line(raw_face_stillwater, extension);
    const auto approach = crossing(
        points, approach_line,
        std::nextafter(seaward_extent, -std::numeric_limits<float>::infinity()),
        out.face_stillwater.station, true);
    if (!approach)
      throw std::invalid_argument(
          "The approach slope does not meet the seaward profile.");
    out.approach = *approach;
    auto eroded = ground_between(points, out.approach, out.face);
    eroded.push_back(out.face_stillwater);
    out.eroded_area = form_area(eroded);
    auto swel_start = water_crossing(points, swel, out.face.station);
    auto above = ground_between(points, swel_start, out.face);
    above.push_back(out.face_stillwater);
    out.eroded_above_stillwater = form_area(above);
    out.seaward = textbox(point_at(points, settings.seaward.station));
    Point seaward_water{
        float(double(out.seaward.station) +
              (double(swel) - out.seaward.elevation) * settings.seaward_slope),
        swel};
    // The original form recomputes its approach line from the two displayed
    // intersection coordinates before calculating the deposit corner.
    out.seaward_approach =
        textbox(intersect(general_line(out.face_stillwater, out.approach),
                          general_line(out.seaward, seaward_water)));
    if (!(out.seaward.station < out.seaward_approach.station &&
          out.seaward_approach.station < out.approach.station))
      throw std::invalid_argument(
          "The seaward and approach slopes do not form a deposit before the "
          "dune. Move the seaward point.");
    auto deposit = ground_between(points, out.seaward, out.approach);
    deposit.push_back(out.seaward_approach);
    out.deposited_area = form_area(deposit);
    for (const auto &p : points)
      if (p.station < out.seaward.station)
        append(out.profile, point(p), p.source);
    for (auto p : {out.seaward, out.seaward_approach, out.approach,
                   out.face_stillwater, out.face})
      append(out.profile, p);
    for (const auto &p : points)
      if (p.station > out.face.station)
        append(out.profile, point(p), p.source);
  }
  out.profile = insert_zero(out.profile);
  validate_profile(out.profile);
  return out;
}
ErosionSettings Project::erosion_settings(std::string_view id,
                                          Scenario scenario) const {
  const auto ground = profile(id, ProfileKind::adjusted);
  validate_profile(ground);
  ErosionSettings s;
  s.seaward_extent = numeric(transect(id), "xmin", ground.front().station);
  s.landward_extent = numeric(transect(id), "xmax", ground.back().station);
  s.peak_station = std::max_element(ground.begin(), ground.end(),
                                    [](const auto &a, const auto &b) {
                                      return a.elevation < b.elevation;
                                    })
                       ->station;
  s.face_station = s.peak_station;
  s.toe_station = ground.front().station;
  s.seaward.station = ground.front().station;
  const auto geometry = rows(scenario_table("GEOMETRY", scenario), id);
  if (geometry.empty()) {
    const auto p = parameters(id, scenario);
    try {
      s.toe_station =
          water_crossing(ground, p.ten_year_stillwater, s.peak_station).station;
    } catch (const std::exception &) {
    }
    auto zero = std::find_if(ground.begin(), ground.end(),
                             [](const auto &p) { return p.elevation == 0; });
    if (zero != ground.end())
      s.seaward.station =
          float((double(ground.front().station) + zero->station) * .5);
    return s;
  }
  const auto &r = geometry.front();
  const auto coordinate = [&](const char *key, float fallback) {
    float v = numeric(r, key, fallback);
    return v == -9999 ? fallback : v;
  };
  s.peak_station = coordinate("PEAK_X", s.peak_station);
  s.toe_station = coordinate("TOE_X", s.toe_station);
  s.face_station = coordinate("FACE_X", s.face_station);
  s.seaward = {coordinate("SEAWARD_X", s.seaward.station),
               coordinate("SEAWARD_Y", 0)};
  s.approach = {coordinate("APPROACH_X", 0), coordinate("APPROACH_Y", 0)};
  s.face_slope = numeric(r, "FACE_SLOPE", 1);
  s.approach_slope = numeric(r, "APPROACH_SLOPE", 40);
  s.seaward_slope = numeric(r, "SEAWARD_SLOPE", 12);
  s.removal_slope = numeric(r, "REMOVE_SLOPE", 50);
  return s;
}
ErosionResult Project::erode(std::string_view id, Scenario scenario,
                             const ErosionSettings &s) {
  auto result = assess_erosion(profile(id, ProfileKind::adjusted),
                               parameters(id, scenario), s, scenario);
  auto old = rows(scenario_table("GEOMETRY", scenario), id);
  Json r = old.empty() ? Json::object() : old.front();
  const auto put = [&](std::string name, Point p) {
    r[name + "_X"] = p.station;
    r[name + "_Y"] = p.elevation;
  };
  put("PEAK", result.peak);
  put("TOE", result.toe);
  put("FACE", result.face);
  put("FACESWFL", result.face_stillwater);
  put("APPROACH", result.approach);
  put("SEAWARD", result.seaward);
  put("SEAWARDAPPROACH", result.seaward_approach);
  put("REMOVE", result.removal_end);
  r["FACE_SLOPE"] = s.face_slope;
  r["APPROACH_SLOPE"] = s.approach_slope;
  r["SEAWARD_SLOPE"] = s.seaward_slope;
  r["REMOVE_SLOPE"] = s.removal_slope;
  r["EROSION_STATUS"] = result.retreat ? "RETREAT" : "REMOVE";
  r["CRITICAL_AREA"] = result.critical_area;
  r["RESERVOIR_AREA"] = result.reservoir_area;
  r["ERODED_AREA"] = result.eroded_area;
  r["ERODED_AREA2"] = result.eroded_above_stillwater;
  r["DEPOSITED_AREA"] = result.deposited_area;
  replace_rows(scenario_table("GEOMETRY", scenario), id, {r});
  set_profile(id, ProfileKind::eroded, result.profile, scenario);
  return result;
}
void Project::clear_erosion(std::string_view id, Scenario s) {
  replace_rows(scenario_table("GEOMETRY", s), id, {});
  replace_rows(scenario_table("EROSION", s), id, {});
}
} // namespace legacy::champ
