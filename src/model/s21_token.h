#ifndef SMARTCALC_SRC_S21_TOKEN_H_
#define SMARTCALC_SRC_S21_TOKEN_H_

#include <cctype>
#include <cmath>
#include <functional>
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

const std::map<std::string, std::function<double(double, double)>>
    functions_for_count{
        {"u_minus", [](double arg_1,
                       double arg_2 = 0.0) { return (arg_1 * -1.0 + arg_2); }},
        {"u_plus", [](double arg_1,
                      double arg_2 = 0.0) { return (arg_1 * 1.0 + arg_2); }},
        {"cos",
         [](double arg_1, double arg_2 = 0.0) { return (cos(arg_1) + arg_2); }},
        {"sin",
         [](double arg_1, double arg_2 = 0.0) { return (sin(arg_1) + arg_2); }},
        {"tan",
         [](double arg_1, double arg_2 = 0.0) { return (tan(arg_1) + arg_2); }},
        {"acos", [](double arg_1,
                    double arg_2 = 0.0) { return (acos(arg_1) + arg_2); }},
        {"asin", [](double arg_1,
                    double arg_2 = 0.0) { return (asin(arg_1) + arg_2); }},
        {"atan", [](double arg_1,
                    double arg_2 = 0.0) { return (atan(arg_1) + arg_2); }},
        {"sqrt", [](double arg_1,
                    double arg_2 = 0.0) { return (sqrt(arg_1) + arg_2); }},
        {"ln",
         [](double arg_1, double arg_2 = 0.0) { return (log(arg_1) + arg_2); }},
        {"log", [](double arg_1,
                   double arg_2 = 0.0) { return (log10(arg_1) + arg_2); }},
        {"sum", [](double arg_1, double arg_2) { return (arg_1 + arg_2); }},
        {"sub", [](double arg_1, double arg_2) { return (arg_1 - arg_2); }},
        {"*", [](double arg_1, double arg_2) { return (arg_1 * arg_2); }},
        {"/", [](double arg_1, double arg_2) { return (arg_1 / arg_2); }},
        {"^", [](double arg_1, double arg_2) { return (pow(arg_1, arg_2)); }},
        {"%", [](double arg_1, double arg_2) { return (fmod(arg_1, arg_2)); }}};
};  // namespace s21

#endif  // SMARTCALC_SRC_S21_TOKEN_H_