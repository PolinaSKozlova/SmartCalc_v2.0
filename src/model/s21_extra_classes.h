#ifndef SRC_S21_EXTRA_CLASSES_H_
#define SRC_S21_EXTRA_CLASSES_H_

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
  Token(double value, s21::Priority priority, char type)
      : value_(value), priority_(priority), type_(type) {}
  ~Token() = default;
  double value_;
  s21::Priority priority_;
  char type_;
};

const std::map<std::string, Token> valid_tokens{
    // const перед string
    {"x", Token(0.0, s21::Priority::kZero, 'x')},
    {"+", Token(0.0, s21::Priority::kFirst, 'p')},
    {"-", Token(0.0, s21::Priority::kFirst, 'm')},
    {"*", Token(0.0, s21::Priority::kSecond, '*')},
    {"/", Token(0.0, s21::Priority::kSecond, '/')},
    {"(", Token(0.0, s21::Priority::kThird, '(')},
    {")", Token(0.0, s21::Priority::kThird, ')')},
    {"cos", Token(0.0, s21::Priority::kFourth, 'c')},
    {"sin", Token(0.0, s21::Priority::kFourth, 's')},
    {"tan", Token(0.0, s21::Priority::kFourth, 't')},
    {"acos", Token(0.0, s21::Priority::kFourth, 'o')},
    {"asin", Token(0.0, s21::Priority::kFourth, 'i')},
    {"atan", Token(0.0, s21::Priority::kFourth, 'a')},
    {"sqrt", Token(0.0, s21::Priority::kFourth, 'q')},
    {"ln", Token(0.0, s21::Priority::kFourth, 'l')},
    {"log", Token(0.0, s21::Priority::kFourth, 'g')},
    {"mod", Token(0.0, s21::Priority::kFourth, '%')}};

class Tokenizer {
 public:
  explicit Tokenizer(const std::string& input_src) : input_src_(input_src) {}
  ~Tokenizer() = default;
  std::vector<Token> GetTokens() const noexcept { return tokens_; }
  void CreateTokenOutput();
  void CreateTokens();
  void CheckHooksInInput() const;
  void CheckDotsInInput() const;
  bool TokenIsFunction(const char& sym) const;
  bool TokenIsOperator(const char& sym) const;
  bool TokenIsNumber(const char& sym) const;
  bool TokenIsHook(const char& sym) const;
  void FillOperatorToken(const char& sym) noexcept;
  void FillFunctionToken(const std::string& key);
  void FillRecievedToken(const std::string& key);

  /* вывод вектора токенов */
  void print() {
    for (auto it = tokens_.cbegin(); it != tokens_.cend(); ++it) {
      std::cout << it->value_ << " " << it->type_ << std::endl;
    }
  }

 private:
  std::string input_src_;
  std::vector<Token> tokens_;
};

class Validator {
 public:
  Validator() {}
  ~Validator() {}

 private:
};

}  // namespace s21

#endif  // SRC_S21_EXTRA_CLASSES_H