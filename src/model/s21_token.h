#ifndef SMARTCALC_SRC_S21_TOKEN_H_
#define SMARTCALC_SRC_S21_TOKEN_H_

#include <cctype>
#include <iostream>
#include <map>
#include <regex>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

namespace s21 {
enum class Priority { kZero = 0, kFirst, kSecond, kThird, kFourth };

class Token {
 public:
  explicit Token(double value, s21::Priority priority, std::string type,
                 bool is_binary = false)
      : value_(value),
        priority_(priority),
        type_(type),
        is_binary_(is_binary) {}
  ~Token() = default;
  double value_;
  s21::Priority priority_;
  std::string type_;
  bool is_binary_;
};

const std::map<const std::string, Token> valid_tokens{
    {"x", Token(0.0, s21::Priority::kZero, "x")},
    {"+", Token(0.0, s21::Priority::kFirst, "sum", true)},
    {"-", Token(0.0, s21::Priority::kFirst, "sub", true)},
    {"*", Token(0.0, s21::Priority::kSecond, "*", true)},
    {"/", Token(0.0, s21::Priority::kSecond, "/", true)},
    {"(", Token(0.0, s21::Priority::kThird, "(")},
    {")", Token(0.0, s21::Priority::kThird, ")")},
    {"^", Token(0.0, s21::Priority::kThird, "^", true)},
    {"cos", Token(0.0, s21::Priority::kFourth, "cos")},
    {"sin", Token(0.0, s21::Priority::kFourth, "sin")},
    {"tan", Token(0.0, s21::Priority::kFourth, "tan")},
    {"acos", Token(0.0, s21::Priority::kFourth, "acos")},
    {"asin", Token(0.0, s21::Priority::kFourth, "asin")},
    {"atan", Token(0.0, s21::Priority::kFourth, "atan")},
    {"sqrt", Token(0.0, s21::Priority::kFourth, "sqrt")},
    {"ln", Token(0.0, s21::Priority::kFourth, "ln")},
    {"log", Token(0.0, s21::Priority::kFourth, "log")},
    {"mod", Token(0.0, s21::Priority::kSecond, "%", true)}};
};  // namespace s21

#endif  // SMARTCALC_SRC_S21_TOKEN_H_