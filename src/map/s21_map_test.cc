#include "s21_map.cc"

#include <map>

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
// 1) Красная вершина с 0 детьми
TEST(map_erase_tests, erase_1) {
  std::map<int, int> std_a;
  s21::map<int, int> s21_a;

  std_a.insert(std::pair<int, int>(1, 1));
  std_a.insert(std::pair<int, int>(2, 1));
  std_a.insert(std::pair<int, int>(3, 56));
  std_a.insert(std::pair<int, int>(4, 3));

  s21_a.insert(1, 1);
  s21_a.insert(2, 1);
  s21_a.insert(3, 56);
  s21_a.insert(4, 3);

  s21_a.erase(s21_a.find(std::pair<int, int>(3, 56)));
  std_a.erase(std_a.find(3));

  EXPECT_EQ(s21_a.empty(), std_a.empty());
  EXPECT_EQ(s21_a.size(), std_a.size());

  auto s21_itr = s21_a.begin();
  auto std_itr = std_a.begin();

  for (; std_itr != std_a.end(); ++std_itr, ++s21_itr) {
    EXPECT_EQ((*s21_itr).first, (*std_itr).first);
    EXPECT_EQ((*s21_itr).second, (*std_itr).second);
  }
}

// 3) Красная или черная вершина с 2 детьми
TEST(map_erase_tests, erase_3) {
  std::map<int, int> std_a;
  s21::map<int, int> s21_a;

  std_a.insert(std::pair<int, int>(1, 1));
  std_a.insert(std::pair<int, int>(2, 1));
  std_a.insert(std::pair<int, int>(3, 56));
  std_a.insert(std::pair<int, int>(4, 3));
  std_a.insert(std::pair<int, int>(5, 8));

  s21_a.insert(1, 1);
  s21_a.insert(2, 1);
  s21_a.insert(3, 56);
  s21_a.insert(4, 3);
  s21_a.insert(5, 8);

  s21_a.erase(s21_a.find(std::pair<int, int>(2, 1)));
  std_a.erase(std_a.find(2));

  EXPECT_EQ(s21_a.empty(), std_a.empty());
  EXPECT_EQ(s21_a.size(), std_a.size());

  auto s21_itr = s21_a.begin();
  auto std_itr = std_a.begin();

  for (; std_itr != std_a.end(); ++std_itr, ++s21_itr) {
    EXPECT_EQ((*s21_itr).first, (*std_itr).first);
    EXPECT_EQ((*s21_itr).second, (*std_itr).second);
  }
}

// 3) Красная или черная вершина с 2 детьми (корень)
TEST(map_erase_tests, erase_3_root) {
  std::map<int, int> std_a;
  s21::map<int, int> s21_a;

  std_a.insert(std::pair<int, int>(1, 1));
  std_a.insert(std::pair<int, int>(2, 1));
  std_a.insert(std::pair<int, int>(3, 56));
  std_a.insert(std::pair<int, int>(4, 3));
  std_a.insert(std::pair<int, int>(5, 8));

  s21_a.insert(1, 1);
  s21_a.insert(2, 1);
  s21_a.insert(3, 56);
  s21_a.insert(4, 3);
  s21_a.insert(5, 8);

  s21_a.erase(s21_a.find(std::pair<int, int>(4, 3)));
  std_a.erase(std_a.find(4));

  EXPECT_EQ(s21_a.empty(), std_a.empty());
  EXPECT_EQ(s21_a.size(), std_a.size());

  auto s21_itr = s21_a.begin();
  auto std_itr = std_a.begin();

  for (; std_itr != std_a.end(); ++std_itr, ++s21_itr) {
    EXPECT_EQ((*s21_itr).first, (*std_itr).first);
    EXPECT_EQ((*s21_itr).second, (*std_itr).second);
  }
}

