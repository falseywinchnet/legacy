// Development-only independent reference exporter, linked to MDB Tools.
// This is not compiled into the product. Retains raw floating values and nulls
// that the MDB Tools command-line JSON formatter would round or omit.
#include <fstream>
#include <iostream>
#include <mdbtools.h>
#include <nlohmann/json.hpp>
#include <vector>

int main(int argc, char **argv) {
  if (argc != 3)
    return 2;
  MdbHandle *db = mdb_open(argv[1], MDB_NOFLAGS);
  if (!db)
    return 1;
  mdb_read_catalog(db, MDB_TABLE);
  nlohmann::json output = nlohmann::json::object();
  for (unsigned i = 0; i < db->catalog->len; ++i) {
    auto *entry =
        static_cast<MdbCatalogEntry *>(g_ptr_array_index(db->catalog, i));
    const std::string name = entry->object_name;
    if (name.starts_with("MSys") || name.starts_with("~"))
      continue;
    auto *table = mdb_read_table(entry);
    mdb_read_columns(table);
    mdb_rewind_table(table);
    output[name] = nlohmann::json::array();
    while (mdb_fetch_row(table)) {
      int start;
      size_t length;
      if (mdb_find_row(db, table->cur_row - 1, &start, &length))
        return 3;
      std::vector<MdbField> fields(table->num_cols);
      if (mdb_crack_row(table, start & 0x1fff, length, fields.data()) < 0)
        return 4;
      nlohmann::json row = nlohmann::json::object();
      for (unsigned j = 0; j < table->num_cols; ++j) {
        auto *col =
            static_cast<MdbColumn *>(g_ptr_array_index(table->columns, j));
        auto &field = fields[j];
        auto &value = row[col->name];
        if (col->col_type == MDB_BOOL) {
          value = !field.is_null;
          continue;
        }
        if (field.is_null) {
          value = nullptr;
          continue;
        }
        switch (col->col_type) {
        case MDB_BOOL:
          value = !field.is_null;
          break;
        case MDB_INT:
          value = short(mdb_get_int16(field.value, 0));
          break;
        case MDB_LONGINT:
          value = int(mdb_get_int32(field.value, 0));
          break;
        case MDB_FLOAT:
          value = mdb_get_single(field.value, 0);
          break;
        case MDB_DOUBLE:
          value = mdb_get_double(field.value, 0);
          break;
        default: {
          char *text = mdb_col_to_string(db, db->pg_buf, field.start,
                                         col->col_type, field.siz);
          value = text ? text : "";
          g_free(text);
          break;
        }
        }
      }
      output[name].push_back(row);
    }
    mdb_free_tabledef(table);
  }
  std::ofstream(argv[2]) << output.dump(2) << '\n';
  mdb_close(db);
}
