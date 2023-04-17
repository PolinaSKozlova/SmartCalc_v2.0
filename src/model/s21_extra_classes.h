#ifndef SRC_S21_EXTRA_CLASSES_H_
#define SRC_S21_EXTRA_CLASSES_H_

#include <cctype>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

namespace s21 {
class Token {
 public:
  Token(double value, int priority, char type)
      : value_(value), priority_(priority), type_(type) {}
  ~Token() = default;
  double value_;
  int priority_;
  char type_;
};

class Tokenizer {
 public:
  explicit Tokenizer(const std::string& input_src) : input_src_(input_src) {}
  ~Tokenizer() = default;
  std::vector<Token> GetTokens() const noexcept { return tokens_; }
  void CreateTokenOutput();
  void CheckHooksInInput() const;
  void CheckDotsInInput() const;
  bool TokenIsFunction(const char& sym) const;
  bool TokenIsOperator(const char& sym) const;
  bool TokenIsNumber(const char& sym) const;
  bool TokenIsHook(const char& sym) const;

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