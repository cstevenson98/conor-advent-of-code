# day-9 unit tests
add_executable(test_day-9
    test_movie_theatre.cpp
)

target_include_directories(test_day-9 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

target_link_libraries(test_day-9 PRIVATE
    core_cli
    GTest::gtest
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_day-9)

