#ifndef INSTRUCTION_SET_HPP_
#define INSTRUCTION_SET_HPP_

#include <string>
#include <unordered_map>
#include <map>
#include <functional>
#include <memory>

typedef std::map<std::string, int> Registers;
class Condition;
class Operation;
class Instruction;

class ConditionFactory {
 public:
  typedef std::unordered_map<std::string, std::function<std::unique_ptr<Condition>()>> RegistryMap;
  static std::unique_ptr<Condition> create(const std::string& reg, const std::string& cond, int value);

  static RegistryMap& GetFactory();
};

template <typename T>
struct ConditionFactoryRegister {
  ConditionFactoryRegister(const std::string& op);
};

class Condition {
 public:
  enum class Code {
    NOP = 0,
    LT,
    GT,
    LE,
    GE,
    EQ,
    NEQ,
  };
  Condition(Code code = Code::NOP) : code(code) {
  }
  virtual bool evaluate(Registers& regs) {
    return false;
  };

  std::string registerName;
  int value;
  Code code;
};

class OperationFactory {
 public:
  typedef std::unordered_map<std::string, std::function<std::unique_ptr<Operation>()>> RegistryMap;
  static std::unique_ptr<Operation> create(const std::string& reg, const std::string& op, int value);

  static RegistryMap& GetFactory();
};

template <typename T>
struct OperationFactoryRegister {
  OperationFactoryRegister(const std::string& op);
};

class Operation {
 public:
  enum class Code {
    INC = 1,
    NOP = 0,
    DEC = -1,
  };

  Operation(Code code = Code::NOP) : code(code) {
  }
  virtual void execute(Registers& regs){};

  std::string registerName;
  int value;
  Code code;
};

class Instruction {
 public:
  Instruction(std::unique_ptr<Condition> cond, std::unique_ptr<Operation> op);

  bool execute(Registers& regs) {
    if (cond->evaluate(regs)) {
      op->execute(regs);
      return true;
    }
    return false;
  };

  std::unique_ptr<Condition> cond;
  std::unique_ptr<Operation> op;
};

#define DECLARE_CONDITION(Kode)                                \
  class Condition##Kode : public Condition {                   \
   public:                                                     \
    Condition##Kode();                                         \
    virtual bool evaluate(Registers& regs);                    \
    static ConditionFactoryRegister<Condition##Kode> Register; \
  };

#define DECLARE_OPERATION(Kode)                                \
  class Operation##Kode : public Operation {                   \
   public:                                                     \
    Operation##Kode();                                         \
    virtual void execute(Registers& regs);                     \
    static OperationFactoryRegister<Operation##Kode> Register; \
  };

DECLARE_CONDITION(LT)
DECLARE_CONDITION(GT)
DECLARE_CONDITION(LE)
DECLARE_CONDITION(GE)
DECLARE_CONDITION(EQ)
DECLARE_CONDITION(NEQ)

DECLARE_OPERATION(INC)
DECLARE_OPERATION(DEC)

#endif