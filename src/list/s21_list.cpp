#include "s21_list.h"

#include "cstring"

// complete: empty
// complete: size
// todo: max size

// complete: clear
// complete: push_back
// complete: pop_back
// complete: push_front
// complete: pop_front
// todo: swap
// todo: merge
// todo: splice
// todo: reverse
// todo: unique
// todo: sort

int main() {
  list<int> a;
  //  list<int> b(a);
  a.push_back(3);
  a.push_back(4);
  //  //  a.pop_back();
  //  a.pop_back();
  //  printf("%ld - size\n", b.size());
  //  a.clear();
  a.print_list();
  a.reverse();
  a.print_list();
  return 0;

  printf("%s", a.empty() ? "empty" : "not empty");
  return 0;
}

// constructor
template <class T>
list<T>::list() {
  //  head_ = NULL;
  //  tail_ = NULL;
  //  count_ = 0;
}

template <class T>
list<T>::list(size_type n) {
  head_ = NULL;
  tail_ = NULL;
  count_ = 0;
  for (int i = 0; i < n; i++) {
    push_back(0);
  }
}

template <class T>
list<T>::list(const list &l) {
  head_ = NULL;
  tail_ = NULL;
  node *temp_node = l.head_;
  while (temp_node) {
    this->push_back(temp_node->data_);
    temp_node = temp_node->next_;
  }
}

template <class T>
list<T>::~list() {
  clear();
}

// template <class T>
// int list<T>::operator=(list &&l) { return 0; }

// iterators
// list iterator_begin() {}
// list iterator_end() {}

// information
template <class T>
bool list<T>::empty() {
  return !head_;
}

template <class T>
size_t list<T>::size() {
  return count_;
}

// size_type max_size() {}

// methods to modify
template <class T>
void list<T>::clear() {
  node *temp_node;
  while (head_) {
    temp_node = head_;
    head_ = head_->next_;
    delete temp_node;
    count_--;
  }
}

// template <class T>
// void list<T>::iterator_insert(iterator pos, const_reference value) {}

// template <class T>
// void list<T>::erase(iterator pos) {}

template <class T>
void list<T>::push_back(const_reference value) {
  node *new_node = new node;
  if (!head_) {
    head_ = new_node;
    tail_ = head_;
  } else {
    tail_->next_ = new_node;
    new_node->prev_ = tail_;
    tail_ = new_node;
  }
  new_node->next_ = NULL;
  new_node->data_ = value;
  count_++;
}

template <class T>
void list<T>::pop_back() {
  node *temp_node = tail_;
  if (head_ != tail_) {
    tail_ = tail_->prev_;
    tail_->next_ = NULL;
  }
  delete temp_node;
  count_--;
}

template <class T>
void list<T>::push_front(const_reference value) {
  node *new_node = new node;
  if (!head_) {
    head_ = new_node;
    tail_ = head_;
  } else {
    new_node->next_ = head_;
    head_->prev_ = new_node;
    head_ = new_node;
  }

  new_node->prev_ = NULL;
  new_node->data_ = value;
  count_++;
}

template <class T>
void list<T>::pop_front() {
  node *temp_node = head_;
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
void list<T>::swap(list &other) {}

template <class T>
void list<T>::merge(list &other) {}

// template <class T>
// void list<T>::splice(const_iterator pos, list &other) {}

template <class T>
void list<T>::reverse() {
  while (head_) {
//    head_->prev_ = head_->next_;
//    head_ = head_->next_;
  }
}
template <class T>
void list<T>::unique() {
  node *temp_node = head_;
  while (temp_node) {
    if (temp_node->next_ && temp_node->data_ == temp_node->next_->data_) {
    }
    temp_node = temp_node->next_;
  }
}

template <class T>
void list<T>::sort() {}

// additional temp methods
template <class T>
void list<T>::print_list() {
  printf("%ld\n", count_);
  node *temp_node = head_;
  while (temp_node) {
    printf("data: %d\n", head_->data_);
    temp_node = temp_node->next_;
  }
}

// Iterator
