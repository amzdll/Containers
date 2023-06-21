#ifndef CPP2_CONTAINERS_SET_S21_SET_H_
#define CPP2_CONTAINERS_SET_S21_SET_H_

#include "../tree/tree.cc"

namespace s21 {
template <class Key>
class set : public tree<Key> {
 public:
  // Members type
  using key_type = Key;
  using value_type = key_type;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_t;
  using node_ = typename tree<Key>::node_;

  // Constructors
  set();
  set(std::initializer_list<value_type> const &items);
  set(const set &s);
  set(set &&s) noexcept;
  ~set() = default;
};

}  // namespace s21

#endif  //  CPP2_CONTAINERS_SET_S21_SET_H_
