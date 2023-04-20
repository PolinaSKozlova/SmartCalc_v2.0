#ifndef SRC_S21_MODEL_H_
#define SRC_S21_MODEL_H_

#include <cmath>

#include "s21_tokenizer.h"
#include "s21_validator.h"

namespace s21 {

class MathCalculator {
 public:
  // MathCalculator() {}
  // MathCalculator(const std::string &other, std::string x_value = "0.0")
  //     : input_src_(other), x_value_(x_value) {}
  MathCalculator(const std::string &other, std::string x_value = "0.0")
      : tokens_src_(other, x_value) {}
  ~MathCalculator() = default;
  void CalculateResultFromInput() noexcept;
  void CountResult() noexcept;
  double GetAnswer() const noexcept;
  std::string GetStringAnswer() const noexcept;
  // double GetDoubleXFromString() const noexcept;
  void SetOutputTokens(std::vector<Token> &other) noexcept;

  void print() {
    std::cout << "mathcalc" << std::endl;
    for (auto it = output_tokens_.cbegin(); it != output_tokens_.cend(); ++it) {
      std::cout << it->value_ << " " << (int)it->priority_ << " " << it->type_
                << " " << it->is_binary_ << std::endl;
    }
  }

 private:
  void CreateNotationFromInput();
  Tokenizer tokens_src_;
  // std::string input_src_;
  std::vector<Token> output_tokens_{};
  // std::string x_value_;
  double answer_{};
};

class CreditCalculator {
 public:
  CreditCalculator() {}
  ~CreditCalculator() = default;

 private:
};

};  // namespace s21

#endif  // SRC_S21_MODEL_H_
