#ifndef CPP2_CONTAINERS_MAP_S21_SET_H_
#define CPP2_CONTAINERS_MAP_S21_SET_H_

#include "../tree/tree.cc"

namespace s21 {
template <class Key, class T>
class map : public tree<std::pair<Key, T>> {
 public:
  // Members type
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_t;
  using node_ = typename tree<value_type>::node_;
  using iterator = typename s21::tree<value_type>::tree_iterator;

  // Constructors
  map() = default;
  map(std::initializer_list<value_type> const &items);
  map(const map &m);
  map(map &&m) noexcept;
  ~map() = default;

  // Element access
  T &at(const Key &key);
  T &operator[](const Key &key);

  // Modifiers
  std::pair<iterator, bool> insert(const_reference value);
  std::pair<iterator, bool> insert(const key_type &key, const mapped_type &obj);
  std::pair<iterator, bool> insert_or_assign(const key_type &key,
                                             const mapped_type &obj);

 private:
  // Additional
  iterator find_key(const key_type &key);
};

}  // namespace s21

#endif  // CPP2_CONTAINERS_MAP_S21_SET_H_
