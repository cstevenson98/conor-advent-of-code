#pragma once

namespace cli {
class CliExecutor;
}

namespace aoc::year_2025::day_2 {

/// Register day-2 commands with the CLI executor
void register_commands(cli::CliExecutor &executor);

} // namespace aoc::year_2025::day_2

