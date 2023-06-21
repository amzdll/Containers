#include "s21_set.cc"

#include <set>

#include "gtest/gtest.h"

/*
 * REMOVAL TESTS:
 * 1) Red top with 0 children
 * X 2) Red top with 1 child - impossible case
 * 3) Red or black top with 2 children
 * 4) Black top with 1 child
 * 5) Black top with 0 children
 * 5.1) Brother Black
 * 5.1.1) At least one child of the brother is red
 * X 5.1.1.a) The right child is red (left -- any) is an impossible case
 * 5.1.1.b) Left child red (right -- black)
 * 5.1.2) Both brother's children are black
 * 5.2) The brother is red
 */

// ERASE TESTS
// 1) Red top with 0 children
TEST(set_erase_tests, erase_1) {
  std::set<int> std_a;
  s21::set<int> s21_a;

  std_a.insert(1);
  std_a.insert(2);
  std_a.insert(3);
  std_a.insert(4);

  s21_a.insert(1);
  s21_a.insert(2);
  s21_a.insert(3);
  s21_a.insert(4);

  s21_a.erase(s21_a.find(3));
  std_a.erase(std_a.find(3));

  EXPECT_EQ(s21_a.empty(), std_a.empty());
  EXPECT_EQ(s21_a.size(), std_a.size());

  auto s21_itr = s21_a.begin();
  auto std_itr = std_a.begin();

  for (; std_itr != std_a.end(); ++std_itr, ++s21_itr) {
    EXPECT_EQ(*s21_itr, *std_itr);
  }
}

// 3) Red or black top with 2 children
TEST(set_erase_tests, erase_3) {
  std::set<int> std_a;
  s21::set<int> s21_a;

  std_a.insert(1);
  std_a.insert(2);
  std_a.insert(3);
  std_a.insert(4);
  std_a.insert(5);

  s21_a.insert(1);
  s21_a.insert(2);
  s21_a.insert(3);
  s21_a.insert(4);
  s21_a.insert(5);

  s21_a.erase(s21_a.find(2));
  std_a.erase(std_a.find(2));

  EXPECT_EQ(s21_a.empty(), std_a.empty());
  EXPECT_EQ(s21_a.size(), std_a.size());

  auto s21_itr = s21_a.begin();
  auto std_itr = std_a.begin();

  for (; std_itr != std_a.end(); ++std_itr, ++s21_itr) {
    EXPECT_EQ(*s21_itr, *std_itr);
  }
}

// 3) Red or black top with 2 children (root)
TEST(set_erase_tests, erase_3_root) {
  std::set<int> std_a;
  s21::set<int> s21_a;

  std_a.insert(1);
  std_a.insert(2);
  std_a.insert(3);
  std_a.insert(4);
  std_a.insert(5);

  s21_a.insert(1);
  s21_a.insert(2);
  s21_a.insert(3);
  s21_a.insert(4);
  s21_a.insert(5);

  s21_a.erase(s21_a.find(4));
  std_a.erase(std_a.find(4));

  EXPECT_EQ(s21_a.empty(), std_a.empty());
  EXPECT_EQ(s21_a.size(), std_a.size());

  auto s21_itr = s21_a.begin();
  auto std_itr = std_a.begin();

  for (; std_itr != std_a.end(); ++std_itr, ++s21_itr) {
    EXPECT_EQ(*s21_itr, *std_itr);
  }
}

// 4) Black top with 1 child
TEST(set_erase_tests, erase_4) {
  std::set<int> std_a;
  s21::set<int> s21_a;

  std_a.insert(1);
  std_a.insert(2);
  std_a.insert(3);
  std_a.insert(4);

  s21_a.insert(1);
  s21_a.insert(2);
  s21_a.insert(3);
  s21_a.insert(4);

  s21_a.erase(s21_a.find(4));
  std_a.erase(std_a.find(4));

  EXPECT_EQ(s21_a.empty(), std_a.empty());
  EXPECT_EQ(s21_a.size(), std_a.size());

  auto s21_itr = s21_a.begin();
  auto std_itr = std_a.begin();

  for (; std_itr != std_a.end(); ++std_itr, ++s21_itr) {
    EXPECT_EQ(*s21_itr, *std_itr);
  }
}

