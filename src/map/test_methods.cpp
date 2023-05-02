#include "test.h"

// constructors

template <class Key, class T>
s21::tree<Key, T>::tree() {
  begin_node_ = new node_;
  end_node_ = new node_;
}

// element acess


// need throw
template <class Key, class T>
T& s21::tree<Key, T>::at(const Key& key) {
  for (iterator itr = begin(); itr != end(); ++itr) {
    if (itr->first == key) {
      return itr->second;
    }
  }
  iterator test;
  return test->second;
}

template <class Key, class T>
T& s21::tree<Key, T>::operator[](const Key& key) {
  iterator itr = begin();
  for (; itr != end(); ++itr) {
    if (itr->first == key) {
      return (*itr).second;
    }
  }
  return (*itr).second;
}

// map iterators
template <class Key, class T>
typename s21::tree<Key, T>::iterator s21::tree<Key, T>::begin() {
  tree<Key, T>::iterator iterator;
  auto itr_node = begin_node_;
  iterator = *itr_node;
  return iterator;
}

template <class Key, class T>
typename s21::tree<Key, T>::iterator s21::tree<Key, T>::end() {
  tree<Key, T>::iterator iterator;
  auto itr_node = end_node_;
  iterator = *itr_node;
  if (itr_node->value_.first > root_->value_.first) {
    node_* end_node = new node_;
    end_node->value_.first = 0;
    end_node->parent_ = itr_node;
    end_node->parent_->right_ = end_node;
    iterator = *itr_node->right_;
  }
  return iterator;
}

template <class Key, class T>
bool s21::tree<Key, T>::empty() {
  return !root_;
}

template <class Key, class T>
size_t s21::tree<Key, T>::size() {
  return size_;
}

// Modifiers
template <class Key, class T>
std::pair<typename s21::tree<Key, T>::iterator, bool> s21::tree<Key, T>::insert(const tree::value_type &value) {

  return std::pair<iterator, bool>();
}


// Map Lookup
template <class Key, class T>
bool s21::tree<Key, T>::contains(const Key& key) {
  return at(key);
}

// Iterator Overload

template <class Key, class T>
s21::tree<Key, T>::TreeIterator::TreeIterator() {}

template <class Key, class T>
void s21::tree<Key, T>::TreeIterator::operator=(node_& node_) {
  itr_node_ = &node_;
}

template <class Key, class T>
std::pair<Key, T>& s21::tree<Key, T>::TreeIterator::operator*() {
  return itr_node_->value_;
}

template <class Key, class T>
std::pair<Key, T>* s21::tree<Key, T>::TreeIterator::operator->() {
  return &(itr_node_->value_);
}

template <class Key, class T>
void s21::tree<Key, T>::TreeIterator::operator++() {
  if (itr_node_->right_) {
    itr_node_ = itr_node_->right_;
    while (itr_node_->left_) {
      itr_node_ = itr_node_->left_;
    }
  } else {
    node_* parent_itr_node = itr_node_->parent_;
    while (itr_node_->parent_ && itr_node_->parent_->right_ == itr_node_) {
      itr_node_ = itr_node_->parent_;
      parent_itr_node = parent_itr_node->parent_;
    }
    itr_node_ = parent_itr_node;
  }
}

template <class Key, class T>
void s21::tree<Key, T>::TreeIterator::operator--() {
  if (itr_node_->left_) {
    itr_node_ = itr_node_->left_;
    while (itr_node_->right_) {
      itr_node_ = itr_node_->right_;
    }
  } else {
    node_* parent_itr_node = itr_node_->parent_;
    while (itr_node_->parent_ && itr_node_->parent_->left_ == itr_node_) {
      itr_node_ = itr_node_->parent_;
      parent_itr_node = parent_itr_node->parent_;
    }
    itr_node_ = parent_itr_node;
  }
}

template <class Key, class T>
bool s21::tree<Key, T>::TreeIterator::operator!=(
    tree<Key, T>::TreeIterator iterator) {
  return itr_node_ != iterator.itr_node_;
}

template <class Key, class T>
bool s21::tree<Key, T>::TreeIterator::operator==(
    tree<Key, T>::TreeIterator iterator) {
  return itr_node_ != iterator.itr_node_;
}

// Additional methods
