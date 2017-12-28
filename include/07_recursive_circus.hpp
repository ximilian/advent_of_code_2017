#include <string>
#include <queue>
#include <map>
#include <memory>
#include <tuple>

struct Node {
  std::string name;
  int weight;
  std::vector<std::string> children;
  std::string parent;
};

class RecursiveCircus {
 public:
  std::string computeRootNode(const std::string& input);
  int computeBalancedWeight(const std::string& input);

  Node parseLine(const std::string& line);

 private:
  std::queue<std::string> heap;
  std::map<std::string, Node> tree;

  void buildTree(const std::string& input);
  void buildLink();
  std::string retrieveRoot(const std::string& item);
  int retrieveSubTreeWeight(const std::string& item);
  std::tuple<int, bool> retrieveBalanceWeight(const std::string& item);
};
