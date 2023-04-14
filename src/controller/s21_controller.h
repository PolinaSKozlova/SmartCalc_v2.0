#ifndef S21_CONTROLLER_H_
#define S21_CONTROLLER_H_

#include "../model/s21_model.h"
#include "../view/s21_view.h"

namespace s21 {
class Controller {
 public:
  Controller() = default;
  // explicit Controller(const s21::Model &other) : model_(other) {}
  // Controller &operator=(const s21::Model &other) {
  //   model_ = other;
  //   return *this;
  // }
  ~Controller() = default;
  std::pair<bool, std::string> ParceAndCalculateExpression() noexcept {
    std::pair<bool, std::string> count_result = {true, "OK"};
    count_result = model_.StartSmartCalc();
    if (count_result.first) {
      count_result.second = model_.GetOutput();
    } else {
      count_result.second = count_result.second;
    }
    return count_result;
  }

 private:
  Model model_;

  // View *view_;
};
};  // namespace s21

#endif  // S21_CONTROLLER_H_
