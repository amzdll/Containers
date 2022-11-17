#include "s21_vector.h"

#include <cstring>

namespace s21 {

// BLOCK: CONSTRUCTORS
template <class T>
vector<T>::vector() {
  begin_ = NULL;
  end_ = NULL;
  capacity_ = 0;
  size_ = 0;
}

template <class T>
vector<T>::vector(vector::size_type n) {
  begin_ = new T[n];
  end_ = begin_ + n - 1;
  size_ = n;
  capacity_ = n;
}

template <class T>
vector<T>::vector(const vector& v) {
  // refactor to memcpy
  size_ = v.size_;
  capacity_ = v.capacity_;
  begin_ = new T[capacity_];
  // refactor memcpy
  for (int i = 0; i < size_; ++i) {
    begin_[i] = v.begin_[i];
  }
}

template <class T>
vector<T>::vector(vector&& v) {
  end_ = begin_;
//  delete[] begin_;

  size_ = v.size_;
  capacity_ = v.capacity_;
  begin_ = new T[capacity_];
  end_ = begin_ + size_ - 1;

  std::memcpy(begin_, v.begin_, size_);

  delete v.begin_;
  v.begin_ = NULL;
  v.end_ = NULL;
}

template <class T>
vector<T>::~vector() {
  clear();
  //  delete[] begin_;
}

template <class T>
void vector<T>::reallocator() {
  if (size_ == capacity_) {
    capacity_ = (size_t)(capacity_ * 2);
  }
  T* temp_array = new T[capacity_];
  std::memcpy(temp_array, begin_, size_ * sizeof(T));
  delete begin_;
  begin_ = new T[capacity_];
  end_ = begin_ + size_ - 1;
  std::memcpy(begin_, temp_array, size_ * sizeof(T));
  delete[] temp_array;
}

// template <class T>
// typename s21::vector<T> s21::vector<T>::operator=(vector&& v) {
//   delete begin_;
//   size_ = v.size_;
//   begin_ = new T[size_];
//   for (int i = 0; i < size_; ++i) {
//     begin_[i] = v.begin_[i];
//   }
//   return this;
// }

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
  if (begin_) {
    iterator.position_ = begin_;
    iterator.value_ = *begin_;
  }
  return iterator;
}

template <class T>
typename s21::vector<T>::iterator vector<T>::end() {
  vector<T>::iterator iterator;
  if (begin_) {
    iterator.position_ = end_;
    iterator.value_ = *end_;
  }
  return iterator;
}

// BLOCK CAPACITY
template <class T>
bool vector<T>::empty() {
  return !size_;
}
template <class T>
size_t vector<T>::size() {
  return size_;
}
// template <class T>
// vector::size_type vector<T>::max_size() {
//   return 0;
// }
template <class T>
void vector<T>::reserve(vector::size_type size) {
  if (capacity_ < size) {
    capacity_ = size;
    T* temp_array = new T[capacity_];
    std::memcpy(temp_array, begin_, size_ * sizeof(T));

    delete begin_;
    begin_ = new T[capacity_];
    end_ = begin_ + size_ - 1;

    std::memcpy(begin_, temp_array, size_ * sizeof(T));
    delete[] temp_array;
  }
}

template <class T>
typename vector<T>::size_type vector<T>::capacity() {
  return capacity_;
}
// template <class T>
// void vector<T>::shrink_to_fit() {}

//  BLOCK METHODS TO MODIFY
template <class T>
void vector<T>::clear() {
  delete begin_;
  begin_ = NULL;
  size_ = 0;
  // refactor:
  //  capacity_?
}
template <class T>
typename s21::vector<T>::iterator vector<T>::insert(vector::iterator pos,
                                                    const T& value) {
  if (!(pos.position_ < end_ && pos.position_ > begin_)) {
    value = 0;
    pos.position_ = begin_;
  }
  if (pos.position_ != end_) {
    T* temp_array = new T[capacity_];
    long int insertion_position = pos.position_ - begin_;
    size_t size_start_to_insertion = sizeof(T) * insertion_position;
    size_t size_insertion_to_end = sizeof(T) * (end_ - pos.position_ + 1);

    reallocator();
    size_ += 1;

    std::memcpy(temp_array, begin_, size_start_to_insertion);
    std::memcpy(temp_array + insertion_position + 1,
                begin_ + insertion_position, size_insertion_to_end);
    temp_array[insertion_position] = value;

    std::memcpy(begin_, temp_array, size_ * sizeof(T));
    pos.position_ = begin_ + insertion_position;
    pos.value_ = value;
    delete[] temp_array;
  } else {
    push_back(value);
  }
  return pos;
}

template <class T>
void vector<T>::erase(vector::iterator pos) {
  size_ -= 1;
  T* temp_array = new T[capacity_];
  long int deleting_position = pos.position_ - begin_;
  size_t size_start_to_deleting = sizeof(T) * deleting_position;
  size_t size_deleting_to_end = sizeof(T) * (end_ - pos.position_);

  std::memcpy(temp_array, begin_, size_start_to_deleting);
  std::memcpy(temp_array + deleting_position, begin_ + deleting_position + 1,
              size_deleting_to_end);
  std::memcpy(begin_, temp_array, size_ * sizeof(T));
  end_ = begin_ + size_ - 1;
  delete[] temp_array;
  printf("%d %d %d\n", deleting_position, size_start_to_deleting,
         size_deleting_to_end);
}

template <class T>
void vector<T>::push_back(const T& value) {
  reallocator();
  begin_[size_] = value;
  size_ += 1;
  //  end_+=1;
}

template <class T>
void vector<T>::pop_back() {
  size_ -= 1;
  begin_[size_] = 321;
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
    begin_[i] = i + 10;
  }
}

template <class T>
void vector<T>::print() {
  printf("array: \n\t");
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
  //  num_of_position = position-begin_;
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