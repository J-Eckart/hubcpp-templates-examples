#include "variadic_templates.h"
#include <iostream>

int main() {
  std::cout << addNumbers(1, 2, 3, 4) << "\n";

  using VoidAction = Action<>;
  VoidAction a{[]() { std::cout << "Action a. "; }};
  VoidAction b{[]() { std::cout << "Action b. "; }};
  //    [&]() {
  //        a();
  //        b();
  //    }();
  (a + b)();
  std::cout << "\n";

  using BiDoubleAction = Action<double, double>;
  BiDoubleAction c{[](double a, double b) {
    std::cout << (a > b ? "a > b" : "a <= b") << ". ";
  }};
  BiDoubleAction d{
      [](double a, double b) { std::cout << "a + b = " << a + b << ". "; }};
  (c + d)(1.0, 2.0);
  std::cout << "\n";
}
