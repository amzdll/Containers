#include "s21_map.h"

namespace s21 {
// BLOCK: CONSTRUCTORS

template <class Key, class T>
map<Key, T>::map() {}

template <class Key, class T>
map<Key, T>::map(const std::initializer_list<value_type> &items) {}

template <class Key, class T>
map<Key, T>::map(const map &m) {}

template <class Key, class T>
map<Key, T>::map(map &&m) noexcept {}

template <class Key, class T>
map<Key, T>::~map() {}

template <class Key, class T>
typename map<Key, T>::map &map<Key, T>::operator=(map &&m) noexcept {
  return nullptr;
}

// BLOCK: ELEMENT ACCESS
template <class Key, class T>
T &map<Key, T>::at(const Key &key) {
  return nullptr;
}

template <class Key, class T>
T &map<Key, T>::operator[](const Key &key) {
  return nullptr;
}

// BLOCK: ITERATORS

//    template<class Key, class T>
//    iterator map<Key, T>::begin() { return nullptr; }

//    template<class Key, class T>
//    iterator map<Key, T>::end() { return nullptr; }

//  BLOCK: CAPACITY

template <class Key, class T>
bool map<Key, T>::empty() {
  return false;
}

template <class Key, class T>
size_t map<Key, T>::size() {
  return 0;
}

template <class Key, class T>
size_t map<Key, T>::max_size() {
  return 0;
}

// BLOCK:  MODIFIERS

template <class Key, class T>
void map<Key, T>::clear() {}

//    template<class Key, class T>
//    std::pair<iterator, bool> insert(const value_type &value) { return null; }

//    template<class Key, class T>
//    std::pair<iterator, bool> insert(const value_type &value) { return
//    nullptr; }

//    template <class Key, class T>
//    std::pair<iterator, bool> map<Key, T>::insert_or_assign(const Key& key,
//                                                         const T& obj) {return
//                                                         nullptr; }

//    template<class Key, class T>
//    void map<Key, T>::erase(iterator pos) {}

//    template<class Key, class T>
//    void map<Key, T>::swap(map &other) {}
//
//    template<class Key, class T>
//    void map<Key, T>::merge(map &other) {}
//
//
//
//    // BLOCK: LOOKUP

//    template<class Key, class T>
//    bool map<Key, T>::contains(const Key &key) { return false; }
}  // namespace s21