// 5.1.1.b) Black top with 0 children && Brother Black && Left child red
// (right -- black)
TEST(set_erase_tests, erase_5_1_1_a) {
  std::set<int> std_a;
  s21::set<int> s21_a;

  std_a.insert(1);
  std_a.insert(2);
  std_a.insert(3);
  std_a.insert(4);

  s21_a.insert(1);
  s21_a.insert(2);
  s21_a.insert(3);
  s21_a.insert(4);

  s21_a.erase(s21_a.find(1));
  std_a.erase(std_a.find(1));

  EXPECT_EQ(s21_a.empty(), std_a.empty());
  EXPECT_EQ(s21_a.size(), std_a.size());

  auto s21_itr = s21_a.begin();
  auto std_itr = std_a.begin();

  for (; std_itr != std_a.end(); ++std_itr, ++s21_itr) {
    EXPECT_EQ(*s21_itr, *std_itr);
  }
}

// 5.1.2) Black top with 0 children && Brother Black && Both brother's children
// are black
TEST(set_erase_tests, erase_5_1_2) {
  std::set<int> std_a;
  s21::set<int> s21_a;

  std_a.insert(1);
  std_a.insert(2);
  std_a.insert(3);
  std_a.insert(4);
  std_a.insert(5);
  std_a.insert(6);
  std_a.insert(7);
  std_a.insert(8);

  s21_a.insert(1);
  s21_a.insert(2);
  s21_a.insert(3);
  s21_a.insert(4);
  s21_a.insert(5);
  s21_a.insert(6);
  s21_a.insert(7);
  s21_a.insert(8);

  s21_a.erase(s21_a.find(2));
  std_a.erase(std_a.find(2));

  EXPECT_EQ(s21_a.empty(), std_a.empty());
  EXPECT_EQ(s21_a.size(), std_a.size());

  auto s21_itr = s21_a.begin();
  auto std_itr = std_a.begin();

  for (; std_itr != std_a.end(); ++std_itr, ++s21_itr) {
    EXPECT_EQ(*s21_itr, *std_itr);
  }
}

TEST(set_erase_tests, erase_5_1_2_) {
  std::set<int> std_a;
  s21::set<int> s21_a;

  std_a.insert(1);
  std_a.insert(2);
  std_a.insert(3);

  s21_a.insert(1);
  s21_a.insert(2);
  s21_a.insert(3);

  s21_a.erase(s21_a.find(1));
  std_a.erase(std_a.find(1));

  EXPECT_EQ(s21_a.empty(), std_a.empty());
  EXPECT_EQ(s21_a.size(), std_a.size());

  auto s21_itr = s21_a.begin();
  auto std_itr = std_a.begin();

  for (; std_itr != std_a.end(); ++std_itr, ++s21_itr) {
    EXPECT_EQ(*s21_itr, *std_itr);
  }
}

// 5.2) Black top with 0 children && The brother is red
TEST(set_erase_tests, erase_5_2) {
  std::set<int> std_a;
  s21::set<int> s21_a;

  std_a.insert(1);
  std_a.insert(2);
  std_a.insert(3);
  std_a.insert(4);
  std_a.insert(5);

  s21_a.insert(1);
  s21_a.insert(2);
  s21_a.insert(3);
  s21_a.insert(4);
  s21_a.insert(5);

  s21_a.erase(s21_a.find(5));
  std_a.erase(std_a.find(5));

  EXPECT_EQ(s21_a.empty(), std_a.empty());
  EXPECT_EQ(s21_a.size(), std_a.size());

  auto s21_itr = s21_a.begin();
  auto std_itr = std_a.begin();

  for (; std_itr != std_a.end(); ++std_itr, ++s21_itr) {
    EXPECT_EQ(*s21_itr, *std_itr);
  }
}

TEST(set_constructor_suite, default_constructor) {
  std::set<int> std_a;
  s21::set<int> s21_a;

  EXPECT_EQ(s21_a.empty(), std_a.empty());
  EXPECT_EQ(s21_a.size(), std_a.size());
}

TEST(set_constructor_suite, insert_and_copy_constructor) {
  std::set<int> std_a;
  std_a.insert(1);
  std_a.insert(2);
  std_a.insert(3);

  s21::set<int> s21_a;
  s21_a.insert(1);
  s21_a.insert(2);
  s21_a.insert(3);

  std::set<int> std_b(std_a);
  s21::set<int> s21_b(s21_a);

  EXPECT_EQ(s21_b.empty(), std_b.empty());
  EXPECT_EQ(s21_b.size(), std_b.size());

  auto std_itr = std_b.begin();
  auto s21_itr = s21_b.begin();
  for (; std_itr != std_b.end(); ++std_itr, ++s21_itr) {
    EXPECT_EQ(*s21_itr, *std_itr);
  }
}

