# day-9 static library
add_library(day-9-lib STATIC
    day-9.cpp
)

target_include_directories(day-9-lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(day-9-lib PUBLIC
    core_cli
)

# Unit tests
add_subdirectory(unit_tests)
