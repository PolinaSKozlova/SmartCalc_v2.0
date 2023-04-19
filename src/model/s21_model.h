#ifndef S21_MODEL_H_
#define S21_MODEL_H_

#include "s21_extra_classes.h"

namespace s21 {

class MathCalculator {
 public:
  MathCalculator() {}
  MathCalculator(const std::string &other, std::string x_value = "0.0")
      : input_src_(other), x_value_(x_value) {}
  ~MathCalculator() = default;
  void CalculateResultFromInput() const noexcept;
  double GetAnswer() const noexcept;
  std::string GetStringAnswer() const noexcept;
  double GetDoubleXFromString() const noexcept;
  void SetOutputTokens(std::vector<Token> &other) noexcept;

 private:
  std::string input_src_;
  std::vector<Token> output_tokens_;
  std::string x_value_;
  // double x_value_;
  double answer_;
};

class CreditCalculator {
 public:
  CreditCalculator() {}
  ~CreditCalculator() = default;

 private:
};

};  // namespace s21

#endif  // S21_MODEL_H_
