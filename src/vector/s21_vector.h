#include <initializer_list>

#include "cstdio"

namespace s21 {
template <class T>
class vector {
 private:
  T *array_;
  size_t size_;
  size_t capacity_;

 public:
  class VectorIterator {
    friend class vector<T>;

   private:
   public:
  };

  class ConstVectorIterator {
    friend class vector<T>;

   private:
   public:
  };

  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = VectorIterator;
  using const_iterator = ConstVectorIterator;
  using size_type = size_t;

  vector();
  vector(size_type n);
  vector(std::initializer_list<value_type> const &items);
  vector(const vector &v);
  vector(vector &&v);
  ~vector();
  vector operator=(vector &&v);

  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference front();
  const_reference back();
  iterator data();

  iterator begin();
  iterator end();

  bool empty();
  size_type size();
  size_type max_size();
  void reserve(size_type size);
  size_type capacity();
  void shrink_to_fit();

  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(vector &other);

  void filling();
  void print();
};

}  // namespace s21