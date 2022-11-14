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
  s21::vector<int> a(5);
  s21::vector<int> c;
  std::vector<int> std_a(5);
  for(int i = 0; i < 6; ++i) {
    std_a[i] = i+1;
  }
  a.filling();
  std_a.clear();
//  a.clear();
  c = a;
  a.print();
  std_print(std_a);
  printf("%s\n", a.empty() ? "true" : "false");
  printf("size is - %ld\n", a.size());
  printf("std size is - %ld\n", std_a.size());
  printf("front of a: %d\n", a.front());
  printf("front of std_a: %d\n", std_a.front());
//  s21::vector<int> b(std::move(a));
//  b.print();
  return 0;
}
