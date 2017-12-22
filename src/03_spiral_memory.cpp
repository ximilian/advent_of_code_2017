#include "03_spiral_memory.hpp"
#include <cmath>

void SpiralMemory::reset() {
  coordinates.clear();
}

int SpiralMemory::getNthElement(int i) {
  if (i <= 0) {
    return 1;
  }

  return i * 2 * 4 + getNthElement(i - 1);
}

std::tuple<int, int, int> SpiralMemory::computeBounds(int input) {
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

std::tuple<int, Coords> SpiralMemory::computeEdgeDistance(int lower_bound, int upper_bound, int input) {
  int distance = 0;
  Coords Coords;
  if (input != 1) {
    int delta = (upper_bound - lower_bound) / 4;
    distance  = delta / 2 - (input - lower_bound) % delta;
    auto q    = (upper_bound - lower_bound) / delta;
    switch (q) {
      case 1:
        Coords.x = 1;
        Coords.y = distance > 0 ? -1 : 1;
        break;
      case 2:
        Coords.x = distance > 0 ? 1 : -1;
        Coords.y = 1;
        break;
      case 3:
        Coords.x = -1;
        Coords.y = distance > 0 ? 1 : -1;
        break;
      case 4:
        Coords.x = distance > 0 ? -1 : 1;
        Coords.y = -1;
        break;
    }
  }
  return std::make_tuple(distance, Coords);
}

std::tuple<int, int> SpiralMemory::computeCoordinates(int input) {
  auto bounds   = computeBounds(input);
  auto distance = computeEdgeDistance(std::get<0>(bounds), std::get<1>(bounds), input);
  return std::make_tuple(std::get<1>(distance).x * std::get<2>(bounds),
                         std::get<1>(distance).y * std::get<0>(distance));
}

int SpiralMemory::solve(const std::string& sinput) {
  auto coords = computeCoordinates(std::stoi(sinput));

  return abs(std::get<0>(coords)) + abs(std::get<1>(coords));
}

int SpiralMemory::computeSum(const Coords& c) {
  int sum = 0;
  for (auto dx : { -1, 0, 1 }) {
    for (auto dy : { -1, 0, 1 }) {
      auto dirx = coordinates.find(dx + c.x);
      if (dirx != coordinates.end()) {
        auto diry = dirx->second.find(dy + c.y);
        if (diry != dirx->second.end()) {
          sum += diry->second;
        }
      }
    }
  }
  coordinates[c.x][c.y] = sum;
  return sum;
}

Coords SpiralMemory::generateNextCoords(const Coords& current) {
  Coords next(current);
  next.step();

  Coords rightCoord(next);
  rightCoord.turnLeft();
  rightCoord.step();
  auto x = coordinates.find(rightCoord.x);
  if (x == coordinates.end()) {
    next.turnLeft();
  }
  else {
    auto y = x->second.find(rightCoord.y);
    if (y == x->second.end()) {
      next.turnLeft();
    }
  }
  return next;
}

int SpiralMemory::solveSum(const std::string& sinput) {
  int input = std::stoi(sinput);

  coordinates[0][0] = 1;

  int current_value = 1;
  bool found        = false;
  Coords coords(0, 0, Coords::E);
  while (not found) {
    coords = generateNextCoords(coords);
    current_value = computeSum(coords);

    if (current_value > input) {
      found = true;
    }
  }

  return current_value;
}
