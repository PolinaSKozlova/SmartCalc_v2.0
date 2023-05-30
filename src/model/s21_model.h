#ifndef SMARTCALC_SRC_S21_MODEL_H_
#define SMARTCALC_SRC_S21_MODEL_H_

#include "s21_polish_notation.h"

namespace s21 {
class MathCalculator {
 public:
  MathCalculator() = default;
  explicit MathCalculator(const std::string &other) : tokens_notation_(other) {}
  ~MathCalculator() = default;
  double GetAnswer() const noexcept;
  std::string GetStringAnswer() const noexcept;
  void CalculateResultFromInput(const std::string &src,
                                const std::string &x_value = "0.0");
  std::pair<std::vector<double>, std::vector<double>>
  CountCoordinatesForChartArea(const std::string &src, double x_min,
                               double x_max, double y_min, double y_max);

 private:
  void CheckXValue(const std::string &x_value) const;
  double GetXValue(const std::string &x_value) const;
  void CountResult(double x_value) noexcept;
  double GetStep(double x_min, double x_max);
  PolishNotation tokens_notation_;
  std::vector<Token> output_tokens_{};
  double answer_{};
};
};  // namespace s21

#endif  // SMARTCALC_SRC_S21_MODEL_H_
