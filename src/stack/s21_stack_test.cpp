#include "s21_stack.cpp"

#include <stack>

#include "gtest/gtest.h"

// BLOCK: FUNCTIONS
TEST(default_constructor_suite, int_true_test) {
  s21::stack<int> s21_a;
  std::stack<int> std_a;

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
}

TEST(default_constructor_suite, double_true_test) {
  s21::stack<double> s21_a;
  std::stack<double> std_a;

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
}

TEST(default_constructor_suite, float_true_test) {
  s21::stack<float> s21_a;
  std::stack<float> std_a;

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
}

TEST(default_constructor_suite, struct_true_test) {
  struct test_struct {
    int a;
    double b;
    float c;
  };

  s21::stack<test_struct> s21_a;
  std::stack<test_struct> std_a;

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
}

TEST(initializer_constructor_suite, int_true_test) {
  s21::stack<int> s21_a({1, 2, 3, 4, 5});
  std::stack<int> std_a({1, 2, 3, 4, 5});

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_a.top() == std_a.top());
}

TEST(initializer_constructor_suite, double_true_test) {
  s21::stack<double> s21_a({1, 2, 3, 4, 5});
  std::stack<double> std_a({1, 2, 3, 4, 5});

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_a.top() == std_a.top());
}

TEST(initializer_constructor_suite, float_true_test) {
  s21::stack<float> s21_a({1, 2, 3, 4, 5});
  std::stack<float> std_a({1, 2, 3, 4, 5});

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_a.top() == std_a.top());
}

TEST(initializer_constructor_suite, struct_true_test) {
  struct test_struct {
    int a;
    double b;
    float c;
  };
  test_struct a{}, b{}, c{}, d{}, e{};
  s21::stack<test_struct> s21_a({a, b, c, d, e});
  std::stack<test_struct> std_a({a, b, c, d, e});

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
}

TEST(copy_constructor_suite, int_true_test) {
  s21::stack<int> s21_b({1, 2, 3, 4, 5});
  s21::stack<int> s21_a(s21_b);
  std::stack<int> std_b({1, 2, 3, 4, 5});
  std::stack<int> std_a(std_b);

    EXPECT_TRUE(s21_a.empty() == std_a.empty());
    EXPECT_TRUE(s21_a.size() == std_a.size());
    EXPECT_TRUE(s21_a.top() == std_a.top());

    EXPECT_TRUE(s21_b.empty() == std_b.empty());
    EXPECT_TRUE(s21_b.size() == std_b.size());
    EXPECT_TRUE(s21_b.top() == std_b.top());
}

TEST(copy_constructor_suite, double_true_test) {
  s21::stack<double> s21_b({1, 2, 3, 4, 5});
  s21::stack<double> s21_a(s21_b);
  std::stack<double> std_b({1, 2, 3, 4, 5});
  std::stack<double> std_a(std_b);

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());

  EXPECT_TRUE(s21_b.empty() == std_b.empty());
  EXPECT_TRUE(s21_b.size() == std_b.size());
}

TEST(copy_constructor_suite, float_true_test) {
  s21::stack<float> s21_b({1, 2, 3, 4, 5});
  s21::stack<float> s21_a(s21_b);
  std::stack<float> std_b({1, 2, 3, 4, 5});
  std::stack<float> std_a(std_b);

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
  test_struct a{}, b{}, c{}, d{}, e{};
  s21::stack<test_struct> s21_a({a, b, c, d, e});
  std::stack<test_struct> std_a({a, b, c, d, e});
  s21::stack<test_struct> s21_b(s21_a);
  std::stack<test_struct> std_b(std_a);

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_b.empty() == std_b.empty());
  EXPECT_TRUE(s21_b.size() == std_b.size());
}

TEST(move_constructor_suite, int_true_test) {
  s21::stack<int> s21_a({1, 2, 3});
  s21::stack<int> s21_b(std::move(s21_a));
  std::stack<int> std_a({1, 2, 3});
  std::stack<int> std_b(std::move(std_a));

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_b.top() == std_b.top());
  EXPECT_TRUE(s21_b.empty() == std_b.empty());
  EXPECT_TRUE(s21_b.size() == std_b.size());
}

TEST(move_constructor_suite, double_true_test) {
  s21::stack<double> s21_a({1, 2, 3});
  s21::stack<double> s21_b(std::move(s21_a));
  std::stack<double> std_a({1, 2, 3});
  std::stack<double> std_b(std::move(std_a));

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_b.empty() == std_b.empty());
  EXPECT_TRUE(s21_b.size() == std_b.size());
}

TEST(move_constructor_suite, flaot_true_test) {
  s21::stack<float> s21_a({1, 2, 3});
  s21::stack<float> s21_b(std::move(s21_a));
  std::stack<float> std_a({1, 2, 3});
  std::stack<float> std_b(std::move(std_a));

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
  s21::stack<test_struct> s21_a({a, b, c, d, e});
  s21::stack<test_struct> s21_b(std::move(s21_a));
  std::stack<test_struct> std_a({a, b, c, d, e});
  std::stack<test_struct> std_b(std::move(std_a));

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_b.empty() == std_b.empty());
  EXPECT_TRUE(s21_b.size() == std_b.size());
}

TEST(move_operator_constructor_suite, int_true_test) {
  s21::stack<int> s21_a({1, 2, 3});
  s21::stack<int> s21_b = s21_a;
  std::stack<int> std_a({1, 2, 3});
  std::stack<int> std_b = std_a;

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_b.empty() == std_b.empty());
  EXPECT_TRUE(s21_b.size() == std_b.size());
}

