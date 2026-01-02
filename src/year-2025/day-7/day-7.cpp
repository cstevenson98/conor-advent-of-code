#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "cli.hpp"
#include "stdin_reader.hpp"
#include "tachyon_manifold.hpp"

namespace aoc::year_2025::day_7 {

void register_commands(cli::CliExecutor &executor) {
  // Part 1 - solve the tachyon manifold
  executor.add_nested_command(
      "year-2025.day-7.part-1",
      "Solve the tachyon manifold",
      [](const cli::ParseResult & /* result */) {
        if (!cli::StdinReader::has_piped_input()) {
          std::cerr << "Error: No input provided. Pipe data to stdin.\n";
          return 1;
        }
        auto lines = cli::StdinReader::read_lines();
        tachyons::TachyonManifold manifold(lines);
        auto result = manifold.solve();
        std::cout << result.total_timelines << '\n';
        return 0;
      });
}

} // namespace aoc::year_2025::day_7

