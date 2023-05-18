#ifndef SMARTCALC_S21_CONTROLLER_H_
#define SMARTCALC_S21_CONTROLLER_H_

#include "../model/s21_model.h"

namespace s21 {
class Controller {
 public:
  Controller() = default;
  explicit Controller(s21::MathCalculator *other) : model_(other) {
    std::cout << "controller constructor" << std::endl;
  }
  ~Controller() = default;
  void ParceAndCalculateExpression(const std::string &src,
                                   const std::string &x_value = "0.0") {
    try {
      model_->CalculateResultFromInput(src, x_value);
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
};
};  // namespace s21

#endif  // SMARTCALC_S21_CONTROLLER_H_
