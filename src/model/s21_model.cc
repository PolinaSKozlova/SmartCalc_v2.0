#include "s21_model.h"

bool s21::Model::CheckHooks(std::string src) noexcept {
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

bool s21::Model::CheckDots(std::string src) noexcept {
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

bool s21::Model::IsFunction(std::string src) noexcept {
  bool result = true;
  return result;
}

bool s21::Model::IsOperator(std::string src) noexcept {
  bool result = true;
  return result;
}

bool s21::Model::IsHooks(std::string src) noexcept {
  bool result = true;
  return result;
}
