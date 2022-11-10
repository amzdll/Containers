#ifndef CPP2_S21_CONTAINERS_LIST_S21_LIST_H_
#define CPP2_S21_CONTAINERS_LIST_S21_LIST_H_

#include "cstdio"
// namespace s21 {
template <class T>
class list {
 public:
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
  node *head_ = NULL;
  node *tail_ = NULL;
  size_type count_ = 0;

 public:
  class ListIterator {
    friend class list<T>;

   private:
    node *node_ = NULL;
    value_type value_ = value_type();

   public:
    ListIterator();

    void operator=(node &node_);
    value_type& operator*();
    void operator++(value_type);
    void operator++();
    void operator--(value_type);
    void operator--();
    bool operator!=(list<T>::ListIterator iterator);
  };

  using iterator = ListIterator;
  using const_iterator = const T *;

  // constructors
  list();
  explicit list(size_type n);
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
  iterator begin();
  iterator end();

  //  information
  bool empty();
  size_type size();
  size_type max_size();

  // methods to modify
  void clear();
  iterator iterator_insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list &other);
  void merge(list &other);
  void splice(const_iterator pos, list &other);
  void reverse();
  void unique();
  void sort();

  // additional temp methods
  void print_list();
  void itr();
};
//}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_LIST_S21_LIST_H_
