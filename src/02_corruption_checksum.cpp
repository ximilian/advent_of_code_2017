#include "02_corruption_checksum.hpp"

#include <sstream>
#include <climits>
#include <vector>

int CorruptionChecksum::check(const std::string& input) {
  return check_base(input, CorruptionChecksum::compute_single_checksum);
}

int CorruptionChecksum::check_division(const std::string& input) {
  return check_base(input, CorruptionChecksum::compute_single_checksum_division);
}

int CorruptionChecksum::check_base(const std::string& input, std::function<int(const std::string&)> method) {
  int checksum = 0;
  std::istringstream iss(input);
  std::string line;
  while (std::getline(iss, line)) {
    checksum += method(line);
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

int CorruptionChecksum::compute_single_checksum_division(const std::string& line) {
  int result = 0;

  std::vector<int> numbers;
  std::istringstream iss(line);
  int n1, n2;
  while (iss >> n1) {
    numbers.push_back(n1);
  }

  bool found  = false;
  size_t idx1 = 0, idx2 = 1;
  while (not found && not numbers.empty() && idx1<numbers.size()) {
    n1 = numbers[idx1];
    for (; idx2 < numbers.size(); ++idx2) {
      n2    = numbers[idx2];
      int r = n1 % n2;
      if (r == 0) {
        result = n1 / n2;
        found  = true;
        break;
      }
      r = n2 % n1;
      if (r == 0) {
        result = n2 / n1;
        found  = true;
        break;
      }
    }
    idx1++;
    idx2 = idx1 + 1;
  }
  return result;
}