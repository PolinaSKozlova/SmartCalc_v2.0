#ifndef SMARTCALC_S21_VIEW_H_
#define SMARTCALC_S21_VIEW_H_

#include <stack>
#include <string>

#include "../controller/s21_controller.h"

namespace s21 {
class View {
 public:
  explicit View(const std::string& other, const std::string& x_value = "0.0")
      : controller_(other, x_value) {}
  // explicit View(Controller* other) : controller_(other) {}
  // View& operator=(Controller* other) {
  //   controller_ = other;s
  //   return *this;
  // }
  ~View() {}
  std::string GetAnswer() const { return controller_.GetAnswer(); }

 private:
  s21::Controller controller_;
};
};  // namespace s21

#endif  // SMARTCALC_S21_VIEW_H_
