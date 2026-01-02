#include <cstdio>

#include "cli.hpp"
#include "printing.hpp"
#include "stdin_reader.hpp"

namespace aoc::year_2025::day_4 {

void register_commands(cli::CliExecutor &executor) {
  // Part 1 - calculate total cells that can be removed iteratively
  executor.add_nested_command(
      "year-2025.day-4.part-1",
      "Calculate total cells that can be removed iteratively",
      [](const cli::ParseResult &result) {
        if (!cli::StdinReader::has_piped_input()) {
          std::fprintf(stderr,
                       "Error: No input provided. Pipe data to stdin\n");
          return 1;
        }

        auto lines = cli::StdinReader::read_lines();
        int max_iterations = printing::kMaxIterations;
        auto max_iter_args = result.get_args("--max-iterations");
        if (!max_iter_args.empty()) {
          max_iterations = std::stoi(max_iter_args[0]);
        }

        bool verbose = result.get_bool("--verbose");
        const auto total =
            printing::total_can_remove(lines, max_iterations, verbose);
        std::printf("%lld\n", total);
        return 0;
      });

  executor.add_nested_command_flag(
      "year-2025.day-4.part-1", "-m,--max-iterations", cli::FlagType::MultiArg,
      "Maximum iterations (default: 1000)");
}

} // namespace aoc::year_2025::day_4
