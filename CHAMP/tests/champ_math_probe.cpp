#include "legacy/champ_geometry.hpp"
#include <array>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char **argv) {
  if (argc != 4)
    return 2;
  std::string routine = argv[1];
  std::ifstream input(argv[2], std::ios::binary);
  std::ofstream output(argv[3], std::ios::binary);
  if (!input || !output)
    return 2;
  unsigned size = routine == "polygon"        ? 17
                  : routine == "intersection" ? 6
                  : routine == "line"         ? 4
                                              : 5;
  std::array<float, 17> values{};
  using namespace legacy::champ;
  while (input.read(reinterpret_cast<char *>(values.data()), size * 4)) {
    const auto &v = values;
    if (routine == "interpolate") {
      float result = interpolate(v[0], v[1], v[2], v[3], v[4]);
      output.write(reinterpret_cast<const char *>(&result), 4);
    } else if (routine == "line") {
      auto result = general_line({v[0], v[1]}, {v[2], v[3]});
      for (auto r : {result.a, result.b, result.c})
        output.write(reinterpret_cast<const char *>(&r), 4);
    } else if (routine == "intersection") {
      auto result = intersect({v[0], v[1], v[2]}, {v[3], v[4], v[5]});
      for (auto r : {result.station, result.elevation})
        output.write(reinterpret_cast<const char *>(&r), 4);
    } else if (routine == "polygon") {
      std::vector<Point> points;
      for (int i = 0; i < int(v[0]); ++i)
        points.push_back({v[1 + i], v[9 + i]});
      double result = polygon_area(points);
      output.write(reinterpret_cast<const char *>(&result), 8);
    } else
      return 2;
  }
}
