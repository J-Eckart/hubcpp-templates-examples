#ifndef CPP20_H
#define CPP20_H

template <typename NumberType1, typename NumberType2>
auto addNumbers(NumberType1 lhs, NumberType2 rhs)
{
    return lhs + rhs;
}

auto addNumbers2(auto lhs, auto rhs)
{
    return lhs + rhs;
}

template <typename Number, typename... Numbers>
auto addNumbersv(Number n, Numbers... args) -> Number
{
    if constexpr (sizeof...(args) > 0) {
        return n + addNumbersv(args...);
    }
    return n;
}

namespace points {
class Point {
public:
    double getX() const { return x_; }
    double getY() const { return y_; }

private:
    double x_, y_;
};

class OtherPoint {
public:
    double x() const { return x_; }
    double y() const { return y_; }

private:
    double x_, y_;
};

struct P {
    double x, y;
};

// this works, but if constexpr is nicer!
//template <typename PointT, decltype(PointT {}.x > 0.0) = true>
//double getX(const PointT& p)
//{
//    return p.x;
//}

//template <typename PointT, decltype(PointT {}.x() > 0.0) = true>
//double getX(const PointT& p)
//{
//    return p.x();
//}

//template <typename PointT, decltype(PointT {}.getX() > 0.0) = true>
//double getX(const PointT& p)
//{
//    return p.getX();
//}

double getX(const auto& p)
{
    if constexpr (requires { p.x; }) {
        return p.x;
    }
    if constexpr (requires { p.x(); }) {
        return p.x();
    }
    if constexpr (requires { p.getX(); }) {
        return p.getX();
    }
}

}

#endif // CPP20_H
