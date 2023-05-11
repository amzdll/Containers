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
  if (pos.itr_node_->color_) {
    eraseRed(pos);
  } else {
    eraseBlack(pos);
  }
}

template <class Key>
void s21::tree<Key>::eraseBlack(s21::tree<Key>::iterator pos) {
  if (!pos.itr_node_->right_ && !pos.itr_node_->left_) {
    //    pos.itr_node_->parent_->left_ = NULL;
    eraseBlackWithoutChildren(pos.itr_node_);
  } else if (pos.itr_node_->right_ && pos.itr_node_->left_) {
    eraseNodeWithTwoChildren(pos.itr_node_);
  } else {
    eraseBlackWithOneChild(pos.itr_node_);
  }
}

template <class Key>
void s21::tree<Key>::eraseBlackWithOneChild(s21::tree<Key>::node_ *node) {
  if (node->left_ && !node->right_) {
    node->value_ = node->left_->value_;
    delete node->left_;
    node->left_ = NULL;
  } else if (!node->left_ && node->right_ && node->right_ != end_node_) {
    node->value_ = node->right_->value_;
    delete node->right_;
    node->left_ = NULL;
  }
}

template <class Key>
void s21::tree<Key>::eraseBlackWithoutChildren(s21::tree<Key>::node_ *node) {
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
    if (!brother->color_ &&
        ((l_nephew && !l_nephew->color_) || !l_nephew) &&
        ((r_nephew && !r_nephew->color_) || !r_nephew)) {
      brother->color_ = true;
      if (!parent->color_) {
//        parent->color_ = true;
        eraseBlackWithoutChildren(parent);
//        balanceTree(parent);
      }
    }
  }
}

// brother - black
//  if (node->parent_) {
//    node_ *parent = node->parent_;
//    if (parent->right_ == node && parent->left_ &&
//        ((parent->left_->left_ && !parent->left_->left_->color_) ||
//         !parent->left_->left_) &&
//        ((parent->left_->right_ && !parent->left_->right_->color_) ||
//         !parent->left_->right_)) {
//      parent->left_->color_ = true;
//      //      node->parent_->right_ = NULL;
//    } else if (parent->left_ == node && parent->right_ &&
//               ((parent->right_->left_ && !parent->right_->left_->color_) ||
//                !parent->right_->left_) &&
//               ((parent->right_->right_ && !parent->right_->right_->color_)
//               ||
//                !parent->right_->right_)) {
//      parent->right_->color_ = true;
//      //      node->parent_->left_ = NULL;
//    }
//    if (!parent->color_) {
//      printTree(root_, "", false);
//      parent->color_ = true;
//      balanceTree(parent);
//      eraseBlackWithoutChildren(parent);
//    }

template <class Key>
void s21::tree<Key>::eraseRed(s21::tree<Key>::iterator pos) {
  if (!pos.itr_node_->left_ && !pos.itr_node_->right_) {
    eraseRedWithoutChildren(pos.itr_node_);
  } else if (pos.itr_node_->left_ && pos.itr_node_->right_) {
    eraseNodeWithTwoChildren(pos.itr_node_);
  }
  //  else {
  //    eraseRedWithOneChild(pos.itr_node_);
  //  }
}

template <class Key>
void s21::tree<Key>::eraseRedWithoutChildren(s21::tree<Key>::node_ *node) {
  if (node->parent_ && node->parent_->left_ == node) {
    node->parent_->left_ = NULL;
  } else if (node->parent_ && node->parent_->right_ == node) {
    if (node->right_ && node->right_ == end_node_) {
      end_node_->parent_ = node->parent_;
      node->parent_->right_ = end_node_;
    } else {
      node->parent_->right_ = NULL;
    }
  }
  delete node;
}

template <class Key>

void s21::tree<Key>::eraseNodeWithTwoChildren(s21::tree<Key>::node_ *node) {
  node_ *itr_node = node;
  if (itr_node->right_) {
    while (itr_node->right_ || itr_node->left_) {
      if (itr_node->right_ && itr_node->right_ != end_node_) {
        itr_node = itr_node->right_;
      } else if (itr_node->left_) {
        itr_node = itr_node->left_;
      }
    }
    node->value_ = itr_node->value_;
    if (itr_node->color_) {
      eraseRedWithoutChildren(itr_node);
    }
  }
}
// MODIFY TREE METHODS
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class Key>
bool s21::tree<Key>::push(value_type value) {
  // refactor on find
  int status_of_insertion = 0;
  if (!root_) {
    root_ = create_node(value, false);
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
    balanceTree(new_node->parent_);
    updateSideNodes(new_node);
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
void s21::tree<Key>::leftTurn(tree<Key>::node_ *node) {
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
    if (end_node_->parent_->right_ == end_node_) {
      end_node_->parent_->right_ = NULL;
    }
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
  //    s21::tree<int> test(
  //        {453, 855, 562, 985});
  //    , 126, 956, 350, 412, 32, 17, 251, 284, 932, 820
  //  s21::tree<int> test ({10, 20, 30, 25, 35});
  s21::tree<int> test;
  test.push(453);
  test.push(855);
  test.push(562);
  test.push(985);
  test.push(126);
  test.push(956);
  test.push(350);
  //  test.push(412);
  //  test.push(32);

  auto a = test.find(453);
  test.erase(a);

  test.printTree(test.get_root(), "", false);
}
