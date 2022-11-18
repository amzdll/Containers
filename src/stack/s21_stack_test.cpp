//#include <stack>
//
//#include "gtest/gtest.h"
//// refactor: cpp to h
//#include "s21_stack.cpp"
//
//// block: CONSTRUCTORS
//// BLOCK: CONSTRUCTORS
//TEST(default_constructor_suite, int_true_test) {
//  s21::stack<int> s21_a;
//  std::stack<int> std_a;
//
//  EXPECT_TRUE(s21_a.empty() == std_a.empty());
//  EXPECT_TRUE(s21_a.size() == std_a.size());
//}
//
//TEST(default_constructor_suite, double_true_test) {
//  s21::stack<double> s21_a;
//  std::stack<double> std_a;
//
//  EXPECT_TRUE(s21_a.empty() == std_a.empty());
//  EXPECT_TRUE(s21_a.size() == std_a.size());
//}
//
//TEST(default_constructor_suite, float_true_test) {
//  s21::stack<float> s21_a;
//  std::stack<float> std_a;
//
//  EXPECT_TRUE(s21_a.empty() == std_a.empty());
//  EXPECT_TRUE(s21_a.size() == std_a.size());
//}
//
//TEST(default_constructor_suite, struct_true_test) {
//  struct test_struct {
//    int a;
//    double b;
//    float c;
//  };
//
//  s21::stack<test_struct> s21_a;
//  std::stack<test_struct> std_a;
//
//  EXPECT_TRUE(s21_a.empty() == std_a.empty());
//  EXPECT_TRUE(s21_a.size() == std_a.size());
//}
//
//TEST(parameterized_constructor_suite, int_true_test) {
//  s21::stack<int> s21_a(5);
//  std::stack<int> std_a(5);
//
//  EXPECT_TRUE(s21_a.empty() == std_a.empty());
//  EXPECT_TRUE(s21_a.size() == std_a.size());
//}
//
//TEST(parameterized_constructor_suite, double_true_test) {
//  s21::stack<double> s21_a(5);
//  std::stack<double> std_a(5);
//
//  EXPECT_TRUE(s21_a.empty() == std_a.empty());
//  EXPECT_TRUE(s21_a.size() == std_a.size());
//}
//
//TEST(parameterized_constructor_suite, float_true_test) {
//  s21::stack<float> s21_a(5);
//  std::stack<float> std_a(5);
//
//  EXPECT_TRUE(s21_a.empty() == std_a.empty());
//  EXPECT_TRUE(s21_a.size() == std_a.size());
//}
//
//TEST(parameterized_constructor_suite, struct_true_test) {
//  struct test_struct {
//    int a;
//    double b;
//    float c;
//  };
//
//  s21::stack<test_struct> s21_a(5);
//  std::stack<test_struct> std_a(5);
//
//  EXPECT_TRUE(s21_a.empty() == std_a.empty());
//  EXPECT_TRUE(s21_a.size() == std_a.size());
//}
//
//TEST(copy_constructor_suite, int_true_test) {
//  s21::stack<int> s21_b(5);
//  s21::stack<int> s21_a(s21_b);
//  std::stack<int> std_b(5);
//  std::stack<int> std_a(std_b);
//
//  EXPECT_TRUE(s21_a.empty() == std_a.empty());
//  EXPECT_TRUE(s21_a.size() == std_a.size());
//
//  EXPECT_TRUE(s21_b.empty() == std_b.empty());
//  EXPECT_TRUE(s21_b.size() == std_b.size());
//}
////
//TEST(copy_constructor_suite, double_true_test) {
//  s21::stack<double> s21_b(5);
//  s21::stack<double> s21_a(s21_b);
//  std::stack<double> std_b(5);
//  std::stack<double> std_a(std_b);
//
//  EXPECT_TRUE(s21_a.empty() == std_a.empty());
//  EXPECT_TRUE(s21_a.size() == std_a.size());
//
//  EXPECT_TRUE(s21_b.empty() == std_b.empty());
//  EXPECT_TRUE(s21_b.size() == std_b.size());
//}
//
//TEST(copy_constructor_suite, float_true_test) {
//  s21::stack<float> s21_b(5);
//  s21::stack<float> s21_a(s21_b);
//  std::stack<float> std_b(5);
//  std::stack<float> std_a(std_b);
//
//  EXPECT_TRUE(s21_a.empty() == std_a.empty());
//  EXPECT_TRUE(s21_a.size() == std_a.size());
//
//  EXPECT_TRUE(s21_b.empty() == std_b.empty());
//  EXPECT_TRUE(s21_b.size() == std_b.size());
//}
////
//TEST(copy_constructor_suite, struct_true_test) {
//  struct test_struct {
//    int a;
//    double b;
//    float c;
//  };
//
//  s21::stack<test_struct> s21_b(5);
//  s21::stack<test_struct> s21_a(s21_b);
//  std::stack<test_struct> std_b(5);
//  std::stack<test_struct> std_a(std_b);
//
//  EXPECT_TRUE(s21_a.empty() == std_a.empty());
//  EXPECT_TRUE(s21_a.size() == std_a.size());
//  EXPECT_TRUE(s21_b.empty() == std_b.empty());
//  EXPECT_TRUE(s21_b.size() == std_b.size());
//}
//
//// TEST(move_constructor_suite, int_true_test) {
////  s21::stack<int> s21_b(5);
////  s21::stack<int> s21_a(std::move(s21_b));
////  std::stack<int> std_b(5);
////  std::stack<int> std_a(std::move(std_b));
////
////  EXPECT_TRUE(s21_a.empty() == std_a.empty());
////  EXPECT_TRUE(s21_a.size() == std_a.size());
////}
//
//// block: ITERATORS
//// TEST(overloading_assignment_and_dereference_iterator_suite,
////     overloading_true_test) {
////  s21::stack<int> stack(1);
////  s21::stack<int>::iterator itr = stack.begin();
////  std::stack<int> std_stack(1);
////  std::stack<int>::iterator std_itr = std_stack.begin();
////
////  EXPECT_TRUE(*itr == *std_itr);
////}
////
//// TEST(overloading_assignment_and_dereference_iterator_suite,overloading_true_test_2)
//// {
////   s21::stack<int> stack(1);
////   s21::stack<int>::iterator itr = stack.end();
////   std::stack<int> std_stack(1);
////   std::stack<int>::iterator std_itr = std_stack.end();
////
////   EXPECT_TRUE(*itr == *std_itr);
//// }
////
//// TEST(overloading_assignment_and_dereference_iterator_suite,
////     empty_stack_begin_edge_test) {
////  s21::stack<int> stack;
////  s21::stack<int>::iterator itr = stack.begin();
////  std::stack<int> std_stack;
////  std::stack<int>::iterator std_itr = std_stack.begin();
////
////  EXPECT_TRUE(*itr == *std_itr);
////}
////
//// TEST(overloading_assignment_and_dereference_iterator_suite,
////     empty_stack_end_edge_test) {
////  s21::stack<int> stack;
////  s21::stack<int>::iterator itr = stack.end();
////  std::stack<int> std_stack;
////  std::stack<int>::iterator std_itr = std_stack.end();
////
////  EXPECT_TRUE(*itr == *std_itr);
////}
////
//// TEST(overloading_assignment_and_dereference_iterator_suite,
////     delete_element_edge_test) {
////  s21::stack<int> stack(1);
////  s21::stack<int>::iterator itr = stack.begin();
////  std::stack<int> std_stack(1);
////  std::stack<int>::iterator std_itr = std_stack.begin();
////
////  stack.erase(itr);
////  std_stack.erase(std_itr);
////
////  EXPECT_TRUE(*itr == *std_itr);
////}
////
//// TEST(overloading_increment_suite, true_test) {
////  s21::stack<int> stack;
////  std::stack<int> std_stack;
////  stack.push_back(1);
////  stack.push_back(2);
////  std_stack.push_back(1);
////  std_stack.push_back(2);
////
////  s21::stack<int>::iterator itr = stack.begin();
////  std::stack<int>::iterator std_itr = std_stack.begin();
////
////  EXPECT_TRUE(*itr == *std_itr);
////  ++itr;
////  ++std_itr;
////  EXPECT_TRUE(*itr == *std_itr);
////}
//
//// block: INFO
//TEST(empty_suit, true_test) {
//  s21::stack<int> stack;
//  std::stack<int> std_stack;
//
//  EXPECT_TRUE(stack.empty() == std_stack.empty());
//}
//
//TEST(empty_suit, cleaned_edge_test) {
//  s21::stack<int> stack(5);
//  std::stack<int> std_stack(5);
//
//  stack.clear();
//  std_stack.clear();
//
//  EXPECT_TRUE(stack.empty() == std_stack.empty());
//}
//
//TEST(empty_suit, merged_edge_test) {
//  s21::stack<int> stack_a(5);
//  s21::stack<int> stack_b(5);
//  std::stack<int> std_stack_a(5);
//  std::stack<int> std_stack_b(5);
//
//  stack_a.merge(stack_b);
//  std_stack_a.merge(std_stack_b);
//
//  EXPECT_TRUE(stack_b.empty() == std_stack_b.empty());
//}
//
//TEST(empty_suit, spliced_edge_test) {
//  s21::stack<int> stack_a(5);
//  s21::stack<int> stack_b(5);
//  s21::stack<int>::iterator itr_a = stack_a.begin();
//  std::stack<int> std_stack_a(5);
//  std::stack<int> std_stack_b(5);
//  std::stack<int>::iterator std_itr_a = std_stack_a.begin();
//
//  stack_a.splice(itr_a, stack_b);
//  std_stack_a.splice(std_itr_a, std_stack_b);
//
//  EXPECT_TRUE(stack_b.empty() == std_stack_b.empty());
//}
//
//TEST(size_suite, true_test) {
//  s21::stack<int> stack(5);
//  std::stack<int> std_stack(5);
//
//  ASSERT_EQ(stack.size(), std_stack.size());
//}
//
//TEST(size_suite, empty_edge_test) {
//  s21::stack<int> stack;
//  std::stack<int> std_stack;
//
//  ASSERT_EQ(stack.size(), std_stack.size());
//}
//
//TEST(size_suite, cleaned_edge_test) {
//  s21::stack<int> stack(5);
//  std::stack<int> std_stack(5);
//
//  stack.clear();
//  std_stack.clear();
//
//  ASSERT_EQ(stack.size(), std_stack.size());
//}
//
//// TEST(size_suite, erase_one_element_edge_test) { // SEG
////   s21::stack<int> stack(5);
////   std::stack<int> std_stack(5);
////   s21::stack<int>::iterator itr = stack.begin();
////   std::stack<int>::iterator std_itr = std_stack.begin();
////
////   printf("\n\n\n\n\n\n\n\n%d\n\n\n\n\n\n\n\n", *itr);
////   stack.erase(itr);  // SEG
////   std_stack.erase(std_itr);
////
//////  ASSERT_EQ(stack.size(), std_stack.size());
////}
//
//TEST(size_suite, add_back_one_element_edge_test) {
//  s21::stack<int> stack(5);
//  std::stack<int> std_stack(5);
//
//  stack.push_back(1);
//  std_stack.push_back(1);
//
//  ASSERT_EQ(stack.size(), std_stack.size());
//}
////
//TEST(size_suite, add_front_one_element_edge_test) {
//  s21::stack<int> stack(5);
//  std::stack<int> std_stack(5);
//
//  stack.push_front(1);
//  std_stack.push_front(1);
//
//  ASSERT_EQ(stack.size(), std_stack.size());
//}
//
//TEST(size_suite, delete_back_one_element_edge_test) {
//  s21::stack<int> stack(5);
//  std::stack<int> std_stack(5);
//
//  stack.pop_back();
//  std_stack.pop_back();
//
//  ASSERT_EQ(stack.size(), std_stack.size());
//}
//
//TEST(size_suite, delete_front_one_element_edge_test) {
//  s21::stack<int> stack(5);
//  std::stack<int> std_stack(5);
//
//  stack.pop_front();
//  std_stack.pop_front();
//
//  ASSERT_EQ(stack.size(), std_stack.size());
//}
//
//// block: METHODS TO MODIFY
//TEST(clear_suite, true_test) {
//  s21::stack<int> stack;
//  std::stack<int> std_stack;
//
//  stack.push_back(1);
//  std_stack.push_back(1);
//
//  stack.clear();
//  std_stack.clear();
//
//  EXPECT_TRUE(std_stack.empty() && stack.empty());
//  EXPECT_TRUE(std_stack.size() == stack.size());
//}
//
//TEST(clear_suite, empty_stack_edge_test) {
//  s21::stack<int> stack;
//  std::stack<int> std_stack;
//
//  stack.clear();
//  std_stack.clear();
//
//  EXPECT_TRUE(std_stack.empty() && stack.empty());
//  EXPECT_TRUE(std_stack.size() == stack.size());
//}
//
//// TEST(erase_suite, true_test) {
////   s21::stack<int> stack(5);
////   s21::stack<int>::iterator itr = stack.begin();
////   std::stack<int> std_stack(5);
////   std::stack<int>::iterator std_itr = std_stack.begin();
////   stack.erase(itr);
////   std_stack.erase(std_itr);
////
////  s21::stack<int>::iterator loop_itr = stack.begin();
////  std::stack<int>::iterator std_loop_itr = std_stack.begin();
////  for (; std_loop_itr != std_stack.end(); ++std_loop_itr, ++loop_itr) {
////    EXPECT_TRUE(*loop_itr == *std_loop_itr);
////  }
////  EXPECT_TRUE(*stack.begin() == *stack.begin());
////}
//
//TEST(push_back_suite, true_test) {
//  s21::stack<int> stack(2);
//  std::stack<int> std_stack(2);
//  s21::stack<int>::iterator itr;
//  std::stack<int>::iterator std_itr;
//
//  stack.push_back(1);
//  std_stack.push_back(1);
//
//  itr = stack.end();
//  std_itr = std_stack.end();
//  --itr;
//  --std_itr;
//  //
//  EXPECT_TRUE(*itr == *std_itr);
//  //  printf("\n\n\n\n\n\n%d\n\n\n\n\n", *itr);
//  //  EXPECT_TRUE(*itr == 1); // SEG
//}
//
//TEST(push_front_suite, true_test) {
//  s21::stack<int> stack(2);
//  std::stack<int> std_stack(2);
//  s21::stack<int>::iterator itr;
//  std::stack<int>::iterator std_itr;
//
//  stack.push_front(1);
//  std_stack.push_front(1);
//  itr = stack.begin();
//  std_itr = std_stack.begin();
//
//  EXPECT_TRUE(*itr == *std_itr);
//  EXPECT_TRUE(*itr == 1);
//}
//
//TEST(pop_back_suite, true_test) {
//  s21::stack<int> stack(2);
//  std::stack<int> std_stack(2);
//  s21::stack<int>::iterator itr;
//  std::stack<int>::iterator std_itr;
//
//  stack.pop_back();
//  std_stack.pop_back();
//
//  itr = stack.end();
//  std_itr = std_stack.end();
//  --itr;
//  --std_itr;
//  //    printf("\n\n\n\n\n\n%d\t%d\n\n\n\n\n", *itr, *std_itr);
//
//  EXPECT_TRUE(*itr == *std_itr);
//  //  EXPECT_TRUE(*itr == 0); // SEG
//}
//
//TEST(pop_front_suite, true_test) {
//  s21::stack<int> stack(2);
//  std::stack<int> std_stack(2);
//  s21::stack<int>::iterator itr;
//  std::stack<int>::iterator std_itr;
//
//  stack.push_front(5);
//  std_stack.push_front(5);
//  stack.pop_front();
//  std_stack.pop_front();
//  itr = stack.begin();
//  std_itr = std_stack.begin();
//
//  //      printf("\n\n\n\n\n\n%d\t%d\n\n\n\n\n", *itr, *std_itr);
//
//  EXPECT_TRUE(*itr == *std_itr);
//  EXPECT_TRUE(stack.size() == std_stack.size());
//  //    EXPECT_TRUE(*itr == 0); // SEG
//}
//
//TEST(swap_suite, true_test) {
//  s21::stack<int> stack_a(2);
//  s21::stack<int> stack_b;
//  std::stack<int> std_stack_a(2);
//  std::stack<int> std_stack_b;
//
//  stack_b.swap(stack_a);
//  std_stack_b.swap(std_stack_a);
//
//  EXPECT_TRUE(stack_b.size() == std_stack_b.size());
//  EXPECT_TRUE(stack_b.size() == 2);
//}
//
//TEST(swap_suite, value_true_test) {
//  int temp[] = {1, 2, 3};
//
//  s21::stack<int> stack_a(2);
//  s21::stack<int> stack_b;
//  s21::stack<int>::iterator itr_b;
//  std::stack<int> std_stack_a(2);
//  std::stack<int> std_stack_b;
//  std::stack<int>::iterator std_itr_b;
//
//  stack_a.push_back(1);
//  stack_a.push_back(2);
//  stack_a.push_back(3);
//  std_stack_a.push_back(1);
//  std_stack_a.push_back(2);
//  std_stack_a.push_back(3);
//
//  stack_b.swap(stack_a);
//  std_stack_b.swap(std_stack_a);
//
//  //  EXPECT_TRUE(stack_b.size() == std_stack_b.size()); // SEG
//  //  long double a = stack_b.size();
//  //  printf("HUI:%Lf\n", a);
//  //  EXPECT_TRUE(stack_b.size() == 5);
//  //
//  //  for (int i = 0; itr_b != stack_b.end() && std_itr_b != std_stack_b.end();
//  //       ++itr_b, ++std_itr_b, ++i) {
//  //    EXPECT_TRUE(*itr_b == *std_itr_b);
//  //    EXPECT_TRUE(*itr_b == temp[i]);
//  //  }
//}
//
//int main(int argc, char **argv) {
//  ::testing::InitGoogleTest(&argc, argv);
//  return RUN_ALL_TESTS();
//}