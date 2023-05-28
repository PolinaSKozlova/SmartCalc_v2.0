#include "s21_model.h"

namespace s21 {
void MathCalculator::CalculateResultFromInput(const std::string &src,
                                              const std::string &x_value) {
  tokens_notation_.SetTokensNewValues(src);
  output_tokens_ = tokens_notation_.CreateNotation();
  CountResult(GetXValue(x_value));
}

void MathCalculator::CountCoordinates(const std::string &src, double x_min,
                                      double x_max, double y_min, double y_max,
                                      std::vector<double> &x_axis,
                                      std::vector<double> &y_axis) {
  if (x_min >= x_max) throw std::invalid_argument("x_min > x_max");
  if (y_min >= y_max) throw std::invalid_argument("y_min > y_max");
  if (!x_axis.empty()) x_axis.clear();
  if (!y_axis.empty()) y_axis.clear();
  tokens_notation_.SetTokensNewValues(src);
  output_tokens_ = tokens_notation_.CreateNotation();
  double step = GetStep(x_min, x_max);
  double x = x_min;
  while (x < x_max) {
    x += step;
    CountResult(x);
    if (!isnan(GetAnswer())) {
      x_axis.push_back(x);
      y_axis.push_back(GetAnswer());
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

double MathCalculator::GetStep(double x_min, double x_max) {
  double step = 0;
  if ((x_max + fabs(x_min) < 100)) {
    step = (x_max - x_min) / ((x_max + fabs(x_min)) * 100);
  } else if (((x_max + fabs(x_min)) >= 100 && (x_max + fabs(x_min)) < 1000)) {
    step = (x_max - x_min) / ((x_max + fabs(x_min)) * 10);
  } else if ((x_max + fabs(x_min)) >= 1000) {
    step = (x_max - x_min) / ((x_max + fabs(x_min)));
  }
  return step;
}

double MathCalculator::GetAnswer() const noexcept { return answer_; }

std::string MathCalculator::GetStringAnswer() const noexcept {
  std::ostringstream oss;
  oss.precision(10);
  oss << answer_;
  return oss.str();
}
};  // namespace s21
