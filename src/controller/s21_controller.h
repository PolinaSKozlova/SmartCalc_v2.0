#ifndef S21_CONTROLLER_H_
#define S21_CONTROLLER_H_

// #include "../model/s21_extra_classes.h"
#include "../model/s21_model.h"
#include "../view/s21_view.h"

namespace s21 {
class Controller {
 public:
  Controller() = default;
  explicit Controller(const std::string &src, const std::string &x = "0.0")
      : model_(src, x) {}
  ~Controller() = default;
  std::string ParceAndCalculateExpression() noexcept {
    std::string count_result{};
    try {
      model_.CalculateResultFromInput();
      count_result = model_.GetStringAnswer();
    } catch (std::invalid_argument &e) {
      count_result = e.what();
    }
    return count_result;
  }
  std::string GetAnswer() const { return model_.GetStringAnswer(); }

 private:
  s21::MathCalculator model_;
  std::string output_;
  std::string x_value_;
  // View *view_;
};
};  // namespace s21

#endif  // S21_CONTROLLER_H_
