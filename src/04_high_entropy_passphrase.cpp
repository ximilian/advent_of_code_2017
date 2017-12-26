#include "04_high_entropy_passphrase.hpp"

#include <sstream>
#include <map>
#include <iostream>

bool HighEntrpyPassphrase::isValid(const std::string& input) {
  std::istringstream iss(input);
  std::string word;
  std::map<std::string, int> dict;
  std::cout << "[" << input << "]\n";
  bool has_a_word = false;
  while (iss >> word) {
    dict[word]++;
    has_a_word = true;
  }
  for (auto item : dict) {
    if (item.second > 1) {
      return false;
    }
  }
  return has_a_word;
}

int HighEntrpyPassphrase::solve(const std::string& input) {
  std::istringstream iss(input);
  int count = 0;
  std::string line;
  while (getline(iss, line)) {
    if (isValid(line)) {
      count++;
    }
  }

  return count;
}
