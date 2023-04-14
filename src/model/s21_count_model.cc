#include <cmath>

#include "s21_model.h"

double s21::Model::CalculateResultFromInput() const noexcept {
  double result = 0.0;
  std::stack<s21::Token> my_stack;
  for (auto pos = input_.cbegin(); pos != input_.cend(); ++pos) {
    if (TokenIsNumber(*pos)) {
      my_stack.push(*pos);
    } else if (TokenIsUnary(*pos)) {
      s21::Token value = my_stack.top();
      my_stack.pop();
      my_stack.push(UnaryOperations(pos->type_, value));
    } else if (TokenIsBinary(*pos)) {
      s21::Token value_1 = my_stack.top();
      my_stack.pop();
      s21::Token value_2 = my_stack.top();
      my_stack.pop();
      my_stack.push(BinaryOperations(pos->type_, value_1, value_2));
    }
  }
  result = my_stack.top().value_;
  return result;
}

s21::Token s21::Model::UnaryOperations(const char& sym,
                                       s21::Token& token) const noexcept {
  s21::Token result;
  switch (sym) {
    case '+':
      result.value_ = token.value_ * 1.0;
      break;
    case '-':
      result.value_ = token.value_ * (-1.0);
      break;
    case 'c':
      result.value_ = cos(token.value_);
      break;
    case 's':
      result.value_ = sin(token.value_);
      break;
    case 't':
      result.value_ = tan(token.value_);
      break;
    case 'o':
      result.value_ = acos(token.value_);
      break;
    case 'i':
      result.value_ = asin(token.value_);
      break;
    case 'a':
      result.value_ = atan(token.value_);
      break;
    case 'q':
      result.value_ = sqrt(token.value_);
      break;
    case 'l':
      result.value_ = log(token.value_);
      break;
    case 'g':
      result.value_ = log10(token.value_);
      break;
  }
  return result;
}

s21::Token s21::Model::BinaryOperations(const char& sym, s21::Token& token_1,
                                        s21::Token& token_2) const noexcept {
  s21::Token result;
  switch (sym) {
    case 'p':
      result.value_ = token_2.value_ + token_1.value_;
      break;
    case 'm':
      result.value_ = token_2.value_ - token_1.value_;
      break;
    case '*':
      result.value_ = token_2.value_ * token_1.value_;
      break;
    case '/':
      result.value_ = token_2.value_ / token_1.value_;
      break;
    case '^':
      result.value_ = pow(token_2.value_, token_1.value_);
      break;
    case '%':
      result.value_ = fmod(token_2.value_, token_1.value_);
      break;
  }
  return result;
}

bool s21::Model::TokenIsUnary(const s21::Token& sym) const noexcept {
  bool result = true;
  std::string cmp = "+-cstoiaqlg";
  if (cmp.find(sym.type_) == std::string::npos) result = false;
  return result;
}

bool s21::Model::TokenIsBinary(const s21::Token& sym) const noexcept {
  bool result = true;
  std::string cmp = "pm*/^%";
  if (cmp.find(sym.type_) == std::string::npos) result = false;
  return result;
}

bool s21::Model::TokenIsNumber(const s21::Token& sym) const noexcept {
  bool result = false;
  if (sym.type_ == 'n' || sym.type_ == 'x') result = true;
  return result;
}
