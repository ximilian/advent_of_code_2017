#include <string>

class HighEntrpyPassphrase {
 public:
  int countValidPassphrase(const std::string& input);

  int countValidPassphraseNoAnagram(const std::string& input);

  bool isValid(const std::string& input);
  bool isValidWithNoAnagram(const std::string& input);
};
