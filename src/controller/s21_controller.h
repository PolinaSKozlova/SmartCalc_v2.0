#ifndef S21_CONTROLLER_H_
#define S21_CONTROLLER_H_

#include "../model/s21_model.h"
#include "../view/s21_view.h"

namespace s21 {
class Controller {
 public:
  Controller();
  Controller(Model *other) : model_(other) {}
  Controller &operator=(Model *other) {
    model_ = other;
    return *this;
  }
  ~Controller();

 private:
  Model *model_;
  View *view_;
};
};  // namespace s21

#endif  // S21_CONTROLLER_H_
