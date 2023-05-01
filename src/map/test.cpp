#include "test.h"

#include "map"
#include "test_methods.cpp"

namespace s21 {

template <class Key, class T>
tree<Key, T>::tree(const std::initializer_list<value_type> &items) {
  if (items.size()) {
    auto itr = items.begin();
    while (itr != items.end()) {
      insert(*itr);
      ++itr;
    }
  }
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

template <class Key, class T>
void s21::tree<Key, T>::insert(const value_type value) {
  if (!root_) {
    root_ = create_node(value, false);
  } else {
    node_ *iter_node = root_;
    node_ *new_node = create_node(value, true);
    while (!new_node->parent_) {
      if (value.first < iter_node->value_.first) {
        if (iter_node->left_) {
          iter_node = iter_node->left_;
        } else {
          iter_node->left_ = new_node;
          new_node->parent_ = iter_node;
          size_ += 1;
        }
      } else if (value.first > iter_node->value_.first) {
        if (iter_node->right_) {
          iter_node = iter_node->right_;
        } else {
          iter_node->right_ = new_node;
          new_node->parent_ = iter_node;
          size_ += 1;
        }
      }
    }
    balanceTree(root_);
    balanceTree(root_);
  }
}

template <class Key, class T>
void s21::tree<Key, T>::balanceTree(node_ *node) {
  bool is_balanced = false;
  while (!is_balanced) {
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
  if (node->left_) {
    balanceTree(node->left_);
  }
  if (node->right_) {
    balanceTree(node->right_);
  }
  root_->color_ = false;
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
}  // namespace s21

int main() {
  s21::tree<int, int> tree(
      {std::pair<int, int>(10, 10), std::pair<int, int>(20, 20),
       std::pair<int, int>(30, 30), std::pair<int, int>(40, 40),
       std::pair<int, int>(50, 50), std::pair<int, int>(60, 60),
       std::pair<int, int>(70, 70), std::pair<int, int>(25, 25),
       std::pair<int, int>(55, 55), std::pair<int, int>(22, 22)});

  std::map<int, int> test(
      {std::pair<int, int>(10, 10), std::pair<int, int>(20, 20),
       std::pair<int, int>(30, 30), std::pair<int, int>(40, 40),
       std::pair<int, int>(50, 50), std::pair<int, int>(55, 55),
       std::pair<int, int>(60, 60), std::pair<int, int>(70, 70),
       std::pair<int, int>(25, 25), std::pair<int, int>(22, 22)});
  //    s21::tree<int, int> tree;
  //    tree.insert(std::pair<int, int>(24, 24));
  //    tree.insert(std::pair<int, int>(5, 5));
  //    tree.insert(std::pair<int, int>(1, 3));
  //    tree.insert(std::pair<int, int>(15, 15));
  //    tree.insert(std::pair<int, int>(3, 3));
  //    tree.insert(std::pair<int, int>(8, 8));
  //    tree.insert(std::pair<int, int>(12, 12));
  //    tree.insert(std::pair<int, int>(16, 16));

  auto a = test.begin();
  s21::tree<int, int>::iterator b = tree.begin();
  ++a;
  ++a;
  ++a;
  ++a;
  ++a;
  ++a;
  ++a;
  ++a;
  ++a;
  ++a;


  ++b;
  ++b;
  ++b;
  ++b;
  ++b;
  ++b;
  ++b;
  ++b;
  ++b;
  ++b;
//  auto z = test.end();
//  --z;
  test.insert({80, 80});
  std::cout << a->first  << std::endl;
  std::cout << b->first << std::endl;

  tree.printTree(tree.get_root(), "", false);
}