#include "s21_model.h"

std::pair<bool, std::string> s21::Model::ValidationSrc() noexcept {
  std::pair<bool, std::string> result = {true, "OK"};
  if (!CheckHooks() || !CheckDots() || src_.length() > 255) {
    result = {false, "Hooks or dots error or source length > 255"};
  } else {
    std::pair<bool, std::string> create_token_result = CreateTokens();
    std::pair<bool, std::string> check_x_value_result = CheckXValue();
    if (create_token_result.first && check_x_value_result.first) {
      CreateNotation();
      GetXValue();
    } else {
      input_.clear();
      if (!create_token_result.first) {
        result = create_token_result;
      } else if (!check_x_value_result.first) {
        result = check_x_value_result;
      }
    }
  }
  return result;
}

std::pair<bool, std::string> s21::Model::CreateTokens() noexcept {
  std::pair<bool, std::string> result = {true, "OK"};
  size_t pos = 0;
  while (src_[pos] != '\0' && result.first) {
    if ((std::isdigit(src_[pos]) || src_[pos] == '.')) {
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
    } else if (TokenIsHooks(src_[pos])) {
      input_.emplace_back(0.0, THIRD, src_[pos++]);
    } else if (src_[pos] == 'x') {
      input_.emplace_back(0.0, ZERO, src_[pos++]);
    } else {
      result = {false, "Incorrect tokens"};
      input_.clear();
    }
  }
  if (!input_.empty()) {
    CheckUnarySign();
    result = CheckFinalExpression();
  }
  return result;
}

void s21::Model::CreateNotation() noexcept {
  std::vector<s21::Token> copy_input(input_);
  std::stack<s21::Token> my_stack;
  my_stack.emplace(0.0, 0, 0);
  input_.clear();
  for (auto index = copy_input.cbegin(); index != copy_input.cend(); ++index) {
    if (index->priority_ == ZERO) {
      input_.push_back(*index);
    } else if (index->priority_ == FOURTH || index->type_ == '(') {
      my_stack.push(*index);
    } else if (index->type_ == ')') {
      while (true) {
        if (my_stack.top().type_ == '(') {
          my_stack.pop();
          break;
        } else {
          input_.push_back(my_stack.top());
          my_stack.pop();
        }
      }
    } else {
      if (my_stack.top().priority_ < index->priority_ || my_stack.size() == 1) {
        my_stack.push(*index);
      } else {
        if (my_stack.top().type_ == '(') {
          my_stack.push(*index);
        } else {
          if (index->type_ == '^') {
            while (my_stack.top().priority_ > index->priority_ &&
                   my_stack.top().type_ != '(' && my_stack.size() > 1) {
              input_.push_back(my_stack.top());
              my_stack.pop();
            }
          } else {
            while (my_stack.top().priority_ >= index->priority_ &&
                   my_stack.top().type_ != '(' && my_stack.size() > 1) {
              input_.push_back(my_stack.top());
              my_stack.pop();
            }
          }
          my_stack.push(*index);
        }
      }
    }
  }
  while (my_stack.size() > 1) {
    input_.push_back(my_stack.top());
    my_stack.pop();
  }
}

void s21::Model::GetXValue() noexcept {
  for (auto it = input_.begin(); it != input_.end(); ++it) {
    if (it->type_ == 'x') {
      it->value_ = std::stod(x_value_, nullptr);
    }
  }
}
