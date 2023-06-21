#include "map"

#ifndef CPP2_S21_CONTAINERS_TREE_S21_TREE_H_
#define CPP2_S21_CONTAINERS_TREE_S21_TREE_H_

#include <initializer_list>
#include <sstream>
#include <stdexcept>
#include <utility>

#include "iostream"
#include "string"

namespace s21 {
template <class Key>
class tree {
 public:
  // Members type
  using key_type = Key;
  using value_type = key_type;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_t;

  class tree_iterator;
  using iterator = tree_iterator;
  using const_iterator = const tree_iterator;

  struct node_ {
    node_ *left_;
    node_ *right_;
    node_ *parent_;
    value_type value_;
    bool color_;
  };

  // Constructors
  tree();
  tree(const tree &other);
  tree(std::initializer_list<value_type> const &items);
  tree(tree &&other) noexcept;
  tree &operator=(tree &&other) noexcept;
  ~tree();

  // Iterators
  iterator begin() const;
  iterator end() const;

  // Capacity
  bool empty();
  size_type size();
  size_type max_size();

  // Modifiers
  void clear();
  void erase(s21::tree<Key>::iterator pos);
  void swap(tree &other);
  void merge(tree &other);

  // Lookup
  bool contains(const value_type &value);
  iterator find(const Key &key);

  // llrb tree
  bool insert(value_type value);
  node_ *create_node(value_type value, bool is_red);
  void update_side_nodes(node_ *node);
  void balance_tree(tree<Key>::node_ *node);
  void balance_node(tree<Key>::node_ *node);
  void color_swap(tree<Key>::node_ *node);
  void right_turn(tree<Key>::node_ *node);
  void left_turn(tree<Key>::node_ *node);

  void erase_black(s21::tree<Key>::iterator pos);
  void erase_red(s21::tree<Key>::iterator pos);

  // 1) Removing the red top with 0 children
  void erase_red_without_children(s21::tree<Key>::node_ *node);

  // 3) Removal of a red or black top with 2 children
  void erase_node_with_two_children(s21::tree<Key>::node_ *node);

  // 4) Removal of the black top with 1 child
  void erase_black_with_one_child(s21::tree<Key>::node_ *node);

  // 5) Removing the black top with 0 children
  void erase_black_without_children(s21::tree<Key>::node_ *node);
  // 5.1) Black brother
  // 5.1.1) At least one brother's child is red
  // 5.1.1.а) The right child is red (the left child is whatever)
  void erase_black_without_children_and_black_brother_with_right_red_nephew(
      s21::tree<Key>::node_ *node, s21::tree<Key>::node_ *parent,
      s21::tree<Key>::node_ *brother);

  // 5.1.1.б) The left child is red (the right child is black)
  void erase_black_without_children_and_black_brother_with_left_red_nephew(
      s21::tree<Key>::node_ *node, s21::tree<Key>::node_ *parent,
      s21::tree<Key>::node_ *brother);

  // 5.1.2) Both of the brother's children are black
  void erase_black_without_children_and_black_brother_with_black_nephews(
      s21::tree<Key>::node_ *node, s21::tree<Key>::node_ *parent,
      s21::tree<Key>::node_ *brother);

  // 5.2) Red brother
  void erase_black_without_children_and_red_brother(
      s21::tree<Key>::node_ *node, s21::tree<Key>::node_ *parent,
      s21::tree<Key>::node_ *brother);

  void delete_node(node_ *node);

 protected:
  node_ *root_ = nullptr;
  node_ *begin_node_ = nullptr;
  node_ *end_node_ = nullptr;
  size_type size_ = 0;
};

// Nested class
template <class Key>
class tree<Key>::tree_iterator {
 public:
  tree_iterator() = default;

  value_type &operator*();
  void operator++();
  void operator--();
  bool operator==(tree<Key>::tree_iterator iterator);
  void operator=(node_ &node_);
  bool operator!=(tree<Key>::tree_iterator iterator);
  value_type *operator->();

  friend class tree;

 protected:
  node_ *itr_node_ = nullptr;
};

};  // namespace s21

#endif  // CPP2_S21_CONTAINERS_TREE_S21_TREE_H_
