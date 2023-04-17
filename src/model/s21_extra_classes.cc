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
      tokens_.emplace_back(std::stod(&(*current), &shift), ZERO, 'n');
      current += shift;
    } else if (TokenIsFunction(*current)) {
    } else if (TokenIsOperator(*current)) {
      FillOperatorToken(*(current++));
    } else if (TokenIsHook(*current)) {
      tokens_.emplace_back(0, THIRD, *(current++));
    } else if (*current == 'x') {
      tokens_.emplace_back(0, ZERO, *(current++));
    } else {
      throw std::invalid_argument("Invalid token");
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
      throw std::invalid_argument("Hooks error");
      break;
    }
  }
  if (count_hooks) throw std::invalid_argument("Hooks error");
}

void s21::Tokenizer::CheckDotsInInput() const {
  for (auto current_sym = ++input_src_.cbegin();
       current_sym != input_src_.cend(); ++current_sym) {
    if (*current_sym == '.' && !std::isdigit(*(current_sym - 1)) &&
        !std::isdigit(*(current_sym + 1))) {
      throw std::invalid_argument("Dots error: dot without number");
      break;
    }
  }
}

bool s21::Tokenizer::TokenIsFunction(const char& sym) const {
  bool result = true;
  std::string cmp = "cstoiaqnlm";
  if (cmp.find(sym) == std::string::npos) result = false;
  return result;
}

bool s21::Tokenizer::TokenIsOperator(const char& sym) const {
  bool result = true;
  std::string cmp = "+-*/^";
  if (cmp.find(sym) == std::string::npos) result = false;
  return result;
}

bool s21::Tokenizer::TokenIsNumber(const char& sym) const {
  bool result = false;
  if (std::isdigit(sym) || sym == '.') {
    result = true;
  }
  return result;
}

bool s21::Tokenizer::TokenIsHook(const char& sym) const {
  bool result = false;
  if (sym == '(' || sym == ')') result = true;
  return result;
}

void s21::Tokenizer::FillOperatorToken(const char& sym) noexcept {
  if (sym == '+') {
    tokens_.emplace_back(0.0, FIRST, 'p');
  } else if (sym == '-') {
    tokens_.emplace_back(0.0, FIRST, 'm');
  } else if (sym == '*') {
    tokens_.emplace_back(0.0, SECOND, '*');
  } else if (sym == '/') {
    tokens_.emplace_back(0.0, SECOND, '/');
  } else if (sym == '^') {
    tokens_.emplace_back(0.0, THIRD, '^');
  }
}

void s21::Tokenizer::FillFunctionToken() {}