// 4) Черная вершина с 1 ребенком
TEST(map_erase_tests, erase_4) {
  std::map<int, int> std_a;
  s21::map<int, int> s21_a;

  std_a.insert(std::pair<int, int>(1, 1));
  std_a.insert(std::pair<int, int>(2, 1));
  std_a.insert(std::pair<int, int>(3, 56));
  std_a.insert(std::pair<int, int>(4, 3));

  s21_a.insert(1, 1);
  s21_a.insert(2, 1);
  s21_a.insert(3, 56);
  s21_a.insert(4, 3);

  s21_a.erase(s21_a.find(std::pair<int, int>(4, 3)));
  std_a.erase(std_a.find(4));

  EXPECT_EQ(s21_a.empty(), std_a.empty());
  EXPECT_EQ(s21_a.size(), std_a.size());

  auto s21_itr = s21_a.begin();
  auto std_itr = std_a.begin();

  for (; std_itr != std_a.end(); ++std_itr, ++s21_itr) {
    EXPECT_EQ((*s21_itr).first, (*std_itr).first);
    EXPECT_EQ((*s21_itr).second, (*std_itr).second);
  }
}

// 5.1.1.б) Черная вершина с 0 детьми && Брат черный && Левый ребенок красный
// (правый -- черный)
TEST(map_erase_tests, erase_5_1_1_a) {
  std::map<int, int> std_a;
  s21::map<int, int> s21_a;

  std_a.insert(std::pair<int, int>(1, 1));
  std_a.insert(std::pair<int, int>(2, 1));
  std_a.insert(std::pair<int, int>(3, 56));
  std_a.insert(std::pair<int, int>(4, 3));

  s21_a.insert(1, 1);
  s21_a.insert(2, 1);
  s21_a.insert(3, 56);
  s21_a.insert(4, 3);

  s21_a.erase(s21_a.find(std::pair<int, int>(1, 1)));
  std_a.erase(std_a.find(1));

  EXPECT_EQ(s21_a.empty(), std_a.empty());
  EXPECT_EQ(s21_a.size(), std_a.size());

  auto s21_itr = s21_a.begin();
  auto std_itr = std_a.begin();

  for (; std_itr != std_a.end(); ++std_itr, ++s21_itr) {
    EXPECT_EQ((*s21_itr).first, (*std_itr).first);
    EXPECT_EQ((*s21_itr).second, (*std_itr).second);
  }
}

// 5.1.2) Черная вершина с 0 детьми && Брат черный && Оба ребенка брата - черные
TEST(map_erase_tests, erase_5_1_2) {
  std::map<int, int> std_a;
  s21::map<int, int> s21_a;

  std_a.insert(std::pair<int, int>(1, 1));
  std_a.insert(std::pair<int, int>(2, 1));
  std_a.insert(std::pair<int, int>(3, 56));
  std_a.insert(std::pair<int, int>(4, 3));
  std_a.insert(std::pair<int, int>(5, 8));
  std_a.insert(std::pair<int, int>(6, 8));
  std_a.insert(std::pair<int, int>(7, 67));
  std_a.insert(std::pair<int, int>(8, 7));

  s21_a.insert(1, 1);
  s21_a.insert(2, 1);
  s21_a.insert(3, 56);
  s21_a.insert(4, 3);
  s21_a.insert(5, 8);
  s21_a.insert(6, 8);
  s21_a.insert(7, 67);
  s21_a.insert(8, 7);

  s21_a.erase(s21_a.find(std::pair<int, int>(2, 1)));
  std_a.erase(std_a.find(2));

  EXPECT_EQ(s21_a.empty(), std_a.empty());
  EXPECT_EQ(s21_a.size(), std_a.size());

  auto s21_itr = s21_a.begin();
  auto std_itr = std_a.begin();

  for (; std_itr != std_a.end(); ++std_itr, ++s21_itr) {
    EXPECT_EQ((*s21_itr).first, (*std_itr).first);
    EXPECT_EQ((*s21_itr).second, (*std_itr).second);
  }
}

