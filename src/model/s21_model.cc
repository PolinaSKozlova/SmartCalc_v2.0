#include "s21_model.h"

std::pair<bool, std::string> s21::Model::ValidationSrc() noexcept {
  std::pair<bool, std::string> result = {true, "OK"};
  if (!CheckHooks() || !CheckDots() || src_.size() > 255) {
    result = {false, "Hooks or dots error"};
  } else {
    if (CreateTokens().first) {
      // CreateNotation();
    } else {
      result = {false, "Tokens parcing error"};
    }
  }
  return result;
}

std::pair<bool, std::string> s21::Model::CreateTokens() noexcept {
  std::pair<bool, std::string> result = {true, "OK"};
  size_t pos = 0;
  while (src_[pos] != '\0' && result.first) {
    if ((std::isdigit(src_[pos]) || src_[pos] == '.') && CheckDots()) {
      size_t shift = 0;
      input_.emplace_back(std::stod(&src_[pos], &shift), ZERO, 'n');
      pos += shift;
    } else if (TokenIsFunction(src_[pos])) {
      result = FillTokenFunction(pos);
      if (result.first) {
        std::string cmp_3_letters = "cstg%";
        std::string cmp_4_letters = "oiaq";
        if (cmp_3_letters.find(input_.back().type_) != std::string::npos) {
          pos += 3;
        } else if (cmp_4_letters.find(input_.back().type_) !=
                   std::string::npos) {
          pos += 4;
        } else {
          pos += 2;
        }
      }
    } else if (TokenIsOperator(src_[pos])) {
      FillTokenOperator(src_[pos++]);
      // ++pos;
    } else if (TokenIsHooks(src_[pos])) {
      input_.emplace_back(0.0, THIRD, src_[pos++]);
      // ++pos;
    } else if (src_[pos] == 'x') {
      input_.emplace_back(0.0, ZERO, src_[pos++]);
      // ++pos;
    } else {
      result = {false, "Incorrect tokens"};
      break;
    }
  }
  if (!input_.empty()) {
    CheckUnarySign();
    result = CheckFinalExpression();
  }
  return result;
}

void s21::Model::CreateNotation() noexcept {
  const std::vector<s21::Token> template_input(input_);
  std::stack<Token> template_stack;
  input_.clear();
  for (size_t i = 0; i < template_input.size(); ++i) {
    if (template_input[i].priority_ == ZERO) {
      input_.push_back(template_input[i]);
      ++i;
    } else if (template_input[i].priority_ == FOURTH) {
    }
  }
}
