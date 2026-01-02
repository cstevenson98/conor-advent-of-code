# day-6 static library
add_library(day-6-lib STATIC
    day-6.cpp
)

target_include_directories(day-6-lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/src/include
)

target_link_libraries(day-6-lib PUBLIC
    cpp-cli::core_cli
)

# Unit tests
add_subdirectory(unit_tests)
