#include <cstdio>
#include <iostream>
#include <list>

#include "s21_list.cpp"
void temp_print(std::list<int> &list);

void temp_print(std::list<int> &list) {
  //   iterator = list.begin();
  //  auto iterator = list.end();
  for (std::list<int>::iterator i = list.begin(); i != list.end(); i++) {
    //    std::advance(iterator, i);
    std::cout << "data:  " << *i << "\n";
  }
}

int main() {
  s21::list<int> a(1);
  std::list<int> b(55);

//  a.push_back(13);
//  a.push_back(21);
//  b.push_back(13);
//  b.push_back(21);

  s21::list<int>::iterator itr_a = a.begin();
  std::list<int>::iterator itr_b = b.end();

  itr_a++;
//  itr_b++;
//  itr_a++;
//  itr_a++;
//  itr_b++;
//  itr_b++;
  printf("%d\t%d\n", *itr_a, *itr_b);
//  temp_print(b);
//  a.print_list();
  return 0;
}