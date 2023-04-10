#include "s21_model.h"

#include <iostream>

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
  std::string cmp = "cstal";  // уменьшила строку поиска
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
  bool result = true;
  std::string cmp = "()";
  if (cmp.find(sym) == std::string::npos) result = false;
  return result;
}

bool s21::Model::WhatFunction(const std::string& src, size_t pos) noexcept {
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
    input_.emplace_back(0.0, SECOND, '%');
  } else {
    result = false;
  }
  return result;
}

bool s21::Model::WhatOperator(const std::string& src, size_t pos) noexcept {
  bool result = true;
  return result;
}
