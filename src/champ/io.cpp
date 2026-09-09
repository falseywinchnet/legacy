// SPDX-License-Identifier: MIT
#include "legacy/project_io.hpp"
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <locale>
#include <set>
#include <sstream>
#include <stdexcept>

namespace legacy::champ {
namespace {
std::string trim(std::string s) {
  auto b = s.find_first_not_of(" \t\r\n");
  return b == s.npos ? "" : s.substr(b, s.find_last_not_of(" \t\r\n") - b + 1);
}
std::string quote(std::string_view text) {
  std::string result = "\"";
  for (char c : text) {
    if (c == '"')
      result += '"';
    result += c;
  }
  return result + '"';
}
std::string xml(std::string_view s) {
  std::string o;
  for (char c : s) {
    if (c == '&')
      o += "&amp;";
    else if (c == '<')
      o += "&lt;";
    else if (c == '>')
      o += "&gt;";
    else if (c == '"')
      o += "&quot;";
    else
      o += c;
  }
  return o;
}
std::vector<std::string> fields(std::string_view line, char separator) {
  std::vector<std::string> result;
  std::string current;
  bool quoted = false;
  for (std::size_t i = 0; i < line.size(); ++i) {
    char c = line[i];
    if (c == '"') {
      if (quoted && i + 1 < line.size() && line[i + 1] == '"') {
        current += '"';
        ++i;
      } else
        quoted = !quoted;
    } else if (!quoted && (c == separator || (separator == ' ' && c == '\t'))) {
      if (separator != ' ' || !current.empty())
        result.push_back(trim(current));
      current.clear();
    } else
      current += c;
  }
  if (quoted)
    throw std::runtime_error("An imported CSV row has an unfinished quote.");
  if (separator != ' ' || !current.empty())
    result.push_back(trim(current));
  return result;
}
float number(const std::string &s) {
  std::size_t used{};
  float value = std::stof(s, &used);
  if (used != s.size() || !std::isfinite(value))
    throw std::runtime_error("Invalid coordinate: " + s);
  return value;
}
std::vector<ProfileImport> dxf(std::string_view text) {
  std::istringstream in{std::string(text)};
  std::string code, value;
  std::vector<std::pair<int, std::string>> pairs;
  while (std::getline(in, code)) {
    if (!std::getline(in, value))
      throw std::runtime_error("Incomplete DXF group.");
    pairs.push_back({std::stoi(trim(code)), trim(value)});
  }
  std::vector<ProfileImport> result;
  ProfileImport current;
  std::string entity;
  float x{}, y{};
  bool have_x = false, have_y = false;
  int polyline = 0;
  const auto finish_point = [&]() {
    if (have_x && have_y)
      current.points.push_back({x, y, "DXF: " + current.name});
    have_x = have_y = false;
  };
  const auto finish_profile = [&]() {
    finish_point();
    if (current.points.size() >= 2) {
      std::stable_sort(
          current.points.begin(), current.points.end(),
          [](const auto &a, const auto &b) { return a.station < b.station; });
      std::vector<TransectPoint> points;
      for (const auto &p : current.points) {
        if (!points.empty() && p.station == points.back().station &&
            p.elevation == points.back().elevation)
          continue;
        points.push_back(p);
      }
      current.points = std::move(points);
      validate_profile(current.points);
      result.push_back(current);
    }
    current = {};
    polyline = 0;
  };
  for (const auto &[c, v] : pairs) {
    if (c == 0) {
      if (v == "LWPOLYLINE" || v == "POLYLINE" || v == "LINE") {
        finish_profile();
        current.name = v + " " + std::to_string(result.size() + 1);
        polyline = v == "POLYLINE" ? 1 : v == "LWPOLYLINE" ? 2 : 3;
      } else if (v == "VERTEX" && polyline == 1)
        finish_point();
      else if (v == "SEQEND" || v == "ENDSEC" || v == "EOF")
        finish_profile();
      else if (polyline != 1)
        finish_profile();
      entity = v;
      continue;
    }
    if (!polyline)
      continue;
    if (c == 8)
      current.name = v;
    if (c == 10 && (entity == "VERTEX" || polyline == 2 || polyline == 3)) {
      if (polyline == 2)
        finish_point();
      x = number(v);
      have_x = true;
    }
    if (c == 20 && (entity == "VERTEX" || polyline == 2 || polyline == 3)) {
      y = number(v);
      have_y = true;
    }
    if (polyline == 3 && c == 11) {
      finish_point();
      x = number(v);
      have_x = true;
    }
    if (polyline == 3 && c == 21) {
      y = number(v);
      have_y = true;
    }
  }
  finish_profile();
  if (result.empty())
    throw std::runtime_error(
        "No station/elevation polylines were found in this DXF file.");
  return result;
}
} // namespace
std::string read_text_file(const std::filesystem::path &path) {
  std::ifstream in(path, std::ios::binary);
  if (!in)
    throw std::runtime_error("Cannot open " + path.string());
  in.seekg(0, std::ios::end);
  const auto size = in.tellg();
  if (size < 0 || size > 64 * 1024 * 1024)
    throw std::runtime_error("The text file exceeds 64 MB.");
  std::string text(static_cast<std::size_t>(size), '\0');
  in.seekg(0);
  in.read(text.data(), size);
  if (!in)
    throw std::runtime_error("Cannot read " + path.string());
  return text;
}
void write_text_file(const std::filesystem::path &path, std::string_view text) {
  std::ofstream out(path, std::ios::binary);
  if (!out)
    throw std::runtime_error("Cannot create " + path.string());
  out.write(text.data(), text.size());
  out.flush();
  if (!out)
    throw std::runtime_error("Could not finish writing " + path.string());
}
std::vector<ProfileImport> read_profiles(const std::filesystem::path &path) {
  return parse_profile_text(read_text_file(path), path.stem().string(),
                            path.extension().string());
}
std::vector<ProfileImport>
parse_profile_text(std::string text, std::string name, std::string extension) {
  for (auto &c : extension)
    c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
  if (extension == ".dxf")
    return dxf(text);
  if (text.starts_with("\xef\xbb\xbf"))
    text.erase(0, 3);
  std::istringstream in(text);
  std::string line;
  ProfileImport profile{std::move(name), {}};
  bool first = true;
  while (std::getline(in, line)) {
    line = trim(line);
    if (line.empty() || line.starts_with('#'))
      continue;
    char separator = line.find(',') != line.npos    ? ','
                     : line.find('\t') != line.npos ? '\t'
                                                    : ' ';
    const auto v = fields(line, separator);
    if (v.size() < 2)
      throw std::runtime_error("Each profile row needs station and elevation.");
    if (first) {
      first = false;
      auto label = v[0];
      for (auto &c : label)
        c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
      if (label == "station" || label == "distance" || label == "x")
        continue;
    }
    profile.points.push_back(
        {number(v[0]), number(v[1]), v.size() > 2 ? v[2] : "Imported"});
  }
  std::stable_sort(
      profile.points.begin(), profile.points.end(),
      [](const auto &a, const auto &b) { return a.station < b.station; });
  validate_profile(profile.points);
  return {profile};
}
std::string profile_csv(std::span<const TransectPoint> points) {
  std::ostringstream out;
  out.imbue(std::locale::classic());
  out << "station,elevation,source\r\n" << std::setprecision(9);
  for (const auto &p : points)
    out << p.station << ',' << p.elevation << ',' << quote(p.source) << "\r\n";
  return out.str();
}
std::string table_csv(std::span<const Json> rows) {
  std::set<std::string> columns;
  for (const auto &r : rows)
    for (auto i = r.begin(); i != r.end(); ++i)
      columns.insert(i.key());
  std::string out;
  bool first = true;
  for (const auto &c : columns) {
    if (!first)
      out += ',';
    out += quote(c);
    first = false;
  }
  out += "\r\n";
  for (const auto &r : rows) {
    first = true;
    for (const auto &c : columns) {
      if (!first)
        out += ',';
      out += quote(textual(r, c));
      first = false;
    }
    out += "\r\n";
  }
  return out;
}
std::string profiles_dxf(const std::vector<ProfileImport> &profiles) {
  std::ostringstream out;
  out.imbue(std::locale::classic());
  out << std::setprecision(9)
      << "0\nSECTION\n2\nHEADER\n9\n$ACADVER\n1\nAC1015\n9\n$"
         "INSUNITS\n70\n2\n0\nENDSEC\n0\nSECTION\n2\nENTITIES\n";
  for (const auto &profile : profiles) {
    if (profile.points.empty())
      continue;
    std::string name = profile.name;
    for (auto &c : name)
      if (c == '\n' || c == '\r')
        c = '_';
    out << "0\nLWPOLYLINE\n100\nAcDbEntity\n8\n"
        << name << "\n100\nAcDbPolyline\n90\n"
        << profile.points.size() << "\n70\n0\n";
    for (const auto &p : profile.points)
      out << "10\n" << p.station << "\n20\n" << p.elevation << '\n';
  }
  return out.str() + "0\nENDSEC\n0\nEOF\n";
}
std::string profiles_svg(std::string_view title,
                         const std::vector<ProfileImport> &profiles) {
  float xmin = 0, xmax = 1, ymin = 0, ymax = 1;
  bool first = true;
  for (const auto &profile : profiles)
    for (const auto &p : profile.points) {
      if (first) {
        xmin = xmax = p.station;
        ymin = ymax = p.elevation;
        first = false;
      }
      xmin = std::min(xmin, p.station);
      xmax = std::max(xmax, p.station);
      ymin = std::min(ymin, p.elevation);
      ymax = std::max(ymax, p.elevation);
    }
  const double dx = std::max(1., double(xmax) - xmin),
               dy = std::max(1., double(ymax) - ymin);
  ymin -= dy * .08f;
  ymax += dy * .08f;
  const auto x = [&](float value) {
    return 85 + (double(value) - xmin) / dx * 1050;
  };
  const auto y = [&](float value) {
    return 565 - (double(value) - ymin) / (double(ymax) - ymin) * 440;
  };
  std::ostringstream out;
  out.imbue(std::locale::classic());
  out << std::setprecision(9)
      << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"1200\" "
         "height=\"650\" viewBox=\"0 0 1200 650\"><rect width=\"1200\" "
         "height=\"650\" fill=\"#f8fafb\"/><g font-family=\"sans-serif\" "
         "fill=\"#233548\"><text x=\"85\" y=\"48\" font-size=\"26\">"
      << xml(title) << "</text>";
  for (int i = 0; i <= 5; ++i) {
    const float xv = float(xmin + dx * i / 5);
    const float yv = float(ymin + (double(ymax) - ymin) * i / 5);
    out << "<path d=\"M" << x(xv) << " 125V565 M85 " << y(yv)
        << "H1135\" fill=\"none\" stroke=\"#dce3e8\"/><text x=\"" << x(xv)
        << "\" y=\"589\" text-anchor=\"middle\">" << xv
        << "</text><text x=\"73\" y=\"" << y(yv) + 5
        << "\" text-anchor=\"end\">" << yv << "</text>";
  }
  const char *colors[] = {"#366e94", "#91a0ab", "#d97d28", "#008f82"};
  std::size_t i = 0;
  for (const auto &profile : profiles) {
    out << "<text x=\"" << 85 + i * 240 << "\" y=\"89\" fill=\""
        << colors[i % 4] << "\">" << xml(profile.name)
        << "</text><polyline fill=\"none\" stroke=\"" << colors[i % 4]
        << "\" stroke-width=\"2.5\" points=\"";
    for (const auto &p : profile.points)
      out << x(p.station) << ',' << y(p.elevation) << ' ';
    out << "\"/>";
    ++i;
  }
  out << "<text x=\"610\" y=\"628\" text-anchor=\"middle\">Station (ft), "
         "increasing landward</text><text transform=\"translate(23 345) "
         "rotate(-90)\" text-anchor=\"middle\">Elevation (ft)</text></g></svg>";
  return out.str();
}
} // namespace legacy::champ