TEST(move_operator_constructor_suite, double_true_test) {
  s21::stack<double> s21_a({1, 2, 3});
  s21::stack<double> s21_b = s21_a;
  std::stack<double> std_a({1, 2, 3});
  std::stack<double> std_b = std_a;

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_b.empty() == std_b.empty());
  EXPECT_TRUE(s21_b.size() == std_b.size());
}

TEST(move_operator_constructor_suite, flaot_true_test) {
  s21::stack<float> s21_a({1, 2, 3});
  s21::stack<float> s21_b = s21_a;
  std::stack<float> std_a({1, 2, 3});
  std::stack<float> std_b = std_a;

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
  s21::stack<test_struct> s21_a({a, b, c, d, e});
  s21::stack<test_struct> s21_b = s21_a;
  std::stack<test_struct> std_a({a, b, c, d, e});
  std::stack<test_struct> std_b = std_a;

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_b.empty() == std_b.empty());
  EXPECT_TRUE(s21_b.size() == std_b.size());
}

// BLOCK: ELEMENT ACCESS
TEST(top_suite, true_test) {
  s21::stack<int> s21_a({1, 2, 3, 4, 5});
  std::stack<int> std_a({1, 2, 3, 4, 5});

  EXPECT_TRUE(s21_a.top() == std_a.top());
}

TEST(top_suite, pop_test) {
  s21::stack<int> s21_a({1, 2, 3, 4, 5});
  std::stack<int> std_a({1, 2, 3, 4, 5});

  s21_a.pop();
  std_a.pop();

  EXPECT_TRUE(s21_a.top() == std_a.top());
}

TEST(top_suite, push_test) {
  s21::stack<int> s21_a({1, 2, 3, 4, 5});
  std::stack<int> std_a({1, 2, 3, 4, 5});

  s21_a.push(6);
  std_a.push(6);

  EXPECT_TRUE(s21_a.top() == std_a.top());
}

TEST(top_suite, swap_test) {
  s21::stack<int> s21_a({1, 2, 3, 4, 5});
  s21::stack<int> s21_b({6});
  std::stack<int> std_a({1, 2, 3, 4, 5});
  std::stack<int> std_b({6});

  s21_a.swap(s21_b);
  std_a.swap(std_b);

  EXPECT_TRUE(s21_a.top() == std_a.top());
  EXPECT_TRUE(s21_b.top() == std_b.top());
}

// BLOCK: CAPACITY
TEST(empty_suite, true_test) {
  s21::stack<int> s21_a({1, 2, 3, 4, 5});
  s21::stack<int> s21_b;
  std::stack<int> std_a({1, 2, 3, 4, 5});
  std::stack<int> std_b;

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_b.empty() == std_b.empty());
}

TEST(empty_suite, push_test) {
  s21::stack<int> s21_a;
  std::stack<int> std_a;

  s21_a.push(21);
  std_a.push(21);

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
}

TEST(empty_suite, pop_test) {
  s21::stack<int> s21_a({1});
  std::stack<int> std_a({1});

  s21_a.pop();
  std_a.pop();

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
}

TEST(empty_suite, swap_test) {
  s21::stack<int> s21_a({1, 2, 3, 4, 5});
  s21::stack<int> s21_b;
  std::stack<int> std_a({1, 2, 3, 4, 5});
  std::stack<int> std_b;

  s21_a.swap(s21_b);
  std_a.swap(std_b);

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_b.empty() == std_b.empty());
}

TEST(size_suite, true_test) {
  s21::stack<int> s21_a({1, 2, 3, 4, 5});
  s21::stack<int> s21_b;
  std::stack<int> std_a({1, 2, 3, 4, 5});
  std::stack<int> std_b;

  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_b.size() == std_b.size());
}

TEST(size_suite, push_test) {
  s21::stack<int> s21_a;
  std::stack<int> std_a;

  s21_a.push(21);
  std_a.push(21);

  EXPECT_TRUE(s21_a.size() == std_a.size());
}

TEST(size_suite, pop_test) {
  s21::stack<int> s21_a({1});
  std::stack<int> std_a({1});

  s21_a.pop();
  std_a.pop();

  EXPECT_TRUE(s21_a.size() == std_a.size());
}

TEST(size_suite, swap_test) {
  s21::stack<int> s21_a({1, 2, 3, 4, 5});
  s21::stack<int> s21_b;
  std::stack<int> std_a({1, 2, 3, 4, 5});
  std::stack<int> std_b;

  s21_a.swap(s21_b);
  std_a.swap(std_b);

  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_b.size() == std_b.size());
}

// BLOCK: MODIFIERS
TEST(push_suite, true_test) {
  s21::stack<int> s21_a({1, 2, 3, 4});
  std::stack<int> std_a({1, 2, 3, 4});

  s21_a.push(5);
  std_a.push(5);

  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_a.top() == std_a.top());
}

TEST(pop_suite, true_test) {
  s21::stack<int> s21_a({1, 2, 3, 4});
  std::stack<int> std_a({1, 2, 3, 4});

  s21_a.pop();
  std_a.pop();

  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_a.top() == std_a.top());
}

TEST(swap_suite, true_test) {
  s21::stack<int> s21_a({1, 2, 3, 4, 5});
  s21::stack<int> s21_b({6});
  std::stack<int> std_a({1, 2, 3, 4, 5});
  std::stack<int> std_b({6});

  s21_a.swap(s21_b);
  std_a.swap(std_b);

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_a.top() == std_a.top());
  EXPECT_TRUE(s21_b.size() == std_b.size());
  EXPECT_TRUE(s21_b.top() == std_b.top());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
