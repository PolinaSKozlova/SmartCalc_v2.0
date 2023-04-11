#include "s21_model.h"

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

bool s21::Model::CheckUnarySign() noexcept {
  bool result = true;
  if (input_[0].priority_ == FIRST &&
      (input_[1].priority_ == ZERO || input_[1].priority_ == FOURTH ||
       input_[1].type_ == '(')) {
    input_[0].priority_ = THIRD;
    // if (input_[0].type_ == 'p') input_[0].type_ == '+';
    // if (input_[0].type_ == 'm') input_[0].type_ == '-';
  }
  for (size_t i = 1; i < input_.size() - 1; i++) {
    if (input_[i].priority_ == FIRST &&
        (input_[i - 1].priority_ == FIRST ||
         input_[i - 1].priority_ == SECOND || input_[i - 1].type_ == '(') &&
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
  return result;
}

bool s21::Model::CheckHooksAfterFunctions() const noexcept {
  bool result = true;
  for (auto iterator_current = input_.cbegin();
       iterator_current != input_.cend(); ++iterator_current) {
    auto iterator_next = ++iterator_current;
    if ((iterator_current->priority_ == FOURTH &&
         iterator_next->type_ != '(') ||
        iterator_next == input_.cend()) {
      result = false;
      break;
    }
  }
  // for (size_t i = 0; i < input_.size()-1; ++i) {
  //   if (input_[i].priority_ == FOURTH && input_[i + 1].type_ != '(') {
  //     result = false;
  //     break;
  //   }
  // }
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

bool s21::Model::CheckExpression() const noexcept {
  bool result = true;
  if (!CheckHooksAfterFunctions()) result = false;
  if (result && CheckEdgeValues()) {
    ;
  }
  return result;
}
