#ifndef SMARTCALC_S21_CONTROLLER_H_
#define SMARTCALC_S21_CONTROLLER_H_

#include "../model/s21_model.h"

namespace s21 {
class Controller {
 public:
  Controller() = default;
  explicit Controller(s21::MathCalculator *other) : model_(other) {}
  // explicit Controller(const std::string &src, const std::string &x = "0.0")
  //     : model_(src, x) {}
  ~Controller() = default;
  void ParceAndCalculateExpression() noexcept {
    try {
      model_->CalculateResultFromInput();
      output_ = model_->GetStringAnswer();
    } catch (std::invalid_argument &e) {
      output_ = e.what();
    }
    // return output_;
  }
  std::string GetOutputAnswer() const { return output_; }

 private:
  s21::MathCalculator *model_;
  std::string output_{};
  // std::string x_value_;
  // s21::View *view_;
};
};  // namespace s21

#endif  // SMARTCALC_S21_CONTROLLER_H_
