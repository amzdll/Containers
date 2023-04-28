#include "s21_map.h"

namespace s21 {
// BLOCK: CONSTRUCTORS

template <class Key, class T>
map<Key, T>::map() {}

// template <class Key, class T>
// map<Key, T>::map(const std::initializer_list<value_type> &items) {}

template <class Key, class T>
map<Key, T>::map(const map &m) {}

template <class Key, class T>
map<Key, T>::map(map &&m) {}

template <class Key, class T>
map<Key, T>::~map() {}

template <class Key, class T>
typename map<Key, T>::map &map<Key, T>::operator=(map &&m) {
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

// BLOCK: LOOKUP
//    template<class Key, class T>
//    bool map<Key, T>::contains(const Key &key) { return false; }
}  // namespace s21

// TEMP
template <class Key, class T>
void s21::map<Key, T>::Push(const value_type value) {
  auto *new_node = new node_;
  new_node->value_ = value;
  if (!root_) {
    root_ = new_node;
  } else {
    auto *iter_node = root_;
    while (!new_node->parent_node_) {
      if (value.first < iter_node->value_.first) {
        if (iter_node->left_) {
          iter_node = iter_node->left_;
        } else {
          iter_node->left_ = new_node;
          new_node->parent_node_ = iter_node;
        }
      } else if (value.first > iter_node->value_.first && !iter_node->right_) {
        if (iter_node->right_) {
          new_node = new_node->right_;
        } else {
          iter_node->right_ = new_node;
          new_node->parent_node_ = iter_node;
        }
      }
    }
  }
}

//int main() {
//  s21::map<int, int> b;
//
//  b.Push(std::pair<int, int>(10, 3));
//  b.Push(std::pair<int, int>(123, 324));
//  b.Push(std::pair<int, int>(5, 1234));
//  b.Push(std::pair<int, int>(4, 1234));
//  b.Push(std::pair<int, int>(6, 1234));
//
//  //  printf("%d", b.root_->right_ ? 1 : 0);
//  //  printf("%d", ads);
//  b.root_ = b.root_->left_;
//  printf("%d, %d asdad\n", b.root_->value_.first, b.root_->value_.second);
//  b.root_ = b.root_->right_;
//  printf("%d, %d asdad\n", b.root_->value_.first, b.root_->value_.second);
//  //  printf("<%d, %d>", b.temp1, b.temp2);
//  return 0;
//}