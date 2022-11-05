#include "s21_list.h"

// constructor
list::list() {}
list::list(size_type n) {}
list::~list() {}
int list::operator=(list &&l) { return 0; }

// methods to modify
void list::clear() {}
void list::iterator_insert(iterator pos, const_reference value) {}
void list::erase(iterator pos) {}
void list::push_back(const_reference value) {}
void list::pop_back() {}
void list::push_front(const_reference value) {}
void list::pop_front() {}
void list::swap(list &other) {}
void list::merge(list &other) {}
void list::splice(const_iterator pos, list &other) {}
void list::reverse() {}
void list::unique() {}
void list::sort() {}
