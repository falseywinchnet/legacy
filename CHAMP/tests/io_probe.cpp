// SPDX-License-Identifier: MIT
#include "legacy/project_io.hpp"
#include <bit>
#include <cmath>
#include <iostream>
#include <limits>
#include <stdexcept>
using namespace legacy::champ;
namespace {
void require(bool ok, const char *message) {
  if (!ok)
    throw std::runtime_error(message);
}
template <class F> void rejects(F operation, const char *message) {
  try {
    operation();
  } catch (const std::exception &) {
    return;
  }
  throw std::runtime_error(message);
}
void same(const std::vector<TransectPoint> &a,
          const std::vector<TransectPoint> &b) {
  require(a.size() == b.size(), "Profile round trip lost points.");
  for (std::size_t i = 0; i < a.size(); ++i)
    require(std::bit_cast<unsigned>(a[i].station) ==
                    std::bit_cast<unsigned>(b[i].station) &&
                std::bit_cast<unsigned>(a[i].elevation) ==
                    std::bit_cast<unsigned>(b[i].elevation),
            "Profile round trip changed float bits.");
}
} // namespace
int main() {
  try {
    const std::vector<TransectPoint> p{
        {-1234.56789f, -12.34567f, "Survey, \"one\""},
        {0, 0, "Shore\ncontinued"},
        {123.456789f, 37.987654f, "Dune"}};
    const auto csv = parse_profile_text(profile_csv(p)).at(0).points;
    same(p, csv);
    require(csv[0].source == p[0].source && csv[1].source == p[1].source,
            "CSV quoting damaged a source name.");
    const auto tab =
        parse_profile_text(
            "station\televation\tsource\n100\t12\tDune\n0\t-5\tSea\n")
            .at(0);
    require(tab.points[0].station == 0 && tab.points[1].elevation == 12,
            "TSV import/sorting failed.");
    const auto space = parse_profile_text("# profile\n-10 -5\n100 12\n").at(0);
    require(space.points.size() == 2, "Whitespace import failed.");
    const auto dxf = parse_profile_text(
        profiles_dxf({{"Survey", p}, {"Second", tab.points}}), "", ".DXF");
    require(dxf.size() == 2 && dxf[0].name == "Survey" &&
                dxf[1].name == "Second",
            "DXF lost layers.");
    same(p, dxf[0].points);
    same(tab.points, dxf[1].points);
    const auto svg = profiles_svg("A&B <study>", {{"<survey>", p}});
    require(svg.find("A&amp;B &lt;study&gt;") != svg.npos &&
                svg.find("&lt;survey&gt;") != svg.npos,
            "SVG titles or labels were not escaped.");
    const std::vector<Json> rows{{{"x", 1}, {"note", "a,b\n\"c\""}},
                                 {{"y", 2}}};
    const auto table = table_csv(rows);
    require(table.starts_with("\"note\",\"x\",\"y\"\r\n") &&
                table.find("\"a,b\n\"\"c\"\"\"") != table.npos,
            "Table CSV lost columns or escaped text.");
    rejects([] { parse_profile_text("0,1\n0,2\n"); },
            "Duplicate stations accepted.");
    rejects([] { parse_profile_text("0,nan\n1,2\n"); },
            "NaN coordinate accepted.");
    rejects([] { parse_profile_text("0,1\n1,inf\n"); },
            "Infinite coordinate accepted.");
    rejects([] { parse_profile_text("0,1\n1,2,\"bad\n"); },
            "Unterminated quote accepted.");
    rejects([] { parse_profile_text("0\nLINE\n10", "", ".dxf"); },
            "Truncated DXF accepted.");
    auto project = Project::create();
    project.add_transect("A");
    auto before = project.serialize();
    auto parameters = project.parameters("A", Scenario::annual_1_percent);
    parameters.stillwater = 123;
    parameters.wind_vegetation = std::numeric_limits<float>::quiet_NaN();
    rejects(
        [&] {
          project.set_parameters("A", Scenario::annual_1_percent, parameters);
        },
        "Invalid parameter accepted.");
    require(project.serialize() == before,
            "Invalid parameter update partially modified project.");
    std::cout << "CSV/TSV, exact DXF/profile round trips, SVG escaping, "
                 "invalid inputs, and atomic parameters passed.\n";
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
}
