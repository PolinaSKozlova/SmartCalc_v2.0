#ifndef S21_VIEW_H_
#define S21_VIEW_H_

#include <stack>
#include <string>

enum TokenPriority { ZERO, FIRST, SECOND, THIRD, FOURTH };

namespace s21 {
class View {
 public:
  View() : calc_notation_() {}
  ~View() { ClearStack(); }
  bool CheckHooks(std::string src);
  bool CheckDots(std::string src);
  bool IsFunction(std::string src);
  bool IsOperator(std::string src);
  bool IsHooks(std::string src);

 private:
  void ClearStack();
  struct Token {
    double value_;
    int priority_;
    char type_;
  };
  std::stack<Token> calc_notation_;
};
};  // namespace s21

#endif  // S21_VIEW_H_
