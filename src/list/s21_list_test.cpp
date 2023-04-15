#include <list>

#include "gtest/gtest.h"
// refactor: cpp to h
#include "s21_list.cpp"

// block: CONSTRUCTORS
TEST(default_constructor_suite, int_true_test) {
  s21::list<int> s21_a;
  std::list<int> std_a;

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
}

TEST(default_constructor_suite, double_true_test) {
  s21::list<double> s21_a;
  std::list<double> std_a;

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
}

TEST(default_constructor_suite, float_true_test) {
  s21::list<float> s21_a;
  std::list<float> std_a;

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
}

TEST(default_constructor_suite, struct_true_test) {
  struct test_struct {
    int a;
    double b;
    float c;
  };

  s21::list<test_struct> s21_a;
  std::list<test_struct> std_a;

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
}

TEST(parameterized_constructor_suite, int_true_test) {
  s21::list<int> s21_a(5);
  std::list<int> std_a(5);

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
}

TEST(parameterized_constructor_suite, double_true_test) {
  s21::list<double> s21_a(5);
  std::list<double> std_a(5);

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
}

TEST(parameterized_constructor_suite, float_true_test) {
  s21::list<float> s21_a(5);
  std::list<float> std_a(5);

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
}

TEST(parameterized_constructor_suite, struct_true_test) {
  struct test_struct {
    int a;
    double b;
    float c;
  };

  s21::list<test_struct> s21_a(5);
  std::list<test_struct> std_a(5);

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
}

TEST(initializer_constructor_suite, int_true_test) {
  s21::list<int> s21_a({1, 2, 3, 4, 5});
  std::list<int> std_a({1, 2, 3, 4, 5});

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
}

TEST(initializer_constructor_suite, double_true_test) {
  s21::list<double> s21_a({1, 2, 3, 4, 5});
  std::list<double> std_a({1, 2, 3, 4, 5});

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
}

TEST(initializer_constructor_suite, float_true_test) {
  s21::list<float> s21_a({1, 2, 3, 4, 5});
  std::list<float> std_a({1, 2, 3, 4, 5});

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
}

TEST(initializer_constructor_suite, struct_true_test) {
  struct test_struct {
    int a;
    double b;
    float c;
  };
  test_struct a{}, b{}, c{}, d{}, e{};
  s21::list<test_struct> s21_a({a, b, c, d, e});
  std::list<test_struct> std_a({a, b, c, d, e});

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
}

TEST(copy_constructor_suite, int_true_test) {
  s21::list<int> s21_b(5);
  s21::list<int> s21_a(s21_b);
  std::list<int> std_b(5);
  std::list<int> std_a(std_b);

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());

  EXPECT_TRUE(s21_b.empty() == std_b.empty());
  EXPECT_TRUE(s21_b.size() == std_b.size());
}

TEST(copy_constructor_suite, double_true_test) {
  s21::list<double> s21_b(5);
  s21::list<double> s21_a(s21_b);
  std::list<double> std_b(5);
  std::list<double> std_a(std_b);

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());

  EXPECT_TRUE(s21_b.empty() == std_b.empty());
  EXPECT_TRUE(s21_b.size() == std_b.size());
}

TEST(copy_constructor_suite, float_true_test) {
  s21::list<float> s21_b(5);
  s21::list<float> s21_a(s21_b);
  std::list<float> std_b(5);
  std::list<float> std_a(std_b);

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());

  EXPECT_TRUE(s21_b.empty() == std_b.empty());
  EXPECT_TRUE(s21_b.size() == std_b.size());
}

TEST(copy_constructor_suite, struct_true_test) {
  struct test_struct {
    int a;
    double b;
    float c;
  };

  s21::list<test_struct> s21_b(5);
  s21::list<test_struct> s21_a(s21_b);
  std::list<test_struct> std_b(5);
  std::list<test_struct> std_a(std_b);

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_b.empty() == std_b.empty());
  EXPECT_TRUE(s21_b.size() == std_b.size());
}

TEST(move_constructor_suite, int_true_test) {
  s21::list<int> s21_a({1, 2, 3});
  s21::list<int> s21_b(std::move(s21_a));
  std::list<int> std_a({1, 2, 3});
  std::list<int> std_b(std::move(std_a));

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_b.empty() == std_b.empty());
  EXPECT_TRUE(s21_b.size() == std_b.size());
}

