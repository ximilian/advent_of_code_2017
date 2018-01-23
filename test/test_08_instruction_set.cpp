#include "08_instruction_set.hpp"
#include "gtest/gtest.h"

#include "test_utils.hpp"

class InstructionSetTest : public ::testing::Test {
 public:
  virtual void SetUp() {
    solver.reset();
  }
  InstructionSetSolver solver;

  const std::string inputFile = "data/input_08_instruction_set.txt";
};

TEST_F(InstructionSetTest, maxValueInRegister_whenEmpty_shouldCompute0) {
  std::string test_input(R"(
  )");
  EXPECT_EQ(0, solver.maxValueInRegister(test_input));
}

TEST_F(InstructionSetTest, maxValueInRegister_whenEmptyNoNewline_shouldCompute0) {
  std::string test_input(R"()");
  EXPECT_EQ(0, solver.maxValueInRegister(test_input));
}

TEST_F(InstructionSetTest, createinstruction_whenLessThan_shouldParseInstruction) {
  Instruction instr = solver.createInstruction("es inc 496 if kg < 2723");
  EXPECT_EQ(Condition::Code::LT, instr.cond->code);
  EXPECT_EQ(Operation::Code::INC, instr.op->code);
}

TEST_F(InstructionSetTest, createinstruction_whenLessOrEqualThan_shouldParseInstruction) {
  Instruction instr = solver.createInstruction("es inc 496 if kg <= 2723");
  EXPECT_EQ(Condition::Code::LE, instr.cond->code);
  EXPECT_EQ(Operation::Code::INC, instr.op->code);
}

TEST_F(InstructionSetTest, createinstruction_whenGreaterThan_shouldParseInstruction) {
  Instruction instr = solver.createInstruction("es inc 496 if kg > 2723");
  EXPECT_EQ(Condition::Code::GT, instr.cond->code);
  EXPECT_EQ(Operation::Code::INC, instr.op->code);
}

TEST_F(InstructionSetTest, createinstruction_whenGreaterOrEqualThan_shouldParseInstruction) {
  Instruction instr = solver.createInstruction("es inc 496 if kg >= 2723");
  EXPECT_EQ(Condition::Code::GE, instr.cond->code);
  EXPECT_EQ(Operation::Code::INC, instr.op->code);
}

TEST_F(InstructionSetTest, createinstruction_whenEqual_shouldParseInstruction) {
  Instruction instr = solver.createInstruction("es dec 496 if kg == 2723");
  EXPECT_EQ(Condition::Code::EQ, instr.cond->code);
  EXPECT_EQ(Operation::Code::DEC, instr.op->code);
}

TEST_F(InstructionSetTest, createinstruction_whenNotEqual_shouldParseInstruction) {
  Instruction instr = solver.createInstruction("es inc 496 if kg != 2723");
  EXPECT_EQ(Condition::Code::NEQ, instr.cond->code);
  EXPECT_EQ(Operation::Code::INC, instr.op->code);
}

TEST_F(InstructionSetTest, createinstruction_whenInvalid_shouldReturnNop) {
  Instruction instr = solver.createInstruction("es 496 if kg <= 2723");
  EXPECT_EQ(Operation::Code::NOP, instr.op->code);
}

TEST_F(InstructionSetTest, createinstruction_whenInvalidOperation_shouldReturnNop) {
  Instruction instr = solver.createInstruction("es Inc 496 if kg <= 2723");
  EXPECT_EQ(Operation::Code::NOP, instr.op->code);
}

TEST_F(InstructionSetTest, createinstruction_whenInvalidCond_shouldReturnNop) {
  Instruction instr = solver.createInstruction("es inc 496 if kg =< 2723");
  EXPECT_EQ(Condition::Code::NOP, instr.cond->code);
}

TEST_F(InstructionSetTest, maxValueInRegister_whenTestInput_shouldComputeMax) {
  std::string test_input(R"(
b inc 5 if a >= 0
c dec 5 if a <= 0
d dec 5 if a < 0
a inc 2 if b > 1
)");
  solver.evaluate(test_input);
  EXPECT_EQ(2, solver.registers["a"]);
  EXPECT_EQ(5, solver.registers["b"]);
  EXPECT_EQ(-5, solver.registers["c"]);
  EXPECT_EQ(0, solver.registers["d"]);
}

TEST_F(InstructionSetTest, maxValueInRegister_whenExerciseTestInput_shouldComputeMax) {
  std::string test_input(R"(
b inc 5 if a > 1
a inc 1 if b < 5
c dec -10 if a >= 1
c inc -20 if c == 10
)");
  EXPECT_EQ(1, solver.maxValueInRegister(test_input));
  EXPECT_EQ(1, solver.registers["a"]);
  EXPECT_EQ(0, solver.registers["b"]);
  EXPECT_EQ(-10, solver.registers["c"]);
}

TEST_F(InstructionSetTest, absoluteMaxValueInRegister_whenExerciseTestInput_shouldComputeMax) {
  std::string test_input(R"(
b inc 5 if a > 1
a inc 1 if b < 5
c dec -10 if a >= 1
c inc -20 if c == 10
)");
  EXPECT_EQ(10, solver.absoluteMaxValueInRegister(test_input));
  EXPECT_EQ(1, solver.registers["a"]);
  EXPECT_EQ(0, solver.registers["b"]);
  EXPECT_EQ(-10, solver.registers["c"]);
}

TEST_F(InstructionSetTest, maxValueInRegister_solvePuzzleInputPartOne) {
  EXPECT_EQ(7787, solver.maxValueInRegister(TestUtils::ReadInputFile(inputFile)));
}

TEST_F(InstructionSetTest, absoluteMaxValueInRegister_solvePuzzleInputPartTwo) {
  EXPECT_EQ(8997, solver.absoluteMaxValueInRegister(TestUtils::ReadInputFile(inputFile)));
}
