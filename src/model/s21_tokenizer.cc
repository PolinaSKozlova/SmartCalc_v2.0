#include "s21_tokenizer.h"

#include "s21_model.h"

std::vector<s21::Token> s21::Tokenizer::GetTokens() const noexcept {
  return tokens_;
}

void s21::Tokenizer::CreateTokenOutput() {
  if (!input_src_.empty()) {
    CheckHooksInInput();
    CheckDotsInInput();
    CheckXValue();
    CreateTokens();
    CheckEdgeValues();
    CheckHooksAfterFunctions();
    FinalInputCheck();
  }
}

void s21::Tokenizer::SetNewValues(const std::string& input_src,
                                  const std::string& x) {
  input_src_.clear();
  token_x_value_.clear();
  input_src_ = input_src;
  token_x_value_ = x;
}

void s21::Tokenizer::CreateTokens() {
  tokens_.clear();
  auto current = input_src_.cbegin();
  while (current != input_src_.cend()) {
    if (std::isdigit(*current) || *current == '.') {
      size_t shift = 0;
      tokens_.emplace_back(std::stod(&(*current), &shift), s21::Priority::kZero,
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

double s21::Tokenizer::GetXValue() const noexcept {
  return std::stod(token_x_value_);
}

void s21::Tokenizer::CheckHooksInInput() const {
  int count_hooks = 0;
  for (auto current_sym = input_src_.cbegin(); current_sym != input_src_.cend();
       ++current_sym) {
    if (*current_sym == '(') ++count_hooks;
    if (*current_sym == ')') --count_hooks;
    if (*current_sym == '(' && *(current_sym + 1) == ')') {
      throw std::invalid_argument("Empty hooks");
    }
  }
  if (count_hooks) throw std::invalid_argument("Hooks error");
}

void s21::Tokenizer::CheckDotsInInput() const {
  for (auto current_sym = ++input_src_.cbegin();
       current_sym != input_src_.cend(); ++current_sym) {
    if (*current_sym == '.' && *(current_sym - 1) == '.')
      throw std::invalid_argument("Dots error: two dots in input");
    if (*current_sym == '.' && !std::isdigit(*(current_sym - 1)) &&
        !std::isdigit(*(current_sym + 1))) {
      throw std::invalid_argument("Dots error: dot without number");
    }
  }
}

void s21::Tokenizer::FillRecievedToken(const std::string& key) {
  auto search_token = valid_tokens.find(key);
  if (search_token == valid_tokens.cend())
    throw std::invalid_argument("Invalid token");
  tokens_.emplace_back(search_token->second);
  if (key == "x") {
    tokens_.back().value_ = GetXValue();
  }
}

void s21::Tokenizer::FindUnarySign() noexcept {
  if (tokens_.front().priority_ == s21::Priority::kFirst) {
    tokens_.front() = FillUnarySign(tokens_.front());
  }
  for (auto current = tokens_.begin(); current != tokens_.end(); ++current) {
    if ((current->priority_ == s21::Priority::kFirst ||
         current->priority_ == s21::Priority::kSecond ||
         current->priority_ == s21::Priority::kFourth ||
         current->type_ == "(" || current->type_ == "^" ||
         current->type_ == "%") &&
        (current + 1)->priority_ == s21::Priority::kFirst) {
      *(current + 1) = FillUnarySign(*(current + 1));
    }
  }
}

s21::Token s21::Tokenizer::FillUnarySign(Token& other) noexcept {
  other.priority_ = s21::Priority::kThird;
  other.is_binary_ = false;
  if (other.type_ == "sum") other.type_ = "u_plus";
  if (other.type_ == "sub") other.type_ = "u_minus";
  return other;
}

void s21::Tokenizer::CheckHooksAfterFunctions() const {
  for (auto current = tokens_.cbegin(); current != tokens_.cend(); ++current) {
    if (current->priority_ == s21::Priority::kFourth &&
        (current + 1)->type_ != "(")
      throw std::invalid_argument("Function without hooks");
  }
}

void s21::Tokenizer::CheckXValue() const {
  for (auto iterator_to_num = token_x_value_.cbegin();
       iterator_to_num != token_x_value_.cend(); ++iterator_to_num) {
    if ((!std::isdigit(*iterator_to_num) && *iterator_to_num != '.') ||
        (*iterator_to_num == '.' && *(iterator_to_num + 1) == '.') ||
        (*iterator_to_num == '.' && token_x_value_.length() == 1)) {
      throw std::invalid_argument("Incorrect x value");
    }
  }
}

void s21::Tokenizer::CheckEdgeValues() const {
  if (tokens_.front().is_binary_)
    throw std::invalid_argument("Missing operand");
  if (tokens_.back().is_binary_ ||
      tokens_.back().priority_ == s21::Priority::kFourth)
    throw std::invalid_argument("Missing operand");
}

void s21::Tokenizer::FinalInputCheck() const {
  for (auto current_token = tokens_.cbegin(); current_token != --tokens_.cend();
       ++current_token) {
    if (current_token->priority_ == s21::Priority::kZero &&
        ((current_token + 1)->priority_ == s21::Priority::kFourth ||
         (current_token + 1)->type_ == "(")) {
      throw std::invalid_argument("Missing operator");
    }
    if ((current_token->priority_ == s21::Priority::kSecond ||
         current_token->priority_ == s21::Priority::kFirst) &&
        ((current_token + 1)->type_ == ")" ||
         (current_token + 1)->type_ == "^" ||
         (current_token + 1)->type_ == "%")) {
      throw std::invalid_argument("Missing value");
    }
    if (current_token->is_binary_ &&
        ((current_token + 1)->priority_ != s21::Priority::kZero &&
         (current_token + 1)->priority_ != s21::Priority::kFourth &&
         (current_token + 1)->type_ != "("))
      throw std::invalid_argument("Missing value");
    // if (((current_token->priority_ == (current_token + 1)->priority_ ||
    //       current_token->type_ == (current_token + 1)->type_)) &&
    //     ((current_token->type_ != "(" || current_token->type_ != ")") &&
    //      (current_token + 1)->priority_ != s21::Priority::kThird)) {
    //   std::cout << current_token->type_ << " " << (current_token + 1)->type_
    //             << std::endl;
    //   throw std::invalid_argument("Two equal tokens in a row");
    // }
  }
}
