#include "s21_queue.h"

// Constructors
template <class T>
s21::queue<T>::queue() : list<T>() {}

template <class T>
s21::queue<T>::queue(size_type n) : list<T>(n) {}

template <class T>
s21::queue<T>::queue(std::initializer_list<value_type> const &items)
    : list<T>(items) {}

template <class T>
s21::queue<T>::queue(const queue &q) : list<T>(q) {}

template <class T>
s21::queue<T>::queue(queue &&q) : list<T>(std::move(q)) {}

template <class T>
s21::queue<T>::~queue() {}

// Overload operators
template <class T>
s21::queue<T> s21::queue<T>::operator=(queue &&q) {
  s21::list<T>::clear();
  s21::list<T>::MoveList(q);
  return *this;
}

// Modifiers
template <class T>
void s21::queue<T>::push(const_reference value) {
  s21::list<T>::push_back(value);
}

template <class T>
void s21::queue<T>::pop() {
  s21::list<T>::pop_front();
}
