#include "s21_list.h"

#include "cstring"

int main() {
  list<int> a;
  a.push_back(3);
  a.push_back(4);
  a.pop_front();
  a.pop_front();
  a.print_list();

  printf("%s", a.empty() ? "empty" : "not empty");
  return 0;
}

// constructor
template <class T>
list<T>::list() {
  head = NULL;
  tail = NULL;
  count = 0;
}

template <class T>
list<T>::list(size_type n) {}

template <class T>
list<T>::~list() {}

// template <class T>
// int list<T>::operator=(list &&l) { return 0; }

// iterators
// list iterator_begin() {}
// list iterator_end() {}

// information
template <class T>
bool list<T>::empty() {
  return head == NULL;
}

// size_type size() {}
// size_type max_size() {}

// methods to modify
template <class T>
void list<T>::clear() {
  node *temp_node;
  while (head) {
    temp_node = head;
    head = head->next;
    delete temp_node;
    count--;
  }
}

// template <class T>
// void list<T>::iterator_insert(iterator pos, const_reference value) {}

// template <class T>
// void list<T>::erase(iterator pos) {}

template <class T>
void list<T>::push_back(const_reference value) {
  node *new_node = new node;
  if (!head) {
    head = new_node;
    tail = head;
  } else {
    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;
  }
  new_node->next = NULL;
  new_node->data = value;
  count++;
}

template <class T>
void list<T>::pop_back() {
  node *temp_node = tail;
  if (head != tail) {
    tail = tail->prev;
  }
  tail->next = NULL;
  delete temp_node;
  count--;
}

template <class T>
void list<T>::push_front(const_reference value) {
  node *new_node = new node;
  if (!head) {
    head = new_node;
    tail = head;
  }
  new_node->next = head;
  head->prev = new_node;
  head = new_node;
  new_node->prev = NULL;
  new_node->data = value;
  count++;
}

template <class T>
void list<T>::pop_front() {
  node *temp_node = head;
  if (head != tail) {
    head = head->next;
    head->prev = NULL;
  } else {
    head = NULL;
    tail = NULL;
  }
  delete temp_node;
  count--;
}

template <class T>
void list<T>::swap(list &other) {}

template <class T>
void list<T>::merge(list &other) {}

// template <class T>
// void list<T>::splice(const_iterator pos, list &other) {}

template <class T>
void list<T>::reverse() {}

template <class T>
void list<T>::unique() {}

template <class T>
void list<T>::sort() {}

// additional temp methods
template <class T>
void list<T>::print_list() {
  printf("%d\n", count);
  node *temp_node = head;
  while (temp_node) {
    printf("data: %d\n", head->data);
    temp_node = temp_node->next;
  }
}
