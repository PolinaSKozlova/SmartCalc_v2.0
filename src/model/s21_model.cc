#include "s21_model.h"

void s21::Model::ClearStack() {
  while (input_.size()) {
    input_.pop();
  }
}

bool s21::Model::CheckHooks(std::string src) noexcept {
  int count_hooks = 0;
  bool result = true;
  for (size_t i = 0; i < src.length() && count_hooks >= 0; ++i) {
    if (src[i] == '(') {
      ++count_hooks;
    }
    if (src[i] == ')') {
      --count_hooks;
    }
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

// bool CheckDots(std::string src) {}

// bool IsFunction(std::string src) {}

// bool IsOperator(std::string src) {}

// bool IsHooks(std::string src) {}
