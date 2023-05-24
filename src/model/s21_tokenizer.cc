#include "s21_tokenizer.h"

namespace s21 {
std::vector<Token> Tokenizer::GetTokens() const noexcept { return tokens_; }

void Tokenizer::CreateTokenOutput() {
  if (input_src_.empty()) return;
  CheckHooksInInput();
  CheckDotsInInput();
  CreateTokens();
  CheckEdgeValues();
  CheckHooksAfterFunctions();
  CheckWithAdjacencyMatrix();
}

void Tokenizer::SetNewInput(const std::string& input_src) {
  input_src_ = input_src;
}

void Tokenizer::CreateTokens() {
  tokens_.clear();
  auto current = input_src_.cbegin();
  while (current != input_src_.cend()) {
    if (std::isdigit(*current) || *current == '.') {
      size_t shift = 0;
      tokens_.emplace_back(std::stod(&(*current), &shift), Priority::kZero,
                           "number");
      current += shift;
    } else if (std::isalpha(*current)) {
      std::regex base_regex("([a-z]+)");
      std::sregex_iterator regex_it =
          std::sregex_iterator(current, input_src_.cend(), base_regex);
      std::smatch base_match = *regex_it;
      FillRecievedToken(base_match.str());
      current += base_match.length();
    } else {
      const std::string tmp{*current++};
      FillRecievedToken(tmp);
    }
  }
  FindUnarySign();
}

void Tokenizer::CheckHooksInInput() const {
  int count_brackets = 0;
  for (const char& current_sym : input_src_) {
    if (current_sym == '(') ++count_brackets;
    if (current_sym == ')') --count_brackets;
  }
  if (count_brackets) throw std::invalid_argument("Brackets error");
}

void Tokenizer::CheckDotsInInput() const {
  for (auto current_sym = ++input_src_.cbegin();
       current_sym != input_src_.cend(); ++current_sym) {
    if (*current_sym == '.' && !std::isdigit(*(current_sym - 1)) &&
        !std::isdigit(*(current_sym + 1))) {
      throw std::invalid_argument("Dots error: dot without number");
    }
  }
}

void Tokenizer::FillRecievedToken(const std::string& key) {
  auto search_token = valid_tokens.find(key);
  if (search_token == valid_tokens.cend())
    throw std::invalid_argument("Invalid token");
  tokens_.emplace_back(search_token->second);
}

void Tokenizer::FindUnarySign() noexcept {
  if (tokens_.size() < 2) return;
  if (tokens_.begin()->priority_ == Priority::kFirst &&
      ((++tokens_.begin())->priority_ == Priority::kZero ||
       (++tokens_.begin())->priority_ == Priority::kFourth ||
       (++tokens_.begin())->type_ == "(")) {
    tokens_.front() = FillUnarySign(tokens_.front());
  }
  for (auto current = tokens_.begin(); current != tokens_.end(); ++current) {
    if ((current->priority_ == Priority::kFirst ||
         current->priority_ == Priority::kSecond ||
         current->priority_ == Priority::kFourth || current->type_ == "(" ||  //
         current->type_ == "^" ||                                             //
         current->type_ == "%")                                               //
        && (current + 1)->priority_ == Priority::kFirst) {
      *(current + 1) = FillUnarySign(*(current + 1));
    }
  }
}

Token Tokenizer::FillUnarySign(Token& other) noexcept {
  other.priority_ = Priority::kThird;
  other.is_binary_ = false;
  other.type_id_ = 5;
  if (other.type_ == "sum") other.type_ = "u_plus";
  if (other.type_ == "sub") other.type_ = "u_minus";
  return other;
}

void Tokenizer::CheckHooksAfterFunctions() const {
  for (auto current = tokens_.cbegin(); current != tokens_.cend(); ++current) {
    if (current->priority_ == Priority::kFourth && (current + 1)->type_ != "(")
      throw std::invalid_argument("Function without brackets");
  }
}

void Tokenizer::CheckEdgeValues() const {
  if (tokens_.front().is_binary_) throw std::invalid_argument("Missing value");
  if (tokens_.back().is_binary_ ||
      tokens_.back().priority_ == Priority::kFourth)
    throw std::invalid_argument("Missing value");
}

void Tokenizer::CheckWithAdjacencyMatrix() const {
  bool adjacency_matrix[][6] = {
      /*
       0  1  2  3  4  5*/
      {0, 1, 0, 1, 0, 0},  //  0: x, number
      {1, 0, 1, 0, 1, 1},  //  1: sum, sub, div, mult, mod, power
      {1, 0, 1, 0, 1, 1},  //  2: (
      {0, 1, 0, 1, 0, 0},  //  3: )
      {0, 0, 1, 0, 0, 0},  //  4: sin, cos, tan, acos, asin, atan, sqrt, ln, log
      {1, 0, 1, 0, 1, 0},  //  5: unary_plus, unary_minus
  };
  for (auto current_token = tokens_.cbegin(); current_token != --tokens_.cend();
       ++current_token) {
    auto next_token = current_token + 1;
    if (!adjacency_matrix[current_token->type_id_][next_token->type_id_])
      throw std::invalid_argument("Expression error");
  }
}
};  // namespace s21
