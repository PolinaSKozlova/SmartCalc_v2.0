#ifndef SMARTCALC_S21_POLISHNOTATION_H_
#define SMARTCALC_S21_POLISHNOTATION_H_

#include "s21_tokenizer.h"

namespace s21 {
class PolishNotation {
 public:
  PolishNotation() = default;
  explicit PolishNotation(const std::string& src) : tokens_(src) {}
  ~PolishNotation() {}
  std::vector<Token> CreateNotation();
  void SetTokensNewValues(const std::string& src) noexcept;

 private:
  Tokenizer tokens_;
  std::vector<Token> output_notation_{};
};
}  // namespace s21

#endif  // SMARTCALC_SRC_S21_POLISHNOTATION_H_