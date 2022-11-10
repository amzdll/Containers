#include <cstdio>
#include <list>
#include <iostream>

void temp_print(std::list<int> &list);



void temp_print(std::list<int> &list) {
  std::list<int>::iterator iterator = list.begin();
//  auto iterator = list.end();
  for(int i  = 0; i < list.size(); i++) {
//    std::advance(iterator, i);
    iterator++;
    std::cout << *iterator << " ";
  }
}

int main() {
  std::list<int> a;
  std::list<int> b;
  a.push_back(10);
  a.push_back(2);
  a.push_back(100);
  printf("a: %d\n", a.front());
  printf("a: %d\n", a.back());
//  a.push_back(4);
  b.swap(a);
  temp_print(b);
  return 0;
}