#include "03_spiral_memory.hpp"
#include "gtest/gtest.h"

class SpiralMemoryTest: public ::testing::Test {
public:
  virtual void SetUp() {
    solver.reset();
  }

  SpiralMemory solver;
};

TEST_F(SpiralMemoryTest, solve_whenInputIs1_shouldBe0) {
  EXPECT_EQ(0, solver.solve("1"));
}

TEST_F(SpiralMemoryTest, solve_whenInputIs12_shouldBe3) {
  EXPECT_EQ(3, solver.solve("12"));
}

TEST_F(SpiralMemoryTest, solve_whenInputIs23_shouldBe2) {
  EXPECT_EQ(2, solver.solve("23"));
}

TEST_F(SpiralMemoryTest, solve_whenInputIs1024_shouldBe31) {
  EXPECT_EQ(31, solver.solve("1024"));
}

TEST_F(SpiralMemoryTest, solve_solvePuzzleInputPartOne) {
  EXPECT_EQ(475, solver.solve("277678"));
}

TEST_F(SpiralMemoryTest, solveSum_whenInputIs1_shouldBe2) {
  EXPECT_EQ(2, solver.solveSum("1"));
}

TEST_F(SpiralMemoryTest, solveSum_whenInputIs2_shouldBe3) {
  EXPECT_EQ(4, solver.solveSum("2"));
}

TEST_F(SpiralMemoryTest, solveSum_whenInputIs3_shouldBe4) {
  EXPECT_EQ(4, solver.solveSum("3"));
}

TEST_F(SpiralMemoryTest, solveSum_whenInputIs4_shouldBe5) {
  EXPECT_EQ(5, solver.solveSum("4"));
}

TEST_F(SpiralMemoryTest, solveSum_whenInputIs5_shouldBe10) {
  EXPECT_EQ(10, solver.solveSum("5"));
}

TEST_F(SpiralMemoryTest, solveSum_solvePuzzleInputPartTwo) {
  EXPECT_EQ(279138, solver.solveSum("277678"));
}
