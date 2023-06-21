#include "s21_map.h"

namespace s21 {
// Constructors
template <class Key, class T>
map<Key, T>::map(const std::initializer_list<value_type> &items) {
  if (items.size()) {
    auto itr = items.begin();
    while (itr != items.end()) {
      insert(*itr);
      ++itr;
    }
  }
}

template <class Key, class T>
map<Key, T>::map(const map &m) : tree<value_type>(m) {}

template <class Key, class T>
map<Key, T>::map(map &&m) noexcept : tree<value_type>(std::move(m)) {}

// Element access
template <class Key, class T>
T &s21::map<Key, T>::at(const Key &key) {
  iterator itr_found = this->find_key(key);

  if (itr_found == this->end()) {
    throw std::out_of_range("at::no such element in the map!");
  }

  return (*itr_found).second;
}

template <class Key, class T>
T &map<Key, T>::operator[](const Key &key) {
  iterator itr_found = this->find_key(key);

  if (itr_found == this->end()) {
    auto insert_result_pair = this->insert(std::pair<Key, T>(key, 0));
    return (*insert_result_pair.first).second;
  }
  return (*itr_found).second;
}

// Modifiers
template <class Key, class T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    typename map<Key, T>::const_reference value) {
  bool inserted = s21::tree<value_type>::insert(value);
  auto pos = this->find(value);
  return std::pair<typename map<Key, T>::iterator, bool>(pos, inserted);
}

template <class Key, class T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    const Key &key, const T &obj) {
  return this->insert(value_type(key, obj));
}

template <class Key, class T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert_or_assign(
    const Key &key, const T &obj) {
  auto found = find_key(key);
  std::pair<iterator, bool> result(found, false);
  if (found == this->end()) {
    result = insert(key, obj);
  } else {
    (*found).second = obj;
    result.second = true;
  }
  return result;
}

// Additional
template <class Key, class T>
typename map<Key, T>::iterator map<Key, T>::find_key(const Key &key) {
  auto pos = this->end_node_;
  if (this->root_) {
    node_ *itr = this->root_;
    size_t i = 0;
    while (pos == this->end_node_ && i < this->size()) {
      if (key < itr->value_.first && itr->left_) {
        itr = itr->left_;
      } else if (key > itr->value_.first && itr->right_) {
        itr = itr->right_;
      } else if (key == itr->value_.first) {
        pos = itr;
      }
      ++i;
    }
  }
  auto found_pos = this->find(pos->value_);
  return found_pos;
}
}  // namespace s21
