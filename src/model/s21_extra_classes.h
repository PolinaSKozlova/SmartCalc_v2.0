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
  Token(double value, s21::Priority priority, std::string type)
      : value_(value), priority_(priority), type_(type) {}
  ~Token() = default;
  double value_;
  s21::Priority priority_;
  // char type_;
  std::string type_;
};

const std::map<std::string, Token> valid_tokens{
    // const перед string
    {"x", Token(0.0, s21::Priority::kZero, "x")},
    {"+", Token(0.0, s21::Priority::kFirst, "sum")},
    {"-", Token(0.0, s21::Priority::kFirst, "sub")},
    {"*", Token(0.0, s21::Priority::kSecond, "*")},
    {"/", Token(0.0, s21::Priority::kSecond, "/")},
    {"(", Token(0.0, s21::Priority::kThird, "(")},
    {")", Token(0.0, s21::Priority::kThird, ")")},
    {"cos", Token(0.0, s21::Priority::kFourth, "cos")},
    {"sin", Token(0.0, s21::Priority::kFourth, "sin")},
    {"tan", Token(0.0, s21::Priority::kFourth, "tan")},
    {"acos", Token(0.0, s21::Priority::kFourth, "acos")},
    {"asin", Token(0.0, s21::Priority::kFourth, "asin")},
    {"atan", Token(0.0, s21::Priority::kFourth, "atan")},
    {"sqrt", Token(0.0, s21::Priority::kFourth, "sqrt")},
    {"ln", Token(0.0, s21::Priority::kFourth, "ln")},
    {"log", Token(0.0, s21::Priority::kFourth, "log")},
    {"mod", Token(0.0, s21::Priority::kFourth, "%")}};

class Tokenizer {
 public:
  explicit Tokenizer(const std::string& input_src, const std::string& x = "0.0")
      : input_src_(input_src), token_x_value_(x) {}
  ~Tokenizer() = default;
  std::vector<Token> GetTokens() const noexcept { return tokens_; }
  void CreateTokenOutput();

  /* вывод вектора токенов */
  void print() {
    for (auto it = tokens_.cbegin(); it != tokens_.cend(); ++it) {
      std::cout << it->value_ << " " << (int)it->priority_ << " " << it->type_
                << std::endl;
    }
  }

 private:
  void CreateTokens();
  void CheckHooksInInput() const;
  void CheckDotsInInput() const;
  void FillRecievedToken(const std::string& key);
  void FindUnarySign() noexcept;
  void CheckHooksAfterFunctions() const;
  void CheckXValue() const;
  std::string input_src_;
  std::vector<Token> tokens_;
  std::string token_x_value_;
};

class Validator {
 public:
  explicit Validator(const std::vector<Token>& other) : output_tokens_(other) {}
  ~Validator() {}
  void CreateNotation();

  /* вывод вектора токенов */
  void print() {
    for (auto it = tokens_notation_.cbegin(); it != tokens_notation_.cend();
         ++it) {
      std::cout << it->value_ << " " << (int)it->priority_ << it->type_
                << std::endl;
    }
  }

 private:
  std::vector<Token> output_tokens_;
  std::vector<Token> tokens_notation_;
};

}  // namespace s21

#endif  // SRC_S21_EXTRA_CLASSES_H