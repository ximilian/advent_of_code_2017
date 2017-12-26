#include "04_high_entropy_passphrase.hpp"

#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

bool isAnagram(const std::string& word, const std::vector<std::string>& dict) {
    for (auto wdict : dict) {
        if (wdict == word) {
          return true;
        }
    }
    return false;
}

bool HighEntrpyPassphrase::isValidWithNoAnagram(const std::string& input) {
  std::istringstream iss(input);
  std::string word;
  std::vector<std::string> dict;
  while (iss >> word) {
      std::sort(word.begin(), word.end());
      if (isAnagram(word, dict)) {
        return false;
      }
      dict.push_back(word);
  }
  return isValid(input);
}

bool HighEntrpyPassphrase::isValid(const std::string& input) {
  std::istringstream iss(input);
  std::string word;
  std::map<std::string, int> dict;
  bool has_a_word = false;
  while (iss >> word) {
    dict[word]++;
    has_a_word = true;
  }
  for (auto item : dict) {
    if (item.second > 1) {
      return false;
    }
  }
  return has_a_word;
}

int HighEntrpyPassphrase::countValidPassphrase(const std::string& input) {
  std::istringstream iss(input);
  int count = 0;
  std::string line;
  while (getline(iss, line)) {
    if (isValid(line)) {
      count++;
    }
  }

  return count;
}


int HighEntrpyPassphrase::countValidPassphraseNoAnagram(const std::string& input) {
  std::istringstream iss(input);
  int count = 0;
  std::string line;
  while (getline(iss, line)) {
    if (isValidWithNoAnagram(line)) {
      count++;
    }
  }

  return count;
}

