#include "06_memory_reallocation.hpp"
#include <sstream>
#include <iterator>
#include <algorithm>
#include <iostream>

std::string getStringRepresentation(std::vector<int>& banks) {
  std::stringstream configuration;
  std::copy(banks.begin(), banks.end(), std::ostream_iterator<int>(configuration, " "));
  return configuration.str();
}

int nextIndex(const std::vector<int>& banks, int index) {
  return (index + 1) % banks.size();
}

void MemoryReallocation::storeConfiguration(const std::string& configuration, int index) {
  dict[configuration] = index;
}

std::string MemoryReallocation::redistribute(int index) {
  storeConfiguration(getStringRepresentation(banks), index);

  auto max_banks            = std::max_element(banks.begin(), banks.end());
  int value_to_redistribute = *max_banks;

  int cursor    = max_banks - banks.begin();
  banks[cursor] = 0;

  while (value_to_redistribute > 0) {
    int i = nextIndex(banks, cursor);
    banks[i]++;
    value_to_redistribute--;
    cursor = i;
  }
  return getStringRepresentation(banks);
}

bool MemoryReallocation::hasAlreadySeen(const std::string& configuration) {
  return dict.find(configuration) != dict.end();
}

void MemoryReallocation::load(const std::string& input) {
  std::istringstream iss(input);
  int bank;
  banks.clear();
  while (iss >> bank) {
    banks.push_back(bank);
  }
}

int MemoryReallocation::detectInfiniteLoop(const std::string& input) {
  load(input);
  int runs                      = 0;
  std::string new_configuration = redistribute(runs++);
  while (not hasAlreadySeen(new_configuration)) {
    new_configuration = redistribute(runs++);
  }
  return runs;
}

int MemoryReallocation::computeLoopSize(const std::string& input) {
  int loop_cycle = detectInfiniteLoop(input);

  return loop_cycle - dict[getStringRepresentation(banks)];
}
