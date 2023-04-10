#ifndef S21_MODEL_H_
#define S21_MODEL_H_

#include <string>
#include <vector>

// #include "../controller/s21_controller.h"

enum TokenPriority { ZERO, FIRST, SECOND, THIRD, FOURTH };

namespace s21 {
class Model {
  struct Token;

 public:
  Model(std::string other) : src_(other) {}
  ~Model() {
    // src_ = nullptr;
    input_.clear();
  }
  bool CheckHooks(const std::string &src) noexcept;
  bool CheckDots(const std::string &src) noexcept;
  bool IsFunction(const char &sym) noexcept;
  bool IsOperator(const char &sym) noexcept;
  bool IsHooks(const char &sym) const noexcept;
  std::vector<Token> input_;
  std::string src_;

 private:
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
};
};  // namespace s21

#endif  // S21_MODEL_H_