TEST(map_erase_tests, erase_5_1_2_) {
  std::map<int, int> std_a;
  s21::map<int, int> s21_a;

  std_a.insert(std::pair<int, int>(1, 1));
  std_a.insert(std::pair<int, int>(2, 1));
  std_a.insert(std::pair<int, int>(3, 56));

  s21_a.insert(1, 1);
  s21_a.insert(2, 1);
  s21_a.insert(3, 56);

  s21_a.erase(s21_a.find(std::pair<int, int>(1, 1)));
  std_a.erase(std_a.find(1));

  EXPECT_EQ(s21_a.empty(), std_a.empty());
  EXPECT_EQ(s21_a.size(), std_a.size());

  auto s21_itr = s21_a.begin();
  auto std_itr = std_a.begin();

  for (; std_itr != std_a.end(); ++std_itr, ++s21_itr) {
    EXPECT_EQ((*s21_itr).first, (*std_itr).first);
    EXPECT_EQ((*s21_itr).second, (*std_itr).second);
  }
}

// 5.2) Черная вершина с 0 детьми && Брат красный
TEST(map_erase_tests, erase_5_2) {
  std::map<int, int> std_a;
  s21::map<int, int> s21_a;

  std_a.insert(std::pair<int, int>(1, 1));
  std_a.insert(std::pair<int, int>(2, 1));
  std_a.insert(std::pair<int, int>(3, 56));
  std_a.insert(std::pair<int, int>(4, 3));
  std_a.insert(std::pair<int, int>(5, 8));

  s21_a.insert(1, 1);
  s21_a.insert(2, 1);
  s21_a.insert(3, 56);
  s21_a.insert(4, 3);
  s21_a.insert(5, 8);

  s21_a.erase(s21_a.find(std::pair<int, int>(5, 8)));
  std_a.erase(std_a.find(5));

  EXPECT_EQ(s21_a.empty(), std_a.empty());
  EXPECT_EQ(s21_a.size(), std_a.size());

  auto s21_itr = s21_a.begin();
  auto std_itr = std_a.begin();

  for (; std_itr != std_a.end(); ++std_itr, ++s21_itr) {
    EXPECT_EQ((*s21_itr).first, (*std_itr).first);
    EXPECT_EQ((*s21_itr).second, (*std_itr).second);
  }
}

TEST(map_constructor_suite, default_constructor) {
  std::map<int, int> std_a;
  s21::map<int, int> s21_a;

  EXPECT_EQ(s21_a.empty(), std_a.empty());
  EXPECT_EQ(s21_a.size(), std_a.size());
}

TEST(map_constructor_suite, insert_and_copy_constructor) {
  std::map<int, int> std_a;
  std_a.insert(std::pair<int, int>(1, 1));
  std_a.insert(std::pair<int, int>(2, 1));
  std_a.insert(std::pair<int, int>(3, 56));

  s21::map<int, int> s21_a;
  s21_a.insert(1, 1);
  s21_a.insert(2, 1);
  s21_a.insert(3, 56);

  std::map<int, int> std_b(std_a);
  s21::map<int, int> s21_b(s21_a);

  EXPECT_EQ(s21_b.empty(), std_b.empty());
  EXPECT_EQ(s21_b.size(), std_b.size());

  auto std_itr = std_b.begin();
  auto s21_itr = s21_b.begin();
  for (; std_itr != std_b.end(); ++std_itr, ++s21_itr) {
    EXPECT_EQ((*s21_itr).first, (*std_itr).first);
    EXPECT_EQ((*s21_itr).second, (*std_itr).second);
  }
}

TEST(map_constructor_suite, initializer_constructor) {
  std::map<int, int> std_a = {std::pair<int, int>(1, 1),
                              std::pair<int, int>(2, 2),
                              std::pair<int, int>(3, 3)};

  s21::map<int, int> s21_a = {std::pair<int, int>(1, 1),
                              std::pair<int, int>(2, 2),
                              std::pair<int, int>(3, 3)};

  EXPECT_EQ(s21_a.empty(), std_a.empty());
  EXPECT_EQ(s21_a.size(), std_a.size());

  auto std_itr = std_a.begin();
  auto s21_itr = s21_a.begin();
  for (; std_itr != std_a.end(); ++std_itr, ++s21_itr) {
    EXPECT_EQ((*s21_itr).first, (*std_itr).first);
    EXPECT_EQ((*s21_itr).second, (*std_itr).second);
  }
}

