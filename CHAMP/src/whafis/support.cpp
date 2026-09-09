#include "support.hpp"
#include <cctype>
#include <iomanip>
#include <locale>
#include <sstream>

namespace legacy::whafis::detail {
namespace {
class FormatParser {
    std::string_view source;
    std::size_t at{};
    void spaces() {
        while (at < source.size() && (source[at] == ' ' || source[at] == ','))
            ++at;
    }
    int number() {
        int n = 0;
        while (at < source.size() && std::isdigit(static_cast<unsigned char>(source[at])))
            n = n * 10 + source[at++] - '0';
        return n;
    }

  public:
    explicit FormatParser(std::string_view s) : source(s) {}
    std::vector<FormatField> parse() {
        std::vector<FormatField> out;
        spaces();
        if (at < source.size() && source[at] == '(')
            ++at;
        while (at < source.size()) {
            spaces();
            if (at == source.size())
                break;
            if (source[at] == ')') {
                ++at;
                break;
            }
            int repeat = number();
            if (!repeat)
                repeat = 1;
            spaces();
            if (at == source.size())
                break;
            char c = static_cast<char>(std::toupper(static_cast<unsigned char>(source[at++])));
            if (c == '(') {
                --at;
                auto nested = parse();
                for (int i = 0; i < repeat; ++i)
                    out.insert(out.end(), nested.begin(), nested.end());
                continue;
            }
            FormatField f{c, 0, 0, {}};
            if (c == 'H') {
                f.code = 'L';
                f.literal = source.substr(at, repeat);
                at += repeat;
                out.push_back(f);
                continue;
            }
            if (c == '\'') {
                f.code = 'L';
                while (at < source.size()) {
                    if (source[at] == '\'') {
                        ++at;
                        if (at < source.size() && source[at] == '\'') {
                            f.literal += '\'';
                            ++at;
                            continue;
                        }
                        break;
                    }
                    f.literal += source[at++];
                }
            } else if (c == 'X') {
                f.width = repeat;
                repeat = 1;
            } else if (c == '/' || c == ':') {
            } else if (c == 'A' || c == 'F' || c == 'I' || c == 'E' || c == 'G' || c == 'T') {
                f.width = number();
                if (at < source.size() && source[at] == '.') {
                    ++at;
                    f.precision = number();
                }
            } else
                throw std::runtime_error("Unsupported WHAFIS format at " + std::to_string(at) +
                                         ": " + std::string(source));
            for (int i = 0; i < repeat; ++i)
                out.push_back(f);
        }
        return out;
    }
};

double parse_number(std::string value, int decimals) {
    value.erase(std::remove(value.begin(), value.end(), ' '), value.end());
    if (value.empty() || value == "." || value == "+." || value == "-.")
        return 0;
    for (char &c : value)
        if (c == 'd' || c == 'D')
            c = 'E';
    // Fortran also accepts an exponent sign without the letter E.
    if (value.find_first_of("Ee") == std::string::npos)
        for (std::size_t i = 1; i < value.size(); ++i)
            if (value[i] == '+' || value[i] == '-') {
                value.insert(i, "E");
                break;
            }
    std::size_t used{};
    double result = std::stod(value, &used);
    if (used != value.size())
        throw std::runtime_error("Invalid WHAFIS numeric field: " + value);
    if (value.find('.') == std::string::npos && decimals)
        result /= std::pow(10., decimals);
    return result;
}
} // namespace

std::vector<FormatField> parse_format(std::string_view format) {
    return FormatParser(format).parse();
}
std::string decimal_field(double value, int width, int precision) {
    std::ostringstream s;
    s.imbue(std::locale::classic());
    s << std::fixed << std::setprecision(precision) << value;
    std::string result = s.str();
    // The original Compaq runtime suppresses the sign when rounding an F
    // field to zero, including small negative slopes in CHAMP-generated decks.
    if (result.starts_with('-') &&
        result.find_first_not_of("0.", 1) == std::string::npos)
        result.erase(0, 1);
    if (static_cast<int>(result.size()) > width)
        return std::string(width, '*');
    return std::string(width - result.size(), ' ') + result;
}
std::string RecordFiles::File::read() {
    if (position >= lines.size()) {
        if (++reads_past_end > 1000)
            throw std::runtime_error("WHAFIS input ended before the required ET card");
        return {};
    }
    reads_past_end = 0;
    return lines[position++];
}
void RecordFiles::File::write(std::string line) {
    if (position >= 100000)
        throw std::runtime_error("WHAFIS output record limit exceeded");
    lines.resize(position);
    lines.push_back(std::move(line));
    ++position;
}
void RecordFiles::load(int unit, std::string_view content) {
    auto &file = files.at(unit);
    file = {};
    while (!content.empty()) {
        const auto end = content.find('\n');
        auto line = content.substr(0, end);
        if (!line.empty() && line.back() == '\r')
            line.remove_suffix(1);
        file.lines.emplace_back(line);
        if (end == std::string_view::npos)
            break;
        content.remove_prefix(end + 1);
    }
}
std::string RecordFiles::content(int unit) const {
    std::string result;
    for (const auto &line : files.at(unit).lines) {
        result += line;
        result += "\r\n";
    }
    return result;
}

RecordFiles::Reader::Reader(File *file, std::string_view format, std::string internal)
    : file_(file), fields_(parse_format(format)), line_(file ? file->read() : std::move(internal)) {
}
std::string RecordFiles::Reader::characters(int count) {
    std::string result;
    if (column_ < line_.size())
        result = line_.substr(column_, count);
    result.resize(count, ' ');
    column_ += count;
    return result;
}
FormatField RecordFiles::Reader::next() {
    for (std::size_t safety = 0; safety < fields_.size() * 2; ++safety) {
        if (field_ == fields_.size()) {
            field_ = 0;
            column_ = 0;
            line_ = file_ ? file_->read() : "";
        }
        const auto &f = fields_[field_++];
        if (f.code == 'A' || f.code == 'F' || f.code == 'I' || f.code == 'E' || f.code == 'G')
            return f;
        if (f.code == 'X')
            column_ += f.width;
        if (f.code == 'T')
            column_ = f.width - 1;
        if (f.code == '/') {
            column_ = 0;
            line_ = file_ ? file_->read() : "";
        }
    }
    throw std::runtime_error("WHAFIS input format has no value field");
}
void RecordFiles::Reader::read(float &value) {
    const auto f = next();
    const auto text = characters(f.width ? f.width : 4);
    try {
        value = f.code == 'A' ? word(text) : static_cast<float>(parse_number(text, f.precision));
    } catch (const std::exception &error) {
        throw std::runtime_error(std::string(error.what()) + "; field '" + text + "' at column " +
                                 std::to_string(column_) + " of '" + line_ + "'");
    }
}
void RecordFiles::Reader::read(int &value) {
    const auto f = next();
    value = integer(parse_number(characters(f.width), f.precision));
}

RecordFiles::Writer::Writer(File &file, std::string_view format)
    : file_(file), fields_(parse_format(format)) {}
void RecordFiles::Writer::put(std::string_view value) {
    if (line_.size() < column_ + value.size())
        line_.resize(column_ + value.size(), ' ');
    line_.replace(column_, value.size(), value);
    column_ += value.size();
}
void RecordFiles::Writer::newline() {
    file_.write(std::move(line_));
    line_.clear();
    column_ = 0;
}
bool RecordFiles::Writer::control() {
    if (field_ == fields_.size())
        return false;
    const auto &f = fields_[field_];
    if (f.code == 'A' || f.code == 'F' || f.code == 'I' || f.code == 'E' || f.code == 'G')
        return false;
    ++field_;
    if (f.code == 'X')
        column_ += f.width;
    if (f.code == 'T')
        column_ = f.width - 1;
    if (f.code == 'L')
        put(f.literal);
    if (f.code == '/')
        newline();
    return true;
}
FormatField RecordFiles::Writer::next() {
    while (control()) {
    }
    if (field_ == fields_.size()) {
        newline();
        field_ = 0;
        while (control()) {
        }
    }
    if (field_ == fields_.size())
        throw std::runtime_error("WHAFIS output format has no value field");
    return fields_[field_++];
}
void RecordFiles::Writer::write(float value) {
    const auto f = next();
    if (f.code == 'A') {
        auto text = word_text(value);
        text.resize(f.width ? f.width : 4, ' ');
        put(text);
    } else
        put(decimal_field(value, f.width, f.precision));
}
void RecordFiles::Writer::write(double value) {
    const auto f = next();
    put(decimal_field(value, f.width, f.precision));
}
void RecordFiles::Writer::write(int value) {
    const auto f = next();
    if (f.code == 'I') {
        auto s = std::to_string(value);
        put(static_cast<int>(s.size()) > f.width ? std::string(f.width, '*')
                                                 : std::string(f.width - s.size(), ' ') + s);
    } else
        put(decimal_field(value, f.width, f.precision));
}
void RecordFiles::Writer::write(std::string_view value) {
    const auto f = next();
    if (f.code != 'A')
        throw std::runtime_error("WHAFIS text write requires an A field");
    std::string text(value);
    if (f.width) {
        if (text.size() < static_cast<std::size_t>(f.width))
            text.insert(0, f.width - text.size(), ' ');
        else
            text.resize(f.width);
    }
    put(text);
}
void RecordFiles::Writer::finish() {
    if (finished_)
        return;
    while (control()) {
    }
    newline();
    finished_ = true;
}
} // namespace legacy::whafis::detail
