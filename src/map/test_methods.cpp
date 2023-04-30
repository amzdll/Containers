#include "test.h"

// element acess

template <class Key, class T>
T& s21::tree<Key, T>::at(const Key& key) {
    node_* iter_node = root_;
    bool isFinded = false;
    while (!isFinded) {
        if (key == iter_node->value_.first) {
            isFinded = true;
        } else if (key < iter_node->value_.first) {
            if (iter_node->left_) {
                iter_node = iter_node->left_;
            } else {
                isFinded = true;
                iter_node->value_.second = 0;

            }
        } else if (key > iter_node->value_.first) {
            if (iter_node->right_) {
                iter_node = iter_node->right_;
                iter_node->value_.second = 0;
            } else {
                isFinded = true;
            }
        }
    }
    return iter_node->value_.second;
}

template <class Key, class T>
T& s21::tree<Key, T>::operator[](const Key& key) {
    //    T value = 0;
    //    node_ *iter_node = root_;
    //    node_ *new_node = create_node(value, true);
    //    while (!new_node->parent_) {
    //        if (value.first < iter_node->value_.first) {
    //            if (iter_node->left_) {
    //                iter_node = iter_node->left_;
    //            } else {
    //                iter_node->left_ = new_node;
    //                new_node->parent_ = iter_node;
    //                size_ += 1;
    //            }
    //        } else if (value.first > iter_node->value_.first) {
    //            if (iter_node->right_) {
    //                iter_node = iter_node->right_;
    //            } else {
    //                iter_node->right_ = new_node;
    //                new_node->parent_ = iter_node;
    //                size_ += 1;
    //            }
    //        }
    //    };
}

// map iterators
template <class Key, class T>
typename s21::tree<Key, T>::iterator s21::tree<Key, T>::begin() {
    tree<Key, T>::iterator iterator;
    node_* itr_node = root_;
    while (itr_node->left_) {
        itr_node = itr_node->left_;
    }
    iterator = *itr_node;
    return iterator;
}


template <class Key, class T>
bool s21::tree<Key, T>::empty() {
    return !root_;
}

template <class Key, class T>
size_t s21::tree<Key, T>::size() {
    return size_;
}

// Map Lookup
template <class Key, class T>
bool s21::tree<Key, T>::contains(const Key& key) {
    node_* iter_node = root_;
    bool isFinded = false;
    T value = 0;
    while (!isFinded) {
        if (key == iter_node->value_.first) {
            value = iter_node->value_.second;
            isFinded = true;
        } else if (key < iter_node->value_.first) {
            if (iter_node->left_) {
                iter_node = iter_node->left_;
            } else {
                isFinded = true;
            }
        } else if (key > iter_node->value_.first) {
            if (iter_node->right_) {
                iter_node = iter_node->right_;
            } else {
                isFinded = true;
            }
        }
    }
    return value;
}

// Iterator Overload

template <class Key, class T>
s21::tree<Key, T>::TreeIterator::TreeIterator() {}

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

