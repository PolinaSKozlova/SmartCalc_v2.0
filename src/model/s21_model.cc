#include "s21_model.h"

void s21::MathCalculator::CalculateResultFromInput() noexcept {
  try {
    CreateNotationFromInput();
  } catch (std::invalid_argument& e) {
    std::cerr << e.what() << std::endl;
  }
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

void s21::MathCalculator::SetOutputTokens(std::vector<Token>& other) noexcept {
  output_tokens_ = other;
}

void s21::MathCalculator::CreateNotationFromInput() {
  try {
    // Tokenizer tokens_src(input_src_, x_value_);
    tokens_src_.CreateTokenOutput();
    PolishNotation p_not(tokens_src_.GetTokens());
    output_tokens_ = p_not.CreateNotation();
  } catch (std::invalid_argument& e) {
    std::cerr << e.what() << std::endl;
  }
}
