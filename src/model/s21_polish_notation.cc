#include "s21_polish_notation.h"

namespace s21 {
std::vector<Token> PolishNotation::CreateNotation() {
  tokens_.CreateTokenOutput();
  if (!output_notation_.empty()) output_notation_.clear();
  std::stack<Token> result_stack;
  std::vector<Token> copy_input(tokens_.GetTokens());
  for (const Token &current_token : copy_input) {
    if (current_token.priority_ == s21::Priority::kZero) {
      output_notation_.push_back(current_token);
    } else if (current_token.priority_ == s21::Priority::kFourth ||
               current_token.type_ == "(") {
      result_stack.push(current_token);
    } else if (current_token.type_ == ")") {
      while (result_stack.top().type_ != "(") {
        output_notation_.push_back(result_stack.top());
        result_stack.pop();
      };
      result_stack.pop();
    } else {
      while (!result_stack.empty() &&
             ((result_stack.top().priority_ >= current_token.priority_ &&
               current_token.type_ != "^") ||
              (result_stack.top().priority_ > current_token.priority_ &&
               current_token.type_ == "^")) &&
             result_stack.top().type_ != "(") {
        output_notation_.push_back(result_stack.top());
        result_stack.pop();
      }
      result_stack.push(current_token);
    }
  }
  while (!result_stack.empty()) {
    output_notation_.push_back(result_stack.top());
    result_stack.pop();
  }
  return output_notation_;
}

void PolishNotation::SetTokensNewValues(const std::string &src) noexcept {
  tokens_.SetNewInput(src);
}

};  // namespace s21