TEST(set_constructor_suite, initializer_constructor) {
  std::set<int> std_a = {1, 2, 3};

  s21::set<int> s21_a = {1, 2, 3};

  EXPECT_EQ(s21_a.empty(), std_a.empty());
  EXPECT_EQ(s21_a.size(), std_a.size());

  auto std_itr = std_a.begin();
  auto s21_itr = s21_a.begin();
  for (; std_itr != std_a.end(); ++std_itr, ++s21_itr) {
    EXPECT_EQ(*s21_itr, *std_itr);
  }
}

TEST(set_constructor_suite, move_constructor) {
  std::set<int> std_a = {1, 2, 3};

  s21::set<int> s21_a = {1, 2, 3};

  std::set<int> std_b(std::move(std_a));
  s21::set<int> s21_b(std::move(s21_a));

  EXPECT_EQ(s21_b.empty(), std_b.empty());
  EXPECT_EQ(s21_b.size(), std_b.size());

  auto std_itr = std_b.begin();
  auto s21_itr = s21_b.begin();
  for (; std_itr != std_b.end() && s21_itr != s21_b.end();
       ++std_itr, ++s21_itr) {
    EXPECT_EQ(*s21_itr, *std_itr);
  }
}

TEST(set_constructor_suite, move_operator) {
  std::set<int> std_a = {1, 2, 3};

  s21::set<int> s21_a = {1, 2, 3};

  std::set<int> std_b = std::move(std_a);
  s21::set<int> s21_b = std::move(s21_a);

  EXPECT_EQ(s21_b.empty(), std_b.empty());
  EXPECT_EQ(s21_b.size(), std_b.size());

  auto std_itr = std_b.begin();
  auto s21_itr = s21_b.begin();
  for (; std_itr != std_b.end() && s21_itr != s21_b.end();
       ++std_itr, ++s21_itr) {
    EXPECT_EQ(*s21_itr, *std_itr);
  }
}

TEST(set_iterators_suite, int_begin_end_iterators) {
  std::set<int> std_a = {1, 2, 3};
  s21::set<int> s21_a = {1, 2, 3};

  EXPECT_EQ(*s21_a.begin(), *std_a.begin());
}

TEST(set_edge_constructor_suite, initializer_constructor) {
  std::set<int> std_a = {};

  s21::set<int> s21_a = {};

  EXPECT_EQ(s21_a.empty(), std_a.empty());
  EXPECT_EQ(s21_a.size(), std_a.size());

  auto std_itr = std_a.begin();
  auto s21_itr = s21_a.begin();
  for (; std_itr != std_a.end() && s21_itr != s21_a.end();
       ++std_itr, ++s21_itr) {
    EXPECT_EQ(*s21_itr, *std_itr);
  }
}

TEST(set_edge_constructor_suite, move_constructor) {
  std::set<int> std_a = {};

  s21::set<int> s21_a = {};

  std::set<int> std_b(std::move(std_a));
  s21::set<int> s21_b(std::move(s21_a));

  EXPECT_EQ(s21_b.empty(), std_b.empty());
  EXPECT_EQ(s21_b.size(), std_b.size());

  auto std_itr = std_b.begin();
  auto s21_itr = s21_b.begin();
  for (; std_itr != std_b.end() && s21_itr != s21_b.end();
       ++std_itr, ++s21_itr) {
    EXPECT_EQ(*s21_itr, *std_itr);
  }
}

TEST(set_edge_constructor_suite, move_operator) {
  std::set<int> std_a = {};

  s21::set<int> s21_a = {};

  std::set<int> std_b = std::move(std_a);
  s21::set<int> s21_b = std::move(s21_a);

  EXPECT_EQ(s21_b.empty(), std_b.empty());
  EXPECT_EQ(s21_b.size(), std_b.size());

  auto std_itr = std_b.begin();
  auto s21_itr = s21_b.begin();
  for (; std_itr != std_b.end() && s21_itr != s21_b.end();
       ++std_itr, ++s21_itr) {
    EXPECT_EQ(*s21_itr, *std_itr);
  }
}

