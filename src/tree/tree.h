#include "map"

#ifndef CPP2_S21_CONTAINERS_TREE_S21_TREE_H_
#define CPP2_S21_CONTAINERS_TREE_S21_TREE_H_

#include <initializer_list>
#include <sstream>
#include <stdexcept>
#include <utility>

#include "iostream"
#include "string"

// #include "tree.cpp"

namespace s21 {
template <class Key>
class tree {
  using key_type = Key;
//  using mapped_type = T;
  using value_type = key_type;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_t;
//  bool operator<(value_type &lhs, value_type &rhs) {
//    return (lhs.first < rhs.first);
//  }
  // temp pub
 private:
  struct node_ {
    node_ *left_;
    node_ *right_;
    node_ *parent_;
    Key value_;
//    std::pair<Key, mapped_type> value_;
    bool color_;
  };
  node_ *root_ = nullptr;
  node_ *begin_node_ = nullptr;
  node_ *end_node_ = nullptr;
  size_type size_ = 0;

 public:
  class TreeIterator;
  using iterator = TreeIterator;

  // Member functions
  tree();
  tree(std::initializer_list<value_type> const &items);
  ~tree();

  // Element access
//  T &at(const Key &key);
//  T &operator[](const Key &key);

  //  Iterators
  iterator begin();
  iterator end();

  // Capacity
  bool empty();
  size_type size();

  // Modifiers
  void clear();
  //  std::pair<iterator, bool> insert(const value_type &value);
  //  std::pair<iterator, bool> push(const value_type& value);
  //  std::pair<iterator, bool> push(const Key& key, const T& obj);
//  std::pair<iterator, bool> insert_or_assign(const Key &key, const T &obj);
  void erase(s21::tree<Key>::iterator pos);
  void swap(tree &other);
  void merge(tree &other);

  // Lookup
  bool contains(const Key &key);
  iterator find(const Key& key);

  // llrb tree
  node_ *get_root() { return root_; };
  void initTree();
  void printTree(tree<Key>::node_ *root_, std::string indent, bool left);

  bool push(value_type value);
  node_ *create_node(value_type value, bool is_red);
  void updateSideNodes(node_ *node);
  void balanceTree(tree<Key>::node_ *node);
  void balanceNode(tree<Key>::node_ *node);
  void colorSwap(tree<Key>::node_ *node);
  void rightTurn(tree<Key>::node_ *node);
  void leftTurn(tree<Key>::node_ *node);

  void eraseBlack(s21::tree<Key>::iterator pos);
  void eraseBlackWithOneChild(s21::tree<Key>::iterator pos);
  void eraseBlackWithTwoChildren(s21::tree<Key>::iterator pos);
  void eraseBlackWithoutChildren(s21::tree<Key>::iterator pos);

  void eraseRed(s21::tree<Key>::iterator pos);

  void deleteNode(node_ *node);
};

template <class Key>
class tree<Key>::TreeIterator {
 private:
  node_ *itr_node_ = NULL;

 public:
  TreeIterator() = default;

  Key &operator*();
  void operator++();
  void operator--();
  bool operator==(tree<Key>::TreeIterator iterator);
  void operator=(node_ &node_);
  bool operator!=(tree<Key>::TreeIterator iterator);
  Key *operator->();

  friend class tree;
};

// template <typename Key, typename T>
// class map : s21::tree<std::pair<Key, T>> {
//
// }
};  // namespace s21

#endif  // CPP2_S21_CONTAINERS_TREE_S21_TREE_H_
