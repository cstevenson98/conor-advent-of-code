# day-2 unit tests
add_executable(test_day-2
    test_invalid_ids.cpp
)

target_include_directories(test_day-2 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

target_link_libraries(test_day-2 PRIVATE
    cpp-cli::core_cli
    GTest::gtest
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_day-2)

