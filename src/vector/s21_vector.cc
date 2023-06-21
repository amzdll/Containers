#include "s21_vector.h"

namespace s21 {
// Constructors
template <class T>
vector<T>::vector() = default;

template <class T>
vector<T>::vector(vector::size_type n) {
  begin_ = new T[n];
  size_ = n;
  capacity_ = n;
}

template <class T>
vector<T>::vector(std::initializer_list<T> const& items)
    : vector(items.size()) {
  auto itr = items.begin();
  std::memcpy(begin_, itr, size_ * sizeof(T));
}

template <class T>
vector<T>::vector(const vector& v) : size_(v.size_), capacity_(v.capacity_) {
  begin_ = new T[capacity_];
  std::memcpy(begin_, v.begin_, v.size_ * sizeof(T));
}

template <class T>
vector<T>::vector(vector&& v) noexcept {
  if (this != &v) {
    if (begin_) {
      delete[] begin_;
    }
    size_ = 0;
    capacity_ = 0;
    begin_ = nullptr;
    std::swap(size_, v.size_);
    std::swap(capacity_, v.capacity_);
    std::swap(begin_, v.begin_);
  }
}

template <class T>
vector<T>::~vector() {
  clear();
}

// Overload operators
template <class T>
typename s21::vector<T>& s21::vector<T>::operator=(vector&& v) noexcept {
  if (begin_) {
    delete[] begin_;
  }
  size_ = 0;
  capacity_ = 0;
  begin_ = nullptr;
  std::swap(size_, v.size_);
  std::swap(capacity_, v.capacity_);
  std::swap(begin_, v.begin_);
  return *this;
}

// Element access
template <class T>
T& vector<T>::at(vector::size_type pos) {
  if (pos >= size()) {
    throw std::out_of_range("out_of_range");
  }
  return begin_[pos];
}

template <class T>
T& vector<T>::operator[](vector::size_type pos) {
  return begin_[pos];
}

template <class T>
const T& vector<T>::front() {
  return begin_[0];
}

template <class T>
const T& vector<T>::back() {
  return *(end() - 1);
}

template <class T>
typename s21::vector<T>::iterator vector<T>::data() {
  return begin_;
}

// Iterators
template <class T>
typename s21::vector<T>::iterator vector<T>::begin() const {
  return begin_;
}

template <class T>
typename s21::vector<T>::iterator vector<T>::end() const {
  return begin_ + size_;
}

// Capacity
template <class T>
bool vector<T>::empty() {
  return !size_;
}

template <class T>
size_t vector<T>::size() {
  return size_;
}

template <class T>
size_t vector<T>::max_size() {
  std::allocator<T> alloc;
  return alloc.max_size();
}

template <class T>
void vector<T>::reserve(vector::size_type size) {
  if (capacity_ < size) {
    capacity_ = size;
    T* sized_array = new T[capacity_];
    std::memcpy(sized_array, begin_, size_ * sizeof(T));

    delete[] begin_;
    begin_ = new T[capacity_];

    std::memcpy(begin_, sized_array, size_ * sizeof(T));
    delete[] sized_array;
  }
}

template <class T>
typename vector<T>::size_type vector<T>::capacity() {
  return capacity_;
}

template <class T>
void vector<T>::shrink_to_fit() {
  if (size_ != capacity_) {
    T* shrinked_array = new T[size_];
    capacity_ = size_;
    std::memcpy(shrinked_array, begin_, size_ * sizeof(T));
    delete[] begin_;

    begin_ = shrinked_array;
  }
}

// Modifiers
template <class T>
void vector<T>::clear() {
  delete[] begin_;
  begin_ = nullptr;
  size_ = 0;
  capacity_ = 0;
}

template <class T>
typename s21::vector<T>::iterator vector<T>::insert(vector::iterator pos,
                                                    const T& value) {
  if (pos == end()) {
    push_back(value);
  } else if (pos == begin_) {
    T* temp_array = new T[capacity_ + 1]();
    temp_array[0] = value;
    std::memcpy(temp_array + 1, begin_, size_ * sizeof(T));
    ++size_;
    reallocator();
    std::memcpy(begin_, temp_array, size_ * sizeof(T));
    delete temp_array;
  } else {
    T* temp_array = new T[capacity_ + 1]();
    long int insertion_position = pos - begin_;
    size_t size_start_to_insertion = insertion_position * sizeof(T);
    size_t size_insertion_to_end = (end() - pos + 1) * sizeof(T);
    std::memcpy(temp_array, begin_, size_start_to_insertion);
    temp_array[insertion_position] = value;
    std::memcpy(temp_array + insertion_position + 1,
                begin_ + insertion_position, size_insertion_to_end);
    ++size_;
    reallocator();
    std::memcpy(begin_, temp_array, size_ * sizeof(T));
    pos = begin_ + insertion_position;
    delete temp_array;
  }
  return pos;
}

template <class T>
void vector<T>::erase(vector::iterator pos) {
  size_ -= 1;
  T* new_array = new T[capacity_];
  long deleting_position = pos - begin_;
  size_t size_start_to_deleting = sizeof(T) * deleting_position;
  size_t size_deleting_to_end = sizeof(T) * (begin_ + size_ - pos);

  std::memcpy(new_array, begin_, size_start_to_deleting);
  std::memcpy(new_array + deleting_position, begin_ + deleting_position + 1,
              size_deleting_to_end);
  std::memcpy(begin_, new_array, size_ * sizeof(T));
  delete[] new_array;
}

template <class T>
void vector<T>::push_back(const T& value) {
  reallocator();
  begin_[size_] = value;
  size_ += 1;
}

template <class T>
void vector<T>::pop_back() {
  erase(end() - 1);
}

template <class T>
void vector<T>::swap(vector& other) {
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
  std::swap(begin_, other.begin_);
}

// Additional
template <class T>
void vector<T>::filling() {
  for (size_type i = 0; i < size_; i++) {
    begin_[i] = i + 10;
  }
}

template <class T>
void vector<T>::reallocator() {
  if (!size_ && !capacity_) {
    capacity_ = 1;
  } else if (size_ == capacity_) {
    capacity_ = (size_t)(capacity_ * 2);
  }
  T* extended_array = new T[capacity_];
  std::memcpy(extended_array, begin_, size_ * sizeof(T));
  delete[] begin_;
  begin_ = new T[capacity_];
  std::memcpy(begin_, extended_array, size_ * sizeof(T));
  delete[] extended_array;
}

}  // namespace s21