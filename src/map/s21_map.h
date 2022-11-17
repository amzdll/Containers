#ifndef CPP2_S21_CONTAINERS_MAP_S21_MAP_H_
#define CPP2_S21_CONTAINERS_MAP_S21_MAP_H_

#include <cstdio>
#include <utility>

namespace s21 {
template <class Key, class T>
class map {
 private:
 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  //  using iterator = ;
  //  using const_iterator = ;
  using size_type = size_t;

  map();
  //  map(std::initializer_list<value_type> const &items);
  map(const map &m);
  map(map &&m);
  ~map();
  //  operator=(map &&m);

  T &at(const Key &key);
  T &operator[](const Key &key);

  iterator begin();
  iterator end();

  bool empty();
  size_type size();
  size_type max_size();

  void clear();
  std::pair<iterator, bool> insert(const value_type& value);
  std::pair<iterator, bool> insert(const Key& key, const T& obj);
  std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj);;
  void erase(iterator pos);
  void swap(map& other);
  void merge(map& other);

  bool contains(const Key& key);
};

}  // namespace s21

#endif  //  CPP2_S21_CONTAINERS_MAP_S21_MAP_H_