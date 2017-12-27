#include <string>
#include <functional>
#include <vector>

class TwistyTrampolines {
 public:
  int simpleJump(const std::string& input);
  int conditionalJump(const std::string& input);

  private:
   int jump(const std::string& input, std::function<int(std::vector<int>&, int)> jumpMethod);
};
