// Independent Jet 3/4 reader. Format reference: MDB Tools HACKING.md.
// This implementation follows the documented file format; it does not link to
// MDB Tools. Table allocation maps, overflow rows, and long text are respected.
#include "legacy/database.hpp"

#include <algorithm>
#include <array>
#include <bit>
#include <cmath>
#include <fstream>
#include <iterator>
#include <numeric>
#include <set>
#include <span>
#include <stdexcept>

namespace legacy::database {
namespace {
using Bytes = std::vector<std::uint8_t>;
using View = std::span<const std::uint8_t>;

[[noreturn]] void invalid(const std::string &reason) {
  throw std::runtime_error("Cannot read this Access project: " + reason);
}
View part(View bytes, std::size_t start, std::size_t count) {
  if (start > bytes.size() || count > bytes.size() - start)
    invalid("a field extends beyond its record.");
  return bytes.subspan(start, count);
}
std::uint32_t number(View bytes, std::size_t at, unsigned count) {
  auto p = part(bytes, at, count);
  std::uint32_t result = 0;
  for (unsigned i = 0; i < count; ++i)
    result |= std::uint32_t(p[i]) << (8 * i);
  return result;
}
std::uint64_t number64(View bytes) {
  return number(bytes, 0, 4) | (std::uint64_t(number(bytes, 4, 4)) << 32);
}
void append_utf8(std::string &out, unsigned c) {
  if (c < 0x80)
    out += char(c);
  else if (c < 0x800) {
    out += char(0xc0 | (c >> 6));
    out += char(0x80 | (c & 63));
  } else if (c < 0x10000) {
    out += char(0xe0 | (c >> 12));
    out += char(0x80 | ((c >> 6) & 63));
    out += char(0x80 | (c & 63));
  } else {
    out += char(0xf0 | (c >> 18));
    out += char(0x80 | ((c >> 12) & 63));
    out += char(0x80 | ((c >> 6) & 63));
    out += char(0x80 | (c & 63));
  }
}
void rc4(Bytes &bytes, View key) {
  std::array<unsigned, 256> state{};
  std::iota(state.begin(), state.end(), 0);
  unsigned j = 0;
  for (unsigned i = 0; i < 256; ++i) {
    j = (j + state[i] + key[i % key.size()]) & 255;
    std::swap(state[i], state[j]);
  }
  unsigned i = 0;
  j = 0;
  for (auto &b : bytes) {
    i = (i + 1) & 255;
    j = (j + state[i]) & 255;
    std::swap(state[i], state[j]);
    b ^= state[(state[i] + state[j]) & 255];
  }
}
struct Field {
  Column column;
  unsigned number{}, variable{}, fixed_offset{}, size{};
  bool fixed{};
};
struct Definition {
  std::uint32_t page{}, allocation{};
  unsigned variable_count{}, expected_rows{};
  std::vector<Field> fields;
};

class AccessFile {
public:
  explicit AccessFile(const std::filesystem::path &path) {
    std::ifstream stream(path, std::ios::binary);
    if (!stream)
      throw std::runtime_error("Cannot open project: " + path.string());
    bytes_ = Bytes(std::istreambuf_iterator<char>(stream), {});
    if (bytes_.size() < 2048 || number(bytes_, 0, 4) != 0x100 ||
        std::string(reinterpret_cast<const char *>(bytes_.data() + 4), 15) !=
            "Standard Jet DB")
      invalid("the file is not a Jet database.");
    auto version = number(bytes_, 0x14, 1);
    if (version > 1)
      invalid("use an Access 97–2003 .mdb file for import.");
    jet4_ = version == 1;
    page_size_ = jet4_ ? 4096 : 2048;
    row_count_offset_ = jet4_ ? 12 : 8;
    if (bytes_.size() % page_size_)
      invalid("the file ends inside a database page.");
    auto encrypted = part(bytes_, 0x18, jet4_ ? 128 : 126);
    Bytes header(encrypted.begin(), encrypted.end());
    const std::array<std::uint8_t, 4> key{0xc7, 0xda, 0x39, 0x6b};
    rc4(header, key);
    encryption_key_ = number(header, 0x3e - 0x18, 4);
  }
  Tables tables() const {
    Tables result;
    const auto catalog = read_table(2);
    for (const auto &row : catalog.rows) {
      if (!row.contains("Name") || !row["Name"].is_string() ||
          !row.contains("Type"))
        continue;
      const auto name = row["Name"].get<std::string>();
      if (name.starts_with("MSys") || name.starts_with("~") || row["Type"] != 1)
        continue;
      if (!row.contains("Id") || !row["Id"].is_number_integer())
        continue;
      result.emplace(name,
                     read_table(row["Id"].get<std::uint32_t>() & 0xffffff));
    }
    return result;
  }

private:
  Bytes bytes_;
  unsigned page_size_{}, row_count_offset_{};
  bool jet4_{};
  std::uint32_t encryption_key_{};

