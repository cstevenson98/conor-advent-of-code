# day-4 static library
add_library(day-4-lib STATIC
    day-4.cpp
)

target_include_directories(day-4-lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/src/include
)

target_link_libraries(day-4-lib PUBLIC
    cpp-cli::core_cli
)

# Unit tests
add_subdirectory(unit_tests)
