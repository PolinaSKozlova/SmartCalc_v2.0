#ifndef S21_MODEL_H_
#define S21_MODEL_H_

#include "s21_extra_classes.h"

namespace s21 {
enum Priority { ZERO, FIRST, SECOND, THIRD, FOURTH };

class MathCalculator {
 public:
  MathCalculator() {}
  ~MathCalculator() = default;

 private:
  std::vector<Token> output_tokens_;
  std::string x_value_;
  // double x_value_;
  double answer_;
};

class CreditCalculator {
 public:
  CreditCalculator() {}
  ~CreditCalculator() = default;

 private:
};

};  // namespace s21

#endif  // S21_MODEL_H_
