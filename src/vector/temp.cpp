#include "s21_vector.cpp"
#include <utility>
#include <cstring>
#include <vector>

void std_print(std::vector<int> arr) {
  printf("std: ");
  for(int i = 0; i < arr.size(); ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}


int main() {
  s21::vector<int> a(6);
  a.filling();
  s21::vector<int> b(3);
  s21::vector<int>::iterator itr_a;
  itr_a = a.begin();
  printf("itr: %d\n", *itr_a);
  ++itr_a;
  printf("itr: %d\n", *itr_a);
//  s21::vector<int> c;
//  std::vector<int> std_a(5);
//  std::vector<int>::iterator itr_std=std_a.begin();
////  for(int i = 0; i < 6; ++i) {
////    a[i] = i+10;
////  }
//  a.filling();
//  std_a.clear();
////  b.filling();
////  std_a.clear();
////  a.clear();
//
//
//  a.swap(b);
//  a.print();
//  b.print();
////  std_print(std_a);
////  std_print(std_a);
////  printf("%s\n", a.empty() ? "true" : "false");
////  printf("size is - %ld\n", a.size());
////  printf("std size is - %ld\n", std_a.size());
////  printf("front of a: %d\n", a.front());
//  printf("front of std_a: %d\n", std_a.front());
////  s21::vector<int> b(std::move(a));
////  b.print();


  return 0;
}
