#include <initializer_list>

#include "cstdio"

namespace s21 {
template <class T>
class vector {
 private:
  T *begin_ = NULL;
  T *end_ = NULL;
  size_t size_ = 0;
  size_t capacity_ = 0;

  void reallocator();
 public:
  //temp
  void filling();

  using value_type = T;
  using reference = T &;
  using const_reference = const T &;

  using size_type = size_t;

  class VectorIterator {
    friend class vector<T>;

   private:
    value_type* position_;
    value_type value_;


   public:
    VectorIterator();

    void operator=(value_type* position);
    value_type operator*();
    void operator++();
    void operator++(value_type);
    void operator--();
    void operator--(value_type);
    bool operator==(vector<T>::VectorIterator iterator);
    bool operator!=(vector<T>::VectorIterator iterator);
  };


  class ConstVectorIterator {
    friend class vector<T>;
   private:

   public:
  };

  using iterator = VectorIterator;
  using const_iterator = ConstVectorIterator;

  vector();
  vector(size_type n);
  vector(std::initializer_list<value_type> const &items);
  vector(const vector &v);
  vector(vector &&v);
  ~vector();
  vector &operator=(vector &&v);

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

  void print();
};


}  // namespace s21