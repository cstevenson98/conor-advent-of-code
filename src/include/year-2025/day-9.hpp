#pragma once

namespace cli {
class CliExecutor;
}

namespace aoc::year_2025::day_9 {

/// Register day-9 commands with the CLI executor
void register_commands(cli::CliExecutor &executor);

} // namespace aoc::year_2025::day_9

