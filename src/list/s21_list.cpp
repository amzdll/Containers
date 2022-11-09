//#include <initializer_list>
#include "s21_list.h"

#include "cstring"

// namespace s21 {
int main() {
  list<int> a(5);
  a.push_back(10);
  a.push_back(2);
  a.push_back(100);
  printf("a: %d\n", a.front());
  printf("a: %d\n", a.back());
  a.print_list();
  return 0;
}
// CONSTRUCTORS =================================================================
template <class T>
list<T>::list() {
  head_ = NULL;
  tail_ = NULL;
  count_ = 0;
}

template <class T>
list<T>::list(size_type n) {
  head_ = NULL;
  tail_ = NULL;
  count_ = 0;
  for (size_type i = 0; i < n; i++) {
    push_back(T());
  }
}

//template <class T>
//list<T>::list(std::initializer_list<value_type> const &items){}

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
list<T>::list(list &&l) {
//  head_ = NULL;
//  tail_ = NULL;
//  node *temp_node = l.head_;
//  while (temp_node) {
//    this->push_back(temp_node->data_);
//    temp_node = temp_node->next_;
//  }
}

template <class T>
list<T>::~list() {
  clear();
}

// template <class T>
// int list<T>::operator=(list &&l) { return 0; }

// ELEMENT ACCESS =================================================================

template <class T>
const T & list<T>::front() {
  return head_->data_;
}

template <class T>
const T & list<T>::back() {
  return tail_->data_;
}

// INFORMATION =================================================================
template <class T>
bool list<T>::empty() {
  return !head_;
}

template <class T>
size_t list<T>::size() {
  return count_;
}

template <class T>
size_t list<T>::max_size() {
  return 0;
}

// METHODS TO MODIFY =================================================================
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
    tail_->next_ = NULL;
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
void list<T>::swap(list &other) {
  node *temp_node = head_;
  size_type count = count_;
  head_ = other.head_;
  count_ = other.count_;
  other.head_ = temp_node;
  other.count_ = count;
}

template <class T>
void list<T>::merge(list &other) {}

 template <class T>
 void list<T>::splice(const_iterator pos, list &other) {}

template <class T>
void list<T>::reverse() {
  //  head_ = tail_ while (tail_) {
  //    tail_->
  //  }
  //  while (temp_node) {
  //    head_->next_ = head_->next_->next_;
  //    head_->prev_ = head_;
  //    head_->next_->next_ = head_;
  //    head_
  //    temp_node= temp_node->next_;
  //  }
}

template <class T>
void list<T>::unique() {
  node *temp_node = head_;
  while (temp_node) {
    //    if(temp_node->data_ == tem)
  }
}

template <class T>
void list<T>::sort() {}

// additional temp methods =================================================================
template <class T>
void list<T>::print_list() {
  printf("%ld\n", count_);
  node *temp_node = head_;
  while (temp_node) {
    printf("data: %d\n", temp_node->data_);
    temp_node = temp_node->next_;
  }
}
//};  // namespace s21
