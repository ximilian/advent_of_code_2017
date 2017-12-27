#include "05_twisty_trampolines.hpp"
#include <vector>
#include <sstream>
#include <iostream>

std::vector<int> load(const std::string& input) {
  std::vector<int> registers;
  std::istringstream iss(input);
  int reg;
  while (iss >> reg) {
    registers.push_back(reg);
  }
  return registers;
}

int computeInstruction(std::vector<int>& input, int instr) {
  int current_instr = input[instr];
  input[instr]++;
  return instr + current_instr;
}

int computeConditionalInstruction(std::vector<int>& input, int instr) {
  int offset = input[instr];
  if (offset > 2) {
    input[instr]--;
  }
  else {
    input[instr]++;
  }
  return instr + offset;
}

int TwistyTrampolines::simpleJump(const std::string& input) {
  return jump(input, computeInstruction);
}

int TwistyTrampolines::conditionalJump(const std::string& input) {
  return jump(input, computeConditionalInstruction);
}

int TwistyTrampolines::jump(const std::string& input, std::function<int(std::vector<int>&, int)> jumpMethod) {
  std::vector<int> instructions = load(input);
  int exit_instruction          = instructions.size();
  int current_instruction       = 0;
  int jumps                     = 0;
  while (true) {
    current_instruction = jumpMethod(instructions, current_instruction);

    jumps++;
    if (current_instruction >= exit_instruction) {
      break;
    }
  }

  return jumps;
}
