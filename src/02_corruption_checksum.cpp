#include "02_corruption_checksum.hpp"

#include <sstream>
#include <climits>

#include <iostream>

int CorruptionChecksum::check(const std::string& input) {
  int checksum = 0;
  std::istringstream iss(input);
  std::string line;
  while (std::getline(iss, line)) {
    checksum += compute_single_checksum(line);
  }
  return checksum;
}

int CorruptionChecksum::compute_single_checksum(const std::string& line) {
  int largest  = -INT_MAX;
  int smallest = INT_MAX;

  std::istringstream iss(line);
  int number = -1;
  while (iss >> number) {
    largest  = std::max(number, largest);
    smallest = std::min(number, smallest);
  }
  if (number == -1) {
    return 0;
  }
  return largest - smallest;
}