TEST(move_constructor_suite, double_true_test) {
  s21::list<double> s21_a({1, 2, 3});
  s21::list<double> s21_b(std::move(s21_a));
  std::list<double> std_a({1, 2, 3});
  std::list<double> std_b(std::move(std_a));

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_b.empty() == std_b.empty());
  EXPECT_TRUE(s21_b.size() == std_b.size());
}

TEST(move_constructor_suite, flaot_true_test) {
  s21::list<float> s21_a({1, 2, 3});
  s21::list<float> s21_b(std::move(s21_a));
  std::list<float> std_a({1, 2, 3});
  std::list<float> std_b(std::move(std_a));

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_b.empty() == std_b.empty());
  EXPECT_TRUE(s21_b.size() == std_b.size());
}

TEST(move_constructor_suite, struct_true_test) {
  struct test_struct {
    int a;
    double b;
    float c;
  };
  test_struct a{}, b{}, c{}, d{}, e{};
  s21::list<test_struct> s21_a({a, b, c, d, e});
  s21::list<test_struct> s21_b(std::move(s21_a));
  std::list<test_struct> std_a({a, b, c, d, e});
  std::list<test_struct> std_b(std::move(std_a));

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_b.empty() == std_b.empty());
  EXPECT_TRUE(s21_b.size() == std_b.size());
}

TEST(move_operator_constructor_suite, int_true_test) {
  s21::list<int> s21_a({1, 2, 3});
  s21::list<int> s21_b = s21_a;
  std::list<int> std_a({1, 2, 3});
  std::list<int> std_b = std_a;

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_b.empty() == std_b.empty());
  EXPECT_TRUE(s21_b.size() == std_b.size());
}

TEST(move_operator_constructor_suite, double_true_test) {
  s21::list<double> s21_a({1, 2, 3});
  s21::list<double> s21_b = s21_a;
  std::list<double> std_a({1, 2, 3});
  std::list<double> std_b = std_a;

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_b.empty() == std_b.empty());
  EXPECT_TRUE(s21_b.size() == std_b.size());
}

TEST(move_operator_constructor_suite, flaot_true_test) {
  s21::list<float> s21_a({1, 2, 3});
  s21::list<float> s21_b = s21_a;
  std::list<float> std_a({1, 2, 3});
  std::list<float> std_b = std_a;

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_b.empty() == std_b.empty());
  EXPECT_TRUE(s21_b.size() == std_b.size());
}

TEST(move_operator_constructor_suite, struct_true_test) {
  struct test_struct {
    int a;
    double b;
    float c;
  };
  test_struct a{}, b{}, c{}, d{}, e{};
  s21::list<test_struct> s21_a({a, b, c, d, e});
  s21::list<test_struct> s21_b = s21_a;
  std::list<test_struct> std_a({a, b, c, d, e});
  std::list<test_struct> std_b = std_a;

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_b.empty() == std_b.empty());
  EXPECT_TRUE(s21_b.size() == std_b.size());
}

// BLOCK: ELEMENT ACCESS
TEST(front_suite, true_test) {
  s21::list<int> s21_a({1, 2, 3, 4, 5});
  std::list<int> std_a({1, 2, 3, 4, 5});

  EXPECT_TRUE(s21_a.front() == std_a.front());
}

TEST(front_suite, pop_test) {
  s21::list<int> s21_a({1, 2, 3, 4, 5});
  std::list<int> std_a({1, 2, 3, 4, 5});

  s21_a.pop_front();
  std_a.pop_front();

  EXPECT_TRUE(s21_a.front() == std_a.front());
}

TEST(front_suite, push_test) {
  s21::list<int> s21_a({1, 2, 3, 4, 5});
  std::list<int> std_a({1, 2, 3, 4, 5});

  s21_a.push_front(6);
  std_a.push_front(6);

  EXPECT_TRUE(s21_a.front() == std_a.front());
}

TEST(front_suite, swap_test) {
  s21::list<int> s21_a({1, 2, 3, 4, 5});
  s21::list<int> s21_b({6});
  std::list<int> std_a({1, 2, 3, 4, 5});
  std::list<int> std_b({6});

  s21_a.swap(s21_b);
  std_a.swap(std_b);

  EXPECT_TRUE(s21_a.front() == std_a.front());
  EXPECT_TRUE(s21_b.front() == std_b.front());
}

TEST(back_suite, true_test) {
  s21::list<int> s21_a({1, 2, 3, 4, 5});
  std::list<int> std_a({1, 2, 3, 4, 5});

  EXPECT_TRUE(s21_a.back() == std_a.back());
}

