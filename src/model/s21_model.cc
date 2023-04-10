#include "s21_model.h"

#include <iostream>

bool s21::Model::ValidationSrc(const Model& m) noexcept {
  bool result = true;
  if (!CheckHooks() || !CheckDots()) {
    result = false;
  } else {
    if (CreateTokens()) {
      CreateNotation();
    } else {
      result = false;
    }
  }
  return result;
}

bool s21::Model::CheckHooks() noexcept {
  int count_hooks = 0;
  bool result = true;
  for (size_t i = 0; i < src_.length() && count_hooks >= 0; ++i) {
    if (src_[i] == '(') ++count_hooks;
    if (src_[i] == ')') --count_hooks;
    if (src_[i] == '(' && src_[i + 1] == ')') {
      result = false;
      break;
    }
  }
  if (count_hooks) {
    result = false;
  }
  return result;
}

bool s21::Model::CheckDots() noexcept {
  bool result = true;
  if (src_[0] == '.' && !(std::isdigit(src_[1]))) {
    result = false;
  }
  for (size_t i = 1; i < src_.length() - 1; ++i) {
    if ((src_[i] == '.' && !std::isdigit(src_[i + 1]) &&
         !std::isdigit(src_[i - 1])) ||
        (src_[i] == '.' && src_[i + 1] == '.')) {
      result = false;
      break;
    }
  }
  return result;
}

bool s21::Model::IsFunction(const char& sym) noexcept {
  bool result = true;
  std::string cmp = "cstoiaqnlm";
  if (cmp.find(sym) == std::string::npos) result = false;
  return result;
}

bool s21::Model::IsOperator(const char& sym) noexcept {
  bool result = true;
  std::string cmp = "+-*/^";
  if (cmp.find(sym) == std::string::npos) result = false;
  return result;
}

bool s21::Model::IsHooks(const char& sym) const noexcept {
  bool result = false;
  if (sym == '(' || sym == ')') result = true;
  return result;
}

bool s21::Model::TokenFunction(size_t pos) noexcept {
  bool result = true;
  if (!src_.compare(pos, 3, "cos")) {
    input_.emplace_back(0.0, FOURTH, 'c');
  } else if (!src_.compare(pos, 3, "sin")) {
    input_.emplace_back(0.0, FOURTH, 's');
  } else if (!src_.compare(pos, 3, "tan")) {
    input_.emplace_back(0.0, FOURTH, 't');
  } else if (!src_.compare(pos, 4, "acos")) {
    input_.emplace_back(0.0, FOURTH, 'o');
  } else if (!src_.compare(pos, 4, "asin")) {
    input_.emplace_back(0.0, FOURTH, 'i');
  } else if (!src_.compare(pos, 4, "atan")) {
    input_.emplace_back(0.0, FOURTH, 'a');
  } else if (!src_.compare(pos, 4, "sqrt")) {
    input_.emplace_back(0.0, FOURTH, 'q');
  } else if (!src_.compare(pos, 2, "ln")) {
    input_.emplace_back(0.0, FOURTH, 'l');
  } else if (!src_.compare(pos, 3, "log")) {
    input_.emplace_back(0.0, FOURTH, 'g');
  } else if (!src_.compare(pos, 3, "mod")) {
    input_.emplace_back(0.0, THIRD, '%');
  } else {
    result = false;
  }
  return result;
}

void s21::Model::TokenOperator(const char& sym) noexcept {
  if (sym == '+') {
    input_.emplace_back(0.0, FIRST, 'p');
  } else if (sym == '-') {
    input_.emplace_back(0.0, FIRST, 'm');
  } else if (sym == '*') {
    input_.emplace_back(0.0, SECOND, '*');
  } else if (sym == '/') {
    input_.emplace_back(0.0, SECOND, '/');
  } else if (sym == '^') {
    input_.emplace_back(0.0, THIRD, '^');
  }
}

bool s21::Model::CreateTokens() noexcept {
  bool result = true;
  size_t pos = 0;
  while (src_[pos] != '\0') {
    if ((std::isdigit(src_[pos]) || src_[pos] == '.') && CheckDots(src)) {
      size_t shift = 0;
      input_.emplace_back(std::stod(&src_[pos], &shift), ZERO, 'n');
      pos += shift;
    } else if (IsFunction(src_[pos])) {
      TokenFunction(pos);
      std::string cmp_3_letters = "cstg%";
      std::string cmp_4_letters = "oiaq";
      if (cmp_3_letters.find(input_.back().type_) != std::string::npos) {
        pos += 3;
      } else if (cmp_4_letters.find(input_.back().type_) != std::string::npos) {
        pos += 4;
      } else {
        pos += 2;
      }
    } else if (IsOperator(src_[pos])) {
      TokenOperator(src_[pos]);
      ++pos;
    } else if (IsHooks(src_[pos])) {
      input_.emplace_back(0.0, THIRD, src_[pos]);
      ++pos;
    } else if (src_[pos] == 'x') {
      input_.emplace_back(0.0, ZERO, src_[pos]);
      ++pos;
    } else {
      result = false;
      break;
    }
  }
  return result;
}

void s21::Model::CreateNotation() noexcept {
  const std::vector<s21::Token> template_input(input_);
  input_.clear();
  for (size_t i = 0; i < template_input.size(); ++i) {
    if (template_input[i].priority_ == ZERO) {
      input_.push_back(template_input[i]);
      ++i;
    } else if (template_input[i].priority_ == FOURTH) {
    }
  }
}
