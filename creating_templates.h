#ifndef CREATE_TEMPLATES_H_
#define CREATE_TEMPLATES_H_
#include <vector>

template<typename NumberType>
NumberType addNumbers(NumberType lhs, NumberType rhs){
    return lhs + rhs;
}

template<typename Type>
class Vector2{
public:

private:
    std::vector<Type> v_;
}


#endif