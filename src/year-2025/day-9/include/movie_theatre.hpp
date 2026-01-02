#pragma once

#include <algorithm>
#include <iostream>
#include <optional>
#include <string>
#include <vector>

namespace movie_theatre {

// Stub class for movie theatre maximisation
class MovieTheatre {
public:
  using Position = std::pair<int, int>;
  using CornerCandidates = std::vector<Position>;

  explicit MovieTheatre(const std::vector<std::string> &input_data)
      : input_data_(input_data), corner_candidates_(parse_input_data()) {}

  // Stub helper method
  [[nodiscard]] bool validate_input() const {
    // Stub implementation
    return !input_data_.empty();
  }

  // Getter for testing private parse_input_data results
  [[nodiscard]] const CornerCandidates &get_corner_candidates() const {
    return corner_candidates_;
  }

  static void sort_by_x_then_y(CornerCandidates &candidates) {
    std::sort(candidates.begin(), candidates.end(),
              [](Position &p1, Position &p2) {
                return p1.first < p2.first ||
                       (p1.first == p2.first && p1.second < p2.second);
              });
  }

  [[nodiscard]] static long long rect_area(const Position &p1,
                                           const Position &p2) {
    return (std::llabs(p1.first - p2.first) + 1) *
           (std::llabs(p1.second - p2.second) + 1);
  }

  /**
   * @brief Calculate the maximal area of the movie theatre
   * @return The maximal area of the movie theatre
   */
  [[nodiscard]] long long maximimal_area() const {
    // Just brute force it for now
    long long max_area = 0;
    for (const auto &candidate : corner_candidates_) {
      for (const auto &other_candidate : corner_candidates_) {
        long long area = rect_area(candidate, other_candidate);
        if (area > max_area) {
          max_area = area;
        }
      }
    }
    return max_area;
  }

private:
  std::vector<std::string> input_data_;
  CornerCandidates corner_candidates_;

  [[nodiscard]] static std::optional<Position>
  parse_line(const std::string &line) {
    try {
      // Find the comma separator
      size_t comma_pos = line.find(',');
      if (comma_pos == std::string::npos) {
        return std::nullopt;
      }

      // Extract and parse the two parts
      std::string x_str = line.substr(0, comma_pos);
      std::string y_str = line.substr(comma_pos + 1);

      int x = std::stoi(x_str);
      int y = std::stoi(y_str);

      return {{x, y}};
    } catch (const std::exception &e) {
      return std::nullopt;
    }
  }

  // Parse x,y pairs from the data
  [[nodiscard]] CornerCandidates parse_input_data() const {
    CornerCandidates result;
    for (const auto &line : input_data_) {
      auto pair = parse_line(line);
      if (pair) {
        result.emplace_back(pair.value());
      } else {
        std::cerr << "Warning: Failed to parse line, ignoring: " << line
                  << "\n";
      }
    }
    return result;
  }
};

} // namespace movie_theatre
