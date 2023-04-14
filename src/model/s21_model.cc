#include "s21_model.h"

std::pair<bool, std::string> s21::Model::StartCalculations() noexcept {
  std::pair<bool, std::string> result = {true, "OK"};
  result = ValidationSrc();
  if (result.first) {
    // double answer = CalculateExpression();
    // output_ = std::to_string(answer);
    output_ = std::to_string(CalculateResultFromInput());
  }
  return result;
}

std::string s21::Model::GetOutput() const noexcept { return output_; }
