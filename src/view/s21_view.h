#ifndef S21_VIEW_H_
#define S21_VIEW_H_

#include <stack>
#include <string>

namespace s21 {
class View {
 public:
  View() : calc_notation_() {}
  ~View() { ClearStack(); }
  bool CheckBracets();
  struct Token {
    double value;
    int priority;
    char type;
  };
  std::stack<Token> calc_notation_;

 private:
  void ClearStack() {
    while (calc_notation_.size()) {
      calc_notation_.pop();
    }
  }
};
};  // namespace s21

#endif  // S21_VIEW_H_