TEST(set_modifiers_suite, clear_1) {
  std::set<int> std_a = {1, 2, 3, 4, 5};
  s21::set<int> s21_a = {1, 2, 3, 4, 5};

  std_a.clear();
  s21_a.clear();

  EXPECT_EQ(s21_a.empty(), std_a.empty());
  EXPECT_EQ(s21_a.size(), std_a.size());
}

TEST(set_modifiers_suite, clear_2) {
  std::set<int> std_a;
  s21::set<int> s21_a;

  std_a.clear();
  s21_a.clear();

  EXPECT_EQ(s21_a.empty(), std_a.empty());
  EXPECT_EQ(s21_a.size(), std_a.size());
}

TEST(set_modifiers_suite, insert) {
  std::set<int> std_a;
  s21::set<int> s21_a;

  std_a.insert(1);
  std_a.insert(2);
  std_a.insert(3);
  std_a.insert(4);
  std_a.insert(5);
  std_a.insert(6);
  std_a.insert(7);
  std_a.insert(8);
  std_a.insert(9);
  std_a.insert(10);

  s21_a.insert(1);
  s21_a.insert(2);
  s21_a.insert(3);
  s21_a.insert(4);
  s21_a.insert(5);
  s21_a.insert(6);
  s21_a.insert(7);
  s21_a.insert(8);
  s21_a.insert(9);
  s21_a.insert(10);

  auto std_itr = std_a.begin();
  auto s21_itr = s21_a.begin();
  for (; std_itr != std_a.end() && s21_itr != s21_a.end();
       ++std_itr, ++s21_itr) {
    EXPECT_EQ(*s21_itr, *std_itr);
  }
}

TEST(set_modifiers_suite, swap) {
  s21::set<int> s21_a = {1, 2, 3, 4, 5};
  s21::set<int> s21_b = {11, 22, 33, 44, 55};

  s21::set<int> s21_b_swapped = {1, 2, 3, 4, 5};
  s21::set<int> s21_a_swapped = {11, 22, 33, 44, 55};

  s21_a.swap(s21_b);
  auto s21_a_itr = s21_a.begin();
  auto s21_a_swapped_itr = s21_a_swapped.begin();
  for (; s21_a_itr != s21_a.end(); ++s21_a_itr, ++s21_a_swapped_itr) {
    EXPECT_EQ(*s21_a_itr, *s21_a_swapped_itr);
  }

  auto s21_b_itr = s21_b.begin();
  auto s21_b_swapped_itr = s21_b_swapped.begin();
  for (; s21_b_itr != s21_b.end(); ++s21_b_itr, ++s21_b_swapped_itr) {
    EXPECT_EQ(*s21_b_itr, *s21_b_swapped_itr);
  }
}

TEST(set_modifiers_suite, merge) {
  s21::set<int> s21_a = {1, 2, 3, 4, 5};
  s21::set<int> s21_b = {11, 22, 33, 44, 55};

  s21::set<int> s21_result = {1, 2, 3, 4, 5, 11, 22, 33, 44, 55};

  s21_a.merge(s21_b);
  auto s21_a_itr = s21_a.begin();
  auto s21_result_itr = s21_result.begin();
  for (; s21_a_itr != s21_a.end(); ++s21_a_itr, ++s21_result_itr) {
    EXPECT_EQ(*s21_a_itr, *s21_result_itr);
  }
}

TEST(set_lookup_suite, find) {
  s21::set<int> s21_a = {1, 2, 3, 4, 5};
  auto s21_itr_begin = s21_a.begin();
  auto s21_itr_begin_find = s21_a.find(1);

  EXPECT_TRUE(s21_itr_begin == s21_itr_begin_find);
}

TEST(set_lookup_suite, find_false) {
  s21::set<int> s21_a = {1, 2, 3, 4, 5};
  auto s21_itr_end = s21_a.end();
  auto s21_itr_end_find = s21_a.find(10);

  EXPECT_TRUE(s21_itr_end == s21_itr_end_find);
}

TEST(set_lookup_suite, contains) {
  s21::set<int> s21_a = {1, 2, 3, 4, 5};
  EXPECT_TRUE(s21_a.contains(1));
  EXPECT_TRUE(s21_a.contains(2));
  EXPECT_TRUE(s21_a.contains(3));
  EXPECT_TRUE(s21_a.contains(4));
  EXPECT_TRUE(s21_a.contains(5));

  EXPECT_FALSE(s21_a.contains(0));
  EXPECT_FALSE(s21_a.contains(6));
  EXPECT_FALSE(s21_a.contains(123));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
