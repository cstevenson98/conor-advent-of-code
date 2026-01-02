# day-1 static library
add_library(day-1-lib STATIC
    day-1.cpp
)

target_include_directories(day-1-lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/src/include
)

target_link_libraries(day-1-lib PUBLIC
    core_cli
)

# Unit tests
add_subdirectory(unit_tests)