TEST(map_constructor_suite, move_constructor) {
  std::map<int, int> std_a = {std::pair<int, int>(1, 1),
                              std::pair<int, int>(2, 2),
                              std::pair<int, int>(3, 3)};

  s21::map<int, int> s21_a = {std::pair<int, int>(1, 1),
                              std::pair<int, int>(2, 2),
                              std::pair<int, int>(3, 3)};

  std::map<int, int> std_b(std::move(std_a));
  s21::map<int, int> s21_b(std::move(s21_a));

  EXPECT_EQ(s21_b.empty(), std_b.empty());
  EXPECT_EQ(s21_b.size(), std_b.size());

  auto std_itr = std_b.begin();
  auto s21_itr = s21_b.begin();
  for (; std_itr != std_b.end() && s21_itr != s21_b.end();
       ++std_itr, ++s21_itr) {
    EXPECT_EQ((*s21_itr).first, (*std_itr).first);
    EXPECT_EQ((*s21_itr).second, (*std_itr).second);
  }
}

TEST(map_constructor_suite, move_operator) {
  std::map<int, int> std_a = {std::pair<int, int>(1, 1),
                              std::pair<int, int>(2, 2),
                              std::pair<int, int>(3, 3)};

  s21::map<int, int> s21_a = {std::pair<int, int>(1, 1),
                              std::pair<int, int>(2, 2),
                              std::pair<int, int>(3, 3)};

  std::map<int, int> std_b = std::move(std_a);
  s21::map<int, int> s21_b = std::move(s21_a);

  EXPECT_EQ(s21_b.empty(), std_b.empty());
  EXPECT_EQ(s21_b.size(), std_b.size());

  auto std_itr = std_b.begin();
  auto s21_itr = s21_b.begin();
  for (; std_itr != std_b.end() && s21_itr != s21_b.end();
       ++std_itr, ++s21_itr) {
    EXPECT_EQ((*s21_itr).first, (*std_itr).first);
    EXPECT_EQ((*s21_itr).second, (*std_itr).second);
  }
}

TEST(map_iterators_suite, int_begin_end_iterators) {
  std::map<int, int> std_a = {std::pair<int, int>(1, 1),
                              std::pair<int, int>(2, 2),
                              std::pair<int, int>(3, 3)};
  s21::map<int, int> s21_a = {std::pair<int, int>(1, 1),
                              std::pair<int, int>(2, 2),
                              std::pair<int, int>(3, 3)};

  EXPECT_EQ((*s21_a.begin()).first, (*std_a.begin()).first);
  EXPECT_EQ((*s21_a.begin()).second, (*std_a.begin()).second);
}

TEST(map_edge_constructor_suite, initializer_constructor) {
  std::map<int, int> std_a = {};

  s21::map<int, int> s21_a = {};

  EXPECT_EQ(s21_a.empty(), std_a.empty());
  EXPECT_EQ(s21_a.size(), std_a.size());

  auto std_itr = std_a.begin();
  auto s21_itr = s21_a.begin();
  for (; std_itr != std_a.end() && s21_itr != s21_a.end();
       ++std_itr, ++s21_itr) {
    EXPECT_EQ((*s21_itr).first, (*std_itr).first);
    EXPECT_EQ((*s21_itr).second, (*std_itr).second);
  }
}

