#include "s21_model.h"

namespace s21 {
void MathCalculator::CalculateResultFromInput(const std::string &src,
                                              const std::string &x_value) {
  if (!src.empty()) {
    tokens_notation_.SetTokensNewValues(src);
    output_tokens_ = tokens_notation_.CreateNotation();
    CountResult(GetXValue(x_value));
  }
}

void MathCalculator::CountResult(double x_value) noexcept {
  std::stack<double> result_stack;
  for (auto &current_token : output_tokens_) {
    if (current_token.priority_ == s21::Priority::kZero) {
      if (current_token.type_ == "x") current_token.value_ = x_value;
      result_stack.push(current_token.value_);
    } else if (current_token.is_binary_) {
      double arg_2 = result_stack.top();
      result_stack.pop();
      double arg_1 = result_stack.top();
      result_stack.pop();
      result_stack.push(
          functions_for_count.find(current_token.type_)->second(arg_1, arg_2));
    } else {
      double arg_1 = result_stack.top();
      result_stack.pop();
      result_stack.push(
          functions_for_count.find(current_token.type_)->second(arg_1, 0.0));
    }
  }
  if (result_stack.size()) answer_ = result_stack.top();
}

void MathCalculator::CountCoordinatesForChartArea(
    const std::string &src, MaxMinValues max_min_values,
    std::pair<std::vector<double>, std::vector<double>> &xy_pairs) {
  CheckMaxMin(max_min_values);
  if (!xy_pairs.first.empty()) xy_pairs.first.clear();
  if (!xy_pairs.second.empty()) xy_pairs.second.clear();
  tokens_notation_.SetTokensNewValues(src);
  output_tokens_ = tokens_notation_.CreateNotation();
  double step = GetStep(max_min_values.min_x_, max_min_values.max_x_);
  double x = max_min_values.min_x_;
  while (x <= max_min_values.max_x_) {
    x += step;
    CountResult(x);
    xy_pairs.first.push_back(x);
    if (GetAnswer() <= max_min_values.max_y_ &&
        GetAnswer() >= max_min_values.min_y_) {
      xy_pairs.second.push_back(GetAnswer());
    } else {
      xy_pairs.second.push_back((std::numeric_limits<double>::quiet_NaN()));
    }
  }
}

void MathCalculator::CheckXValue(const std::string &x_value) const {
  if (x_value == ".") throw std::invalid_argument("X value can't be only dot");
  if (!std::regex_match(
          x_value,
          std::regex(
              "(([-+])?\\d*[.]\\d*)|"
              "((([-+])?((\\d+[.])|([.]\\d+)|(\\d+)))?([eE]([-+])?\\d+)?)")))
    throw std::invalid_argument("Incorrect x value");
}

double MathCalculator::GetXValue(const std::string &x_value) const {
  CheckXValue(x_value);
  return std::stod(x_value);
}

double MathCalculator::GetStep(double x_min, double x_max) {
  double step = 0;
  if ((x_max + fabs(x_min) < 100)) {
    step = (x_max - x_min) / ((x_max + fabs(x_min)) * 200);
  } else if (((x_max + fabs(x_min)) >= 100 && (x_max + fabs(x_min)) < 1000)) {
    step = (x_max - x_min) / ((x_max + fabs(x_min)) * 50);
  } else if ((x_max + fabs(x_min)) >= 1000) {
    step = (x_max - x_min) / ((x_max + fabs(x_min)) * 10);
  }
  step = round(step * 100) / 100;
  return step;
}

void MathCalculator::CheckMaxMin(MaxMinValues max_min_values) const {
  if (max_min_values.min_x_ >= max_min_values.max_x_)
    throw std::invalid_argument("x_min > x_max");
  if (max_min_values.min_y_ >= max_min_values.max_y_)
    throw std::invalid_argument("y_min > y_max");
}

double MathCalculator::GetAnswer() const noexcept { return answer_; }

std::string MathCalculator::GetStringAnswer() const noexcept {
  std::ostringstream oss;
  oss.precision(10);
  oss << answer_;
  return oss.str();
}
};  // namespace s21
