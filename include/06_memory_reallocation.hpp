#include <string>
#include <vector>
#include <unordered_map>

class MemoryReallocation {
 public:
  int detectInfiniteLoop(const std::string& input);
  int computeLoopSize(const std::string& input);

  private:
   void load(const std::string& input);
   bool hasAlreadySeen(const std::string& configuration);
   void storeConfiguration(const std::string& configuration, int index);
   std::string redistribute(int index);

   std::vector<int> banks;
   std::unordered_map<std::string, int> dict;
};
