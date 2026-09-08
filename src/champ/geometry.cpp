#include "legacy/champ_geometry.hpp"
#include <cmath>
#include <utility>

namespace legacy::champ {
float interpolate(float y1, float y2, float x1, float x2, float x) {
  const float dy = double(y2) - y1;
  const float dx = double(x2) - x1;
  float change = 0;
  if (dx != 0 && dy != 0) {
    const float slope = double(dy) / dx;
    const float distance = double(x) - x1;
    change = double(distance) * slope;
  }
  return float(double(y1) + change);
}
Line general_line(Point first, Point second) {
  const double x1 = first.station, y1 = first.elevation;
  const double x2 = second.station, y2 = second.elevation;
  if (x1 == x2)
    return {-1, 0, float((x1 + x2) * .5)};
  return {float((y2 - y1) / (x2 - x1)), -1,
          float((y1 * x2 - x1 * y2) / (x2 - x1))};
}
Point intersect(Line first, Line second) {
  const float denominator = double(second.a) - first.a;
  if (denominator == 0)
    return {-99999, -99999};
  return {float((double(first.c) - second.c) / denominator),
          float((double(second.a) * first.c - double(first.a) * second.c) /
                denominator)};
}
namespace {
// Retain the residual of each addition. The original VB runtime keeps this
// final expression in x87 extended registers until its Double return store.
// All products here are exact products of two binary32 coordinates.
std::pair<double, double> sum_and_residual(double a, double b) {
  const double sum = a + b;
  const double from_b = sum - a;
  return {sum, (a - (sum - from_b)) + (b - from_b)};
}
double final_sum(double sum, double positive, double negative) {
  const auto [first, first_error] = sum_and_residual(sum, positive);
  const auto [second, second_error] = sum_and_residual(first, -negative);
  return second + (first_error + second_error);
}
} // namespace
double polygon_area(std::span<const Point> vertices) {
  if (vertices.size() < 3)
    return 0;
  float sum = 0;
  for (std::size_t i = 1; i < vertices.size(); ++i) {
    const auto p = vertices[i - 1], q = vertices[i];
    sum = double(sum) + double(p.station) * q.elevation -
          double(p.elevation) * q.station;
  }
  const auto first = vertices.front(), last = vertices.back();
  return .5 * std::abs(final_sum(sum, double(last.station) * first.elevation,
                                 double(last.elevation) * first.station));
}
} // namespace legacy::champ
