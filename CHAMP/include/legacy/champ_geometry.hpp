#pragma once
#include <span>

namespace legacy::champ {
struct Point {
  float station{}, elevation{};
};
struct Line {
  float a{}, b{}, c{};
};

// The original CHAMP interpolation has explicit Single storage after each
// subtraction, division, and multiplication. Its arguments are y1,y2,x1,x2,x.
float interpolate(float y1, float y2, float x1, float x2, float x);
Line general_line(Point first, Point second);
// Historical CHAMP intersection: designed for the b=-1 slope/intercept lines
// used by its erosion workflow. Parallel lines return the original sentinel.
Point intersect(Line first, Line second);
double polygon_area(std::span<const Point> vertices);
} // namespace legacy::champ
