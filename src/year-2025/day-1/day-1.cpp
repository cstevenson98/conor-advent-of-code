#include <cstdio>

#include "cli.hpp"
#include "safes.hpp"
#include "stdin_reader.hpp"

namespace {

struct SafeParams {
  int initial_position = 0;
  int num_digits = 2;
  bool valid = true;
};

SafeParams parse_safe_params(const cli::ParseResult &result) {
  SafeParams params;

  auto initial_pos_args = result.get_args("--initial-position");
  if (!initial_pos_args.empty()) {
    try {
      params.initial_position = std::stoi(initial_pos_args[0]);
    } catch (const std::exception &e) {
      std::fprintf(stderr, "Error: Invalid initial-position value '%s'\n",
                   initial_pos_args[0].c_str());
      params.valid = false;
      return params;
    }
  }

  auto num_digits_args = result.get_args("--num-digits");
  if (!num_digits_args.empty()) {
    try {
      params.num_digits = std::stoi(num_digits_args[0]);
    } catch (const std::exception &e) {
      std::fprintf(stderr, "Error: Invalid num-digits value '%s'\n",
                   num_digits_args[0].c_str());
      params.valid = false;
      return params;
    }
  }

  return params;
}

} // namespace

namespace aoc::year_2025::day_1 {

void register_commands(cli::CliExecutor &executor) {
  // Part 1 - crack safe by counting zeros in positions
  executor.add_nested_command(
      "year-2025.day-1.part-1",
      "Crack safe by counting zeros in positions",
      [](const cli::ParseResult &result) {
        if (!cli::StdinReader::has_piped_input()) {
          std::fprintf(stderr,
                       "Error: No input provided. Pipe data to stdin\n");
          return 1;
        }

        auto params = parse_safe_params(result);
        if (!params.valid) {
          return 1;
        }

        auto instructions_strs = cli::StdinReader::read_lines();
        const auto password = safes::crack(
            instructions_strs, params.initial_position, params.num_digits);
        std::printf("%lld\n", password);
        return 0;
      });

  executor.add_nested_command_flag("year-2025.day-1.part-1", "-p,--initial-position",
                            cli::FlagType::MultiArg,
                            "Initial position of the safe (default: 0)");

  executor.add_nested_command_flag("year-2025.day-1.part-1", "-d,--num-digits",
                            cli::FlagType::MultiArg,
                            "Number of digits on the safe (default: 2)");

  // Part 2 - crack safe by counting every zero crossing
  executor.add_nested_command(
      "year-2025.day-1.part-2",
      "Crack safe by counting every zero crossing",
      [](const cli::ParseResult &result) {
        if (!cli::StdinReader::has_piped_input()) {
          std::fprintf(stderr,
                       "Error: No input provided. Pipe data to stdin\n");
          return 1;
        }

        auto params = parse_safe_params(result);
        if (!params.valid) {
          return 1;
        }

        auto instructions_strs = cli::StdinReader::read_lines();
        const auto password = safes::crack_true(
            instructions_strs, params.initial_position, params.num_digits);
        std::printf("%lld\n", password);
        return 0;
      });

  executor.add_nested_command_flag("year-2025.day-1.part-2", "-p,--initial-position",
                            cli::FlagType::MultiArg,
                            "Initial position of the safe (default: 0)");

  executor.add_nested_command_flag("year-2025.day-1.part-2", "-d,--num-digits",
                            cli::FlagType::MultiArg,
                            "Number of digits on the safe (default: 2)");
}

} // namespace aoc::year_2025::day_1