  Bytes page(std::uint32_t index) const {
    auto view = part(bytes_, std::size_t(index) * page_size_, page_size_);
    Bytes result(view.begin(), view.end());
    if (index && encryption_key_) {
      auto k = encryption_key_ ^ index;
      std::array<std::uint8_t, 4> key{};
      for (unsigned i = 0; i < 4; ++i)
        key[i] = std::uint8_t(k >> (i * 8));
      rc4(result, key);
    }
    return result;
  }
  Bytes record(std::uint32_t pointer, unsigned depth = 0) const {
    if (depth > 32)
      invalid("a row contains an overflow cycle.");
    auto p = page(pointer >> 8);
    unsigned slot = pointer & 255;
    if (slot >= number(p, row_count_offset_, 2))
      invalid("an overflow row is missing.");
    auto encoded = number(p, row_count_offset_ + 2 + slot * 2, 2);
    auto start = encoded & 0x1fff;
    auto end =
        slot ? number(p, row_count_offset_ + slot * 2, 2) & 0x1fff : page_size_;
    if (end < start)
      invalid("a row has invalid boundaries.");
    if (encoded & 0x4000)
      return record(number(p, start, 4), depth + 1);
    auto view = part(p, start, end - start);
    return Bytes(view.begin(), view.end());
  }
  std::string text(View data) const {
    std::string result;
    if (!jet4_) {
      constexpr std::array<unsigned, 32> cp1252{
          0x20ac, 0x81,   0x201a, 0x192,  0x201e, 0x2026, 0x2020, 0x2021,
          0x2c6,  0x2030, 0x160,  0x2039, 0x152,  0x8d,   0x17d,  0x8f,
          0x90,   0x2018, 0x2019, 0x201c, 0x201d, 0x2022, 0x2013, 0x2014,
          0x2dc,  0x2122, 0x161,  0x203a, 0x153,  0x9d,   0x17e,  0x178};
      for (auto c : data)
        append_utf8(result, c >= 0x80 && c < 0xa0 ? cp1252[c - 0x80] : c);
      return result;
    }
    bool compressed = data.size() >= 2 && data[0] == 0xff && data[1] == 0xfe;
    bool narrow = compressed;
    std::size_t pos = compressed ? 2 : 0;
    while (pos < data.size()) {
      if (compressed && data[pos] == 0) {
        narrow = !narrow;
        ++pos;
        continue;
      }
      auto c = number(data, pos, narrow ? 1 : 2);
      pos += narrow ? 1 : 2;
      if (c >= 0xd800 && c <= 0xdbff && !narrow && pos + 2 <= data.size()) {
        auto low = number(data, pos, 2);
        if (low >= 0xdc00 && low <= 0xdfff) {
          c = 0x10000 + (c - 0xd800) * 1024 + low - 0xdc00;
          pos += 2;
        }
      }
      append_utf8(result, c);
    }
    return result;
  }
  Bytes long_value(View value) const {
    if (value.empty())
      return {};
    auto flags = number(value, 0, 4);
    auto length = flags & 0x3fffffff;
    if (length > bytes_.size())
      invalid("a memo length exceeds the file size.");
    if (flags & 0x80000000) {
      auto v = part(value, 12, length);
      return Bytes(v.begin(), v.end());
    }
    auto pointer = number(value, 4, 4);
    if (flags & 0x40000000)
      return record(pointer);
    Bytes result;
    std::set<std::uint32_t> visited;
    while (pointer && result.size() < length) {
      if (!visited.insert(pointer).second)
        invalid("a memo contains a cycle.");
      auto row = record(pointer);
      pointer = number(row, 0, 4);
      auto data = part(row, 4, row.size() - 4);
      result.insert(result.end(), data.begin(), data.end());
    }
    if (result.size() < length)
      invalid("a memo is incomplete.");
    result.resize(length);
    return result;
  }
  Definition definition(std::uint32_t index) const {
    Bytes data = page(index);
    if (data[0] != 2)
      invalid("a table definition is missing.");
    auto next = number(data, 4, 4);
    std::set<std::uint32_t> visited{index};
    while (next) {
      if (!visited.insert(next).second)
        invalid("a table definition contains a cycle.");
      auto p = page(next);
      next = number(p, 4, 4);
      data.insert(data.end(), p.begin() + 8, p.end());
    }
    Definition result;
    result.page = index;
    result.expected_rows = number(data, jet4_ ? 16 : 12, 4);
    result.variable_count = number(data, jet4_ ? 43 : 23, 2);
    result.allocation = number(data, jet4_ ? 55 : 35, 4);
    auto count = number(data, jet4_ ? 45 : 25, 2);
    auto indexes = number(data, jet4_ ? 51 : 31, 4);
    std::size_t pos = (jet4_ ? 63 : 43) + indexes * (jet4_ ? 12 : 8);
    for (unsigned i = 0; i < count; ++i) {
      Field f;
      f.column.type = number(data, pos, 1);
      f.number = number(data, pos + (jet4_ ? 5 : 1), 2);
      f.variable = number(data, pos + (jet4_ ? 7 : 3), 2);
      f.fixed = (number(data, pos + (jet4_ ? 15 : 13), 1) & 1) != 0;
      f.fixed_offset = number(data, pos + (jet4_ ? 21 : 14), 2);
      f.size = number(data, pos + (jet4_ ? 23 : 16), 2);
      result.fields.push_back(f);
      pos += jet4_ ? 25 : 18;
    }
    for (auto &f : result.fields) {
      auto length = number(data, pos, jet4_ ? 2 : 1);
      pos += jet4_ ? 2 : 1;
      f.column.name = text(part(data, pos, length));
      pos += length;
    }
    return result;
  }
  std::vector<unsigned> allocated_pages(std::uint32_t pointer) const {
    const auto map = record(pointer);
    std::vector<unsigned> result;
    auto add = [&](View bits, unsigned base) {
      for (std::size_t i = 0; i < bits.size() * 8; ++i)
        if (bits[i / 8] & (1 << (i % 8)))
          result.push_back(base + unsigned(i));
    };
    if (map.empty())
      invalid("a table allocation map is empty.");
    if (map[0] == 0)
      add(part(map, 5, map.size() - 5), number(map, 1, 4));
    else if (map[0] == 1) {
      for (std::size_t i = 1; i + 4 <= map.size(); i += 4) {
        auto pointer = number(map, i, 4);
        if (pointer) {
          const auto p = page(pointer);
          add(part(p, 4, p.size() - 4),
              unsigned((i - 1) / 4) * (page_size_ - 4) * 8);
        }
      }
    } else
      invalid("the table uses an unknown allocation map.");
    return result;
  }
  Value value(const Field &field, View data) const {
    switch (field.column.type) {
    case 2:
      return number(data, 0, 1);
    case 3:
      return std::bit_cast<std::int16_t>(std::uint16_t(number(data, 0, 2)));
    case 4:
      return std::bit_cast<std::int32_t>(number(data, 0, 4));
    case 5:
      return double(std::bit_cast<std::int64_t>(number64(data))) / 10000;
    case 6:
      return std::bit_cast<float>(number(data, 0, 4));
    case 7:
    case 8:
      return std::bit_cast<double>(number64(data));
    case 10:
      return text(data);
    case 12: {
      auto memo = long_value(data);
      return text(memo);
    }
    default: {
      // Preserve other column types as typed hexadecimal bytes for a
      // lossless import, even when the coastal workflow does not use them.
      const char digits[] = "0123456789abcdef";
      auto raw = field.column.type == 11 ? long_value(data)
                                         : Bytes(data.begin(), data.end());
      std::string hex;
      for (auto b : raw) {
        hex += digits[b >> 4];
        hex += digits[b & 15];
      }
      return Value{{"access_type", field.column.type}, {"hex", hex}};
    }
    }
  }
  Value row(const Definition &table, View data) const {
    const unsigned width = jet4_ ? 2 : 1;
    const auto count = number(data, 0, width);
    const auto mask_size = (count + 7) / 8;
    auto mask = part(data, data.size() - mask_size, mask_size);
    unsigned variable_count = 0;
    std::vector<unsigned> offsets;
    if (table.variable_count) {
      variable_count = number(data, data.size() - mask_size - width, width);
      if (variable_count > count)
        invalid("a row contains too many variable fields.");
      if (jet4_) {
        for (unsigned i = 0; i <= variable_count; ++i)
          offsets.push_back(
              number(data, data.size() - mask_size - 4 - i * 2, 2));
      } else {
        unsigned jumps = unsigned((data.size() - 1) / 256), used = 0;
        auto last_offset = data.size() - mask_size - jumps - 2;
        if ((last_offset - variable_count) / 256 < jumps)
          --jumps;
        for (unsigned i = 0; i <= variable_count; ++i) {
          while (used < jumps &&
                 i == number(data, data.size() - mask_size - used - 2, 1))
            ++used;
          offsets.push_back(number(data, last_offset - i, 1) + used * 256);
        }
      }
    }
    Value result = Value::object();
    for (const auto &f : table.fields) {
      const bool present =
          f.number < count && (mask[f.number / 8] & (1 << (f.number % 8)));
      if (f.column.type == 1) {
        result[f.column.name] = present;
        continue;
      }
      if (!present || (!f.fixed && f.variable >= variable_count)) {
        result[f.column.name] = nullptr;
        continue;
      }
      const auto start =
          f.fixed ? f.fixed_offset + width : offsets.at(f.variable);
      const auto size = f.fixed ? f.size : offsets.at(f.variable + 1) - start;
      result[f.column.name] = value(f, part(data, start, size));
    }
    return result;
  }
  Table read_table(std::uint32_t index) const {
    const auto def = definition(index);
    Table result;
    for (const auto &f : def.fields)
      result.columns.push_back(f.column);
    for (auto pg : allocated_pages(def.allocation)) {
      const auto data = page(pg);
      if (data[0] != 1 || number(data, 4, 4) != index)
        continue;
      auto count = number(data, row_count_offset_, 2);
      for (unsigned i = 0; i < count; ++i) {
        if (number(data, row_count_offset_ + 2 + i * 2, 2) & 0x8000)
          continue;
        try {
          result.rows.push_back(row(def, record((pg << 8) | i)));
        } catch (const std::exception &e) {
          invalid("table " + std::to_string(index) + ", row " +
                  std::to_string(i) + ": " + e.what());
        }
      }
    }
    if (result.rows.size() != def.expected_rows)
      invalid("the table's row count does not agree with its allocation map.");
    return result;
  }
};
} // namespace

Tables read_access(const std::filesystem::path &path) {
  return AccessFile(path).tables();
}
} // namespace legacy::database
