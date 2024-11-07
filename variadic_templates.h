#ifndef VARIADIC_TEMPLATES_H
#define VARIADIC_TEMPLATES_H

#include <functional>

template <typename Number> Number addNumbers(Number n) { return n; }

template <typename Number, typename... Numbers>
auto addNumbers(Number n, Numbers... args) -> Number {
  return n + addNumbers(args...);
}

template <class... InputArgs>
/**
 * @brief The Action class is a wrapper around a
 * std::function<void(InputArgs...)> that offers additional utility, namely the
 * && operator
 */
class Action {
  using ActionFunction = std::function<void(const InputArgs &...)>;

public:
  /**
   * @param function the underlying function
   */
  explicit Action(ActionFunction function) : m_function(function) {}

  operator ActionFunction() { return m_function; }

  // ### Move/Copy
  // Moving and copying is OK. Default implementations should suffice.
  Action(const Action &) = default;
  Action(Action &&) = default;
  Action &operator=(const Action &) = default;
  Action &operator=(Action &&) = default;

  /**
   * @brief operator () executes the underlying function
   * @param args input argument(s)
   */
  void operator()(const InputArgs &... args) const { m_function(args...); }

  Action &operator+=(const Action &other) {
    auto thisFunction = this->m_function;
    auto otherFunction = other.m_function;

    this->m_function = [thisFunction,
                        otherFunction](const InputArgs &... args) {
      thisFunction(args...);
      otherFunction(args...);
    };
    return *this;
  }
  friend Action operator+(Action lhs, const Action &rhs) {
    lhs += rhs;
    return lhs;
  }

private:
  ActionFunction m_function;
};

#endif // VARIADIC_TEMPLATES_H
