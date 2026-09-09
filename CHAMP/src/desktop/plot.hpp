#pragma once
#include "imgui.h"
#include "legacy/project_io.hpp"
#include <optional>
namespace legacy::desktop {
struct PlotSeries {
  std::string label;
  std::vector<champ::TransectPoint> points;
  ImU32 color;
  bool markers{};
};
struct PlotState {
  double xmin{}, xmax{}, ymin{}, ymax{};
  bool fitted{};
};
std::optional<champ::Point> plot(const char *id, PlotState &state,
                                 const std::vector<PlotSeries> &series,
                                 ImVec2 size, float water = 0,
                                 bool select = false);
} // namespace legacy::desktop
