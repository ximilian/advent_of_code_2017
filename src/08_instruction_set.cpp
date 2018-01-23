#include "08_instruction_set.hpp"

#include <sstream>
#include <algorithm>
#include <iostream>

Instruction InstructionSetSolver::createInstruction(const std::string& input) {
  std::string reg, op, tok, reg_cond, cond;
  int value_op, value_cond;
  std::stringstream iss(input);
  iss >> reg >> op >> value_op >> tok >> reg_cond >> cond >> value_cond;
  return Instruction(ConditionFactory::create(reg_cond, cond, value_cond), OperationFactory::create(reg, op, value_op));
}

int maxInRegisters(const Registers& registers) {
  return std::max_element(std::begin(registers),
                          std::end(registers),
                          [](const std::pair<std::string, int>& p1, const std::pair<std::string, int>& p2) {
                            return p1.second < p2.second;
                          })
      ->second;
}

int InstructionSetSolver::maxValueInRegister(const std::string& input) {
  int max_element = 0;
  if (evaluate(input)) {
    max_element = maxInRegisters(registers);
  }
  return max_element;
}

int InstructionSetSolver::absoluteMaxValueInRegister(const std::string& input) {
  int max_element = 10;
  std::istringstream iss(input);
  std::string line;
  while (getline(iss, line)) {
    auto instr = createInstruction(line);
    if (instr.execute(registers)) {
      max_element      = std::max(max_element, maxInRegisters(registers));
    }
  }
  return max_element;
}

bool InstructionSetSolver::evaluate(const std::string& input) {
  std::istringstream iss(input);
  std::string line;
  bool didEvaluate = false;
  while (getline(iss, line)) {
    auto instr = createInstruction(line);
    didEvaluate |= instr.execute(registers);
  }
  return didEvaluate;
}