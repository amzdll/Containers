#include "s21_stack.h"

namespace s21 {
template <class T>
s21::stack<T>::stack() {
  head_ = NULL;
  tail_ = NULL;
}

// template <class T>
// s21::stack<T>::stack(const std::initializer_list<value_type>& items) {}

template <class T>
stack<T>::stack(const stack& s) {
  // refactor
  node_* temp_head;

  //  s21::stack<T> temp;
  //  while (temp_head) {
  //    temp.push(temp_head->value_);
  //    temp_head = temp_head -> next_;
  //  }
  //  while (temp.head_) {
  //    this->push(temp.head_->value_);
  //    temp.head_ = temp.head_->next_;
  //  }

  for (int i = 1; i < s.count_; ++i) {
    temp_head = s.head_;
    for (int j = i; j < s.count_; ++j) {
      temp_head = temp_head->next_;
    }
    this->push(temp_head->value_);
  }
  temp_head = s.head_;
  this->push(temp_head->value_);
}

template <class T>
s21::stack<T>::stack(stack&& s) {
  node_* temp_head;
  for (int i = 1; i < s.count_; ++i) {
    temp_head = s.head_;
    for (int j = i; j < s.count_; ++j) {
      temp_head = temp_head->next_;
    }
    this->push(temp_head->value_);
  }
  temp_head = s.head_;
  this->push(temp_head->value_);
  s.head_ = NULL;
}

template <class T>
s21::stack<T>::~stack() {
  while (head_) {
    this->pop();
  }
}

 template <class T>
 typename s21::stack<T> s21::stack<T>::operator=(stack&& s) {
   node_* temp_head;
   for (int i = 1; i < s.count_; ++i) {
     temp_head = s.head_;
     for (int j = i; j < s.count_; ++j) {
       temp_head = temp_head->next_;
     }
     this->push(temp_head->value_);
   }
   temp_head = s.head_;
   this->push(temp_head->value_);
   return head_;
 }

template <class T>
const T& s21::stack<T>::top() {
  return head_->value_;
}

template <class T>
bool s21::stack<T>::empty() {
  return !head_;
}

template <class T>
size_t s21::stack<T>::size() {
  return count_;
}

template <class T>
void s21::stack<T>::push(const_reference value) {
  node_* new_node = new node_;
  new_node->next_ = head_;
  new_node->value_ = value;
  head_ = new_node;
  ++count_;
}

template <class T>
void s21::stack<T>::pop() {
  node_* deletable_node = head_;
  if (head_) {
    head_ = head_->next_;
    --count_;
    delete deletable_node;
  }
}

template <class T>
void s21::stack<T>::swap(stack& other) {
  node_* temp_head = head_;
  head_ = other.head_;
  other.head_ = temp_head;
}

// template methods
template <class T>
void s21::stack<T>::print() {
  node_* temp_node = head_;
  while (temp_node) {
    printf("%d ", temp_node->value_);
    temp_node = temp_node->next_;
  }
  printf("\n");
}

}  // namespace s21