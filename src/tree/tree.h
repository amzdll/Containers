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
template <class Key, class T>
class tree {
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_t;
  bool operator<(value_type &lhs, value_type& rhs) {
    return (lhs.first < rhs.first);
  }
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
  T &at(const Key &key);
  T &operator[](const Key &key);

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
  std::pair<iterator, bool> insert_or_assign(const Key &key, const T &obj);
  void erase(s21::tree<Key, T>::iterator pos);
  void swap(tree &other);
  void merge(tree &other);


  bool contains(const Key &key);

  // rb tree
  node_ *get_root() { return root_; };
  void updateSideNodes(node_ *node);

  void initTree();
  node_ *create_node(value_type value, bool is_red);
  bool push(value_type value);
  bool checkBalance();
  void balanceTree(tree<Key, T>::node_ *node);
  void balanceNode(tree<Key, T>::node_ *node);
  void colorSwap(tree<Key, T>::node_ *node);
  void rightTurn(tree<Key, T>::node_ *node);
  void leftTurn(tree<Key, T>::node_ *node);
  void deleteNode(node_ *node);
  void printTree(tree<Key, T>::node_ *root_, std::string indent, bool left);
};




template <class Key, class T>
class tree<Key, T>::TreeIterator {
 private:
  node_ *itr_node_ = NULL;

 public:
  TreeIterator()= default;

  std::pair<Key, T> &operator*();
  void operator++();
  void operator--();
  bool operator==(tree<Key, T>::TreeIterator iterator);
  void operator=(node_ &node_);
  bool operator!=(tree<Key, T>::TreeIterator iterator);
  std::pair<Key, T> *operator->();

  friend class tree;
};


//template <typename Key>
//class set:tree<Key, Key> {
//
//}  // namespace s21
};

#endif  // CPP2_S21_CONTAINERS_TREE_S21_TREE_H_
