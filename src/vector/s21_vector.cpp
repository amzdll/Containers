#include <cstring>
#include "s21_vector.h"

namespace s21 {

// BLOCK: CONSTRUCTORS
template <class T>
vector<T>::vector() {
  begin_ = NULL;
  size_ = 0;
}

template <class T>
vector<T>::vector(vector::size_type n) {
  begin_ = new T[n];
  size_ = n;
  for (int i = 0; i < size_; ++i) {
    memset(begin_, 0, size_ * sizeof(T));
  }
}

template <class T>
vector<T>::vector(const vector& v) {
  size_ = v.size_;
  begin_ = new T[size_];
  for (int i = 0; i < size_; ++i) {
    begin_[i] = v.begin_[i];
  }
}

template <class T>
vector<T>::vector(vector&& v) {
  size_ = v.size_;
  begin_ = new T[size_];
  for (int i = 0; i < size_; ++i) {
    begin_[i] = v.begin_[i];
  }
  delete v.begin_;
  v.begin_ = NULL;
}

template <class T>
vector<T>::~vector() {
  //  clear();
  delete begin_;
}

//template <class T>
//typename s21::vector<T> s21::vector<T>::operator=(vector&& v) {
//  delete begin_;
//  size_ = v.size_;
//  begin_ = new T[size_];
//  for (int i = 0; i < size_; ++i) {
//    begin_[i] = v.begin_[i];
//  }
//  return this;
//}

// template <class T>
// typename s21::vector<T> s21::vector<T>::operator=(vector&& v) {
//   delete begin_;
//   size_ = v.size_;
//   begin_ = new T[size_];
//   for (int i = 0; i < size_; ++i) {
//     begin_[i] = v.begin_[i];
//   }
//   return begin_;
// }

// BLOCK ELEMENT ACCESS
// template <class T>
// T & vector<T>::at(vector::size_type pos) {
//  return <#initializer #>;
//}
// template <class T>
// T & vector<T>::operator[](vector::size_type pos) {
//  return <#initializer #>;
//}
template <class T>
const T& vector<T>::front() {
  return begin_[0];
}
// template <class T>
// const T & vector<T>::back() {
//  return <#initializer #>;
//}

// template <class T>
// vector::iterator vector<T>::data() {
//   return s21::vector::iterator();
// }

template <class T>
typename s21::vector<T>::iterator vector<T>::begin() {
  vector<T>::iterator iterator;
  if(begin_) {
    iterator.position_ = begin_;
    iterator.value_ = *begin_;
  }
  return iterator;
}

// template <class T>
// vector::iterator vector<T>::end() {
//   return s21::vector::iterator();
// }

// BLOCK CAPACITY
template <class T>
bool vector<T>::empty() {
  return !begin_;
}
template <class T>
size_t vector<T>::size() {
  return size_;
}
// template <class T>
// vector::size_type vector<T>::max_size() {
//   return 0;
// }
// template <class T>
// void vector<T>::reserve(vector::size_type size) {}

template <class T>
typename vector<T>::size_type vector<T>::capacity() {
  return capacity_;
}
// template <class T>
// void vector<T>::shrink_to_fit() {}

//  BLOCK METHODS TO MODIFY
template <class T>
void vector<T>::clear() {
  //  delete begin_;
  //  for() {
  //
  //  }
  //  begin_ = NULL;
  size_ = 0;
}
// template <class T>
// vector::iterator vector<T>::insert(vector::iterator pos,
//                                    const T & value) {
//   return s21::vector::iterator();
// }
template <class T>
void vector<T>::erase(vector::iterator pos) {}

template <class T>
void vector<T>::push_back(const T& value) {}

template <class T>
void vector<T>::pop_back() {
  if (size_) {
  }
}

template <class T>
void vector<T>::swap(vector& other) {
  vector<T> temp_array(*this);
  size_t temp_size = size_;
  size_ = other.size_;
  begin_ = other.begin_;
  other.size_ = temp_size;
  other.begin_ = temp_array.begin_;
  temp_array.begin_ = NULL;
}

// BLOCK: TEMP

template <class T>
void vector<T>::filling() {
  for (int i = 0; i < size_; i++) {
    begin_[i] = i+10;
  }
}

template <class T>
void vector<T>::print() {
  printf("array: ");
  for (int i = 0; i < size_; i++) {
    printf("%d ", begin_[i]);
  }
  printf("\n");
}


// BLOCK: ITERATORS METHODS
template <class T>
vector<T>::VectorIterator::VectorIterator() {
  position_ = NULL;
  value_ = T();
}

template <class T>
void vector<T>::VectorIterator::operator=(value_type* position) {
  position_ = position;
  value_ = *position;
}

template <class T>
T vector<T>::VectorIterator::operator*() {
  return value_;
}

template <class T>
void vector<T>::VectorIterator::operator++() {
  ++position_;
  value_ = *position_;
}

template <class T>
void vector<T>::VectorIterator::operator++(value_type) {
  ++position_;
  value_ = *position_;
}

template <class T>
void vector<T>::VectorIterator::operator--() {
  --position_;
  value_ = *position_;
}

template <class T>
void vector<T>::VectorIterator::operator--(value_type) {
  --position_;
  value_ = *position_;
}

template <class T>
bool vector<T>::VectorIterator::operator==(vector<T>::VectorIterator iterator) {
  return false;
}

template <class T>
bool vector<T>::VectorIterator::operator!=(vector<T>::VectorIterator iterator) {
  return false;
}


}  // namespace s21