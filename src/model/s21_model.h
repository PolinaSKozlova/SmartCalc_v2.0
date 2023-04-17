#ifndef S21_MODEL_H_
#define S21_MODEL_H_

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
  bool CheckHooks();

 private:
  std::string input_src_;
  std::vector<Token> tokens_;
};

class Validator {
 public:
 private:
};

class Model {
 public:
 private:
};

class CreditCalculator {
 public:
 private:
};

};  // namespace s21

#endif  // S21_MODEL_H_
