#include "03_spiral_memory.hpp"
#include <iostream>
#include <tuple>

int getNthElement(int i) {
  if (i <= 0) {
    return 1;
  }

  return i * 2 * 4 + getNthElement(i - 1);
}

std::tuple<int, int, int> computeBounds(int input) {
  int upper_bound   = 0;
  int lower_bound   = 0;
  int current_level = 0;
  bool found        = false;
  while (not found) {
    lower_bound = upper_bound;
    upper_bound = getNthElement(current_level);
    if (upper_bound >= input) {
      found = true;
      break;
    }
    current_level++;
  }

  return std::make_tuple(lower_bound, upper_bound, current_level);
}

int computeEdgeDistance(int lower_bound, int upper_bound, int input) {
  if (input == 1) {
    return 0;
  }
  int delta = (upper_bound - lower_bound)/4;
  return abs(delta/2 - (input-lower_bound) % delta);
}

int SpiralMemory::solve(const std::string& sinput) {
  int input = std::stoi(sinput);

  auto bounds = computeBounds(input);

  std::cout << "Upper bound for " << std::get<0>(bounds) << " < " << input << " < " << std::get<1>(bounds) << " | "
            << std::get<2>(bounds) << "\n";

  auto distance = computeEdgeDistance(std::get<0>(bounds), std::get<1>(bounds), input);

  return std::get<2>(bounds) + distance;
}
