#include <cstring>
#include <initializer_list>
#include <iostream>

#include "cstdio"

namespace s21 {
template <class T>
class vector {
 public:
  // Members type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  // Constructors
  vector();
  vector(size_type n);
  vector(std::initializer_list<value_type> const &items);
  vector(const vector &v);
  vector(vector &&v) noexcept;
  ~vector();

  // Overload operators
  vector &operator=(vector &&v) noexcept;

  // Element access
  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference front();
  const_reference back();
  iterator data();

  // Iterators
  iterator begin() const;
  iterator end() const;

  // Capacity
  bool empty();
  size_type size();
  size_type max_size();
  void reserve(size_type size);
  size_type capacity();
  void shrink_to_fit();

  // Modifiers
  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(vector &other);

  // Additional
  void filling();

 private:
  T *begin_ = nullptr;
  size_t size_ = 0;
  size_t capacity_ = 0;

  // Additional
  void reallocator();
};

}  // namespace s21