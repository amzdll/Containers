#include <list>

#include "gtest/gtest.h"
// refactor: cpp to h
#include "s21_list.cpp"

// block: CONSTRUCTORS
// BLOCK: CONSTRUCTORS
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
//
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
//
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

// TEST(move_constructor_suite, int_true_test) {
//  s21::list<int> s21_b(5);
//  s21::list<int> s21_a(std::move(s21_b));
//  std::list<int> std_b(5);
//  std::list<int> std_a(std::move(std_b));
//
//  EXPECT_TRUE(s21_a.empty() == std_a.empty());
//  EXPECT_TRUE(s21_a.size() == std_a.size());
//}

// block: ITERATORS
// TEST(overloading_assignment_and_dereference_iterator_suite,
//     overloading_true_test) {
//  s21::list<int> list(1);
//  s21::list<int>::iterator itr = list.begin();
//  std::list<int> std_list(1);
//  std::list<int>::iterator std_itr = std_list.begin();
//
//  EXPECT_TRUE(*itr == *std_itr);
//}
//
// TEST(overloading_assignment_and_dereference_iterator_suite,overloading_true_test_2)
// {
//   s21::list<int> list(1);
//   s21::list<int>::iterator itr = list.end();
//   std::list<int> std_list(1);
//   std::list<int>::iterator std_itr = std_list.end();
//
//   EXPECT_TRUE(*itr == *std_itr);
// }
//
// TEST(overloading_assignment_and_dereference_iterator_suite,
//     empty_list_begin_edge_test) {
//  s21::list<int> list;
//  s21::list<int>::iterator itr = list.begin();
//  std::list<int> std_list;
//  std::list<int>::iterator std_itr = std_list.begin();
//
//  EXPECT_TRUE(*itr == *std_itr);
//}
//
// TEST(overloading_assignment_and_dereference_iterator_suite,
//     empty_list_end_edge_test) {
//  s21::list<int> list;
//  s21::list<int>::iterator itr = list.end();
//  std::list<int> std_list;
//  std::list<int>::iterator std_itr = std_list.end();
//
//  EXPECT_TRUE(*itr == *std_itr);
//}
//
// TEST(overloading_assignment_and_dereference_iterator_suite,
//     delete_element_edge_test) {
//  s21::list<int> list(1);
//  s21::list<int>::iterator itr = list.begin();
//  std::list<int> std_list(1);
//  std::list<int>::iterator std_itr = std_list.begin();
//
//  list.erase(itr);
//  std_list.erase(std_itr);
//
//  EXPECT_TRUE(*itr == *std_itr);
//}
//
// TEST(overloading_increment_suite, true_test) {
//  s21::list<int> list;
//  std::list<int> std_list;
//  list.push_back(1);
//  list.push_back(2);
//  std_list.push_back(1);
//  std_list.push_back(2);
//
//  s21::list<int>::iterator itr = list.begin();
//  std::list<int>::iterator std_itr = std_list.begin();
//
//  EXPECT_TRUE(*itr == *std_itr);
//  ++itr;
//  ++std_itr;
//  EXPECT_TRUE(*itr == *std_itr);
//}

// block: INFO
TEST(empty_suit, true_test) {
  s21::list<int> list;
  std::list<int> std_list;

  EXPECT_TRUE(list.empty() == std_list.empty());
}

TEST(empty_suit, cleaned_edge_test) {
  s21::list<int> list(5);
  std::list<int> std_list(5);

  list.clear();
  std_list.clear();

  EXPECT_TRUE(list.empty() == std_list.empty());
}

TEST(empty_suit, merged_edge_test) {
  s21::list<int> list_a(5);
  s21::list<int> list_b(5);
  std::list<int> std_list_a(5);
  std::list<int> std_list_b(5);

  list_a.merge(list_b);
  std_list_a.merge(std_list_b);

  EXPECT_TRUE(list_b.empty() == std_list_b.empty());
}

TEST(empty_suit, spliced_edge_test) {
  s21::list<int> list_a(5);
  s21::list<int> list_b(5);
  s21::list<int>::iterator itr_a = list_a.begin();
  std::list<int> std_list_a(5);
  std::list<int> std_list_b(5);
  std::list<int>::iterator std_itr_a = std_list_a.begin();

  list_a.splice(itr_a, list_b);
  std_list_a.splice(std_itr_a, std_list_b);

  EXPECT_TRUE(list_b.empty() == std_list_b.empty());
}

TEST(size_suite, true_test) {
  s21::list<int> list(5);
  std::list<int> std_list(5);

  ASSERT_EQ(list.size(), std_list.size());
}

TEST(size_suite, empty_edge_test) {
  s21::list<int> list;
  std::list<int> std_list;

  ASSERT_EQ(list.size(), std_list.size());
}

TEST(size_suite, cleaned_edge_test) {
  s21::list<int> list(5);
  std::list<int> std_list(5);

  list.clear();
  std_list.clear();

  ASSERT_EQ(list.size(), std_list.size());
}

// TEST(size_suite, erase_one_element_edge_test) { // SEG
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

TEST(size_suite, add_back_one_element_edge_test) {
  s21::list<int> list(5);
  std::list<int> std_list(5);

  list.push_back(1);
  std_list.push_back(1);

  ASSERT_EQ(list.size(), std_list.size());
}
//
TEST(size_suite, add_front_one_element_edge_test) {
  s21::list<int> list(5);
  std::list<int> std_list(5);

  list.push_front(1);
  std_list.push_front(1);

  ASSERT_EQ(list.size(), std_list.size());
}

