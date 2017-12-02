#include <string>
#include <functional>

class CorruptionChecksum {

 public:
  static int check(const std::string& input);

  static int check_division(const std::string& input);

 private:
  static int check_base(const std::string& input, std::function<int(const std::string&)> method);
  static int compute_single_checksum(const std::string& line);
  static int compute_single_checksum_division(const std::string& line);
};