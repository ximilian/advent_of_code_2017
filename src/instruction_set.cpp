#include "instruction_set.hpp"

template <typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
  return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

template <typename T>
ConditionFactoryRegister<T>::ConditionFactoryRegister(const std::string& cond) {
  ConditionFactory::GetFactory()[cond] = []() { return make_unique<T>(); };
}

ConditionFactory::RegistryMap& ConditionFactory::GetFactory() {
  static RegistryMap impl;
  return impl;
}

std::unique_ptr<Condition> ConditionFactory::create(const std::string& reg, const std::string& cond, int value) {
  auto it = GetFactory().find(cond);
  if (it == GetFactory().end()) {
    return make_unique<Condition>();
  }
  auto condition          = it->second();
  condition->value        = value;
  condition->registerName = reg;
  return std::move(condition);
}

template <typename T>
OperationFactoryRegister<T>::OperationFactoryRegister(const std::string& op) {
  OperationFactory::GetFactory()[op] = []() { return make_unique<T>(); };
}

OperationFactory::RegistryMap& OperationFactory::GetFactory() {
  static RegistryMap impl;
  return impl;
}

std::unique_ptr<Operation> OperationFactory::create(const std::string& reg, const std::string& op, int value) {
  auto it = GetFactory().find(op);
  if (it == GetFactory().end()) {
    return make_unique<Operation>();
  }
  auto operation          = it->second();
  operation->value        = value;
  operation->registerName = reg;
  return std::move(operation);
}

Instruction::Instruction(std::unique_ptr<Condition> cond, std::unique_ptr<Operation> op)
    : cond(std::move(cond)), op(std::move(op)) {
}

#define DEFINE_CONDITION(Kode, Tag)                                       \
  Condition##Kode::Condition##Kode() : Condition(Condition::Code::Kode) { \
  }                                                                       \
  ConditionFactoryRegister<Condition##Kode> Condition##Kode::Register = ConditionFactoryRegister<Condition##Kode>(Tag);

#define DEFINE_OPERATION(Kode, Tag)                                       \
  Operation##Kode::Operation##Kode() : Operation(Operation::Code::Kode) { \
  }                                                                       \
  OperationFactoryRegister<Operation##Kode> Operation##Kode::Register = OperationFactoryRegister<Operation##Kode>(Tag);

DEFINE_CONDITION(LT, "<")
DEFINE_CONDITION(GT, ">")
DEFINE_CONDITION(LE, "<=")
DEFINE_CONDITION(GE, ">=")
DEFINE_CONDITION(EQ, "==")
DEFINE_CONDITION(NEQ, "!=")

DEFINE_OPERATION(INC, "inc")
DEFINE_OPERATION(DEC, "dec")

bool ConditionLT::evaluate(Registers& regs) {
  return regs[registerName] < value;
}

bool ConditionGT::evaluate(Registers& regs) {
  return regs[registerName] > value;
}

bool ConditionLE::evaluate(Registers& regs) {
  return regs[registerName] <= value;
}

bool ConditionGE::evaluate(Registers& regs) {
  return regs[registerName] >= value;
}

bool ConditionEQ::evaluate(Registers& regs) {
  return regs[registerName] == value;
}

bool ConditionNEQ::evaluate(Registers& regs) {
  return regs[registerName] != value;
}

void OperationINC::execute(Registers& regs) {
  regs[registerName] += value;
}

void OperationDEC::execute(Registers& regs) {
  regs[registerName] -= value;
}
