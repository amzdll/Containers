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
  s21::list<int> list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};

  s21::list<int>::iterator itr = list.end();
  std::list<int>::iterator std_itr = std_list.end();

  ++itr;
  printf("\n\n\n%d\n\n\n", *itr);
  //  temp_print(b);
  //  a.print_list();
  return 0;
}