#ifndef S21_MODEL_H_
#define S21_MODEL_H_

#include <cctype>
#include <iostream>
#include <stack>
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
class Token {
 public:
  Token() = default;
  explicit Token(double value, int priority, char type)
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
  std::pair<bool, std::string> ValidationSrc() noexcept;
  std::pair<bool, std::string> CreateTokens() noexcept;
  void CreateNotation() noexcept;
  double CalculateExpression() const noexcept;

  // extra method
  void print() {
    for (size_t i = 0; i < input_.size(); ++i) {
      std::cout << input_[i].value_ << " " << input_[i].priority_ << " "
                << input_[i].type_ << std::endl;
    }
  }

 private:
  // методы для парсинга строки
  bool CheckHooks() const noexcept;
  bool CheckDots() const noexcept;
  bool TokenIsFunction(const char &sym) const noexcept;
  bool TokenIsOperator(const char &sym) const noexcept;
  bool TokenIsHooks(const char &sym) const noexcept;
  std::pair<bool, std::string> FillTokenFunction(size_t pos) noexcept;
  void FillTokenOperator(const char &sym) noexcept;
  void CheckUnarySign() noexcept;
  bool CheckHooksAfterFunctions() const noexcept;
  bool CheckEdgeValues() const noexcept;
  std::pair<bool, std::string> CheckFinalExpression() const noexcept;
  // методы для вычислений
  bool TokenIsUnary(const s21::Token &sym) const noexcept;
  bool TokenIsBinary(const s21::Token &sym) const noexcept;
  bool TokenIsNumber(const s21::Token &sym) const noexcept;
  Token UnaryOperations(const char &sym, s21::Token &token) const noexcept;
  Token BinaryOperations(const char &sym, s21::Token &token_1,
                         s21::Token &token_2) const noexcept;
  std::vector<s21::Token> input_;
  std::string src_;
};
};  // namespace s21

#endif  // S21_MODEL_H_
