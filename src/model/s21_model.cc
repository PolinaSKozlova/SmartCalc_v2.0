#include "s21_model.h"

void s21::MathCalculator::CalculateResultFromInput(const std::string &src,
                                                   const std::string &x_value) {
  // try {
  tokens_notation_.SetTokensNewValues(src, x_value);
  if (!output_tokens_.empty()) output_tokens_.clear();
  output_tokens_ = tokens_notation_.CreateNotation();
  CountResult();
  // } catch (std::invalid_argument& e) {
  // std::cerr << e.what() << std::endl;
  //   throw e;
  // }
}

void s21::MathCalculator::CountResult() noexcept {
  std::stack<double> result_stack;
  for (auto &current_token : output_tokens_) {
    if (current_token.priority_ == s21::Priority::kZero) {
      result_stack.push(current_token.value_);
    } else if (current_token.is_binary_) {
      double arg_2 = result_stack.top();
      result_stack.pop();
      double arg_1 = result_stack.top();
      result_stack.pop();
      result_stack.push(
          functions_for_count.find(current_token.type_)->second(arg_1, arg_2));
    } else {
      double arg_1 = result_stack.top();
      result_stack.pop();
      result_stack.push(
          functions_for_count.find(current_token.type_)->second(arg_1, 0.0));
    }
  }
  if (result_stack.size()) answer_ = result_stack.top();
}

double s21::MathCalculator::GetAnswer() const noexcept { return answer_; }

std::string s21::MathCalculator::GetStringAnswer() const noexcept {
  std::ostringstream oss;
  oss.precision(10);
  oss << answer_;
  return oss.str();
}
