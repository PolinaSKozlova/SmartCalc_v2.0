#include "s21_model_old.h"

std::pair<bool, std::string> s21::Model::StartSmartCalc() noexcept {
  std::pair<bool, std::string> result = {true, "OK"};
  result = ValidationSrc();
  if (result.first) {
    // output_ = std::to_string(CalculateResultFromInput());
    output_ = CalculateResultFromInput();
  } else {
    // output_ = result.second;
  }
  return result;
}

double s21::Model::GetOutput() const noexcept { return output_; }

std::string s21::Model::GetStringOutput() const noexcept {
  std::ostringstream oss;
  oss.precision(7);
  oss << output_;
  return oss.str();
}
