#ifndef CREATE_TEMPLATES_H_
#define CREATE_TEMPLATES_H_
#include <iostream>
#include <type_traits>
#include <vector>

template <typename NumberType>
// template <class NumberType> <-- the exact same
NumberType addNumbers(NumberType lhs, NumberType rhs) {
  return lhs + rhs;
}

template <> std::string addNumbers(std::string lhs, std::string rhs) {
  std::cout << "String addition!";
  return lhs + " and " + rhs;
}

template <typename NumberType1, typename NumberType2>
NumberType1 addNumbers2(NumberType1 lhs, NumberType2 rhs) {
  return lhs + rhs;
}

template <typename NumberType1, typename NumberType2>
auto addNumbers3(NumberType1 lhs, NumberType2 rhs)
    -> decltype(NumberType2{} + NumberType1{}) {
  return lhs + rhs;
}

template <int N> int addN(int i) { return i + N; }

enum class MathOp { ADD, SUBTRACT, MULTIPLY, DIVIDE };

template <MathOp op, int rhs> int doMath(int lhs) {
  static_assert(op != MathOp::DIVIDE || rhs != 0, "Cannot divide by zero");
  switch (op) {
  case MathOp::ADD:
    return lhs + rhs;
    break;
  case MathOp::SUBTRACT:
    return lhs - rhs;
    break;
  case MathOp::MULTIPLY:
    return lhs * rhs;
    break;
  case MathOp::DIVIDE:
    return lhs / rhs;
    break;
  default:
    break;
  }
  return 0.0;
}

template <typename Type> class Vector2 {
public:
  Vector2(Type x, Type y) : x_(x), y_(y) {}
  Type x() const { return x_; }
  Type y() const { return y_; }
  Vector2 operator+(const Vector2 &other) {
    return Vector2(x() + other.x(), y() + other.y());
  }

private:
  Type x_, y_;
};

#endif
