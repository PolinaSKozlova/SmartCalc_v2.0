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
  Model() : src_(""), x_value_("0.0") {}
  explicit Model(std::string other, std::string x = "0.0")
      : src_(other), x_value_(x) {}
  ~Model() = default;
  std::pair<bool, std::string> ValidationSrc() noexcept;
  double CalculateResultFromInput() const noexcept;
  std::pair<bool, std::string> StartCalculations() noexcept;
  std::string GetOutput() const noexcept;
  // extra method
  void print() {
    for (auto it = input_.cbegin(); it != input_.cend(); ++it) {
      std::cout << it->value_ << " " << it->priority_ << " " << it->type_
                << std::endl;
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
  void CreateNotation() noexcept;
  std::pair<bool, std::string> CreateTokens() noexcept;
  std::pair<bool, std::string> CheckXValue() const noexcept;
  void GetXValue() noexcept;
  // методы для вычислений
  bool TokenIsUnary(const s21::Token &sym) const noexcept;
  bool TokenIsBinary(const s21::Token &sym) const noexcept;
  bool TokenIsNumber(const s21::Token &sym) const noexcept;
  Token UnaryOperations(const char &sym, s21::Token &token) const noexcept;
  Token BinaryOperations(const char &sym, s21::Token &token_1,
                         s21::Token &token_2) const noexcept;
  std::vector<s21::Token> input_;
  std::string src_;
  std::string x_value_;
  std::string output_;
};
};  // namespace s21

#endif  // S21_MODEL_H_
