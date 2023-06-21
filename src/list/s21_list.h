#ifndef CPP2_CONTAINERS_LIST_S21_LIST_H_
#define CPP2_CONTAINERS_LIST_S21_LIST_H_

#include <iostream>
#include <limits>

namespace s21 {
template <class T>
class list {
 public:
  // Members type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  class ListIterator;
  using iterator = ListIterator;
  using const_iterator = ListIterator;

  // Constructors
  list();
  list(size_type n);
  list(std::initializer_list<value_type> const &items);
  list(const list &l);
  list(list &&l);
  ~list();

  // Overload operators
  list operator=(list &&l);

  // Element access
  const_reference front() const;
  const_reference back() const;

  // Iterators
  iterator begin() const;
  iterator end() const;

  // Capacity
  bool empty() const;
  size_type size() const;
  size_type max_size() const;

  // Modifiers
  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list &other);
  void merge(list &other);
  void splice(const_iterator pos, list &other);
  void unique();
  void reverse();
  void sort();

  // Additional
  void MoveList(list &l);

 private:
  struct node_ {
    value_type value_;
    node_ *next_ = nullptr;
    node_ *previous_ = nullptr;
  };
  node_ *head_ = nullptr;
  node_ *tail_ = nullptr;
  node_ *end_node_ = nullptr;
  size_type size_ = 0;
};

// Nested class
template <class T>
class list<T>::ListIterator {
  friend class list<T>;

 public:
  void operator=(node_ &other);
  T &operator*();
  void operator++();
  void operator++(int);
  void operator--();
  void operator--(int);
  bool operator==(s21::list<T>::ListIterator iterator);
  bool operator!=(s21::list<T>::ListIterator iterator);

 private:
  value_type value_ = value_type();
  node_ *itr_node_ = nullptr;
};
}  // namespace s21

#endif  // CPP2_CONTAINERS_LIST_S21_LIST_H_
