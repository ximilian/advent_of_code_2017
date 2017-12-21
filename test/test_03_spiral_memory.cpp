#include "03_spiral_memory.hpp"
#include "gtest/gtest.h"

TEST(SpiralMemoryTest, solve_test) {
  std::cout << SpiralMemory::solve("1") << std::endl;
  std::cout << SpiralMemory::solve("12") << std::endl;
  std::cout << SpiralMemory::solve("23") << std::endl;
  std::cout << SpiralMemory::solve("1024") << std::endl;
  std::cout << SpiralMemory::solve("277678") << std::endl;
  EXPECT_EQ(true, false);
}

TEST(SpiralMemoryTest, solve_whenInputIs1_shouldBe0) {
  EXPECT_EQ(0, SpiralMemory::solve("1"));
}

TEST(SpiralMemoryTest, solve_whenInputIs12_shouldBe3) {
  EXPECT_EQ(3, SpiralMemory::solve("12"));
}

TEST(SpiralMemoryTest, solve_whenInputIs23_shouldBe2) {
  EXPECT_EQ(2, SpiralMemory::solve("23"));
}

TEST(SpiralMemoryTest, solve_whenInputIs1024_shouldBe31) {
  EXPECT_EQ(31, SpiralMemory::solve("1024"));
}

TEST(SpiralMemoryTest, solve_solvePuzzleInputPartOne) {
  EXPECT_EQ(0, SpiralMemory::solve("277678"));
}

// TEST(SpiralMemoryTest, solve_solvePuzzleInputPartTwo) {
// }
