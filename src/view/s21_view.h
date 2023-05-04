#ifndef SMARTCALC_S21_VIEW_H_
#define SMARTCALC_S21_VIEW_H_

#include "../controller/s21_controller.h"

namespace s21 {
class View {
 public:
  View() = default;
  explicit View(s21::Controller* other) : controller_(other) {}
  // explicit View(const std::string& other, const std::string& x_value = "0.0")
  //     : controller_(other, x_value) {}
  ~View() {}
  std::string GetAnswer() {
    controller_->ParceAndCalculateExpression();
    return controller_->GetOutputAnswer();
  }

 private:
  s21::Controller* controller_;
};
};  // namespace s21

#endif  // SMARTCALC_S21_VIEW_H_
