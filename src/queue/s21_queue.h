#ifndef CPP2_S21_CONTAINERS_QUEUE_S21_QUEUE_H_
#define CPP2_S21_CONTAINERS_QUEUE_S21_QUEUE_H_

#include <cstdio>
#include <initializer_list>
namespace s21 {
template <class T>
class queue {
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

  queue();
  queue(std::initializer_list<value_type> const &items);
  queue(const queue &q);
  queue(queue &&q) noexcept;
  ~queue();
  queue operator=(queue &&q);

  const_reference front();
  const_reference back();

  bool empty();
  size_type size();

  void push(const_reference value);
  void pop();
  void swap(queue &other);
};

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_QUEUE_S21_QUEUE_H_
