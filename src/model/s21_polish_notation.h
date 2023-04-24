#ifndef SMARTCALC_SRC_S21_POLISHNOTATION_H_
#define SMARTCALC_SRC_S21_POLISHNOTATION_H_

#include "s21_tokenizer.h"

namespace s21 {

class PolishNotation {
 public:
  PolishNotation() = default;
  explicit PolishNotation(const std::string& src,
                          const std::string& x_value = "0.0")
      : tokens_(src, x_value) {}
  ~PolishNotation() {}
  std::vector<Token> CreateNotation();
  std::vector<Token> GetOutputTokens() const noexcept {
    return output_notation_;
  }

  /* вывод вектора токенов */
  void print() {
    std::cout << "PolishNotation" << std::endl;
    for (auto const& it : output_notation_) {
      std::cout << it.value_ << " " << (int)it.priority_ << " " << it.type_
                << " " << it.is_binary_ << std::endl;
    }
  }

 private:
  Tokenizer tokens_;
  std::vector<Token> output_notation_{};
};

}  // namespace s21

#endif  // SMARTCALC_SRC_S21_POLISHNOTATION_H_