#include "s21_model.h"

bool s21::Model::CheckHooks() const noexcept {
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

bool s21::Model::CheckDots() const noexcept {
  bool result = true;
  if (src_[0] == '.' && !(std::isdigit(src_[1]))) {
    result = false;
  }
  if (src_[src_.length() - 1] == '.' &&
      !(std::isdigit(src_[src_.length() - 2]))) {
    result = false;
  }
  if (src_.size()) {
    for (size_t i = 1; i < src_.length() - 1 && result; ++i) {
      if ((src_[i] == '.' && !std::isdigit(src_[i + 1]) &&
           !std::isdigit(src_[i - 1])) ||
          (src_[i] == '.' && src_[i + 1] == '.')) {
        result = false;
        break;
      }
    }
  }
  return result;
}

bool s21::Model::TokenIsFunction(const char& sym) const noexcept {
  bool result = true;
  std::string cmp = "cstoiaqnlm";
  if (cmp.find(sym) == std::string::npos) result = false;
  return result;
}

bool s21::Model::TokenIsOperator(const char& sym) const noexcept {
  bool result = true;
  std::string cmp = "+-*/^";
  if (cmp.find(sym) == std::string::npos) result = false;
  return result;
}

bool s21::Model::TokenIsHooks(const char& sym) const noexcept {
  bool result = false;
  if (sym == '(' || sym == ')') result = true;
  return result;
}

std::pair<bool, std::string> s21::Model::FillTokenFunction(
    size_t pos) noexcept {
  std::pair<bool, std::string> result = {true, "OK"};
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
    input_.emplace_back(0.0, SECOND, '%');
  } else {
    result = {false, "Function not found"};
  }
  return result;
}

void s21::Model::FillTokenOperator(const char& sym) noexcept {
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

void s21::Model::CheckUnarySign() noexcept {
  if (input_[0].priority_ == FIRST &&
      (input_[1].priority_ == ZERO || input_[1].priority_ == FOURTH ||
       input_[1].type_ == '(')) {
    input_[0].priority_ = THIRD;
    if (input_[0].type_ == 'p') {
      input_[0].type_ = '+';
    } else if (input_[0].type_ == 'm') {
      input_[0].type_ = '-';
    }
  }
  for (size_t i = 1; i < input_.size() - 1; i++) {
    if (input_[i].priority_ == FIRST &&
        (input_[i - 1].priority_ == FIRST ||
         input_[i - 1].priority_ == SECOND || input_[i - 1].type_ == '(' ||
         input_[i - 1].type_ == '^') &&
        (input_[i + 1].priority_ == ZERO ||
         input_[i + 1].priority_ == FOURTH)) {
      input_[i].priority_ = THIRD;
      if (input_[i].type_ == 'p') {
        input_[i].type_ = '+';
      } else if (input_[i].type_ == 'm') {
        input_[i].type_ = '-';
      }
    }
  }
}

bool s21::Model::CheckHooksAfterFunctions() const noexcept {
  bool result = true;
  for (size_t i = 0; i < input_.size() - 1; ++i) {
    if (input_[i].priority_ == FOURTH && input_[i + 1].type_ != '(') {
      result = false;
      break;
    }
  }
  return result;
}

bool s21::Model::CheckEdgeValues() const noexcept {
  bool result = true;
  if (input_.cbegin()->priority_ == SECOND || input_.cbegin()->type_ == '^' ||
      input_.cbegin()->type_ == '%')
    result = false;
  if (input_.cbegin()->priority_ == ZERO &&
      ((++input_.cbegin())->priority_ == ZERO ||
       (++input_.cbegin())->priority_ == FOURTH))
    result = false;
  if ((--input_.cend())->priority_ == SECOND ||
      (--input_.cend())->priority_ == FOURTH ||
      (--input_.cend())->priority_ == FIRST || (--input_.cend())->type_ == '^')
    result = false;
  return result;
}

std::pair<bool, std::string> s21::Model::CheckFinalExpression() const noexcept {
  std::pair<bool, std::string> result = {true, "OK"};
  if (!CheckHooksAfterFunctions() || !CheckEdgeValues())
    result = {false, "Hooks or edge values error"};
  if (result.first) {
    for (size_t i = 1; i < input_.size() - 1; ++i) {
      if ((input_[i].priority_ == SECOND || input_[i].priority_ == FIRST ||
           input_[i].type_ == '^') &&
          (input_[i - 1].priority_ != ZERO || input_[i - 1].type_ != ')') &&
          ((input_[i + 1].priority_ != ZERO &&
            input_[i + 1].priority_ != FOURTH) &&
           (input_[i + 1].type_ == ')' || input_[i + 1].type_ == '^' ||
            input_[i + 1].priority_ == FIRST ||
            input_[i + 1].priority_ == SECOND))) {
        result = {false, "Missing values"};
        break;
      }
      if (input_[i].priority_ == ZERO &&
          (input_[i - 1].priority_ == ZERO ||
           input_[i - 1].priority_ == FOURTH || input_[i - 1].type_ == ')' ||
           input_[i + 1].priority_ == ZERO ||
           input_[i + 1].priority_ == FOURTH ||
           (input_[i + 1].priority_ == THIRD && input_[i + 1].type_ != '^' &&
            input_[i + 1].type_ != ')'))) {
        result = {false, "Missing operator"};
        break;
      }
      if (input_[i].priority_ == FIRST && input_[i + 1].priority_ == SECOND) {
        result = {false, "Sign error"};
        break;
      }
    }
  }
  return result;
}
