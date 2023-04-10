#include "s21_model.h"

#include <iostream>

// bool s21::Model::ValidationSrc(const std::string& src) noexcept {
//   bool result = true;
//   if (CheckHooks(src) || CheckDots(src)) {
//     result = false;
//   } else {
//     CreateTokens(src);
//   }
//   return false;
// }

bool s21::Model::ValidationSrc(const Model& m) noexcept {
  bool result = true;
  if (!CheckHooks(m.src_) || !CheckDots(m.src_)) {
    result = false;
  } else {
    CreateTokens(m.src_);
  }
  return result;
}

bool s21::Model::CheckHooks(const std::string& src) noexcept {
  int count_hooks = 0;
  bool result = true;
  for (size_t i = 0; i < src.length() && count_hooks >= 0; ++i) {
    if (src[i] == '(') ++count_hooks;
    if (src[i] == ')') --count_hooks;
    if (src[i] == '(' && src[i + 1] == ')') {
      result = false;
      break;
    }
  }
  if (count_hooks) {
    result = false;
  }
  return result;
}

bool s21::Model::CheckDots(const std::string& src) noexcept {
  bool result = true;
  if (src[0] == '.' && !(std::isdigit(src[1]))) {
    result = false;
  }
  for (size_t i = 1; i < src.length() - 1; ++i) {
    if ((src[i] == '.' && !std::isdigit(src[i + 1]) &&
         !std::isdigit(src[i - 1])) ||
        (src[i] == '.' && src[i + 1] == '.')) {
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
  // std::string cmp = "()";
  // if (cmp.find(sym) == std::string::npos) result = false;
  if (sym == '(' || sym == ')') result = true;
  return result;
}

bool s21::Model::TokenFunction(const std::string& src, size_t pos) noexcept {
  bool result = true;
  if (!src.compare(pos, 3, "cos")) {
    input_.emplace_back(0.0, FOURTH, 'c');
  } else if (!src.compare(pos, 3, "sin")) {
    input_.emplace_back(0.0, FOURTH, 's');
  } else if (!src.compare(pos, 3, "tan")) {
    input_.emplace_back(0.0, FOURTH, 't');
  } else if (!src.compare(pos, 4, "acos")) {
    input_.emplace_back(0.0, FOURTH, 'o');
  } else if (!src.compare(pos, 4, "asin")) {
    input_.emplace_back(0.0, FOURTH, 'i');
  } else if (!src.compare(pos, 4, "atan")) {
    input_.emplace_back(0.0, FOURTH, 'a');
  } else if (!src.compare(pos, 4, "sqrt")) {
    input_.emplace_back(0.0, FOURTH, 'q');
  } else if (!src.compare(pos, 2, "ln")) {
    input_.emplace_back(0.0, FOURTH, 'l');
  } else if (!src.compare(pos, 3, "log")) {
    input_.emplace_back(0.0, FOURTH, 'g');
  } else if (!src.compare(pos, 3, "mod")) {
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

bool s21::Model::CreateTokens(const std::string& src) noexcept {
  bool result = true;
  size_t pos = 0;
  while (src[pos] != '\0') {
    if ((std::isdigit(src[pos]) || src[pos] == '.') && CheckDots(src)) {
      size_t shift = 0;
      input_.emplace_back(std::stod(&src[pos], &shift), ZERO, 'n');
      pos += shift;
    } else if (IsFunction(src[pos])) {
      TokenFunction(src, pos);
      std::string cmp_3_letters = "cstg%";
      std::string cmp_4_letters = "oiaq";
      if (cmp_3_letters.find(input_.back().type_) != std::string::npos) {
        pos += 3;
      } else if (cmp_4_letters.find(input_.back().type_) != std::string::npos) {
        pos += 4;
      } else {
        pos += 2;
      }
    } else if (IsOperator(src[pos])) {
      TokenOperator(src[pos]);
      ++pos;
    } else if (IsHooks(src[pos])) {
      input_.emplace_back(0.0, THIRD, src[pos]);
      ++pos;
    } else if (src[pos] == 'x') {
      input_.emplace_back(0.0, ZERO, src[pos]);
      ++pos;
    } else {
      result = false;
      break;
    }
  }

  return result;
}
