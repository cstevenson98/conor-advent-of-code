#include <cstdio>

#include "cli.hpp"
#include "invalid-ids.hpp"
#include "stdin_reader.hpp"

namespace {

struct InvalidIdsParams {
  bool valid = true;
};

} // namespace

namespace aoc::year_2025::day_2 {

void register_commands(cli::CliExecutor &executor) {
  // Part 1
  executor.add_nested_command(
      "year-2025.day-2.part-1", "Process invalid IDs - Part 1",
      [](const cli::ParseResult &result) {
        if (!cli::StdinReader::has_piped_input()) {
          std::fprintf(stderr,
                       "Error: No input provided. Pipe data to stdin\n");
          return 1;
        }

        auto input_lines = cli::StdinReader::read_lines();
        InvalidIDFinder finder(input_lines);
        std::printf("%lld\n", finder.sum_of_invalid_ids());
        return 0;
      });

  // Part 2
  executor.add_nested_command(
      "year-2025.day-2.part-2", "Process invalid IDs - Part 2",
      [](const cli::ParseResult &result) {
        if (!cli::StdinReader::has_piped_input()) {
          std::fprintf(stderr,
                       "Error: No input provided. Pipe data to stdin\n");
          return 1;
        }

        auto input_lines = cli::StdinReader::read_lines();
        InvalidIDFinder finder(input_lines);
        std::printf("%lld\n", finder.sum_of_invalid_ids());
        return 0;
      });
}

} // namespace aoc::year_2025::day_2
