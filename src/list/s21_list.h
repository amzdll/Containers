#ifndef CPP2_S21_CONTAINERS_S21_LIST_H_
#define CPP2_S21_CONTAINERS_S21_LIST_H_

class list {
 private:
 public:
  // constructor
  list();
  list(size_type n);
  list(std::initializer_list<value_type> const &items);
  list(const list &l);
  list(list &&l);
  ~list();

  // custom types
  typedef value_type value_type;
  typedef size_type size_type;
  typedef value_type &reference;
  typedef const value_type &const_reference;
  typedef value_type *iterator;
  typedef const value_type *const_iterator;

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
  void iterator_insert(iterator pos, const_reference value);
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
};

#endif  // CPP2_S21_CONTAINERS_S21_LIST_H_