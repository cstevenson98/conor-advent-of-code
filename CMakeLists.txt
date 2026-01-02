cmake_minimum_required(VERSION 3.21)
project(conor-advent-of-code VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find cpp-cli from Conan
find_package(cpp-cli REQUIRED)

# Find GTest from Conan
find_package(GTest REQUIRED)

# Enable testing
enable_testing()

# Function to create symlink in project root
function(symlink_tool_to_root TOOL_NAME)
    add_custom_command(TARGET ${TOOL_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E create_symlink
            $<TARGET_FILE:${TOOL_NAME}>
            ${CMAKE_SOURCE_DIR}/${TOOL_NAME}
        COMMENT "Creating symlink: ${CMAKE_SOURCE_DIR}/${TOOL_NAME}"
    )
endfunction()

# Add year directories to build day libraries
add_subdirectory(src/year-2025)

# Main advent-of-code executable
add_executable(advent-of-code
    src/main.cpp
)

target_include_directories(advent-of-code PRIVATE
    ${CMAKE_SOURCE_DIR}/src/include
)

target_link_libraries(advent-of-code PRIVATE
    cpp-cli::core_cli
    day-1-lib
    day-2-lib
    day-3-lib
    day-4-lib
    day-6-lib
    day-7-lib
    day-9-lib
)

symlink_tool_to_root(advent-of-code)

# Create symlink for compile_commands.json in project root for clangd
if(CMAKE_EXPORT_COMPILE_COMMANDS)
    execute_process(
        COMMAND ${CMAKE_COMMAND} -E create_symlink
            ${CMAKE_BINARY_DIR}/compile_commands.json
            ${CMAKE_SOURCE_DIR}/compile_commands.json
    )
endif()

