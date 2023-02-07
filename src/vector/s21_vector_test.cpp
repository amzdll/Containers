#include <vector>

#include "gtest/gtest.h"
// refactor: cpp to h
#include "s21_vector.cpp"

// BLOCK: CONSTRUCTORS
TEST(default_constructor_suite, int_true_test) {
  s21::vector<int> s21_a;
  std::vector<int> std_a;

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_a.capacity() == std_a.capacity());
}

TEST(default_constructor_suite, double_true_test) {
  s21::vector<double> s21_a;
  std::vector<double> std_a;

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_a.capacity() == std_a.capacity());
}

TEST(default_constructor_suite, float_true_test) {
  s21::vector<float> s21_a;
  std::vector<float> std_a;

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_a.capacity() == std_a.capacity());
}

TEST(default_constructor_suite, struct_true_test) {
  struct test_struct {
    int a;
    double b;
    float c;
  };

  s21::vector<test_struct> s21_a;
  std::vector<test_struct> std_a;

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_a.capacity() == std_a.capacity());
}

TEST(parameterized_constructor_suite, int_true_test) {
  s21::vector<int> s21_a(5);
  std::vector<int> std_a(5);

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_a.capacity() == std_a.capacity());
}

TEST(parameterized_constructor_suite, double_true_test) {
  s21::vector<double> s21_a(5);
  std::vector<double> std_a(5);

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_a.capacity() == std_a.capacity());
}

TEST(parameterized_constructor_suite, float_true_test) {
  s21::vector<float> s21_a(5);
  std::vector<float> std_a(5);

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_a.capacity() == std_a.capacity());
}

TEST(parameterized_constructor_suite, struct_true_test) {
  struct test_struct {
    int a;
    double b;
    float c;
  };

  s21::vector<test_struct> s21_a(5);
  std::vector<test_struct> std_a(5);

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_a.capacity() == std_a.capacity());
}

TEST(copy_constructor_suite, int_true_test) {
  s21::vector<int> s21_b(5);
  s21::vector<int> s21_a(s21_b);
  std::vector<int> std_b(5);
  std::vector<int> std_a(std_b);

  s21_b.filling();
  s21_b.print();
  s21_a.print();


  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_a.capacity() == std_a.capacity());
  EXPECT_TRUE(s21_b.empty() == std_b.empty());
  EXPECT_TRUE(s21_b.size() == std_b.size());
  EXPECT_TRUE(s21_b.capacity() == std_b.capacity());
}

TEST(copy_constructor_suite, double_true_test) {
  s21::vector<double> s21_b(5);
  s21::vector<double> s21_a(s21_b);
  std::vector<double> std_b(5);
  std::vector<double> std_a(std_b);

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_a.capacity() == std_a.capacity());
  EXPECT_TRUE(s21_b.empty() == std_b.empty());
  EXPECT_TRUE(s21_b.size() == std_b.size());
  EXPECT_TRUE(s21_b.capacity() == std_b.capacity());
}

TEST(copy_constructor_suite, float_true_test) {
  s21::vector<float> s21_b(5);
  s21::vector<float> s21_a(s21_b);
  std::vector<float> std_b(5);
  std::vector<float> std_a(std_b);

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_a.capacity() == std_a.capacity());
  EXPECT_TRUE(s21_b.empty() == std_b.empty());
  EXPECT_TRUE(s21_b.size() == std_b.size());
  EXPECT_TRUE(s21_b.capacity() == std_b.capacity());
}

TEST(copy_constructor_suite, struct_true_test) {
  struct test_struct {
    int a;
    double b;
    float c;
  };

  s21::vector<test_struct> s21_b(5);
  s21::vector<test_struct> s21_a(s21_b);
  std::vector<test_struct> std_b(5);
  std::vector<test_struct> std_a(std_b);

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_a.capacity() == std_a.capacity());
  EXPECT_TRUE(s21_b.empty() == std_b.empty());
  EXPECT_TRUE(s21_b.size() == std_b.size());
  EXPECT_TRUE(s21_b.capacity() == std_b.capacity());
}

TEST(move_constructor_suite, int_true_test) {
  s21::vector<int> s21_b(5);
  s21::vector<int> s21_a(std::move(s21_b));
  std::vector<int> std_b(5);
  std::vector<int> std_a(std::move(std_b));

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_a.capacity() == std_a.capacity());
  //  EXPECT_TRUE(s21_b.empty() == std_b.empty());
  //  EXPECT_TRUE(s21_b.size() == std_b.size());
  //  EXPECT_TRUE(s21_b.capacity() == std_b.capacity());
}

//  BLOCK: ITERATORS
TEST(iterator_begin, true_test) {
  s21::vector<int> s21_a;
  std::vector<int> std_a;
  s21::vector<int>::iterator s21_itr;
  std::vector<int>::iterator std_itr;

  s21_a.push_back(21);
  std_a.push_back(21);

  s21_itr = s21_a.begin();
  std_itr = std_a.begin();

  EXPECT_TRUE(*s21_itr == *std_itr);
}


// refactor: need pop
//TEST(iterator_begin, elem_after_pop_test) {
//  s21::vector<int> s21_a;
//  std::vector<int> std_a;
//  s21::vector<int>::iterator s21_itr;
//  std::vector<int>::iterator std_itr;
//
//  s21_a.push_back(21);
//  std_a.push_back(21);
//  s21_a.pop_back();
//  std_a.pop_back();
//
//  s21_itr = s21_a.begin();
//  std_itr = std_a.begin();
//  printf("\n%d\t%d\n",*s21_itr,  *std_itr );
//  EXPECT_TRUE(*s21_itr == *std_itr);
//}


