#ifndef SMARTCALC_TOKEN_H_
#define SMARTCALC_TOKEN_H_

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

namespace smartcalc {
enum class Priority { kZero = 0, kFirst, kSecond, kThird, kFourth };

class Token {
 public:
  explicit Token(double value, smartcalc::Priority priority,
                 const std::string& type, int type_id = 0,
                 bool is_binary = false)
      : value_(value),
        priority_(priority),
        type_(type),
        type_id_(type_id),
        is_binary_(is_binary) {}
  ~Token() = default;
  double value_;
  smartcalc::Priority priority_;
  std::string type_;
  int type_id_;
  bool is_binary_;
};

using namespace smartcalc;

const std::map<const std::string, Token> valid_tokens{
    {"x", Token(0.0, Priority::kZero, "x")},
    {"nan", Token(0.0 / 0.0, Priority::kZero, "nan")},
    {"inf", Token(1.0 / 0.0, Priority::kZero, "inf")},
    {"-inf", Token(-1.0 / 0.0, Priority::kZero, "-inf")},
    {"+", Token(0.0, Priority::kFirst, "sum", 1, true)},
    {"-", Token(0.0, Priority::kFirst, "sub", 1, true)},
    {"*", Token(0.0, Priority::kSecond, "*", 1, true)},
    {"/", Token(0.0, Priority::kSecond, "/", 1, true)},
    {"(", Token(0.0, Priority::kThird, "(", 2)},
    {")", Token(0.0, Priority::kThird, ")", 3)},
    {"^", Token(0.0, Priority::kThird, "^", 1, true)},
    {"cos", Token(0.0, Priority::kFourth, "cos", 4)},
    {"sin", Token(0.0, Priority::kFourth, "sin", 4)},
    {"tan", Token(0.0, Priority::kFourth, "tan", 4)},
    {"acos", Token(0.0, Priority::kFourth, "acos", 4)},
    {"asin", Token(0.0, Priority::kFourth, "asin", 4)},
    {"atan", Token(0.0, Priority::kFourth, "atan", 4)},
    {"sqrt", Token(0.0, Priority::kFourth, "sqrt", 4)},
    {"ln", Token(0.0, Priority::kFourth, "ln", 4)},
    {"log", Token(0.0, Priority::kFourth, "log", 4)},
    {"mod", Token(0.0, Priority::kSecond, "%", 1, true)}};

const std::map<std::string, std::function<double(double, double)>>
    functions_for_count{
        {"u_minus",
         [](double arg_1, double arg_2 = 0.0) { return (arg_2 - arg_1); }},
        {"u_plus",
         [](double arg_1, double arg_2 = 0.0) { return (arg_1 + arg_2); }},
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
};  // namespace smartcalc

#endif  // SMARTCALC_SRC_TOKEN_H_