// SPDX-License-Identifier: MIT
#include "legacy/project.hpp"
#include <bit>
#include <fstream>
#include <iostream>
#include <stdexcept>
using namespace legacy::champ;
namespace {
void require(bool condition, const char *message) {
  if (!condition)
    throw std::runtime_error(message);
}
void write(const std::filesystem::path &path, const std::string &value) {
  std::ofstream out(path, std::ios::binary);
  out << value;
  if (!out)
    throw std::runtime_error("Cannot write test output.");
}
} // namespace
int main(int argc, char **argv) {
  try {
    if (argc != 3)
      throw std::runtime_error("project_probe ROOT OUTPUT_DIRECTORY");
    const std::filesystem::path root(argv[1]), output(argv[2]);
    std::filesystem::create_directories(output);
    auto p = Project::open(root / "originals/champ2/sample.mdb");
    const auto before = p.serialize();
    require(p.transects().size() == 4, "Four imported transects expected.");
    p.save(output / "sample.coastal");
    require(Project::open(output / "sample.coastal").serialize() == before,
            "Saved project lost imported data.");
    p.copy_transect("1", "copy");
    require(p.profile("copy", ProfileKind::eroded).size() ==
                p.profile("1", ProfileKind::eroded).size(),
            "Copy lost profile rows.");
    p.rename_transect("copy", "renamed");
    p.delete_transect("renamed");
    require(p.serialize() == before, "Copy/rename/delete altered source data.");
    const auto one = Scenario::annual_1_percent,
               five = Scenario::annual_0_2_percent;
    for (const auto &id : p.transects()) {
      const auto runup = p.run_runup(id, one);
      write(output / ("r" + id + ".dat"), runup.input);
      write(output / ("r" + id + ".out"), runup.report);
      const auto whafis = p.run_whafis(
          id, one, {"INPUT.DAT", "OUTPUT.OUT", "reference project test", ""});
      require(whafis.error.empty(),
              "Imported WHAFIS project calculation failed.");
      write(output / ("w" + id + ".dat"),
            p.documents.at(id).at("100").at("whafis").at("input"));
      write(output / ("w" + id + ".out"), whafis.text);
      auto geometry = p.erosion_settings(id, one);
      auto erosion = assess_erosion(p.profile(id, ProfileKind::adjusted),
                                    p.parameters(id, one), geometry, one);
      require(erosion.retreat == (id == "1" || id == "4"),
              "Original dune treatment classification differs.");
      if (erosion.retreat) {
        const auto imported = p.profile(id, ProfileKind::eroded);
        require(imported.size() == erosion.profile.size(),
                "Original retreat point count differs.");
        for (std::size_t i = 0; i < imported.size(); ++i) {
          if (std::bit_cast<unsigned>(imported[i].station) !=
                  std::bit_cast<unsigned>(erosion.profile[i].station) ||
              std::bit_cast<unsigned>(imported[i].elevation) !=
                  std::bit_cast<unsigned>(erosion.profile[i].elevation)) {
            std::cerr << id << " retreat point " << i << ": original "
                      << imported[i].station << "," << imported[i].elevation
                      << " native " << erosion.profile[i].station << ","
                      << erosion.profile[i].elevation << '\n';
            throw std::runtime_error("Original retreat coordinates differ.");
          }
        }
      } else {
        const auto r = p.rows("GEOMETRY", id).at(0);
        require(erosion.removal_end.station == numeric(r, "REMOVE_X") &&
                    erosion.removal_end.elevation == numeric(r, "REMOVE_Y"),
                "Original removal intersection differs.");
      }
    }
    auto baseline_one = p.rows("EROSION", "1");
    auto params = p.parameters("1", one);
    p.set_parameters("1", five, params);
    p.erode("1", five, p.erosion_settings("1", one));
    require(p.rows("EROSION", "1") == baseline_one,
            "500-year erosion overwrote 100-year erosion.");
    p.populate_runup("1", five);
    p.run_runup("1", five);
    p.populate_whafis("1", five);
    auto report = p.run_whafis("1", five);
    require(report.error.empty() && !report.transects.empty(),
            "Prepared 500-year WHAFIS workflow failed.");
    p.save(output / "analysed.coastal");
    require(Project::open(output / "analysed.coastal").serialize() ==
                p.serialize(),
            "Analysis documents did not survive save/reopen.");
    auto fresh = Project::create("New project");
    fresh.add_transect("A");
    const std::vector<TransectPoint> raw{{10, -5, "Survey"},
                                         {110, 5, "Survey"},
                                         {210, 15, "Survey"},
                                         {410, 9, "Survey"}};
    fresh.set_profile("A", ProfileKind::surveyed, raw);
    fresh.adjust("A");
    const auto adjusted = fresh.profile("A", ProfileKind::adjusted);
    require(adjusted.size() == 5 && adjusted[1].station == 0 &&
                adjusted[1].elevation == 0,
            "New transect shoreline adjustment failed.");
    require(numeric(fresh.rows("ADJTRANS", "A")[1], "STATION") == 60,
            "Adjustment lost original station.");
    std::cout << "Project import/save, transect operations, original erosion "
                 "coordinates, eight engine analyses, and separate scenarios "
                 "passed.\n";
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
}
