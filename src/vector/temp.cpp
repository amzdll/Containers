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
  s21::vector<int> s21_a(6);
  std::vector<int> std_a(6);
  s21::vector<int>::iterator s21_itr;
  std::vector<int>::iterator std_itr;
//
//  s21_a.push_back(21);
  std_a.push_back(21);
//  s21_a.pop_back();
//  std_a.pop_back();
//  s21_itr = s21_a.end();
  std_itr = std_a.end();
  *std_itr--;
  printf("%ld\n", *std_itr);
//  printf("\n%d\t%d\n",2,  *std_itr );
  return 0;
}
