#include "s21_queue.h"

namespace s21 {
template <class T>
s21::queue<T>::queue() {
  head_ = new node_;
  tail_ = head_;
  head_->value_ = T();
  count_ = 0;
}

// refactor fix push
template <class T>
s21::queue<T>::queue(std::initializer_list<value_type> const& items) {
  head_ = NULL;
  tail_ = NULL;
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
queue<T>::queue(const queue& q) {
  head_ = NULL;
  tail_ = NULL;
  node_* temp_node = q.head_;
  while (temp_node) {
    this->push(temp_node->value_);
    temp_node = temp_node->next_;
  }
}

template <class T>
s21::queue<T>::queue(queue&& q) noexcept {
  head_ = q.head_;
  tail_ = q.tail_;
  count_ = q.count_;
  q.head_ = NULL;
  q.tail_ = NULL;
  q.count_ = 0;
}

template <class T>
s21::queue<T>::~queue() {
  node_* temp_node;
  while (!empty()) {
    temp_node = head_;
    head_ = head_->next_;
    --count_;
    delete temp_node;
  }
}

template <class T>
typename s21::queue<T> s21::queue<T>::operator=(queue&& q) {
  head_ = NULL;
  tail_ = NULL;
  node_* temp_node = q.head_;
  while (temp_node) {
    this->push(temp_node->value_);
    temp_node = temp_node->next_;
  }
  return 0;
}

template <class T>
const T& s21::queue<T>::front() {
  return head_->value_;
}

// refactor wtf?
template <class T>
const T& s21::queue<T>::back() {
  return tail_->prev_ ? tail_->prev_->value_ : tail_->value_;
}

template <class T>
bool s21::queue<T>::empty() {
  return head_ == tail_;
}

template <class T>
typename s21::queue<T>::size_type s21::queue<T>::size() {
  return count_;
}

template <class T>
void s21::queue<T>::push(const_reference value) {
  auto* new_node = new node_;
  new_node->value_ = value;
  new_node->next_ = NULL;
  if (!head_) {
    head_ = new_node;
    tail_ = head_;
  } else {
    tail_->next_ = new_node;
    tail_ = new_node;
  }
  ++count_;
}

template <class T>
void s21::queue<T>::pop() {
  node_* deletable_node = head_;
  if (head_ && head_ == tail_) {
    head_ = NULL;
    tail_ = NULL;
  } else if (head_) {
    head_ = head_->next_;
    //    head_->prev_ = NULL;
  }
  delete deletable_node;
  --count_;
}

template <class T>
void s21::queue<T>::swap(queue& other) {
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

template <class T>
void s21::queue<T>::print() {
  node_* temp_node = head_;
  printf("queue: ");
  while (temp_node) {
    printf("%d, ", temp_node->value_);
    temp_node = temp_node->next_;
  }
}
}  // namespace s21
