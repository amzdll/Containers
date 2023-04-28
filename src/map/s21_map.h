#ifndef CPP2_S21_CONTAINERS_MAP_S21_MAP_H_
#define CPP2_S21_CONTAINERS_MAP_S21_MAP_H_

#include <cstdio>
#include <utility>

#include "iostream"
#include "string"

namespace s21 {
template <class Key, class T>
class map {
    using key_type = Key;
    using mapped_type = T;
    using value_type = std::pair<const key_type, mapped_type>;
    using reference = value_type &;
    using const_reference = const value_type &;
    //  using const_iterator = ;
    using size_type = size_t;

   private:
    //  struct node_ {
    //    node_ *left_;
    //    node_ *right_;
    //    node_ *parent_node_;
    //    std::pair<Key, mapped_type> value_;
    //  };
    //  node_ *root_ = nullptr;

   public:
    class MapIterator;
    using iterator = MapIterator;

    struct node_ {
        node_ *left_ = nullptr;
        node_ *right_ = nullptr;
        node_ *parent_node_ = nullptr;
        std::pair<Key, mapped_type> value_;
    };
    node_ *root_ = nullptr;

    map();
    //  map(std::initializer_list<value_type> const &items);
    map(const map &m);
    map(map &&m);
    ~map();
    map &operator=(map &&m);

    T &at(const Key &key);
    T &operator[](const Key &key);
    iterator begin();
    //        iterator end();
    bool empty();
    size_type size();
    size_type max_size();

    void clear();
    //  std::pair<iterator, bool> insert(const value_type &value);
    //  std::pair<iterator, bool> insert(const Key& key, const T& obj);
    //  std::pair<iterator, bool> insert_or_assign(const Key& key, const T&
    //  obj);; void erase(iterator pos); void swap(map& other); void merge(map&
    //  other);

    void Push(value_type value);
    //  bool contains(const Key &key);
};

template <class Key, class T>
class map<Key, T>::MapIterator {
   private:
    node_ *itr_node_ = NULL;

   public:
    MapIterator();

    void operator=(node_ &node_);
    std::pair<Key, T> &operator*();
    std::pair<Key, T> *operator->();
    void operator++();
    void operator--();
    bool operator==(map<Key, T>::MapIterator iterator);
    bool operator!=(map<Key, T>::MapIterator iterator);
};


//};

}  // namespace s21

#endif  //  CPP2_S21_CONTAINERS_MAP_S21_MAP_H_