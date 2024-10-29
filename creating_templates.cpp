#include "creating_templates.h"
#include <iostream>

/*
int addNumbers(int lhs, int rhs){
    return lhs + rhs;
}
double addNumbers(double lhs, double rhs){
    return lhs + rhs;
}
[....]
*/

int main(){
    std::cout << addNumbers<double>(3.5, 4.0) << "\n";
    std::cout << addNumbers<int>(1, 2) << "\n";
    std::cout << addNumbers<std::string>("abc", "def") << "\n";
    std::cout << addNumbers(5.0, 6.0)<< "\n";
}