#include "s21_set.h"

namespace s21 {

// Constructors
template <class Key>
set<Key>::set() : tree<key_type>() {}

template <class Key>
set<Key>::set(std::initializer_list<value_type> const &items)
    : tree<key_type>(items) {}

template <class Key>
set<Key>::set(const set &s) : tree<key_type>(s) {}

template <class Key>
set<Key>::set(set &&s) noexcept : tree<key_type>(std::move(s)) {}

}  // namespace s21