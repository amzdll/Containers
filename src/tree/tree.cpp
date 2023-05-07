#include "tree.h"

#include "set"

// TEMP
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class Key>
void s21::tree<Key>::printTree(tree<Key>::node_ *root_, std::string indent,
                               bool left) {
  node_ *iter_node = root_;
  if (iter_node) {
    std::cout << indent;
    std::cout << (left ? "├──" : "└──");
    if (iter_node->color_) {
      std::cout << "\033[1;31m(\033[0m" << iter_node->value_
                << "\033[1;31m)\033[0m" << std::endl;
    } else {
      std::cout << "\033[1;37m(\033[0m" << iter_node->value_
                << "\033[1;37m)\033[0m" << std::endl;
    }
    printTree(iter_node->left_, indent + (left ? "│   " : "    "), true);
    printTree(iter_node->right_, indent + (left ? "│   " : "    "), false);
  }
}

namespace s21 {
// Member functions
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class Key>
s21::tree<Key>::tree() {
  begin_node_ = new node_;
  end_node_ = new node_;
}

template <class Key>
tree<Key>::tree(const std::initializer_list<value_type> &items) {
  begin_node_ = new node_;
  end_node_ = new node_;
  if (items.size()) {
    auto itr = items.begin();
    while (itr != items.end()) {
      push(*itr);
      ++itr;
    }
  }
}

template <class Key>
tree<Key>::~tree() {
  clear();
}

// Element access
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// fix text of throw
// template <class Key>
// T &s21::tree<Key>::at(const Key &key) {
//  for (iterator itr = begin(); itr != end(); ++itr) {
//    if (itr->first == key) {
//      return itr->second;
//    }
//  }
//  throw std::out_of_range("at");
//}

// template <class Key>
// T& s21::tree<Key>::operator[](const Key& key) {
//   bool in_tree = false;
//   iterator itr = begin();
//   for (; itr != end(); ++itr) {
//     if (itr->first == key) {
//       return (*itr).second;
//     }
//   }
//   return (*itr).second;
// }

// Iterators
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class Key>
typename s21::tree<Key>::iterator s21::tree<Key>::begin() {
  tree<Key>::iterator iterator;
  auto itr_node = begin_node_;
  iterator = *itr_node;
  return iterator;
}

template <class Key>
typename s21::tree<Key>::iterator s21::tree<Key>::end() {
  tree<Key>::iterator iterator;
  auto itr_node = end_node_;
  iterator = *itr_node;
  return iterator;
}

// Capacity
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class Key>
bool s21::tree<Key>::empty() {
  return size_;
}

template <class Key>
size_t s21::tree<Key>::size() {
  return size_;
}

// Modifiers
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class Key>
void s21::tree<Key>::clear() {
  deleteNode(root_);
  //  root_ = NULL;
  //  begin_node_ = NULL;
  //  end_node_ = NULL;
  size_ = 0;
  //  delete begin_node_;
  //  delete end_node_;
}

// fix begin and end iterators
template <class Key>
void s21::tree<Key>::erase(s21::tree<Key>::iterator pos) {
  auto itr = pos;
  if (pos.itr_node_) {
    if (!pos.itr_node_->left_ && !pos.itr_node_->right_) {
      if (pos.itr_node_->parent_ &&
          pos.itr_node_->parent_->right_ == pos.itr_node_) {
        pos.itr_node_->parent_->right_ = NULL;
      } else if (pos.itr_node_->parent_ &&
                 pos.itr_node_->parent_->left_ == pos.itr_node_) {
        pos.itr_node_->parent_->left_ = NULL;
      }
      delete pos.itr_node_;
    }
    if (pos.itr_node_->left_ && !pos.itr_node_->right_) {
      if (pos.itr_node_->parent_) {
        itr.itr_node_->parent_->left_ = itr.itr_node_->left_;
      }
      itr.itr_node_->left_->parent_ = itr.itr_node_->parent_;
    } else if (pos.itr_node_->right_ && !pos.itr_node_->left_) {
      if (pos.itr_node_->parent_) {
        itr.itr_node_->parent_->right_ = itr.itr_node_->right_;
      }
      itr.itr_node_->right_->parent_ = itr.itr_node_->parent_;
    }
    if (pos.itr_node_->left_ && pos.itr_node_->right_) {

    }
    //    if (pos.itr_node_->parent_ && pos.itr_node_->parent_->color_) {
    //      pos.itr_node_->parent_->color_ = false;
    //    }
    //    if (pos.itr_node_->right_ && pos.itr_node_->left_) {
    //      while (itr.itr_node_->right_ && itr.itr_node_->right_ != end_node_) {
    //        itr.itr_node_ = itr.itr_node_->right_;
    //      }
    //      pos.itr_node_->value_ = itr.itr_node_->value_;
    //      itr.itr_node_->parent_->right_ = NULL;
    //      delete itr.itr_node_;
    //    } else if (!pos.itr_node_->right_ && !pos.itr_node_->left_) {
    //      if (pos.itr_node_->parent_ &&
    //          pos.itr_node_->parent_->right_ == pos.itr_node_) {
    //        pos.itr_node_->parent_->right_ = NULL;
    //      } else if (pos.itr_node_->parent_ &&
    //                 pos.itr_node_->parent_->left_ == pos.itr_node_) {
    //        pos.itr_node_->parent_->left_ = NULL;
    //      }
    //      delete itr.itr_node_;
    //    } else if (!pos.itr_node_->right_ || !pos.itr_node_->left_) {
    //      if (pos.itr_node_->parent_ &&
    //          pos.itr_node_->parent_->right_ == pos.itr_node_) {
    //        pos.itr_node_->right_->parent_ = pos.itr_node_->parent_;
    //        pos.itr_node_->parent_->right_ = pos.itr_node_->right_;
    //
    //      } else if (pos.itr_node_->parent_ &&
    //                 pos.itr_node_->parent_->left_ == pos.itr_node_) {
    //        pos.itr_node_->left_->parent_ = pos.itr_node_->parent_;
    //        pos.itr_node_->parent_->left_ = pos.itr_node_->left_;
    //      }
    //      delete itr.itr_node_;
    //    }
    //    balanceTree(pos.itr_node_);
    //    balanceTree(end_node_);
    //    balanceTree(begin_node_);
  }
}

// MODIFY TREE METHODS
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class Key>
bool s21::tree<Key>::push(value_type value) {
  bool status = false;
  if (!root_) {
    root_ = create_node(value, false);
    begin_node_ = root_;
    end_node_->parent_ = root_;
    root_->right_ = end_node_;
    size_ += 1;
  } else {
    node_ *new_node = create_node(value, true);
    for (auto itr = begin(); itr != end() && !status; ++itr) {
      if (!itr.itr_node_->left_ && value < itr.itr_node_->value_) {
        itr.itr_node_->left_ = new_node;
        new_node->parent_ = itr.itr_node_;
        status = true;
        size_ += 1;
      } else if ((itr.itr_node_->right_ == end_node_ ||
                  !itr.itr_node_->right_) &&
                 value < itr.itr_node_->parent_->value_ &&
                 value > itr.itr_node_->value_) {
        itr.itr_node_->right_ = new_node;
        new_node->parent_ = itr.itr_node_;
        size_ += 1;
        status = true;
      }
    }
    balanceTree(new_node->parent_);
    updateSideNodes(new_node);
  }
  return status;
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
void tree<Key>::deleteNode(node_ *node) {
  if (node) {
    deleteNode(node->left_);
    deleteNode(node->right_);
    delete node;
    //    node = NULL;
  }
}

// Lookup
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// template <class Key>
// bool s21::tree<Key>::contains(const Key& key) {
//   return at(key);
// }

template <class Key>
typename s21::tree<Key>::iterator tree<Key>::find(const Key &key) {
  s21::tree<Key>::iterator pos = end();
  for (s21::tree<Key>::iterator itr = begin(); itr != end(); ++itr) {
    if (key == itr.itr_node_->value_) {
      pos = itr;
    }
  }
  return pos;
}

// Balance
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class Key>
void s21::tree<Key>::balanceTree(node_ *node) {
  balanceNode(node);
  if (node->parent_) {
    balanceTree(node->parent_);
  }
  root_->color_ = false;
}

template <class Key>
void s21::tree<Key>::balanceNode(tree<Key>::node_ *node) {
  bool is_balanced = false;
  while (!is_balanced && node != end_node_) {
    is_balanced = true;
    if (node && node->right_ && node->right_->color_) {
      leftTurn(node);
      node = node->parent_;
      is_balanced = false;
    }
    if (node && node->left_ && node->left_->left_ && node->left_->color_ &&
        node->left_->left_->color_) {
      rightTurn(node);
      node = node->parent_;
      is_balanced = false;
    }
    if (node && node->left_ && node->right_ && !node->color_ &&
        node->left_->color_ && node->right_->color_) {
      colorSwap(node);
      is_balanced = false;
    }
  }
}

template <class Key>
void s21::tree<Key>::rightTurn(tree<Key>::node_ *node) {
  node_ *top_node = node;
  node_ *bottom_node = node->left_;
  top_node->color_ = true;
  bottom_node->color_ = false;
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
void s21::tree<Key>::leftTurn(tree<Key>::node_ *node) {
  node_ *top_node = node;
  node_ *bottom_node = node->right_;
  top_node->color_ = true;
  bottom_node->color_ = false;
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
void s21::tree<Key>::colorSwap(tree<Key>::node_ *node) {
  node->color_ = true;
  node->left_->color_ = false;
  node->right_->color_ = false;
}

template <class Key>
void s21::tree<Key>::updateSideNodes(node_ *node) {
  if (begin_node_->value_ > node->value_) {
    begin_node_ = node;
  }
  if (end_node_->parent_->value_ < node->value_) {
    end_node_->parent_->right_ = NULL;
    end_node_->parent_ = node;
    node->right_ = end_node_;
  }
}

// ITERATORS
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class Key>
void s21::tree<Key>::TreeIterator::operator=(node_ &node_) {
  itr_node_ = &node_;
}

template <class Key>
Key &s21::tree<Key>::TreeIterator::operator*() {
  return itr_node_->value_;
}

template <class Key>
Key *s21::tree<Key>::TreeIterator::operator->() {
  return &(itr_node_->value_);
}

template <class Key>
void s21::tree<Key>::TreeIterator::operator++() {
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
void s21::tree<Key>::TreeIterator::operator--() {
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
bool s21::tree<Key>::TreeIterator::operator!=(
    tree<Key>::TreeIterator iterator) {
  return itr_node_ != iterator.itr_node_;
}

template <class Key>
bool s21::tree<Key>::TreeIterator::operator==(
    tree<Key>::TreeIterator iterator) {
  return itr_node_ != iterator.itr_node_;
}

}  // namespace s21

int main() {
  std::set<int> set({24, 5, 1, 15, 3, 8});
  s21::tree<int> test({24, 5, 1, 15, 3, 8});

  auto itr = test.begin();
  ++itr;
  ++itr;
  ++itr;

  auto a = test.find(5);
  //  a = set.find(24);
  //  std::cout << a << std::endl;
  test.erase(a);

  test.printTree(test.get_root(), "", false);
}
