#include "cstring"
#include "s21_queue.cpp"
#include <queue>

int main() {
  s21::queue<int> a;
  s21::queue<int> b;

  std::queue<int> std_a;


  a.push(5);
  std_a.push(5);

  a.push(4);
  std_a.push(4);

  printf("size is - %ld\n", a.size());
  printf("is empty - %s\n", a.empty() ? "true" : "false");
  printf("a:");
  a.swap(b);
  b.swap(a);
  a.print();
  printf(("\nb:"));
  b.print();
  printf("front std: %d, front: %d\n", std_a.front(), a.front());
  printf("back std: %d, back: %d\n", std_a.back(), a.back());

  return 0;
}
