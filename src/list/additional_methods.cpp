#include <cstdio>
#include <iostream>
#include <list>

void temp_print(std::list<int> &list);

void temp_print(std::list<int> &list) {
  //   iterator = list.begin();
  //  auto iterator = list.end();
  for (std::list<int>::iterator i = list.begin(); i != list.end(); i++) {
    //    std::advance(iterator, i);
    std::cout << "data: " << *i << "\n";
  }
}

int main() {
  std::list<int> a;
  std::list<int> b;

//  a.push_back(50);
//  a.push_back(30);
//  a.push_back(50);
//  a.push_back(30);
//  a.push_back(50);

  std::list<int>::iterator iter_b = b.begin();
  iter_b++;
  b.push_back(1000);
  b.push_back(2000);
  b.push_back(3000);
  b.push_back(4000);


  printf("%d", *iter_b);
  return 0;
}