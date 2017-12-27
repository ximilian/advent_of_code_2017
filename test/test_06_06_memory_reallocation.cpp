#include "06_memory_reallocation.hpp"
#include "gtest/gtest.h"

class MemoryReallocationTest : public ::testing::Test {
 public:
  std::string input = "14	0	15	12	11	11	3	5	1	6	8	4	9	1	8	4";
  MemoryReallocation solver;
};

TEST_F(MemoryReallocationTest, detectInfiniteLoop_whenTest_shouldComputeLoopSize) {
  EXPECT_EQ(5, solver.detectInfiniteLoop("0 2 7 0"));
}

TEST_F(MemoryReallocationTest, detectInfiniteLoop_solvePuzzleInputPartOne) {
    EXPECT_EQ(11137, solver.detectInfiniteLoop(input));
}

TEST_F(MemoryReallocationTest, _solvePuzzleInputPartTwo) {
}