TEST(back_suite, push_test) {
  s21::list<int> s21_a({1, 2, 3, 4, 5});
  std::list<int> std_a({1, 2, 3, 4, 5});

  s21_a.push_back(21);
  std_a.push_back(21);

  EXPECT_TRUE(s21_a.back() == std_a.back());
}

TEST(back_suite, pop_test) {
  s21::list<int> s21_a({1, 2, 3, 4, 5});
  std::list<int> std_a({1, 2, 3, 4, 5});

  s21_a.pop_back();
  std_a.pop_back();

  EXPECT_TRUE(s21_a.back() == std_a.back());
}

TEST(back_suite, swap_test) {
  s21::list<int> s21_a({1, 2, 3, 4, 5});
  s21::list<int> s21_b({6});
  std::list<int> std_a({1, 2, 3, 4, 5});
  std::list<int> std_b({6});

  s21_a.swap(s21_b);
  std_a.swap(std_b);

  EXPECT_TRUE(s21_a.back() == std_a.back());
  EXPECT_TRUE(s21_b.back() == std_b.back());
}

// block: ITERATORS
TEST(iterator_begin_suite, true_test) {
  s21::list<int> s21_a({1, 2, 3, 4, 5});
  std::list<int> std_a({1, 2, 3, 4, 5});
  s21::list<int>::iterator s21_itr = s21_a.begin();
  std::list<int>::iterator std_itr = std_a.begin();

  EXPECT_TRUE(*s21_itr == *std_itr);
}

TEST(iterator_begin_suite, empty_test) {
  s21::list<int> s21_a;
  std::list<int> std_a;
  s21::list<int>::iterator s21_itr = s21_a.begin();
  std::list<int>::iterator std_itr = std_a.begin();

  EXPECT_TRUE(*s21_itr == *std_itr);
}

TEST(iterator_begin_suite, pop_test) {
  s21::list<int> s21_a({1, 2, 3, 4, 5});
  std::list<int> std_a({1, 2, 3, 4, 5});
  s21::list<int>::iterator s21_itr = s21_a.begin();
  std::list<int>::iterator std_itr = std_a.begin();

  s21_a.pop_front();
  std_a.pop_front();

  EXPECT_TRUE(*s21_itr == *std_itr);
}

TEST(iterator_begin_suite, push_test) {
  s21::list<int> s21_a({1, 2, 3, 4, 5});
  std::list<int> std_a({1, 2, 3, 4, 5});
  s21::list<int>::iterator s21_itr = s21_a.begin();
  std::list<int>::iterator std_itr = std_a.begin();

  s21_a.push_front(6);
  std_a.push_front(6);

  EXPECT_TRUE(*s21_itr == *std_itr);
}

TEST(iterator_end_suite, true_test) {
  s21::list<int> s21_a({1, 2, 3, 4, 5});
  std::list<int> std_a({1, 2, 3, 4, 5});
  s21::list<int>::iterator s21_itr = s21_a.end();
  std::list<int>::iterator std_itr = std_a.end();

  EXPECT_TRUE(*s21_itr == *std_itr);
}

TEST(iterator_end_suite, empty_test) {
  s21::list<int> s21_a;
  std::list<int> std_a;
  s21::list<int>::iterator s21_itr = s21_a.end();
  std::list<int>::iterator std_itr = std_a.end();

  EXPECT_TRUE(*s21_itr == *std_itr);
}

TEST(iterator_end_suite, pop_test) {
  s21::list<int> s21_a({1, 2, 3, 4, 5});
  std::list<int> std_a({1, 2, 3, 4, 5});

  s21::list<int>::iterator s21_itr = s21_a.end();
  std::list<int>::iterator std_itr = std_a.end();

  s21_a.pop_back();
  std_a.pop_back();

  EXPECT_TRUE(*s21_itr == *std_itr);
}

TEST(iterator_end_suite, push_test) {
  s21::list<int> s21_a({1, 2, 3, 4, 5});
  std::list<int> std_a({1, 2, 3, 4, 5});
  s21::list<int>::iterator s21_itr = s21_a.end();
  std::list<int>::iterator std_itr = std_a.end();

  s21_a.push_back(6);
  std_a.push_back(6);

  EXPECT_TRUE(*s21_itr == *std_itr);
}

// block: INFO
TEST(empty_suit, true_test) {
  s21::list<int> list;
  std::list<int> std_list;

  EXPECT_TRUE(list.empty() == std_list.empty());
}

