#ifndef S21_MODEL_H_
#define S21_MODEL_H_

#include <stack>
#include <string>

// #include "../controller/s21_controller.h"

enum TokenPriority { ZERO, FIRST, SECOND, THIRD, FOURTH };

namespace s21 {
class Model {
 public:
  Model(std::string other) : src_(other) {}
  ~Model() {
    // src_ = nullptr;
    // ClearStack();
  }
  bool CheckHooks(std::string src) noexcept;
  bool CheckDots(std::string src) noexcept;
  bool IsFunction(std::string src) noexcept;
  bool IsOperator(std::string src) noexcept;
  bool IsHooks(std::string src) noexcept;

 private:
  void ClearStack();
  struct Token {
    // нужен ли конструктор и деструктор
    Token(double value, int priority, char type)
        : value_(value), priority_(priority), type_(type) {}
    ~Token() {
      value_ = 0;
      priority_ = 0;
      type_ = '\0';
    }
    double value_;
    int priority_;
    char type_;
  };
  // std::stack<Token> input_;
  std::string src_;
};
};  // namespace s21

#endif  // S21_MODEL_H_
