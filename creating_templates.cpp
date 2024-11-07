#include "creating_templates.h"
#include <iostream>
#include <vector>

/*
int addNumbers(int lhs, int rhs){
    return lhs + rhs;
}
double addNumbers(double lhs, double rhs){
    return lhs + rhs;
}
[....]
*/

int main() {
  std::cout << "-----addNumbers-----\n";
  std::cout << addNumbers<double>(3.5, 4.0) << "\n";
  std::cout << addNumbers<int>(1, 2) << "\n";
  std::cout << addNumbers<std::string>("abc", "def") << "\n";
  std::cout << addNumbers(5.0, 6.0) << "\n";
  std::cout << addNumbers<double>(1, 3.0) << "\n";
  std::cout << "addnumbers2 int + double: " << addNumbers2(1, 3.5) << "\n";

  // auto res = addNumbers3(std::vector<int> {}, std::vector<int> {});

  std::cout << "----Vector2----\n";
  Vector2<double> v = {1.5, 2.0};
  Vector2<double> v2 = {3.5, 4.5};
  Vector2<double> v3 = v + v2;
  std::cout << "x = " << v3.x() << ", y = " << v3.y() << "\n";

  std::cout << "----addN----\n";
  std::cout << addN<5>(1) << "\n";

  std::cout << doMath<MathOp::ADD, 5>(1) << "\n";
  // std::cout << doMath<MathOp::DIVIDE, 0>(1);
}
