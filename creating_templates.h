#ifndef CREATE_TEMPLATES_H_
#define CREATE_TEMPLATES_H_
#include <iostream>
#include <vector>

template <typename NumberType>
NumberType addNumbers(NumberType lhs, NumberType rhs)
{
    return lhs + rhs;
}

template <>
unsigned addNumbers(unsigned lhs, unsigned rhs)
{
    std::cout << "Unsigned addition!\n";
    return lhs + rhs;
}

template <typename Type>
class Vector2 {
public:
    Vector2(Type x, Type y)
        : v_ { x, y }
    {
    }
    Type x() const
    {
        return v_.at(0);
    }
    Type y() const
    {
        return v_.at(1);
    }
    Vector2 operator+(const Vector2& other)
    {
        return Vector2(x() + other.x(), y() + other.y());
    }

private:
    std::vector<Type> v_;
};

template <typename NumberType1, typename NumberType2>
auto addNumbers2(NumberType1 lhs, NumberType2 rhs) -> decltype(NumberType2 {} + NumberType1 {})
{
    return lhs + rhs;
}

#endif
