#pragma once

namespace cli {
class CliExecutor;
}

namespace aoc::year_2025::day_7 {

/// Register day-7 commands with the CLI executor
void register_commands(cli::CliExecutor &executor);

} // namespace aoc::year_2025::day_7

