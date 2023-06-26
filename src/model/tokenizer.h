#ifndef SMARTCALC_TOKENIZER_H_
#define SMARTCALC_TOKENIZER_H_

#include "token.h"

namespace smartcalc {
class Tokenizer {
 public:
  Tokenizer() = default;
  explicit Tokenizer(const std::string& input_src) : input_src_(input_src) {}
  ~Tokenizer() = default;
  std::vector<Token> GetTokens() const noexcept;
  void CreateTokenOutput();
  void SetNewInput(const std::string& input_src);

 private:
  void CreateTokens();
  void CheckHooksInInput() const;
  void CheckDotsInInput() const;
  void FillRecievedToken(const std::string& key);
  Token FillUnarySign(Token& other) noexcept;
  void FindUnarySign() noexcept;
  void CheckHooksAfterFunctions() const;
  void CheckEdgeValues() const;
  void CheckWithAdjacencyMatrix() const;
  std::string input_src_{};
  std::vector<Token> tokens_{};
};
}  // namespace smartcalc

#endif  // SMARTCALC_TOKENIZER_H_