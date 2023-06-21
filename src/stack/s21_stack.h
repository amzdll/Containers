#ifndef CPP2_CONTAINERS_STACK_S21_STACK_H_
#define CPP2_CONTAINERS_STACK_S21_STACK_H_

#include <iostream>

#include "../list/s21_list.cc"

namespace s21 {
template <class T>
class stack : public list<T> {
 public:
  // Members type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  // Constructors
  stack();
  stack(size_type n);
  stack(std::initializer_list<value_type> const &items);
  stack(const stack &s);
  stack(stack &&s);
  ~stack();

  // Overload operators
  stack operator=(stack &&s);

  // Element access
  const_reference top() const;

  // Modifiers
  void push(const_reference value);
  void pop();
};
}  // namespace s21

#endif  // CPP2_CONTAINERS_STACK_S21_STACK_H_
