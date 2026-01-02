#include "movie_theatre.hpp"

#include <gtest/gtest.h>

namespace movie_theatre {
namespace {

// Dummy test data - using comma-separated format as expected by parse_line
const std::vector<std::string> k_sample_input = {
    "10,10",
    "15,15",
    "12,12",
};

const std::vector<std::string> k_invalid_input = {
    "10,10",
    "not a number",
    "15,15",
};

const std::vector<std::string> k_empty_input = {};

TEST(MovieTheatreTest, BasicConstruction) {
  MovieTheatre theatre(k_sample_input);
  EXPECT_TRUE(theatre.validate_input());
}

TEST(MovieTheatreTest, EmptyInput) {
  MovieTheatre theatre(k_empty_input);
  EXPECT_FALSE(theatre.validate_input());
}

TEST(MovieTheatreTest, ParseInputData) {
  MovieTheatre theatre(k_sample_input);
  // Access via public getter to test parse_input_data
  const auto &candidates = theatre.get_corner_candidates();
  EXPECT_EQ(candidates.size(), 3u);
  EXPECT_EQ(candidates[0], MovieTheatre::Position(10, 10));
  EXPECT_EQ(candidates[1], MovieTheatre::Position(15, 15));
  EXPECT_EQ(candidates[2], MovieTheatre::Position(12, 12));
}

TEST(MovieTheatreTest, ParseInputDataWithInvalidLines) {
  MovieTheatre theatre(k_invalid_input);
  // Should parse 2 valid lines and skip 1 invalid
  const auto &candidates = theatre.get_corner_candidates();
  EXPECT_EQ(candidates.size(), 2u);
  EXPECT_EQ(candidates[0], MovieTheatre::Position(10, 10));
  EXPECT_EQ(candidates[1], MovieTheatre::Position(15, 15));
}

TEST(MovieTheatreTest, MaximiseBasic) {
  MovieTheatre theatre(k_sample_input);
  auto result = theatre.maximimal_area();
  // Stub test - just checking it runs
  EXPECT_EQ(result, 0); // Stub returns 0
}

TEST(MovieTheatreTest, RectArea2) {
  auto result = MovieTheatre::rect_area(MovieTheatre::Position(1, 1),
                                        MovieTheatre::Position(1, 7));
  EXPECT_EQ(result, 7);
}

TEST(MovieTheatreTest, RectArea3) {
  auto result = MovieTheatre::rect_area(MovieTheatre::Position(5, 3),
                                        MovieTheatre::Position(1, 7));
  EXPECT_EQ(result, 25);
}

TEST(MovieTheatreTest, RectArea) {
  auto result = MovieTheatre::rect_area(MovieTheatre::Position(1, 1),
                                        MovieTheatre::Position(5, 3));
  EXPECT_EQ(result, 15);
}

// clang-format off
const std::vector<std::string> kExampleInput = {
    "7,1", 
    "11,1", 
    "11,7", 
    "9,7", 
    "9,5", 
    "2,5", 
    "2,3", 
    "7,3",
};

const std::vector<std::string> kExampleInput2 = {
  "1,1", 
  "1,7", 
  "5,3", 
};
// clang-format on 

// Test that we get 8 coordinates in the correct order
TEST(MovieTheatreTest, GetCornerCandidates) {
  MovieTheatre theatre(kExampleInput);
  auto candidates = theatre.get_corner_candidates();
  EXPECT_EQ(candidates.size(), 8);
  EXPECT_EQ(candidates[0], MovieTheatre::Position(7, 1));
  EXPECT_EQ(candidates[1], MovieTheatre::Position(11, 1));
  EXPECT_EQ(candidates[2], MovieTheatre::Position(11, 7));
  EXPECT_EQ(candidates[3], MovieTheatre::Position(9, 7));
  EXPECT_EQ(candidates[4], MovieTheatre::Position(9, 5)); 
  EXPECT_EQ(candidates[5], MovieTheatre::Position(2, 5));
  EXPECT_EQ(candidates[6], MovieTheatre::Position(2, 3));
  EXPECT_EQ(candidates[7], MovieTheatre::Position(7, 3));
}

TEST(MovieTheatreTest, TestCase1) {
  MovieTheatre theatre(kExampleInput);
  auto result = theatre.maximimal_area();
  EXPECT_EQ(result, 50);
}

TEST(MovieTheatreTest, TestCase2) {
  MovieTheatre theatre(kExampleInput2);
  auto result = theatre.maximimal_area();
  EXPECT_EQ(result, 20);
}

TEST(MovieTheatreTest, SortByXThenY) {
  MovieTheatre::CornerCandidates candidates = {
    {7,1},
    {11,1},
    {11,7},
    {9,7},
    {9,5},
    {2,5},
    {2,3},
    {7,3},
    {2, 1},
  };

  MovieTheatre::sort_by_x_then_y(candidates);
  // clang-format off
  EXPECT_EQ(candidates, MovieTheatre::CornerCandidates({
    {2, 1},
    {2, 3}, 
    {2, 5},
    {7, 1},
    {7, 3},
    {9, 5},
    {9, 7},
    {11, 1},
    {11, 7},
    }));
  // clang-format on
}

} // namespace
} // namespace movie_theatre
