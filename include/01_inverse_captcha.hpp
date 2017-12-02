#include <string>


class InverseCaptcha {
 public:
  static int compute(const std::string& input);
  static int compute_halfway(const std::string& input);
};
