#include "s21_model.h"

void s21::MathCalculator::CalculateResultFromInput() {
  try {
    output_tokens_ = tokens_notation_.CreateNotation();
    // CountResult();
  } catch (std::invalid_argument& e) {
    std::cerr << e.what() << std::endl;
  }
}

void s21::MathCalculator::CountResult() noexcept {
  std::stack<Token> my_stack;
  for (auto& current_token : output_tokens_) {
    if (current_token.priority_ == s21::Priority::kZero) {
      my_stack.push(current_token);
    } else if (current_token.is_binary_) {
      s21::Token arg_1 = my_stack.top();
      my_stack.pop();
      s21::Token arg_2 = my_stack.top();
      my_stack.pop();
      ChooseFunction = current_token.type_;
      // my_stack.push();
    } else {
      s21::Token arg_1 = my_stack.top();
      my_stack.pop();
      // my_stack.push();
    }
  }
  answer_ = my_stack.top().value_;
}

double s21::MathCalculator::GetAnswer() const noexcept { return answer_; }

std::string s21::MathCalculator::GetStringAnswer() const noexcept {
  std::ostringstream oss;
  oss.precision(7);
  oss << answer_;
  return oss.str();
}

// double s21::MathCalculator::GetDoubleXFromString() const noexcept {
//   return std::stod(x_value_);
// }

// void s21::MathCalculator::SetOutputTokens(std::vector<Token>& other) noexcept
// {
//   output_tokens_ = other;
// }
