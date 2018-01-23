#include "09_stream_processing.hpp"
#include "gtest/gtest.h"

#include "test_utils.hpp"

class StreamProcessingTest : public ::testing::Test {
 public:
  const std::string inputFilename = "data/input_09_stream_processing.txt";
};

TEST_F(StreamProcessingTest, _solvePuzzleInputPartOne) {
  std::cout << TestUtils::ReadInputFile(inputFilename) << "\n";
}

TEST_F(StreamProcessingTest, _solvePuzzleInputPartTwo) {
}
