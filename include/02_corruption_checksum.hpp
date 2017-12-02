#include <string>

class CorruptionChecksum {

 public:
  static int check(const std::string& input);

 private:
  static int compute_single_checksum(const std::string& line);
};