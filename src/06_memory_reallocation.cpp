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

void MemoryReallocation::storeConfiguration(const std::string& configuration) {
  dict.insert(configuration);
}

std::string MemoryReallocation::redistribute(std::vector<int>& banks) {
  storeConfiguration(getStringRepresentation(banks));

  auto max_banks            = std::max_element(banks.begin(), banks.end());
  int value_to_redistribute = *max_banks;

  int cursor                = max_banks - banks.begin();
  banks[cursor]             = 0;

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

std::vector<int> MemoryReallocation::load(const std::string& input) {
  std::vector<int> banks;
  std::istringstream iss(input);
  int bank;
  while (iss >> bank) {
    banks.push_back(bank);
  }
  return banks;
}

int MemoryReallocation::detectInfiniteLoop(const std::string& input) {
  std::vector<int> banks        = load(input);
  std::string new_configuration = redistribute(banks);
  int runs                      = 1;
  while (not hasAlreadySeen(new_configuration)) {
    new_configuration = redistribute(banks);
    runs++;
  }
  return runs;
}
