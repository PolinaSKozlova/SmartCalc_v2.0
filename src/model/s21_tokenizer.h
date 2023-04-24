#ifndef SMARTCALC_SRC_S21_TOKENIZER_H_
#define SMARTCALC_SRC_S21_TOKENIZER_H_

#include "s21_token.h"

/*
 * ZERO - x, number
 * FIRST - sum, sub
 * SECOND - div, mult, mod
 * THIRD - hooks, pow, unary plus, unary minus
 * FOURTH - sin, cos, tan, acos, asin, atan, sqrt, ln, log
 */

namespace s21 {
class Tokenizer {
 public:
  Tokenizer() = default;
  explicit Tokenizer(const std::string& input_src, const std::string& x = "0.0")
      : input_src_(input_src), token_x_value_(x) {}
  ~Tokenizer() = default;
  std::vector<Token> GetTokens() const noexcept;
  double GetXValue() const noexcept;
  void CreateTokenOutput();

  /* вывод вектора токенов */
  void print() {
    std::cout << "tokenizer" << std::endl;
    for (auto it = tokens_.cbegin(); it != tokens_.cend(); ++it) {
      std::cout << it->value_ << " " << (int)it->priority_ << " " << it->type_
                << " " << it->is_binary_ << std::endl;
    }
  }

 private:
  void CreateTokens();
  void CheckHooksInInput() const;
  void CheckDotsInInput() const;
  void FillRecievedToken(const std::string& key);
  void FindUnarySign() noexcept;
  void CheckHooksAfterFunctions() const;
  void CheckXValue() const;
  void CheckEdgeValues() const;
  void FinalInputCheck() const;
  std::string input_src_;
  std::vector<Token> tokens_;
  std::string token_x_value_;
};
}  // namespace s21

#endif  // SMARTCALC_SRC_S21_TOKENIZER_H_