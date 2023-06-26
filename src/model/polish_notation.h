#ifndef SMARTCALC_POLISHNOTATION_H_
#define SMARTCALC_POLISHNOTATION_H_

#include "tokenizer.h"

namespace smartcalc {
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
}  // namespace smartcalc

#endif  // SMARTCALC_POLISHNOTATION_H_