TEST(map_edge_constructor_suite, move_constructor) {
  std::map<int, int> std_a;

  s21::map<int, int> s21_a;

  std_a.insert(std::pair<int, int>(1, 1));
  std_a.insert(std::pair<int, int>(2, 1));
  std_a.insert(std::pair<int, int>(3, 56));
  std_a.insert(std::pair<int, int>(4, 3));
  std_a.insert(std::pair<int, int>(5, 8));
  std_a.insert(std::pair<int, int>(6, 8));
  std_a.insert(std::pair<int, int>(7, 67));
  std_a.insert(std::pair<int, int>(8, 7));
  std_a.insert(std::pair<int, int>(9, 9));
  std_a.insert(std::pair<int, int>(10, 11));

  s21_a.insert(1, 1);
  s21_a.insert(2, 1);
  s21_a.insert(3, 56);
  s21_a.insert(4, 3);
  s21_a.insert(5, 8);
  s21_a.insert(6, 8);
  s21_a.insert(7, 67);
  s21_a.insert(8, 7);
  s21_a.insert(9, 9);
  s21_a.insert(10, 11);

  std::map<int, int> std_b(std::move(std_a));
  s21::map<int, int> s21_b(std::move(s21_a));

  EXPECT_EQ(s21_b.empty(), std_b.empty());
  EXPECT_EQ(s21_b.size(), std_b.size());

  auto std_itr = std_b.begin();
  auto s21_itr = s21_b.begin();
  for (; std_itr != std_b.end() && s21_itr != s21_b.end();
       ++std_itr, ++s21_itr) {
    EXPECT_EQ((*s21_itr).first, (*std_itr).first);
    EXPECT_EQ((*s21_itr).second, (*std_itr).second);
  }
}

TEST(map_edge_constructor_suite, move_operator) {
  std::map<int, int> std_a = {};

  s21::map<int, int> s21_a = {};

  std::map<int, int> std_b = std::move(std_a);
  s21::map<int, int> s21_b = std::move(s21_a);

  EXPECT_EQ(s21_b.empty(), std_b.empty());
  EXPECT_EQ(s21_b.size(), std_b.size());

  auto std_itr = std_b.begin();
  auto s21_itr = s21_b.begin();
  for (; std_itr != std_b.end() && s21_itr != s21_b.end();
       ++std_itr, ++s21_itr) {
    EXPECT_EQ((*s21_itr).first, (*std_itr).first);
    EXPECT_EQ((*s21_itr).second, (*std_itr).second);
  }
}

TEST(map_modifiers_suite, clear_1) {
  std::map<int, int> std_a = {
      std::pair<int, int>(1, 1), std::pair<int, int>(2, 2),
      std::pair<int, int>(3, 3), std::pair<int, int>(4, 4),
      std::pair<int, int>(5, 5)};
  s21::map<int, int> s21_a = {
      std::pair<int, int>(1, 1), std::pair<int, int>(2, 2),
      std::pair<int, int>(3, 3), std::pair<int, int>(4, 4),
      std::pair<int, int>(5, 5)};

  std_a.clear();
  s21_a.clear();

  EXPECT_EQ(s21_a.empty(), std_a.empty());
  EXPECT_EQ(s21_a.size(), std_a.size());
}

TEST(map_modifiers_suite, clear_2) {
  std::map<int, int> std_a;
  s21::map<int, int> s21_a;

  std_a.clear();
  s21_a.clear();

  EXPECT_EQ(s21_a.empty(), std_a.empty());
  EXPECT_EQ(s21_a.size(), std_a.size());
}

TEST(map_modifiers_suite, insert) {
  std::map<int, int> std_a;
  s21::map<int, int> s21_a;

  std_a.insert(std::pair<int, int>(1, 1));
  std_a.insert(std::pair<int, int>(2, 1));
  std_a.insert(std::pair<int, int>(3, 56));
  std_a.insert(std::pair<int, int>(4, 3));
  std_a.insert(std::pair<int, int>(5, 8));
  std_a.insert(std::pair<int, int>(6, 8));
  std_a.insert(std::pair<int, int>(7, 67));
  std_a.insert(std::pair<int, int>(8, 7));
  std_a.insert(std::pair<int, int>(9, 9));
  std_a.insert(std::pair<int, int>(10, 11));

  s21_a.insert(1, 1);
  s21_a.insert(2, 1);
  s21_a.insert(3, 56);
  s21_a.insert(4, 3);
  s21_a.insert(5, 8);
  s21_a.insert(6, 8);
  s21_a.insert(7, 67);
  s21_a.insert(8, 7);
  s21_a.insert(9, 9);
  s21_a.insert(10, 11);

  auto std_itr = std_a.begin();
  auto s21_itr = s21_a.begin();
  for (; std_itr != std_a.end() && s21_itr != s21_a.end();
       ++std_itr, ++s21_itr) {
    EXPECT_EQ((*s21_itr).first, (*std_itr).first);
    EXPECT_EQ((*s21_itr).second, (*std_itr).second);
  }
}

