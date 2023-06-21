#include "s21_vector.cc"

#include <vector>

#include "gtest/gtest.h"

// BLOCK: CONSTRUCTORS (MEMBER FUNCTIONS)

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
  std::vector<int> std_b(5);

  int* std_b_data = std_b.data();
  for (long unsigned int i = 0; i < std_b.size(); ++i) std_b_data[i] = i + 10;
  std::vector<int> std_a(std_b);

  s21_b.filling();
  s21::vector<int> s21_a(s21_b);

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_a.capacity() == std_a.capacity());
  EXPECT_TRUE(s21_b.empty() == std_b.empty());
  EXPECT_TRUE(s21_b.size() == std_b.size());
  EXPECT_TRUE(s21_b.capacity() == std_b.capacity());

  std::vector<int>::iterator std_itr = std_a.begin();
  s21::vector<int>::iterator s21_itr = s21_a.begin();
  for (; s21_itr != s21_a.end() && std_itr != std_a.end();
       ++s21_itr, ++std_itr) {
    EXPECT_TRUE(*s21_itr == *std_itr);
  }
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
}

TEST(initializer_list_suite, filled_true_test) {
  s21::vector<int> s21_b = {1, 2, 3, 4, 5};
  s21::vector<int> s21_a(std::move(s21_b));

  std::vector<int> std_b = {1, 2, 3, 4, 5};
  std::vector<int> std_a(std::move(std_b));

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_a.capacity() == std_a.capacity());

  std::vector<int>::iterator std_itr = std_a.begin();
  s21::vector<int>::iterator s21_itr = s21_a.begin();

  for (; s21_itr != s21_a.end() && std_itr != std_a.end();
       ++s21_itr, ++std_itr) {
    EXPECT_TRUE(*s21_itr == *std_itr);
  }
}

TEST(move_operator_constructor_suite, float_true_test) {
  s21::vector<float> s21_a({1, 2, 3});
  s21::vector<float> s21_b;
  s21_b = std::move(s21_a);
  std::vector<float> std_a({1, 2, 3});
  std::vector<float> std_b;
  std_b = std::move(std_a);

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_b.empty() == std_b.empty());
  EXPECT_TRUE(s21_b.size() == std_b.size());
}

TEST(initializer_list_suite_struct, filled_true_test) {
  struct test_struct {
    int a = 0;
    double b = 0;
    float c = 0;
  };
  test_struct s1 = {1, 1.9, 1e-8};
  test_struct s2 = {2, 2.9, 1e-9};
  test_struct s3 = {3, 3.9, 1e-10};

  s21::vector<test_struct> s21_a = {s1, s2, s3};

  std::vector<test_struct> std_a = {s1, s2, s3};

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_a.capacity() == std_a.capacity());

  std::vector<test_struct>::iterator std_itr = std_a.begin();
  s21::vector<test_struct>::iterator s21_itr = s21_a.begin();

  for (; s21_itr != s21_a.end() && std_itr != std_a.end();
       ++s21_itr, ++std_itr) {
    EXPECT_TRUE((*s21_itr).a == (*std_itr).a);
    EXPECT_TRUE((*s21_itr).b == (*std_itr).b);
    EXPECT_TRUE((*s21_itr).c == (*std_itr).c);
  }
}

TEST(assignment_operator, int_true_test) {
  struct test_struct {
    int a = 0;
    double b = 0;
    float c = 0;
  };
  test_struct s1 = {1, 1.9, 1e-8};
  test_struct s2 = {2, 2.9, 1e-9};
  test_struct s3 = {3, 3.9, 1e-10};

  s21::vector<test_struct> s21_b = {s1, s2, s3};
  s21::vector<test_struct> s21_a = std::move(s21_b);

  std::vector<test_struct> std_b = {s1, s2, s3};
  std::vector<test_struct> std_a = std::move(std_b);

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_a.capacity() == std_a.capacity());

  std::vector<test_struct>::iterator std_itr = std_a.begin();
  s21::vector<test_struct>::iterator s21_itr = s21_a.begin();

  for (; s21_itr != s21_a.end() && std_itr != std_a.end();
       ++s21_itr, ++std_itr) {
    EXPECT_TRUE((*s21_itr).a == (*std_itr).a);
    EXPECT_TRUE((*s21_itr).b == (*std_itr).b);
    EXPECT_TRUE((*s21_itr).c == (*std_itr).c);
  }
}

TEST(move_constructor_suite, double_true_test) {
  s21::vector<double> s21_b(5);
  s21::vector<double> s21_a(std::move(s21_b));
  std::vector<double> std_b(5);
  std::vector<double> std_a(std::move(std_b));

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_a.capacity() == std_a.capacity());
}

TEST(move_constructor_suite, float_true_test) {
  s21::vector<float> s21_b(5);
  s21::vector<float> s21_a(std::move(s21_b));
  std::vector<float> std_b(5);
  std::vector<float> std_a(std::move(std_b));

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_a.capacity() == std_a.capacity());
}

TEST(move_constructor_suite, struct_true_test) {
  struct test_struct {
    int a;
    double b;
    float c;
  };

  s21::vector<test_struct> s21_b(5);
  s21::vector<test_struct> s21_a(std::move(s21_b));
  std::vector<test_struct> std_b(5);
  std::vector<test_struct> std_a(std::move(std_b));

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_a.capacity() == std_a.capacity());
}

