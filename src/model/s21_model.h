#ifndef S21_MODEL_H_
#define S21_MODEL_H_

#include <cctype>
#include <iostream>
#include <string>
#include <vector>

#include "../controller/s21_controller.h"

/*
 * ZERO - x, number
 * FIRST - sum, sub
 * SECOND - div, mult, mod
 * THIRD - hooks, pow, unary plus, unary minus
 * FOURTH - sin, cos, tan, acos, asin, atan, sqrt, ln, log
 */

enum TokenPriority { ZERO, FIRST, SECOND, THIRD, FOURTH };

namespace s21 {
struct Token {
  // нужен ли конструктор и деструктор
  Token(double value, int priority, char type)
      : value_(value), priority_(priority), type_(type) {}
  ~Token() = default;
  double value_;
  int priority_;
  char type_;
};

class Model {
 public:
  Model(std::string other) : src_(other) {}
  ~Model() = default;
  bool ValidationSrc() noexcept;
  bool ValidationTokens() const noexcept;
  bool CreateTokens() noexcept;
  void CreateNotation() noexcept;

  // extra method
  void print() {
    for (size_t i = 0; i < input_.size(); ++i) {
      std::cout << input_[i].value_ << " " << input_[i].priority_ << " "
                << input_[i].type_ << std::endl;
    }
  }
  bool CheckEdgeValues() const noexcept;

 private:
  bool CheckHooks() noexcept;  // проверка корректности скобок
  bool CheckDots() noexcept;  // проверка корректности точек
  bool IsFunction(const char &sym) noexcept;  // проверка функции
  bool IsOperator(const char &sym) noexcept;  // проверка оператора
  bool IsHooks(const char &sym) const noexcept;  // проверка скобок
  bool TokenFunction(size_t pos) noexcept;  // заполнение токена для функции
  // заполнение токена для оператора
  void TokenOperator(const char &sym) noexcept;
  bool CheckUnarySign() noexcept;  // проверка унарного оператора
  // проверка скобок после функций
  bool CheckHooksAfterFunctions() const noexcept;
  // проверка выражения

  bool CheckExpression() const noexcept;
  std::vector<s21::Token> input_;
  std::string src_;
};
};  // namespace s21

#endif  // S21_MODEL_H_
