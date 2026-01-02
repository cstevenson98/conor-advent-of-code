#include <gtest/gtest.h>

#include "invalid-ids.hpp"

namespace aoc::year_2025::day_2 {
namespace {

TEST(IDRangeTest, ParseRange) {
  IDRange range("10-100");
  EXPECT_EQ(range.start(), 10);
  EXPECT_EQ(range.end(), 100);
}

TEST(IDRangeTest, ParseRangeWithMultipleParts) {
  IDRange range("10-100,20-200,30-300");
  EXPECT_EQ(range.start(), 10);
  EXPECT_EQ(range.end(), 100);
}

TEST(InvalidIDFinderTest, ParseInput) {
  std::vector<std::string> input = {
      "10-100,20-200,30-300",
      "40-400,50-500,60-600",
  };
  InvalidIDFinder finder(input);
  EXPECT_EQ(finder.ranges().size(), 6);
  EXPECT_EQ(finder.ranges()[0].start(), 10);
  EXPECT_EQ(finder.ranges()[0].end(), 100);
  EXPECT_EQ(finder.ranges()[1].start(), 20);
  EXPECT_EQ(finder.ranges()[1].end(), 200);
  EXPECT_EQ(finder.ranges()[2].start(), 30);
  EXPECT_EQ(finder.ranges()[2].end(), 300);
}

TEST(InvalidIDFinderTest, IsNotValid) {
  EXPECT_TRUE(InvalidIDFinder::is_not_valid(12341234));
  EXPECT_FALSE(InvalidIDFinder::is_not_valid(123412341));
  EXPECT_FALSE(InvalidIDFinder::is_not_valid(12345678));
}

TEST(InvalidIDFinderTest, InvalidIds) {
  std::vector<std::string> input = {
      "11-22",
  };
  InvalidIDFinder finder(input);
  EXPECT_EQ(finder.invalid_ids().size(), 2);
  EXPECT_EQ(finder.invalid_ids()[0], 11);
  EXPECT_EQ(finder.invalid_ids()[1], 22);
}

TEST(InvalidIDFinderTest, SumOfInvalidIds) {
  std::vector<std::string> input = {
      "11-22,95-115,998-1012,1188511880-1188511890,222220-222224,1698522-"
      "1698528,446443-446449,38593856-38593862,565653-565659,824824821-"
      "824824827,2121212118-2121212124",
  };
  InvalidIDFinder finder(input);
  EXPECT_EQ(finder.sum_of_invalid_ids(), 1227775554);
}

} // namespace
} // namespace aoc::year_2025::day_2
