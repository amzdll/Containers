#include "s21_stack.h"

#include <iostream>

namespace s21 {
template <class T>
s21::stack<T>::stack() {
  head_ = NULL;
  tail_ = NULL;
  count_ = 0;
}

template <class T>
s21::stack<T>::stack(const std::initializer_list<value_type>& items) {
  count_ = 0;
  if (items.size()) {
    auto itr = items.begin();
    while (itr != items.end()) {
      push(*itr);
      ++itr;
    }
  }
}

template <class T>
stack<T>::stack(const stack& s) {
  node_* temp_node = s.tail_;
  while (temp_node) {
    this->push(temp_node->value_);
    temp_node = temp_node->prev_;
  }
}

template <class T>
s21::stack<T>::stack(stack&& s) {
  head_ = s.head_;
  tail_ = s.tail_;
  count_ = s.count_;

  s.head_ = NULL;
  s.tail_ = NULL;
  s.count_ = 0;
}

template <class T>
s21::stack<T>::~stack() {
  while (!empty()) {
    pop();
  }
}

template <class T>
typename s21::stack<T> s21::stack<T>::operator=(stack&& s) {
  head_ = s.head_;
  tail_ = s.tail_;
  count_ = s.count_;

  s.head_ = NULL;
  s.tail_ = NULL;
  s.count_ = 0;
}

template <class T>
const T& s21::stack<T>::top() {
  return head_->value_;
}

template <class T>
bool s21::stack<T>::empty() {
  return !size();
}

template <class T>
size_t s21::stack<T>::size() {
  return count_;
}

template <class T>
void s21::stack<T>::push(const_reference value) {
  node_* new_node = new node_;
  new_node->prev_ = NULL;
  new_node->value_ = value;
  if (!head_) {
    tail_ = new_node;
  } else {
    new_node->next_ = head_;
    head_->prev_ = new_node;
  }
  head_ = new_node;
  count_++;
}

template <class T>
void s21::stack<T>::pop() {
  if (head_) {
    node_* deletable_node = head_;
    head_ = head_->next_;
    delete deletable_node;
    --count_;
  }
}

template <class T>
void s21::stack<T>::swap(stack& other) {
  node_* temp_head = head_;
  node_* temp_tail = tail_;
  size_t temp_count = count_;

  head_ = other.head_;
  tail_ = other.tail_;
  count_ = other.count_;

  other.head_ = temp_head;
  other.tail_ = temp_tail;
  other.count_ = temp_count;
}
}  // namespace s21