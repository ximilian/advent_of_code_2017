#include "02_corruption_checksum.hpp"
#include "gtest/gtest.h"

TEST(TestCorruptionChecksum, check_emptyString) {
  EXPECT_EQ(0, CorruptionChecksum::check(""));
}

