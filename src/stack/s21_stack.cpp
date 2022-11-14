#include "s21_stack.h"
template <class T>
s21::stack<T>::stack() {
  head_ = NULL;
  tail_ = NULL;
}

//template <class T>
//s21::stack<T>::stack(const std::initializer_list<value_type>& items) {}

template <class T>
s21::stack<T>::stack(stack&& s) {}

template <class T>
s21::stack<T>::~stack() {}

template <class T>
int s21::stack<T>::operator=(stack&& s) { return 0; }

template <class T>
const_reference s21::stack<T>::top() { return nullptr; }

template <class T>
bool s21::stack<T>::empty() { return false; }

template <class T>
size_t s21::stack<T>::size() { return nullptr; }

template <class T>
void s21::stack<T>::push(const_reference value) {
  node_* new_node = new node_;
  new_node->next_ = head_;
  new_node->value_ = value;
  head_ = new_node;
}

template <class T>
void s21::stack<T>::pop() {}

template <class T>
void s21::stack<T>::swap(s21::stack& other) {}



// template methods
template <class T>
void s21::stack<T>::print() {
  while(head_) {
    printf("%d", this->head_->value_);
  }
}

