// SPDX-License-Identifier: MIT
#pragma once
#include <filesystem>
#include <string>
#include <string_view>
namespace legacy::desktop {
inline std::filesystem::path utf8_path(std::string_view text) {
  return std::filesystem::path(std::u8string(text.begin(), text.end()));
}
inline std::string utf8_text(const std::filesystem::path &path) {
  const auto text = path.u8string();
  return std::string(text.begin(), text.end());
}
inline std::string file_url(const std::filesystem::path &path) {
  const auto bytes = path.generic_u8string();
  std::string url = bytes.starts_with(u8"/") ? "file://" : "file:///";
  constexpr char hex[] = "0123456789ABCDEF";
  for (unsigned char c : bytes) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9') || c == '/' || c == ':' || c == '-' ||
        c == '_' || c == '.')
      url += char(c);
    else {
      url += '%';
      url += hex[c >> 4];
      url += hex[c & 15];
    }
  }
  return url;
}
} // namespace legacy::desktop
