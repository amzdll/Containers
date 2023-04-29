#include "test.h"

//////////////////////////////////////////////////////////////////////////////////////////////////
namespace s21 {

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
        }
      } else if (value.first > iter_node->value_.first) {
        if (iter_node->right_) {
          iter_node = iter_node->right_;
        } else {
          iter_node->right_ = new_node;
          new_node->parent_ = iter_node;
        }
      }
    }
    balanceTree(root_);
  }
}

template <class Key, class T>
void s21::tree<Key, T>::balanceTree(node_ *node) {
  auto *node_copy = node;
  bool is_balanced = false;
  if (!is_balanced) {
    if (node && node->left_ && node->left_->left_ && node->left_->color_ &&
        node->left_->left_->color_) {
      rightTurn(node);
    } else {
      is_balanced = true;
    }
    if (node && node->left_ && node->right_ && !node->color_ &&
        node->left_->color_ && node->left_->color_) {
      colorSwap(node);
    } else {
      is_balanced = true;
    }
    if (node && node->left_ && node->right_ && node->right_->color_ &&
        !node->left_->color_) {
    } else {
      is_balanced = true;
    }
    root_->color_ = false;

    if(node->left_) {
      balanceTree(node->left_);
    } else if (node->right_) {
      balanceTree(node->right_);
    }
  }
}


template <class Key, class T>
void s21::tree<Key, T>::colorSwap(tree<Key, T>::node_ *node) {
  node->color_ = true;
  node->left_->color_ = false;
  node->right_->color_ = false;
}

template <class Key, class T>
void s21::tree<Key, T>::rightTurn(tree<Key, T>::node_ *node) {
  node_ *parent_node = node;
  node_ *central_node = node->left_;
  if (parent_node == root_) {
    root_ = central_node;
  }
  parent_node->color_ = true;
  central_node->color_ = false;
  parent_node->right_ = central_node->right_;
  parent_node->left_ = nullptr;
  central_node->right_ = parent_node;
  central_node->parent_ = parent_node->parent_;
  parent_node->parent_ = central_node;

  node->parent_ = central_node;
  node = parent_node;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class Key, class T>
void s21::tree<Key, T>::printTree(tree<Key, T>::node_ *root_,
                                  std::string indent, bool left) {
  node_ *iter_node = root_;
  if (iter_node) {
    std::cout << indent;
    std::cout << (left ? "├──" : "└──" );
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
  s21::tree<int, int> tree;
  tree.insert(std::pair<int, int>(24, 24));
  tree.insert(std::pair<int, int>(5, 5));
  tree.insert(std::pair<int, int>(1, 1));
  tree.insert(std::pair<int, int>(15, 15));
  tree.insert(std::pair<int, int>(3, 3));
  tree.insert(std::pair<int, int>(8, 8));

  tree.printTree(tree.get_root(), "", false);
}