#include "s21_model.h"

bool s21::Model::ValidationSrc() noexcept {
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

bool s21::Model::ValidationTokens() const noexcept {
  bool result = true;

  return result;
}

bool s21::Model::CreateTokens() noexcept {
  bool result = true;
  size_t pos = 0;
  while (src_[pos] != '\0') {
    if ((std::isdigit(src_[pos]) || src_[pos] == '.') && CheckDots()) {
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
  CheckUnarySign();
  result = CheckFinalExpression();
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
