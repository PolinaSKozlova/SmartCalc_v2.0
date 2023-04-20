#ifndef SRC_S21_TOKENIZER_H_
#define SRC_S21_TOKENIZER_H_

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
  Token(double value, s21::Priority priority, std::string type,
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

const std::map<std::string, Token> valid_tokens{
    // const перед string
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
    {"mod", Token(0.0, s21::Priority::kFourth, "%", true)}};

class Tokenizer {
 public:
  explicit Tokenizer(const std::string& input_src, const std::string& x = "0.0")
      : input_src_(input_src), token_x_value_(x) {}
  ~Tokenizer() = default;
  std::vector<Token> GetTokens() noexcept;
  void CreateTokenOutput();
  double GetXValue() const noexcept;
  /* вывод вектора токенов */
  void print() {
    std::cout << "tokenizer" << std::endl;
    for (auto it = tokens_.cbegin(); it != tokens_.cend(); ++it) {
      std::cout << it->value_ << " " << (int)it->priority_ << " " << it->type_
                << " " << it->is_binary_ << std::endl;
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
  void FinalInputCheck() const;
  std::string input_src_;
  std::vector<Token> tokens_;
  std::string token_x_value_;
};
}  // namespace s21

#endif  // SRC_S21_TOKENIZER_H_