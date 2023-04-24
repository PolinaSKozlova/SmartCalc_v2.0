#ifndef SMARTCALC_SRC_S21_MODEL_H_
#define SMARTCALC_SRC_S21_MODEL_H_

#include <cmath>
#include <functional>

#include "s21_polish_notation.h"

namespace s21 {
// map для функторов вычисления
const std::map<std::string, std::function<double(double arg_1, double arg_2)>>
    functions_for_count{
        {"u_minus", [](double arg_1,
                       double arg_2 = 0.0) { return (arg_1 * -1.0 + arg_2); }},
        {"u_plus", [](double arg_1,
                      double arg_2 = 0.0) { return (arg_1 * -1.0 + arg_2); }},
        {"cos",
         [](double arg_1, double arg_2 = 0.0) { return (cos(arg_1) + arg_2); }},
        {"sin",
         [](double arg_1, double arg_2 = 0.0) { return (sin(arg_1) + arg_2); }},
        {"tan",
         [](double arg_1, double arg_2 = 0.0) { return (tan(arg_1) + arg_2); }},
        {"acos", [](double arg_1,
                    double arg_2 = 0.0) { return (acos(arg_1) + arg_2); }},
        {"asin", [](double arg_1,
                    double arg_2 = 0.0) { return (asin(arg_1) + arg_2); }},
        {"atan", [](double arg_1,
                    double arg_2 = 0.0) { return (atan(arg_1) + arg_2); }},
        {"sqrt", [](double arg_1,
                    double arg_2 = 0.0) { return (sqrt(arg_1) + arg_2); }},
        {"ln",
         [](double arg_1, double arg_2 = 0.0) { return (log(arg_1) + arg_2); }},
        {"log", [](double arg_1,
                   double arg_2 = 0.0) { return (log10(arg_1) + arg_2); }},
        {"sum", [](double arg_1, double arg_2) { return (arg_1 + arg_2); }},
        {"sub", [](double arg_1, double arg_2) { return (arg_1 - arg_2); }},
        {"*", [](double arg_1, double arg_2) { return (arg_1 * arg_2); }},
        {"/", [](double arg_1, double arg_2) { return (arg_1 / arg_2); }},
        {"pow", [](double arg_1, double arg_2) { return (pow(arg_1, arg_2)); }},
        {"mod",
         [](double arg_1, double arg_2) { return (fmod(arg_1, arg_2)); }}};

class MathCalculator {
 public:
  explicit MathCalculator(const std::string &other,
                          const std::string &x_value = "0.0")
      : tokens_notation_(other, x_value) {}
  ~MathCalculator() = default;
  double GetAnswer() const noexcept;
  std::string GetStringAnswer() const noexcept;
  void CalculateResultFromInput();
  // нужны ли  данные методы
  // double GetDoubleXFromString() const noexcept;
  // void SetOutputTokens(std::vector<Token> &other) noexcept;

  void print() {
    std::cout << "mathcalc" << std::endl;
    std::cout << "value priority type " << std::endl;
    for (const auto &it : output_tokens_) {
      std::cout << "   " << it.value_ << "    " << (int)it.priority_
                << "       " << it.type_ << std::endl;
      // << "     " << it.is_binary_
    }
  }

 private:
  void CountResult() noexcept;
  PolishNotation tokens_notation_;
  std::vector<Token> output_tokens_{};
  double answer_{};
};

};  // namespace s21

#endif  // SMARTCALC_SRC_S21_MODEL_H_
