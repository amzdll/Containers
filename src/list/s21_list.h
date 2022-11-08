#ifndef CPP2_S21_CONTAINERS_S21_LIST_H_
#define CPP2_S21_CONTAINERS_S21_LIST_H_

#include "cstdio"

template <class T>
class list {
 private:

  // member types
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

 protected:
  struct node {
    node *next_;
    node *prev_;
    value_type data_;
  };
  node *head_;
  node *tail_;
  size_type count_;

 public:
  class ListIterator;
  using iterator = ListIterator;
  using const_iterator = const T *;


  // constructors
  list();
  list(size_type n);
  //  list(std::initializer_list<value_type> const &items);
  list(const list &l);
  list(list &&l);
  ~list();

  // overloading
  list operator=(list &&l);

  // methods
  const_reference front();
  const_reference back();

  // iterators
  list iterator_begin();
  list iterator_end();

  //  information
  bool empty();
  size_type size();
  size_type max_size();

  // methods to modify
  void clear();
  //    void iterator_insert(iterator pos, const_reference value);
  //    void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list &other);
  void merge(list &other);
  //    void splice(const_iterator pos, list &other);
  void reverse();
  void unique();
  void sort();

  // additional temp methods
  void print_list();
};

#endif  // CPP2_S21_CONTAINERS_S21_LIST_H_