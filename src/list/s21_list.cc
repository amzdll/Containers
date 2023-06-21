#include "s21_list.h"

// Constructors
template <class T>
s21::list<T>::list() {
  end_node_ = new node_;
}

template <class T>
s21::list<T>::list(size_type n) {
  end_node_ = new node_;
  for (size_type i = 0; i < n; ++i) {
    push_back(T());
  }
}

template <class T>
s21::list<T>::list(std::initializer_list<value_type> const &items) {
  end_node_ = new node_;
  for (auto itr = items.begin(); itr != items.end(); ++itr) {
    push_back(*itr);
  }
}

template <class T>
s21::list<T>::list(const list &l) {
  end_node_ = new node_;
  for (auto itr = l.begin(); itr != l.end(); ++itr) {
    push_back(*itr);
  }
}

template <class T>
s21::list<T>::list(list &&l) {
  MoveList(l);
}

template <class T>
s21::list<T>::~list() {
  clear();
}

// Overload operators
template <class T>
s21::list<T> s21::list<T>::operator=(list &&l) {
  clear();
  MoveList(l);
  return *this;
}

// Element access
template <class T>
typename s21::list<T>::const_reference s21::list<T>::front() const {
  static const T default_value = T();
  if (size_ > 0) {
    return head_->value_;
  } else {
    return default_value;
  }
}

template <class T>
typename s21::list<T>::const_reference s21::list<T>::back() const {
  static const T default_value = T();
  if (size_ > 0) {
    return tail_->value_;
  } else {
    return default_value;
  }
}

// Iterators
template <class T>
typename s21::list<T>::iterator s21::list<T>::begin() const {
  s21::list<T>::iterator iterator;
  if (head_) {
    iterator = *head_;
  } else {
    iterator = *end_node_;
  }
  return iterator;
}

template <class T>
typename s21::list<T>::iterator s21::list<T>::end() const {
  s21::list<T>::iterator iterator;
  if (end_node_) {
    iterator = *end_node_;
  }
  return iterator;
}

// Capacity
template <class T>
bool s21::list<T>::empty() const {
  return !size();
}

template <class T>
typename s21::list<T>::size_type s21::list<T>::size() const {
  return size_;
}

template <class T>
typename s21::list<T>::size_type s21::list<T>::max_size() const {
  return std::numeric_limits<size_type>::max();
}

// Modifiers
template <class T>
void s21::list<T>::clear() {
  if (size_ > 0) {
    head_->previous_ = nullptr;
    end_node_->next_ = nullptr;
  } else {
    head_ = nullptr;
  }
  if (head_) {
    node_ *deletable_node = nullptr;
    while (head_) {
      deletable_node = head_;
      head_ = head_->next_;
      delete deletable_node;
    }
    size_ = 0;
  } else {
    delete end_node_;
  }
  end_node_ = nullptr;
}

template <class T>
typename s21::list<T>::iterator s21::list<T>::insert(iterator pos,
                                                     const_reference value) {
  node_ *current_node = pos.itr_node_;
  node_ *new_value = new node_{value};
  if (size_ > 0) {
    if (current_node == head_) {
      new_value->next_ = head_;
      new_value->previous_ = end_node_;
      head_->previous_ = new_value;
      new_value->next_ = current_node;
      end_node_->next_ = new_value;
      head_ = new_value;
    } else if (current_node == end_node_) {
      new_value->previous_ = tail_;
      tail_->next_ = new_value;
      new_value->next_ = end_node_;
      new_value->previous_ = current_node;
      end_node_->previous_ = new_value;
      tail_ = new_value;
    } else {
      current_node->previous_->next_ = new_value;
      new_value->previous_ = current_node->previous_;
      new_value->next_ = current_node;
      current_node->previous_ = new_value;
    }
  } else {
    new_value->next_ = end_node_;
    new_value->previous_ = end_node_;
    end_node_->next_ = new_value;
    end_node_->previous_ = new_value;
    head_ = new_value;
    tail_ = new_value;
  }
  pos.itr_node_ = new_value;
  ++size_;
  return pos;
}

template <class T>
void s21::list<T>::erase(iterator pos) {
  node_ *current_node = pos.itr_node_;
  if (size_ > 0 && current_node != end_node_) {
    node_ *next_node = current_node->next_;
    node_ *previous_node = current_node->previous_;
    if (current_node == head_) {
      head_ = next_node;
    } else {
      previous_node->next_ = next_node;
    }
    if (current_node == tail_) {
      tail_ = previous_node;
    } else {
      next_node->previous_ = previous_node;
    }
    delete current_node;
    --size_;
  }
}

template <class T>
void s21::list<T>::push_back(const_reference value) {
  auto *new_node = new node_;
  new_node->value_ = value;
  new_node->next_ = end_node_;
  end_node_->previous_ = new_node;
  if (head_) {
    new_node->previous_ = tail_;
    tail_->next_ = new_node;
    tail_ = new_node;
    end_node_->next_ = head_;
    head_->previous_ = end_node_;
  } else {
    head_ = new_node;
    tail_ = head_;
  }
  ++size_;
}

