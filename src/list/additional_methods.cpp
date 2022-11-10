#include <cstdio>
#include <list>
#include <iostream>

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

  b.push_back(1000);
  b.push_back(2000);
  b.push_back(3000);
  b.push_back(4000);

  std::list<int>::const_iterator  iter_b = b.begin();

  a.push_back(50);
  a.push_back(30);
  a.push_back(50);
//  a.insert()
  a.push_back(30);
  a.push_back(50);

//  a.splice(iter_b, b);
  b.insert(iter_b, 2);
  temp_print(b);
//  a.merge(b);
  //  printf("a: %d\n", a.front());
  //  printf("a: %d\n", a.back());
  //  a.push_back(4);
  //  b.swap(a);
  //  a.sort();
  //  printf("%d", *a.end());
//  temp_print(a);
//  printf("%d", a[0]);
  //  printf("\n-----\n");
  //  temp_print(b);
  return 0;
}