TEST(empty_suit, cleaned_test) {
  s21::list<int> list({1, 2, 3, 4, 5});
  std::list<int> std_list({1, 2, 3, 4, 5});

  list.clear();
  std_list.clear();

  EXPECT_TRUE(list.empty() == std_list.empty());
}
//
// TEST(empty_suit, merged_test) {
//  s21::list<int> list_a(5);
//  s21::list<int> list_b(5);
//  std::list<int> std_list_a(5);
//  std::list<int> std_list_b(5);
//
//  list_a.merge(list_b);
//  std_list_a.merge(std_list_b);
//
//  EXPECT_TRUE(list_b.empty() == std_list_b.empty());
//}
//
// TEST(empty_suit, spliced_test) {
//  s21::list<int> list_a(5);
//  s21::list<int> list_b(5);
//  s21::list<int>::iterator itr_a = list_a.begin();
//  std::list<int> std_list_a(5);
//  std::list<int> std_list_b(5);
//  std::list<int>::iterator std_itr_a = std_list_a.begin();
//
//  list_a.splice(itr_a, list_b);
//  std_list_a.splice(std_itr_a, std_list_b);
//
//  EXPECT_TRUE(list_b.empty() == std_list_b.empty());
//}

TEST(size_suite, true_test) {
  s21::list<int> list({1, 2, 3, 4, 5});
  std::list<int> std_list({1, 2, 3, 4, 5});

  EXPECT_TRUE(list.size() == std_list.size());
}

TEST(size_suite, empty_test) {
  s21::list<int> list;
  std::list<int> std_list;

  EXPECT_TRUE(list.size() == std_list.size());
}

TEST(size_suite, cleaned_test) {
  s21::list<int> list({1, 2, 3, 4, 5});
  std::list<int> std_list({1, 2, 3, 4, 5});

  list.clear();
  std_list.clear();

  EXPECT_TRUE(list.size() == std_list.size());
}

// TEST(size_suite, erase_one_element_test) { // SEG
//   s21::list<int> list(5);
//   std::list<int> std_list(5);
//   s21::list<int>::iterator itr = list.begin();
//   std::list<int>::iterator std_itr = std_list.begin();
//
//   printf("\n\n\n\n\n\n\n\n%d\n\n\n\n\n\n\n\n", *itr);
//   list.erase(itr);  // SEG
//   std_list.erase(std_itr);
//
////  ASSERT_EQ(list.size(), std_list.size());
//}
//
// TEST(size_suite, add_back_one_element_test) {
//  s21::list<int> list(5);
//  std::list<int> std_list(5);
//
//  list.push_back(1);
//  std_list.push_back(1);
//
//  ASSERT_EQ(list.size(), std_list.size());
//}
////
// TEST(size_suite, add_front_one_element_test) {
//   s21::list<int> list(5);
//   std::list<int> std_list(5);
//
//   list.push_front(1);
//   std_list.push_front(1);
//
//   ASSERT_EQ(list.size(), std_list.size());
// }
//
// TEST(size_suite, delete_back_one_element_test) {
//   s21::list<int> list(5);
//   std::list<int> std_list(5);
//
//   list.pop_back();
//   std_list.pop_back();
//
//   ASSERT_EQ(list.size(), std_list.size());
// }
//
// TEST(size_suite, delete_front_one_element_test) {
//   s21::list<int> list(5);
//   std::list<int> std_list(5);
//
//   list.pop_front();
//   std_list.pop_front();
//
//   ASSERT_EQ(list.size(), std_list.size());
// }

// block: MODIFIERS
TEST(insert_suite, true_test) {
  s21::list<int> list({1, 2, 3, 4, 5});
  std::list<int> std_list({1, 2, 3, 4, 5});
  s21::list<int>::iterator itr_b = list.begin();
  std::list<int>::iterator std_itr_b = std_list.begin();

  ++itr_b;
  ++itr_b;
  ++std_itr_b;
  ++std_itr_b;

  list.insert(itr_b, 1000);
  std_list.insert(std_itr_b, 1000);

  s21::list<int>::iterator itr_i = list.begin();
  std::list<int>::iterator std_itr_i = std_list.begin();

  for (; itr_i != list.end() && std_itr_i != std_list.end();
       ++itr_i, ++std_itr_i) {
    EXPECT_TRUE(*itr_i == *std_itr_i);
  }
  EXPECT_TRUE(std_list.size() == list.size());
  EXPECT_TRUE(std_list.front() == list.front());
  EXPECT_TRUE(std_list.back() == list.back());
}

