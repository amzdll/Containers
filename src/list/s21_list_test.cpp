#include <list>

#include "gtest/gtest.h"
// refactor: cpp to h
#include "s21_list.cpp"

// block: ITERATORS
TEST(overloading_assignment_and_dereference_iterator_suite,
     overloading_true_test) {
  s21::list<int> list(1);
  s21::list<int>::iterator itr = list.begin();
  std::list<int> std_list(1);
  std::list<int>::iterator std_itr = std_list.begin();

  EXPECT_TRUE(*itr == *std_itr);
}

 TEST(overloading_assignment_and_dereference_iterator_suite,overloading_true_test_2)
 {
   s21::list<int> list(1);
   s21::list<int>::iterator itr = list.end();
   std::list<int> std_list(1);
   std::list<int>::iterator std_itr = std_list.end();

   EXPECT_TRUE(*itr == *std_itr);
 }

TEST(overloading_assignment_and_dereference_iterator_suite,
     empty_list_begin_edge_test) {
  s21::list<int> list;
  s21::list<int>::iterator itr = list.begin();
  std::list<int> std_list;
  std::list<int>::iterator std_itr = std_list.begin();

  EXPECT_TRUE(*itr == *std_itr);
}

TEST(overloading_assignment_and_dereference_iterator_suite,
     empty_list_end_edge_test) {
  s21::list<int> list;
  s21::list<int>::iterator itr = list.end();
  std::list<int> std_list;
  std::list<int>::iterator std_itr = std_list.end();

  EXPECT_TRUE(*itr == *std_itr);
}

//SEG
//TEST(overloading_assignment_and_dereference_iterator_suite,
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


TEST(size_suite, erase_one_element_edge_test) {
  s21::list<int> list(5);
  std::list<int> std_list(5);
  s21::list<int>::iterator itr = list.begin();
  std::list<int>::iterator std_itr = std_list.begin();

  printf("\n\n\n\n\n\n\n\n%d\n\n\n\n\n\n\n\n", *itr);
  list.erase(itr);  // SEG
  std_list.erase(std_itr);

//  ASSERT_EQ(list.size(), std_list.size());
}

TEST(size_suite, add_back_one_element_edge_test) {
  s21::list<int> list(5);
  std::list<int> std_list(5);

  list.push_back(1);
  std_list.push_back(1);

  ASSERT_EQ(list.size(), std_list.size());
}

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
//TEST(clear_suite, true_test) {
//  s21::list<int> list;
//  std::list<int> std_list;
//
//  list.push_back(1);
//  std_list.push_back(1);
//
//  list.clear();
//  std_list.clear();

//  EXPECT_TRUE(std_list.empty() && list.empty());
//}

//TEST(erase_suite, true_test) {
//  s21::list<int> list(5);
//  s21::list<int>::iterator itr = list.begin();
//  std::list<int> std_list(5);
//  std::list<int>::iterator std_itr = std_list.begin();
//  list.erase(itr);
//  std_list.erase(std_itr);
//
//  s21::list<int>::iterator loop_itr = list.begin();
//  std::list<int>::iterator std_loop_itr = std_list.begin();
//  for (; std_loop_itr != std_list.end(); ++std_loop_itr, ++loop_itr) {
//    EXPECT_TRUE(*loop_itr == *std_loop_itr);
//  }
//  EXPECT_TRUE(*list.begin() == *list.begin());
//}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}