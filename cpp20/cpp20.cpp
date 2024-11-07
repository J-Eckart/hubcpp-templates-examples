#include "cpp20.h"
#include <iostream>
#include <vector>

int main()
{
    std::vector v = { 1, 2, 3 };
    std::cout << "addNumbers: " << addNumbers(1, 2) << "\n";

    std::cout << "addNumbers2: " << addNumbers(3, 2) << "\n";

    std::cout << "addNumbers3: " << addNumbersv(1, 2, 3, 4);

    points::P p1 {};
    points::OtherPoint p2 {};
    points::Point p3 {};
    std::cout << getX(p1) << getX(p2) << getX(p3) << "\n";
}
