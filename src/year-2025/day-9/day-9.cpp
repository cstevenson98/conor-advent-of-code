#include <iostream>
#include <string>
#include <vector>

#include "cli.hpp"
#include "movie_theatre.hpp"
#include "stdin_reader.hpp"

namespace aoc::year_2025::day_9 {

void register_commands(cli::CliExecutor &executor) {
  // Part 1 - maximise theatre seating
  executor.add_nested_command(
      "year-2025.day-9.part-1",
      "Maximise theatre seating efficiency",
      [](const cli::ParseResult &result) {
        bool verbose = result.has_flag("--verbose") || result.has_flag("-v");

        if (!cli::StdinReader::has_piped_input()) {
          std::cerr << "Error: No input provided. Pipe data to stdin.\n";
          return 1;
        }

        // Read all lines from stdin
        auto lines = cli::StdinReader::read_lines();

        if (lines.empty()) {
          std::cerr << "Error: No data to process.\n";
          return 1;
        }

        if (verbose) {
          std::cout << "Processing " << lines.size() << " lines...\n";
        }

        // Create theatre instance and run maximise
        movie_theatre::MovieTheatre theatre(lines);

        if (!theatre.validate_input()) {
          std::cerr << "Error: Invalid input data.\n";
          return 1;
        }

        auto maximimal_area = theatre.maximimal_area();

        if (verbose) {
          std::cout << "Solving for max area from "
                    << theatre.get_corner_candidates().size()
                    << " coordinates.\n";
          std::cout << "Maximal area: " << maximimal_area << "\n";
        } else {
          std::cout << maximimal_area << "\n";
        }

        return 0;
      });

  executor.add_nested_command_flag("year-2025.day-9.part-1", "-v,--verbose", cli::FlagType::Boolean,
                            "Enable verbose output", false);
}

} // namespace aoc::year_2025::day_9

