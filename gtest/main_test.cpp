#include "gtest.h"
#include "task_test.cpp"
#include "cluster_test.cpp"

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
