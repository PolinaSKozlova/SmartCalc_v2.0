#include "s21_model.h"

void s21::MathCalculator::CalculateResultFromInput() {
  try {
    output_tokens_ = tokens_notation_.CreateNotation();
    CountResult();
  } catch (std::invalid_argument& e) {
    std::cerr << e.what() << std::endl;
  }
}

void s21::MathCalculator::CountResult() noexcept {}

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
