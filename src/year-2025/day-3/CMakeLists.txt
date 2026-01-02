# day-3 static library
add_library(day-3-lib STATIC
    day-3.cpp
)

target_include_directories(day-3-lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/src/include
)

target_link_libraries(day-3-lib PUBLIC
    core_cli
)

# Unit tests
add_subdirectory(unit_tests)
