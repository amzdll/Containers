#include "tree.h"
// TEMP
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class Key, class T>
void s21::tree<Key, T>::printTree(tree<Key, T>::node_ *root_,
                                  std::string indent, bool left) {
  node_ *iter_node = root_;
  if (iter_node) {
    std::cout << indent;
    std::cout << (left ? "├──" : "└──");
    if (iter_node->color_) {
      std::cout << "\033[1;31m(\033[0m" << iter_node->value_.first
                << "\033[1;31m)\033[0m" << std::endl;
    } else {
      std::cout << "\033[1;37m(\033[0m" << iter_node->value_.first
                << "\033[1;37m)\033[0m" << std::endl;
    }
    printTree(iter_node->left_, indent + (left ? "│   " : "    "), true);
    printTree(iter_node->right_, indent + (left ? "│   " : "    "), false);
  }
}

// CONSTRUCTORS
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class Key, class T>
s21::tree<Key, T>::tree() {
  begin_node_ = new node_;
  end_node_ = new node_;
}

namespace s21 {
template <class Key, class T>
tree<Key, T>::tree(const std::initializer_list<value_type> &items) {
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

template <class Key, class T>
tree<Key, T>::~tree() {
  clear();
}

template <class Key, class T>
void tree<Key, T>::deleteNode(node_ *node) {
  if (node) {
    deleteNode(node->left_);
    deleteNode(node->right_);
    delete node;
//    node = NULL;
  }
}

// capacity
template <class Key, class T>
bool s21::tree<Key, T>::empty() {
  return size_;
}

template <class Key, class T>
size_t s21::tree<Key, T>::size() {
  return size_;
}

// MODIFY METHODS
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class Key, class T>
void s21::tree<Key, T>::clear() {
  deleteNode(root_);
//  root_ = NULL;
//  begin_node_ = NULL;
  size_ = 0;
//  delete begin_node_;
  delete end_node_;
  end_node_ = NULL;
}

template <class Key, class T>
bool s21::tree<Key, T>::push(const value_type value) {
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
      if (!itr.itr_node_->left_ && value.first < itr.itr_node_->value_.first) {
        itr.itr_node_->left_ = new_node;
        new_node->parent_ = itr.itr_node_;
        status = true;
        size_ += 1;
      } else if ((itr.itr_node_->right_ == end_node_ ||
                  !itr.itr_node_->right_) &&
                 value.first < itr.itr_node_->parent_->value_.first &&
                 value.first > itr.itr_node_->value_.first) {
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

// fix begin and end iterators
template <class Key, class T>
void s21::tree<Key, T>::erase(s21::tree<Key, T>::iterator pos) {
  auto itr = pos;
  if (pos.itr_node_->right_ && pos.itr_node_->left_) {
    while (itr.itr_node_->right_ && itr.itr_node_->right_ != end_node_) {
      itr.itr_node_ = itr.itr_node_->right_;
    }
    pos.itr_node_->value_ = itr.itr_node_->value_;
    itr.itr_node_->parent_->right_ = NULL;
    delete itr.itr_node_;
  } else if (!pos.itr_node_->right_ && !pos.itr_node_->left_) {
    if (pos.itr_node_->parent_ &&
        pos.itr_node_->parent_->right_ == pos.itr_node_) {
      pos.itr_node_->parent_->right_ = NULL;
    } else if (pos.itr_node_->parent_ &&
               pos.itr_node_->parent_->left_ == pos.itr_node_) {
      pos.itr_node_->parent_->left_ = NULL;
    }
    delete itr.itr_node_;
  } else if (!pos.itr_node_->right_ || !pos.itr_node_->left_) {
    if (pos.itr_node_->parent_ &&
        pos.itr_node_->parent_->right_ == pos.itr_node_) {
      pos.itr_node_->right_->parent_ = pos.itr_node_->parent_;
      pos.itr_node_->parent_->right_ = pos.itr_node_->right_;

    } else if (pos.itr_node_->parent_ &&
               pos.itr_node_->parent_->left_ == pos.itr_node_) {
      pos.itr_node_->left_->parent_ = pos.itr_node_->parent_;
      pos.itr_node_->parent_->left_ = pos.itr_node_->left_;
    }
    delete itr.itr_node_;
  }
  //  if ()
  //    balanceTree(end_node_);
}

template <class Key, class T>
typename s21::tree<Key, T>::node_ *s21::tree<Key, T>::create_node(
    const value_type value, bool is_red) {
  auto node = new node_;
  node->left_ = nullptr;
  node->right_ = nullptr;
  node->parent_ = nullptr;
  node->color_ = is_red;
  node->value_ = value;
  return node;
}

// BALANCE
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class Key, class T>
void s21::tree<Key, T>::balanceTree(node_ *node) {
  balanceNode(node);
  if (node->parent_) {
    balanceTree(node->parent_);
  }
  root_->color_ = false;
}

template <class Key, class T>
void s21::tree<Key, T>::balanceNode(tree<Key, T>::node_ *node) {
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

template <class Key, class T>
void s21::tree<Key, T>::rightTurn(tree<Key, T>::node_ *node) {
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

template <class Key, class T>
void s21::tree<Key, T>::leftTurn(tree<Key, T>::node_ *node) {
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

template <class Key, class T>
void s21::tree<Key, T>::colorSwap(tree<Key, T>::node_ *node) {
  node->color_ = true;
  node->left_->color_ = false;
  node->right_->color_ = false;
}

template <class Key, class T>
void s21::tree<Key, T>::updateSideNodes(node_ *node) {
  if (begin_node_->value_.first > node->value_.first) {
    begin_node_ = node;
  }
  if (end_node_->parent_->value_.first < node->value_.first) {
    end_node_->parent_->right_ = NULL;
    end_node_->parent_ = node;
    node->right_ = end_node_;
  }
}

// ITERATORS
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class Key, class T>
s21::tree<Key, T>::TreeIterator::TreeIterator() {}

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
  return iterator;
}

template <class Key, class T>
void s21::tree<Key, T>::TreeIterator::operator=(node_ &node_) {
  itr_node_ = &node_;
}

template <class Key, class T>
std::pair<Key, T> &s21::tree<Key, T>::TreeIterator::operator*() {
  return itr_node_->value_;
}

template <class Key, class T>
std::pair<Key, T> *s21::tree<Key, T>::TreeIterator::operator->() {
  return &(itr_node_->value_);
}

template <class Key, class T>
void s21::tree<Key, T>::TreeIterator::operator++() {
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

template <class Key, class T>
void s21::tree<Key, T>::TreeIterator::operator--() {
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

}  // namespace s21

int main() {
  //  s21::tree<int, int> tree;
  s21::tree<int, int> test;
//  test.push({24, 25});
//  test.push({5, 5});
  //  test.push({1, 1});
  //  test.push({15, 15});
  //  test.push({3, 3});
  //  test.push({8, 8});
  //  test.push({13, 13});
  //  test.push({14, 14});

  auto itr = test.end();
  std::cout << test.size() << std::endl;

  test.clear();

//  auto a = test.get_root();
  //  --itr;
  //  --itr;
  //
  //  test.erase(itr);
  //  std::cout << itr->first << std::endl;

  test.printTree(test.get_root(), "", false);
}
