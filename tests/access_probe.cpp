#include "legacy/database.hpp"
#include <fstream>
#include <iostream>
int main(int argc, char **argv) {
  if (argc != 3)
    return 2;
  try {
    legacy::database::Value output;
    for (const auto &[name, table] : legacy::database::read_access(argv[1]))
      output[name] = table.rows;
    std::ofstream(argv[2]) << output.dump(2) << '\n';
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
}
