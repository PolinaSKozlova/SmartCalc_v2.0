#ifndef S21_VIEW_H_
#define S21_VIEW_H_

#include <stack>
#include <string>

#include "../controller/s21_controller.h"

namespace s21 {
class View {
 public:
  View(const std::string& other) : src_(other) {}
  explicit View(Controller* other) : controller_(other) {}
  View& operator=(Controller* other) {
    controller_ = other;
    return *this;
  }
  ~View() {}

 private:
  Controller* controller_;
  std::string src_;
};
};  // namespace s21

#endif  // S21_VIEW_H_
