#include <string>

#include "instruction_set.hpp"

class InstructionSetSolver {
 public:
  int maxValueInRegister(const std::string& input);
  int absoluteMaxValueInRegister(const std::string& input);

  Instruction createInstruction(const std::string& input);

  bool evaluate(const std::string& input);

  void reset() {
    registers.clear();
  }

  Registers registers;
};
