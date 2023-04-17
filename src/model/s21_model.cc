#include "s21_model.h"

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
    if (*current_sym == '.' && *(current_sym - 1) == '.') {
      throw std::invalid_argument("Dots error: two dots in input");
      break;
    }
    if (*current_sym == '.' && !std::isdigit(*(current_sym - 1)) &&
        !std::isdigit(*(current_sym + 1))) {
      throw std::invalid_argument("Dots error: dot without number");
      break;
    }
  }
}
