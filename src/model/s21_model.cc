#include "s21_model.h"

std::pair<bool, std::string> s21::Model::StartSmartCalc() noexcept {
  std::pair<bool, std::string> result = {true, "OK"};
  result = ValidationSrc();
  if (result.first) {
    output_ = std::to_string(CalculateResultFromInput());
  } else {
    output_ = result.second;
  }
  return result;
}

std::string s21::Model::GetOutput() const noexcept { return output_; }