TEST(insert_suite, front_test) {
  s21::list<int> list({1, 2, 3, 4, 5});
  std::list<int> std_list({1, 2, 3, 4, 5});
  s21::list<int>::iterator itr_b = list.begin();
  std::list<int>::iterator std_itr_b = std_list.begin();

  list.insert(itr_b, 100);
  std_list.insert(std_itr_b, 100);

  s21::list<int>::iterator itr_i = list.begin();
  std::list<int>::iterator std_itr_i = std_list.begin();
  for (; itr_i != list.end() && std_itr_i != std_list.end();
       ++itr_i, ++std_itr_i) {
    EXPECT_TRUE(*itr_i == *std_itr_i);
  }
  EXPECT_TRUE(std_list.size() == list.size());
  EXPECT_TRUE(std_list.front() == list.front());
}

TEST(insert_suite, back_test) {
  s21::list<int> list({1, 2, 3, 4, 5});
  std::list<int> std_list({1, 2, 3, 4, 5});
  s21::list<int>::iterator itr_e = list.end();
  std::list<int>::iterator std_itr_e = std_list.end();

  list.insert(itr_e, 100);
  std_list.insert(std_itr_e, 100);

  s21::list<int>::iterator itr_i = list.begin();
  std::list<int>::iterator std_itr_i = std_list.begin();
  for (; itr_i != list.end() && std_itr_i != std_list.end();
       ++itr_i, ++std_itr_i) {
    EXPECT_TRUE(*itr_i == *std_itr_i);
  }
  EXPECT_TRUE(std_list.size() == list.size());
  EXPECT_TRUE(std_list.back() == list.back());
}

TEST(clear_suite, true_test) {
  s21::list<int> list({1, 2, 3, 4, 5});
  std::list<int> std_list({1, 2, 3, 4, 5});

  list.clear();
  std_list.clear();

  EXPECT_TRUE(std_list.empty() && list.empty());
  EXPECT_TRUE(std_list.size() == list.size());
}

TEST(clear_suite, empty_test) {
  s21::list<int> list;
  std::list<int> std_list;

  list.clear();
  std_list.clear();

  EXPECT_TRUE(std_list.empty() && list.empty());
  EXPECT_TRUE(std_list.size() == list.size());
}

//// TEST(erase_suite, true_test) {
////   s21::list<int> list(5);
////   s21::list<int>::iterator itr = list.begin();
////   std::list<int> std_list(5);
////   std::list<int>::iterator std_itr = std_list.begin();
////   list.erase(itr);
////   std_list.erase(std_itr);
////
////  s21::list<int>::iterator loop_itr = list.begin();
////  std::list<int>::iterator std_loop_itr = std_list.begin();
////  for (; std_loop_itr != std_list.end(); ++std_loop_itr, ++loop_itr) {
////    EXPECT_TRUE(*loop_itr == *std_loop_itr);
////  }
////  EXPECT_TRUE(*list.begin() == *list.begin());
////}
//

