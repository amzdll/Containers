#include "s21_list.h"

#include <initializer_list>
#include <iostream>

#include "cstring"

namespace s21 {
// block:  CONSTRUCTORS
template <class T>
list<T>::list() {}

template <class T>
list<T>::list(size_type n) {
  for (size_type i = 0; i < n; ++i) {
    push_back(T());
  }
}

template <class T>
list<T>::list(std::initializer_list<value_type> const &items) {
  if (items.size()) {
    auto itr = items.begin();
    while (itr != items.end()) {
      push_back(*itr);
      ++itr;
    }
  }
}

template <class T>
list<T>::list(const list &l) {
  node_ *temp_node = l.head_;
  while (temp_node != l.end_node_) {
    this->push_back(temp_node->value_);
    temp_node = temp_node->next_;
  }
}

template <class T>
list<T>::list(list &&l) {
  head_ = l.head_;
  tail_ = l.tail_;
  end_node_ = l.end_node_;
  count_ = l.count_;

  l.head_ = NULL;
  l.tail_ = NULL;
  l.end_node_ = NULL;
  l.count_ = 0;
}

template <class T>
s21::list<T> s21::list<T>::operator=(list &&l) {
  head_ = l.head_;
  tail_ = l.tail_;
  count_ = l.count_;
  end_node_ = l.end_node_;

  l.head_ = NULL;
  l.tail_ = NULL;
  l.end_node_ = NULL;
  l.count_ = 0;
}

template <class T>
list<T>::~list() {
  clear();
}

// block:ELEMENT ACCESS
template <class T>
const T &list<T>::front() {
  return head_->value_;
}

template <class T>
const T &list<T>::back() {
  return tail_->value_;
}

// block: CAPACITY
template <class T>
bool list<T>::empty() {
  return !count_;
}

template <class T>
size_t list<T>::size() {
  return count_;
}

template <class T>
size_t list<T>::max_size() {
  return 0;
}

// block: MODIFIERS
template <class T>
void list<T>::clear() {
  node_ *temp_node;
  while (head_ && head_ != end_node_) {
    temp_node = head_;
    head_ = head_->next_;
    count_--;
    delete temp_node;
  }
}

template <class T>
typename list<T>::iterator list<T>::insert(iterator pos,
                                           const_reference value) {
  if(!pos.itr_node_->prev_) {
    push_front(value);
  } else if (!pos.itr_node_->next_) {
    push_back(value);
  } else {
    node_ *new_node = new node_;
    new_node->prev_ = pos.itr_node_->prev_;
    new_node->next_ = pos.itr_node_;
    new_node->value_ = value;
    pos.itr_node_->prev_->next_ = new_node;
    pos.itr_node_->prev_ = new_node;
//    pos.itr_node_->next_->prev_ = new_node;
    ++count_;
  }
//  if (pos.itr_node_->prev_) {
//    new_node->prev_ = pos.itr_node_->prev_;
//    //    pos.itr_node_->prev_->next_ = new_node;
//  } else {
//    push_front(value);
//  }
//  new_node->value_ = value;
//  new_node->next_ = pos.itr_node_;
//  pos.itr_node_->prev_ = new_node;
  return pos;
}

template <class T>
void list<T>::erase(iterator pos) {
  // refactor: if to post.node == head_
  if (pos.node_->prev_) {
    pos.node_->prev_->next_ = pos.node_->next_;
  } else {
    head_ = pos.node_->next_;
  }
  // refactor: if to post.node == tail_
  if (pos.node_->next_) {
    pos.node_->next_->prev_ = pos.node_->prev_;
  } else {
    tail_ = pos.node_->prev_;
  }
  count_--;
  delete pos.node_;
}

template <class T>
void list<T>::push_back(const_reference value) {
  auto *new_node = new node_;
  new_node->next_ = end_node_;
  new_node->value_ = value;
  if (!head_) {
    head_ = new_node;
    tail_ = head_;
    end_node_->next_ = NULL;
  } else {
    new_node->prev_ = tail_;
    tail_->next_ = new_node;
    tail_ = new_node;
  }
  end_node_->prev_ = tail_;
  ++count_;
}

template <class T>
void list<T>::pop_back() {
  node_ *deletable_node = tail_;
  if (head_ != tail_) {
    tail_ = tail_->prev_;
    tail_->next_ = NULL;
  }
  delete deletable_node;
  count_--;
}

template <class T>
void list<T>::push_front(const_reference value) {
  node_ *new_node = new node_;
  if (!head_) {
    head_ = new_node;
    tail_ = head_;
  } else {
    new_node->next_ = head_;
    head_->prev_ = new_node;
    head_ = new_node;
  }
  new_node->prev_ = NULL;
  new_node->value_ = value;
  count_++;
}

template <class T>
void list<T>::pop_front() {
  node_ *temp_node = head_;
  if (head_ != tail_) {
    head_ = head_->next_;
    head_->prev_ = NULL;
  } else {
    head_ = NULL;
    tail_ = NULL;
  }
  delete temp_node;
  count_--;
}

template <class T>
void list<T>::swap(list &other) {
  node_ *temp_head = head_;
  node_ *temp_tail = tail_;
  node_ *temp_end_node = end_node_;
  size_t temp_count = count_;

  head_ = other.head_;
  tail_ = other.tail_;
  end_node_ = other.end_node_;
  count_ = other.count_;

  other.head_ = temp_head;
  other.tail_ = temp_tail;
  other.end_node_ = temp_end_node;
  other.count_ = temp_count;
}

template <class T>
void list<T>::merge(list &other) {
  if (tail_->value_ < other.head_->value_) {
    tail_->next_ = other.head_;
    tail_ = other.tail_;
  } else {
    other.tail_->next_ = head_;
    head_->prev_ = other.tail_;
    head_ = other.head_;
  }
  count_ += other.count_;
  other.head_ = NULL;
}

template <class T>
void list<T>::splice(iterator pos, list &other) {
  if (pos.node_ == head_) {
    head_ = other.head_;
  } else {
    pos.node_->prev_->next_ = other.head_;
  }
  other.tail_->next_ = pos.node_;
  pos.node_->prev_ = other.tail_;
  other.head_ = NULL;
}

template <class T>
void list<T>::reverse() {
  node_ *temp_tail = tail_;
  node_ *temp_head = head_;
  value_type temp_value;
  while (temp_head != temp_tail && temp_head->prev_ != temp_tail) {
    temp_value = temp_head->value_;
    temp_head->value_ = temp_tail->value_;
    temp_tail->value_ = temp_value;
    temp_tail = temp_tail->prev_;
    temp_head = temp_head->next_;
  }
}

template <class T>
void list<T>::unique() {
  node_ *temp_head = head_;
  node_ *node_for_delete;
  while (temp_head) {
    if (temp_head->next_ && temp_head->value_ == temp_head->next_->value_) {
      node_for_delete = temp_head->next_;
      temp_head->next_ = temp_head->next_->next_;
      temp_head->next_->prev_ = temp_head;
      delete node_for_delete;
    } else {
      temp_head = temp_head->next_;
    }
  }
}
template <class T>
void list<T>::sort() {
  value_type temp_value;
  node_ *temp_head = head_;
  while (temp_head) {
    node_ *temp_node = temp_head;
    while (temp_node->prev_ && temp_node->prev_->value_ > temp_node->value_) {
      temp_value = temp_node->prev_->value_;
      temp_node->prev_->value_ = temp_node->value_;
      temp_node->value_ = temp_value;
      temp_node = temp_node->prev_;
    }
    temp_head = temp_head->next_;
  }
}

// block: ITERATORS
template <class T>
void list<T>::ListIterator::operator=(node_ &node) {
  itr_node_ = &node;
  value_ = node.value_;
}

template <class T>
typename list<T>::iterator list<T>::begin() {
  list<T>::iterator iterator;
  if (head_) {
    iterator = *head_;
    iterator.value_ = head_->value_;
  } else {
    iterator.value_ = 0;
  }
  return iterator;
}

template <class T>
typename list<T>::iterator list<T>::end() {
  list<T>::iterator iterator;
  iterator = *end_node_;
  iterator.size_ = &count_;
  iterator.value_ = T();
  return iterator;
}

template <class T>
list<T>::ListIterator::ListIterator() = default;

template <class T>
typename list<T>::value_type &list<T>::ListIterator::operator*() {
  T *value = &value_;
  if (itr_node_ && !itr_node_->next_) {
    std::memset(value, 0, sizeof(T));
    std::memcpy(value, size_, sizeof(*size_));
  }
  return *value;
}

template <class T>
void list<T>::ListIterator::operator++() {
  if (itr_node_) {
    if (itr_node_->next_) {
      itr_node_ = itr_node_->next_;
    } else {
      while (itr_node_ && itr_node_->prev_) {
        itr_node_ = itr_node_->prev_;
      }
    }
    value_ = itr_node_->value_;
  }
}

template <class T>
void list<T>::ListIterator::operator--() {
  if (itr_node_->prev_) {
    itr_node_ = itr_node_->prev_;
    value_ = itr_node_->value_;
  } else {
    count_ = 0;
    while (itr_node_ && itr_node_->next_) {
      itr_node_ = itr_node_->next_;
      ++count_;
    }
    size_ = &count_;
  }
}

template <class T>
bool list<T>::ListIterator::operator==(list<T>::ListIterator iterator) {
  return itr_node_ == iterator.itr_node_;
}

template <class T>
bool list<T>::ListIterator::operator!=(list<T>::ListIterator iterator) {
  return itr_node_ != iterator.itr_node_;
}
}  // namespace s21