TEST(map_modifiers_suite, swap) {
  s21::map<int, int> s21_a = {
      std::pair<int, int>(1, 1), std::pair<int, int>(2, 2),
      std::pair<int, int>(3, 3), std::pair<int, int>(4, 4),
      std::pair<int, int>(5, 5)};
  s21::map<int, int> s21_b = {
      std::pair<int, int>(11, 11), std::pair<int, int>(22, 22),
      std::pair<int, int>(33, 33), std::pair<int, int>(44, 44),
      std::pair<int, int>(55, 55)};

  s21::map<int, int> s21_b_swapped = {
      std::pair<int, int>(1, 1), std::pair<int, int>(2, 2),
      std::pair<int, int>(3, 3), std::pair<int, int>(4, 4),
      std::pair<int, int>(5, 5)};
  s21::map<int, int> s21_a_swapped = {
      std::pair<int, int>(11, 11), std::pair<int, int>(22, 22),
      std::pair<int, int>(33, 33), std::pair<int, int>(44, 44),
      std::pair<int, int>(55, 55)};

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

TEST(map_modifiers_suite, merge) {
  s21::map<int, int> s21_a = {
      std::pair<int, int>(1, 1), std::pair<int, int>(2, 2),
      std::pair<int, int>(3, 3), std::pair<int, int>(4, 4),
      std::pair<int, int>(5, 5)};
  s21::map<int, int> s21_b = {
      std::pair<int, int>(1, 1),   std::pair<int, int>(2, 2),
      std::pair<int, int>(3, 3),   std::pair<int, int>(4, 4),
      std::pair<int, int>(5, 5),   std::pair<int, int>(11, 11),
      std::pair<int, int>(22, 22), std::pair<int, int>(33, 33),
      std::pair<int, int>(44, 44), std::pair<int, int>(55, 55)};

  s21::map<int, int> s21_result = {
      std::pair<int, int>(1, 1),   std::pair<int, int>(2, 2),
      std::pair<int, int>(3, 3),   std::pair<int, int>(4, 4),
      std::pair<int, int>(5, 5),   std::pair<int, int>(11, 11),
      std::pair<int, int>(22, 22), std::pair<int, int>(33, 33),
      std::pair<int, int>(44, 44), std::pair<int, int>(55, 55)};

  s21_a.merge(s21_b);
  auto s21_a_itr = s21_a.begin();
  auto s21_result_itr = s21_result.begin();
  for (; s21_a_itr != s21_a.end(); ++s21_a_itr, ++s21_result_itr) {
    EXPECT_EQ(*s21_a_itr, *s21_result_itr);
  }
}

TEST(map_modifiers_suite, merge_empty) {
  s21::map<int, int> s21_a = {
      std::pair<int, int>(1, 1), std::pair<int, int>(2, 2),
      std::pair<int, int>(3, 3), std::pair<int, int>(4, 4),
      std::pair<int, int>(5, 5)};
  s21::map<int, int> s21_b;
  s21::map<int, int> s21_result = {
      std::pair<int, int>(1, 1), std::pair<int, int>(2, 2),
      std::pair<int, int>(3, 3), std::pair<int, int>(4, 4),
      std::pair<int, int>(5, 5)};

  s21_a.merge(s21_b);
  auto s21_a_itr = s21_a.begin();
  auto s21_result_itr = s21_result.begin();
  for (; s21_a_itr != s21_a.end(); ++s21_a_itr, ++s21_result_itr) {
    EXPECT_EQ(*s21_a_itr, *s21_result_itr);
  }
}

TEST(map_modifiers_suite, merge_both_empty) {
  s21::map<int, int> s21_a;
  s21::map<int, int> s21_b;
  s21::map<int, int> s21_result;

  s21_a.merge(s21_b);
  auto s21_a_itr = s21_a.begin();
  auto s21_result_itr = s21_result.begin();
  for (; s21_a_itr != s21_a.end(); ++s21_a_itr, ++s21_result_itr) {
    EXPECT_EQ(*s21_a_itr, *s21_result_itr);
  }
}

TEST(map_lookup_suite, contains) {
  s21::map<int, int> s21_a = {
      std::pair<int, int>(1, 1), std::pair<int, int>(2, 2),
      std::pair<int, int>(3, 3), std::pair<int, int>(4, 4),
      std::pair<int, int>(5, 5)};

  EXPECT_TRUE(s21_a.contains(std::pair<int, int>(1, 1)));
  EXPECT_TRUE(s21_a.contains(std::pair<int, int>(2, 2)));
  EXPECT_TRUE(s21_a.contains(std::pair<int, int>(3, 3)));
  EXPECT_TRUE(s21_a.contains(std::pair<int, int>(4, 4)));
  EXPECT_TRUE(s21_a.contains(std::pair<int, int>(5, 5)));

  EXPECT_FALSE(s21_a.contains(std::pair<int, int>(0, 0)));
  EXPECT_FALSE(s21_a.contains(std::pair<int, int>(77, 77)));
  EXPECT_FALSE(s21_a.contains(std::pair<int, int>(123, 123)));
}

TEST(map_element_access, braces_and_at) {
  s21::map<int, int> s21_a;
  std::map<int, int> std_a;

  s21_a.insert_or_assign(1, 1);
  s21_a.insert_or_assign(2, 1);
  s21_a.insert_or_assign(1, 11);
  s21_a.insert_or_assign(2, 22);
  s21_a.insert_or_assign(3, 1);

  std_a.insert_or_assign(1, 1);
  std_a.insert_or_assign(2, 1);
  std_a.insert_or_assign(1, 11);
  std_a.insert_or_assign(2, 22);
  std_a.insert_or_assign(3, 1);

  EXPECT_EQ(s21_a.empty(), std_a.empty());
  EXPECT_EQ(s21_a.size(), std_a.size());

  auto std_itr = std_a.begin();
  auto s21_itr = s21_a.begin();
  for (; std_itr != std_a.end(); ++std_itr, ++s21_itr) {
    EXPECT_EQ((*s21_itr).first, (*std_itr).first);
    EXPECT_EQ((*s21_itr).second, (*std_itr).second);
  }
}

TEST(map_modifiers_insert, insert_or_assign) {
  s21::map<int, int> s21_a;
  std::map<int, int> std_a;

  std_a.insert(std::pair<int, int>(1, 1));
  std_a.insert(std::pair<int, int>(2, 1));
  std_a.insert(std::pair<int, int>(3, 56));
  std_a.insert(std::pair<int, int>(4, 3));
  std_a.insert(std::pair<int, int>(5, 8));
  std_a.insert(std::pair<int, int>(6, 8));
  std_a.insert(std::pair<int, int>(7, 67));
  std_a.insert(std::pair<int, int>(8, 7));
  std_a.insert(std::pair<int, int>(9, 9));
  std_a.insert(std::pair<int, int>(10, 11));

  s21_a.insert(1, 1);
  s21_a.insert(2, 1);
  s21_a.insert(3, 56);
  s21_a.insert(4, 3);
  s21_a.insert(5, 8);
  s21_a.insert(6, 8);
  s21_a.insert(7, 67);
  s21_a.insert(8, 7);
  s21_a.insert(9, 9);
  s21_a.insert(10, 11);

  EXPECT_EQ(s21_a.empty(), std_a.empty());
  EXPECT_EQ(s21_a.size(), std_a.size());

  auto std_itr = std_a.begin();
  auto s21_itr = s21_a.begin();

  for (int i = 1; std_itr != std_a.end(); ++std_itr, ++s21_itr, ++i) {
    EXPECT_EQ(s21_a.at(i), std_a.at(i));
    EXPECT_EQ(s21_a[i], std_a[i]);

    EXPECT_EQ((*s21_itr).first, (*std_itr).first);
    EXPECT_EQ((*s21_itr).second, (*std_itr).second);
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
