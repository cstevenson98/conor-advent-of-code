#include <cstdio>

#include "cephalopods.hpp"
#include "cli.hpp"
#include "stdin_reader.hpp"

namespace aoc::year_2025::day_6 {

void register_commands(cli::CliExecutor &executor) {
  // Part 1 - do homework (naive mode)
  executor.add_nested_command(
      "year-2025.day-6.part-1",
      "Process homework from stdin",
      [](const cli::ParseResult & /* result */) {
        if (!cli::StdinReader::has_piped_input()) {
          std::fprintf(
              stderr,
              "Error: No input provided. Pipe homework lines to stdin.\n");
          return 1;
        }

        auto lines = cli::StdinReader::read_lines();
        auto result = cephalopods::do_homework(lines);

        if (!result.has_value()) {
          std::fprintf(stderr, "Error: Failed to solve homework.\n");
          return 1;
        }

        std::printf("%lld\n", result.value());
        return 0;
      });

  // Part 2 - do homework (true mode)
  executor.add_nested_command(
      "year-2025.day-6.part-2",
      "Process homework from stdin (verbose mode)",
      [](const cli::ParseResult &result) {
        if (!cli::StdinReader::has_piped_input()) {
          std::fprintf(
              stderr,
              "Error: No input provided. Pipe homework lines to stdin.\n");
          return 1;
        }

        bool verbose = result.get_bool("--verbose");
        auto lines = cli::StdinReader::read_lines();
        auto homework_solution = cephalopods::do_homework_true(lines, verbose);

        if (!homework_solution.has_value()) {
          std::fprintf(stderr, "Error: Failed to solve homework.\n");
          return 1;
        }

        std::printf("%lld\n", homework_solution.value());
        return 0;
      });

  executor.add_nested_command_flag("year-2025.day-6.part-2", "-v,--verbose",
                            cli::FlagType::Boolean, "Enable verbose output");
}

} // namespace aoc::year_2025::day_6

