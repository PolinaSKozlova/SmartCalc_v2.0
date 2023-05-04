#ifndef SMARTCALC_SRC_S21_MODEL_H_
#define SMARTCALC_SRC_S21_MODEL_H_

#include "s21_polish_notation.h"

namespace s21 {
class MathCalculator {
 public:
  MathCalculator() = default;
  explicit MathCalculator(const std::string &other,
                          const std::string &x_value = "0.0")
      : tokens_notation_(other, x_value) {}
  ~MathCalculator() = default;
  double GetAnswer() const noexcept;
  std::string GetStringAnswer() const noexcept;
  void CalculateResultFromInput();

 private:
  void CountResult() noexcept;
  PolishNotation tokens_notation_;
  std::vector<Token> output_tokens_{};
  double answer_{};
};

};  // namespace s21

#endif  // SMARTCALC_SRC_S21_MODEL_H_
