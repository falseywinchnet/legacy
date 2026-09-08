#pragma once
#include <algorithm>
#include <array>
#include <bit>
#include <cmath>
#include <cstdint>
#include <limits>
#include <stdexcept>
#include <string>
#include <string_view>
#include <type_traits>
#include <utility>
#include <vector>

namespace legacy::whafis::detail {

struct CalculationStopped : std::runtime_error {
    CalculationStopped() : std::runtime_error("WHAFIS stopped the calculation") {}
};

// The published model uses one-based, column-major arrays. Bounds are checked;
// malformed input cannot overwrite an adjacent variable as it could in Fortran.
template <class T, std::size_t... Extents> class Array {
    std::array<T, (Extents * ...)> values_{};

  public:
    template <class... Index> T &operator()(Index... index) {
        static_assert(sizeof...(Index) == sizeof...(Extents));
        const std::array<int, sizeof...(Index)> ix{static_cast<int>(index)...};
        constexpr std::array<std::size_t, sizeof...(Extents)> shape{Extents...};
        std::size_t offset = 0, stride = 1;
        for (std::size_t d = 0; d != ix.size(); ++d) {
            if (ix[d] < 1 || static_cast<std::size_t>(ix[d]) > shape[d])
                throw std::out_of_range("WHAFIS array index " + std::to_string(ix[d]) +
                                        " exceeds 1.." + std::to_string(shape[d]));
            offset += static_cast<std::size_t>(ix[d] - 1) * stride;
            stride *= shape[d];
        }
        return values_[offset];
    }
    template <class... Index> const T &operator()(Index... index) const {
        return const_cast<Array &>(*this)(index...);
    }
};

template <std::size_t N> class Text {
    std::string value_ = std::string(N, ' ');

  public:
    Text() = default;
    Text(std::string_view value) { *this = value; }
    Text &operator=(std::string_view value) {
        value_ = value.substr(0, N);
        value_.resize(N, ' ');
        return *this;
    }
    template <std::size_t M> Text &operator=(const Text<M> &value) {
        return *this = std::string_view(value);
    }
    operator std::string_view() const { return value_; }
    std::string slice(int first, int last) const {
        if (first < 1 || last < first || last > static_cast<int>(N))
            throw std::out_of_range("WHAFIS text slice");
        return value_.substr(first - 1, last - first + 1);
    }
    friend bool operator==(const Text &a, std::string_view b) {
        auto av = std::string_view(a);
        while (!av.empty() && av.back() == ' ')
            av.remove_suffix(1);
        while (!b.empty() && b.back() == ' ')
            b.remove_suffix(1);
        return av == b;
    }
    friend bool operator==(std::string_view a, const Text &b) { return b == a; }
};

inline std::string trim(std::string_view v) {
    while (!v.empty() && v.back() == ' ')
        v.remove_suffix(1);
    return std::string(v);
}
inline int trimmed_length(std::string_view v) { return static_cast<int>(trim(v).size()); }
inline std::string adjust_left(std::string_view v) {
    const auto first = v.find_first_not_of(' ');
    if (first == std::string_view::npos)
        return std::string(v);
    std::string out(v.substr(first));
    out.resize(v.size(), ' ');
    return out;
}
inline std::string concatenate(std::string_view a, std::string_view b) {
    return std::string(a) + std::string(b);
}

// Explicit representation of the historical A2/A4 tags in real-valued fields.
// No pointer aliasing, host byte order, or floating arithmetic is used here.
inline float word(std::string_view text) {
    std::uint32_t bits = 0;
    for (int i = 0; i < 4; ++i)
        bits |= static_cast<std::uint32_t>(
                    static_cast<unsigned char>(i < static_cast<int>(text.size()) ? text[i] : ' '))
                << (8 * i);
    return std::bit_cast<float>(bits);
}
inline std::string word_text(float value) {
    const auto bits = std::bit_cast<std::uint32_t>(value);
    std::string out(4, ' ');
    for (int i = 0; i < 4; ++i)
        out[i] = static_cast<char>((bits >> (8 * i)) & 255);
    return out;
}
inline int integer(double value) {
    if (!std::isfinite(value) || value < std::numeric_limits<int>::min() ||
        value > std::numeric_limits<int>::max())
        throw std::domain_error("WHAFIS integer conversion is out of range");
    return static_cast<int>(value);
}
inline float real(int value) { return static_cast<float>(value); }
template <class T> inline double wide(T value) { return static_cast<double>(value); }
template <class... T> double maximum(T... x) { return std::max({static_cast<double>(x)...}); }
template <class... T> double minimum(T... x) { return std::min({static_cast<double>(x)...}); }
inline double power(double x, double y) { return std::pow(x, y); }
inline double power(double x, int n) {
    if (n == 2)
        return x * x;
    if (n == 3)
        return x * x * x;
    return std::pow(x, n);
}
inline double sign(double a, double b) { return b < 0 ? -std::abs(a) : std::abs(a); }

struct FormatField {
    char code{};
    int width{}, precision{};
    std::string literal;
};
std::vector<FormatField> parse_format(std::string_view format);
std::string decimal_field(double value, int width, int precision);

class RecordFiles {
  public:
    struct File {
        std::vector<std::string> lines;
        std::size_t position{};
        std::size_t reads_past_end{};
        std::string read();
        void write(std::string line);
    };
    std::array<File, 11> files;
    void load(int unit, std::string_view content);
    std::string content(int unit) const;
    void rewind(int unit) { files.at(unit).position = 0; }
    void backspace(int unit) {
        auto &p = files.at(unit).position;
        if (p)
            --p;
    }

    class Reader {
        File *file_{};
        std::vector<FormatField> fields_;
        std::size_t field_{}, column_{};
        std::string line_;
        FormatField next();
        std::string characters(int count);

      public:
        Reader(File *file, std::string_view format, std::string internal = {});
        void read(float &value);
        void read(int &value);
        template <std::size_t N> void read(Text<N> &value) {
            auto field = next();
            if (field.code != 'A')
                throw std::runtime_error("WHAFIS text read requires an A field");
            value = characters(field.width ? field.width : N);
        }
        void finish() {}
    };

    class Writer {
        File &file_;
        std::vector<FormatField> fields_;
        std::size_t field_{}, column_{};
        std::string line_;
        bool finished_{};
        void put(std::string_view text);
        void newline();
        FormatField next();
        bool control();

      public:
        Writer(File &file, std::string_view format);
        void write(float value);
        void write(double value);
        void write(int value);
        void write(std::string_view value);
        template <std::size_t N> void write(const Text<N> &value) {
            write(std::string_view(value));
        }
        void finish();
    };

    Reader reader(int unit, std::string_view format) { return Reader(&files.at(unit), format); }
    template <std::size_t N> Reader reader(const Text<N> &text, std::string_view format) {
        return Reader(nullptr, format, std::string(std::string_view(text)));
    }
    Writer writer(int unit, std::string_view format) { return Writer(files.at(unit), format); }
};
} // namespace legacy::whafis::detail
