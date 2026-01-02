#include <cstdio>

#include "cli.hpp"
#include "maxjoltage.hpp"
#include "stdin_reader.hpp"

namespace aoc::year_2025::day_3 {

void register_commands(cli::CliExecutor &executor) {
  // Part 1 - compute max joltage from input
  executor.add_nested_command(
      "year-2025.day-3.part-1",
      "Compute max joltage from input",
      [](const cli::ParseResult &result) {
        if (!cli::StdinReader::has_piped_input()) {
          std::fprintf(stderr,
                       "Error: No input provided. Pipe data to stdin\n");
          return 1;
        }

        // Get the width parameter (default to 2)
        int width = 2;
        if (result.has_flag("--width")) {
          auto width_args = result.get_args("--width");
          if (!width_args.empty()) {
            try {
              width = std::stoi(width_args[0]);
            } catch (const std::exception &e) {
              std::fprintf(stderr, "Error: Invalid width value '%s'\n",
                           width_args[0].c_str());
              return 1;
            }
          }
        }

        auto lines = cli::StdinReader::read_lines();

        long long total_maxjoltage = 0;
        for (const auto &line : lines) {
          long long maxjoltage = maxjoltage::maximum_joltage(line, width);
          total_maxjoltage += maxjoltage;
        }
        std::printf("%lld\n", total_maxjoltage);
        return 0;
      });

  executor.add_nested_command_flag(
      "year-2025.day-3.part-1", "-w,--width", cli::FlagType::MultiArg,
      "Width for maximum joltage computation (default: 2)", false);
}

} // namespace aoc::year_2025::day_3