// TEST(push_back_suite, true_test) {
//   s21::list<int> s21_a({1, 2, 3, 4, 5});
//   std::list<int> std_a({1, 2, 3, 4, 5});
//
//   s21_a.push_back(6);
//   std_a.push_back(6);
//
//   EXPECT_TRUE(s21_a.back() == std_a.back());
//   EXPECT_TRUE(s21_a.size() == std_a.size());
// }
//
// TEST(push_front_suite, true_test) {
//   s21::list<int> s21_a({1, 2, 3, 4, 5});
//   std::list<int> std_a({1, 2, 3, 4, 5});
//   s21::list<int>::iterator s21_itr;
//   std::list<int>::iterator std_itr;
//
//   s21_a.push_front(0);
//   std_a.push_front(0);
//   s21_itr = s21_a.begin();
//   std_itr = std_a.begin();
//
//   EXPECT_TRUE(*s21_itr == *std_itr);
//   EXPECT_TRUE(s21_a.size() == std_a.size());
// }
//
// TEST(pop_back_suite, true_test) {
//   s21::list<int> s21_a({1, 2, 3, 4, 5});
//   std::list<int> std_a({1, 2, 3, 4, 5});
//
//   s21_a.pop_back();
//   std_a.pop_back();
//
//   EXPECT_TRUE(s21_a.back() == std_a.back());
//   EXPECT_TRUE(s21_a.size() == std_a.size());
// }
//
// TEST(pop_front_suite, true_test) {
//   s21::list<int> s21_a({1, 2, 3, 4, 5});
//   std::list<int> std_a({1, 2, 3, 4, 5});
//
//   s21_a.pop_front();
//   std_a.pop_front();
//
//   EXPECT_TRUE(s21_a.front() == std_a.front());
//   EXPECT_TRUE(s21_a.size() == std_a.size());
// }
//
// TEST(swap_suite, true_test) {
//   s21::list<int> s21_a({1, 2, 3, 4, 5});
//   s21::list<int> s21_b({1});
//   std::list<int> std_a({1, 2, 3, 4, 5});
//   std::list<int> std_b({1});
//
//   s21_a.swap(s21_b);
//   std_a.swap(std_b);
//
//   EXPECT_TRUE(s21_a.empty() == std_a.empty());
//   EXPECT_TRUE(s21_a.size() == std_a.size());
//   EXPECT_TRUE(s21_a.front() == std_a.front());
//   EXPECT_TRUE(s21_a.back() == std_a.back());
//   EXPECT_TRUE(s21_b.size() == std_b.size());
//   EXPECT_TRUE(s21_b.front() == std_b.front());
//   EXPECT_TRUE(s21_b.back() == std_b.back());
// }
//
// TEST(sort_suite, true_test) {
//   s21::list<int> list({11, 2, 6, 9, 5});
//   std::list<int> std_list({11, 2, 6, 9, 5});
//
//   list.sort();
//   std_list.sort();
//
//   auto itr = list.begin();
//   auto std_itr = std_list.begin();
//   for (; itr != list.end(); ++itr, ++std_itr) {
//     EXPECT_TRUE(*itr == *std_itr);
//   }
// }
//
// TEST(sort_suite, empty_test) {
//   s21::list<int> list;
//   std::list<int> std_list;
//
//   list.sort();
//   std_list.sort();
//
//   auto itr = list.begin();
//   auto std_itr = std_list.begin();
//   for (; itr != list.end(); ++itr, ++std_itr) {
//     EXPECT_TRUE(*itr == *std_itr);
//   }
// }

// block: ITERATORS OVERLOADING
TEST(overloading_assignment_and_dereference_iterator_suite,
     overloading_true_test) {
  s21::list<int> s21_a({1, 2, 3, 4, 5});
  std::list<int> std_a({1, 2, 3, 4, 5});
  s21::list<int>::iterator itr_b = s21_a.begin();
  std::list<int>::iterator std_itr_b = std_a.begin();
  s21::list<int>::iterator itr_e = s21_a.end();
  std::list<int>::iterator std_itr_e = std_a.end();

  EXPECT_TRUE(*itr_b == *std_itr_b);
  EXPECT_TRUE(*itr_e == *std_itr_e);
}

TEST(overloading_increment_suite, true_test) {
  s21::list<int> s21_a({1, 2, 3, 4, 5, 6});
  std::list<int> std_a({1, 2, 3, 4, 5, 6});
  s21::list<int>::iterator itr = s21_a.begin();
  std::list<int>::iterator std_itr = std_a.begin();

  for (; itr != s21_a.end(); ++itr, ++std_itr) {
    EXPECT_TRUE(*itr == *std_itr);
  }
}

TEST(overloading_increment_suite, end_to_begin_test) {
  s21::list<int> list = {1, 2, 3, 5};
  std::list<int> std_list = {1, 2, 3, 5};
  s21::list<int>::iterator itr = list.end();
  std::list<int>::iterator std_itr = std_list.end();

  ++itr;
  ++std_itr;

  EXPECT_TRUE(*itr == *std_itr);
  EXPECT_TRUE(*itr == *list.begin());
  EXPECT_TRUE(*std_itr == *std_list.begin());
}

TEST(overloading_decrement_suite, true_test) {
  s21::list<int> s21_a({1, 2, 3, 4, 5, 6});
  std::list<int> std_a({1, 2, 3, 4, 5, 6});
  s21::list<int>::iterator itr = s21_a.end();
  std::list<int>::iterator std_itr = std_a.end();

  for (; itr != s21_a.begin(); --itr, --std_itr) {
    EXPECT_TRUE(*itr == *std_itr);
  }
}

TEST(overloading_decrement_suite, begin_to_end_test) {
  s21::list<int> list = {1, 2, 3, 2};
  std::list<int> std_list = {1, 2, 3, 2};
  s21::list<int>::iterator itr = list.begin();
  std::list<int>::iterator std_itr = std_list.begin();

  --itr;
  --std_itr;
  EXPECT_TRUE(*itr == *std_itr);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}