// TEST(move_constructor_suite, double_true_test) {
//   s21::vector<double> s21_b(5);
//   s21::vector<double> s21_a(std::move(s21_b));
//   std::vector<double> std_b(5);
//   std::vector<double> std_a(std::move(std_b));
//
//   EXPECT_TRUE(s21_a.empty() == std_a.empty());
//   EXPECT_TRUE(s21_a.size() == std_a.size());
//   EXPECT_TRUE(s21_a.capacity() == std_a.capacity());
////  EXPECT_TRUE(s21_b.empty() == std_b.empty());
////  EXPECT_TRUE(s21_b.size() == std_b.size());
////  EXPECT_TRUE(s21_b.capacity() == std_b.capacity());
//}
//
// TEST(move_constructor_suite, float_true_test) {
//  s21::vector<float> s21_b(5);
//  s21::vector<float> s21_a(std::move(s21_b));
//  std::vector<float> std_b(5);
//  std::vector<float> std_a(std::move(std_b));
//
//  EXPECT_TRUE(s21_a.empty() == std_a.empty());
//  EXPECT_TRUE(s21_a.size() == std_a.size());
//  EXPECT_TRUE(s21_a.capacity() == std_a.capacity());
////  EXPECT_TRUE(s21_b.empty() == std_b.empty());
////  EXPECT_TRUE(s21_b.size() == std_b.size());
////  EXPECT_TRUE(s21_b.capacity() == std_b.capacity());
//}
//
// TEST(move_constructor_suite, struct_true_test) {
//  struct test_struct {
//    int a;
//    double b;
//    float c;
//  };
//
//  s21::vector<test_struct> s21_b(5);
//  s21::vector<test_struct> s21_a(std::move(s21_b));
//  std::vector<test_struct> std_b(5);
//  std::vector<test_struct> std_a(std::move(std_b));
//
//  EXPECT_TRUE(s21_a.empty() == std_a.empty());
//  EXPECT_TRUE(s21_a.size() == std_a.size());
//  EXPECT_TRUE(s21_a.capacity() == std_a.capacity());
//  EXPECT_TRUE(s21_b.empty() == std_b.empty());
//  EXPECT_TRUE(s21_b.size() == std_b.size());
//  EXPECT_TRUE(s21_b.capacity() == std_b.capacity());
//}

//

// BLOCK: CAPACITY
TEST(empty_suite, true_test) {
  s21::vector<int> s21_a;
  std::vector<int> std_a;

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
}

TEST(empty_suite, cleaned_test) {
  s21::vector<int> s21_a(5);
  std::vector<int> std_a(5);

  s21_a.clear();
  std_a.clear();

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
}

TEST(empty_suite, erased_test) {
  s21::vector<int> s21_a(1);
  s21::vector<int>::iterator s21_itr = s21_a.begin();
  std::vector<int> std_a(1);
  std::vector<int>::iterator std_itr = std_a.begin();

  s21_a.erase(s21_itr);
  std_a.erase(std_itr);

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
}

TEST(size_suite, empty_test) {
  s21::vector<int> s21_a;
  std::vector<int> std_a;

  EXPECT_TRUE(s21_a.size() == std_a.size());
}

TEST(size_suite, parameterized_test) {
  s21::vector<int> s21_a(5);
  std::vector<int> std_a(5);

  EXPECT_TRUE(s21_a.size() == std_a.size());
}

TEST(size_suite, push_test) {
  s21::vector<int> s21_a(5);
  std::vector<int> std_a(5);

  s21_a.push_back(5);
  std_a.push_back(5);

  EXPECT_TRUE(s21_a.size() == std_a.size());
}

TEST(size_suite, pop_test) {
  s21::vector<int> s21_a(5);
  std::vector<int> std_a(5);

  s21_a.pop_back();
  std_a.pop_back();

  EXPECT_TRUE(s21_a.size() == std_a.size());
}

TEST(capacity_suite, empty_test) {
  s21::vector<int> s21_a;
  std::vector<int> std_a;

  EXPECT_TRUE(s21_a.capacity() == std_a.capacity());
}

TEST(capacity_suite, parameterized_test) {
  s21::vector<int> s21_a(5);
  std::vector<int> std_a(5);

  EXPECT_TRUE(s21_a.capacity() == std_a.capacity());
}

TEST(capacity_suite, push_test) {
  s21::vector<int> s21_a(5);
  std::vector<int> std_a(5);

  s21_a.pop_back();
  std_a.pop_back();
  s21_a.push_back(5);
  std_a.push_back(5);

  EXPECT_TRUE(s21_a.capacity() == std_a.capacity());
}

TEST(capacity_suite, push_full_test) {
  s21::vector<int> s21_a(5);
  std::vector<int> std_a(5);

  s21_a.push_back(5);
  std_a.push_back(5);

  EXPECT_TRUE(s21_a.capacity() == std_a.capacity());
}

TEST(capacity_suite, pop_test) {
  s21::vector<int> s21_a(5);
  std::vector<int> std_a(5);

  s21_a.pop_back();
  std_a.pop_back();

  EXPECT_TRUE(s21_a.capacity() == std_a.capacity());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}