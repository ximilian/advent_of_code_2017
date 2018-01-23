#include "04_high_entropy_passphrase.hpp"
#include "gtest/gtest.h"

#include "test_utils.hpp"

TEST(HighEntropyPassphraseTest, isValid_whenInputIsValid_shouldBeTrue) {
  HighEntrpyPassphrase solver;
  EXPECT_TRUE(solver.isValid("aa bb cc dd ee"));
}

TEST(HighEntropyPassphraseTest, isValid_whenInputIsInvalid_shouldBeFalse) {
  HighEntrpyPassphrase solver;
  EXPECT_FALSE(solver.isValid("aa bb cc dd aa"));
}

TEST(HighEntropyPassphraseTest, isValid_whenInputIsValid2_shouldBeTrue) {
  HighEntrpyPassphrase solver;
  EXPECT_TRUE(solver.isValid("aa bb cc dd aaa"));
}

TEST(HighEntropyPassphraseTest, isValid_whenInputIsEmpty_shouldBeFalse) {
  HighEntrpyPassphrase solver;
  EXPECT_FALSE(solver.isValid(""));
}

const std::string inputFilename = "data/input_04_high_entropy_passphrase.txt";

TEST(HighEntropyPassphraseTest, countValidPassphrase_solvePuzzleInputPartOne) {
  HighEntrpyPassphrase solver;
  EXPECT_EQ(383, solver.countValidPassphrase(TestUtils::ReadInputFile(inputFilename)));
}

TEST(HighEntropyPassphraseTest, isValidWithNoAnagram_whenInputIsValid_shouldBeTrue) {
  HighEntrpyPassphrase solver;
  EXPECT_TRUE(solver.isValidWithNoAnagram("abcde fghij"));
}

TEST(HighEntropyPassphraseTest, isValidWithNoAnagram_whenInputIsAnagram_shouldBeFalse) {
  HighEntrpyPassphrase solver;
  EXPECT_FALSE(solver.isValidWithNoAnagram("abcde xyz ecdab"));
}

TEST(HighEntropyPassphraseTest, isValidWithNoAnagram_whenInputIsValid2_shouldBeTrue) {
  HighEntrpyPassphrase solver;
  EXPECT_TRUE(solver.isValidWithNoAnagram("a ab abc abd abf abj"));
}

TEST(HighEntropyPassphraseTest, isValidWithNoAnagram_whenInputIsValid3_shouldBeTrue) {
  HighEntrpyPassphrase solver;
  EXPECT_TRUE(solver.isValidWithNoAnagram("iiii oiii ooii oooi oooo"));
}

TEST(HighEntropyPassphraseTest, isValidWithNoAnagram_whenInputIsInvalid_shouldBeTrue) {
  HighEntrpyPassphrase solver;
  EXPECT_FALSE(solver.isValidWithNoAnagram("oiii ioii iioi iiio"));
}

TEST(HighEntropyPassphraseTest, countValidPassphraseNoAnagram_solvePuzzleInputPartTwo) {
  HighEntrpyPassphrase solver;
  EXPECT_EQ(265, solver.countValidPassphraseNoAnagram(TestUtils::ReadInputFile(inputFilename)));
}