TEST(size_suite, delete_back_one_element_edge_test) {
  s21::list<int> list(5);
  std::list<int> std_list(5);

  list.pop_back();
  std_list.pop_back();

  ASSERT_EQ(list.size(), std_list.size());
}

TEST(size_suite, delete_front_one_element_edge_test) {
  s21::list<int> list(5);
  std::list<int> std_list(5);

  list.pop_front();
  std_list.pop_front();

  ASSERT_EQ(list.size(), std_list.size());
}

// block: METHODS TO MODIFY
TEST(clear_suite, true_test) {
  s21::list<int> list;
  std::list<int> std_list;

  list.push_back(1);
  std_list.push_back(1);

  list.clear();
  std_list.clear();

  EXPECT_TRUE(std_list.empty() && list.empty());
  EXPECT_TRUE(std_list.size() == list.size());
}

TEST(clear_suite, empty_list_edge_test) {
  s21::list<int> list;
  std::list<int> std_list;

  list.clear();
  std_list.clear();

  EXPECT_TRUE(std_list.empty() && list.empty());
  EXPECT_TRUE(std_list.size() == list.size());
}

// TEST(erase_suite, true_test) {
//   s21::list<int> list(5);
//   s21::list<int>::iterator itr = list.begin();
//   std::list<int> std_list(5);
//   std::list<int>::iterator std_itr = std_list.begin();
//   list.erase(itr);
//   std_list.erase(std_itr);
//
//  s21::list<int>::iterator loop_itr = list.begin();
//  std::list<int>::iterator std_loop_itr = std_list.begin();
//  for (; std_loop_itr != std_list.end(); ++std_loop_itr, ++loop_itr) {
//    EXPECT_TRUE(*loop_itr == *std_loop_itr);
//  }
//  EXPECT_TRUE(*list.begin() == *list.begin());
//}

TEST(push_back_suite, true_test) {
  s21::list<int> list(2);
  std::list<int> std_list(2);
  s21::list<int>::iterator itr;
  std::list<int>::iterator std_itr;

  list.push_back(1);
  std_list.push_back(1);

  itr = list.end();
  std_itr = std_list.end();
  --itr;
  --std_itr;
  //
  EXPECT_TRUE(*itr == *std_itr);
  //  printf("\n\n\n\n\n\n%d\n\n\n\n\n", *itr);
  //  EXPECT_TRUE(*itr == 1); // SEG
}

TEST(push_front_suite, true_test) {
  s21::list<int> list(2);
  std::list<int> std_list(2);
  s21::list<int>::iterator itr;
  std::list<int>::iterator std_itr;

  list.push_front(1);
  std_list.push_front(1);
  itr = list.begin();
  std_itr = std_list.begin();

  EXPECT_TRUE(*itr == *std_itr);
  EXPECT_TRUE(*itr == 1);
}

TEST(pop_back_suite, true_test) {
  s21::list<int> list(2);
  std::list<int> std_list(2);
  s21::list<int>::iterator itr;
  std::list<int>::iterator std_itr;

  list.pop_back();
  std_list.pop_back();

  itr = list.end();
  std_itr = std_list.end();
  --itr;
  --std_itr;
  //    printf("\n\n\n\n\n\n%d\t%d\n\n\n\n\n", *itr, *std_itr);

  EXPECT_TRUE(*itr == *std_itr);
  //  EXPECT_TRUE(*itr == 0); // SEG
}

TEST(pop_front_suite, true_test) {
  s21::list<int> list(2);
  std::list<int> std_list(2);
  s21::list<int>::iterator itr;
  std::list<int>::iterator std_itr;

  list.push_front(5);
  std_list.push_front(5);
  list.pop_front();
  std_list.pop_front();
  itr = list.begin();
  std_itr = std_list.begin();

  //      printf("\n\n\n\n\n\n%d\t%d\n\n\n\n\n", *itr, *std_itr);

  EXPECT_TRUE(*itr == *std_itr);
  EXPECT_TRUE(list.size() == std_list.size());
  //    EXPECT_TRUE(*itr == 0); // SEG
}

TEST(swap_suite, true_test) {
  s21::list<int> list_a(2);
  s21::list<int> list_b;
  std::list<int> std_list_a(2);
  std::list<int> std_list_b;

  list_b.swap(list_a);
  std_list_b.swap(std_list_a);

  EXPECT_TRUE(list_b.size() == std_list_b.size());
  EXPECT_TRUE(list_b.size() == 2);
}

TEST(swap_suite, value_true_test) {
  int temp[] = {1, 2, 3};

  s21::list<int> list_a(2);
  s21::list<int> list_b;
  s21::list<int>::iterator itr_b;
  std::list<int> std_list_a(2);
  std::list<int> std_list_b;
  std::list<int>::iterator std_itr_b;

  list_a.push_back(1);
  list_a.push_back(2);
  list_a.push_back(3);
  std_list_a.push_back(1);
  std_list_a.push_back(2);
  std_list_a.push_back(3);

  list_b.swap(list_a);
  std_list_b.swap(std_list_a);

//  EXPECT_TRUE(list_b.size() == std_list_b.size()); // SEG
//  long double a = list_b.size();
//  printf("HUI:%Lf\n", a);
//  EXPECT_TRUE(list_b.size() == 5);
//
//  for (int i = 0; itr_b != list_b.end() && std_itr_b != std_list_b.end();
//       ++itr_b, ++std_itr_b, ++i) {
//    EXPECT_TRUE(*itr_b == *std_itr_b);
//    EXPECT_TRUE(*itr_b == temp[i]);
//  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}