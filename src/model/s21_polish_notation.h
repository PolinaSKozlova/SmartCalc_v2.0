#ifndef SRC_S21_POLISHNOTATION_H_
#define SRC_S21_POLISHNOTATION_H_

#include "s21_tokenizer.h"

namespace s21 {

class PolishNotation {
 public:
  PolishNotation() = default;
  explicit PolishNotation(const std::vector<Token>& other)
      : output_tokens_(other) {}
  ~PolishNotation() {}
  std::vector<Token> CreateNotation();
  // void CreateNotation();
  std::vector<Token> GetOutputTokens() const noexcept { return output_tokens_; }

  /* вывод вектора токенов */
  void print() {
    std::cout << "PolishNotation" << std::endl;
    for (auto const& it : output_tokens_) {
      std::cout << it.value_ << " " << (int)it.priority_ << " " << it.type_
                << " " << it.is_binary_ << std::endl;
    }
  }

 private:
  std::vector<Token> output_tokens_{};
};

}  // namespace s21

#endif  // SRC_S21_POLISHNOTATION_H_