TEST(shrink_to_fit_suite, int_true_test) {
  s21::vector<int> s21_a;
  s21_a.push_back(1);
  s21_a.push_back(2);
  s21_a.push_back(3);
  s21_a.push_back(4);
  s21_a.push_back(5);

  std::vector<int> std_a;
  std_a.push_back(1);
  std_a.push_back(2);
  std_a.push_back(3);
  std_a.push_back(4);
  std_a.push_back(5);

  EXPECT_FALSE(s21_a.capacity() == s21_a.size());
  s21_a.shrink_to_fit();
  std_a.shrink_to_fit();

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_a.capacity() == std_a.capacity());

  std::vector<int>::iterator std_itr = std_a.begin();
  s21::vector<int>::iterator s21_itr = s21_a.begin();

  for (; s21_itr != s21_a.end() && std_itr != std_a.end();
       ++s21_itr, ++std_itr) {
    EXPECT_TRUE(*s21_itr == *std_itr);
  }
}

TEST(shrink_to_fit_suite, struct_true_test) {
  struct test_struct {
    int a = 0;
    double b = 0;
    float c = 0;
  };
  test_struct s1 = {1, 1.9, 1e-8};
  test_struct s2 = {2, 2.9, 1e-9};
  test_struct s3 = {3, 3.9, 1e-10};

  s21::vector<test_struct> s21_a;
  s21_a.push_back(s1);
  s21_a.push_back(s2);
  s21_a.push_back(s3);

  std::vector<test_struct> std_a;
  std_a.push_back(s1);
  std_a.push_back(s2);
  std_a.push_back(s3);

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_a.capacity() == std_a.capacity());

  std::vector<test_struct>::iterator std_itr = std_a.begin();
  s21::vector<test_struct>::iterator s21_itr = s21_a.begin();

  for (; s21_itr != s21_a.end() && std_itr != std_a.end();
       ++s21_itr, ++std_itr) {
    EXPECT_TRUE((*s21_itr).a == (*std_itr).a);
    EXPECT_TRUE((*s21_itr).b == (*std_itr).b);
    EXPECT_TRUE((*s21_itr).c == (*std_itr).c);
  }
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

TEST(iterator_begin, elem_after_pop_test) {
  s21::vector<int> s21_a;
  std::vector<int> std_a;
  s21::vector<int>::iterator s21_itr;
  std::vector<int>::iterator std_itr;

  s21_a.push_back(21);
  std_a.push_back(21);
  s21_a.pop_back();
  std_a.pop_back();

  s21_itr = s21_a.begin();
  std_itr = std_a.begin();

  EXPECT_TRUE(*s21_itr == *std_itr);
}

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

TEST(front_suite, swap_test) {
  s21::vector<int> s21_a({1, 2, 3, 4, 5});
  s21::vector<int> s21_b({6});
  std::vector<int> std_a({1, 2, 3, 4, 5});
  std::vector<int> std_b({6});

  s21_a.swap(s21_b);
  std_a.swap(std_b);

  EXPECT_TRUE(s21_a.front() == std_a.front());
  EXPECT_TRUE(s21_b.front() == std_b.front());
}

TEST(test_reserve, true_test) {
  s21::vector<int> v = {1, 2, 3};
  v.reserve(10);
  std::vector<int> std_v = {1, 2, 3};
  std_v.reserve(10);
  EXPECT_TRUE(v.capacity() == std_v.capacity());

  s21::vector<float> f = {2.5f, 3.6f, 4.7f};
  std::vector<float> std_f = {2.5f, 3.6f, 4.7f};
  EXPECT_TRUE(f.capacity() == std_f.capacity());
  f.reserve(20);
  std_f.reserve(20);
  EXPECT_TRUE(f.capacity() == std_f.capacity());
}

TEST(test_back, true_test) {
  s21::vector<int> v = {1, 2, 3};
  std::vector<int> std_v = {1, 2, 3};

  EXPECT_TRUE(v.back() == std_v.back());

  s21::vector<double> nums = {1.2, 3.4, 5.6, 7.8};
  std::vector<double> std_nums = {1.2, 3.4, 5.6, 7.8};
  EXPECT_TRUE(nums.back() == std_nums.back());
}

TEST(data_test, true_test) {
  s21::vector<int> c = {1, 2, 3};
  EXPECT_TRUE(&c[0] == c.data());
}

TEST(vector_test, access_in_range) {
  s21::vector<int> v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  EXPECT_EQ(v.at(0), std_v.at(0));
}

TEST(VectorTest, TestInsert) {
  s21::vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(4);
  std::vector<int> std_vec;
  std_vec.push_back(1);
  std_vec.push_back(2);
  std_vec.push_back(4);

  // Insert value in the middle of vector
  auto it = vec.insert(vec.begin() + 2, 3);
  auto std_it = std_vec.insert(std_vec.begin() + 2, 3);

  EXPECT_EQ(vec.size(), std_vec.size());
  EXPECT_EQ(*it, *std_it);
  EXPECT_EQ(vec[2], std_vec[2]);

  // Insert value before the beginning of vector
  it = vec.insert(vec.begin(), 0);
  std_it = std_vec.insert(std_vec.begin(), 0);
  EXPECT_EQ(vec.size(), std_vec.size());
  EXPECT_EQ(*it, *std_it);
  EXPECT_EQ(vec[0], std_vec[0]);

  // Insert value after the end of vector
  it = vec.insert(vec.end(), 5);
  std_it = std_vec.insert(std_vec.end(), 5);

  EXPECT_EQ(vec.size(), std_vec.size());
  EXPECT_EQ(*it, *std_it);
  EXPECT_EQ(vec[5], std_vec[5]);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}