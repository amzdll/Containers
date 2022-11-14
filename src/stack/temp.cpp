#include "s21_stack.cpp"
#include "s21_stack.h"
#include <stack>
#include <cstdio>
#include <iostream>

// namespace s21 {
void PrintStack(std::stack<int> s) {
  if (s.empty()) return;
  int x = s.top();
  s.pop();
  PrintStack(s);
  std::cout << x << " ";
  s.push(x);
}

int main() {
//  std::stack<int> std_a;
//  std_a.push(80);
//  std_a.push(15);
//  std_a.push(61);
//  std::stack<int> std_b(std_a);
//  PrintStack(std_a);
//  printf(("\n§§§§§§§§§§§§§§§§\n"));
//  PrintStack(std_b);
  printf("\n");
  s21::stack<int> a;
  a.push(80);
  a.push(15);
  a.push(61);
  s21::stack<int> b = a;
//  s21::stack<int> b(std::move(a));
  a.print();
//  PrintStack(b);
  printf(("§§§§§§§§§§§§§§§§\n"));
  b.print();
//  PrintStack(a);
  return 0;
}
//}  // namespace s21