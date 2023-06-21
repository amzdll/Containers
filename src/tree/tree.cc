#include "tree.h"

#include "set"

namespace s21 {
// Constructors

template <class Key>
s21::tree<Key>::tree() = default;

template <class Key>
s21::tree<Key>::tree(const s21::tree<Key> &other) {
  for (auto itr = other.begin(); itr != other.end(); ++itr) {
    insert(*itr);
  }
}

template <class Key>
tree<Key>::tree(tree &&other) noexcept {
  root_ = nullptr;
  begin_node_ = nullptr;
  end_node_ = nullptr;
  size_ = 0;
  std::swap(root_, other.root_);
  std::swap(begin_node_, other.begin_node_);
  std::swap(end_node_, other.end_node_);
  std::swap(size_, other.size_);
}

template <class Key>
tree<Key> &tree<Key>::operator=(tree &&other) noexcept {
  if (*this != other) {
    root_ = nullptr;
    begin_node_ = nullptr;
    end_node_ = nullptr;
    size_ = 0;
    std::swap(root_, other.root_);
    std::swap(begin_node_, other.begin_node_);
    std::swap(end_node_, other.end_node_);
    std::swap(size_, other.size_);
  }
  return *this;
}

template <class Key>
tree<Key>::tree(const std::initializer_list<value_type> &items) {
  if (items.size()) {
    auto itr = items.begin();
    while (itr != items.end()) {
      insert(*itr);
      ++itr;
    }
  }
}

template <class Key>
tree<Key>::~tree() {
  clear();
}

// Iterators
template <class Key>
typename s21::tree<Key>::iterator s21::tree<Key>::begin() const {
  tree<Key>::iterator iterator;
  auto itr_node = begin_node_;
  iterator = *itr_node;
  return iterator;
}

template <class Key>
typename s21::tree<Key>::iterator s21::tree<Key>::end() const {
  tree<Key>::iterator iterator;
  auto itr_node = end_node_;
  iterator = *itr_node;
  return iterator;
}

// Capacity
template <class Key>
bool s21::tree<Key>::empty() {
  return !size_;
}

template <class Key>
size_t s21::tree<Key>::size() {
  return size_;
}

template <class Key>
typename s21::tree<Key>::size_type tree<Key>::max_size() {
  std::allocator<Key> alloc;
  return alloc.max_size();
}

// Modifiers
template <class Key>
void s21::tree<Key>::clear() {
  if (root_) {
    delete_node(root_);
    size_ = 0;
    root_ = nullptr;
  }
}

template <class Key>
void s21::tree<Key>::erase(s21::tree<Key>::iterator pos) {
  if (pos.itr_node_ != nullptr) {
    if (pos.itr_node_ == begin_node_) {
      begin_node_ = pos.itr_node_->parent_;
    }
    if (pos.itr_node_->color_) {
      erase_red(pos);
    } else {
      erase_black(pos);
    }
    size_ -= 1;
  }
}

template <class Key>
void tree<Key>::swap(tree &other) {
  std::swap(root_, other.root_);
  std::swap(size_, other.size_);
  std::swap(begin_node_, other.begin_node_);
  std::swap(end_node_, other.end_node_);
}

template <class Key>
void tree<Key>::merge(tree<Key> &other) {
  for (auto it = other.begin(); it != other.end(); ++it) {
    insert(*it);
  }
}

// Lookup
template <class Key>
bool s21::tree<Key>::contains(const value_type &value) {
  return find(value) != end();
}

template <class Key>
typename s21::tree<Key>::iterator tree<Key>::find(const Key &key) {
  s21::tree<Key>::iterator pos = end();
  for (s21::tree<Key>::iterator itr = begin(); itr != end() && itr != pos;
       ++itr) {
    if (key == *itr) {
      pos = itr;
    }
  }
  return pos;
}

template <class Key>
void s21::tree<Key>::erase_black(s21::tree<Key>::iterator pos) {
  if ((!pos.itr_node_->right_ || pos.itr_node_->right_ == end_node_) &&
      (!pos.itr_node_->left_ || pos.itr_node_->left_ == end_node_)) {
    node_ *parent = pos.itr_node_->parent_;
    erase_black_without_children(pos.itr_node_);
    balance_tree(parent);
  } else if (pos.itr_node_->right_ && pos.itr_node_->left_ &&
             pos.itr_node_->right_ != end_node_ &&
             pos.itr_node_->left_ != end_node_) {
    erase_node_with_two_children(pos.itr_node_);
  } else {
    erase_black_with_one_child(pos.itr_node_);
  }
}

template <class Key>
void s21::tree<Key>::erase_black_with_one_child(s21::tree<Key>::node_ *node) {
  if (node->left_ && (!node->right_ || node->right_ == end_node_)) {
    node->value_ = node->left_->value_;
    delete node->left_;
    node->left_ = nullptr;
  } else if (!node->left_ && node->right_ && node->right_ != end_node_) {
    node->value_ = node->right_->value_;
    delete node->right_;
    node->left_ = nullptr;
  }
}

template <class Key>
void s21::tree<Key>::erase_black_without_children(s21::tree<Key>::node_ *node) {
  node_ *parent = nullptr;
  node_ *brother = nullptr;
  node_ *l_nephew = nullptr;
  node_ *r_nephew = nullptr;

  if (node->parent_) {
    parent = node->parent_;
    if (parent->left_ == node && parent->right_) {
      brother = parent->right_;
    } else if (parent->right_ == node && parent->left_) {
      brother = parent->left_;
    }
    if (brother && brother->right_) {
      r_nephew = brother->right_;
    }
    if (brother && brother->left_) {
      l_nephew = brother->left_;
    }

    if (brother && !brother->color_) {
      if (r_nephew && l_nephew && (r_nephew->color_ || l_nephew->color_)) {
        if (l_nephew->color_ && (!r_nephew->color_ || r_nephew == end_node_)) {
          erase_black_without_children_and_black_brother_with_left_red_nephew(
              node, parent, brother);
        }
      } else if (((l_nephew && !l_nephew->color_) || !l_nephew) &&
                 ((r_nephew && !r_nephew->color_) || !r_nephew)) {
        erase_black_without_children_and_black_brother_with_black_nephews(
            node, parent, brother);
      }
    } else if (brother && brother->color_) {
      erase_black_without_children_and_red_brother(node, parent, brother);
    }
  }
}

template <class Key>
void s21::tree<Key>::
    erase_black_without_children_and_black_brother_with_black_nephews(
        s21::tree<Key>::node_ *node, s21::tree<Key>::node_ *parent,
        s21::tree<Key>::node_ *brother) {
  brother->color_ = true;

  if (!node->left_ && (!node->right_ || node->right_ == end_node_)) {
    if (parent->left_ == node) {
      parent->left_ = nullptr;
    } else if (parent->right_ == node) {
      parent->right_ = nullptr;
    }
    delete node;
  }
  if (!parent->color_) {
    erase_black_without_children(parent);
  }
  parent->color_ = false;
}

template <class Key>
void s21::tree<Key>::erase_black_without_children_and_red_brother(
    s21::tree<Key>::node_ *node, s21::tree<Key>::node_ *parent,
    s21::tree<Key>::node_ *brother) {
  brother->color_ = true;
  if (!node->left_ && (!node->right_ || node->right_ == end_node_)) {
    if (parent->left_ == node) {
      parent->left_ = nullptr;
    } else if (parent->right_ == node) {
      parent->right_ = nullptr;
    }
    if (node->right_ && node->right_ == end_node_) {
      end_node_->parent_ = node->parent_;
      node->parent_->right_ = end_node_;
    }
    delete node;
  }
  if (!parent->color_) {
    erase_black_without_children(parent);
  }
  parent->color_ = false;
}

template <class Key>
void s21::tree<Key>::erase_red(s21::tree<Key>::iterator pos) {
  if (!pos.itr_node_->left_ && !pos.itr_node_->right_) {
    erase_red_without_children(pos.itr_node_);
  } else if (pos.itr_node_->left_ && pos.itr_node_->right_) {
    erase_node_with_two_children(pos.itr_node_);
  }
}

template <class Key>
void s21::tree<Key>::erase_red_without_children(s21::tree<Key>::node_ *node) {
  if (node->parent_ && node->parent_->left_ == node) {
    node->parent_->left_ = nullptr;
  } else if (node->parent_ && node->parent_->right_ == node) {
    if (node->right_ && node->right_ == end_node_) {
      end_node_->parent_ = node->parent_;
      node->parent_->right_ = end_node_;
    } else {
      node->parent_->right_ = nullptr;
    }
  }
  delete node;
}

template <class Key>

void s21::tree<Key>::erase_node_with_two_children(s21::tree<Key>::node_ *node) {
  node_ *itr_node = node;
  if (itr_node->right_) {
    itr_node = itr_node->right_;
    while (itr_node->right_ && !itr_node->left_ &&
           itr_node->right_ != end_node_) {
      itr_node = itr_node->right_;
    }
    if (itr_node->left_) {
      itr_node = itr_node->left_;
    }
  }
  node->value_ = itr_node->value_;
  if (itr_node->color_) {
    erase_red_without_children(itr_node);
  } else {
    erase_black_without_children(itr_node);
  }
}

template <class Key>
void tree<Key>::
    erase_black_without_children_and_black_brother_with_left_red_nephew(
        s21::tree<Key>::node_ *node, s21::tree<Key>::node_ *parent,
        s21::tree<Key>::node_ *brother) {
  std::swap(brother->color_, brother->left_->color_);
  right_turn(brother);
  erase_black_without_children_and_black_brother_with_right_red_nephew(
      node, parent, brother);
}

template <class Key>
void tree<Key>::
    erase_black_without_children_and_black_brother_with_right_red_nephew(
        s21::tree<Key>::node_ *node, s21::tree<Key>::node_ *parent,
        s21::tree<Key>::node_ *brother) {
  brother->color_ = brother->parent_->color_;
  brother->parent_->color_ = false;
  brother->right_->color_ = false;
  left_turn(parent);
  if (parent->left_ == node) {
    parent->left_ = nullptr;
  } else if (parent->right_ == node) {
    parent->right_ = nullptr;
  }
  delete node;
}

// llrb tree
template <class Key>
bool s21::tree<Key>::insert(value_type value) {
  int status_of_insertion = 0;
  if (!contains(value)) {
    if (!root_) {
      root_ = create_node(value, false);
      end_node_ = new node_;
      end_node_->left_ = nullptr;
      end_node_->right_ = nullptr;
      begin_node_ = root_;
      end_node_->parent_ = root_;
      root_->right_ = end_node_;
      size_ += 1;
    } else {
      node_ *new_node = create_node(value, true);
      node_ *itr = root_;
      while (!status_of_insertion) {
        if (value < itr->value_) {
          if (!itr->left_) {
            itr->left_ = new_node;
            new_node->parent_ = itr;
            status_of_insertion = 1;
            size_ += 1;
          } else {
            itr = itr->left_;
          }
        } else if (value > itr->value_) {
          if (!itr->right_ || itr->right_ == end_node_) {
            itr->right_ = new_node;
            new_node->parent_ = itr;
            size_ += 1;
            status_of_insertion = 1;
          } else {
            itr = itr->right_;
          }
        } else {
          status_of_insertion = -1;
        }
      }
      balance_tree(new_node->parent_);
      update_side_nodes(new_node);
    }
  }
  return status_of_insertion;
}

template <class Key>
typename s21::tree<Key>::node_ *s21::tree<Key>::create_node(
    const value_type value, bool is_red) {
  auto node = new node_;
  node->left_ = nullptr;
  node->right_ = nullptr;
  node->parent_ = nullptr;
  node->color_ = is_red;
  node->value_ = value;
  return node;
}

template <class Key>
void tree<Key>::delete_node(node_ *node) {
  if (node == nullptr) {
    return;
  }

  if (node->left_ != nullptr) {
    delete_node(node->left_);
  }

  if (node->right_) {
    delete_node(node->right_);
  }

  delete node;
}

template <class Key>
void s21::tree<Key>::balance_tree(tree<Key>::node_ *node) {
  balance_node(node);
  if (node->parent_) {
    balance_tree(node->parent_);
  }
  root_->color_ = false;
}

template <class Key>
void s21::tree<Key>::balance_node(tree<Key>::node_ *node) {
  bool is_balanced = false;
  while (!is_balanced && node != end_node_) {
    is_balanced = true;
    if (node && node->right_ && node->right_->color_) {
      left_turn(node);
      node = node->parent_;
      is_balanced = false;
    }
    if (node && node->left_ && node->left_->left_ && node->left_->color_ &&
        node->left_->left_->color_) {
      right_turn(node);
      node = node->parent_;
      is_balanced = false;
    }
    if (node && node->left_ && node->right_ && !node->color_ &&
        node->left_->color_ && node->right_->color_) {
      color_swap(node);
      is_balanced = false;
    }
  }
}

template <class Key>
void s21::tree<Key>::right_turn(tree<Key>::node_ *node) {
  node_ *top_node = node;
  node_ *bottom_node = node->left_;
  bottom_node->color_ = top_node->color_;
  top_node->color_ = true;
  if (top_node == root_) {
    root_ = bottom_node;
  } else if (top_node->parent_->right_ == top_node) {
    top_node->parent_->right_ = bottom_node;
  } else if (top_node->parent_->left_ == top_node) {
    top_node->parent_->left_ = bottom_node;
  }

  if (bottom_node->right_) {
    bottom_node->right_->parent_ = top_node;
  }

  bottom_node->parent_ = top_node->parent_;
  top_node->parent_ = bottom_node;

  top_node->left_ = bottom_node->right_;
  bottom_node->right_ = top_node;

  node = bottom_node;
  node->right_ = top_node;
}

template <class Key>
void s21::tree<Key>::left_turn(tree<Key>::node_ *node) {
  node_ *top_node = node;
  node_ *bottom_node = node->right_;

  bottom_node->color_ = top_node->color_;
  top_node->color_ = true;
  if (top_node == root_) {
    root_ = bottom_node;
  } else if (top_node->parent_->right_ == top_node) {
    top_node->parent_->right_ = bottom_node;
  } else if (top_node->parent_->left_ == top_node) {
    top_node->parent_->left_ = bottom_node;
  }

  if (bottom_node->left_) {
    bottom_node->left_->parent_ = top_node;
  }

  bottom_node->parent_ = top_node->parent_;
  top_node->parent_ = bottom_node;

  top_node->right_ = bottom_node->left_;
  bottom_node->left_ = top_node;

  node = bottom_node;
  node->left_ = top_node;
}

template <class Key>
void s21::tree<Key>::color_swap(tree<Key>::node_ *node) {
  node->color_ = true;
  node->left_->color_ = false;
  node->right_->color_ = false;
}

template <class Key>
void s21::tree<Key>::update_side_nodes(node_ *node) {
  if (begin_node_->value_ > node->value_) {
    begin_node_ = node;
  }
  if (end_node_->parent_->value_ < node->value_) {
    if (end_node_->parent_->right_ == end_node_) {
      end_node_->parent_->right_ = nullptr;
    }
    end_node_->parent_ = node;
    node->right_ = end_node_;
  }
}

// tree_iterator methods
template <class Key>
void s21::tree<Key>::tree_iterator::operator=(node_ &node_) {
  itr_node_ = &node_;
}

template <class Key>
typename tree<Key>::value_type &s21::tree<Key>::tree_iterator::operator*() {
  return itr_node_->value_;
}

template <class Key>
typename tree<Key>::value_type *s21::tree<Key>::tree_iterator::operator->() {
  return &(itr_node_->value_);
}

template <class Key>
void s21::tree<Key>::tree_iterator::operator++() {
  if (itr_node_ && itr_node_->right_) {
    itr_node_ = itr_node_->right_;
    while (itr_node_ && itr_node_->left_) {
      itr_node_ = itr_node_->left_;
    }
  } else if (itr_node_->parent_) {
    node_ *parent_itr_node = itr_node_->parent_;
    while (itr_node_->parent_ && itr_node_->parent_->right_ == itr_node_) {
      itr_node_ = itr_node_->parent_;
      parent_itr_node = parent_itr_node->parent_;
    }
    itr_node_ = parent_itr_node;
  }
}

template <class Key>
void s21::tree<Key>::tree_iterator::operator--() {
  if (itr_node_->left_) {
    itr_node_ = itr_node_->left_;
    while (itr_node_->right_) {
      itr_node_ = itr_node_->right_;
    }
  } else {
    node_ *parent_itr_node = itr_node_->parent_;
    while (itr_node_->parent_ && itr_node_->parent_->left_ == itr_node_) {
      itr_node_ = itr_node_->parent_;
      parent_itr_node = parent_itr_node->parent_;
    }
    itr_node_ = parent_itr_node;
  }
}

template <class Key>
bool s21::tree<Key>::tree_iterator::operator!=(
    tree<Key>::tree_iterator iterator) {
  return itr_node_ != iterator.itr_node_;
}

template <class Key>
bool s21::tree<Key>::tree_iterator::operator==(
    tree<Key>::tree_iterator iterator) {
  return itr_node_ == iterator.itr_node_;
}

}  // namespace s21
