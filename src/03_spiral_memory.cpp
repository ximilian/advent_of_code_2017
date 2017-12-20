#include "03_spiral_memory.hpp"

int getNthElement(int i) {
  return 1 + i* 2 * 4;
}

int SpiralMemory::solve(const std::string& input) {
  return getNthElement(std::stoi(input));
}
