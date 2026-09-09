#include "plot.hpp"
#include <algorithm>
#include <cmath>
#include <cstdio>
namespace legacy::desktop {
std::optional<champ::Point> plot(const char *id, PlotState &s,
                                 const std::vector<PlotSeries> &series,
                                 ImVec2 size, float water, bool select) {
  const auto origin = ImGui::GetCursorScreenPos();
  if (size.x <= 0)
    size.x = ImGui::GetContentRegionAvail().x;
  if (size.y <= 0)
    size.y = 320;
  ImGui::InvisibleButton(id, size,
                         ImGuiButtonFlags_MouseButtonLeft |
                             ImGuiButtonFlags_MouseButtonRight);
  const bool hovered = ImGui::IsItemHovered();
  auto *draw = ImGui::GetWindowDrawList();
  const auto &io = ImGui::GetIO();
  const ImVec2 a{origin.x + 66, origin.y + 35},
      b{origin.x + size.x - 20, origin.y + size.y - 40};
  if (!s.fitted) {
    bool first = true;
    for (const auto &line : series)
      for (const auto &p : line.points) {
        if (first) {
          s.xmin = s.xmax = p.station;
          s.ymin = s.ymax = p.elevation;
          first = false;
        }
        s.xmin = std::min(s.xmin, double(p.station));
        s.xmax = std::max(s.xmax, double(p.station));
        s.ymin = std::min(s.ymin, double(p.elevation));
        s.ymax = std::max(s.ymax, double(p.elevation));
      }
    if (first) {
      s.xmin = 0;
      s.xmax = 100;
      s.ymin = -10;
      s.ymax = 30;
    }
    s.ymin = std::min(s.ymin, double(water));
    s.ymax = std::max(s.ymax, double(water));
    const auto dx = std::max(1., s.xmax - s.xmin),
               dy = std::max(1., s.ymax - s.ymin);
    s.xmin -= dx * .025;
    s.xmax += dx * .025;
    s.ymin -= dy * .1;
    s.ymax += dy * .13;
    s.fitted = true;
  }
  auto mouse_x = [&]() {
    return s.xmin + (io.MousePos.x - a.x) / (b.x - a.x) * (s.xmax - s.xmin);
  };
  auto mouse_y = [&]() {
    return s.ymax - (io.MousePos.y - a.y) / (b.y - a.y) * (s.ymax - s.ymin);
  };
  if (hovered && io.MouseWheel != 0) {
    const auto x = mouse_x(), y = mouse_y(),
               f = std::pow(.82, double(io.MouseWheel));
    s.xmin = x + (s.xmin - x) * f;
    s.xmax = x + (s.xmax - x) * f;
    s.ymin = y + (s.ymin - y) * f;
    s.ymax = y + (s.ymax - y) * f;
  }
  if (hovered && ImGui::IsMouseDragging(ImGuiMouseButton_Right)) {
    const auto dx = io.MouseDelta.x / (b.x - a.x) * (s.xmax - s.xmin),
               dy = io.MouseDelta.y / (b.y - a.y) * (s.ymax - s.ymin);
    s.xmin -= dx;
    s.xmax -= dx;
    s.ymin += dy;
    s.ymax += dy;
  }
  auto x = [&](double v) {
    return float(a.x + (v - s.xmin) / (s.xmax - s.xmin) * (b.x - a.x));
  };
  auto y = [&](double v) {
    return float(b.y - (v - s.ymin) / (s.ymax - s.ymin) * (b.y - a.y));
  };
  draw->AddRectFilled(origin, {origin.x + size.x, origin.y + size.y},
                      IM_COL32(248, 250, 252, 255), 8);
  draw->AddRectFilled(a, b, IM_COL32(255, 255, 255, 255));
  char label[80];
  for (int i = 0; i <= 5; ++i) {
    double xv = s.xmin + (s.xmax - s.xmin) * i / 5,
           yv = s.ymin + (s.ymax - s.ymin) * i / 5;
    const float px = x(xv), py = y(yv);
    draw->AddLine({px, a.y}, {px, b.y}, IM_COL32(227, 233, 238, 255));
    draw->AddLine({a.x, py}, {b.x, py}, IM_COL32(227, 233, 238, 255));
    std::snprintf(label, sizeof(label), "%.4g", xv);
    draw->AddText({px - ImGui::CalcTextSize(label).x / 2, b.y + 8},
                  IM_COL32(91, 106, 122, 255), label);
    std::snprintf(label, sizeof(label), "%.4g", yv);
    draw->AddText({a.x - ImGui::CalcTextSize(label).x - 9, py - 7},
                  IM_COL32(91, 106, 122, 255), label);
  }
  float legend = origin.x + 12;
  for (const auto &line : series) {
    draw->AddLine({legend, origin.y + 15}, {legend + 15, origin.y + 15},
                  line.color, 3);
    draw->AddText({legend + 22, origin.y + 7}, IM_COL32(57, 71, 88, 255),
                  line.label.c_str());
    legend += ImGui::CalcTextSize(line.label.c_str()).x + 50;
  }
  draw->PushClipRect(a, b, true);
  if (y(water) >= a.y && y(water) <= b.y)
    draw->AddLine({a.x, y(water)}, {b.x, y(water)}, IM_COL32(81, 154, 180, 155),
                  1.5f);
  for (const auto &line : series) {
    for (std::size_t i = 1; i < line.points.size(); ++i)
      draw->AddLine(
          {x(line.points[i - 1].station), y(line.points[i - 1].elevation)},
          {x(line.points[i].station), y(line.points[i].elevation)}, line.color,
          2.3f);
    if (line.markers)
      for (const auto &p : line.points)
        draw->AddCircleFilled({x(p.station), y(p.elevation)}, 3.2f, line.color);
  }
  if (hovered && io.MousePos.x >= a.x && io.MousePos.x <= b.x &&
      io.MousePos.y >= a.y && io.MousePos.y <= b.y) {
    draw->AddLine({io.MousePos.x, a.y}, {io.MousePos.x, b.y},
                  IM_COL32(80, 90, 105, 85));
    draw->AddLine({a.x, io.MousePos.y}, {b.x, io.MousePos.y},
                  IM_COL32(80, 90, 105, 85));
    ImGui::SetTooltip(
        "Station %.2f ft\nElevation %.2f ft%s", mouse_x(), mouse_y(),
        select ? "\nClick to select" : "\nScroll to zoom; right-drag to pan");
    if (select)
      ImGui::SetMouseCursor(ImGuiMouseCursor_Hand);
  }
  draw->PopClipRect();
  draw->AddText({origin.x + 5, origin.y + size.y - 18},
                IM_COL32(91, 106, 122, 255), "Elevation (ft)");
  const char *axis = "Station (ft) / landward";
  draw->AddText({b.x - ImGui::CalcTextSize(axis).x, origin.y + size.y - 18},
                IM_COL32(91, 106, 122, 255), axis);
  if (select && hovered && ImGui::IsMouseClicked(ImGuiMouseButton_Left) &&
      io.MousePos.x >= a.x && io.MousePos.x <= b.x && io.MousePos.y >= a.y &&
      io.MousePos.y <= b.y)
    return champ::Point{float(mouse_x()), float(mouse_y())};
  return {};
}
} // namespace legacy::desktop
