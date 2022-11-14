#include "s21_stack.cpp"

namespace s21 {
int main() {
  s21::stack<int> a;
  a.push(2);
  a.push(3);
  a.print();
  return 0;
}
}  // namespace s21