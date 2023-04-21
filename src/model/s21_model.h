#ifndef SRC_S21_MODEL_H_
#define SRC_S21_MODEL_H_

#include <cmath>

#include "s21_polish_notation.h"
#include "s21_tokenizer.h"

namespace s21 {

// map для функторов вычисления
// const std::map<std::string, std::function(double arg_1, double arg_2)>
// functions_for_count{};

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

#endif  // SRC_S21_MODEL_H_
