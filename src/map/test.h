
#include <sstream>
#include <utility>
#include <initializer_list>
#include "iostream"
#include "string"
#ifndef CPP2_S21_CONTAINERS_MAP_S21_TREE_H_
#define CPP2_S21_CONTAINERS_MAP_S21_TREE_H_

// #include "test.cpp"

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
  size_type size_ = 0;

 public:
  class TreeIterator;
  using iterator = TreeIterator;

  tree(){};
  tree(std::initializer_list<value_type> const &items);

  T &at(const Key &key);
  T &operator[](const Key &key);

  iterator begin();
  iterator end();

  bool empty();
  size_type size();

  bool contains(const Key &key);

  // rb tree
  node_ *get_root() { return root_; };
  node_ *create_node(value_type value, bool is_red);
  void insert(value_type value);
  void balanceTree(tree<Key, T>::node_ *node);
  void colorSwap(tree<Key, T>::node_ *node);
  void rightTurn(tree<Key, T>::node_ *node);
  void leftTurn(tree<Key, T>::node_ *node);

  void printTree(tree<Key, T>::node_ *root_, std::string indent, bool left);
};

template <class Key, class T>
class tree<Key, T>::TreeIterator {
 private:
  node_ *itr_node_ = NULL;
  node_ *itr_root_ = NULL;

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

#endif  // CPP2_S21_CONTAINERS_MAP_S21_TREE_H_
