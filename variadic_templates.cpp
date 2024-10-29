#include "variadic_templates.h"
#include <iostream>

int main()
{
    std::cout << addNumbers(1, 2, 3, 4) << "\n";
    using VoidAction = Action<>;
    VoidAction a { []() {
        std::cout << "Action a";
    } };
    VoidAction b { []() {
        std::cout << "Action b";
    } };
    (a + b)();
    std::cout << "\n";
}
