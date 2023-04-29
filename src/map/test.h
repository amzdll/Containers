#include <utility>
#include <sstream>
#include "iostream"
#include "string"
#ifndef CONTAINERS_TEST_H
#define CONTAINERS_TEST_H

//#include "test.cpp"

namespace s21 {
template <class Key, class T>
class tree {
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_t;

  // temp pub
 private:
  struct node_ {
    node_ *left_;
    node_ *right_;
    node_ *parent_;
    std::pair<Key, mapped_type> value_;
    bool color_;
  };
  node_ *root_ = nullptr;

 public:
  class TreeIterator;
  using iterator = TreeIterator;

  tree(){};

  node_* get_root() {return root_;};

  node_ *create_node(value_type value, bool is_red);
  void insert(value_type value);
  void printTree(tree<Key, T>::node_ *root_, std::string indent, bool left);
  // balance Methods
  void balanceTree(tree<Key, T>::node_ *node);
  bool nodeIsExist(tree<Key, T>::node_ *node);
  void colorSwap(tree<Key, T>::node_ *node);
  void rightTurn(tree<Key, T>::node_ *node);
};

template <class Key, class T>
class tree<Key, T>::TreeIterator {
 private:
  node_ *itr_node_ = NULL;

 public:
  TreeIterator();

  void operator=(node_ &node_);
  std::pair<Key, T> &operator*();
  std::pair<Key, T> *operator->();
  void operator++();
  void operator--();
  bool operator==(tree<Key, T>::TreeIterator iterator);
  bool operator!=(tree<Key, T>::TreeIterator iterator);
};

}  // namespace s21




#endif  // CONTAINERS_TEST_H
