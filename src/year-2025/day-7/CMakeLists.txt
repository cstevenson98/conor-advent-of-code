# day-7 static library
add_library(day-7-lib STATIC
    day-7.cpp
    tachyon_manifold.cc
)

target_include_directories(day-7-lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(day-7-lib PUBLIC
    core_cli
)

# Unit tests
add_subdirectory(unit_tests)
