#ifndef TEST_UTILS_HPP_
#define TEST_UTILS_HPP_

#include <string>
#include <fstream>
#include <iostream>

class TestUtils {
 public:
  static std::string ReadInputFile(const std::string& inputFile) {
    std::ifstream ifs(inputFile);
    if (ifs.is_open()) {
      std::string output((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
      return output;
    }
    else {
      // when running from cmake, working dir is build instead the current path
      ifs.open("../" + inputFile);
      if (ifs.is_open()) {
        std::string output((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
        return output;
      }
      else {
        std::cout << "Non existing file: " << inputFile << "\n";
      }
    }
    return "";
  }
};

#endif