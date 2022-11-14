#include "s21_vector.h"

namespace s21 {

// block: constructors
template <class T>
vector<T>::vector() {
  array_ = NULL;
  size_ = 0;
  capacity_ = sizeof(T);
}

template <class T>
vector<T>::vector(vector::size_type n) {
  array_ = new T[n];
  size_ = n;
  capacity_ = sizeof(T);
}

template <class T>
vector<T>::vector(const vector& v) {}
template <class T>
vector<T>::vector(vector&& v) {}
template <class T>
vector<T>::~vector() {}

template <class T>
typename s21::vector<T> vector<T>::operator=(vector&& v) {
  return vector();
}

// block
//template <class T>
//T & vector<T>::at(vector::size_type pos) {
//  return <#initializer #>;
//}
//template <class T>
//T & vector<T>::operator[](vector::size_type pos) {
//  return <#initializer #>;
//}
//template <class T>
//const T & vector<T>::front() {
//  return <#initializer #>;
//}
//template <class T>
//const T & vector<T>::back() {
//  return <#initializer #>;
//}

//template <class T>
//vector::iterator vector<T>::data() {
//  return s21::vector::iterator();
//}
//template <class T>
//vector::iterator vector<T>::begin() {
//  return s21::vector::iterator();
//}
//template <class T>
//vector::iterator vector<T>::end() {
//  return s21::vector::iterator();
//}

// block
template <class T>
bool vector<T>::empty() {
  return false;
}
//template <class T>
//vector::size_type vector<T>::size() {
//  return 0;
//}
//template <class T>
//vector::size_type vector<T>::max_size() {
//  return 0;
//}
//template <class T>
//void vector<T>::reserve(vector::size_type size) {}
//template <class T>
//vector::size_type vector<T>::capacity() {
//  return 0;
//}
//template <class T>
//void vector<T>::shrink_to_fit() {}
// block
template <class T>
void vector<T>::clear() {}
//template <class T>
//vector::iterator vector<T>::insert(vector::iterator pos,
//                                   const T & value) {
//  return s21::vector::iterator();
//}
template <class T>
void vector<T>::erase(vector::iterator pos) {}
template <class T>
void vector<T>::push_back(const T & value) {}
template <class T>
void vector<T>::pop_back() {}
template <class T>
void vector<T>::swap(vector& other) {}

// temp

template <class T>
void vector<T>::filling() {
  for(int i = 0; i < size_; i++) {
    array_[i] = i;
  }
}

template <class T>
void vector<T>::print() {
  printf("array");
  for(int i = 0; i < size_; i++) {
    printf("%d ", array_[i]);
  }
}

}  // namespace s21