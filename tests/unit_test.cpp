#include "gtest/gtest.h"
#include "snakeAlgTest.h"
#include "imageAlgTest.h"
#include "pineappleAlgTest.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
