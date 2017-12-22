#include <string>
#include <tuple>
#include <map>

struct Coords {
  enum Orientation : int { E = 0, N, W, S };
  Coords(int _x = 0, int _y = 0, Orientation _o = E) : x(_x), y(_y), o(_o) {
  }
  void turnLeft() {
    int i = (static_cast<int>(o) + 1) % 4;
    o     = Orientation(i);
  }
  void turnRight() {
    int i = (static_cast<int>(o) - 1) % 4;
    o     = Orientation(i);
  }
  void step() {
    switch (o) {
      case E:
        x++;
        break;
      case N:
        y++;
        break;
      case W:
        x--;
        break;
      case S:
        y--;
        break;
    }
  }

  int x = 0;
  int y = 0;
  Orientation o;
};

class SpiralMemory {
 public:
  int solve(const std::string& input);

  int solveSum(const std::string& input);

  void reset();

 private:
  Coords generateNextCoords(const Coords& current);
  std::tuple<int, int, int> computeBounds(int input);
  std::tuple<int, Coords> computeEdgeDistance(int lower_bound, int upper_bound, int input);
  std::tuple<int, int> computeCoordinates(int input);
  int getNthElement(int i);

  int computeSum(const Coords& c);
  std::map<size_t, std::map<size_t, int>> coordinates;
};
