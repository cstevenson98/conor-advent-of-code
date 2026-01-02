#pragma once

#include <numeric>
#include <sstream>
#include <string>
#include <vector>

namespace aoc::year_2025::day_2 {

class IDRange {
public:
  IDRange(const std::string &range_string) { parse_range(range_string); }

  inline long long start() const { return start_; }

  inline long long end() const { return end_; }

private:
  long long start_{0};
  long long end_{0};

  void parse_range(const std::string &range_string) {
    std::stringstream string_stream(range_string);
    std::string range_part;
    std::vector<long long> range_parts;
    while (std::getline(string_stream, range_part, '-')) {
      range_parts.push_back(std::stoll(range_part));
    }
    start_ = range_parts[0];
    end_ = range_parts[1];
  }
};

class InvalidIDFinder {
public:
  InvalidIDFinder(const std::vector<std::string> &input) : input_(input) {
    parse_input(input);
    find_invalid_ids();
  }

  inline const std::vector<IDRange> &ranges() const { return ranges_; }

  static std::vector<uint8_t> id_to_digits(long long id) {
    std::vector<uint8_t> digits;
    while (id > 0) {
      digits.push_back(id % 10);
      id /= 10;
    }
    return digits;
  }

  static bool is_not_valid(long long id) {
    // An id is valid if does not repeat its digits
    // For example 12341234 is not valid
    auto digits = id_to_digits(id);
    if (digits.size() % 2 != 0) {
      return false;
    }

    bool is_not_valid = true;
    for (size_t i = 0; i < digits.size() / 2; i++) {
      if (digits[i] != digits[i + digits.size() / 2]) {
        is_not_valid = false;
        break;
      }
    }

    return is_not_valid;
  }

  inline long long sum_of_invalid_ids() const {
    return std::accumulate(invalid_ids_.begin(), invalid_ids_.end(), 0LL);
  }

  inline const std::vector<long long> &invalid_ids() const {
    return invalid_ids_;
  }

private:
  std::vector<std::string> input_{};
  std::vector<IDRange> ranges_{};
  std::vector<long long> invalid_ids_{};

  void parse_input(const std::vector<std::string> &input) {
    for (const auto &line : input) {
      // Split the strings by using stringstream
      std::stringstream string_stream(line);
      std::string range_string;

      // Split the string "10-100,20-200,30-300"
      // into {"10-100", "20-200", "30-300"}
      std::vector<std::string> range_strings;
      while (std::getline(string_stream, range_string, ',')) {
        ranges_.push_back(IDRange(range_string));
      }
    }
  }

  void find_invalid_ids() {
    for (const auto &range : ranges_) {
      for (long long id = range.start(); id <= range.end(); id++) {
        if (is_not_valid(id)) {
          invalid_ids_.push_back(id);
        }
      }
    }
  }
};

} // namespace aoc::year_2025::day_2
