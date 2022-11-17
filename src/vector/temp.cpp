#include "s21_vector.cpp"
#include <utility>
#include <cstring>
#include <vector>

void std_print(std::vector<int> arr) {
  printf("std array: \n\t");
  for (int i = 0; i < arr.capacity(); ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  s21::vector<int> a(10);
  std::vector<int> std_a(10);
  s21::vector<int> b(std::move(a));
//  s21::vector<int>::iterator itr_a = a.end();
//  std::vector<int>::iterator std_itr_a = std_a.end();
//    for(int i = 0;  i < std_a.size(); ++i) {
//        std_a[i] = i+10;
//    }
//    a.filling();
//
////  itr_a++;
////  std_itr_a++;
//  a.reserve(50);
//  printf("capacity = %ld, size = %ld\n", a.capacity(), a.size());
//  //  a.erase(itr_a);
////  a.insert(itr_a, 123);
//  a.print();
//  printf("------------------------------------------------------------\n");
//  std_a.reserve(50);
//  std_a.insert(std_itr_a, 123);
//  printf("std capacity = %ld, std size = %ld\n", std_a.capacity(),
//         std_a.size());
//  std_print(std_a);
//  printf("\nend: %d\n", *a.end());
  return 0;
}
