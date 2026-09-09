// SPDX-License-Identifier: MIT
#pragma once
#include "project.hpp"
namespace legacy::champ {
struct ProfileImport {
  std::string name;
  std::vector<TransectPoint> points;
};
std::vector<ProfileImport> parse_profile_text(std::string text,
                                              std::string name = "Imported",
                                              std::string extension = ".csv");
std::vector<ProfileImport> read_profiles(const std::filesystem::path &path);
std::string profile_csv(std::span<const TransectPoint> points);
std::string table_csv(std::span<const Json> rows);
std::string profiles_dxf(const std::vector<ProfileImport> &profiles);
std::string profiles_svg(std::string_view title,
                         const std::vector<ProfileImport> &profiles);
void write_text_file(const std::filesystem::path &path, std::string_view text);
std::string read_text_file(const std::filesystem::path &path);
} // namespace legacy::champ
