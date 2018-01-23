#include "05_twisty_trampolines.hpp"
#include "gtest/gtest.h"

#include "test_utils.hpp"

class TwistyTrampolinesTest : public ::testing::Test {
 public:
  TwistyTrampolines solver;
  const std::string inputFilename = "data/input_05_twisty_trampolines.txt";
};

TEST_F(TwistyTrampolinesTest, simpleJump_whenTestList_shouldComputeJumps) {
  EXPECT_EQ(5, solver.simpleJump("0 3 0 1 -3"));
}

TEST_F(TwistyTrampolinesTest, simpleJump_solvePuzzleInputPartOne) {
  EXPECT_EQ(358309, solver.simpleJump(TestUtils::ReadInputFile(inputFilename)));
}

TEST_F(TwistyTrampolinesTest, conditionalJump_whenTestList_shouldComputeJumps) {
  EXPECT_EQ(10, solver.conditionalJump("0 3 0 1 -3"));
}

TEST_F(TwistyTrampolinesTest, conditionalJump_solvePuzzleInputPartTwo) {
  EXPECT_EQ(28178177, solver.conditionalJump(TestUtils::ReadInputFile(inputFilename)));
}
