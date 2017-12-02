#include "01_inverse_captcha.hpp"

int InverseCaptcha::compute(const std::string& input) {
  int sum = 0;
  if (!input.empty()) {
    char prev = input.back();
    for (char c : input) {
      if (c == prev) {
        sum += std::stoi(std::string(1, c));
      }
      prev = c;
    }
  }
  return sum;
}

int InverseCaptcha::compute_halfway(const std::string& input) {
  int sum       = 0;
  size_t length = input.size();
  if (length > 0) {
    size_t index = length/2;
    for (char c : input) {
      char prev    = input[index];
      if (c == prev) {
        sum += std::stoi(std::string(1, c));
      }
      prev  = c;
      index = (index+1) % length;
    }
  }
  return sum;
}
