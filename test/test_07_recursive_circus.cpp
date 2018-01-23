#include "07_recursive_circus.hpp"
#include "gtest/gtest.h"

#include "test_utils.hpp"

class RecursiveCircusTest : public ::testing::Test {
 public:
  RecursiveCircus solver;
  const std::string inputFilename = "data/input_07_recursive_circus.txt";
};

TEST_F(RecursiveCircusTest, parseLine_whenOnlyNode_shouldParseIntoNode) {
  Node n = solver.parseLine("gqzlx (81)");

  EXPECT_STREQ("gqzlx", n.name.c_str());
  EXPECT_EQ(static_cast<size_t>(0), n.children.size());
  EXPECT_TRUE(n.parent.empty());
}

TEST_F(RecursiveCircusTest, parseLine_whenNodeWithOneChild_shouldParseIntoNode) {
  Node n = solver.parseLine("gqzlx (81) -> hpboonp");

  EXPECT_STREQ("gqzlx", n.name.c_str());
  EXPECT_EQ(static_cast<size_t>(1), n.children.size());
  EXPECT_TRUE(n.parent.empty());
}

TEST_F(RecursiveCircusTest, parseLine_whenNodeWithMultipleChildren_shouldParseIntoNode) {
  Node n = solver.parseLine("gqzlx (81) -> hpboonp, vjycok");

  EXPECT_STREQ("gqzlx", n.name.c_str());
  EXPECT_EQ(static_cast<size_t>(2), n.children.size());
  EXPECT_TRUE(n.parent.empty());
}

TEST_F(RecursiveCircusTest, computeRootNode_whenFirstTest_shouldComputeRoot) {
  std::string test_input = R"(pbga (66)
xhth (57)
ebii (61)
havc (66)
ktlj (57)
fwft (72) -> ktlj, cntj, xhth
qoyq (66)
padx (45) -> pbga, havc, qoyq
tknk (41) -> ugml, padx, fwft
jptl (61)
ugml (68) -> gyxo, ebii, jptl
gyxo (61)
cntj (57))";
  EXPECT_EQ("tknk", solver.computeRootNode(test_input));
}

TEST_F(RecursiveCircusTest, _solvePuzzleInputPartOne) {
  EXPECT_EQ("svugo", solver.computeRootNode(TestUtils::ReadInputFile(inputFilename)));
}

TEST_F(RecursiveCircusTest, computeBalancedWeight_whenFirstTest_shoulComputeBalancedWeight) {
  std::string test_input = R"(pbga (66)
xhth (57)
ebii (61)
havc (66)
ktlj (57)
fwft (72) -> ktlj, cntj, xhth
qoyq (66)
padx (45) -> pbga, havc, qoyq
tknk (41) -> ugml, padx, fwft
jptl (61)
ugml (68) -> gyxo, ebii, jptl
gyxo (61)
cntj (57))";
  EXPECT_EQ(60, solver.computeBalancedWeight(test_input));
}

TEST_F(RecursiveCircusTest, computeBalancedWeight_whenLessThanReference_shoulComputeBalancedWeight) {
  std::string test_input = R"(pbga (9)
xhth (9)
ebii (9)
havc (9)
ktlj (9)
fwft (2) -> ktlj, cntj, xhth
qoyq (9)
padx (2) -> pbga, havc, qoyq
tknk (1) -> ugml, padx, fwft
jptl (9)
ugml (2) -> gyxo, ebii, jptl
gyxo (1) -> aaaa, bbbb
aaaa (3)
bbbb (3)
cntj (9))";
  EXPECT_EQ(3, solver.computeBalancedWeight(test_input));
}

TEST_F(RecursiveCircusTest, computeBalancedWeight_whenMoreThanReference_shoulComputeBalancedWeight) {
  std::string test_input = R"(pbga (9)
xhth (9)
ebii (9)
havc (9)
ktlj (9)
fwft (2) -> ktlj, cntj, xhth
qoyq (9)
padx (2) -> pbga, havc, qoyq
tknk (1) -> ugml, padx, fwft
jptl (9)
ugml (2) -> gyxo, ebii, jptl
gyxo (10) -> aaaa, bbbb
aaaa (3)
bbbb (3)
cntj (9))";
  EXPECT_EQ(3, solver.computeBalancedWeight(test_input));
}

TEST_F(RecursiveCircusTest, computeBalancedWeight_whenSingleNode_shoulComputeBalancedWeight) {
  std::string test_input = R"(pbga (9))";
  EXPECT_EQ(9, solver.computeBalancedWeight(test_input));
}

TEST_F(RecursiveCircusTest, _solvePuzzleInputPartTwo) {
  EXPECT_EQ(1152, solver.computeBalancedWeight(TestUtils::ReadInputFile(inputFilename)));
}
