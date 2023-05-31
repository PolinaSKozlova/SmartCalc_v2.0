#ifndef SMARTCALC_SRC_S21_MODEL_H_
#define SMARTCALC_SRC_S21_MODEL_H_

#include "s21_polish_notation.h"

namespace s21 {
struct MaxMinValues {
  MaxMinValues() = default;
  MaxMinValues(double min_x, double max_x, double min_y, double max_y)
      : min_x_(min_x), max_x_(max_x), min_y_(min_y), max_y_(max_y) {}
  double min_x_{};
  double max_x_{};
  double min_y_{};
  double max_y_{};
};

class MathCalculator {
 public:
  MathCalculator() = default;
  explicit MathCalculator(const std::string &other) : tokens_notation_(other) {}
  ~MathCalculator() = default;
  double GetAnswer() const noexcept;
  std::string GetStringAnswer() const noexcept;
  void CalculateResultFromInput(const std::string &src,
                                const std::string &x_value = "0.0");
  void CountCoordinatesForChartArea(
      const std::string &src, MaxMinValues max_min_values,
      std::pair<std::vector<double>, std::vector<double>> &xy_pairs);

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
