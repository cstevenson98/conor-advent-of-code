#include <cstdio>

#include "cli.hpp"

// Include all day registration headers
#include "day-1.hpp"
#include "day-3.hpp"
#include "day-4.hpp"
#include "day-6.hpp"
#include "day-7.hpp"
#include "day-9.hpp"

int main(int argc, char *argv[]) {
  cli::CliExecutor executor("advent-of-code", 
                            "Advent of Code Solutions");

  // Register all year 2025 day commands
  aoc::year_2025::day_1::register_commands(executor);
  aoc::year_2025::day_3::register_commands(executor);
  aoc::year_2025::day_4::register_commands(executor);
  aoc::year_2025::day_6::register_commands(executor);
  aoc::year_2025::day_7::register_commands(executor);
  aoc::year_2025::day_9::register_commands(executor);

  // Enable completion generation
  executor.enable_completion_generation();

  return executor.run(argc, argv);
}

