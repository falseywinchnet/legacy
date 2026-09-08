#pragma once

#include <filesystem>
#include <map>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

namespace legacy::database {
using Value = nlohmann::json;
struct Column {
  std::string name;
  unsigned type{};
};
struct Table {
  std::vector<Column> columns;
  std::vector<Value> rows;
};
using Tables = std::map<std::string, Table>;

// Reads the actual Jet 3 / Jet 4 file. No Access, ODBC driver, or external
// process. Tables retain their original names, columns, nulls, and row values.
Tables read_access(const std::filesystem::path &path);
} // namespace legacy::database
