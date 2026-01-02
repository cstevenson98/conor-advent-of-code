# day-7 unit tests
add_executable(test_day-7
    test_tachyon_manifold.cpp
    ../tachyon_manifold.cc
)

target_include_directories(test_day-7 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

target_link_libraries(test_day-7 PRIVATE
    core_cli
    GTest::gtest
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_day-7)

