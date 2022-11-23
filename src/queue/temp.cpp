#include "cstring"
#include "s21_queue.cpp"
#include <queue>

int main() {
  s21::queue<int> a;
  std::queue<int> std_a;


  a.push(5);
//  a.push(4);
  std_a.push(5);
  std_a.push(4);
  a.pop();
  std_a.pop();
  printf("%d\n", a.empty());
  a.print();
//
//
//  printf("size is - %ld\n", a.size());
//  printf("is empty - %s\n", a.empty() ? "true" : "false");
////  a.swap(b);
////  b.swap(a);
//  s21::queue<int> b = a;
//  std::queue<int> std_b = std_a;
//  printf("\na:");
//  a.print();
//  printf("\nb:");
//  b.print();
//  printf("\n std_b:");
//  std_b.print();
//  b.print();

//  printf("%d", std_a.front());
//  printf("%d", a.front());
//  printf("front std: %d, front: %d\n", std_a.front(), a.front());
//  printf("back std: %d, back: %d\n", std_a.back(), a.back());

  return 0;
}
