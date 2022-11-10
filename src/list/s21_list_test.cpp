#include <list>

#include "gtest/gtest.h"
// refactor: cpp to h
#include "s21_list.cpp"

TEST(methods_to_modify, clear) {
  std::list<int> std_list;
  s21::list<int> list;

  //list.push_back(1);
  std_list.push_back(1);

  //  list.clear();
  std_list.clear();

  EXPECT_TRUE(std_list.empty());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}