template <class T>
void s21::list<T>::pop_back() {
  if (size_ > 0) {
    node_ *deletable_node = tail_;
    if (head_ == tail_) {
      head_ = end_node_;
      tail_ = end_node_;
    } else {
      tail_ = tail_->previous_;
      tail_->next_ = end_node_;
      end_node_->previous_ = tail_;
    }
    delete deletable_node;
    --size_;
  }
}

template <class T>
void s21::list<T>::push_front(const_reference value) {
  auto *new_node = new node_;
  new_node->value_ = value;
  new_node->previous_ = end_node_;
  end_node_->next_ = new_node;
  if (head_) {
    new_node->next_ = head_;
    head_->previous_ = new_node;
    head_ = new_node;
    end_node_->previous_ = tail_;
    tail_->next_ = end_node_;
  } else {
    head_ = new_node;
    tail_ = head_;
    tail_->next_ = end_node_;
  }
  ++size_;
}

template <class T>
void s21::list<T>::pop_front() {
  if (size_ > 0) {
    node_ *deletable_node = head_;
    if (head_ == tail_) {
      head_ = end_node_;
      tail_ = end_node_;
    } else {
      head_ = head_->next_;
      head_->previous_ = end_node_;
      end_node_->next_ = head_;
    }
    delete deletable_node;
    --size_;
  }
}

template <class T>
void s21::list<T>::swap(list &other) {
  std::swap(head_, other.head_);
  std::swap(tail_, other.tail_);
  std::swap(end_node_, other.end_node_);
  std::swap(size_, other.size_);
}

template <class T>
void s21::list<T>::merge(list &other) {
  if (other.size_ > 0 && &other != this) {
    for (auto itr = other.begin(); itr != other.end(); ++itr) {
      push_back(*itr);
    }
    other.clear();
  }
}

template <class T>
void s21::list<T>::splice(const_iterator pos, list &other) {
  if (other.size_ > 0 && &other != this) {
    if (size_ == 0) {
      pos = end();
    }
    for (auto itr = other.begin(); itr != other.end(); ++itr) {
      insert(pos, *itr);
    }
    other.clear();
  }
}

template <class T>
void s21::list<T>::unique() {
  if (size_ > 1) {
    s21::list<T>::iterator current_node = begin();
    s21::list<T>::iterator next_node = begin();
    while (current_node != end()) {
      next_node = current_node;
      current_node = next_node;
      ++next_node;
      if (next_node != end() && *next_node == *current_node) {
        erase(next_node);
      } else {
        ++current_node;
      }
    }
  }
}

template <class T>
void s21::list<T>::reverse() {
  if (size_ > 1) {
    node_ *current_node = head_;
    while (current_node != end_node_) {
      node_ *next_node = current_node->next_;
      std::swap(current_node->next_, current_node->previous_);
      current_node = next_node;
    }
    std::swap(head_, tail_);
  }
}

template <class T>
void s21::list<T>::sort() {
  if (size_ > 1) {
    bool swapped = true;
    while (swapped) {
      swapped = false;
      node_ *previous_node = nullptr;
      node_ *current_node = head_;
      while (current_node->next_ != end_node_) {
        if (current_node->value_ > current_node->next_->value_) {
          if (previous_node) {
            previous_node->next_ = current_node->next_;
          } else {
            head_ = current_node->next_;
          }
          node_ *next_node = current_node->next_->next_;
          current_node->next_->next_ = current_node;
          current_node->next_ = next_node;
          if (previous_node) {
            previous_node = previous_node->next_;
          } else {
            previous_node = head_;
          }
          swapped = true;
        } else {
          previous_node = current_node;
          current_node = current_node->next_;
        }
        if (current_node->next_ == end_node_) {
          tail_ = current_node;
        }
      }
    }
  }
}

// ListIterator methods
template <class T>
void s21::list<T>::ListIterator::operator=(node_ &other) {
  itr_node_ = &other;
  value_ = other.value_;
}

template <class T>
typename s21::list<T>::value_type &s21::list<T>::ListIterator::operator*() {
  T *value = &value_;
  return *value;
}

template <class T>
void s21::list<T>::ListIterator::operator++() {
  if (itr_node_ && itr_node_->next_) {
    itr_node_ = itr_node_->next_;
    value_ = itr_node_->value_;
  }
}

template <class T>
void s21::list<T>::ListIterator::operator++(int) {
  ++(*this);
}

template <class T>
void s21::list<T>::ListIterator::operator--() {
  if (itr_node_ && itr_node_->previous_) {
    itr_node_ = itr_node_->previous_;
    value_ = itr_node_->value_;
  }
}

template <class T>
void s21::list<T>::ListIterator::operator--(int) {
  --(*this);
}

template <class T>
bool s21::list<T>::ListIterator::operator==(
    const s21::list<T>::ListIterator iterator) {
  return itr_node_ == iterator.itr_node_;
}

template <class T>
bool s21::list<T>::ListIterator::operator!=(
    const s21::list<T>::ListIterator iterator) {
  return itr_node_ != iterator.itr_node_;
}

// Additional
template <class T>
void s21::list<T>::MoveList(list &l) {
  head_ = l.head_;
  tail_ = l.tail_;
  end_node_ = l.end_node_;
  size_ = l.size_;
  l.head_ = nullptr;
  l.tail_ = nullptr;
  l.end_node_ = nullptr;
  l.size_ = 0;
}
