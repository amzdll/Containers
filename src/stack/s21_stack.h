#ifndef CPP2_S21_CONTAINERS_STACK_S21_STACK_H_
#define CPP2_S21_CONTAINERS_STACK_S21_STACK_H_

#include <initializer_list>

#include "cstdio"

namespace s21 {
template <class T>
class stack {
 private:
  struct node_ {
    node_ *next_;
    node_ *prev_;
    T value_ = T();
  };

  node_ *head_ = NULL;
  node_ *tail_ = NULL;
  size_t count_ = 0;

 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  stack();
  stack(std::initializer_list<value_type> const &items);
  stack(const stack &s);
  stack(stack &&s);
  ~stack();
  stack operator=(stack &&s);

  const_reference top();

  bool empty();
  size_type size();

  void push(const_reference value);
  void pop();
  void swap(stack &other);

  void print();
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_STACK_S21_STACK_H_
