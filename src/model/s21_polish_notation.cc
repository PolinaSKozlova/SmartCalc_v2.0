#include "s21_polish_notation.h"

std::vector<s21::Token> s21::PolishNotation::CreateNotation() {
  try {
    tokens_.CreateTokenOutput();
  } catch (std::invalid_argument &e) {
    std::cerr << e.what() << std::endl;
  }
  std::stack<Token> my_stack;
  std::vector<Token> copy_input(tokens_.GetTokens());
  for (auto &current_token : copy_input) {
    if (current_token.priority_ == s21::Priority::kZero) {
      output_notation_.push_back(current_token);
    } else if (current_token.priority_ == s21::Priority::kFourth ||
               current_token.type_ == "(") {
      my_stack.push(current_token);
    } else if (current_token.type_ == ")") {
      while (my_stack.top().type_ != "(") {
        output_notation_.push_back(my_stack.top());
        my_stack.pop();
      };
      my_stack.pop();
    } else {
      while (!my_stack.empty() &&
             my_stack.top().priority_ >= current_token.priority_ &&
             my_stack.top().type_ != "(") {
        if (current_token.type_ != "^") {
          output_notation_.push_back(my_stack.top());
          my_stack.pop();
        }
      }
      my_stack.push(current_token);
    }
  }
  while (!my_stack.empty()) {
    output_notation_.push_back(my_stack.top());
    my_stack.pop();
  }
  return output_notation_;
}
