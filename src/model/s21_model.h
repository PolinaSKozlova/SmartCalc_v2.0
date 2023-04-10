#ifndef S21_MODEL_H_
#define S21_MODEL_H_

#include <stack>
#include <string>

#include "../controller/s21_controller.h"

namespace s21 {
class Model {
 public:
  Model();
  ~Model() { ClearStack(); }
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
  std::stack<Token> input_;
};
};  // namespace s21

#endif  // S21_MODEL_H_
