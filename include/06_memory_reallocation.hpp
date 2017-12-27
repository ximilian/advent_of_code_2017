#include <string>
#include <vector>
#include <unordered_set>

class MemoryReallocation {
 public:
  int detectInfiniteLoop(const std::string& input);

  private:
   std::vector<int> load(const std::string& input);
   bool hasAlreadySeen(const std::string& configuration);
   void storeConfiguration(const std::string& configuration);
   std::string redistribute(std::vector<int>& banks);
   std::unordered_set<std::string> dict;
};
