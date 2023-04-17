#include "s21_extra_classes.h"

#include "s21_model.h"

void s21::Tokenizer::CreateTokenOutput() {
  try {
    CheckHooksInInput();
    CheckDotsInInput();
    CreateTokens();
  } catch (std::invalid_argument& e) {
    std::cerr << e.what() << std::endl;
  }
}

void s21::Tokenizer::CreateTokens() {
  auto current = input_src_.cbegin();
  while (current != input_src_.cend()) {
    if (TokenIsNumber(*current)) {
      size_t shift = 0;
      tokens_.emplace_back(std::stod(&(*current), &shift), s21::Priority::kZero,
                           'n');
      current += shift;
    } else if (std::isalpha(*current)) {
      std::regex base_regex("([a-z]+)");
      std::sregex_iterator it =
          std::sregex_iterator(current, input_src_.cend(), base_regex);
      std::smatch base_match = *it;
      FillRecievedToken(base_match.str());
      current += base_match.length();
    } else {
      const std::string tmp{*current++};
      FillRecievedToken(tmp);
    }
  }
  print();
}

void s21::Tokenizer::CheckHooksInInput() const {
  int count_hooks = 0;
  for (auto current_sym = input_src_.cbegin(); current_sym != input_src_.cend();
       ++current_sym) {
    if (*current_sym == '(') ++count_hooks;
    if (*current_sym == ')') --count_hooks;
    if (*current_sym == '(' && *(current_sym + 1) == ')') {
      throw std::invalid_argument("Empty hooks error");
      break;
    }
  }
  if (count_hooks) throw std::invalid_argument("Hooks error");
}

void s21::Tokenizer::CheckDotsInInput() const {
  for (auto current_sym = ++input_src_.cbegin();
       current_sym != input_src_.cend(); ++current_sym) {
    if (*current_sym == '.' &&
        (!std::isdigit(*(current_sym - 1)) || *(current_sym - 1) == '.') &&
        !std::isdigit(*(current_sym + 1))) {
      throw std::invalid_argument("Dots error: dot without number");
      break;
    }
  }
}

bool s21::Tokenizer::TokenIsNumber(const char& sym) const {
  bool result = false;
  if (std::isdigit(sym) || sym == '.') {
    result = true;
  }
  return result;
}

void s21::Tokenizer::FillRecievedToken(const std::string& key) {
  auto search_token = valid_tokens.find(key);
  if (search_token == valid_tokens.cend())
    throw std::invalid_argument("Invalid token");
  tokens_.emplace_back(search_token->second);
}
